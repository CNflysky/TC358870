#include "tc358870_panel.h"

#ifdef LT070ME05000
#include "panels/LT070ME05000.h"
#elif defined TPM0551002P
#include "panels/TPM0551002P.h"
#elif defined VVX10F034N00
#include "panels/VVX10F034N00.h"
#endif

void RS2() {
  // Initialization for Ready (RS2)
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask
  // Set HPDO to "H"
  i2c1_uh2cd_write8(0x854A, 0x01);  // INIT_END
}

void RS4() {
  // MIPI Output Disable(RS4)
  // Reset Display by H/W reset
  // Stop DSI output
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask
}

void RS5() {
  // MIPI Output Disable & Sleep(RS5)
  // Reset Display by H/W reset
  // Stop DSI output
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0F1F);  // IntMask
  // Enter Sleep
  i2c1_uh2cd_write16(0x0002, 0x0001);  // SysCtl
}

void turn_on_panel() {
  panel_power_set(GPIO_PIN_SET);  // turn on panel power
  HAL_Delay(POWER_ON_DELAY);
  panel_rst_set(GPIO_PIN_RESET);  // reset panel
  HAL_Delay(RESET_LOW_TIME);
  panel_rst_set(GPIO_PIN_SET);
  HAL_Delay(RESET_HIGH_TIME);
  RS3();
  HAL_Delay(BACKLIGHT_TURN_ON_DELAY);
  panel_backlight_enable();       // turn on backlight
  board_audio_set(GPIO_PIN_SET);  // turn on audio
}

void turn_off_panel(void (*RS_Seq)()) {
  panel_backlight_disable();  // turn off backlight
  RS_Seq();
  panel_power_set(GPIO_PIN_RESET);  // turn off panel power
  board_audio_set(GPIO_PIN_RESET);  // turn off audio
}

void RS_Int() {
  // Interrupt Service Routine(RS_Int)
  static int stage = 0;
  // on-board led control
  usr_led_set(stage == 3 ? GPIO_PIN_RESET : GPIO_PIN_SET);
  // Exit from Sleep
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  HAL_Delay(1);
  // Check Interrupt
  uint16_t int_status = i2c1_uh2cd_read16(0x0014);      // IntStatus
  uint16_t int_sys_status = i2c1_uh2cd_read16(0x001A);  // IntSYSSTATUS
  uint8_t sys_int = i2c1_uh2cd_read8(0x8502);           // SYS_INT
  uint8_t misc_int = i2c1_uh2cd_read8(0x850B);          // MISC_INT
  uint8_t sys_status = i2c1_uh2cd_read8(0x8520);        // SYS_STATUS
#ifdef DEBUG
  printf_u(
      "dbg stage 1: int_status = 0x%x, int_sys_status = 0x%x, sys_int = "
      "0x%x, "
      "misc_int = 0x%x, "
      "sys_status = 0x%x\n",
      int_status, int_sys_status, sys_int, misc_int, sys_status);
#endif
  // check SYS_INT(5)
  if (CHECK_BIT(int_status, 5)) {
    // re-reading register int_sys_status.
    int_sys_status = i2c1_uh2cd_read16(0x001A);  // IntSYSSTATUS
    // check HPD_CHG(0)
    if (CHECK_BIT(int_sys_status, 0)) {
      RS2();
      stage = 2;
      printf_u("Executed RS2 --- Stage S2: Ready\n");
    }
  }
  // check HDMI_INT(9)
  if (CHECK_BIT(int_status, 9)) {
    // re-reading register misc_int and sys_status.
    misc_int = i2c1_uh2cd_read8(0x850B);    // MISC_INT
    sys_status = i2c1_uh2cd_read8(0x8520);  // SYS_STATUS
#ifdef DEBUG
    printf_u(
        "dbg stage 2: int_status = 0x%x, int_sys_status = 0x%x, sys_int = "
        "0x%x, "
        "misc_int = 0x%x, "
        "sys_status = 0x%x\n",
        int_status, int_sys_status, sys_int, misc_int, sys_status);
#endif
    // check bit 1 and bit 7
    if (misc_int & 0x02 && sys_status & 0x80) {
      turn_on_panel();
      stage = 3;
      printf_u("Executed RS3 --- Stage S3: Video Transmission\n");
    }
  }

  misc_int = i2c1_uh2cd_read8(0x850B);    // MISC_INT
  sys_status = i2c1_uh2cd_read8(0x8520);  // SYS_STATUS
  sys_int = i2c1_uh2cd_read8(0x8502);     // SYS_INT
#ifdef DEBUG
  printf_u(
      "dbg stage 3: int_status = 0x%x, int_sys_status = 0x%x, sys_int = "
      "0x%x, "
      "misc_int = 0x%x, "
      "sys_status = 0x%x\n",
      int_status, int_sys_status, sys_int, misc_int, sys_status);
#endif
  // check I_SYNC_CHG(1), S_DDC5V(0) and S_SYNC(7)
  if (CHECK_BIT(misc_int, 1) && CHECK_BIT(sys_status, 0) &&
      !CHECK_BIT(sys_status, 7)) {
    stage = 2;
    printf_u("Executed RS4 --- Stage S2: Ready\n");
  }
  // re-reading sys_int and sys_status
  sys_int = i2c1_uh2cd_read8(0x8502);     // SYS_INT
  sys_status = i2c1_uh2cd_read8(0x8520);  // SYS_STATUS
#ifdef DEBUG
  printf_u(
      "dbg stage 4: int_status = 0x%x, int_sys_status = 0x%x, sys_int = "
      "0x%x, "
      "misc_int = 0x%x, "
      "sys_status = 0x%x\n",
      int_status, int_sys_status, sys_int, misc_int, sys_status);
#endif
  // check I_DDC(0) and S_DDC5V(0)
  if (CHECK_BIT(sys_int, 0) && !CHECK_BIT(sys_status, 0)) {
    turn_off_panel(RS5);
    // turn off audio
    board_audio_set(GPIO_PIN_RESET);
    stage = 1;
    printf_u("Executed RS5 --- Stage S1: Stand by\n");
    // check check I_DDC(0) and S_DDC5V(0)
  } else if (CHECK_BIT(sys_int, 0) && CHECK_BIT(sys_status, 0)) {
    RS2();
    stage = 2;
    printf_u("Executed RS2 --- Stage S2: Ready\n");
  }
  panel_backlight_set_brightness_level(br);
#ifdef DEBUG
  printf_u("Setting brightness level to %d\n", br);
#endif
  HAL_Delay(200);
}
