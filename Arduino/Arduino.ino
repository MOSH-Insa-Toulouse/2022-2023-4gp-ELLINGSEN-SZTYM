/*
  Fichier : Arduino      
  Description :  Code Arduino pour notre projet capteur de 4A GP 
  Auteur : ELLINGSEN Abélia & SZTYM Alice       
  Créé le : Mai 2023       
*/

//Définitions et librairies relatives à l'OLED
#include <Adafruit_SSD1306.h>

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);


#define Periode 50 //envoie des données toutes les 50ms


// Constantes relatives au flex sensor
const int flexPin = A0;      // Pin utilisé pour récupérer le signal
const float VCC = 5;      // VCC de l'Arduino
const float R_DIV = 33000.0;  // Résistance utilisée pour créer un pont diviseur de tension 
const float flatResistance = 33000.0; // Résistance avec capteur plat
const float bendResistance = 77000.0;  // Résistance avec le capteur à 90 degrés

float sensorValue ;
float resistance ;

// Définitions et librairies relatives au module Bluetooth
#include <SoftwareSerial.h>
#define rxPin 10//Broche 11 en tant que RX, à raccorder sur TX du HC-05
#define txPin 11//Broche 10 en tant que RX, à raccorder sur TX du HC-05

SoftwareSerial mySerial(rxPin ,txPin); //Définition du software serial
unsigned long temps_ref=0;

void setup() {

  // Initialisation de l'écran OLED
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while(1);    // Arrêt du programme (boucle infinie) si échec d'initialisation

  pinMode(flexPin, INPUT);
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
    
  // Lecture de la valeur du capteur graphite et conversion en résistance
  sensorValue = analogRead(A1);
  sensorValue=sensorValue*5/1024; //Tension sur 5 volt et 10 bits
  resistance = (1.0+100.0)*100000.0*(5.0/sensorValue)-100000.0-10000.0;
  //Serial.println(resistance);
  //Serial.println(sensorValue);  

  // Lecture et conversion du signal en résistance délivré par le flex sensor
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  //Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Estimation de l'angle du flex sensor 
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  //Serial.println("Bend: " + String(angle) + " degrees");

 // Affichage sur l'écran OLED
  byte tailleDeCaractere=1 ;
  
  ecranOLED.clearDisplay(); 
  ecranOLED.setTextSize(tailleDeCaractere); // Taille des caractères (1:1)
  ecranOLED.setCursor(0, 0); // Déplacement du curseur en position (0,0), c'est à dire dans l'angle supérieur gauche
  ecranOLED.setTextColor(SSD1306_WHITE); // Affichage du texte en "blanc" 
 
  ecranOLED.println("Resistance capteur graphite : " + String(resistance/1e6) + " MOhms"); 
  
  ecranOLED.println("Resistance flexsensor : " + String(Rflex) + " ohms"); 
  ecranOLED.println("Angle: " + String(angle) + " degrees");
          
  ecranOLED.display(); // Transfert le buffer à l'écran

//Transfert auBluetooth  
if (abs(millis()-temps_ref) > Periode)
 { 
  temps_ref=millis();
 byte V = map(sensorValue,0,1023,0,255);
 mySerial.write(V);
 }
 
 delay(25);

}
