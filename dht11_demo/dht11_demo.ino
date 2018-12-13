// Prikaz temeljne primjene DHT11 senzora

//DHT library from Adafruit
#include <DHT.h>

//Deninirati constante
#define DHTPIN 7        //DHT11 spoj na izlaz senzora
#define DHTTYPE DHT11   //DHT tip senzora

//Inicijalizacija DHT senzora za Arduino s taktom od 16MHz
DHT dht(DHTPIN, DHTTYPE);

//Definiranje varijabli
float vlaga;
float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000); //Senzoru treba vremena za početak očitanja
               //stoga na početku petlje stavljamo kašnjenje od 2s
                
  vlaga = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Vlažnost: ");
  Serial.print(vlaga);
  Serial.print(" %, Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C"); 
}
