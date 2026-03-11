#include <xc.h>
#include "inc/led_led.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_led_init (void)
{
	HAL_GPIO_PinCfg(Led1, GPIO_OUTPUT);
}




