#include "tc358870_panel.h"

#include "tc358870_gpio.h"

void RS1() {
#ifdef TPM0551002P
  // Initialization for Stand-by (RS1)
  // Software Reset
  i2c1_uh2cd_write16(0x0004, 0x0004);  // ConfCtl0
  i2c1_uh2cd_write16(0x0002, 0x3F00);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  i2c1_uh2cd_write16(0x0006, 0x0000);  // ConfCtl1
  // HDMI Interrupt Mask, Clear
  i2c1_uh2cd_write16(0x0016, 0x0F3F);  // IntMask
  i2c1_uh2cd_write8(0x8502, 0xFF);     // SYS_INT
  i2c1_uh2cd_write8(0x850B, 0xFF);     // MISC_INT
  i2c1_uh2cd_write16(0x0014, 0x0F3F);  // IntStatus
  i2c1_uh2cd_write8(0x8512, 0xFE);     // SYS_INTM
  i2c1_uh2cd_write8(0x851B, 0xFD);     // MISC_INTM
  // HDMI PHY
  i2c1_uh2cd_write8(0x8410, 0x03);  // PHY CTL
  i2c1_uh2cd_write8(0x8413, 0x3F);  // PHY_ENB
  i2c1_uh2cd_write8(0x8420, 0x07);  // EQ_BYPS
  i2c1_uh2cd_write8(0x84F0, 0x31);  // APLL_CTL
  i2c1_uh2cd_write8(0x84F4, 0x01);  // DDCIO_CTL
  // HDMI Clock
  i2c1_uh2cd_write16(0x8540, 0x12C0);  // SYS_FREQ0_1
  i2c1_uh2cd_write8(0x8630, 0x00);     // LOCKDET_FREQ0
  i2c1_uh2cd_write16(0x8631, 0x0753);  // LOCKDET_REF1_2
  i2c1_uh2cd_write8(0x8670, 0x02);     // NCO_F0_MOD
  i2c1_uh2cd_write16(0x8A0C, 0x12C0);  // CSC_SCLK0_1
  // EDID
  i2c1_uh2cd_write8(0x85E0, 0x01);     // EDID_MODE
  i2c1_uh2cd_write16(0x85E3, 0x0100);  // EDID_LEN1_2
  // EDID Data
  i2c1_uh2cd_write8(0x8C00, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C01, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C02, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C03, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C04, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C05, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C06, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C07, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C08, 0x52);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C09, 0x62);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0A, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0B, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0D, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0E, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0F, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C10, 0x1C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C11, 0x15);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C12, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C13, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C14, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C15, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C16, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C17, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C18, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C19, 0x0D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1A, 0xC9);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1B, 0xA0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1C, 0x57);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1D, 0x47);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1E, 0x98);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1F, 0x27);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C20, 0x12);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C21, 0x48);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C22, 0x4C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C23, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C24, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C25, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C26, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C27, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C28, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C29, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2A, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2B, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2C, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2D, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2E, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2F, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C30, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C31, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C32, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C33, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C34, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C35, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C36, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C37, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C38, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C39, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3A, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3B, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3C, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3D, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3E, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3F, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C40, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C41, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C42, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C43, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C44, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C45, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C46, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C47, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C48, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C49, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4A, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4B, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4C, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4D, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4E, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4F, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C50, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C51, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C52, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C53, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C54, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C55, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C56, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C57, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C58, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C59, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5A, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5B, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5D, 0xFC);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5E, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5F, 0x54);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C60, 0x6F);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C61, 0x73);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C62, 0x68);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C63, 0x69);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C64, 0x62);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C65, 0x61);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C66, 0x2D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C67, 0x55);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C68, 0x48);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C69, 0x32);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6A, 0x44);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6B, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6D, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6E, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6F, 0xFD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C70, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C71, 0x14);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C72, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C73, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C74, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C75, 0x1D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C76, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C77, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C78, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C79, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7A, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7B, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7C, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7D, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7E, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7F, 0xA3);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C80, 0x02);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C81, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C82, 0x1A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C83, 0x71);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C84, 0x47);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C85, 0xC6);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C86, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C87, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C88, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C89, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8A, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8B, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8C, 0x23);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8D, 0x09);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8E, 0x07);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8F, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C90, 0x83);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C91, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C92, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C93, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C94, 0x65);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C95, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C96, 0x0C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C97, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C98, 0x10);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C99, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9A, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9B, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9C, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9D, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9E, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9F, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA0, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA1, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA2, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA3, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA4, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA6, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA7, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAB, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAC, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAD, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAE, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAF, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB0, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB1, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB2, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB3, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB4, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB5, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB6, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB8, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB9, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBD, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBE, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBF, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC0, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC1, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC2, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC3, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC4, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC5, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC6, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC7, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC8, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCA, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCB, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCD, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCF, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD0, 0x34);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD1, 0x3A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD2, 0x38);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD3, 0xD0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD4, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD5, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD6, 0x08);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD7, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD8, 0x60);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD9, 0x3E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDA, 0x41);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDC, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDD, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDF, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE0, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE1, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE2, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE3, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE4, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE6, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CED, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEF, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF0, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF1, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF2, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF3, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF4, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF6, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFD, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFF, 0xF7);  // EDID_RAM
  // HDCP Setting
  // HDMI SYSTEM
  i2c1_uh2cd_write8(0x8543, 0x02);  // DDC_CTL
  i2c1_uh2cd_write8(0x8544, 0x10);  // HPD_CTL
  // HDMI Audio Setting
  i2c1_uh2cd_write8(0x8600, 0x00);         // AUD_Auto_Mute
  i2c1_uh2cd_write8(0x8602, 0xF3);         // Auto_CMD0
  i2c1_uh2cd_write8(0x8603, 0x02);         // Auto_CMD1
  i2c1_uh2cd_write8(0x8604, 0x0C);         // Auto_CMD2
  i2c1_uh2cd_write8(0x8606, 0x05);         // BUFINIT_START
  i2c1_uh2cd_write8(0x8607, 0x00);         // FS_MUTE
  i2c1_uh2cd_write8(0x8652, 0x02);         // SDO_MODE1
  i2c1_uh2cd_write32(0x8671, 0x020C49BA);  // NCO_48F0A_D
  i2c1_uh2cd_write32(0x8675, 0x01E1B089);  // NCO_44F0A_D
  i2c1_uh2cd_write8(0x8680, 0x00);         // AUD_MODE
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0F1F);  // IntMask
  // Enter Sleep
  i2c1_uh2cd_write16(0x0002, 0x0001);  // SysCtl
#elif defined LT070ME05000
  i2c1_uh2cd_write16(0x0004, 0x0004);  // ConfCtl0
  i2c1_uh2cd_write16(0x0002, 0x3F00);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  i2c1_uh2cd_write16(0x0006, 0x0000);  // ConfCtl1
  // HDMI Interrupt Mask, Clear
  i2c1_uh2cd_write16(0x0016, 0x0F3F);  // IntMask
  i2c1_uh2cd_write8(0x8502, 0xFF);     // SYS_INT
  i2c1_uh2cd_write8(0x850B, 0xFF);     // MISC_INT
  i2c1_uh2cd_write16(0x0014, 0x0F3F);  // IntStatus
  i2c1_uh2cd_write8(0x8512, 0xFE);     // SYS_INTM
  i2c1_uh2cd_write8(0x851B, 0xFD);     // MISC_INTM
  // HDMI PHY
  i2c1_uh2cd_write8(0x8410, 0x03);  // PHY CTL
  i2c1_uh2cd_write8(0x8413, 0x3F);  // PHY_ENB
  i2c1_uh2cd_write8(0x8420, 0x07);  // EQ_BYPS
  i2c1_uh2cd_write8(0x84F0, 0x31);  // APLL_CTL
  i2c1_uh2cd_write8(0x84F4, 0x01);  // DDCIO_CTL
  // HDMI Clock
  i2c1_uh2cd_write16(0x8540, 0x12C0);  // SYS_FREQ0_1
  i2c1_uh2cd_write8(0x8630, 0x00);     // LOCKDET_FREQ0
  i2c1_uh2cd_write16(0x8631, 0x0753);  // LOCKDET_REF1_2
  i2c1_uh2cd_write8(0x8670, 0x02);     // NCO_F0_MOD
  i2c1_uh2cd_write16(0x8A0C, 0x12C0);  // CSC_SCLK0_1
  // EDID
  i2c1_uh2cd_write8(0x85E0, 0x01);     // EDID_MODE
  i2c1_uh2cd_write16(0x85E3, 0x0100);  // EDID_LEN1_2
  // EDID Data
  i2c1_uh2cd_write8(0x8C00, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C01, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C02, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C03, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C04, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C05, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C06, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C07, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C08, 0x52);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C09, 0x62);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0A, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0B, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0D, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0E, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C0F, 0x88);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C10, 0x1C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C11, 0x15);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C12, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C13, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C14, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C15, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C16, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C17, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C18, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C19, 0x0D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1A, 0xC9);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1B, 0xA0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1C, 0x57);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1D, 0x47);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1E, 0x98);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C1F, 0x27);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C20, 0x12);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C21, 0x48);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C22, 0x4C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C23, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C24, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C25, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C26, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C27, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C28, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C29, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2A, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2B, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2C, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2D, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2E, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C2F, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C30, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C31, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C32, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C33, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C34, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C35, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C36, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C37, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C38, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C39, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3A, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3B, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3C, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3D, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3E, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C3F, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C40, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C41, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C42, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C43, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C44, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C45, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C46, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C47, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C48, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C49, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4A, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4B, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4C, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4D, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4E, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C4F, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C50, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C51, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C52, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C53, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C54, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C55, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C56, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C57, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C58, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C59, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5A, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5B, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5D, 0xFC);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5E, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C5F, 0x54);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C60, 0x6F);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C61, 0x73);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C62, 0x68);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C63, 0x69);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C64, 0x62);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C65, 0x61);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C66, 0x2D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C67, 0x55);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C68, 0x48);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C69, 0x32);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6A, 0x44);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6B, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6C, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6D, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6E, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C6F, 0xFD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C70, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C71, 0x14);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C72, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C73, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C74, 0xFF);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C75, 0x1D);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C76, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C77, 0x0A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C78, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C79, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7A, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7B, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7C, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7D, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7E, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C7F, 0xCD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C80, 0x02);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C81, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C82, 0x1A);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C83, 0x71);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C84, 0x47);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C85, 0xC6);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C86, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C87, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C88, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C89, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8A, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8B, 0x46);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8C, 0x23);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8D, 0x09);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8E, 0x07);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C8F, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C90, 0x83);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C91, 0x01);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C92, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C93, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C94, 0x65);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C95, 0x03);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C96, 0x0C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C97, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C98, 0x10);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C99, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9A, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9B, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9C, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9D, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9E, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8C9F, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA0, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA1, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA2, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA3, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA4, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA6, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA7, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CA9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAB, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAC, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAD, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAE, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CAF, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB0, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB1, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB2, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB3, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB4, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB5, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB6, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB8, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CB9, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBD, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBE, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CBF, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC0, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC1, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC2, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC3, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC4, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC5, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC6, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC7, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC8, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CC9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCA, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCB, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCD, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CCF, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD0, 0xBD);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD1, 0x3C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD2, 0xB0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD3, 0x8C);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD4, 0x40);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD5, 0x80);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD6, 0x0E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD7, 0x70);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD8, 0x30);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CD9, 0x20);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDA, 0x35);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDC, 0xC0);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDD, 0x78);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CDF, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE0, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE1, 0x1E);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE2, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE3, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE4, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE6, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CE9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CED, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CEF, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF0, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF1, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF2, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF3, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF4, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF5, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF6, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF7, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF8, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CF9, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFA, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFB, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFC, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFD, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFE, 0x00);  // EDID_RAM
  i2c1_uh2cd_write8(0x8CFF, 0x4B);  // EDID_RAM
  // HDCP Setting
  // HDMI SYSTEM
  i2c1_uh2cd_write8(0x8543, 0x02);  // DDC_CTL
  i2c1_uh2cd_write8(0x8544, 0x10);  // HPD_CTL
  // HDMI Audio Setting
  i2c1_uh2cd_write8(0x8600, 0x00);         // AUD_Auto_Mute
  i2c1_uh2cd_write8(0x8602, 0xF3);         // Auto_CMD0
  i2c1_uh2cd_write8(0x8603, 0x02);         // Auto_CMD1
  i2c1_uh2cd_write8(0x8604, 0x0C);         // Auto_CMD2
  i2c1_uh2cd_write8(0x8606, 0x05);         // BUFINIT_START
  i2c1_uh2cd_write8(0x8607, 0x00);         // FS_MUTE
  i2c1_uh2cd_write8(0x8652, 0x02);         // SDO_MODE1
  i2c1_uh2cd_write32(0x8671, 0x020C49BA);  // NCO_48F0A_D
  i2c1_uh2cd_write32(0x8675, 0x01E1B089);  // NCO_44F0A_D
  i2c1_uh2cd_write8(0x8680, 0x00);         // AUD_MODE
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0F1F);  // IntMask
  // Enter Sleep
  i2c1_uh2cd_write16(0x0002, 0x0001);  // SysCtl
#else
#error "Please define a panel in tc358870_panel.h!"
#endif
}

void RS2() {
  // Initialization for Ready (RS2)
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask
  // Set HPDO to "H"
  i2c1_uh2cd_write8(0x854A, 0x01);  // INIT_END
}

void Panel_Init() {
#ifdef LT070ME05000
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
  i2c1_uh2cd_write16(0x0504, 0x0000);
  i2c1_uh2cd_write16(0x0504, 0xaf04);
  HAL_Delay(1);

  // set page address
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x002B);
  i2c1_uh2cd_write16(0x0504, 0x0000);
  i2c1_uh2cd_write16(0x0504, 0x7f07);
  HAL_Delay(1);

  /* SleepOut */
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0011);  // DCSCMD_Q
  HAL_Delay(150);
#endif
}

void RS3() {
#ifdef TPM0551002P
  // MIPI Output Enable(RS3)
  // MIPI Output Setting
  // Stop Video and Audio
  i2c1_uh2cd_write16(0x0004, 0x0C32);  // ConfCtl0
  // Soft Reset CSI-TX and Splitter Block
  i2c1_uh2cd_write16(0x0002, 0x1200);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  // Video Color Format Setting
  i2c1_uh2cd_write8(0x8A02, 0x42);  // VOUT_SYNC0
  // DSI-TX0 Transition Timing
  i2c1_uh2cd_write32(0x0108, 0x00000001);  // DSI_TX_CLKEN
  i2c1_uh2cd_write32(0x010C, 0x00000001);  // DSI_TX_CLKSEL
  i2c1_uh2cd_write32(0x02A0, 0x00000001);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x02AC, 0x000090C7);  // MIPI_PLL_CNF
  Waitx1ms(1);
  i2c1_uh2cd_write32(0x02A0, 0x00000003);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x0118, 0x00000014);  // LANE_ENABLE
  i2c1_uh2cd_write32(0x0120, 0x00001770);  // LINE_INIT_COUNT
  i2c1_uh2cd_write32(0x0124, 0x00000000);  // HSTX_TO_COUNT
  i2c1_uh2cd_write32(0x0128, 0x00000101);  // FUNC_ENABLE
  i2c1_uh2cd_write32(0x0130, 0x00010000);  // DSI_TATO_COUNT
  i2c1_uh2cd_write32(0x0134, 0x00005000);  // DSI_PRESP_BTA_COUNT
  i2c1_uh2cd_write32(0x0138, 0x00010000);  // DSI_PRESP_LPR_COUNT
  i2c1_uh2cd_write32(0x013C, 0x00010000);  // DSI_PRESP_LPW_COUNT
  i2c1_uh2cd_write32(0x0140, 0x00010000);  // DSI_PRESP_HSR_COUNT
  i2c1_uh2cd_write32(0x0144, 0x00010000);  // DSI_PRESP_HSW_COUNT
  i2c1_uh2cd_write32(0x0148, 0x00001000);  // DSI_PR_TO_COUNT
  i2c1_uh2cd_write32(0x014C, 0x00010000);  // DSI_LRX-H_TO_COUNT
  i2c1_uh2cd_write32(0x0150, 0x00000161);  // FUNC_MODE
  i2c1_uh2cd_write32(0x0154, 0x00000001);  // DSI_RX_VC_ENABLE
  i2c1_uh2cd_write32(0x0158, 0x000000C8);  // IND_TO_COUNT
  i2c1_uh2cd_write32(0x0168, 0x0000002A);  // DSI_HSYNC_STOP_COUNT
  i2c1_uh2cd_write32(0x0170, 0x000003E7);  // APF_VDELAYCNT
  i2c1_uh2cd_write32(0x017C, 0x00000081);  // DSI_TX_MODE
  i2c1_uh2cd_write32(0x018C, 0x000000C8);  // DSI_HSYNC_WIDTH
  i2c1_uh2cd_write32(0x0190, 0x00000169);  // DSI_HBPR
  i2c1_uh2cd_write32(0x01A4, 0x00000000);  // DSI_RX_STATE_INT_MASK
  i2c1_uh2cd_write32(0x01C0, 0x00000015);  // DSI_LPRX_THRESH_COUNT
  i2c1_uh2cd_write32(0x0214, 0x00000000);  // APP_SIDE_ERR_INT_MASK
  i2c1_uh2cd_write32(0x021C, 0x00000080);  // DSI_RX_ERR_INT_MASK
  i2c1_uh2cd_write32(0x0224, 0x00000000);  // DSI_LPTX_INT_MASK
  i2c1_uh2cd_write32(0x0254, 0x00000004);  // LPTXTIMECNT
  i2c1_uh2cd_write32(0x0258, 0x001E0003);  // TCLK_HEADERCNT
  i2c1_uh2cd_write32(0x025C, 0x000A0006);  // TCLK_TRAILCNT
  i2c1_uh2cd_write32(0x0260, 0x000A0003);  // THS_HEADERCNT
  i2c1_uh2cd_write32(0x0264, 0x00003E80);  // TWAKEUPCNT
  i2c1_uh2cd_write32(0x0268, 0x0000000C);  // TCLK_POSTCNT
  i2c1_uh2cd_write32(0x026C, 0x000A0004);  // THS_TRAILCNT
  i2c1_uh2cd_write32(0x0270, 0x00000020);  // HSTXVREGCNT
  i2c1_uh2cd_write32(0x0274, 0x0000001F);  // HSTXVREGEN
  i2c1_uh2cd_write32(0x0278, 0x00040005);  // BTA_COUNT
  i2c1_uh2cd_write32(0x027C, 0x00000002);  // DPHY_TX ADJUST
  i2c1_uh2cd_write32(0x011C, 0x00000001);  // DSITX_START
  // DSI-TX1 Transition Timing
  // Command Transmission Before Video Start
  i2c1_uh2cd_write16(0x0500, 0x0000);      // CMD_SEL
  i2c1_uh2cd_write32(0x0110, 0x00000016);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000016);  // MODE_CONFIG
  // LCD Initialization
  // Soft Reset
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0001);  // DCSCMD_Q
  Waitx1ms(5);
  // Set Pixel Format
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x773A);  // DCSCMD_Q
  Waitx1us(200);
  // Set Column Address
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x002A);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0400);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00FF);  // DCSCMD_Q
  Waitx1us(200);
  // Set Page Address
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x002B);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0600);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x003F);  // DCSCMD_Q
  Waitx1us(200);
  // Set Tear On
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0035);  // DCSCMD_Q
  Waitx1us(200);
  // Set Tear Scanline
  i2c1_uh2cd_write16(0x0504, 0x8039);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0003);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0044);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0000);  // DCSCMD_Q
  Waitx1us(200);
  // Write Display Brightness
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xFF51);  // DCSCMD_Q
  Waitx1us(200);
  // Write Control Display
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x2453);  // DCSCMD_Q
  Waitx1us(200);
  // Adaptive Brightness Control
  i2c1_uh2cd_write16(0x0504, 0x0015);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0155);  // DCSCMD_Q
  Waitx1us(200);
  // Exit Sleep
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0011);  // DCSCMD_Q
  Waitx1ms(120);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00B0);  // DCSCMD_Q
  Waitx1us(200);
  // Backlight Control 4
  i2c1_uh2cd_write16(0x0504, 0x8029);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0014);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x7DCE);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x4840);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x6756);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x8878);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xA798);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xC3B5);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xDED1);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xF2E9);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0xFFFA);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0004);  // DCSCMD_Q
  // Split Control
  i2c1_uh2cd_write16(0x5000, 0x0100);  // STX0_CTL
  i2c1_uh2cd_write16(0x500C, 0x0000);  // STX0_FPX
  i2c1_uh2cd_write16(0x500E, 0x01DF);  // STX0_LPX
  i2c1_uh2cd_write16(0x5080, 0x0100);  // STX1_CTL
  i2c1_uh2cd_write16(0x508C, 0x0000);  // STX1_FPX
  i2c1_uh2cd_write16(0x508E, 0x01DF);  // STX1_LPX
  i2c1_uh2cd_write16(0x7080, 0x0080);  // STX_DBG
  i2c1_uh2cd_write16(0x5008, 0x0CA8);  // STX0_WC
  i2c1_uh2cd_write16(0x5088, 0x0CA8);  // STX1_WC
  // Enable Interrupt
  i2c1_uh2cd_write8(0x8502, 0xFF);     // SYS_INT
  i2c1_uh2cd_write8(0x8503, 0xFF);     // CLK_INT
  i2c1_uh2cd_write8(0x8504, 0xFF);     // PACKET_INT
  i2c1_uh2cd_write8(0x8505, 0xFF);     // CBIT_INT
  i2c1_uh2cd_write8(0x8506, 0xFF);     // AUDIO_INT
  i2c1_uh2cd_write8(0x850B, 0xFF);     // MISC_INT
  i2c1_uh2cd_write16(0x0014, 0x0F3F);  // IntStatus
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask
  // Start Video TX
  i2c1_uh2cd_write16(0x0004, 0x0C35);  // ConfCtl0
  i2c1_uh2cd_write16(0x0006, 0x0000);  // ConfCtl1
  // Command Transmission After Video Start.
  i2c1_uh2cd_write32(0x0110, 0x00000006);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000006);  // MODE_CONFIG
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Interface Setting
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x14B3);  // DCSCMD_Q
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x03B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Set Display On
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0029);  // DCSCMD_Q
  Waitx1ms(32);
#elif defined LT070ME05000
  // MIPI Output Enable(RS3)
  // MIPI Output Setting
  // Stop Video and Audio
  i2c1_uh2cd_write16(0x0004, 0x0C32);  // ConfCtl0
  // Soft Reset CSI-TX and Splitter Block
  i2c1_uh2cd_write16(0x0002, 0x1200);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  // Video Color Format Setting
  i2c1_uh2cd_write8(0x8A02, 0x42);  // VOUT_SYNC0
  // DSI-TX0 Transition Timing
  i2c1_uh2cd_write32(0x0108, 0x00000001);  // DSI_TX_CLKEN
  i2c1_uh2cd_write32(0x010C, 0x00000001);  // DSI_TX_CLKSEL
  i2c1_uh2cd_write32(0x02A0, 0x00000001);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x02AC, 0x000090CC);  // MIPI_PLL_CNF
  Waitx1ms(1);
  i2c1_uh2cd_write32(0x02A0, 0x00000003);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x0118, 0x00000014);  // LANE_ENABLE
  i2c1_uh2cd_write32(0x0120, 0x00001770);  // LINE_INIT_COUNT
  i2c1_uh2cd_write32(0x0124, 0x00000000);  // HSTX_TO_COUNT
  i2c1_uh2cd_write32(0x0128, 0x00000101);  // FUNC_ENABLE
  i2c1_uh2cd_write32(0x0130, 0x00010000);  // DSI_TATO_COUNT
  i2c1_uh2cd_write32(0x0134, 0x00005000);  // DSI_PRESP_BTA_COUNT
  i2c1_uh2cd_write32(0x0138, 0x00010000);  // DSI_PRESP_LPR_COUNT
  i2c1_uh2cd_write32(0x013C, 0x00010000);  // DSI_PRESP_LPW_COUNT
  i2c1_uh2cd_write32(0x0140, 0x00010000);  // DSI_PRESP_HSR_COUNT
  i2c1_uh2cd_write32(0x0144, 0x00010000);  // DSI_PRESP_HSW_COUNT
  i2c1_uh2cd_write32(0x0148, 0x00001000);  // DSI_PR_TO_COUNT
  i2c1_uh2cd_write32(0x014C, 0x00010000);  // DSI_LRX-H_TO_COUNT
  i2c1_uh2cd_write32(0x0150, 0x00000161);  // FUNC_MODE
  i2c1_uh2cd_write32(0x0154, 0x00000001);  // DSI_RX_VC_ENABLE
  i2c1_uh2cd_write32(0x0158, 0x000000C8);  // IND_TO_COUNT
  i2c1_uh2cd_write32(0x0168, 0x0000002A);  // DSI_HSYNC_STOP_COUNT
  i2c1_uh2cd_write32(0x0170, 0x00000411);  // APF_VDELAYCNT
  i2c1_uh2cd_write32(0x017C, 0x00000081);  // DSI_TX_MODE
  i2c1_uh2cd_write32(0x018C, 0x00000066);  // DSI_HSYNC_WIDTH
  i2c1_uh2cd_write32(0x0190, 0x00000124);  // DSI_HBPR
  i2c1_uh2cd_write32(0x01A4, 0x00000000);  // DSI_RX_STATE_INT_MASK
  i2c1_uh2cd_write32(0x01C0, 0x00000015);  // DSI_LPRX_THRESH_COUNT
  i2c1_uh2cd_write32(0x0214, 0x00000000);  // APP_SIDE_ERR_INT_MASK
  i2c1_uh2cd_write32(0x021C, 0x00000080);  // DSI_RX_ERR_INT_MASK
  i2c1_uh2cd_write32(0x0224, 0x00000000);  // DSI_LPTX_INT_MASK
  i2c1_uh2cd_write32(0x0254, 0x00000004);  // LPTXTIMECNT
  i2c1_uh2cd_write32(0x0258, 0x001E0003);  // TCLK_HEADERCNT
  i2c1_uh2cd_write32(0x025C, 0x000A0006);  // TCLK_TRAILCNT
  i2c1_uh2cd_write32(0x0260, 0x000A0003);  // THS_HEADERCNT
  i2c1_uh2cd_write32(0x0264, 0x00003E80);  // TWAKEUPCNT
  i2c1_uh2cd_write32(0x0268, 0x0000000C);  // TCLK_POSTCNT
  i2c1_uh2cd_write32(0x026C, 0x000A0004);  // THS_TRAILCNT
  i2c1_uh2cd_write32(0x0270, 0x00000020);  // HSTXVREGCNT
  i2c1_uh2cd_write32(0x0274, 0x0000001F);  // HSTXVREGEN
  i2c1_uh2cd_write32(0x0278, 0x00040005);  // BTA_COUNT
  i2c1_uh2cd_write32(0x027C, 0x00000002);  // DPHY_TX ADJUST
  i2c1_uh2cd_write32(0x011C, 0x00000001);  // DSITX_START
  // DSI-TX1 Transition Timing
  // Command Transmission Before Video Start
  i2c1_uh2cd_write16(0x0500, 0x0000);      // CMD_SEL
  i2c1_uh2cd_write32(0x0110, 0x00000016);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000016);  // MODE_CONFIG
  // LCD Initialization
  Panel_Init();
  // Split Control
  i2c1_uh2cd_write16(0x5000, 0x0100);  // STX0_CTL
  i2c1_uh2cd_write16(0x500C, 0x0000);  // STX0_FPX
  i2c1_uh2cd_write16(0x500E, 0x01DF);  // STX0_LPX
  i2c1_uh2cd_write16(0x5080, 0x0100);  // STX1_CTL
  i2c1_uh2cd_write16(0x508C, 0x0000);  // STX1_FPX
  i2c1_uh2cd_write16(0x508E, 0x01DF);  // STX1_LPX
  i2c1_uh2cd_write16(0x7080, 0x0080);  // STX_DBG
  i2c1_uh2cd_write16(0x5008, 0x0E10);  // STX0_WC
  i2c1_uh2cd_write16(0x5088, 0x0E10);  // STX1_WC
  // Enable Interrupt
  i2c1_uh2cd_write8(0x8502, 0xFF);     // SYS_INT
  i2c1_uh2cd_write8(0x8503, 0xFF);     // CLK_INT
  i2c1_uh2cd_write8(0x8504, 0xFF);     // PACKET_INT
  i2c1_uh2cd_write8(0x8505, 0xFF);     // CBIT_INT
  i2c1_uh2cd_write8(0x8506, 0xFF);     // AUDIO_INT
  i2c1_uh2cd_write8(0x850B, 0xFF);     // MISC_INT
  i2c1_uh2cd_write16(0x0014, 0x0F3F);  // IntStatus
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask

  // Start Video TX
  i2c1_uh2cd_write16(0x0004, 0x0C35);  // ConfCtl0
  i2c1_uh2cd_write16(0x0006, 0x0000);  // ConfCtl1
  // Command Transmission After Video Start.
  i2c1_uh2cd_write32(0x0110, 0x00000006);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000006);  // MODE_CONFIG
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Interface Setting
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x14B3);  // DCSCMD_Q
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x03B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Set Display On
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0029);  // DCSCMD_Q
  Waitx1ms(32);
#else
#error "Please define a panel in tc358870_panel.h!"
#endif
}

void RS4() {
  // MIPI Output Disable(RS4)
  // Reset Display by H/W reset
  // Stop CSI output
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0D3F);  // IntMask
}

void RS5() {
  // MIPI Output Disable & Sleep(RS5)
  // Reset Display by H/W reset
  // Stop CSI output
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  // Enable Interrupt
  i2c1_uh2cd_write16(0x0016, 0x0F1F);  // IntMask
  // Enter Sleep
  i2c1_uh2cd_write16(0x0002, 0x0001);  // SysCtl
}

void RS_DO() {
  // Auto Disp Off(RS_DO)
  // Software Reset
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  i2c1_uh2cd_write16(0x0006, 0x0008);  // ConfCtl1
  i2c1_uh2cd_write16(0x0002, 0x1200);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
  i2c1_uh2cd_write16(0x0006, 0x0000);  // ConfCtl1
  i2c1_uh2cd_write16(0x7000, 0x0009);  // CB_CTL

  // DSI-TX1 Transition Timing
  i2c1_uh2cd_write32(0x0308, 0x00000001);  // DSI_TX_CLKEN
  i2c1_uh2cd_write32(0x030C, 0x00000001);  // DSI_TX_CLKSEL
  i2c1_uh2cd_write32(0x04A0, 0x00000001);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x04AC, 0x000090CC);  // MIPI_PLL_CNF
  Waitx1ms(1);
  i2c1_uh2cd_write32(0x04A0, 0x00000003);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x0318, 0x00000014);  // LANE_ENABLE
  i2c1_uh2cd_write32(0x0320, 0x00001770);  // LINE_INIT_COUNT
  i2c1_uh2cd_write32(0x0324, 0x00000000);  // HSTX_TO_COUNT
  i2c1_uh2cd_write32(0x0328, 0x00000101);  // FUNC_ENABLE
  i2c1_uh2cd_write32(0x0330, 0x00010000);  // DSI_TATO_COUNT
  i2c1_uh2cd_write32(0x0334, 0x00005000);  // DSI_PRESP_BTA_COUNT
  i2c1_uh2cd_write32(0x0338, 0x00010000);  // DSI_PRESP_LPR_COUNT
  i2c1_uh2cd_write32(0x033C, 0x00010000);  // DSI_PRESP_LPW_COUNT
  i2c1_uh2cd_write32(0x0340, 0x00010000);  // DSI_PRESP_HSR_COUNT
  i2c1_uh2cd_write32(0x0344, 0x00010000);  // DSI_PRESP_HSW_COUNT
  i2c1_uh2cd_write32(0x0348, 0x00001000);  // DSI_PR_TO_COUNT
  i2c1_uh2cd_write32(0x034C, 0x00010000);  // DSI_LRX-H_TO_COUNT
  i2c1_uh2cd_write32(0x0350, 0x00000161);  // FUNC_MODE
  i2c1_uh2cd_write32(0x0354, 0x00000001);  // DSI_RX_VC_ENABLE
  i2c1_uh2cd_write32(0x0358, 0x000000C8);  // IND_TO_COUNT
  i2c1_uh2cd_write32(0x0368, 0x0000002A);  // DSI_HSYNC_STOP_COUNT
  i2c1_uh2cd_write32(0x0370, 0x000009E9);  // APF_VDELAYCNT
  i2c1_uh2cd_write32(0x037C, 0x00000081);  // DSI_TX_MODE
  i2c1_uh2cd_write32(0x038C, 0x00000001);  // DSI_HSYNC_WIDTH
  i2c1_uh2cd_write32(0x0390, 0x00000104);  // DSI_HBPR
  i2c1_uh2cd_write32(0x03A4, 0x00000000);  // DSI_RX_STATE_INT_MASK
  i2c1_uh2cd_write32(0x03C0, 0x00000015);  // DSI_LPRX_THRESH_COUNT
  i2c1_uh2cd_write32(0x0414, 0x00000000);  // APP_SIDE_ERR_INT_MASK
  i2c1_uh2cd_write32(0x041C, 0x00000080);  // DSI_RX_ERR_INT_MASK
  i2c1_uh2cd_write32(0x0424, 0x00000000);  // DSI_LPTX_INT_MASK
  i2c1_uh2cd_write32(0x0454, 0x00000004);  // LPTXTIMECNT
  i2c1_uh2cd_write32(0x0458, 0x001E0003);  // TCLK_HEADERCNT
  i2c1_uh2cd_write32(0x045C, 0x000A0006);  // TCLK_TRAILCNT
  i2c1_uh2cd_write32(0x0460, 0x000A0003);  // THS_HEADERCNT
  i2c1_uh2cd_write32(0x0464, 0x00003E80);  // TWAKEUPCNT
  i2c1_uh2cd_write32(0x0468, 0x0000000C);  // TCLK_POSTCNT
  i2c1_uh2cd_write32(0x046C, 0x000A0004);  // THS_TRAILCNT
  i2c1_uh2cd_write32(0x0470, 0x00000020);  // HSTXVREGCNT
  i2c1_uh2cd_write32(0x0474, 0x0000001F);  // HSTXVREGEN
  i2c1_uh2cd_write32(0x0478, 0x00040005);  // BTA_COUNT
  i2c1_uh2cd_write32(0x047C, 0x00000002);  // DPHY_TX ADJUST
  i2c1_uh2cd_write32(0x031C, 0x00000001);  // DSITX_START
  // DSI-TX0 Transition Timing
  i2c1_uh2cd_write32(0x0108, 0x00000001);  // DSI_TX_CLKEN
  i2c1_uh2cd_write32(0x010C, 0x00000001);  // DSI_TX_CLKSEL
  i2c1_uh2cd_write32(0x02A0, 0x00000001);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x02AC, 0x000090CC);  // MIPI_PLL_CNF
  Waitx1ms(1);
  i2c1_uh2cd_write32(0x02A0, 0x00000003);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x0118, 0x00000014);  // LANE_ENABLE
  i2c1_uh2cd_write32(0x0120, 0x00001770);  // LINE_INIT_COUNT
  i2c1_uh2cd_write32(0x0124, 0x00000000);  // HSTX_TO_COUNT
  i2c1_uh2cd_write32(0x0128, 0x00000101);  // FUNC_ENABLE
  i2c1_uh2cd_write32(0x0130, 0x00010000);  // DSI_TATO_COUNT
  i2c1_uh2cd_write32(0x0134, 0x00005000);  // DSI_PRESP_BTA_COUNT
  i2c1_uh2cd_write32(0x0138, 0x00010000);  // DSI_PRESP_LPR_COUNT
  i2c1_uh2cd_write32(0x013C, 0x00010000);  // DSI_PRESP_LPW_COUNT
  i2c1_uh2cd_write32(0x0140, 0x00010000);  // DSI_PRESP_HSR_COUNT
  i2c1_uh2cd_write32(0x0144, 0x00010000);  // DSI_PRESP_HSW_COUNT
  i2c1_uh2cd_write32(0x0148, 0x00001000);  // DSI_PR_TO_COUNT
  i2c1_uh2cd_write32(0x014C, 0x00010000);  // DSI_LRX-H_TO_COUNT
  i2c1_uh2cd_write32(0x0150, 0x00000161);  // FUNC_MODE
  i2c1_uh2cd_write32(0x0154, 0x00000001);  // DSI_RX_VC_ENABLE
  i2c1_uh2cd_write32(0x0158, 0x000000C8);  // IND_TO_COUNT
  i2c1_uh2cd_write32(0x0168, 0x0000002A);  // DSI_HSYNC_STOP_COUNT
  i2c1_uh2cd_write32(0x0170, 0x000009E9);  // APF_VDELAYCNT
  i2c1_uh2cd_write32(0x017C, 0x00000081);  // DSI_TX_MODE
  i2c1_uh2cd_write32(0x018C, 0x00000066);  // DSI_HSYNC_WIDTH
  i2c1_uh2cd_write32(0x0190, 0x00000124);  // DSI_HBPR
  i2c1_uh2cd_write32(0x01A4, 0x00000000);  // DSI_RX_STATE_INT_MASK
  i2c1_uh2cd_write32(0x01C0, 0x00000015);  // DSI_LPRX_THRESH_COUNT
  i2c1_uh2cd_write32(0x0214, 0x00000000);  // APP_SIDE_ERR_INT_MASK
  i2c1_uh2cd_write32(0x021C, 0x00000080);  // DSI_RX_ERR_INT_MASK
  i2c1_uh2cd_write32(0x0224, 0x00000000);  // DSI_LPTX_INT_MASK
  i2c1_uh2cd_write32(0x0254, 0x00000004);  // LPTXTIMECNT
  i2c1_uh2cd_write32(0x0258, 0x001E0003);  // TCLK_HEADERCNT
  i2c1_uh2cd_write32(0x025C, 0x000A0006);  // TCLK_TRAILCNT
  i2c1_uh2cd_write32(0x0260, 0x000A0003);  // THS_HEADERCNT
  i2c1_uh2cd_write32(0x0264, 0x00003E80);  // TWAKEUPCNT
  i2c1_uh2cd_write32(0x0268, 0x0000000C);  // TCLK_POSTCNT
  i2c1_uh2cd_write32(0x026C, 0x000A0004);  // THS_TRAILCNT
  i2c1_uh2cd_write32(0x0270, 0x00000020);  // HSTXVREGCNT
  i2c1_uh2cd_write32(0x0274, 0x0000001F);  // HSTXVREGEN
  i2c1_uh2cd_write32(0x0278, 0x00040005);  // BTA_COUNT
  i2c1_uh2cd_write32(0x027C, 0x00000002);  // DPHY_TX ADJUST
  i2c1_uh2cd_write32(0x011C, 0x00000001);  // DSITX_START
  // Command Transmission Before Video Start
  i2c1_uh2cd_write16(0x0500, 0x0004);  // CMD_SEL
  // Split Control
  i2c1_uh2cd_write16(0x5000, 0x0000);  // STX0_CTL
  i2c1_uh2cd_write16(0x500C, 0x0000);  // STX0_FPX
  i2c1_uh2cd_write16(0x500E, 0x04AF);  // STX0_LPX
  i2c1_uh2cd_write16(0x5080, 0x0000);  // STX1_CTL
  i2c1_uh2cd_write16(0x508C, 0x0000);  // STX1_FPX
  i2c1_uh2cd_write16(0x508E, 0x04AF);  // STX1_LPX
  // Color Bar Setting
  i2c1_uh2cd_write16(0x7008, 0x0020);  // CB_HSW
  i2c1_uh2cd_write16(0x700A, 0x0005);  // CB_VSW
  i2c1_uh2cd_write16(0x700C, 0x053C);  // CB_Htotal
  i2c1_uh2cd_write16(0x700E, 0x078E);  // CB_Vtotal
  i2c1_uh2cd_write16(0x7010, 0x04B0);  // CB_Hact
  i2c1_uh2cd_write16(0x7012, 0x0780);  // CB_Vact
  i2c1_uh2cd_write16(0x7014, 0x005C);  // CB_Hstart
  i2c1_uh2cd_write16(0x7016, 0x000B);  // CB_Vstart
  i2c1_uh2cd_write16(0x7000, 0x000D);  // CB_CTL

  // Start Video TX
  i2c1_uh2cd_write16(0x0004, 0x0C37);  // ConfCtl0
  // Command Transmission After Video Start. HS command TX
  i2c1_uh2cd_write32(0x0110, 0x00000006);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000006);  // MODE_CONFIG
  // Set Display Off
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0028);  // DCSCMD_Q
  Waitx1ms(100);
  // Enter Sleep
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0010);  // DCSCMD_Q
  Waitx1ms(200);
  i2c1_uh2cd_write16(0x0004, 0x0C34);  // ConfCtl0
  i2c1_uh2cd_write16(0x7000, 0x0000);  // CB_CTL
}

void RS_ColorBar() {
  i2c1_uh2cd_write16(0x0004, 0x0C32);  // ConfCtl0
                                       // Soft Reset CSI-TX and Splitter Block
  i2c1_uh2cd_write16(0x0002, 0x1200);  // SysCtl
  i2c1_uh2cd_write16(0x0002, 0x0000);  // SysCtl
                                       // Video Color Format Setting
  i2c1_uh2cd_write8(0x8A02, 0x42);     // VOUT_SYNC0
  // DSI-TX0 Transition Timing
  i2c1_uh2cd_write32(0x0108, 0x00000001);  // DSI_TX_CLKEN
  i2c1_uh2cd_write32(0x010C, 0x00000001);  // DSI_TX_CLKSEL
  i2c1_uh2cd_write32(0x02A0, 0x00000001);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x02AC, 0x00009086);  // MIPI_PLL_CNF
  Waitx1ms(1);
  i2c1_uh2cd_write32(0x02A0, 0x00000003);  // MIPI_PLL_CONTROL
  i2c1_uh2cd_write32(0x0118, 0x00000011);  // LANE_ENABLE
  i2c1_uh2cd_write32(0x0120, 0x00001770);  // LINE_INIT_COUNT
  i2c1_uh2cd_write32(0x0124, 0x00000000);  // HSTX_TO_COUNT
  i2c1_uh2cd_write32(0x0128, 0x00000101);  // FUNC_ENABLE
  i2c1_uh2cd_write32(0x0130, 0x00010000);  // DSI_TATO_COUNT
  i2c1_uh2cd_write32(0x0134, 0x00005000);  // DSI_PRESP_BTA_COUNT
  i2c1_uh2cd_write32(0x0138, 0x00010000);  // DSI_PRESP_LPR_COUNT
  i2c1_uh2cd_write32(0x013C, 0x00010000);  // DSI_PRESP_LPW_COUNT
  i2c1_uh2cd_write32(0x0140, 0x00010000);  // DSI_PRESP_HSR_COUNT
  i2c1_uh2cd_write32(0x0144, 0x00010000);  // DSI_PRESP_HSW_COUNT
  i2c1_uh2cd_write32(0x0148, 0x00001000);  // DSI_PR_TO_COUNT
  i2c1_uh2cd_write32(0x014C, 0x00010000);  // DSI_LRX-H_TO_COUNT
  i2c1_uh2cd_write32(0x0150, 0x00000161);  // FUNC_MODE
  i2c1_uh2cd_write32(0x0154, 0x00000001);  // DSI_RX_VC_ENABLE
  i2c1_uh2cd_write32(0x0158, 0x000000C8);  // IND_TO_COUNT
  i2c1_uh2cd_write32(0x0168, 0x0000002A);  // DSI_HSYNC_STOP_COUNT
  i2c1_uh2cd_write32(0x0170, 0x00000798);  // APF_VDELAYCNT
  i2c1_uh2cd_write32(0x017C, 0x00000081);  // DSI_TX_MODE
  i2c1_uh2cd_write32(0x018C, 0x000000C3);  // DSI_HSYNC_WIDTH
  i2c1_uh2cd_write32(0x0190, 0x00000145);  // DSI_HBPR
  i2c1_uh2cd_write32(0x01A4, 0x00000000);  // DSI_RX_STATE_INT_MASK
  i2c1_uh2cd_write32(0x01C0, 0x00000015);  // DSI_LPRX_THRESH_COUNT
  i2c1_uh2cd_write32(0x0214, 0x00000000);  // APP_SIDE_ERR_INT_MASK
  i2c1_uh2cd_write32(0x021C, 0x00000080);  // DSI_RX_ERR_INT_MASK
  i2c1_uh2cd_write32(0x0224, 0x00000000);  // DSI_LPTX_INT_MASK
  i2c1_uh2cd_write32(0x0254, 0x00000004);  // LPTXTIMECNT
  i2c1_uh2cd_write32(0x0258, 0x001E0003);  // TCLK_HEADERCNT
  i2c1_uh2cd_write32(0x025C, 0x000A0006);  // TCLK_TRAILCNT
  i2c1_uh2cd_write32(0x0260, 0x000A0003);  // THS_HEADERCNT
  i2c1_uh2cd_write32(0x0264, 0x00003E80);  // TWAKEUPCNT
  i2c1_uh2cd_write32(0x0268, 0x0000000C);  // TCLK_POSTCNT
  i2c1_uh2cd_write32(0x026C, 0x000A0004);  // THS_TRAILCNT
  i2c1_uh2cd_write32(0x0270, 0x00000020);  // HSTXVREGCNT
  i2c1_uh2cd_write32(0x0274, 0x00000003);  // HSTXVREGEN
  i2c1_uh2cd_write32(0x0278, 0x00040005);  // BTA_COUNT
  i2c1_uh2cd_write32(0x027C, 0x00000002);  // DPHY_TX ADJUST
  i2c1_uh2cd_write32(0x011C, 0x00000001);  // DSITX_START
  // Command Transmission Before Video Start
  i2c1_uh2cd_write16(0x0500, 0x0000);      // CMD_SEL
  i2c1_uh2cd_write32(0x0110, 0x00000014);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000014);  // MODE_CONFIG
  // LCD Initialization
  Panel_Init();
  // Split Control
  i2c1_uh2cd_write16(0x5000, 0x0100);  // STX0_CTL
  i2c1_uh2cd_write16(0x500C, 0x0000);  // STX0_FPX
  i2c1_uh2cd_write16(0x500E, 0x01DF);  // STX0_LPX
  i2c1_uh2cd_write16(0x5080, 0x0100);  // STX1_CTL
  i2c1_uh2cd_write16(0x508C, 0x0000);  // STX1_FPX
  i2c1_uh2cd_write16(0x508E, 0x01DF);  // STX1_LPX
  // Color Bar Setting
  i2c1_uh2cd_write16(0x7008, 0x003C);  // CB_HSW
  i2c1_uh2cd_write16(0x700A, 0x0004);  // CB_VSW
  i2c1_uh2cd_write16(0x700C, 0x024E);  // CB_Htotal
  i2c1_uh2cd_write16(0x700E, 0x029A);  // CB_Vtotal
  i2c1_uh2cd_write16(0x7010, 0x01E0);  // CB_Hact
  i2c1_uh2cd_write16(0x7012, 0x0280);  // CB_Vact
  i2c1_uh2cd_write16(0x7014, 0x0064);  // CB_Hstart
  i2c1_uh2cd_write16(0x7016, 0x0012);  // CB_Vstart
  i2c1_uh2cd_write16(0x7000, 0x000D);  // CB_CTL
  // Start Video TX
  i2c1_uh2cd_write16(0x0004, 0x0C35);  // ConfCtl0
  // Command Transmission After Video Start. HS command TX
  i2c1_uh2cd_write32(0x0110, 0x00000006);  // MODE_CONFIG
  i2c1_uh2cd_write32(0x0310, 0x00000006);  // MODE_CONFIG
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x00B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Interface Setting
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x14B3);  // DCSCMD_Q
  Waitx1ms(32);
  // MCAP
  i2c1_uh2cd_write16(0x0504, 0x0023);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x03B0);  // DCSCMD_Q
  Waitx1ms(32);
  // Set Display On
  i2c1_uh2cd_write16(0x0504, 0x0005);  // DCSCMD_Q
  i2c1_uh2cd_write16(0x0504, 0x0029);  // DCSCMD_Q
  Waitx1ms(32);
}

void turn_on_panel() {
  panel_power_control(GPIO_PIN_SET);  // turn on panel power
  HAL_Delay(20);
  panel_reset_control(GPIO_PIN_RESET);  // reset panel
  HAL_Delay(10);
  panel_reset_control(GPIO_PIN_SET);
  HAL_Delay(10);
  RS3();
  HAL_Delay(200);
  board_audio_control(GPIO_PIN_SET);      // turn on audio
  panel_backlight_control(GPIO_PIN_SET);  // turn on backlight
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
