/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500
DigitalOut led1(LED1);

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
    printf("System Clock: %ld\n", SystemCoreClock);

    while (true)
    {
        led1 = !led1;
        const unsigned int num_loops =
          SystemCoreClock / 4  // loops per second, with 4x fudge factor
          / 1000  // loops per ms
          * 500;  // go for 500ms
        for (volatile unsigned int i = 0; i < num_loops; i++) ;
    }
}
