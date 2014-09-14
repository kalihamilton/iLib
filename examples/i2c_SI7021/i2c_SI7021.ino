#include <Wire.h>
#include "i2c.h"
#include "i2c_SI7021.h"
SI7021 si7021 = SI7021();


void setup()
{
    // Serial
    Serial.begin(115200);
    Serial.println("READ SI7021");

    if (si7021.initialize()) { Serial.println("Sensor found!"); }
    else                     { Serial.println("Sensor missing"); while(1) {}; }

}

void loop()
{
    static float humi, temp;

    si7021.getHumidity(humi);
    si7021.getTemperature(temp);
    si7021.requestMeasurement();

    Serial.print("TEMP: ");
    Serial.print(temp);
    Serial.print(" HUMI: ");
    Serial.print(humi);
    Serial.println("");

}


