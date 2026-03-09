#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/************************************Processor Specific Details*****************/
/*ARM Cortex M4 Processor NVIC ISERx register Addresses*/

#define NVIC_ISER0                  ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1                  ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2                  ((volatile uint32_t*)0xE000E108)

/*ARM Cortex M4 Processor NVIC ICERx register Addresses*/
#define NVIC_ICER0                  ((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1                  ((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2                  ((volatile uint32_t*)0xE000E188)

/*ARM Cortex M4 Processor Priority register Addresses*/

#define NVIC_PR_BASEADDR            ((volatile uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED      4
/***************************************************************************** */

#define FLASH_BASEADDR              0x08000000U         /*FLASH Memory 512kB*/
#define SRAM1_BASEADDR              0x20000000U         /*SRAM1 112kB*/
#define SRAM2_BASEADDR              0x2001C000U         /*SRAM2 16kB*/
#define ROM                         0x1FFF0000U         /*System Memory 30kB*/
#define SRAM                        SRAM1_BASE_ADDR     

#define PERIPH_BASE                 0x40000000U
#define APB1_PERIPH_BASEADDR        PERIPH_BASE            
#define APB2_PERIPH_BASEADDR        0x40010000U
#define AHB1_PERIPH_BASEADDR        0x40020000U
#define AHB2_PERIPH_BASEADDR        0x50000000U

/*RCC peripheral on the AHB1 Bus*/
#define RCC_BASEADDR                (AHB1_PERIPH_BASEADDR + 0x3800)

/*GPIO peripherals on the AHB1 Bus*/
#define GPIOA_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR              (AHB1_PERIPH_BASEADDR + 0x1C00)

/*I2C, SPI and UART peripherals on the APB1 Bus*/
#define SPI2_BASEADDR               (APB1_PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR               (APB1_PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR             (APB1_PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR             (APB1_PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR              (APB1_PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR              (APB1_PERIPH_BASEADDR + 0x5000)

#define I2C1_BASEADDR               (APB1_PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR               (APB1_PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR               (APB1_PERIPH_BASEADDR + 0x5C00)

/*SPI, UART, EXTI and SYSCFG on APB2 Bus*/
#define EXTI_BASEADDR               (APB2_PERIPH_BASEADDR + 0x3C00)
#define SPI1_BASEADDR               (APB2_PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR               (APB2_PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR             (APB2_PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR             (APB2_PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR             (APB2_PERIPH_BASEADDR + 0x1400)

/*------------------------------------------PERIPHERAL REGISTER STRUCTURES--------------------------------*/

/*GPIO peripheral register structure*/
typedef struct
{
    volatile uint32_t MODER;        /*GPIO port mode register                       Address offset: 0x00*/
    volatile uint32_t OTYPER;       /*GPIO port output type register                Address offset: 0x04*/
    volatile uint32_t OSPEEDR;      /*GPIO port output speed register               Address offset: 0x08*/
    volatile uint32_t PUPDR;        /*GPIO port pull-up/pull-down register          Address offset: 0x0C*/
    volatile uint32_t IDR;          /*GPIO port input data register                 Address offset: 0x10*/
    volatile uint32_t ODR;          /*GPIO port output data register                Address offset: 0x14*/
    volatile uint32_t BSRR;         /*GPIO port bit set/reset register              Address offset: 0x18*/
    volatile uint32_t LCKR;         /*GPIO port configuration lock registe          Address offset: 0x1C*/
    volatile uint32_t AFR[2];       /*GPIO alternate function low/high registers    Address offset: 0x20 & 0x24*/
}GPIO_RegDef_t;

/*RCC peripheral register structure*/
typedef struct
{   
    volatile uint32_t CR;           /*RCC clock control register                     Address offset: 0x00*/
    volatile uint32_t PLLCFGR;      /*RCC PLL configuration register                 Address offset: 0x04*/
    volatile uint32_t CFGR;         /*RCC clock configuration register               Address offset: 0x08*/
    volatile uint32_t CIR;          /*RCC clock interrupt register                   Address offset: 0x0C*/
    volatile uint32_t AHB1RSTR;     /*RCC AHB1 peripheral reset register             Address offset: 0x10*/
    volatile uint32_t AHB2RSTR;     /*RCC AHB2 peripheral reset register             Address offset: 0x14*/
    volatile uint32_t AHB3RSTR;     /*RCC AHB3 peripheral reset register             Address offset: 0x18*/
    uint32_t RESERVED0[1];          /*Reserved 0                                     Address offset: 0x1C*/
    volatile uint32_t APB1RSTR;     /*RCC APB1 peripheral reset register             Address offset: 0x20*/
    volatile uint32_t APB2RSTR;     /*RCC APB2 peripheral reset register             Address offset: 0x24*/
    uint32_t RESERVED1[2];          /*Reserved 1                                     Address offset: 0x28 & 0x2C*/ 
    volatile uint32_t AHB1ENR;      /*RCC AHB1 peripheral clock enable register      Address offset: 0x30*/
    volatile uint32_t AHB2ENR;      /*RCC AHB2 peripheral clock enable register      Address offset: 0x34*/
    volatile uint32_t AHB3ENR;      /*RCC AHB3 peripheral clock enable register      Address offset: 0x38*/
    uint32_t RESERVED2[1];          /*Reserved 2                                     Address offset: 0x3C*/
    volatile uint32_t APB1ENR;      /*RCC APB1 peripheral clock enable register      Address offset: 0x40*/
    volatile uint32_t APB2ENR;      /*RCC APB2 peripheral clock enable register      Address offset: 0x44*/
    uint32_t RESERVED3[2];          /*Reserved 3                                     Address offset: 0x48 & 0x4C*/ 
    volatile uint32_t AHB1LPENR;    /*RCC AHB1 peripheral clock enable in low power mode register      Address offset: 0x50*/
    volatile uint32_t AHB2LPENR;    /*RCC AHB2 peripheral clock enable in low power mode register      Address offset: 0x54*/
    volatile uint32_t AHB3LPENR;    /*RCC AHB3 peripheral clock enable in low power mode register      Address offset: 0x58*/
    uint32_t RESERVED4[1];          /*Reserved 4                                     Address offset: 0x5C*/
    volatile uint32_t APB1LPENR;    /*RCC APB1 peripheral clock enable in low power mode register      Address offset: 0x60*/
    volatile uint32_t APB2LPENR[3]; /*RCC APB2 peripheral clock enable in low power mode register      Address offset: 0x64*/
    uint32_t RESERVED5[2];          /*Reserved 5                                     Address offset: 0x68 & 0x6C*/ 
    volatile uint32_t BDCR;         /*RCC Backup domain control register             Address offset: 0x70*/
    volatile uint32_t CSR;          /*RCC clock control and status register          Address offset: 0x74*/
    uint32_t RESERVED6[2];          /*Reserved 6                                     Address offset: 0x78 & 0x7C*/ 
    volatile uint32_t SSCGR;        /*RCC spread spectrum clock generation register  Address offset: 0x80*/
    volatile uint32_t PLLI2SCFGR;   /*RCC PLLI2S configuration register              Address offset: 0x84*/
    volatile uint32_t PLLSAICFGR;   /*RCC PLL configuration register                 Address offset: 0x88*/
    volatile uint32_t DCKCFGR;      /*RCC dedicated clock configuration register     Address offset: 0x8C*/
    volatile uint32_t CKGATENR;     /*RCC clocks gated enable register               Address offset: 0x90*/
    volatile uint32_t DCKCFGR2;     /*RCC dedicated clocks configuration register 2  Address offset: 0x94*/

}RCC_RegDef_t;

/*EXTI peripheral register structure*/
typedef struct
{
    volatile uint32_t IMR;          /*Interrupt mask register                       Address offset: 0x00*/
    volatile uint32_t EMR;          /*Event mask register                           Address offset: 0x04*/
    volatile uint32_t RTSR;         /*Rising trigger selection register             Address offset: 0x08*/
    volatile uint32_t FTSR;         /*Falling trigger selection register            Address offset: 0x0C*/
    volatile uint32_t SWIER;        /*Software interrupt event register             Address offset: 0x10*/
    volatile uint32_t PR;           /*Pending register                              Address offset: 0x14*/
}EXTI_RegDef_t;

/*SYSCFG peripheral register structure*/
typedef struct
{
    volatile uint32_t MEMRMP;       /*Memory remap register                         Address offset: 0x00*/
    volatile uint32_t PMC;          /*Peripheral mode configuration register        Address offset: 0x04*/
    volatile uint32_t EXTICR[4];    /*External interrupt configuration register 1-4 Address offset: 0x08 - 0x14*/
    uint32_t RESERVED0[2];          /*Reserved 0                                    Address offser: 0x18 & 0x1C*/
    volatile uint32_t CMPCR;        /*Compensation cell control register            Address offset: 0x20*/
    uint32_t RESERVED1[2];          /*Reserved 1                                    Address offser: 0x24 & 0x28*/
    volatile uint32_t CFGR;         /*configuration register                        Address offset: 0x2C*/

}SYSCFG_RegDef_t;

/*SPI peripheral register structure*/
typedef struct
{
    volatile uint32_t CR1;          /*SPI control register 1                        Address offset: 0x00*/
    volatile uint32_t CR2;          /*SPI control register 2                        Address offser: 0x04*/
    volatile uint32_t SR;           /*SPI status register                           Address offser: 0x08*/
    volatile uint32_t DR;           /*SPI data register                             Address offser: 0x0C*/
    volatile uint32_t CRCPR;        /*SPI CRC polynomial register                   Address offser: 0x10*/
    volatile uint32_t RXCRCR;       /*SPI RX CRC register                           Address offser: 0x14*/
    volatile uint32_t TXCRCR;       /*SPI TX CRC register                           Address offser: 0x18*/
    volatile uint32_t I2SCFGR;      /*SPI_I2S configuration register                Address offser: 0x1C*/
    volatile uint32_t I2SPR;        /*SPI_I2S prescaler register                    Address offser: 0x20*/

}SPI_RegDef_t;

/*I2C Peripheral Register Structure*/
typedef struct
{
    volatile uint32_t CR1;           /*I2C control register 1                        Address offset: 0x00*/
    volatile uint32_t CR2;           /*I2C control register 2                        Address offset: 0x04*/
    volatile uint32_t OAR1;          /*I2C own address register 1                    Address offset: 0x08*/
    volatile uint32_t OAR2;          /*I2C own address register 2                    Address offset: 0x0C*/
    volatile uint32_t DR;            /*I2C data register                             Address offset: 0x10*/
    volatile uint32_t SR1;           /*I2C status register 1                         Address offset: 0x14*/
    volatile uint32_t SR2;           /*I2C status register 2                         Address offset: 0x18*/
    volatile uint32_t CCR;           /*I2C clock control register                    Address offset: 0x1C*/
    volatile uint32_t TRISE;         /*TRISE register                                Address offset: 0x20*/
    volatile uint32_t FLTR;          /*FLTR register                                 Address offset: 0x24*/
}I2C_RegDef_t;

#define RCC         ((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI        ((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG      ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1        ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2        ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3        ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4        ((SPI_RegDef_t*)SPI4_BASEADDR)

#define I2C1        ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2        ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3        ((I2C_RegDef_t*)I2C3_BASEADDR)

#define GPIOA       ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB       ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC       ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD       ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE       ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF       ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG       ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH       ((GPIO_RegDef_t*)GPIOH_BASEADDR)

/*Clock enable macros for GPIOx peripherals*/
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1<<0)) 
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1<<1)) 
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1<<2)) 
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1<<3)) 
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1<<4)) 
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1<<5)) 
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1<<6)) 
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1<<7)) 

/*Clock enable macros for I2Cx peripherals*/
#define I2C1_PCLK_EN()      (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()      (RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()      (RCC->APB1ENR |= (1<<23))

/*Clock enable macros for SPIx peripherals*/
#define SPI1_PCLK_EN()      (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()      (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()      (RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN()      (RCC->APB2ENR |= (1<<13))

/*Clock enable macros for USARTx peripherals*/
#define USART2_PCLK_EN()    (RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN()    (RCC->APB1ENR |= (1<<18))
#define UART4_PCLK_EN()     (RCC->APB1ENR |= (1<<19))
#define UART5_PCLK_EN()     (RCC->APB1ENR |= (1<<20))
/*Clock enable macros for SYSCFG peripheral*/
#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1<<14))

/*Clock disable macros for GPIOx peripherals*/
#define GPIOA_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<1)) 
#define GPIOC_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<2)) 
#define GPIOD_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<3)) 
#define GPIOE_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<4)) 
#define GPIOF_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<5)) 
#define GPIOG_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<6)) 
#define GPIOH_PCLK_DIS()    (RCC->AHB1ENR &= ~(1<<7)) 

/*Clock disable macros for I2Cx peripherals*/
#define I2C1_PCLK_DIS()     (RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DIS()     (RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DIS()     (RCC->APB1ENR &= ~(1<<23))
/*Clock disable macros for SPIx peripherals*/
#define SPI1_PCLK_DIS()     (RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DIS()     (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DIS()     (RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DIS()     (RCC->APB2ENR &= ~(1<<13))

/*Clock disable macros for USARTx peripherals*/
#define USART2_PCLK_DIS()   (RCC->APB1ENR &= ~(1<<17))
#define USART3_PCLK_DIS()   (RCC->APB1ENR &= ~(1<<18))
#define UART4_PCLK_DIS()    (RCC->APB1ENR &= ~(1<<19))
#define UART5_PCLK_DIS()    (RCC->APB1ENR &= ~(1<<20))
/*Clock disable macros for SYSCFG peripheral*/
#define SYSCFG_PCLK_DIS()   (EXTI->APB2ENR &= ~(1<<14))

/*Reset GPIOx peripherals*/
#define GPIOA_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<0)); (RCC->AHB1ENR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<1)); (RCC->AHB1ENR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<2)); (RCC->AHB1ENR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<3)); (RCC->AHB1ENR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<4)); (RCC->AHB1ENR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<5)); (RCC->AHB1ENR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<6)); (RCC->AHB1ENR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<7)); (RCC->AHB1ENR &= ~(1<<7));}while(0)

/*Returns port code fpr given GPIOx base address*/

#define GPIO_BASEADDR_TO_CODE(x)    ((x == GPIOA)?0:\
                                     (x == GPIOB)?1:\
                                     (x == GPIOC)?2:\
                                     (x == GPIOD)?3:\
                                     (x == GPIOE)?4:\
                                     (x == GPIOF)?5:\
                                     (x == GPIOG)?6:\
                                     (x == GPIOH)?7:0)



#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define GPIO_PIN_SET    SET
#define GPIO_PIN_RESET  RESET

//SPI Peripheral macros, SPI control register 1
#define SPI_CR1_CPHA        0
#define SPI_CR1_CPOL        1
#define SPI_CR1_MSTR        2
#define SPI_CR1_BR          3
#define SPI_CR1_SPE         6
#define SPI_CR1_LSBFIRST    7
#define SPI_CR1_SSI         8
#define SPI_CR1_SSM         9
#define SPI_CR1_RXONLY      10
#define SPI_CR1_DFF         11
#define SPI_CR1_CRCNEXT     12
#define SPI_CR1_CRCEN       13
#define SPI_CR1_BIDIOE      14
#define SPI_CR1_BIDIMODE    15

//SPI Peripheral macros, SPI control register 2
#define SPI_CR2_RXDMAEN     0
#define SPI_CR2_TXDMAEN     1
#define SPI_CR2_SSOE        2
#define SPI_CR2_FRF         4
#define SPI_CR2_ERRIE       5
#define SPI_CR2_RXNEIE      6
#define SPI_CR2_TXEIE       7

//SPI Peripheral macros, SPI status register
#define SPI_SR_RXNE         0
#define SPI_SR_TXE          1
#define SPI_SR_CHSIDE       2
#define SPI_SR_UDR          3
#define SPI_SR_CRCERR       4
#define SPI_SR_MODF         5
#define SPI_SR_OVR          6
#define SPI_SR_BSY          7
#define SPI_SR_FRE          8

//I2C Peripheral macros, I2C control register 1
#define I2C_CR1_PE          0
#define I2C_CR1_SMBUS       1
#define I2C_CR1_SMTYPE      3
#define I2C_CR1_ENARP       4
#define I2C_CR1_ENPEC       5
#define I2C_CR1_ENGC        6
#define I2C_CR1_NOSTRETCH   7
#define I2C_CR1_START       8
#define I2C_CR1_STOP        9
#define I2C_CR1_ACK        10
#define I2C_CR1_POS        11
#define I2C_CR1_PEC        12
#define I2C_CR1_ALERT      13
#define I2C_CR1_SWRST      15

//I2C Peripheral macros, I2C control register 2
#define I2C_CR2_FREQ        0
#define I2C_CR2_ITERR       8
#define I2C_CR2_ITEVT       9
#define I2C_CR2_ITBUF       10
#define I2C_CR2_DMA         11
#define I2C_CR2_LAST        12

//I2C Peripheral macros, I2C status register 1
#define I2C_SR1_SB          0
#define I2C_SR1_ADDR        1
#define I2C_SR1_BTF         2
#define I2C_SR1_ADD10       3
#define I2C_SR1_STOPF       4
#define I2C_SR1_RXNE        6
#define I2C_SR1_TXE         7
#define I2C_SR1_BERR        8
#define I2C_SR1_ARLO        9
#define I2C_SR1_AF          10
#define I2C_SR1_OVR         11
#define I2C_SR1_PECERR      12
#define I2C_SR1_TIMEOUT     14
#define I2C_SR1_SMBALERT    15

//I2C Peripheral macros, I2C status register 1
#define I2C_SR2_MSL         0
#define I2C_SR2_BUSY        1
#define I2C_SR2_TRA         2
#define I2C_SR2_GENCALL     4
#define I2C_SR2_SMBDEFAULT  5
#define I2C_SR2_SMBHOST     6
#define I2C_SR2_DUALF       7
#define I2C_CR2_PEC         8

//I2C Peripheral macros, I2C clock control register
#define I2C_CCR_CCR         0
#define I2C_CCR_DUTY        14
#define I2C_SR2_FS          15

//Reset SPIx peripherals
#define SPI1_REG_RESET()     do{ (RCC->APB2ENR |= (1<<12)); (RCC->APB2ENR &= ~(1<<12));}while(0)
#define SPI2_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<14)); (RCC->AHB1ENR &= ~(1<<14));}while(0)
#define SPI3_REG_RESET()     do{ (RCC->AHB1ENR |= (1<<15)); (RCC->AHB1ENR &= ~(1<<15));}while(0)
#define SPI4_REG_RESET()     do{ (RCC->APB2ENR |= (1<<13)); (RCC->AHB2ENR &= ~(1<<13));}while(0)

//Reset I2C peripherals

#define I2C1_PCLK_RESET()      do{(RCC->APB1ENR |= (1<<21)); (RCC->APB1ENR &= ~(1<<21));}while(0)
#define I2C2_PCLK_RESET()      do{(RCC->APB1ENR |= (1<<22)); (RCC->APB1ENR &= ~(1<<22));}while(0)
#define I2C3_PCLK_RESET()      do{(RCC->APB1ENR |= (1<<23)); (RCC->APB1ENR &= ~(1<<23));}while(0)

#define IRQ_NO_EXTI0    6
#define IRQ_NO_EXTI1    7
#define IRQ_NO_EXTI2    8
#define IRQ_NO_EXTI3    9
#define IRQ_NO_EXTI4    10
#define IRQ_NO_EXTI9_5  23
#define IRQ_NO_EXTI5_10 40

#define NVIC_IRQ_PRI_0  0
#define NVIC_IRQ_PRI_1  1
#define NVIC_IRQ_PRI_2  2
#define NVIC_IRQ_PRI_3  3
#define NVIC_IRQ_PRI_4  4
#define NVIC_IRQ_PRI_5  5
#define NVIC_IRQ_PRI_6  6
#define NVIC_IRQ_PRI_7  7
#define NVIC_IRQ_PRI_8  8
#define NVIC_IRQ_PRI_9  9
#define NVIC_IRQ_PRI_10 10
#define NVIC_IRQ_PRI_11 11
#define NVIC_IRQ_PRI_12 12
#define NVIC_IRQ_PRI_13 13
#define NVIC_IRQ_PRI_14 14
#define NVIC_IRQ_PRI_15 15

#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#include "stm32f446xx_i2c_driver.h"

#endif
