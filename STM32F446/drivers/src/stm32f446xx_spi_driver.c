#include "stm32f446xx_spi_driver.h"

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

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t clockState)
{
    if(clockState == ENABLE)
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_EN();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_EN(); 
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_EN(); 
        }
        else if(pSPIx == SPI4)
        {
            SPI4_PCLK_EN(); 
        }

    }
    else
    {
        if(pSPIx == SPI1)
        {
            SPI1_PCLK_DIS();
        }
        else if(pSPIx == SPI2)
        {
            SPI2_PCLK_DIS(); 
        }
        else if(pSPIx == SPI3)
        {
            SPI3_PCLK_DIS(); 
        }
        else if(pSPIx == SPI4)
        {
            SPI4_PCLK_DIS(); 
        }

    }
}

/*SPI Initialization and DeInitialization*/

/******************************************************************************
 * @function        - SPI_Init
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
        //Configure the SPI_CR1 register

        uint32_t tempReg = 0;

        //1. Configure the device mode
        tempReg |= (pSPIHandle->SPI_PinConfig.SPI_DeviceMode << SPI_CR1_MSTR);

        //2. Configure the bus config
        if(pSPIHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
        {
            tempReg &= ~(1 << SPI_CR1_BIDIMODE);
        }
        else if(pSPIHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
        {
            tempReg |= (1 << SPI_CR1_BIDIMODE);
        }
        else if(pSPIHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX_ONLY)
        {
            tempReg &= ~(1 << SPI_CR1_BIDIMODE);
            tempReg |= (1 << SPI_CR1_RXONLY);
        }

        //3. Set baud rate
        tempReg |= (pSPIHandle->SPI_PinConfig.SPI_SClkSpeed << SPI_CR1_BR); 

        //4. Data frame format
        tempReg |= (pSPIHandle->SPI_PinConfig.SPI_DFF << SPI_CR1_DFF);

        //5. Set clock polarity
        tempReg |= (pSPIHandle->SPI_PinConfig.SPI_CPOL << SPI_CR1_CPOL);

        //6. Set clock phase
        tempReg |= (pSPIHandle->SPI_PinConfig.SPI_CPOL << SPI_CR1_CPHA);

        pSPIHandle->pSPIx->CR1 = tempReg;

}

/******************************************************************************
 * @function        - SPI_DeInit
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
    if(pSPIx == SPI1)
    {
        SPI1_REG_RESET();
    }
    else if(pSPIx == SPI2)
    {
        SPI2_REG_RESET();
    }
    else if(pSPIx == SPI3)
    {
        SPI3_REG_RESET();
    }
    else if(pSPIx == SPI4)
    {
        SPI4_REG_RESET();
    }
}

void SPIEnable(SPI_RegDef_t *pSPIx, uint8_t spiState)
{
    if(spiState == ENABLE)
    {
        pSPIx->CR1 |= (1 << SPI_CR1_SPE);
    }
    else
    {
        pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
    }
}

/*Data Sent and Data Receive*/
/******************************************************************************
 * @function        - SPI_SendData
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t length)
{
    while(length > 0)
    {
        while(!(pSPIx->SR & (1<<1)));

        if(pSPIx->CR1 & (1<<SPI_CR1_DFF))
        {
            //Load DR with 2 byte of data and increment buffer address
            pSPIx->DR = *((uint16_t*)pTxBuffer);
            length -= 2;

            (uint16_t*)pTxBuffer++;
        }
        else
        {
            //Load DR with 1 bytes of data and increment buffer address
             pSPIx->DR = *(pTxBuffer);
             length--;
             pTxBuffer++;
        }

    }
}
/******************************************************************************
 * @function        - SPI_ReceiveData
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t length)
{

}

/******************************************************************************
 * @function        - SPI_IRQInterruptConfig
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t pinState)
{

}
/******************************************************************************
 * @function        - SPI_IRQPriorityConfig
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

/******************************************************************************
 * @function        - SPI_IRQHandling
 * 
 * - brief          
 * 
 * - param(in)      
 * - param(in)      
 * - param(in)
 * 
 * - return
 * 
 * - note
 * 
 */
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}
