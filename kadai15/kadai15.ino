#include <SPI.h>
const int SPI_SCLK = 2; //GP2
const int SPI_MOSI = 3; //GP3
const int SPI_MISO = 4; //GP4
const int SPI_CS = 5;   //GP5

short DA, spiData;
char ch = 0;    //チャンネル
float v = 2.0;  //電圧定義
int i,t = 0;
unsigned long tm;
int hz[8] = {1, 2, 3, 4, 5, 7, 9, 10};
float outputValue;

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
  if(Serial.available()>0){
    v = Serial.parseFloat();
  }
  for(i=0;i<8;i++){
    ch = i;
    DAout(ch, v);
  }
  delay(10);
}

void DAout(char channel, float voltage) {
  tm = micros();
  int a = channel;
  outputValue = voltage*sin(2.0*PI*(float)tm*hz[a]/1000000.0);
  //DA = map(outputValue, -5, 5, 0, 0x3FF);
  if(outputValue>0){
    DA = outputValue * 0x3FF / 5.0 + 0x200;    
  } else {
    DA = (-outputValue) * 0x3FF / 5.0;
    DA=0x200-DA;
  }
  spiData = (((channel&0x07)+1)<<12) | ((int)(DA&0x3FF)<<2);
  SPI.transfer16(spiData);
}
