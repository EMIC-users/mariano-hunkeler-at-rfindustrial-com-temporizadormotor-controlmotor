#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_LED1.h"
#include "inc/led_LED2.h"
#include "inc/led_LED3.h"
#include "inc/relay_Relay1.h"
#include "inc/relay_Relay2.h"
#include "inc/timer_api1.h"
#include "inc/EMICBus.h"

void onReset()
{
    setTime1(60000, 'A');
}


void etOut1()
{
    if (motorEncendido == 0)
    {
        contadorMinutos = contadorMinutos + 1;
        if (contadorMinutos >= 60)
        {
            relay_Relay1(1);
            motorEncendido = 1;
            tiempoMotorEncendido = 0;
            contadorMinutos = 0;
        }
    }
    else
    {
        tiempoMotorEncendido = tiempoMotorEncendido + 1;
        if (tiempoMotorEncendido >= 5)
        {
            relay_Relay1(0);
            motorEncendido = 0;
            tiempoMotorEncendido = 0;
        }
    }
}



