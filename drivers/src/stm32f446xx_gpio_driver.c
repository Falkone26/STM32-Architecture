#include "stm32f446xx_gpio_driver.h"

/*Peripheral Clock Setup*/

/******************************************************************************
 * @function        - GPIO_PeriClockControl
 * 
 * - brief          - Enable/disable peripheral clock for the given GPIOx
 * 
 * - param(in)      - base address of the pereipheral GPIO
 * - param(in)      - ENABLE or DISABLE macros
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t clockState)
{
    if(clockState == ENABLE)
    {
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_EN();
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_EN();
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_EN();
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_EN();
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_EN();
        }
        else if(pGPIOx == GPIOF)
        {
            GPIOF_PCLK_EN();
        }
        else if(pGPIOx == GPIOG)
        {
            GPIOG_PCLK_EN();
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_EN();
        }

    }
    else
    {
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DIS();
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_DIS();
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_DIS();
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_DIS();
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_DIS();
        }
        else if(pGPIOx == GPIOF)
        {
            GPIOF_PCLK_DIS();
        }
        else if(pGPIOx == GPIOG)
        {
            GPIOG_PCLK_DIS();
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_DIS();
        }            

    }
}

/*GPIO Initialization and DeInitialization*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    uint32_t temp = 0;
    //1. Configure mode of the GPIO pin
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
    {
        temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
        pGPIOHandle->pGPIOx->MODER |= temp; 
    }
    else
    {
        if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
        {
            //1. Configure the FTSR register
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
        {
            //2. Configure the RTSR register
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }
        else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT)
        {
            //3. Configure both the FTSR and RTSR registers
            EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
            EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
        }

        //2. Configure the GPIO port selection in SYSCFG_EXTICR register
        uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
        uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
        uint8_t portCode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
        SYSCFG_PCLK_EN();
        SYSCFG->EXTICR[temp1] = portCode << (temp2*4);

        //3. Enable the EXTI interrupt delivery using IMR
        EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    }
    temp = 0;
    
    //2. Configure the speed
    temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->OSPEEDR |= temp;

    temp = 0;
    //3. Configure the pull-up/pull-down settings
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
    pGPIOHandle->pGPIOx->PUPDR |= temp;

    temp = 0;

    //4. Configure output type
    temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber;
    pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle->pGPIOx->OTYPER |= temp;
    
    //5. Configure the alternate functionality
    if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALT)
    {
        uint8_t temp1, temp2;

        temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;


        pGPIOHandle->pGPIOx->AFR[temp1] &= (0xF << (4*temp2));
        pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.PinAltFunMode <<(4 * temp2));


    }


}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
        if(pGPIOx == GPIOA)
        {
            GPIOA_REG_RESET();
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_REG_RESET();
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_REG_RESET();
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_REG_RESET();
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_REG_RESET();
        }
        else if(pGPIOx == GPIOF)
        {
            GPIOF_REG_RESET();
        }
        else if(pGPIOx == GPIOG)
        {
            GPIOG_REG_RESET();
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_REG_RESET();
        }            

}

/*Reading and writing*/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
    uint8_t value;
    value = (uint8_t)((pGPIOx->IDR >> pinNumber) & 0x00000001);
    return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t value;
    value = (uint16_t)pGPIOx->IDR;

    return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value)
{
    if(value == GPIO_PIN_SET)
    {
        pGPIOx->ODR |= (1 << pinNumber);
    }
    else
    {
        pGPIOx->ODR &= ~(1 << pinNumber);
    }
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value)
{
    pGPIOx->ODR = value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber)
{
    pGPIOx->ODR ^= (1 << pinNumber);
}

/*Interrupt Handling*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t pinState)
{
    if(pinState == ENABLE)
    {
        if(IRQNumber <= 31)
        {
            //Configure ISER0 register
            *NVIC_ISER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber > 31 && IRQNumber < 64)
        {
            //Configure ISER1 register
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
        }
        else if(IRQNumber >= 64 && IRQNumber < 96)
        {
            //Configure ISER2 register
            *NVIC_ISER2 |= (1 << (IRQNumber % 64));
        }
    }else
    {
        if(IRQNumber <= 31)
        {
            //program ICER0 register
            *NVIC_ICER0 |= (1 << IRQNumber);
        }
        else if(IRQNumber > 31 && IRQNumber < 64)
        {
            //program ICER1 register
            *NVIC_ICER0 |= (1 << (IRQNumber % 32));
        }
        else if(IRQNumber >= 64 && IRQNumber < 96)
        {
            //program ICER2 register
            *NVIC_ICER0 |= (1 << (IRQNumber % 64));
        }
    }
}

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_sec = IRQNumber % 4;

    uint8_t shift_amount = (8 * iprx_sec) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASEADDR + (iprx)) |= (IRQPriority << shift_amount);
}

void GPIO_IRQHandling(uint8_t pinNumber)
{
    if(EXTI->PR & (1 << pinNumber))
    {
        EXTI->PR |= (1 << pinNumber);
    }
}
