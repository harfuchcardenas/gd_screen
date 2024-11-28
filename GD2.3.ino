#include <EEPROM.h>
#include <SPI.h>
#include "GD2.h"
#include "transports/wiring.h"

#define SPIDRIVER
#define ESP32

extern GDClass GD;
extern byte ft8xx_model;

void TFT_4_3()
{
  GDTransport GDT;
  GDT.hostcmd(0x44); //send CLKEXT to FT81X
  GDT.hostcmd(0x00); //send ACTIVE to FT81X

  GD.wr16(REG_HSIZE, 800);
  GD.wr16(REG_HCYCLE, 928);
  GD.wr16(REG_HOFFSET, 88);
  GD.wr16(REG_HSYNC0, 0);
  GD.wr16(REG_HSYNC1, 48);
  GD.wr16(REG_VSIZE, 480);
  GD.wr16(REG_VCYCLE, 525);
  GD.wr16(REG_VOFFSET, 32);
  GD.wr16(REG_VSYNC0, 0);
  GD.wr16(REG_VSYNC1, 3);
  GD.wr16(REG_PCLK, 2);
  GD.wr16(REG_SWIZZLE, 0);
  GD.wr16(REG_PCLK_POL, 1);
  GD.wr16(REG_CSPREAD, 0);
  GD.wr16(REG_DITHER, 1);
  GD.wr16(REG_ROTATE, 0);
  GD.swap();
}
void setup()
{
  Serial.begin(115200);
  GD.begin(0, 17, 22);
  TFT_4_3();

}
void loop()
{
  GD.ClearColorRGB(0x103000);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
  delay(1000);
}
