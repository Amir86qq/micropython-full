USE_MBOOT = 0
USE_PYDFU = 0

# For dual core HAL drivers. (Kept as H7 M7 core flag)
CFLAGS += -DCORE_CM7

# Arduino bootloader PID:VID (Kept exactly as Portenta for Arduino DFU compatibility)
BOOTLOADER_DFU_USB_VID = 0x2341
BOOTLOADER_DFU_USB_PID = 0x035b

# MCU settings (Changed to H743 and matching custom board's linker script)
MCU_SERIES = h7
CMSIS_MCU = STM32H743xx
MICROPY_FLOAT_IMPL = single
AF_FILE = boards/stm32h743_af.csv
LD_FILES = boards/ARDUINO_PORTENTA_H7/stm32h743.ld
TEXT0_ADDR = 0x08040000

# MicroPython settings
# Disabled Bluetooth, LWIP, CYW43 (WiFi), SSL, and OpenAMP (M4 core) 
# because the custom board uses a single-core H743 without these hardwares.
MICROPY_PY_BLUETOOTH = 0
MICROPY_BLUETOOTH_NIMBLE = 0
MICROPY_BLUETOOTH_BTSTACK = 0
MICROPY_PY_LWIP = 0
MICROPY_PY_NETWORK_CYW43 = 0
MICROPY_PY_SSL = 0
MICROPY_PY_SSL_ECDSA_SIGN_ALT = 0
MICROPY_SSL_MBEDTLS = 0
MICROPY_PY_OPENAMP = 0
MICROPY_PY_OPENAMP_REMOTEPROC = 0

# Removed ARDUINO_LIB_DIR and GIT_SUBMODULES as the custom board 
# does not use Arduino's specific external libraries (like se05x, cmwx1).
FROZEN_MANIFEST = $(BOARD_DIR)/manifest.py
MBEDTLS_CONFIG_FILE = '"$(BOARD_DIR)/mbedtls_config_board.h"'
