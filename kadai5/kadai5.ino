const int LED = 28;
const int BUTTON = 17;
int state = 0; //state of pushing
int count = 0; //number of pushing

void setup ()
{
  Serial.begin(9600);
  pinMode (BUTTON, INPUT);
  pinMode (LED, OUTPUT);
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);
}  // end of setup

void switchPressed ()
{
  state = digitalRead(BUTTON);
  //Serial.println(state);
  if (state == 1){
    delay(5);
    if (state == 1){
      digitalWrite (LED, HIGH);
      count++;
      Serial.println(count);
    }
  }else {
    digitalWrite (LED, LOW);
  } 
  delay(1000);
} 

void loop ()
{
  // loop doing nothing 
} 