/*!
    \file  main.c
    \brief running led

    \version 2019-6-5, V1.0.0, firmware for GD32VF103
*/

/*
    Copyright (c) 2019, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32vf103.h"
#include <stdio.h>
#include "nuclei_sdk_soc.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/

/*
 * LED_R: PC_13
 * LED_G: PA_1
 * LED_B: PA_2
 */

int main(void)
{
    /* enable the LED clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOC);
    /* configure LED GPIO port */
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1 | GPIO_PIN_2);
    gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);

    gpio_bit_set(GPIOA, GPIO_PIN_1 | GPIO_PIN_2);
    gpio_bit_set(GPIOC, GPIO_PIN_13);

    while(1){
        /* turn on LED_R, turn off LED_B */
        gpio_bit_reset(GPIOC, GPIO_PIN_13);
        gpio_bit_set(GPIOA, GPIO_PIN_2);
        delay_1ms(1000);

        /* turn on LED_G, turn off LED_R */
        gpio_bit_reset(GPIOA, GPIO_PIN_1);
        gpio_bit_set(GPIOC, GPIO_PIN_13);
        delay_1ms(1000);

        /* turn on LED_B, turn off LED_G */
        gpio_bit_reset(GPIOA, GPIO_PIN_2);
        gpio_bit_set(GPIOA, GPIO_PIN_1);
        delay_1ms(1000);
    }
}
