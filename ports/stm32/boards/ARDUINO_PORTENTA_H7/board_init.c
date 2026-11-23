/*
 * This file is part of the MicroPython project, http://micropython.org/
 * The MIT License (MIT)
 * Copyright (c) 2022 Arduino SA
 */
#include <string.h>
#include "py/mphal.h"
#include "storage.h"
#include "sdram.h"

// Note: eth.h and ulpi.h were removed because the custom H743 board
// does not have the Portenta's Ethernet PHY or external USB ULPI.

void PORTENTA_board_startup(void) {
}

void PORTENTA_board_early_init(void) {
    HAL_InitTick(0);

    // Enable oscillator pin
    PORTENTA_board_osc_enable(true);

    #if MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
    // The Arduino/mbed bootloader uses the MPU to protect sector 1
    // which is used for the flash filesystem. The following code
    // resets and disables all MPU regions configured in the bootloader.
    HAL_MPU_Disable();
    MPU_Region_InitTypeDef MPU_InitStruct;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

    for (int i = MPU_REGION_NUMBER0; i < MPU_REGION_NUMBER15; i++) {
        MPU_InitStruct.Number = i;
        MPU_InitStruct.Enable = MPU_REGION_DISABLE;
        HAL_MPU_ConfigRegion(&MPU_InitStruct);
    }
    #endif

    // =========================================================================
    // CUSTOM BOARD HARDWARE REMOVALS:
    // The PMIC I2C fix, Ethernet PHY reset, and USB ULPI low-power code 
    // from the original Portenta H7 have been removed because the custom 
    // STM32H743 board does not have these physical components.
    // Leaving them in would cause an I2C/ETH initialization hang or HardFault.
    // =========================================================================
}

// This is the standard Portenta H7 logic for entering the DFU bootloader.
// It uses the RTC Backup Register to pass a magic value (0xDF59) to the bootloader,
// then resets the MCU. This perfectly matches your requirement to keep Portenta's logic.
void PORTENTA_board_enter_bootloader(void) {
    RTC_HandleTypeDef RTCHandle;
    RTCHandle.Instance = RTC;
    HAL_RTCEx_BKUPWrite(&RTCHandle, RTC_BKP_DR0, 0xDF59);
    NVIC_SystemReset();
}

void PORTENTA_board_osc_enable(int enable) {
    // The custom board uses a standard 25MHz crystal on OSC_IN/OSC_OUT pins,
    // unlike the Portenta which uses a bypass oscillator with a dedicated OSCEN pin.
    // Thus, this function is left empty to prevent pin conflicts, but kept 
    // so the Portenta's structure (which calls this function) remains intact.
    (void)enable;
}

void PORTENTA_board_low_power(int mode) {
    switch (mode) {
        case 0:     // Leave stop mode.
            sdram_leave_low_power();
            break;
        case 1:     // Enter stop mode.
            sdram_enter_low_power();
            break;
        case 2:     // Enter standby mode.
            sdram_enter_power_down();
            break;
    }

    #if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
    // Enable QSPI deepsleep for modes 1 and 2
    mp_spiflash_deepsleep(&spi_bdev.spiflash, (mode != 0));
    #endif

    // Note: The HSEM logic for signaling the Cortex-M4 core was removed 
    // because the custom board uses STM32H743 (Single-Core), not STM32H747.
}
