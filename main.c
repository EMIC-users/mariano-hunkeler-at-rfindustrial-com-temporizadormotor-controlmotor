#include <xc.h>
#include "inc/systemConfig.h"

#include "inc/systemTimer.h"
#include "inc/led_led.h"
#include "inc/timer_api1.h"
#include "inc/USB_API.h"
#include "inc/EMICBus.h"
#include "inc/relay_ON.h"
#include "inc/relay_DIR.h"
#include "inc/system.h"
#include "inc/userFncFile.h"

#include "system.c"

int main(void)
{
	initSystem();
	systemTimeInit();
	LEDs_led_init();
	USB_Init();
	EMICBus_init();
	initRelay_ON();
	onReset();
	do
	{
		timer1_Poll();
		Poll_USB();
		poll_EMICBus();
	}
	while(1);
}

