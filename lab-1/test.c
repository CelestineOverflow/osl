#include <SoftwareSerial.h>

#define trigger 3 // Arduino Pin an HC-SR04 Trig
#define echo 2    // Arduino Pin an HC-SR04 Echo
#define ledPin 13 // Arduino Pin an LED

SoftwareSerial ardunano(11, 12);

void setup(){
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(trigger, HIGH); //Signal abschalten
    Serial.begin(9600);
    ardunano.begin(9600);
}

void loop() {
    float distance = getDistance();
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
    digitalWrite(ledPin, distance < 10 ? HIGH : LOW);
    delay(1000);
}

float getDistance(){ 
    digitalWrite(trigger, LOW); 
    delayMicroseconds(3);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW); 
    long duration = pulseIn(echo, HIGH);
    return (duration / 2.0) * 0.0343;
}
