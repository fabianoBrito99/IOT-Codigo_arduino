#include <Servo.h>
#include <SoftwareSerial.h>

// Definições de pinos
#define PIEZO_PIN 8          
#define LED_VERDE_PIN 6      

#define RELAY1_PIN 7   // Relé que controla LIGA/DESLIGA do motor
#define RELAY2_PIN 6   // Relé que inverte o sentido do motor

const int servoPin = 10;
const int rfidRxPin = 2;

SoftwareSerial rfidSerial(rfidRxPin, -1); 
Servo servoMotor;

bool emCooldown = false;             
unsigned long tempoInicio = 0;       
const unsigned long tempoCooldown = 20000;  

void setup() {
  Serial.begin(9600);
  rfidSerial.begin(9600);
  servoMotor.attach(servoPin);
  servoMotor.write(0);

  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(LED_VERDE_PIN, OUTPUT);
  
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);

  Serial.println("Sistema inicializado. Aproxime o cartão do leitor...");
}

void loop() {
  if (rfidSerial.available() > 0 && !emCooldown) {
    String rfidData = rfidSerial.readStringUntil('\n');
    Serial.println("Cartão RFID detectado!");
    Serial.println("Dados do cartão: " + rfidData);

    emCooldown = true;
    tempoInicio = millis();

    emitirSom();
    digitalWrite(LED_VERDE_PIN, HIGH);

    servoMotor.write(50);
    Serial.println("Gaveta aberta.");
    delay(15000);
    servoMotor.write(0);
    Serial.println("Gaveta fechada.");

    delay(1000);

    // Liga o motor no sentido HORÁRIO
    digitalWrite(RELAY1_PIN, HIGH);
    digitalWrite(RELAY2_PIN, LOW);
    Serial.println("Motor girando SENTIDO HORÁRIO...");
    delay(6000);
    digitalWrite(RELAY1_PIN, LOW); // Desliga o motor
    Serial.println("Motor desligado.");

    delay(10000);

    // Liga o motor no sentido ANTI-HORÁRIO
    digitalWrite(RELAY1_PIN, HIGH);
    digitalWrite(RELAY2_PIN, HIGH);
    Serial.println("Motor girando SENTIDO ANTI-HORÁRIO...");
    delay(6000);
    digitalWrite(RELAY1_PIN, LOW); // Desliga o motor
    Serial.println("Motor desligado.");

    digitalWrite(LED_VERDE_PIN, LOW);

    enviarDadosParaAPI(rfidData, "servo_motor", "ativado");
  }

  if (emCooldown && millis() - tempoInicio >= tempoCooldown) {
    emCooldown = false;
    Serial.println("Cooldown terminado. Sistema pronto para novo cartão.");
  }
  delay(100);
}

void emitirSom() {
  for (int i = 10; i <= 80; i += 10) {
    tone(PIEZO_PIN, i, 1);
    delay(50);
  }
  for (int i = 400; i >= 200; i -= 15) {
    tone(PIEZO_PIN, i, 100);
    delay(50);
  }
  noTone(PIEZO_PIN);
}

void enviarDadosParaAPI(String rfidData, String tipo, String status) {
  String jsonData = "{";
  jsonData += "\"rfidData\":\"" + rfidData + "\",";
  jsonData += "\"tipo\":\"" + tipo + "\",";
  jsonData += "\"status\":\"" + status + "\"";
  jsonData += "}";
  Serial.println(jsonData);
}
