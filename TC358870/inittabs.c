void Panel_Init() {
  // LCD Initialization ST7701S:
  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0006);
  i2c1_uh2cd_write16(0x0504, 0x77ff);
  i2c1_uh2cd_write16(0x0504, 0x0001);
  i2c1_uh2cd_write16(0x0504, 0x1300);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x08EF);
  HAL_Delay(1);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0006);
  i2c1_uh2cd_write16(0x0504, 0x77ff);
  i2c1_uh2cd_write16(0x0504, 0x0001);
  i2c1_uh2cd_write16(0x0504, 0x1000);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x4fc0);
  i2c1_uh2cd_write16(0x0504, 0x0000);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x10c1);
  i2c1_uh2cd_write16(0x0504, 0x000c);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x07c2);
  i2c1_uh2cd_write16(0x0504, 0x0014);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x10cc);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0017);
  i2c1_uh2cd_write16(0x0504, 0x0ab0);
  i2c1_uh2cd_write16(0x0504, 0x1e18);
  i2c1_uh2cd_write16(0x0504, 0x1612);
  i2c1_uh2cd_write16(0x0504, 0x0e0c);
  i2c1_uh2cd_write16(0x0504, 0x0c0d);
  i2c1_uh2cd_write16(0x0504, 0x0629);
  i2c1_uh2cd_write16(0x0504, 0x1314);
  i2c1_uh2cd_write16(0x0504, 0x3329);
  i2c1_uh2cd_write16(0x0504, 0x180a);
  i2c1_uh2cd_write16(0x0504, 0x001c);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0017);
  i2c1_uh2cd_write16(0x0504, 0x0ab1);
  i2c1_uh2cd_write16(0x0504, 0x2119);
  i2c1_uh2cd_write16(0x0504, 0x0c0a);
  i2c1_uh2cd_write16(0x0504, 0x0c00);
  i2c1_uh2cd_write16(0x0504, 0x0303);
  i2c1_uh2cd_write16(0x0504, 0x0123);
  i2c1_uh2cd_write16(0x0504, 0x0c0e);
  i2c1_uh2cd_write16(0x0504, 0x2b27);
  i2c1_uh2cd_write16(0x0504, 0x001c);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x006);
  i2c1_uh2cd_write16(0x0504, 0x77ff);
  i2c1_uh2cd_write16(0x0504, 0x0001);
  i2c1_uh2cd_write16(0x0504, 0x1100);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x5db0);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x61b1);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x84b2);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x80b3);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x4db5);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x85b7);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x20b8);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x78c1);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x78c2);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, 0x88d0);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0004);
  i2c1_uh2cd_write16(0x0504, 0x00e0);
  i2c1_uh2cd_write16(0x0504, 0x0200);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0012);
  i2c1_uh2cd_write16(0x0504, 0x06e1);
  i2c1_uh2cd_write16(0x0504, 0x08a0);
  i2c1_uh2cd_write16(0x0504, 0x05a0);
  i2c1_uh2cd_write16(0x0504, 0x07a0);
  i2c1_uh2cd_write16(0x0504, 0x00a0);
  i2c1_uh2cd_write16(0x0504, 0x4444);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0013);
  i2c1_uh2cd_write16(0x0504, 0x20e2);
  i2c1_uh2cd_write16(0x0504, 0x4420);
  i2c1_uh2cd_write16(0x0504, 0x9644);
  i2c1_uh2cd_write16(0x0504, 0x00a0);
  i2c1_uh2cd_write16(0x0504, 0x9600);
  i2c1_uh2cd_write16(0x0504, 0x00a0);
  i2c1_uh2cd_write16(0x0504, 0x0000);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0005);
  i2c1_uh2cd_write16(0x0504, 0x00e3);
  i2c1_uh2cd_write16(0x0504, 0x2200);
  i2c1_uh2cd_write16(0x0504, 0x0022);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x44e4);
  i2c1_uh2cd_write16(0x0504, 0x0044);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0017);
  i2c1_uh2cd_write16(0x0504, 0x0de5);
  i2c1_uh2cd_write16(0x0504, 0xa091);
  i2c1_uh2cd_write16(0x0504, 0x0fa0);
  i2c1_uh2cd_write16(0x0504, 0xa093);
  i2c1_uh2cd_write16(0x0504, 0x09a0);
  i2c1_uh2cd_write16(0x0504, 0xa08d);
  i2c1_uh2cd_write16(0x0504, 0x0ba0);
  i2c1_uh2cd_write16(0x0504, 0xa08f);
  i2c1_uh2cd_write16(0x0504, 0x00a0);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0005);
  i2c1_uh2cd_write16(0x0504, 0x00e6);
  i2c1_uh2cd_write16(0x0504, 0x2200);
  i2c1_uh2cd_write16(0x0504, 0x0022);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x44e7);
  i2c1_uh2cd_write16(0x0504, 0x0044);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0017);
  i2c1_uh2cd_write16(0x0504, 0x0ce8);
  i2c1_uh2cd_write16(0x0504, 0xa090);
  i2c1_uh2cd_write16(0x0504, 0x0ea0);
  i2c1_uh2cd_write16(0x0504, 0xa092);
  i2c1_uh2cd_write16(0x0504, 0x08a0);
  i2c1_uh2cd_write16(0x0504, 0xa08c);
  i2c1_uh2cd_write16(0x0504, 0x0aa0);
  i2c1_uh2cd_write16(0x0504, 0xa08e);
  i2c1_uh2cd_write16(0x0504, 0x00a0);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0003);
  i2c1_uh2cd_write16(0x0504, 0x36e9);
  i2c1_uh2cd_write16(0x0504, 0x0000);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0008);
  i2c1_uh2cd_write16(0x0504, 0x00eb);
  i2c1_uh2cd_write16(0x0504, 0xe401);
  i2c1_uh2cd_write16(0x0504, 0x44e4);
  i2c1_uh2cd_write16(0x0504, 0x4088);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0017);
  i2c1_uh2cd_write16(0x0504, 0xffed);
  i2c1_uh2cd_write16(0x0504, 0x6745);
  i2c1_uh2cd_write16(0x0504, 0x01fa);
  i2c1_uh2cd_write16(0x0504, 0xcf2b);
  i2c1_uh2cd_write16(0x0504, 0xffff);
  i2c1_uh2cd_write16(0x0504, 0xb2fc);
  i2c1_uh2cd_write16(0x0504, 0xaf10);
  i2c1_uh2cd_write16(0x0504, 0x5476);
  i2c1_uh2cd_write16(0x0504, 0x00ff);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x8039);
  i2c1_uh2cd_write16(0x0504, 0x0007);
  i2c1_uh2cd_write16(0x0504, 0x10ef);
  i2c1_uh2cd_write16(0x0504, 0x040d);
  i2c1_uh2cd_write16(0x0504, 0x3f08);
  i2c1_uh2cd_write16(0x0504, 0x001f);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0005);
  i2c1_uh2cd_write16(0x0504, 0x0035);

  HAL_Delay(100);

  i2c1_uh2cd_write16(0x0504, 0x0005);
  i2c1_uh2cd_write16(0x0504, 0x0011);
}

void Panel_Init() {
  // LCD Initialization LT070ME05000:
  // Soft Reset
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0001);  // DCSCMD_Q
  HAL_Delay(5);

  // MACP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00B0);  // DCSCMD_Q
  HAL_Delay(1);

  // interface setting
  i2c1_uh2cd_write16(0x0504, 0x8029);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0006);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x04B3);
  i2c1_uh2cd_write16(0x0504, 0x0008);
  i2c1_uh2cd_write16(0x0504, 0x0022);

  // interface id setting
  i2c1_uh2cd_write16(0x0504, 0x8029);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0002);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0CB4);  // DCSCMD_Q

  // DSI control
  i2c1_uh2cd_write16(0x0504, 0x8029);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0003);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x3AB6);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00D3);  // DCSCMD_Q

  // Write Display brightness
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xE651);  // DCSCMD_Q

  // Write control Display
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x2C53);  // DCSCMD_Q

  // Set Pixel Format
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x773A);  // DCSCMD_Q
  HAL_Delay(1);

  // set column address
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x002A);
  i2c1_uh2cd_write16(0x0504, 0x0400);
  i2c1_uh2cd_write16(0x0504, 0x00AF);
  HAL_Delay(1);

  // set page address
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x002B);
  i2c1_uh2cd_write16(0x0504, 0x0700);
  i2c1_uh2cd_write16(0x0504, 0x007F);
  HAL_Delay(1);

  /* SleepOut */
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0011);  // DCSCMD_Q
  HAL_Delay(150);
}