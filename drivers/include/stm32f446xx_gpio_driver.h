#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"

typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOPType;
    uint8_t PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct 
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/*Peripheral Clock Setup*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t clockState);

/*GPIO Initialization and DeInitialization*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*Reading and writing*/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);

/*Interrupt Handling*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t pinState);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t pinNumber);

/*@GPIO_PIN_NUMBERS*/
#define GPIO_PIN_0          0x0
#define GPIO_PIN_1          0x1
#define GPIO_PIN_2          0x2
#define GPIO_PIN_3          0x3
#define GPIO_PIN_4          0x4
#define GPIO_PIN_5          0x5
#define GPIO_PIN_6          0x6
#define GPIO_PIN_7          0x7
#define GPIO_PIN_8          0x8
#define GPIO_PIN_9          0x9
#define GPIO_PIN_10         0xA
#define GPIO_PIN_11         0xB
#define GPIO_PIN_12         0xC
#define GPIO_PIN_13         0xD
#define GPIO_PIN_14         0xE
#define GPIO_PIN_15         0xF

/*GPIO Pin possible modes*/
/*@GPIO_PIN_MODE*/
#define GPIO_MODE_INPUT     0x0
#define GPIO_MODE_OUTPUT    0x1
#define GPIO_MODE_ALT       0x2
#define GPIO_MODE_ANALOG    0x3
#define GPIO_MODE_IT_FT     0x4
#define GPIO_MODE_IT_RT     0x5
#define GPIO_MODE_IT_RFT    0x6

/*@GPIO_TYPE_OUTPUT*/
#define GPIO_OUTPUT_PP      0x0       /*Output push-pull */
#define GPIO_OUTPUT_OD      0x1       /*Output open-drain*/

/*@GPIO_TYPE_SPEED*/
#define GPIO_LOW_SPEED      0x0
#define GPIO_MED_SPEED      0x1
#define GPIO_FAST_SPEED     0x2
#define GPIO_HIGH_SPEED     0x3   

/*@GPIO_*/
#define GPIO_NO_PUPD        0x0
#define GPIO_PIN_PU         0x1
#define GPIO_PIN_PD         0x2

#endif