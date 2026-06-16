#include <WiFi.h>

const char* AP_SSID = "ESPR";
const char* AP_PASSWORD = "123456789";

void setup(){
   Serial.begin(115200);
   WiFi.softAP(AP_SSID,AP_PASSWORD);
   Serial.println("Access point started");
  
   Serial.print("IP Address :");
   Serial.println(WiFi.softAPIP());

}
void loop(){

}