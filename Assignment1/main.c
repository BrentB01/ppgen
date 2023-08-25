/**************************************************************
 * main.c
 * rev 1.0 16-Aug-2023 Brent
 * Assignment1
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    // Initialise components and variables
    stdio_init_all();

    #define RED_LED 11
    #define GREEN_LED 12
    #define BLUE_LED 13
    #define SW1 2
    #define SW2 3
    #define SW3 4

    bool redLedOn = false;
    bool greenLedOn = false;
    bool blueLedOn = false;

    // CALCULATE NUMBER OF SWITCHES
    const uint SWITCH_PINS[] = {SW1, SW2, SW3};
    const size_t NUM_SWITCHES = sizeof(SWITCH_PINS) / sizeof(SWITCH_PINS[0]);

    // INITIALISE LEDS
    const uint LED_PINS[] = {RED_LED, GREEN_LED, BLUE_LED};
    for (size_t i = 0; i < sizeof(LED_PINS) / sizeof(LED_PINS[0]); i++) {
        gpio_init(LED_PINS[i]);
        gpio_set_dir(LED_PINS[i], GPIO_OUT);
    }

    // INITIALISE SWITCHES
    for (size_t i = 0; i < NUM_SWITCHES; i++) {
        gpio_init(SWITCH_PINS[i]);
        gpio_set_dir(SWITCH_PINS[i], GPIO_IN);
        gpio_pull_up(SWITCH_PINS[i]);
    }

    while (true) {
        for (size_t i = 0; i < NUM_SWITCHES; i++) {
            if (!gpio_get(SWITCH_PINS[i])) { // Button is pressed (LOW)
                switch (SWITCH_PINS[i]) {
                    case SW1:
                        redLedOn = !redLedOn;
                        printf("Toggled red LED\n");
                        break;
                    case SW2:
                        greenLedOn = !greenLedOn;
                        printf("Toggled green LED\n"); // MODIFY THIS SO THAT IT READS ALL  CURRENT VALUES (ALL BUTTONS PRESSED SHOULD BE WHITE)
                        break;
                    case SW3:
                        blueLedOn = !blueLedOn;
                        printf("Toggled blue LED\n");
                        break;
                    default:
                        break;
                }
                while (!gpio_get(SWITCH_PINS[i])) {
                }
            }
        }

        gpio_put(RED_LED, redLedOn);
        gpio_put(GREEN_LED, greenLedOn);
        gpio_put(BLUE_LED, blueLedOn);
    }

    return 0;
}
