/****************************************
 * Include Libraries
 ****************************************/

#include <UbidotsMicroESP8266.h>

/****************************************
 * Define Instances and Constants
 ****************************************/

#define TOKEN "BBFF-om3jjdcdFmfiRqPbmfhg2hBj3sSg6y"
//enter own WiFi credentials
#define WIFI_SSID ""
#define WIFI_PASS ""

Ubidots client(TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/***************************                                                                                                                                                            
 ****************************************/

void setup() {
  Serial.begin(115200);
  client.wifiConnection(WIFI_SSID, WIFI_PASS);

  // client.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {
 int analogValue = analogRead(A0);
 float millivolts = (analogValue/1024.0)*3300;
 float celsius = millivolts/100;
 client.add("temperature",celsius);
 client.sendAll(true);
 Serial.print(" ");
 Serial.print(celsius);
 delay(5000);
// /* Obtain last value from a variable as float using HTTP */
// client.get("a020a6133e21", "variable_name_one")
//  float value = client.get("a020a6133e21", "variable_name_one");
//
//  // Evaluates the results obtained
//  if (value != ERROR_VALUE) {
//    Serial.print("Value:");
//    Serial.println(value);
//  }
}
