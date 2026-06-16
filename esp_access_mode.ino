#include<WiFi.h>
#include<WebServer.h>

//Acess point
 const char* ssid = "Esp_hotspot";
 const char* password = "12345678";
 
 WebServer server(80);

//define led pin
const int ledpin = 2;
bool ledstate = LOW;

const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>ESP LED CONTROL</title>
<style>
body{
  font-family: Arial, sans-serif;
  text-align: center;
  background-color:#f0f0f0;
  margin-top: 50px;

}
h1{
  color : #333;
}
.button{
  padding: 16px 36px;
  margin: 20px;
  font-size: 20px;
  border-radius: 10px;
  cursor:pointer;
  transistion: background 0.3s;

}
on.{
  background-color: #4CAF50;
  color:white;
}
.on:hover{
  background-color: #008000;

}
.off:hover { 
  background-color: #f44336;

}
.off:hover {
  background-color: #da190b;

}
</style> 
</head>
<body>
<h1>ESP LED CONTROL</h1>
<p><strong>Status:</strong><span id ="ledstate">%STATE%</span></p>
<button class ="button on" onclick="location.href='/led/on'">Turn ON</button>
<button class ="button off" onclick="location.href='/led/off'">Turn OFF</button>
</body>
<html>
)rawliteral";

void handleRoot(){
  String html = htmlPage;
  html.replace("%STATE%",ledstate ? "on":"OFF");
  server.send(200,"text/html",html);
}
void handleLedOn(){
  digitalWrite(ledpin,HIGH);
  ledstate = true;
  handleRoot();
}
void handleLedOff(){
  digitalWrite(ledpin,LOW);
  ledstate = false;
  handleRoot();
}
void setup(){
  Serial.begin(115200);
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,ledstate);

WiFi.softAP(ssid,password);
Serial.println("Access Point Started");
Serial.print("IP Address");
Serial.println(WiFi.softAPIP());

server.on("/", handleRoot);
server.on("/led/on", handleLedOn);
server.on("/led/off", handleLedOff);
server.begin();
}
void loop(){
  server.handleClient();
}


