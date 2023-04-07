const int MODE = 8;
const int M1_IN_PHASE = 9;
const int M1_IN_ENABLE = 10;
const int M2_IN_PHASE = 11;
const int M2_IN_ENABLE = 12;
volatile int angle = 0;

void setup() {
  pinMode(MODE, OUTPUT);
  digitalWrite(MODE, HIGH);
  pinMode(M1_IN_PHASE, OUTPUT);
  pinMode(M1_IN_ENABLE, OUTPUT);
  pinMode(M2_IN_PHASE, OUTPUT);
  pinMode(M2_IN_ENABLE, OUTPUT);
  digitalWrite(M1_IN_ENABLE, HIGH); //ブレーキ解除
  digitalWrite(M2_IN_ENABLE, HIGH); //ブレーキ解除
  Serial.begin(9600);
}

void loop() {
  int i,f;
  if(Serial.available()>0){
    angle = Serial.parseInt();
    Serial.println(angle);
    if(angle>0) {
      Serial.println("sei");
      f = (int) (angle/3.6);
      for(i=0; i<f; i++) {
        digitalWrite(M1_IN_PHASE, HIGH); //M1=正, M2=逆
        delay(10);
        digitalWrite(M2_IN_PHASE, HIGH); //M1=正, M2=正
        delay(10);
        digitalWrite(M1_IN_PHASE, LOW); //M1=逆, M2=正
        delay(10);
        digitalWrite(M2_IN_PHASE, LOW); //M1=逆, M2=逆
        delay(10);
      }     
    } else if(angle<0) {
      Serial.println("gyaku");
      f = (int) (-angle/3.6);
      for(i=0; i<f; i++) {     
        digitalWrite(M2_IN_PHASE, LOW); //M1=逆, M2=逆
        delay(10);
        digitalWrite(M1_IN_PHASE, LOW); //M1=逆, M2=正
        delay(10);
        digitalWrite(M2_IN_PHASE, HIGH); //M1=正, M2=正
        delay(10);
        digitalWrite(M1_IN_PHASE, HIGH); //M1=正, M2=逆
        delay(10);
      }
    }
  }
}
