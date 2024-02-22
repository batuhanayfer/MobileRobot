/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "IRSensor.h"
#include "mbed.h"


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led0(PD_4);
    DigitalOut led1(PD_3);
    DigitalOut led2(PD_6);
    DigitalOut led3(PD_2);
    DigitalOut led4(PD_7);
    DigitalOut led5(PD_5);

    AnalogIn distance(PA_0);
    DigitalOut enable(PG_1);
    DigitalOut bit0(PF_0);
    DigitalOut bit1(PF_1);
    DigitalOut bit2(PF_2);
    IRSensor IRSHinten(distance,bit0,bit1,bit2,0);
    IRSensor IRSHintenLinks(distance,bit0,bit1,bit2,1);
    IRSensor IRSVorneLinks(distance,bit0,bit1,bit2,2);
    IRSensor IRSVorne(distance,bit0,bit1,bit2,3);
    IRSensor IRSVorneRechts(distance,bit0,bit1,bit2,4);
    IRSensor IRSHintenRechts(distance,bit0,bit1,bit2,5);

    while (true) 
    {
        enable = 1;
        float dHinten = IRSHinten.read();
        float dHintenLinks = IRSHintenLinks.read();
        float dVorneLinks = IRSVorneLinks.read();
        float dVorne = IRSVorne.read();
        float dVorneRechts = IRSVorneRechts.read();
        float dHintenRechts = IRSHintenRechts.read();

        printf("Distanz Hinten: %f",dHinten);
        printf("Distanz Hinten Links: %f",dHintenLinks);
        printf("Distanz Vorne Links: %f",dVorneLinks);
        printf("Distanz Vorne: %f",dVorne);
        printf("Distanz Vorne Rechts: %f",dVorneRechts);
        printf("Distanz Hinten Rechts: %f",dHintenRechts);

        if(dHinten < 0.2) led0 = 1;
        else led0 = 0;

        if(dHintenLinks < 0.2) led1 = 1;
        else led1 = 0;

        if(dVorneLinks < 0.2) led2 = 1;
        else led2 = 0;

        if(dVorne < 0.2) led3 = 1;
        else led3 = 0;

        if(dVorneRechts < 0.2) led4 = 1;
        else led4 = 0;

        if(dHintenRechts < 0.2) led5 = 1;
        else led5 = 0;
   
        // ThisThread::sleep_for(1ms);
    }
}
