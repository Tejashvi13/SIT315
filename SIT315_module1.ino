int motion = 2;
int light = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode (motion,INPUT);
  pinMode (light, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (light,LOW);
  delay(1000); //this delay is to let the sensor settle down before taking a reading
  int sensor = digitalRead(motion);
  if (sensor == HIGH){
    digitalWrite(light,HIGH);
    delay(1000);
    digitalWrite(light,LOW);
    delay(500);
    Serial.println("Motion Detected");
    
  }
}
