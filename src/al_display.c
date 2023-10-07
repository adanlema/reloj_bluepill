/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

/*==================[inclusions]=============================================*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "al_display.h"
/*==================[macros and definitions]=================================*/
#ifndef CANTIDAD_DIGITOS_MAXIMA
#define CANTIDAD_DIGITOS_MAXIMA 8
#endif
/*==================[internal data declaration]==============================*/
struct display_s {
    uint8_t                 digitos;
    uint8_t                 digito_activo;
    uint8_t                 memoria[CANTIDAD_DIGITOS_MAXIMA];
    struct display_driver_s driver[1];
};

static const uint8_t IMAGENES[] = {
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_C | SEGMENTO_D | SEGMENTO_E | SEGMENTO_F,              //! 0
    SEGMENTO_B | SEGMENTO_C,                                                                  //! 1
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_D | SEGMENTO_E | SEGMENTO_G,                           //! 2
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_C | SEGMENTO_D | SEGMENTO_G,                           //! 3
    SEGMENTO_B | SEGMENTO_C | SEGMENTO_F | SEGMENTO_G,                                        //! 4
    SEGMENTO_A | SEGMENTO_C | SEGMENTO_D | SEGMENTO_F | SEGMENTO_G,                           //! 5
    SEGMENTO_A | SEGMENTO_C | SEGMENTO_D | SEGMENTO_E | SEGMENTO_F | SEGMENTO_G,              //! 6
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_C,                                                     //! 7
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_C | SEGMENTO_D | SEGMENTO_E | SEGMENTO_F | SEGMENTO_G, //! 8
    SEGMENTO_A | SEGMENTO_B | SEGMENTO_C | SEGMENTO_F | SEGMENTO_G                            //! 9
};
/*==================[internal functions declaration]=========================*/
static display_t DisplayReservar(void);
static void      DisplayBorrarMemoria(display_t display_dato);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
static display_t DisplayReservar(void) {
    static struct display_s dis[1] = {0};
    return &dis[0];
}
static void DisplayBorrarMemoria(display_t display_dato) {
    memset(display_dato->memoria, 0, sizeof(display_dato->memoria));
}
/*==================[external functions definition]==========================*/

display_t DisplayCreate(uint8_t digitos, display_driver_t driver_dato) {
    display_t display = DisplayReservar();
    if (display) {
        display->digitos       = digitos;
        display->digito_activo = digitos - 1;
        memcpy(display->driver, driver_dato, sizeof(display->driver));
        DisplayBorrarMemoria(display);
        display->driver->DisplayApagar();
    }
    return display;
}

void DisplayWriteBCD(display_t display, uint8_t * number, uint8_t size) {
    DisplayBorrarMemoria(display);
    for (int indice = 0; indice < size; indice++) {
        if (indice >= display->digitos)
            break;
        display->memoria[indice] = IMAGENES[number[indice]];
    }
}

void DisplayRefresh(display_t display) {
    display->driver->DisplayApagar();
    display->digito_activo = (display->digito_activo + 1) % display->digitos;
    display->driver->DisplayEncenderSegmento(display->memoria[display->digito_activo]);
    display->driver->DisplayEncenderDigito(display->digito_activo);
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/