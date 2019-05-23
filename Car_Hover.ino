/* Codigo car Hover
->Só pra frente e pors lados
->direto no esp8266
->ponte h só para voltagem
*/



#define VA  D5     
#define VB  D6 


#define  TEMPO 200
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>


String command;             
int speedCar =1;
int speedStart = 900;
int Stop = 0;
int Time = 1000;

int delay1 = 400;
int delay2 = 25;

const char* ssid = "CarHover";
ESP8266WebServer server(80);

void setup() {
 pinMode(VB, OUTPUT);
 pinMode(VA, OUTPUT);  
 analogWriteFreq(1000);
 Serial.begin(115200);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}



void goAhead(){  
  analogWrite(VA, 900);
  analogWrite(VB, 900);
  delay(delay1);
  
  analogWrite(VA, speedCar);
  analogWrite(VB, speedCar);   
  delay(delay2);
      
}

void stopRobot(){
  analogWrite(VA, Stop);
  analogWrite(VB, Stop);  
}

void goRight(){  
  analogWrite(VA, 900);
  analogWrite(VB, Stop);
  delay(delay1);
  
  analogWrite(VA, speedCar);
  analogWrite(VB, Stop);  
  delay(delay2);
  
}
  
void goLeft(){ 
  analogWrite(VA, Stop);
  analogWrite(VB, 900);
  delay(delay1);
  
  analogWrite(VA, Stop);
  analogWrite(VB, speedCar);  
  delay(delay2);
  
}

void loop() {
      server.handleClient();
      command = server.arg("State");
      if (command == "F") goAhead();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if (command == "0") speedCar = 100;
      else if (command == "1") speedCar = 200;
      else if (command == "2") speedCar = 300;
      else if (command == "3") speedCar = 400;
      else if (command == "4") speedCar = 500;
      else if (command == "5") speedCar = 600;
      else if (command == "6") speedCar = 700;
      else if (command == "7") speedCar = 800;
      else if (command == "8") speedCar = 900;
      else if (command == "9") speedCar = 1000;
      else stopRobot();     
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}


void goBack(){
      stopRobot();
}  

void goAheadRight(){
      stopRobot();     
   }

void goAheadLeft(){
      stopRobot();      
  }
void goBackRight(){ 
      stopRobot();      
  }
void goBackLeft(){ 
      stopRobot();          
  }
