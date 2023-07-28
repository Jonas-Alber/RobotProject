#include <Wire.h>
#include "../lcd/marlinui.h"

bool getEndStopStatus(uint8_t i2c_addr)
{
    uint8_t slaveAdress = 0x1D;
    uint8_t triggerStatus[3] = {0};
    uint8_t index = 0;
    uint8_t returnIndex = 2;
    //uint8_t axisAddress = convertAxisToAddress(Axis);

    Wire.beginTransmission(slaveAdress);
    Wire.write(i2c_addr);
    Wire.endTransmission();

    Wire.requestFrom(slaveAdress, uint8_t(3)); // Read-Befehl senden

    while (Wire.available())
    {                                // Überprüfen, ob Daten verfügbar sind
        triggerStatus[index++] = Wire.read(); // Daten lesen
    }
    if(triggerStatus[0] == 0){
        SERIAL_ECHOPGM(STR_KILL_PRE);
        SERIAL_ECHOPGM("I2C No return");
    } 
    else {
    if(triggerStatus[1]== 0){
        returnIndex = 0;
    }else{
        returnIndex = 1;
    }
    }
        
    return returnIndex;
}