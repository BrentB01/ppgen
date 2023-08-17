/**************************************************************
 * main.c
 * rev 1.0 16-Aug-2023 Brent
 * Assignment1
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>


int main(void) {
  // TODO - Initialise components and variables
  stdio_init_all();
  #define RED_LED 11
  #define BLUE_LED 12
  #define GREEN_LED 13
  gpio_init(RED_LED);
  gpio_init(GREEN_LED);
  gpio_init(BLUE_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);
  gpio_set_dir(GREEN_LED, GPIO_OUT);
  gpio_set_dir(BLUE_LED, GPIO_OUT);

  while (true) {
    // TODO - Repeated code here
    char input = getchar_timeout_us(0);
    if (input != PICO_ERROR_TIMEOUT) {
    switch (input) {
                case '1':
                    gpio_xor_mask(1u << RED_LED);
                    printf("Toggled red LED\n");
                    break;
                case '2':
                    gpio_xor_mask(1u << GREEN_LED);
                    printf("Toggled green LED\n");
                    break;
                case '3':
                    gpio_xor_mask(1u << BLUE_LED);
                    printf("Toggled blue LED\n");
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
