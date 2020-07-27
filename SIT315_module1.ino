int motion = 2; // the number of the motion pin
int light = 13; // the number of the LED pin
volatile int state = 0;

void setup() {
  //initialize the motion pin as input
  pinMode (motion,INPUT);
  //initialize the LED pin as output
  pinMode (light, OUTPUT);
  
  Serial.begin(9600);
  //attach an interrupt to the ISR vector
  attachInterrupt(0, pin_ISR, CHANGE);

}

void loop() {
   //nothing here
}

void pin_ISR(){
  state = digitalRead(motion);
  digitalWrite(light, state);
  Serial.println("Motion Detected"); //print out output in serial monitor
}
