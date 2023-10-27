#include<Servo.h>

const int sensorChuvaPin = A0;
const int sensorUltrassonicoTriggerPin = 2;
const int sensorUltrassonicoEchoPin = 3;
const int servoPin = 9;
Servo meuServo;

void setup() {
  meuServo.attach(servoPin);
  pinMode(sensorChuvaPin, INPUT);
  pinMode(sensorUltrassonicoTriggerPin, OUTPUT);
  pinMode(sensorUltrassonicoEchoPin, INPUT);
}

void loop() {
  int valorChuva = analogRead(sensorChuvaPin);
  digitalWrite(sensorUltrassonicoTriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorUltrassonicoTriggerPin, LOW);
  float distancia = pulseIn(sensorUltrassonicoEchoPin, HIGH) * 0.034 / 2;

  if (valorChuva < 500 && distancia > 10) {
    meuServo.write(0);
    delay(1000);
  } else {
    meuServo.write(90);
    delay(1000);
  }
}
