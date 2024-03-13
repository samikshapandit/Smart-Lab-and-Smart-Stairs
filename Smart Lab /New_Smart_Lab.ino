#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define fanSwitchPin 9
int flagFAN=0;
void runFan(){
  digitalWrite(fanSwitchPin, HIGH); 
}
void stopFan(){
  digitalWrite(fanSwitchPin, LOW);
}

int mainSystem = 1;
int flagLED =0;
int led1 = 7;                // the pin that the LED is atteched to
int led2 =6;
int PIRsensor = 5;           // the pin that the PIR sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

int redLed = 2;
int buzzer = 3;
int smokeA0 = A3;
// threshold value
int sensorThres = 80;

byte warning[8] ={
  0b01110,
  0b10001,
  0b10101,
  0b10101,
  0b10001,
  0b10101,
  0b10001,
  0b01110
};
byte blank[8] ={
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte pattern[8] ={
  0b00100,
  0b01010,
  0b10101,
  0b01110,
  0b10101,
  0b01010,
  0b00100,
  0b00000
};

void setup()
{
  Serial.begin(9600);        // initialize serial
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  mySerial.begin(9600);
  
  pinMode(fanSwitchPin, OUTPUT);
  digitalWrite(fanSwitchPin, LOW);
  dht.begin();               // initialize the Temperature sensor
  
  pinMode(led1, OUTPUT);      
  pinMode(led2, OUTPUT); 
  pinMode(PIRsensor, INPUT); // initialize PIR sensor as an input
  
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);  // initialize Smoke Sensor
  
  lcd.begin(16, 2);
  // create a new character
  lcd.createChar(0, blank);
   // create a new character
  lcd.createChar(1, warning);
  // create a new character
  lcd.createChar(2, pattern);
  lcd.backlight();
  lcd.clear();
}
void loop()
{
  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
    

    mySerial.print("Hum.: ");
    mySerial.print(humi);
    mySerial.print("%");
    mySerial.print(" || ");
    

    mySerial.print("Temp.: ");
    mySerial.print(tempC);
    mySerial.println(" C ");
    
    delay(1000);
  }
  
  val = digitalRead(PIRsensor);   // read sensor value
    
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres){
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(redLed, LOW);
    tone(buzzer, 1000);
  }
  else{
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    delay(500);
  }
  delay(100);

  if(analogSensor>sensorThres){
    lcd.setCursor(0,0);
    lcd.print("                ");
    delay(500);  
    lcd.setCursor(1, 0);
    lcd.write((byte)1);
    lcd.print(" FIRE ALERT ");
    lcd.write((byte)1);
    lcd.setCursor(2, 1);
    lcd.print("DO NOT ENTER");  
  }
  else{
   if(val==HIGH){
      lcd.setCursor(0, 0);
      // Print a message to the lcd.
      lcd.print("  Please knock  ");
      lcd.setCursor(0, 1);
      lcd.print("  before enter  "); 
   }
   else{
      lcd.setCursor(1,0);
      lcd.write((byte)0);
      lcd.setCursor(2, 0);
      lcd.write((byte)2);
      lcd.setCursor(14, 0);
      lcd.write((byte)2);
      delay(500);
      lcd.setCursor(2, 0);
      lcd.write((byte)0);
      lcd.setCursor(14, 0);
      lcd.write((byte)0);
      lcd.setCursor(3, 0);
      lcd.print("  IOT LAB  ");
      lcd.setCursor(0, 1);
      lcd.print("Temp.: ");
      lcd.print(tempC);
      lcd.print(" C  ");
     }
  }     
  char opt = mySerial.read();
  if(Serial.available()>0)
     Serial.write(opt);
  if(opt=='3')runFan();
  switch(opt){
      case '1' : flagLED =1;
                 break;
      case '2' : digitalWrite(led1, LOW); 
                 digitalWrite(led2, LOW);
                 delay(500); 
                 flagLED =0;
                 break;           
      case '3' : flagFAN=1;
                 break;
      case '4' : flagFAN=0;
                 break;  
      case '5' : mainSystem= 1;
                 break;
      case '6' : mainSystem= 0;
                 break;                                      
  }

  
 if(mainSystem == 1){
  if(flagFAN==1){
    runFan();
  }
  else{
    if(tempC>35 || analogSensor >100){
      runFan();
    }
    else{
      stopFan();
    }
  }

  if(flagLED==1){
      digitalWrite(led1, HIGH);   // turn LED ON
      digitalWrite(led2, HIGH);
  }
    
  else{
    if (val == HIGH) {           // check if the sensor is HIGH
      digitalWrite(led1, HIGH);   // turn LED ON
      digitalWrite(led2, HIGH);
      //delay(1000);                 
      if (state == LOW) {
        Serial.println("Motion detected!"); 
        state = HIGH;       // update variable state to HIGH
      }
    } 
      
    else {
        digitalWrite(led1, LOW); 
        digitalWrite(led2, LOW);
        delay(500);              
        if (state == HIGH){
          Serial.println("Motion stopped!");
          state = LOW;       // update variable state to LOW
        }
    }
  }
 }
   
 else{
    stopFan();
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);
 }
 
}
