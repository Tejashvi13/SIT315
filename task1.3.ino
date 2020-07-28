//Libraries
#include <DHT.h>

//Constants
#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
volatile float hum_1 = 0;
int motion = 2; // the number of the motion pin
int light_1 = 13; // the number of the LED pin
int light_2 = 12;

volatile int state_1 = 0;


void setup() {
  //initialize the motion pin as input
  pinMode (motion,INPUT);
  dht.begin();
  //initialize the LED pin as output
  pinMode (light_1, OUTPUT);
  pinMode (light_2, OUTPUT);
  
  Serial.begin(9600);
  //attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(2), pin_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), pin_ISR2, CHANGE);
}

void loop() 
{
  hum_1 = dht.readHumidity();
  temp= dht.readTemperature();
}

void pin_ISR(){
  state_1 = digitalRead(motion);

  if (state_1 == HIGH )
  {
    digitalWrite(light_1, HIGH);
    Serial.println("There is movement in the room"); //print out output in serial monitor
  }
  else 
  {
    digitalWrite(light_1, LOW);
  }
}

void pin_ISR2()
{
  if (hum_1 <= 80) {
  digitalWrite(light_2, LOW);
  }
  else
  {
    digitalWrite(light_2,HIGH);
    Serial.print("Humidity: ");
    Serial.print(hum_1);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    
  }
}
