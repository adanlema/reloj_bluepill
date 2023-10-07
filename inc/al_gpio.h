/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef AL_GPIO_H
#define AL_GPIO_H

/*==================[inclusions]=============================================*/
#include <stdint.h>
#include <stdbool.h>

typedef struct DigitalInput *  DigitalInput_t;
typedef struct DigitalOutput * DigitalOutput_t;
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
/**
 * @brief Digital Input Create
 * Se encarga de configurar como entrada digital a un pin proporcionado.
 * @param port Puerto
 * @param pin Pin
 * @param inverted Si trabajo con Pull-Down(false) o Pull-Up(true)
 * @return DigitalInput_t
 */
DigitalInput_t DigitalInput_Create(uint8_t port, uint8_t pin, bool inverted);
/**
 * @brief Digital Input Get State
 * Devuelve el estado de la entrada.
 * @param self Puntero al struct de la entrada.
 * @return true Si se encuentra activo.
 * @return false Si no esta activo.
 */
bool DigitalInput_GetState(DigitalInput_t self);
/**
 * @brief Digital Input Has Change
 * Evalua si la entrada a cambiado.
 * @param self Puntero al struct de la entrada.
 * @return true Si cambio.
 * @return false Si no cambio.
 */
bool DigitalInput_HasChange(DigitalInput_t self);
/**
 * @brief Digital Input Has Activate
 * Evalua si la entrada a sido activada.
 * @param self Puntero al struct de la entrada.
 * @return true Si se activo.
 * @return false Si no se activo.
 */
bool DigitalInput_HasActivate(DigitalInput_t self);
/**
 * @brief Digital Input Has Desactivate
 * Evalua si la entrada a sido desactivada.
 * @param self Puntero al struct de la entrada.
 * @return true Si se desactivo.
 * @return false Si sigue activa.
 */
bool DigitalInput_HasDesactivate(DigitalInput_t self);
/**
 * @brief Digital Output Create
 * Crea una salida digital, en la cual debemos proporcionar el pin y puerto.
 * Retorna el puntero de la esctructura creada.
 * @param port Puerto
 * @param pin Pin
 * @return DigitalOutput_t
 */
DigitalOutput_t DigitalOutput_Create(uint8_t port, uint8_t pin);
/**
 * @brief Digital Output Get State
 * Retorna el valor del pin.
 * @param self puntero a la salida digital
 */
bool DigitalOutput_GetState(DigitalOutput_t self);
/**
 * @brief Digital Output Activate
 * Activa la salida solicitada.
 * @param self Puntero a la salida digital.
 */
void DigitalOutput_Activate(DigitalOutput_t self);
/**
 * @brief Digital Output Desactivate
 * Desactiva la salida solicitada.
 * @param self Puntero a la salida digital.
 */
void DigitalOutput_Desactivate(DigitalOutput_t self);
/**
 * @brief Digital Output Toggle
 * Cambia el estado de la salida proporcionada.
 * @param self Puntero a la salida digital.
 */
void DigitalOutput_Toggle(DigitalOutput_t self);
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif