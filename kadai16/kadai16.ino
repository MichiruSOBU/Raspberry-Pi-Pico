#define encoder0PinA 7
#define encoder0PinB 6
volatile int encoder0Pos = 0;
volatile float pos = 0;

void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  attachInterrupt(encoder0PinA, doEncoderA, CHANGE);
  attachInterrupt(encoder0PinB, doEncoderB, CHANGE);
  Serial.begin (9600);
}

void loop() {
  if(encoder0Pos>360) {
    encoder0Pos -= 360;
  } else if(encoder0Pos<-360) {
    encoder0Pos += 360;
  }
  pos = encoder0Pos/180; 
  Serial.print(pos); 
  Serial.println("π");
  delay(500);    
}

void doEncoderA() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {
      encoder0Pos = encoder0Pos + 1;         // CW
    } else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  } else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == HIGH) {
      encoder0Pos = encoder0Pos + 1;          // CW
    } else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
  //Serial.println (encoder0Pos, DEC);
}

void doEncoderB() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinB) == HIGH) {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {
      encoder0Pos = encoder0Pos + 1;         // CW
    } else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  } else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinA) == LOW) {
      encoder0Pos = encoder0Pos + 1;          // CW
    } else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
}
