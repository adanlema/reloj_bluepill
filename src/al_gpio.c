/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */
// HAL GPIO - LEMA, ADAN J.A.
/*==================[inclusions]=============================================*/
#include "hal.h"
#include "stm32f1xx_hal.h"
#include <stdbool.h>

#include "al_gpio.h"
#include "al_bluepill.h"
/*==================[macros and definitions]=================================*/
#define CANTIDAD 20

struct DigitalInput {
    uint8_t port;
    uint8_t pin;
    bool    inverted;
    bool    last_state;
    bool    ocupado;
};
struct DigitalOutput {
    uint8_t port;
    uint8_t pin;
    bool    ocupado;
};
/*==================[internal data declaration]==============================*/
static struct DigitalInput  Input[CANTIDAD]  = {0};
static struct DigitalOutput Output[CANTIDAD] = {0};
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* Funciones para las Entradas */

DigitalInput_t DigitalInput_Create(uint8_t port, uint8_t pin, bool inverted) {
    uint8_t posicion = 0;
    for (int i = 0; (i < CANTIDAD) & (posicion == 0); i++) {
        if (Input[i].ocupado == false)
            posicion = i;
    }
    DigitalInput_t self         = &Input[posicion];
    self->port                  = port;
    self->pin                   = pin;
    self->inverted              = inverted;
    self->ocupado               = true;

    GPIO_InitTypeDef pin_config = {0};
    pin_config.Mode             = GPIO_MODE_INPUT;
    pin_config.Pull             = GPIO_PULLUP;

    if (self) {
        switch (self->port) {
            case HAL_PORT_A:
                __HAL_RCC_GPIOA_CLK_ENABLE();
                break;
            case HAL_PORT_B:
                __HAL_RCC_GPIOB_CLK_ENABLE();
                break;
            case HAL_PORT_C:
                __HAL_RCC_GPIOC_CLK_ENABLE();
                break;
            case HAL_PORT_D:
                __HAL_RCC_GPIOD_CLK_ENABLE();
                break;
            default:
                break;
        }
    }
    pin_config.Pin = 1 << self->pin;
    HAL_GPIO_Init(puertos_gpio[self->port], &pin_config);
    return self;
}
bool DigitalInput_GetState(DigitalInput_t self) {
    if (self->inverted == 0)
        return HAL_GPIO_ReadPin(puertos_gpio[self->port], 1 << self->pin);
    else
        return !(HAL_GPIO_ReadPin(puertos_gpio[self->port], 1 << self->pin));
}
bool DigitalInput_HasChange(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if (current_state != self->last_state)
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}
bool DigitalInput_HasActivate(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if ((0 == self->last_state) & (1 == current_state))
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}
bool DigitalInput_HasDesactivate(DigitalInput_t self) {
    bool current_state = DigitalInput_GetState(self);
    bool resultado;
    if ((1 == self->last_state) & (0 == current_state))
        resultado = true;
    else
        resultado = false;
    self->last_state = current_state;
    return resultado;
}

//=================================================================================
/* Funciones para las Salidas */
//=================================================================================
DigitalOutput_t DigitalOutput_Create(uint8_t port, uint8_t pin) {
    uint8_t posicion = 0;
    for (int i = 0; (i < CANTIDAD) & (posicion == 0); i++) {
        if (Output[i].ocupado == false)
            posicion = i;
    }
    DigitalOutput_t self        = &Output[posicion];
    self->port                  = port;
    self->pin                   = pin;
    self->ocupado               = true;

    GPIO_InitTypeDef pin_config = {0};
    pin_config.Mode             = GPIO_MODE_OUTPUT_PP;
    pin_config.Pull             = GPIO_NOPULL;
    pin_config.Speed            = GPIO_SPEED_FREQ_LOW;

    if (self) {
        switch (self->port) {
            case HAL_PORT_A:
                __HAL_RCC_GPIOA_CLK_ENABLE();
                break;
            case HAL_PORT_B:
                __HAL_RCC_GPIOB_CLK_ENABLE();
                break;
            case HAL_PORT_C:
                __HAL_RCC_GPIOC_CLK_ENABLE();
                break;
            case HAL_PORT_D:
                __HAL_RCC_GPIOD_CLK_ENABLE();
                break;
            default:
                break;
        }
    }
    pin_config.Pin = 1 << self->pin;
    HAL_GPIO_Init(puertos_gpio[self->port], &pin_config);
    return self;
}

bool DigitalOutput_GetState(DigitalOutput_t self) {
    return HAL_GPIO_ReadPin(puertos_gpio[self->port], 1 << self->pin);
}
void DigitalOutput_Activate(DigitalOutput_t self) {
    HAL_GPIO_WritePin(puertos_gpio[self->port], 1 << self->pin, GPIO_PIN_SET);
}
void DigitalOutput_Desactivate(DigitalOutput_t self) {
    HAL_GPIO_WritePin(puertos_gpio[self->port], 1 << self->pin, GPIO_PIN_RESET);
}
void DigitalOutput_Toggle(DigitalOutput_t self) {
    HAL_GPIO_TogglePin(puertos_gpio[self->port], 1 << self->pin);
}

/**  doxygen end group definition */
/*==================[end of file]============================================*/