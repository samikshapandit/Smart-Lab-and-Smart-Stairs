const int pingPin = 2; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 3; // Echo Pin of Ultrasonic Sensor
const int led1=4;
const int led2=5;
const int led3=6;
const int led4=7;
const int led5=8;
const int led6=9;
const int led7=10;
const int led8=11;

int IRSensor = 13; // connect ir sensor to arduino pin 13


long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void Ultra(){
  int duration, cm;
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   if(cm<17 && cm>0)
   {   
      digitalWrite(led1, HIGH);
      digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led3, HIGH);
      digitalWrite(led4,HIGH);
      delay(500);
      digitalWrite(led5, HIGH);
      digitalWrite(led6,HIGH);
      delay(500);
      digitalWrite(led7, HIGH);
      digitalWrite(led8,HIGH);
      
      delay(10000);

      digitalWrite(led1, LOW);
      digitalWrite(led2,LOW);
      delay(500);
      digitalWrite(led3, LOW);
      digitalWrite(led4,LOW);
      delay(500);
      digitalWrite(led5, LOW);
      digitalWrite(led6,LOW);
      delay(500);
      digitalWrite(led7, LOW);
      digitalWrite(led8,LOW);
   }
}
void IR(){
  int statusSensor = digitalRead (IRSensor);
  if(statusSensor==0){
    Serial.println("Object Detected");
      digitalWrite(led7, HIGH);
      digitalWrite(led8,HIGH);
      delay(500);
      digitalWrite(led5, HIGH);
      digitalWrite(led6,HIGH);
      delay(500);
      digitalWrite(led3, HIGH);
      digitalWrite(led4,HIGH);
      delay(500);
      digitalWrite(led1, HIGH);
      digitalWrite(led2,HIGH);
      
      delay(5000);

      Serial.println("Object not Detected");
      digitalWrite(led7, LOW);
      digitalWrite(led8,LOW);
      delay(500);
      digitalWrite(led5, LOW);
      digitalWrite(led6,LOW);
      delay(500);
      digitalWrite(led3, LOW);
      digitalWrite(led4,LOW);
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(led2,LOW);
      delay(500);
  }
}
void setup() {
   Serial.begin(9600);
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6,OUTPUT);
   pinMode(led7,OUTPUT);
   pinMode(led8,OUTPUT);
}

void loop() {
   Ultra();
   IR();
}
