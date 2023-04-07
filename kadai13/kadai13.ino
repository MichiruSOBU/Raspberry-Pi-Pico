const int analogOutPin = 21; //GP21
unsigned long t;
int outputValue = 128;
unsigned int buzzer[8] = {261,293,329,349,391,440,493,523}; //ドレミの周波数
int onkai = 0;

void setup() {
  analogWriteFreq(60000); //PWM set to 60kHz
}

void loop() {
  t = micros();
  if(Serial.available()>0){
    onkai = Serial.read();
    outputValue = (int) (128.0 * sin(2.0*PI*buzzer[onkai]*(float)t/1000000.0)+127.0);
    analogWrite(analogOutPin, outputValue);
  }
  delay(15);
}