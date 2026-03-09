#include "stm32f446xx_i2c_driver.h"

/*Peripheral Clock Setup*/
void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t clockState)
{
    if(clockState == ENABLE)
    {
        if(pI2Cx == I2C1)
        {
            I2C1_PCLK_EN();
        }
        else if(pI2Cx == I2C2)
        {
            I2C2_PCLK_EN(); 
        }
        else if(pI2Cx == I2C3)
        {
            I2C3_PCLK_EN(); 
        }

    }
    else
    {
        if(pI2Cx == I2C1)
        {
            I2C1_PCLK_DIS();
        }
        else if(pI2Cx == I2C2)
        {
            I2C2_PCLK_DIS(); 
        }
        else if(pI2Cx == I2C3)
        {
            I2C3_PCLK_DIS(); 
        }

    }
}

/*I2C Initialization and DeInitialization*/

void I2C_Init(I2C_Handle_t *pI2CHandle)
{
    /*1. Configure the mode (standard or fast)
    *2. Configure the speed of the serial clock (SCL)
    *3. Configure the device address (applicable when device is a slave)
    *4. Enable the Acking (disabled by default)
    *5. Configure the rise time for I2C pins
    *
    *  All the above configuration must be done when the 
    *  peripheral is disabled in the control regster
    * 
    */
}

void I2C_DeInit(I2C_RegDef_t *pI2Cx)
{
    if(pI2Cx == I2C1)
    {
        I2C1_PCLK_RESET();
    }
    else if(pI2Cx == I2C2)
    {
        I2C2_PCLK_RESET();
    }
    else if(pI2Cx == I2C3)
    {
        I2C3_PCLK_RESET();
    }
}