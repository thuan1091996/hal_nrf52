# HAL DRIVER FOR nRF52 USING ZEPHYR RTOS ON PLATFORMIO

## Pre-requisites
- platform-nordicnrf52 @10.1 (ZephyrRTOS) v2.7.1

## PWM0 channels 
- [0 1 2 3] ~ [P0.2 P0.11 P0.14 P0.15] 
- The PWM channel can be change to any GPIO pin via overlay file in zephyr directory

## UART pins
- UART0 - TX: P0.19 
- UART0 - RX: P0.20

## I2C pins
- I2C0 - SCL: P0.22
- I2C0 - SDA: P0.23

## ADC channels 
- [0 1 2 3 4 5 6 7] ~ [P0.2 P0.3 P0.4 P0.5 P0.28 P0.29 P0.30 P0.31] 
- ADC channels are fixed and cannot be changed

## Reset
- nRST pin (P0.21 on nRF52-DK) can be enable/disable by System_EnableResetPin()/System_DisableResetPin respectively. But care must be taken when using System_DisableResetPin() because it will erase all the UICRs sector