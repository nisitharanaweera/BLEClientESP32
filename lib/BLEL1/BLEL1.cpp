#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include "BLEL1.h"




class MyClientCallbacks : public BLEClientCallbacks
{
  void onConnect(BLEClient *pClient)
  {
    Serial.println("Connected to server");
  }

  void onDisconnect(BLEClient *pClient)
  {
    Serial.println("Disconnected from server");
  }
};


void BLEL1Client::initBLEClient(int ServerCount,BLEAddress serverAddresses[],BLEClient *pClients[]){

    Serial.println("Starting BLE Client...");
  BLEDevice::init("");

  for (int i = 1; i < ServerCount; i++){

    pClients[i] = BLEDevice::createClient();
    pClients[i]->setClientCallbacks(new MyClientCallbacks());
  }

  for (int i = 1; i < ServerCount; i++)
  {
    Serial.print("Connecting to server ");
    Serial.println(i + 1);
    String sAddress = (serverAddresses[i].toString().c_str());
    pClients[i]->connect(serverAddresses[i]);
  }
}







void BLEL1Client::getBleData(int ServerCount,BLEClient *pClients[],BLEUUID serviceUUID, BLEUUID charUUID){
    for (int i = 1; i < ServerCount; i++)
  {

    if (pClients[i]->isConnected()){

      BLERemoteService *pRemoteService = pClients[i]->getService(serviceUUID);
      if (pRemoteService != nullptr)
      {
        BLERemoteCharacteristic *pRemoteCharacteristic = pRemoteService->getCharacteristic(charUUID);
        if (pRemoteCharacteristic != nullptr){
          
          std::string value = pRemoteCharacteristic->readValue();
          Serial.print("Server ");
          Serial.print(i + 1);
          Serial.print(": ");
          Serial.println(value.c_str());
        }
      }
    }
    else
    {
      break;
    }
  }

  Serial.println();
}