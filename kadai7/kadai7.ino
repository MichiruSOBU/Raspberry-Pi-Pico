const int ADC0 = 26; //GP26
const int ADC1 = 27; //GP27
const int ADC2 = 28; //GP28

int ax, ay, az;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  ax = analogRead(ADC1);
  ay = analogRead(ADC0);
  az = analogRead(ADC2);
  Serial.write(ax>>8);
  Serial.write(ax&0xFF);
  Serial.write(ay>>8);
  Serial.write(ay&0xFF);
  Serial.write(az>>8);
  Serial.write(az&0xFF);
  delay(20);
}
