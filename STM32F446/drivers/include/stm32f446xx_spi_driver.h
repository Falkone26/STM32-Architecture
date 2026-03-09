#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_

#include "stm32f446xx.h"

typedef struct
{
    uint8_t SPI_DeviceMode;
    uint8_t SPI_BusConfig;
    uint8_t SPI_SClkSpeed;
    uint8_t SPI_DFF;
    uint8_t SPI_CPOL;
    uint8_t SPI_CPHA;
    uint8_t SPI_SSM;
}SPI_Config_t;

typedef struct 
{
    SPI_RegDef_t *pSPIx;
    SPI_Config_t SPI_PinConfig;
}SPI_Handle_t;

//SPI Device Mode
#define SPI_DEVICE_MODE_SLAVE   0
#define SPI_DEVICE_MODE_MASTER  1

//BUS Config
#define SPI_BUS_CONFIG_FD               1
#define SPI_BUS_CONFIG_HD               2
#define SPI_BUS_CONFIG_SIMPLEX_RX_ONLY  3

//SPI Clock Speed
#define SPI_CLK_SPEED_DIV_2             0
#define SPI_CLK_SPEED_DIV_4             1
#define SPI_CLK_SPEED_DIV_8             2
#define SPI_CLK_SPEED_DIV_16            3
#define SPI_CLK_SPEED_DIV_32            4
#define SPI_CLK_SPEED_DIV_64            5
#define SPI_CLK_SPEED_DIV_128           6
#define SPI_CLK_SPEED_DIV_256           7

//SPI Data Frame Format
#define SPI_DFF_8_BIT                   0
#define SPI_DFF_16_BIT                  1

//SPI Clock Polarity
#define SPI_CPOL_LOW                    0
#define SPI_CPOL_HIGH                   1

//SPI Phase Polarity
#define SPI_CPHA_LOW                    0
#define SPI_CPHA_HIGH                   1

//SPI SSM
#define SPI_SSM_DIS                     0
#define SPI_SSM_EN                      1

/*Peripheral Clock Setup*/
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t clockState);

/*SPI Initialization and DeInitialization*/
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*SPI Enable*/
void SPIEnable(SPI_RegDef_t *pSPIx, uint8_t spiState);

/*Data Sent and Data Receive*/
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t length);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t length);

/*IRQ Configuration and ISR Handling*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t pinState);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

#endif