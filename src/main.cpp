#include <Arduino.h>
#include <BLEL1.h>


#define NUM_SERVERS 2 // Number of servers

BLEClient *pClients[NUM_SERVERS];

BLEAddress serverAddresses[NUM_SERVERS] = {
    BLEAddress("34:85:18:D1:3C:0A"), // Server 1 MAC
    BLEAddress("C8:C9:A3:F9:15:B2")  // Server 2 MAC
};

BLEUUID serviceUUID("43721262-a0cd-433c-a1bc-36caba2b4c59"); // service UUID
BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");    // characteristic UUID

BLEL1Client ble;

void setup(){

  Serial.begin(115200);
  ble.initBLEClient(NUM_SERVERS, serverAddresses, pClients);
}

void loop(){

  ble.getBleData(NUM_SERVERS, pClients, serviceUUID, charUUID);

  delay(3000);
}
