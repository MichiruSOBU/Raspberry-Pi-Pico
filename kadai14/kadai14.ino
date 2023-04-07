#include <SPI.h>
const int SPI_SCLK = 2; //GP2
const int SPI_MOSI = 3; //GP3
const int SPI_MISO = 4; //GP4
const int SPI_CS = 5;   //GP5

short DA, spiData;
char channel = 0;
int t = 0;
//unsigned long time;

void setup() {
  Serial.begin(9600);
  SPI.setRX(SPI_MISO);
  SPI.setCS(SPI_CS);
  SPI.setSCK(SPI_SCLK);
  SPI.setTX(SPI_MOSI);
  SPI.begin(true);  //true=hardware CS, false=software CS
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  t = (t+1)%2;
  if(t==0){
    DA=0x3FF;
  }else{
    DA=0;
  }
  spiData = (((channel&0x07)+1)<<12) | ((int) (DA&0x3FF)<<2);
  SPI.transfer16(spiData);
}
