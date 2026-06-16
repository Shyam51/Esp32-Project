#include <WiFi.h>

const char* SSID = "pcnet";
const char* PASSWORD = "123456789";

void setup(){
   Serial.begin(115200);
   WiFi.begin(SSID,PASSWORD);
   Serial.print("Connecting to wifi");
   while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
   }
   Serial.print("\n Wifi Connected");
   Serial.print("IP Address :");
   Serial.println(WiFi.localIP());

}
void loop(){

}