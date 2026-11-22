// EL-1200 Introduccion a la Electronica
// Comedero inteligente - Isaac Vargas Moya
// Logica basada en el codigo de la guia del profesor William Marin.

#include <ESP32Servo.h>

// Pines indicados en la guia.
const int pinPIR = 2;
const int pinServo = 13;
const int pinLED = 5;

Servo dispensador;
const int anguloDispensa = 140;
const int anguloCerrado = 40;

// Recuerda si ya se sirvio una porcion durante la activacion actual del PIR.
bool dispensado = false;

void setup() {
  Serial.begin(115200);
  pinMode(pinPIR, INPUT);
  pinMode(pinLED, OUTPUT);

  dispensador.attach(pinServo);
  dispensador.write(anguloCerrado);
  digitalWrite(pinLED, LOW);

  Serial.println("Comedero Inteligente: Modo EN ESPERA...");
}

void loop() {
  int hayGato = digitalRead(pinPIR);

  if (hayGato == HIGH) {
    if (dispensado == false) {
      Serial.println(">>> Gato detectado! Dispensando alimento...");

      dispensador.write(anguloDispensa);
      digitalWrite(pinLED, HIGH);
      delay(1500);

      dispensador.write(anguloCerrado);
      digitalWrite(pinLED, LOW);
      dispensado = true;

      Serial.println("Dispensacion completada. Servo cerrado.");
      delay(10000);
    }
  } else {
    if (dispensado == true) {
      dispensado = false;
      Serial.println("Sistema reiniciado. Listo para la proxima comida.");
    }
    delay(500);
  }

  // Pausa breve para no consultar el PIR continuamente sin descanso.
  delay(10);
}
