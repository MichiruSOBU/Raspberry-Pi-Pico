const int analogOutPin = 21; //GP21
unsigned long t;
int outputValue = 128;

void setup() {
  analogWriteFreq(60000); //PWM set to 60kHz
}

void loop() {
  t = micros();
  outputValue = (int) (128.0 * sin(2.0*PI*100.0*(float)t/1000000.0)+127.0);
  analogWrite(analogOutPin, outputValue);
}
