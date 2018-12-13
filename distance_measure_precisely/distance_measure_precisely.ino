#include <NewPing.h>
#include <DHT.h>

#define PREDAJNIK_PIN  12
#define PRIJAMNIK_PIN  11
#define DHTPIN 7        //DHT11 spoj na izlaz senzora
#define DHTTYPE DHT11
#define MAX_UDALJENOST 400

NewPing sonar(PREDAJNIK_PIN, PRIJAMNIK_PIN, MAX_UDALJENOST);
DHT dht(DHTPIN, DHTTYPE);

float vlaga;
float temp;
float interval;
float udaljenost;
float brzinaZv;
float brzinaZvCm;
int iteracije = 5;

void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(2000);
  vlaga = dht.readHumidity();
  temp = dht.readTemperature();
  brzinaZv = 331.4 + ( 0.606 * temp ) + ( 0.0124 * vlaga );
  brzinaZvCm = brzinaZv / 10000; // pretvorba u cm/mikro sek
  interval = sonar.ping_median(iteracije);
  udaljenost = (interval/2) * brzinaZvCm;

  Serial.print("Zvuk: ");
  Serial.print(brzinaZv);
  Serial.print("m/s, ");
  Serial.print("Vlažnost: ");
  Serial.print(vlaga);
  Serial.print("%, Temperatura: ");
  Serial.print(temp);
  Serial.print("°C, "); 
  Serial.print("Udaljenost: ");
  Serial.print(udaljenost);
  Serial.println("cm");

  if( udaljenost>=400 || udaljenost <= 2){
    Serial.println("Van dosega!");
  }else{
    delay(500);  
  }
  Serial.println(" ");  
}
