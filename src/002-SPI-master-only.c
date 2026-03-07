#include <string.h>
#include "stm32f446xx.h"

void SPI2_GPIOInit(void);
void SPI2_Init(void);

int main(void)
{
    //GPIO pin configuration
    //PB12 - SPI2_NSS
    //PB13 - SPI2_SCK
    //PB14 - SPI2_MISO
    //PB15 - SPI2_MOSI
    //AF5  - Alternate Function Mode 5

    char user_data[] = "Hello World";

    GPIO_PeriClockControl(GPIOB, ENABLE);
    SPI_PeriClockControl(SPI2, ENABLE);
   
    SPI2_GPIOInit();
    SPI2_Init();

    SPIEnable(SPI2, ENABLE);

    SPI_SendData(SPI2, user_data, strlen(user_data));

    while(1);


    return 0;
}

void SPI2_GPIOInit(void)
{
    GPIO_Handle_t SPI2Pins;

    SPI2Pins.pGPIOx = GPIOB;
    SPI2Pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALT;
    SPI2Pins.GPIO_PinConfig.PinAltFunMode = 5;
    SPI2Pins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_PP;
    SPI2Pins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    SPI2Pins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_FAST_SPEED;

    //Configuring SPI2_SCLK - PB13
    SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
    GPIO_Init(&SPI2Pins);

    //Configuring SPI2_MOSI - PB15
    SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_15;
    GPIO_Init(&SPI2Pins);

    //Configuring SPI2_MISO - PB14
    //SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_14;
    //GPIO_Init(&SPI2Pins);

    //Configuring SPI2_NSS - PB12
    //SPI2Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_12;
    //GPIO_Init(&SPI2Pins);


}

void SPI2_Init(void)
{
    SPI_Handle_t SPI2Handle;

    SPI2Handle.pSPIx = SPI2;
    SPI2Handle.SPI_PinConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
    SPI2Handle.SPI_PinConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
    SPI2Handle.SPI_PinConfig.SPI_SClkSpeed = SPI_CLK_SPEED_DIV_2;
    SPI2Handle.SPI_PinConfig.SPI_DFF = SPI_DFF_8_BIT;
    SPI2Handle.SPI_PinConfig.SPI_CPOL = SPI_CPOL_LOW;
    SPI2Handle.SPI_PinConfig.SPI_CPHA = SPI_CPHA_LOW;
    SPI2Handle.SPI_PinConfig.SPI_SSM = SPI_SSM_EN;

    SPI_Init(&SPI2Handle);

}