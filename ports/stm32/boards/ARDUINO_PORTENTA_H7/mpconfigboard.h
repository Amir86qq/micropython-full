/*
 * This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022 Arduino SA
 */

#define MICROPY_HW_BOARD_NAME       "Arduino Portenta H7" // Name kept as requested
#define MICROPY_HW_MCU_NAME         "STM32H743"
#define MICROPY_HW_FLASH_FS_LABEL   "Portenta H7"

// Network config
#define MICROPY_PY_NETWORK_HOSTNAME_DEFAULT "mpy-portenta-h7"

#define MICROPY_OBJ_REPR            (MICROPY_OBJ_REPR_C)

#define MICROPY_FATFS_EXFAT         (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_ENABLE_MMCARD    (0)
#define MICROPY_HW_ENTER_BOOTLOADER_VIA_RESET   (0)

// ROMFS config
#define MICROPY_HW_ROMFS_ENABLE_EXTERNAL_QSPI       (1)
#define MICROPY_HW_ROMFS_QSPI_SPIFLASH_OBJ          (&spi_bdev.spiflash)
#define MICROPY_HW_ROMFS_ENABLE_PART0               (1)

// Flash storage config
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE            (1)
#define MICROPY_HW_SPIFLASH_SOFT_RESET              (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE    (0)

#define MICROPY_BOARD_STARTUP       PORTENTA_board_startup
void PORTENTA_board_startup(void);

#define MICROPY_BOARD_EARLY_INIT    PORTENTA_board_early_init
void PORTENTA_board_early_init(void);

#define MICROPY_BOARD_ENTER_BOOTLOADER(nargs, args) PORTENTA_board_enter_bootloader()
void PORTENTA_board_enter_bootloader(void);

void PORTENTA_board_low_power(int mode);
#define MICROPY_BOARD_LEAVE_STOP    PORTENTA_board_low_power(0);
#define MICROPY_BOARD_ENTER_STOP    PORTENTA_board_low_power(1);
#define MICROPY_BOARD_ENTER_STANDBY PORTENTA_board_low_power(2);

void PORTENTA_board_osc_enable(int enable);
#define MICROPY_BOARD_PRE_STOP      PORTENTA_board_osc_enable(0);
#define MICROPY_BOARD_POST_STOP     PORTENTA_board_osc_enable(1);

// PLL1 480MHz for CPU (From your custom board config)
#define MICROPY_HW_CLK_PLLM             (5)
#define MICROPY_HW_CLK_PLLN             (192)
#define MICROPY_HW_CLK_PLLP             (2)
#define MICROPY_HW_CLK_PLLQ             (20)
#define MICROPY_HW_CLK_PLLR             (2)
#define MICROPY_HW_CLK_PLLVCI           (RCC_PLL1VCIRANGE_2)
#define MICROPY_HW_CLK_PLLVCO           (RCC_PLL1VCOWIDE)
#define MICROPY_HW_CLK_PLLFRAC          (0)

// PLL2 200MHz for FMC and QSPI.
#define MICROPY_HW_CLK_PLL2M            (5)
#define MICROPY_HW_CLK_PLL2N            (80)
#define MICROPY_HW_CLK_PLL2P            (2)
#define MICROPY_HW_CLK_PLL2Q            (2)
#define MICROPY_HW_CLK_PLL2R            (2)
#define MICROPY_HW_CLK_PLL2VCI          (RCC_PLL2VCIRANGE_2)
#define MICROPY_HW_CLK_PLL2VCO          (RCC_PLL2VCOWIDE)
#define MICROPY_HW_CLK_PLL2FRAC         (0)

// PLL3 160MHz for ADC and SPI123
#define MICROPY_HW_CLK_PLL3M            (5)
#define MICROPY_HW_CLK_PLL3N            (160)
#define MICROPY_HW_CLK_PLL3P            (2)
#define MICROPY_HW_CLK_PLL3Q            (5)
#define MICROPY_HW_CLK_PLL3R            (2)
#define MICROPY_HW_CLK_PLL3VCI          (RCC_PLL3VCIRANGE_2)
#define MICROPY_HW_CLK_PLL3VCO          (RCC_PLL3VCOWIDE)
#define MICROPY_HW_CLK_PLL3FRAC         (0)

// HSE in BYPASS mode is disabled (Custom board uses standard crystal)
#define MICROPY_HW_CLK_USE_BYPASS       (0)

// Bus clock divider values
#define MICROPY_HW_CLK_AHB_DIV          (RCC_HCLK_DIV2)
#define MICROPY_HW_CLK_APB1_DIV         (RCC_APB1_DIV2)
#define MICROPY_HW_CLK_APB2_DIV         (RCC_APB2_DIV2)
#define MICROPY_HW_CLK_APB3_DIV         (RCC_APB3_DIV2)
#define MICROPY_HW_CLK_APB4_DIV         (RCC_APB4_DIV2)

// Peripheral clock sources
#define MICROPY_HW_RCC_HSI48_STATE      (RCC_HSI48_ON)
#define MICROPY_HW_RCC_USB_CLKSOURCE    (RCC_USBCLKSOURCE_HSI48)
#define MICROPY_HW_RCC_RTC_CLKSOURCE    (RCC_RTCCLKSOURCE_LSI)
#define MICROPY_HW_RCC_FMC_CLKSOURCE    (RCC_FMCCLKSOURCE_PLL2)
#define MICROPY_HW_RCC_RNG_CLKSOURCE    (RCC_RNGCLKSOURCE_HSI48)
#define MICROPY_HW_RCC_ADC_CLKSOURCE    (RCC_ADCCLKSOURCE_PLL3)
#define MICROPY_HW_RCC_SDMMC_CLKSOURCE  (RCC_SDMMCCLKSOURCE_PLL)
#define MICROPY_HW_RCC_FDCAN_CLKSOURCE  (RCC_FDCANCLKSOURCE_PLL)
#define MICROPY_HW_RCC_SPI123_CLKSOURCE (RCC_SPI123CLKSOURCE_PLL3)
#define MICROPY_HW_RCC_I2C123_CLKSOURCE (RCC_I2C123CLKSOURCE_D2PCLK1)
#define MICROPY_HW_RCC_QSPI_CLKSOURCE   (RCC_QSPICLKSOURCE_PLL2)

// SMPS configuration (Changed to LDO for custom board)
#define MICROPY_HW_PWR_SMPS_CONFIG      (PWR_LDO_SUPPLY)

// Configure the analog switches for dual-pad pins.
#define MICROPY_HW_ANALOG_SWITCH_PA0    (SYSCFG_SWITCH_PA0_OPEN)
#define MICROPY_HW_ANALOG_SWITCH_PA1    (SYSCFG_SWITCH_PA1_OPEN)
#define MICROPY_HW_ANALOG_SWITCH_PC2    (SYSCFG_SWITCH_PC2_OPEN)
#define MICROPY_HW_ANALOG_SWITCH_PC3    (SYSCFG_SWITCH_PC3_OPEN)

// There is an external 32kHz oscillator
#define RTC_ASYNCH_PREDIV           (0)
#define RTC_SYNCH_PREDIV            (0x7fff)
#define MICROPY_HW_RTC_USE_BYPASS   (1)
#define MICROPY_HW_RTC_USE_US       (1)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

#if (MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE == 0)
// QSPI flash #1 for storage (Custom board uses 256MBits = 32MB)
#define MICROPY_HW_QSPI_PRESCALER           (2) // 100MHz
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (28)
#define MICROPY_HW_SPIFLASH_SIZE_BITS       (256 * 1024 * 1024)
#define MICROPY_HW_QSPIFLASH_CS             (pyb_pin_QSPI2_CS)
#define MICROPY_HW_QSPIFLASH_SCK            (pyb_pin_QSPI2_CLK)
#define MICROPY_HW_QSPIFLASH_IO0            (pyb_pin_QSPI2_D0)
#define MICROPY_HW_QSPIFLASH_IO1            (pyb_pin_QSPI2_D1)
#define MICROPY_HW_QSPIFLASH_IO2            (pyb_pin_QSPI2_D2)
#define MICROPY_HW_QSPIFLASH_IO3            (pyb_pin_QSPI2_D3)

// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_SPIFLASH    (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev)
#endif

// Flash latency
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_2

// UART config (From your custom board)
#define MICROPY_HW_UART1_TX         (pin_B14)
#define MICROPY_HW_UART1_RX         (pin_B15)
#define MICROPY_HW_UART_REPL        PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

#define MICROPY_HW_UART2_TX         (pin_A2)
#define MICROPY_HW_UART2_RX         (pin_A3)

// I2C buses (From your custom board)
#define MICROPY_HW_I2C1_SCL         (pin_B6)
#define MICROPY_HW_I2C1_SDA         (pin_B7)

#define MICROPY_HW_I2C2_SCL         (pin_H4)
#define MICROPY_HW_I2C2_SDA         (pin_H5)

// SPI buses (SPI3 for SD Card, From your custom board)
#define MICROPY_HW_SPI3_NSS         (pin_I2)
#define MICROPY_HW_SPI3_SCK         (pin_B3)
#define MICROPY_HW_SPI3_MISO        (pin_B4)
#define MICROPY_HW_SPI3_MOSI        (pin_B5)

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_A0)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (1)

// LEDs (From your custom board)
#define MICROPY_HW_LED1             (pin_G13) // Red
#define MICROPY_HW_LED2             (pin_B8)  // Green
#define MICROPY_HW_LED3             (pin_I8)  // Blue
#define MICROPY_HW_LED4             (pin_I4)  // IR
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_low(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_high(pin))

// USB config (From your custom board)
#define MICROPY_HW_USB_FS           (1)
#define MICROPY_HW_USB_CDC_RX_DATA_SIZE     (1024)
#define MICROPY_HW_USB_CDC_TX_DATA_SIZE     (1024)
#define MICROPY_HW_USB_CDC_1200BPS_TOUCH    (1)
#define GPIO_AF10_OTG_HS                    (GPIO_AF10_OTG2_HS)

// SDRAM (Custom board 16-bit 32MB - schematic says MT48LC16M16A2P)
#define MICROPY_HW_SDRAM_SIZE               (32 * 1024 * 1024) // 32MB
#define MICROPY_HW_SDRAM_STARTUP_TEST       (0)
#define MICROPY_HW_SDRAM_TEST_FAIL_ON_ERROR (true)
#define MICROPY_HW_FMC_SWAP_BANKS           (0)

// Timing configuration (Copied exactly from your custom file for MT48LC16M16A2P-75)
#define MICROPY_HW_SDRAM_CLOCK_PERIOD       2
#define MICROPY_HW_SDRAM_CAS_LATENCY        3
#define MICROPY_HW_SDRAM_FREQUENCY_KHZ      (100000) // 100 MHz
#define MICROPY_HW_SDRAM_TIMING_TMRD        (16)
#define MICROPY_HW_SDRAM_TIMING_TXSR        (16)
#define MICROPY_HW_SDRAM_TIMING_TRAS        (16)
#define MICROPY_HW_SDRAM_TIMING_TRC         (16)
#define MICROPY_HW_SDRAM_TIMING_TWR         (16)
#define MICROPY_HW_SDRAM_TIMING_TRP         (16)
#define MICROPY_HW_SDRAM_TIMING_TRCD        (16)

#define MICROPY_HW_SDRAM_ROW_BITS_NUM       13
#define MICROPY_HW_SDRAM_MEM_BUS_WIDTH      16
#define MICROPY_HW_SDRAM_REFRESH_CYCLES     8192

#define MICROPY_HW_SDRAM_COLUMN_BITS_NUM    9
#define MICROPY_HW_SDRAM_INTERN_BANKS_NUM   4
#define MICROPY_HW_SDRAM_RPIPE_DELAY        0
#define MICROPY_HW_SDRAM_RBURST             (1)
#define MICROPY_HW_SDRAM_WRITE_PROTECTION   (0)

#define MICROPY_HW_SDRAM_AUTOREFRESH_NUM    (8)
#define MICROPY_HW_SDRAM_BURST_LENGTH       1
#define MICROPY_HW_SDRAM_REFRESH_RATE       (64) // ms

// SDRAM configuration (Copied exactly from your custom file - FMC pins)
#define MICROPY_HW_FMC_SDCKE0       (pin_C3)
#define MICROPY_HW_FMC_SDNE0        (pin_C2)
#define MICROPY_HW_FMC_SDNBL0       (pin_E0)
#define MICROPY_HW_FMC_SDNBL1       (pin_E1)
#define MICROPY_HW_FMC_SDCLK        (pin_G8)
#define MICROPY_HW_FMC_SDNCAS       (pin_G15)
#define MICROPY_HW_FMC_SDNRAS       (pin_F11)
#define MICROPY_HW_FMC_SDNWE        (pin_C0)
#define MICROPY_HW_FMC_BA0          (pin_G4)
#define MICROPY_HW_FMC_BA1          (pin_G5)
#define MICROPY_HW_FMC_NBL0         (pin_E0)
#define MICROPY_HW_FMC_NBL1         (pin_E1)
#define MICROPY_HW_FMC_A0           (pin_F0)
#define MICROPY_HW_FMC_A1           (pin_F1)
#define MICROPY_HW_FMC_A2           (pin_F2)
#define MICROPY_HW_FMC_A3           (pin_F3)
#define MICROPY_HW_FMC_A4           (pin_F4)
#define MICROPY_HW_FMC_A5           (pin_F5)
#define MICROPY_HW_FMC_A6           (pin_F12)
#define MICROPY_HW_FMC_A7           (pin_F13)
#define MICROPY_HW_FMC_A8           (pin_F14)
#define MICROPY_HW_FMC_A9           (pin_F15)
#define MICROPY_HW_FMC_A10          (pin_G0)
#define MICROPY_HW_FMC_A11          (pin_G1)
#define MICROPY_HW_FMC_A12          (pin_G2)
#define MICROPY_HW_FMC_D0           (pin_D14)
#define MICROPY_HW_FMC_D1           (pin_D15)
#define MICROPY_HW_FMC_D2           (pin_D0)
#define MICROPY_HW_FMC_D3           (pin_D1)
#define MICROPY_HW_FMC_D4           (pin_E7)
#define MICROPY_HW_FMC_D5           (pin_E8)
#define MICROPY_HW_FMC_D6           (pin_E9)
#define MICROPY_HW_FMC_D7           (pin_E10)
#define MICROPY_HW_FMC_D8           (pin_E11)
#define MICROPY_HW_FMC_D9           (pin_E12)
#define MICROPY_HW_FMC_D10          (pin_E13)
#define MICROPY_HW_FMC_D11          (pin_E14)
#define MICROPY_HW_FMC_D12          (pin_E15)
#define MICROPY_HW_FMC_D13          (pin_D8)
#define MICROPY_HW_FMC_D14          (pin_D9)
#define MICROPY_HW_FMC_D15          (pin_D10)

// USB IDs (Kept Arduino for Bootloader compatibility)
#define MICROPY_HW_USB_VID                      0x2341
#ifndef MICROPY_HW_USB_PID
#define MICROPY_HW_USB_PID                      0x055B
#endif
#define MICROPY_HW_USB_PID_CDC_MSC              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_HID              (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_MSC                  (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3                 (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC             (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC_MSC_HID          (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC2_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_PID_CDC3_MSC_HID         (MICROPY_HW_USB_PID)
#define MICROPY_HW_USB_LANGID_STRING            0x409
#define MICROPY_HW_USB_MANUFACTURER_STRING      "Arduino"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "Portenta Virtual Comm Port in FS Mode"
#define MICROPY_HW_USB_PRODUCT_HS_STRING        "Portenta Virtual Comm Port in HS Mode"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "Portenta Interface"
#define MICROPY_HW_USB_INTERFACE_HS_STRING      "Portenta Interface"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "Portenta Config"
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  "Portenta Config"
