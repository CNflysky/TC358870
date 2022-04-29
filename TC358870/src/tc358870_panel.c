#include "tc358870_panel.h"

#ifdef LT070ME05000
#include "panels/LT070ME05000.h"
#elif defined TPM0551002P
#include "panels/TPM0551002P.h"
#elif defined VVX10F034N00
#include "panels/VVX10F034N00.h"
#elif defined VVX10F034N00_2
#include "panels/VVX10F034N00_2.h"
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
  panel_backlight_enable();           // turn on backlight
  board_audio_control(GPIO_PIN_SET);  // turn on audio
}

void turn_off_panel(void (*RS_Seq)()) {
  panel_backlight_disable();  // turn off backlight
  RS_Seq();
  panel_power_control(GPIO_PIN_RESET);  // turn off panel power
  board_audio_control(GPIO_PIN_RESET);  // turn off audio
}

void RS_Int() {
  // Interrupt Service Routine(RS_Int)
  static int stage = 0;
  static int brightness = 3;
  while (HAL_GPIO_ReadPin(DOWNLOAD_GPIO_Port, DOWNLOAD_Pin)) {
    // The real ISR
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

  HAL_Delay(10);
  if (!HAL_GPIO_ReadPin(DOWNLOAD_GPIO_Port, DOWNLOAD_Pin)) {
    brightness++;
    if (brightness > 5) brightness = 1;
    panel_backlight_set_brightness(brightness);
  }
  HAL_Delay(500);
  // i2c1_uh2cd_write16(0x0504, 0x0006);  // DCSCMD_Q
  // i2c1_uh2cd_write16(0x0504, 0x00BF);  // DCSCMD_Q
  // Waitx1ms(10);
  // printf_u("0x01A0=0x%lx\n",
  //          i2c1_uh2cd_read32(0x01A0));     // DSI_RX_STATE_INT_STAT
  // i2c1_uh2cd_write32(0x01A0, 0x0000001F);  // DSI_RX_STATE_INT_STAT
  // printf_u("0x01BC=0x%lx\n", i2c1_uh2cd_read32(0x01BC));  // DSI_RX_HEADER
  // // If received paclket is Long packet, continue following sequence
  // printf_u("0x01C4=0x%lx\n", i2c1_uh2cd_read32(0x01C4));  //
  // DSI_LPRX_FIFO_LEVEL printf_u("0x01B8=0x%lx\n",
  // i2c1_uh2cd_read32(0x01B8));
  // // DSI_RX_FIFO
  // // Repeat reading [DSI_RX_FIFO(0x01B8)] times.
  // HAL_Delay(1000);
}