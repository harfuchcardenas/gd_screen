#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

//#define __DUE__

GDClass GD;
byte ft8xx_model;

void TFT_4_3()
{ 
  
  Serial.println("READY");
  GD.wr16(REG_HCYCLE, 548);
  GD.wr16(REG_HOFFSET, 43);
  GD.wr16(REG_HSYNC0, 0);
  GD.wr16(REG_HSYNC1, 41);
  GD.wr16(REG_VCYCLE, 292);
  GD.wr16(REG_VOFFSET, 12);
  GD.wr16(REG_VSYNC0, 0);
  GD.wr16(REG_VSYNC1, 10);
  GD.wr16(REG_SWIZZLE, 0);
  GD.wr16(REG_PCLK_POL, 1);
  GD.wr16(REG_CSPREAD, 1);
  GD.wr16(REG_HSIZE, 800);
  GD.wr16(REG_VSIZE, 482);
}

void setup()
{
  pinMode(4, OUTPUT);           // set pin to output
  digitalWrite(4, HIGH);       // turn on pullup resistors
  delay(20000);
  GD.begin(0,15,5);
  TFT_4_3();
}
void loop()
{
  GD.ClearColorRGB(0x103000);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  GD.swap();
}