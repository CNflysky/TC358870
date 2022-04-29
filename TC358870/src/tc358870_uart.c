#include "tc358870_uart.h"

#include <stdarg.h>
#include <usbd_cdc_if.h>

uint8_t printf_u(const char *format, ...) {
  va_list args;
  uint8_t buff[APP_TX_DATA_SIZE] = {0x00};
  va_start(args, format);
  uint32_t length = vsprintf((char *)buff, format, args);
  vprintf(format, args);
  va_end(args);
  return CDC_Transmit_FS(buff, length);
}