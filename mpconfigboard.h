#define MICROPY_HW_BOARD_NAME       "PYFLEX_F401"
#define MICROPY_HW_MCU_NAME         "STM32F401CE"



#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_USB       (1)

// USB config
#define MICROPY_HW_USB_FS           (1)
// recognizing a USB host plug-in-event requires VBUS_DETECT_PIN
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
// No code yet for OTG modes needing OTG_ID_PIN
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

//  PYFLEX_F401 has onboard reset, BOOT0, and USRSW switches, ( USRSW switch allows the
//  filesystem to be reset at boot time).   PB8 drives an LED.

#define MICROPY_HW_LED1             (pin_B8)
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

#define MICROPY_HW_USRSW_PIN        (pin_B10)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)  // active low

// HSE is 16MHz - F401 does 84 MHz max
#define MICROPY_HW_CLK_PLLM (16)
#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV4)
#define MICROPY_HW_CLK_PLLQ (7)
#define MICROPY_HW_CLK_LAST_FREQ    (1)

// The PYFLEX_F401 has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// UART config
#define MICROPY_HW_UART2_TX     (pin_A2)
#define MICROPY_HW_UART2_RX     (pin_A3)
//   #define MICROPY_HW_UART2_RTS    (pin_A1)
//   #define MICROPY_HW_UART2_CTS    (pin_A0)
#define MICROPY_HW_UART_REPL        PYB_UART_2
#define MICROPY_HW_UART_REPL_BAUD   9600

// UART 6 not avail in F401CE package..
//   #define MICROPY_HW_UART1_TX     (pin_A9)
//   #define MICROPY_HW_UART1_RX     (pin_A10)

// I2C busses
#define MICROPY_HW_I2C1_SCL     (pin_B6)
#define MICROPY_HW_I2C1_SDA     (pin_B7)

#define MICROPY_HW_I2C2_SCL     (pin_B4)
#define MICROPY_HW_I2C2_SDA     (pin_B3)

// SPI busses
#define MICROPY_HW_SPI1_NSS     (pin_A15)
#define MICROPY_HW_SPI1_SCK     (pin_B3)
#define MICROPY_HW_SPI1_MISO    (pin_B4)
#define MICROPY_HW_SPI1_MOSI    (pin_B5)

// The PYFLEX_F401 has No SDCard - not enough pins on QFN48 package.
