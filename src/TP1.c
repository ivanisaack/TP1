
/*==================[inclusions]=============================================*/

//#include "blinky.h"   // <= own header (optional)
#include "sapi.h"       // <= sAPI header
#include "main.h"


#if ( (TEST == (TP1_3)) || (TEST ==  (TP1_4)))

void myTickHook( void *ptr ){

	static bool_t ledState = OFF;

	gpioMap_t led = (gpioMap_t)ptr;

	if( ledState ){
		ledState = OFF;
	}
	else{
		ledState = ON;
	}
	gpioWrite( led, ledState );
}
#endif

int main(void){

	/* ------------- INICIALIZACIONES ------------- */
#if (TEST == TP1_2)

	gpioConfig( GPIO0, GPIO_INPUT );

	gpioConfig( GPIO1, GPIO_OUTPUT );

	/* Variable para almacenar el valor de tecla leido */
	bool_t valor;
#endif

	boardConfig();
#if (TEST == TP1_4)

	tickConfig( TICKRATE_MS );

	/* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
	         simplemente una funcion que se ejecutara peri�odicamente con cada
	         interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
	         a una interrupcion.
	         El segundo parametro es el parametro que recibe la funcion myTickHook
	         al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
	 */
	tickCallbackSet( myTickHook, (void*)LEDR );
	delay(LED_TOGGLE_MS);
#endif
#if (TEST == TP1_3)

	tickConfig( 50 );

	/* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
	         simplemente una funcion que se ejecutara peri�odicamente con cada
	         interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
	         a una interrupcion.
	         El segundo parametro es el parametro que recibe la funcion myTickHook
	         al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
	 */
	tickCallbackSet( myTickHook, (void*)LEDR );
	delay(1000);
#endif

	/* Inicializar la placa */

	/* ------------- REPETIR POR SIEMPRE ------------- */
	while(1) {

#if (TEST == TP1_1)
		/* Prendo el led azul */
		gpioWrite( LEDB, ON );

		delay(1000);

		/* Apago el led azul */
		gpioWrite( LEDB, OFF );

		delay(1000);
#endif

#if (TEST == TP1_2)

		valor = !gpioRead( TEC1 );
		gpioWrite( LEDB, valor );

		valor = !gpioRead( TEC2 );
		gpioWrite( LED1, valor );

		valor = !gpioRead( TEC3 );
		gpioWrite( LED2, valor );

		valor = !gpioRead( TEC4 );
		gpioWrite( LED3, valor );

		valor = !gpioRead( GPIO0 );
		gpioWrite( GPIO1, valor );
#endif

#if (TEST == TP1_3)

		tickCallbackSet( myTickHook, (void*)LEDG );
		delay(1000);
		tickCallbackSet( myTickHook, (void*)LEDB );
		delay(1000);
		tickCallbackSet( myTickHook, (void*)LED1 );
		delay(1000);
		tickCallbackSet( myTickHook, (void*)LED2 );
		delay(1000);
		tickCallbackSet( myTickHook, (void*)LED3 );
		delay(1000);
		tickCallbackSet( myTickHook, (void*)LEDR );
		delay(1000);
#endif

#if (TEST == TP1_4)

		tickCallbackSet( myTickHook, (void*)LEDG );
		delay(LED_TOGGLE_MS);
		tickCallbackSet( myTickHook, (void*)LEDB );
		delay(LED_TOGGLE_MS);
		tickCallbackSet( myTickHook, (void*)LED1 );
		delay(LED_TOGGLE_MS);
		tickCallbackSet( myTickHook, (void*)LED2 );
		delay(LED_TOGGLE_MS);
		tickCallbackSet( myTickHook, (void*)LED3 );
		delay(LED_TOGGLE_MS);
		tickCallbackSet( myTickHook, (void*)LEDR );
		delay(LED_TOGGLE_MS);
#endif

	}

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
	return 0 ;
}

/*==================[end of file]============================================*/
