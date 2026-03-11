#include <xc.h>
#include "inc/relay_ON.h"
#include "inc/gpio.h"


void initRelay_ON(void)
{
    HAL_GPIO_PinCfg(RelayON, GPIO_OUTPUT);
    HAL_GPIO_PinSet(RelayON, GPIO_LOW);
}


void relay_ON(uint8_t stateRelay)
{
	switch (stateRelay)
    {
    case 0:
        HAL_GPIO_PinSet(RelayON, GPIO_LOW);
        break;
    case 1:
        HAL_GPIO_PinSet(RelayON, GPIO_HIGH);
        break;
    case 2:
        HAL_GPIO_PinSet(RelayON, !HAL_GPIO_PinGet(RelayON));
        break;
    default:
        break;
    }
}


