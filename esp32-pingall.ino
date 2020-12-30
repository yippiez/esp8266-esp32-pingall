#include <WiFi.h>
#include <ESP32Ping.h>
#include <Arduino.h>
#include <IPAddress.h>
#include "config.h"

void ping_all(){

  IPAddress x = WiFi.localIP();

  for(int i = 0; i<=255; i++){

    if( Ping.ping(IPAddress(x[0], x[1], x[2], i)) ){
      Serial.printf("%s %s\n", IPAddress(x[0], x[1], x[2], i).toString().c_str(), "Succes");
    }else{
      Serial.printf("%s %s\n", IPAddress(x[0], x[1], x[2], i).toString().c_str(), "Fail");
    }

  }

}

void setup() {

  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(STA_SSID, STA_PASS);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.printf("\nConnected to %s \n Local ip:%s\n Dns ip: (%s / %s)\n",
    STA_SSID,
    WiFi.localIP().toString().c_str(),
    WiFi.dnsIP(0).toString().c_str(),
    WiFi.dnsIP(1).toString().c_str());

  delay(1000);

}

void loop() {

  Serial.println("Beggining loop");
  delay(1000);
  ping_all();

}
