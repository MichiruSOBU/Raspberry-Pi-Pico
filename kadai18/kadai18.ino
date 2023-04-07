const int MODE = 8;
const int M1_IN_A = 9;
const int M1_IN_B = 10;

int t = 0;
char key;
char direct, speed;
float p = 0.5;

void motor(char d, char s) {
  if(s=='h'){
    if(p<1.0){
      p=p+0.1;
    }
  } else if(s=='l'){
    if(p>0){
      p=p-0.1;
    }
  }
  speed = 0;
  if(d=='f'){
    analogWrite(M1_IN_A, 0);
    analogWrite(M1_IN_B, (int)(p*65535.0));
  }else if(d=='b'){
    analogWrite(M1_IN_B, 0);
    analogWrite(M1_IN_A, (int)(p*65535.0));
  }
}

void setup() {
  pinMode(MODE, OUTPUT);
  pinMode(M1_IN_A, OUTPUT);
  pinMode(M1_IN_B, OUTPUT);
  digitalWrite(MODE, LOW);
  analogWriteFreq(2000);  //PWM set to 2kHz
  analogWriteResolution(16);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    //key=Serial.readString(); 
    key=Serial.read();
    switch(key){
      case 'f':
        direct = key;
        speed = 0;
        break;
      case 'b':
        direct = key;
        speed = 0;
        break;
      case 'h':
        speed = key;
        break;
      case 'l':
        speed = key;
        break;
    }
  }
  motor(direct, speed);
  delay(100);
}
