#include <NewPing.h>

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200

int distancecm;
float distancepulg;
float distancem;
int dt = 1000;

void calculardistancia() {
  NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
  distancecm = sonar.ping_cm();
  Serial.print("La distancia del objeto es de: ");
  Serial.print(distancecm);
  Serial.print("cm.");
  delay(dt);
}
void convertirapulg(){
  distancepulg = distancecm * 0.393701;
  Serial.print(" / ");
  Serial.print(distancepulg);
  Serial.print("pulg.");
  delay(dt);
}
void convertirametros(){
  distancem = distancecm * 0.01;
  Serial.print(" / ");
  Serial.print(distancem);
  Serial.println("m.");
  delay(dt);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  calculardistancia();
  convertirapulg();
  convertirametros();
}