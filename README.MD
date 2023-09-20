# HAL DRIVER FOR nRF52 USING ZEPHYR RTOS ON PLATFORMIO

## Pre-requisites
- platform-nordicnrf52 @10.1 (ZephyrRTOS) v2.7.1

## PWM0 channels 
- [0 1 2 3] ~ [P0.2 P0.11 P0.14 P0.15] 
- The PWM channel can be change to any GPIO pin via overlay file in zephyr directory

## ADC channels 
- [0 1 2 3 4 5 6 7] ~ [P0.2 P0.3 P0.4 P0.5 P0.28 P0.29 P0.30 P0.31] 
- ADC channels are fixed and cannot be changed