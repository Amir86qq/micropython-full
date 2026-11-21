/*
 * This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (C) 2013-2025 OpenMV, LLC.
 */

#define MICROPY_HW_BOARD_NAME       "OPENMV4"
#define MICROPY_HW_MCU_NAME         "STM32H743"
#define MICROPY_PY_SYS_PLATFORM     "OpenMV4-H7"
#define MICROPY_HW_FLASH_FS_LABEL   "OPENMV"

// Network config
#define MICROPY_PY_NETWORK_HOSTNAME_DEFAULT "mpy-openmv-4"

#define MICROPY_OBJ_REPR            (MICROPY_OBJ_REPR_C)
#define UINT_FMT                    "%u"
#define INT_FMT                     "%d"
typedef int mp_int_t;               // must be pointer size
typedef unsigned int mp_uint_t;     // must be pointer size

#define MICROPY_FATFS_EXFAT         (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_SPI2      (0)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_SERVO     (1)
#define MICROPY_HW_ENABLE_TIMER     (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_ENTER_BOOTLOADER_VIA_RESET   (0)
#define MICROPY_HW_TIM_IS_RESERVED(id) (id == 1 || id == 6)

// ROMFS config — internal flash (no QSPI on this board).
#define MICROPY_HW_ROMFS_ENABLE_INTERNAL_FLASH  (1)
#define MICROPY_HW_ROMFS_ENABLE_PART0           (1)

#define MICROPY_BOARD_ENTER_STANDBY

extern void board_enter_bootloader(void);
#define MICROPY_BOARD_ENTER_BOOTLOADER(nargs, args) board_enter_bootloader()

// PLL: HSE=25MHz → VCO_in=5MHz → VCO=960MHz → P=2 (480MHz), Q=20 (48MHz).
#define MICROPY_HW_CLK_PLLM         (5)
#define MICROPY_HW_CLK_PLLN         (192)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (20)
#define MICROPY_HW_CLK_PLLR         (2)

// UART1 config (P0/P1)
#define MICROPY_HW_UART1_TX  (pin_B14)
#define MICROPY_HW_UART1_RX  (pin_B15)
#define MICROPY_HW_UART_REPL        (1)
#define MICROPY_HW_UART_REPL_BAUD   (115200)

// UART2 config (PA2/PA3)
#define MICROPY_HW_UART2_TX  (pin_A2)
#define MICROPY_HW_UART2_RX  (pin_A3)

// I2C buses
// I2C1 (PB6/PB7)
#define MICROPY_HW_I2C1_SCL (pin_B6)
#define MICROPY_HW_I2C1_SDA (pin_B7)

// I2C2 (PH4/PH5)
#define MICROPY_HW_I2C2_SCL (pin_H4)
#define MICROPY_HW_I2C2_SDA (pin_H5)

// SPI buses (SPI3 for SD card)
#define MICROPY_HW_SPI3_NSS  (pin_I2)
#define MICROPY_HW_SPI3_SCK  (pin_B3)
#define MICROPY_HW_SPI3_MISO (pin_B4)
#define MICROPY_HW_SPI3_MOSI (pin_B5)

// USB config
#define MICROPY_HW_USB_FS                   (1)
#define MICROPY_HW_USB_CDC_RX_DATA_SIZE     (512)
#define MICROPY_HW_USB_CDC_TX_DATA_SIZE     (512)
// #define MICROPY_HW_USB_VBUS_DETECT_PIN      (pin_A9)

// LEDs
#define MICROPY_HW_LED1             (pin_G13) // Red
#define MICROPY_HW_LED2             (pin_B8)  // Green
#define MICROPY_HW_LED3             (pin_I8)  // Blue
#define MICROPY_HW_LED4             (pin_I4)  // IR
#define MICROPY_HW_LED_OTYPE        (GPIO_MODE_OUTPUT_PP)
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_write((pin), ((pin) == MICROPY_HW_LED4)))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_write((pin), ((pin) != MICROPY_HW_LED4)))

// Servos
#define PYB_SERVO_NUM (2)

// Board network interfaces config.
#if MICROPY_PY_WINC1500
extern const struct _mp_obj_type_t mod_network_nic_type_winc;
#define MICROPY_PY_USOCKET_EXTENDED_STATE   (1)
#define MICROPY_BOARD_NETWORK_INTERFACES \
    { MP_ROM_QSTR(MP_QSTR_WINC), MP_ROM_PTR(&mod_network_nic_type_winc) },\
    { MP_ROM_QSTR(MP_QSTR_WLAN), MP_ROM_PTR(&mod_network_nic_type_winc) },
#else
#define MICROPY_BOARD_NETWORK_INTERFACES
#endif

// PC2/PC3 free now (SDRAM removed) → switch OPEN for high-Z.
#define MICROPY_HW_ANALOG_SWITCH_PC2    (SYSCFG_SWITCH_PC2_OPEN)
#define MICROPY_HW_ANALOG_SWITCH_PC3    (SYSCFG_SWITCH_PC3_OPEN)

#define MICROPY_HW_USB_VID                      0x37C5
#define MICROPY_HW_USB_PID                      0x124A
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
#define MICROPY_HW_USB_MANUFACTURER_STRING      "OpenMV"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "OpenMV Virtual Comm Port in FS Mode"
#define MICROPY_HW_USB_PRODUCT_HS_STRING        "OpenMV Virtual Comm Port in HS Mode"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "VCP Interface"
#define MICROPY_HW_USB_INTERFACE_HS_STRING      "VCP Interface"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "VCP Config"
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  "VCP Config"
