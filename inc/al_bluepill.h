/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef AL_BLUEPILL_H
#define AL_BLUEPILL_H

/*==================[inclusions]=============================================*/
#include "hal.h"
#include "stm32f1xx_hal.h"
/*==================[macros]=================================================*/
#define PUERTO_GPIOA 0
#define PUERTO_GPIOB 1
#define PUERTO_GPIOC 2
#define PUERTO_GPIOD 3

#define LED_PUERTO   PUERTO_GPIOC
#define LED_PIN      13

#define DIGITS_GPIO  PUERTO_GPIOB

#define DIGIT_1_PORT DIGITS_GPIO
#define DIGIT_1_PIN  0
#define DIGIT_1_MASK (1 << DIGIT_1_PIN)

#define DIGIT_2_PORT DIGITS_GPIO
#define DIGIT_2_PIN  1
#define DIGIT_2_MASK (1 << DIGIT_2_PIN)

#define DIGIT_3_PORT DIGITS_GPIO
#define DIGIT_3_PIN  10
#define DIGIT_3_MASK (1 << DIGIT_3_PIN)

#define DIGIT_4_PORT DIGITS_GPIO
#define DIGIT_4_PIN  11
#define DIGIT_4_MASK (1 << DIGIT_4_PIN)

#define DIGITS_MASK  (DIGIT_1_MASK | DIGIT_2_MASK | DIGIT_3_MASK | DIGIT_4_MASK)

// Definiciones de los recursos asociados a los SEGMENTs de la pantalla
#define SEGMENTS_GPIO  PUERTO_GPIOA

#define SEGMENT_A_PORT SEGMENTS_GPIO
#define SEGMENT_A_PIN  0
#define SEGMENT_A_MASK (1 << SEGMENT_A_PIN)

#define SEGMENT_B_PORT SEGMENTS_GPIO
#define SEGMENT_B_PIN  1
#define SEGMENT_B_MASK (1 << SEGMENT_B_PIN)

#define SEGMENT_C_PORT SEGMENTS_GPIO
#define SEGMENT_C_PIN  2
#define SEGMENT_C_MASK (1 << SEGMENT_C_PIN)

#define SEGMENT_D_PORT SEGMENTS_GPIO
#define SEGMENT_D_PIN  3
#define SEGMENT_D_MASK (1 << SEGMENT_D_PIN)

#define SEGMENT_E_PORT SEGMENTS_GPIO
#define SEGMENT_E_PIN  4
#define SEGMENT_E_MASK (1 << SEGMENT_E_PIN)

#define SEGMENT_F_PORT SEGMENTS_GPIO
#define SEGMENT_F_PIN  5
#define SEGMENT_F_MASK (1 << SEGMENT_F_PIN)

#define SEGMENT_G_PORT SEGMENTS_GPIO
#define SEGMENT_G_PIN  6
#define SEGMENT_G_MASK (1 << SEGMENT_G_PIN)

#define SEGMENTS_MASK                                                                              \
    (SEGMENT_A_MASK | SEGMENT_B_MASK | SEGMENT_C_MASK | SEGMENT_D_MASK | SEGMENT_E_MASK |          \
     SEGMENT_F_MASK | SEGMENT_G_MASK)

#define SEGMENT_P_PORT SEGMENTS_GPIO
#define SEGMENT_P_PIN  7
#define SEGMENT_P_MASK (1 << SEGMENT_P_PIN)

// Definiciones de los recursos asociados a las teclas del puncho
#define KEYS_PORT       PUERTO_GPIOA

#define KEY_F1_PORT     KEYS_PORT
#define KEY_F1_PIN      8

#define KEY_F2_PORT     KEYS_PORT
#define KEY_F2_PIN      9

#define KEY_F3_PORT     KEYS_PORT
#define KEY_F3_PIN      10

#define KEY_F4_PORT     KEYS_PORT
#define KEY_F4_PIN      11

#define KEY_ACCEPT_PORT KEYS_PORT
#define KEY_ACCEPT_PIN  12

#define KEY_CANCEL_PORT KEYS_PORT
#define KEY_CANCEL_PIN  15

/*==================[typedef]================================================*/
static GPIO_TypeDef * const puertos_gpio[] = {GPIOA, GPIOB, GPIOC, GPIOD};
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif