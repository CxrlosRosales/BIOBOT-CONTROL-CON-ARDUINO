const int motorDerechoPWM = 3;
const int motorDerechoSentido1 = 6;
const int motorDerechoSentido2 = 7;

const int motorIzquierdoPWM = 4;
const int motorIzquierdoSentido1 = 8;
const int motorIzquierdoSentido2 = 9;

const int motorDCPWM = 45;  // Pin de velocidad para el motor DC
const int motorDCSentido1 = 14;  // Pin de dirección 1 para el motor DC
const int motorDCSentido2 = 15;  // Pin de dirección 2 para el motor DC

const int trigPin = 10;
const int echoPin = 11;

void setup() {
  pinMode(motorDerechoPWM, OUTPUT);
  pinMode(motorDerechoSentido1, OUTPUT);
  pinMode(motorDerechoSentido2, OUTPUT);

  pinMode(motorIzquierdoPWM, OUTPUT);
  pinMode(motorIzquierdoSentido1, OUTPUT);
  pinMode(motorIzquierdoSentido2, OUTPUT);

  pinMode(motorDCPWM, OUTPUT);
  pinMode(motorDCSentido1, OUTPUT);
  pinMode(motorDCSentido2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  long duration;

  // Envía un pulso ultrasónico para medir la distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en centímetros
  int distance = duration / 58;

  Serial.println(distance);  // Imprime la distancia en el monitor serial

  if (distance < 40) {  // Si la distancia es menor a 40 cm
    detener();           // Detener completamente
    delay(1500);         // Esperar 1.5 segundos
    retroceder();        // Retrocede
    delay(1000);          // Retrocede medio segundo
    girarIzquierda();    // Girar a la izquierda
    delay(3000);         // Esperar 3 segundos para el giro
    detener();           // Detener completamente
    delay(1500);         // Esperar 1.5 segundos antes de avanzar
    avanzar();           // Avanzar
  } else {
    avanzar();           // Avanzar si no hay obstáculos cercanos
  }
}

void avanzar() {
  analogWrite(motorDerechoPWM, 50);
  digitalWrite(motorDerechoSentido1, LOW);
  digitalWrite(motorDerechoSentido2, HIGH);

  analogWrite(motorIzquierdoPWM, 50);
  digitalWrite(motorIzquierdoSentido1, LOW);
  digitalWrite(motorIzquierdoSentido2, HIGH);

  analogWrite(motorDCPWM, 180);  
  digitalWrite(motorDCSentido1, LOW);  
  digitalWrite(motorDCSentido2, HIGH);
}

void retroceder() {
  analogWrite(motorDerechoPWM, 50);
  digitalWrite(motorDerechoSentido1, HIGH);
  digitalWrite(motorDerechoSentido2, LOW);

  analogWrite(motorIzquierdoPWM, 50);
  digitalWrite(motorIzquierdoSentido1, HIGH);
  digitalWrite(motorIzquierdoSentido2, LOW);

  analogWrite(motorDCPWM, 180);  
  digitalWrite(motorDCSentido1, HIGH);
  digitalWrite(motorDCSentido2, LOW);  
}

void detener() {
  analogWrite(motorDerechoPWM, 0);
  digitalWrite(motorDerechoSentido1, LOW);
  digitalWrite(motorDerechoSentido2, LOW);

  analogWrite(motorIzquierdoPWM, 0);
  digitalWrite(motorIzquierdoSentido1, LOW);
  digitalWrite(motorIzquierdoSentido2, LOW);

  analogWrite(motorDCPWM, 0);
  digitalWrite(motorDCSentido1, LOW);
  digitalWrite(motorDCSentido2, LOW);
}

void girarIzquierda() {
  analogWrite(motorDerechoPWM, 50);
  digitalWrite(motorDerechoSentido1, LOW);
  digitalWrite(motorDerechoSentido2, HIGH);

  analogWrite(motorIzquierdoPWM, 50);
  digitalWrite(motorIzquierdoSentido1, LOW);
  digitalWrite(motorIzquierdoSentido2, LOW);

  analogWrite(motorDCPWM, 180); 
  digitalWrite(motorDCSentido1, HIGH);
  digitalWrite(motorDCSentido2, LOW);
}
