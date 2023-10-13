// Copyright 2022, Adan Lema <adanlema@hotmail.com>

/*==================[inclusions]=============================================*/
#include <stdbool.h>
#include <string.h>
#include "stm32f1xx_hal.h"
#include "hal.h"

#include "al_gpio.h"
#include "al_bsp.h"
#include "al_bluepill.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
static struct board_s board = {0};
/*==================[internal functions declaration]=========================*/
static void config_relojext_init(void);
static void config_pin_digitos(void);
static void config_pin_segmentos(void);

void        DisplayApagar(void);
void        DisplayEncenderSegmento(uint8_t segments);
void        DisplayEncenderDigito(uint8_t digit);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
static void config_relojext_init(void) {
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY))
        continue;
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_Msk) | RCC_CFGR_SW_HSE;
    while (!((RCC->CFGR & RCC_CFGR_SWS_Msk) == RCC_CFGR_SWS_0))
        continue;
    RCC->CFGR &= ~(1 << 7);
    RCC->CFGR &= ~(1 << 10);
    RCC->CFGR &= ~(1 << 13);
    SystemCoreClockUpdate();
}
static void config_pin_digitos(void) {
    DigitalOutput_t pin_dig1 = DigitalOutput_Create(DIGIT_1_PORT, DIGIT_1_PIN);
    DigitalOutput_t pin_dig2 = DigitalOutput_Create(DIGIT_2_PORT, DIGIT_2_PIN);
    DigitalOutput_t pin_dig3 = DigitalOutput_Create(DIGIT_3_PORT, DIGIT_3_PIN);
    DigitalOutput_t pin_dig4 = DigitalOutput_Create(DIGIT_4_PORT, DIGIT_4_PIN);
}
static void config_pin_segmentos(void) {
    DigitalOutput_t pin_seg_a     = DigitalOutput_Create(SEGMENT_A_PORT, SEGMENT_A_PIN);
    DigitalOutput_t pin_seg_b     = DigitalOutput_Create(SEGMENT_B_PORT, SEGMENT_B_PIN);
    DigitalOutput_t pin_seg_c     = DigitalOutput_Create(SEGMENT_C_PORT, SEGMENT_C_PIN);
    DigitalOutput_t pin_seg_d     = DigitalOutput_Create(SEGMENT_D_PORT, SEGMENT_D_PIN);
    DigitalOutput_t pin_seg_e     = DigitalOutput_Create(SEGMENT_E_PORT, SEGMENT_E_PIN);
    DigitalOutput_t pin_seg_f     = DigitalOutput_Create(SEGMENT_F_PORT, SEGMENT_F_PIN);
    DigitalOutput_t pin_seg_g     = DigitalOutput_Create(SEGMENT_G_PORT, SEGMENT_G_PIN);
    DigitalOutput_t pin_seg_punto = DigitalOutput_Create(SEGMENT_P_PORT, SEGMENT_P_PIN);
}

void DisplayApagar(void) {
    puertos_gpio[DIGITS_GPIO]->BRR |= DIGITS_MASK;
    puertos_gpio[SEGMENTS_GPIO]->BRR |= SEGMENTS_MASK;
    puertos_gpio[SEGMENTS_GPIO]->BRR |= SEGMENT_P_MASK;
}

void DisplayEncenderSegmento(uint8_t segments) {
    puertos_gpio[SEGMENTS_GPIO]->BSRR |= (segments & SEGMENTS_MASK);
    puertos_gpio[SEGMENTS_GPIO]->BSRR |= (segments & SEGMENTO_P);
}

void DisplayEncenderDigito(uint8_t digit) {
    puertos_gpio[DIGITS_GPIO]->BSRR |= ((1 << (3 - digit)) & DIGITS_MASK);
}

/*==================[external functions definition]==========================*/
board_t board_Create(void) {

    /*  Configuracion de pines*/
    config_relojext_init();
    config_pin_digitos();
    config_pin_segmentos();
    SysTick_Config(SystemCoreClock / 1000);
    /*  Entradas  */
    board.aceptar  = DigitalInput_Create(KEY_ACCEPT_PORT, KEY_ACCEPT_PIN, false);
    board.rechazar = DigitalInput_Create(KEY_CANCEL_PORT, KEY_CANCEL_PIN, false);
    board.f1       = DigitalInput_Create(KEY_F1_PORT, KEY_F1_PIN, false);
    board.f2       = DigitalInput_Create(KEY_F2_PORT, KEY_F2_PIN, false);
    board.f3       = DigitalInput_Create(KEY_F3_PORT, KEY_F3_PIN, false);
    board.f4       = DigitalInput_Create(KEY_F4_PORT, KEY_F4_PIN, false);
    /*  Salidas  */
    board.buz     = DigitalOutput_Create(LED_PUERTO, LED_PIN);
    board.display = DisplayCreate(4, &(struct display_driver_s){
                                         .DisplayApagar           = DisplayApagar,
                                         .DisplayEncenderSegmento = DisplayEncenderSegmento,
                                         .DisplayEncenderDigito   = DisplayEncenderDigito,
                                     });
    return &board;
}
/**  doxygen end group definition */
/*==================[end of file]============================================*/