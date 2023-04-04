
// Declear pin for relay
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings


#define BLYNK_TEMPLATE_ID "TMPLubxjOHMS"
#define BLYNK_DEVICE_NAME "myhome"
#define BLYNK_AUTH_TOKEN "XA7Ar4g9VXnqKE7mlZcOuK6DwRah3gfB"
#define DHTTYPE DHT11 



#define relay1 23
#define relay2 22
#define relay3 21
#define relay4 19
#define DHT_pin 14
#define BLYNK_PRINT Serial



#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor
#include <SimpleTimer.h>   //including the library of SimpleTimer


char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "M33 5G";
char pass[] = "1223334444";



void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(DHT_pin, INPUT);
  //pinMode();
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  dht.begin();
  timer.setInterval(2000, sendUptime);

}

void sendUptime()
{  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V4, t);
  Blynk.virtualWrite(V5, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();

}

BLYNK_WRITE(V0)
{
  int button1Value = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(relay1, button1Value);

}
BLYNK_WRITE(V1)
{
  int button2Value = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(relay2, button2Value);
}
BLYNK_WRITE(V2)
{
  int button3Value = param.asInt(); // assigning incoming value from pin V3 to a variable
  digitalWrite(relay3, button3Value);
}
BLYNK_WRITE(V3)
{
  int button4Value = param.asInt(); // assigning incoming value from pin V4 to a variable
  digitalWrite(relay4, button4Value);
}
