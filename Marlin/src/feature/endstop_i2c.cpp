#include <Wire.h>
#include "../lcd/marlinui.h"

uint8_t convertAxisToAddress(AxisEnum Axis)
{
    uint8_t axisAddress = 0;
    switch (Axis)
    {
    case X_AXIS:
        axisAddress = 0xA0;
        break;
    case Y_AXIS:
        axisAddress = 0xA1;
        break;
    //case X2_AXIS:
    //    axisAddress = 0xA2;
    //    break;
    //case 10:
    //    axisAddress = 0xA3;
    //    break;
    }
    return axisAddress;
}

bool getEndStopStatus(uint8_t i2c_addr)
{
    uint8_t slaveAdress = 0x1D;
    uint8_t triggerStatus = 0;
    //uint8_t axisAddress = convertAxisToAddress(Axis);

    Wire.beginTransmission(slaveAdress);
    Wire.write(i2c_addr);
    Wire.endTransmission();

    Wire.requestFrom(slaveAdress, uint8_t(1)); // Read-Befehl senden

    while (Wire.available())
    {                                // Überprüfen, ob Daten verfügbar sind
        triggerStatus = Wire.read(); // Daten lesen
    }

    return triggerStatus;
}