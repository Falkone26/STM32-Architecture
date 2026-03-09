#include <stdint.h>
#include <string.h>
#include "stm32f446xx.h"

void SPI2_GPIOInit(void);
void SPI2_Init(void);

#define BUTTON_PRESSED  1

/*1. Use SPI Full Duplex Mode
* 2. STM32 board will be in SPI master
* 3. Arduino board will be in SPI slave mode
* 4. Use data frame format, 8-bit, DFF = 0 
* 5. Use hardware slave management, SSM = 0
* 6. SCLK speed 2MHz, fclk = 16MHz
* 7. STM32 will not receive data, MISO is not required
* 8. GPIO Pin Configuration
*       - PB12 - SPI2_NSS
*       - PB13 - SPI2_SCK
*       - PB14 - SPI2_MISO
*       - PB15 - SPI2_MOSI
*       - AF5 - Alternate Function Mode 5
*
*
*/

int main(void)
{
    /*
    * 1. Enable peripheral clock for GPIOB
    * 2. Enable peripheral clock for SPI2
    * 3. Initialize GPIOB and SPI2
    * 4. Enable SPI2
    * 
    * 1. Once button on Nucleo F446 is pressed (PC13), data is sent from STM32 to Arduino
    * 2. Data received by Arduino is shown on the Arduino IDE Serial monitor
    * 
    */

    char data[] = "Hello";

    GPIO_PeriClockControl(GPIOB, ENABLE);
    SPI_PeriClockControl(SPI2, ENABLE);

    SPI2_GPIOInit();
    SPI2_Init();

    SPIEnable(SPI2, ENABLE);

    while(1)
    {
        if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_13) == BUTTON_PRESSED)
        {
            SPI_SendData(SPI2, data, strlen(data));
        }
    }

    return 0;
}

void SPI2_GPIOInit(void)
{
/*********Initializing GPIOB*************************/    
    
    GPIO_Handle_t SPI2_Pins;
    
    SPI2_Pins.pGPIOx = GPIOB;
    SPI2_Pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALT;
    SPI2_Pins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_PP;
    SPI2_Pins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_FAST_SPEED;
    SPI2_Pins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    SPI2_Pins.GPIO_PinConfig.GPIO_AltMode = GPIO_AF5;

    /*Configuring SPI2 SCK*/
    SPI2_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
    GPIO_Init(&SPI2_Pins);

    /*Configuring SPI2 MOSI*/
    SPI2_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
    GPIO_Init(&SPI2_Pins);


/********Initializing User Button*******************/

    GPIO_Handle_t userButton;

    userButton.pGPIOx = GPIOC;
    userButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
    userButton.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_PP;
    userButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_FAST_SPEED;
    userButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    userButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;

    GPIO_Init(&userButton);

}

void SPI2_Init(void)
{
    SPI_Handle_t SPI2Handle;
    
    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPI_PinConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPI2Handle.SPI_PinConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPI_PinConfig.SPI_SClkSpeed = SPI_CLK_SPEED_DIV_8;
    SPI2Handle.SPI_PinConfig.SPI_DFF = SPI_DFF_8_BIT;
    SPI2Handle.SPI_PinConfig.SPI_CPOL = SPI_CPOL_LOW;
    SPI2Handle.SPI_PinConfig.SPI_CPHA = SPI_CPHA_LOW;
    SPI2Handle.SPI_PinConfig.SPI_SSM = SPI_SSM_DIS;

    SPI_Init(&SPI2Handle);

}