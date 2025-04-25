#include <SPI.h>
#include <LoRa.h> 

int LED = 3;
String inString = "";    // string to hold input
int val = 0;
String LoraTempt;

void setup() {
  Serial.begin(9600);
  // pinMode(LED,OUTPUT);
  
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) { // or 915E6
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSpreadingFactor(7); //12 Max Range
  LoRa.setSignalBandwidth(125000); //The higher the higher the bandwidth
}
 
void loop() {
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) { 
    Serial.print("Received packet ");
    // read packet    
    while (LoRa.available()) {
      
      int inChar = LoRa.read();
      LoraTempt = LoRa.readString();
      inString += (char)inChar;
      // val = inString.toInt(); 
    }
    Serial.print(LoraTempt);
    Serial.print(" with RSSI ");
    Serial.println(LoRa.packetRssi());
    // Convert the accumulated string to an integer
    inString = "";     
    // LoRa.packetRssi();    
  }
  // Serial.println(val); 
  // Serial.println(val);  
  // analogWrite(LED, val);
}
