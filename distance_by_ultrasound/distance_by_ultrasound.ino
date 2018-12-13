#include <NewPing.h>

//Dodijeljivanje funkcija pinovima 
#define PREDAJNIK_PIN  12
#define PRIJAMNIK_PIN  11
#define MAX_UDALJENOST 400

NewPing sonar(PREDAJNIK_PIN, PRIJAMNIK_PIN, MAX_UDALJENOST);

float udaljenost;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // Očitanje udaljenosti
  udaljenost = sonar.ping_cm();

  // Šalji očitanja na Serial Monitor
  Serial.print("Udaljenost = ");
  if( udaljenost>=400 || udaljenost <= 2){
    Serial.println("Van dosega!");
  }else{
    Serial.print(udaljenost);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
}
