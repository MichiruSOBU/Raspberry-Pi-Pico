const int ADC0 = 26; //GP26
const int ADC1 = 27; //GP27
const int ADC2 = 28; //GP28

int ax, ay, az;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  ax = analogRead(ADC1);
  ay = analogRead(ADC0);
  az = analogRead(ADC2);
  Serial.print(ax, DEC); Serial.print(" ");
  Serial.print(ay, DEC); Serial.print(" ");
  Serial.print(az, DEC);
  Serial.print('\n');
  delay(500);
}
