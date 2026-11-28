include("$(PORT_DIR)/boards/manifest.py")

# Utils
require("time")
require("senml")
require("logging")

# Note: 
# Networking (bundle-networking) and Bluetooth (aioble) modules have been removed 
# because the custom STM32H743 board does not have the Portenta's CYW43 WiFi/BT chip.

# Note: 
# The 'arduino-lib' (which includes SE05x and CMWX1 Lora drivers) has been removed 
# because the custom board does not have these specific hardware components.
# add_library("arduino-lib", "$(ARDUINO_LIB_DIR)")
# require("msgpackrpc", library="arduino-lib")
# require("cmwx1", library="arduino-lib")
# require("se05x", library="arduino-lib")

# OpenMV Vision Libraries (Based on your custom board's needs)
add_library("openmv-lib", "$(OMV_LIB_DIR)")

# Standard Drivers
require("onewire")
require("ds18x20")
require("dht")
require("neopixel")

# Frozen Python Modules for Vision/System
freeze ("$(OMV_LIB_DIR)/", "pid.py")
freeze ("$(OMV_LIB_DIR)/", "machine.py")
freeze ("$(OMV_LIB_DIR)/", "display.py")
freeze ("$(OMV_LIB_DIR)/", "sensor.py")
freeze ("$(OMV_LIB_DIR)/", "mutex.py")

# ML Models & Boot script
require("ml", library="openmv-lib")
include("$(MPY_DIR)/extmod/asyncio")

# Boot script
freeze ("$(OMV_LIB_DIR)/", "_boot.py")
