/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef AL_BSP_H
#define AL_BSP_H

/*==================[inclusions]=============================================*/
#include "al_gpio.h"
#include "al_display.h"
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
//! Estructura de la placa que utilizaremos para el reloj despertador.
struct board_s {
    DigitalInput_t  f1;
    DigitalInput_t  f2;
    DigitalInput_t  f3;
    DigitalInput_t  f4;
    DigitalInput_t  aceptar;
    DigitalInput_t  rechazar;
    DigitalOutput_t buz;
    display_t       display;
};
//! Creacion de un tipo de dato que es un puntero a una estructura de la placa.
typedef struct board_s * board_t;
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * @brief Board Create
 * Se encarga de crear una placa, la cual contendra cuatro entradas digitales y
 * seis salidas digitales.
 * @return board_t Retorna el puntero de la estructura de la placa.
 */
board_t board_Create(void);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif