#define MICROPY_HW_BOARD_NAME       "PYFLEX_F401"
#define MICROPY_HW_MCU_NAME         "STM32F401CE"


#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_HAS_SDCARD       (0)
#define MICROPY_HW_HAS_MMA7660      (0)
#define MICROPY_HW_HAS_LIS3DSH      (0)
#define MICROPY_HW_HAS_LCD          (0)
#define MICROPY_HW_ENABLE_RNG       (0)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (0)
#define MICROPY_HW_ENABLE_DAC       (0)
#define MICROPY_HW_ENABLE_CAN       (0)
#define MICROPY_HW_ENABLE_SPI1      (0)
#define MICROPY_HW_ENABLE_SPI2      (0)

// HSE is 16MHz - F401 does 84 MHz max
#define MICROPY_HW_CLK_PLLM (16)
#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV4)
#define MICROPY_HW_CLK_PLLQ (7)

// UART config
#define MICROPY_HW_UART1_PORT (GPIOA)
#define MICROPY_HW_UART1_PINS (GPIO_PIN_9 | GPIO_PIN_10)

#define MICROPY_HW_UART2_PORT (GPIOA)
#define MICROPY_HW_UART2_PINS (GPIO_PIN_2 | GPIO_PIN_3)
#define MICROPY_HW_UART2_RTS  (GPIO_PIN_1)
#define MICROPY_HW_UART2_CTS  (GPIO_PIN_0)

// I2C busses
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)

#define MICROPY_HW_I2C2_SCL (pin_B4)
#define MICROPY_HW_I2C2_SDA (pin_B3) // needed for JTAG

// SPI busses
#define MICROPY_HW_SPI1_NSS  (pin_A15)
#define MICROPY_HW_SPI1_SCK  (pin_B1)
#define MICROPY_HW_SPI1_MISO (pin_B4)
#define MICROPY_HW_SPI1_MOSI (pin_B5)

//  #define MICROPY_HW_SPI2_NSS  (pin_B9)
//  #define MICROPY_HW_SPI2_SCK  (pin_B13)
//  #define MICROPY_HW_SPI2_MISO (pin_B14)
//  #define MICROPY_HW_SPI2_MOSI (pin_B15)

// PYFLEX_F401 has onboard reset, BOOT0, and USR switches, ( USR switch allows the
// filesystem to be reset at boot time).   PB8 drives an LED.

#define MICROPY_HW_LED1             (pin_B8)
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

#define MICROPY_HW_USRSW_PIN        (pin_B10)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// The PYFLEX_F401 has No SDCard -no pins are available in the QFN package.

// USB config
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)
//  What would it take to have the other USB pins show here to make it one place to edit?
