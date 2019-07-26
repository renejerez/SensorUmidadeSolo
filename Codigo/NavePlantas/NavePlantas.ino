//Viral Science www.youtube.com/c/viralscience
//Water Plants Notification Blynk

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

//CONFIGURAÇÕES DA REDE

//char g1 = "-bBnNvg7fZeIwTq2ZQo1bqH4deqPSNMi";
//char g2 = "AMjV9CliOcN-3aHVLsw2h7YCED6pClaW";
//char g3 = "VVqxSHsiY-vCMFn86clULpmdeDm3jCtJ";
//char g4 = "mjBQts3sohxMAknv3GVqaf1N_8U00M0b";
//char g5 = "_JQicvFtWbHz7np93ToP72O5MhXu04V1";
//char g6 = "aOjttq1n-nzxlFRuKTSQcxoCRkS0SB4y";
//char g7 = "TFBrFY3MB9LvLn1govRBQZqOxasY9u9M";
//char g8 = "wguGvF0wdPlYvvafY-o4AD9LiOhcIPLA";


char auth[] = "-bBnNvg7fZeIwTq2ZQo1bqH4deqPSNMi";
const int sensorPin = 5; 
int contador = 1;
int sensorState = 0;
int lastState = 0;


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "RJ03", "mariana1234");  //wifi name and password
  pinMode(sensorPin, INPUT);
  
  servo.attach(4); // NodeMCU D8 pin
  servo.write(110);
}

void loop()
{ 
  Blynk.run();

  sensorState = digitalRead(sensorPin);
  Serial.println(sensorState);

if (sensorState == 1 && lastState == 0) {
     if (contador == 100000) {
                                Blynk.notify("Me molhe, estou com pouca água! Ass.: Planta 2");
                                contador = 0;
                               }
        else{
              contador = contador +1;
            };
  lastState = 1;
   
//send notification
    
  } 
  else if (sensorState == 1 && lastState == 1) {
    //do nothing, has not been watered yet
        if (contador == 100000) {
                                Blynk.notify("Me molhe, estou com pouca água! Ass.: Planta 2");
                                contador = 0;
                               }
        else{
              contador = contador +1;
            }
        
  }
  else {
    //st
    lastState = 0;
  }
  
}
BLYNK_WRITE(V1)
{
  servo.write(110);

}

BLYNK_WRITE(V2)
{
  servo.write(0);
}
