#include <SPI.h>
#include <Ethernet.h> //Zmenit pre Ethernet2.h pre W5500
const int vystup1 = 0;
const int vystup2 = 1;
const int vystup3 = 2;
const int vystup4 = 3;
//D4 vynechany - pre SD kartu
const int vystup5 = 5;
const int vystup6 = 6;
const int vystup7 = 7;
const int vystup8 = 8;

byte mac[] = { 0xAA, 0xBB, 0xCC, 0x81, 0x7B, 0x4A }; //fyzicka adresa MAC
char serverName[] = "arduino.clanweb.eu"; // webserver
IPAddress ip(192, 168, 1, 254);
EthernetClient client;
String readString;
int x=0; //pocitadlo riadkov
char lf=10; //line feed character
void setup(){
pinMode(vystup1, OUTPUT);
pinMode(vystup2, OUTPUT);
pinMode(vystup3, OUTPUT);
pinMode(vystup4, OUTPUT);
pinMode(vystup5, OUTPUT);
pinMode(vystup6, OUTPUT);
pinMode(vystup7, OUTPUT);
pinMode(vystup8, OUTPUT);
 if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP nepridelilo adresu, skusam so statickou...");
    Ethernet.begin(mac, ip); //nastav k mac adrese i IP adresu staticku
  }
  Serial.begin(9600); 
}
void stav_vystup1(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele1.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup1, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup1, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
  void stav_vystup2(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele2.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup2, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup2, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
    void stav_vystup3(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele3.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup3, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup3, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
 void stav_vystup4(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele4.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup4, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup4, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
    void stav_vystup5(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele5.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup5, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup5, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
void stav_vystup6(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele6.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup6, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup6, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
void stav_vystup7(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele7.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup7, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup7, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }
 void stav_vystup8(){
  if (client.connect(serverName, 80)) {  //starts client connection, checks for connection
    Serial.println("connected");
    client.println("GET /rele/rele8.txt HTTP/1.1"); //download text
    client.println("Host: www.arduino.php5.sk");
    client.println("Connection: close");  // ukonc HTTP/1.1 spojenie
    client.println(); //koneic requestu
  } 
  else {
    Serial.println("Pripojenie neuspesne"); //chyba ak nie som pripojeny
    Serial.println();
  }

  while(client.connected() && !client.available()) delay(1); //cakaj na data
  while (client.connected() || client.available()) { //pramenna
    char c = client.read(); //dostan bity z buffera
    Serial.print(c); //cela http hlavicka
    if (c==lf) x=(x+1); //pocitaj 
    else if (x==12) readString += c; //nasa premenna

   } 
if(readString=="ZAP"){
  digitalWrite(vystup8, HIGH); 
  }else if(readString=="VYP"){
  digitalWrite(vystup8, LOW);  
    }
    else{
 Serial.println("Nepodporovany stav! - chyba");
 }  
  readString = ("");
  x=0;
  client.stop(); //ukonc spojenie
  }

void loop(){
stav_vystup1();
stav_vystup2();
stav_vystup3();
stav_vystup4();
stav_vystup5();
stav_vystup6();
stav_vystup7();
stav_vystup8();
delay(5000); //opakuj slucku loop o 5 sekund
} 
