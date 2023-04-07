const int MODE = 8;
const int M1_IN_PHASE = 9;
const int M1_IN_ENABLE = 10;
const int M2_IN_PHASE = 11;
const int M2_IN_ENABLE = 12;
volatile int point = 0;
int velocity = 10;

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
  if(Serial.available()>0){
    point = Serial.parseInt();
    motor(point, velocity);
  }
}

void motor(int angle, int v) {
  int i,f;
  if(angle>0) {
      f = (int) (angle/3.6);
      for(i=0; i<f; i++) {
        digitalWrite(M1_IN_PHASE, HIGH); //M1=正, M2=逆
        delay(v);
        digitalWrite(M2_IN_PHASE, HIGH); //M1=正, M2=正
        delay(v);
        digitalWrite(M1_IN_PHASE, LOW); //M1=逆, M2=正
        delay(v);
        digitalWrite(M2_IN_PHASE, LOW); //M1=逆, M2=逆
        delay(v);
      }     
    } else if(angle<0) {
      f = (int) (-angle/3.6);
      for(i=0; i<f; i++) {     
        digitalWrite(M2_IN_PHASE, LOW); //M1=逆, M2=逆
        delay(v);
        digitalWrite(M1_IN_PHASE, LOW); //M1=逆, M2=正
        delay(v);
        digitalWrite(M2_IN_PHASE, HIGH); //M1=正, M2=正
        delay(v);
        digitalWrite(M1_IN_PHASE, HIGH); //M1=正, M2=逆
        delay(v);
      }
    }
}
