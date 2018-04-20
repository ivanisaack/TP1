
/*==================[inclusions]=============================================*/

//#include "blinky.h"   // <= own header (optional)
#include "sapi.h"       // <= sAPI header

#define TP1_1 (1) //blinky
#define TP1_2 (2) //switches_leds
#define TP1_3 (3) //tickHooks
#define TEST (TP1_2)

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */


int main(void){

   /* ------------- INICIALIZACIONES ------------- */
#if (TEST == TP1_2)

	   gpioConfig( GPIO0, GPIO_INPUT );

	   gpioConfig( GPIO1, GPIO_OUTPUT );

	   /* Variable para almacenar el valor de tecla leido */
	   bool_t valor;
#endif
   /* Inicializar la placa */
   boardConfig();

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
   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
