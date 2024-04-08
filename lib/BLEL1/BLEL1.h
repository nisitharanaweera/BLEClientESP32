#ifndef BLEL1_H
#define BLEL1_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEClient.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include "BLEL1.h"

class BLEL1Client{

    public:
    void initBLEClient(int ServerCount,BLEAddress serverAddresses[],BLEClient *pClients[]);
    void getBleData(int ServerCount,BLEClient *pClients[],BLEUUID serviceUUID, BLEUUID charUUID);
};




#endif