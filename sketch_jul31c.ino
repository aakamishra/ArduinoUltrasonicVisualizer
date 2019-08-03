#include <Stepper.h>

const int trigPin = 6;
const int echoPin = 5;
const int Pin1 = 10; 
const int Pin2 = 11; 
const int Pin3 = 12; 
const int Pin4 = 13;

// Ports On Project
int stepsTaken;
int _step = 0; 
boolean dir = true;// false=clockwise, true=counter clockwise
int count=0;
long duration;
int distance;

// Variables Used In Project

void setup() { 

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

// Set mode for ultrasonic sensor pins

pinMode(Pin1, OUTPUT);  
pinMode(Pin2, OUTPUT);  
pinMode(Pin3, OUTPUT);  
pinMode(Pin4, OUTPUT);



// Set mode for stepper motor board pins

Serial.begin(9600); 

// Starts the serial communication

}
void loop() {

// Cases for Stepper motor

switch(_step){ 
   case 0: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, HIGH); 
   break;    
   default: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
 } 
if(stepsTaken > 2048) {

digitalWrite(Pin1, LOW);  
digitalWrite(Pin2, LOW); 
digitalWrite(Pin3, LOW); 
digitalWrite(Pin4, LOW);
    

}

if(dir){ 
   _step++; 
 }else{ 
   _step--; 
 } 
 if(_step>7){ 
   _step=0; 
 } 
 if(_step<0){ 
   _step=7; 
 } 
  
 stepsTaken++;

// Clears the trigPin

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(echoPin, HIGH);

// Calculating the distance

distance= duration*0.034/2.0;

// Prints the distance on the Serial Monitor
if(stepsTaken<2049){
Serial.print(stepsTaken);
Serial.print(",");
Serial.println(distance);
}
}
