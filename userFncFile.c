#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_led.h"
#include "inc/timer_api1.h"
#include "inc/USB_API.h"
#include "inc/EMICBus.h"
#include "inc/relay_ON.h"
#include "inc/relay_DIR.h"

/* User Variables */
uint8_t estadoMotor = 0;
uint8_t contadorMinutos = 0;
uint8_t tiempoObjetivo = 90;

void onReset()
{
    estadoMotor = 0;
    contadorMinutos = 0;
    tiempoObjetivo = 90;
    relay_ON(0);
    setTime1(60000, 'A');
}


void etOut1()
{
    contadorMinutos = contadorMinutos + 1;
    if (contadorMinutos >= tiempoObjetivo)
    {
        contadorMinutos = 0;
        if (estadoMotor == 0)
        {
            relay_ON(1);
            estadoMotor = 1;
            tiempoObjetivo = 15;
        }
        else
        {
            relay_ON(0);
            estadoMotor = 0;
            tiempoObjetivo = 90;
        }
    }
}



