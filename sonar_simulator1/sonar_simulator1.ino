/*
	Programmer....:Rúben Esperto
    Date..........:8/1/2025
*/

const int BAUD_RATE = 9600;

const byte TRIGGER_PIN = 11;
const byte ECHO_PIN = 12;

const int MEASUREMENT_CYCLE = 60000;
const int PULSE_TRIGGER_TIME= 10;

float highLevelTime;
float distance;

void setup(){
  Serial.begin(BAUD_RATE);
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop(){
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(MEASUREMENT_CYCLE);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(PULSE_TRIGGER_TIME);
  digitalWrite(TRIGGER_PIN, LOW);
  
  highLevelTime = pulseIn (ECHO_PIN, HIGH);
  
  distance = ((highLevelTime * 0.0340) /2);
  Serial.println("Distance: " + String(distance));
}