#include "tc358870_panel.h"

#include "tc358870_gpio.h"

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
  panel_power_control(GPIO_PIN_SET);  // turn on panel power
  HAL_Delay(POWER_ON_DELAY);
  panel_reset_control(GPIO_PIN_RESET);  // reset panel
  HAL_Delay(RESET_LOW_TIME);
  panel_reset_control(GPIO_PIN_SET);
  HAL_Delay(RESET_HIGH_TIME);
  RS3();
  HAL_Delay(BACKLIGHT_TURN_ON_DELAY);
  panel_backlight_control(GPIO_PIN_SET);  // turn on backlight
  board_audio_control(GPIO_PIN_SET);      // turn on audio
  
}

void turn_off_panel(void (*RS_Seq)()) {
  panel_backlight_control(GPIO_PIN_RESET);  // turn off backlight
  RS_Seq();
  panel_power_control(GPIO_PIN_RESET);  // turn off panel power
  board_audio_control(GPIO_PIN_RESET);  // turn off audio
}

void RS_Int() {
  // Interrupt Service Routine(RS_Int)
  static uint8_t stage = 1;  // State: S1
  printf_u("Reading registers...\n");
  switch (stage) {
    case 1:
      printf_u("Current stage: State S1 --- Stand By\n");
      break;
    case 2:
      printf_u("Current stage: State S2 --- Ready\n");
      break;
    case 3:
      printf_u("Current stage: State S3 --- Video Transmission\n");
      break;
    default:
      printf_u("Current stage: State S? --- Unknown: stage code = %d\n", stage);
      break;
  }
#ifdef TPM0551002P
  printf_u("Panel model: TPM0551002P\n");
#elif defined LT070ME05000
  printf_u("Panel model: LT070ME05000\n");
#elif defined VVX10F034N00
  printf_u("Panel model: VVX10F034N00\n");
#endif
  // on-board led control
  (stage == 3) ? board_led_control(GPIO_PIN_RESET)
               : board_led_control(GPIO_PIN_SET);
  // Exit from Sleep
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  HAL_Delay(1);
  // Check Interrupt
  uint16_t int_status = i2c1_uh2cd_read16(0x0014);      // IntStatus
  uint16_t int_sys_status = i2c1_uh2cd_read16(0x001A);  // IntSYSSTATUS
  uint8_t sys_int = i2c1_uh2cd_read8(0x8502);           // SYS_INT
  uint8_t misc_int = i2c1_uh2cd_read8(0x850B);          // MISC_INT
  uint8_t sys_status = i2c1_uh2cd_read8(0x8520);        // SYS_STATUS
  // check bit 5
  if (int_status & 0x20) {
    // re-reading register int_sys_status.
    int_sys_status = i2c1_uh2cd_read16(0x001A);  // IntSYSSTATUS
    // check bit 1
    if (int_sys_status & 0x01) {
      RS2();
      stage = 2;
      printf_u("Executed RS2 --- Stage S2: Ready\n");
    }
  }
  // check bit 9
  if (int_status & 0x0200) {
    // re-reading register misc_int and sys_status.
    misc_int = i2c1_uh2cd_read8(0x850B);    // MISC_INT
    sys_status = i2c1_uh2cd_read8(0x8520);  // SYS_STATUS
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
  // check bit1, bit0 and bit 7
  if (misc_int & 0x02 && sys_status & 0x01 && !(sys_status & 0x80)) {
    turn_off_panel(RS4);
    stage = 2;
    printf_u("Executed RS4 --- Stage S2: Ready\n");
  }
  // re-reading sys_int and sys_status
  sys_int = i2c1_uh2cd_read8(0x8502);     // SYS_INT
  sys_status = i2c1_uh2cd_read8(0x8520);  // SYS_STATUS
  // check bit 0 and bit 0
  if (sys_int & 0x01 && !(sys_status & 0x01)) {
    turn_off_panel(RS5);
    // turn off audio
    board_audio_control(GPIO_PIN_RESET);
    stage = 1;
    printf_u("Executed RS5 --- Stage S1: Stand by\n");
    // check bit 0 and bit 0
  } else if (sys_int & 0x01 && sys_status & 0x01) {
    RS2();
    stage = 2;
    printf_u("Executed RS2 --- Stage S2: Ready\n");
  }
}