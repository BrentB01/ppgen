/**************************************************************
 * main.c
 * rev 1.0 16-Aug-2023 Brent
 * Lab4
 * ***********************************************************/
#include <stdint.h>

#define LED_PIN 25
#define DELAY_ITERATIONS 8000000

#define SIO_BASE 0xd0000000
#define LED_BASE 0x40014000

#define GPIO_OUT_SET (SIO_BASE + 0x014)
#define GPIO_OUT_CLR (SIO_BASE + 0x018)
#define GPIO_OE_SET (SIO_BASE + 0x024)

#define PAD_CONTROL_BASE 0x40014000
#define PAD_CONTROL_OFFSET 0x68

#define FUNCTION_GPIO_F5 0x05

// Macro to read or write a register's content
#define CONTENT_OF(addr) (*(volatile uint32_t*)(addr))

// Delay function
void delay(uint32_t iterations) {
    for (uint32_t i = 0; i < iterations; i++) {
        __asm volatile ("nop");
    }
}

int main(void) {
    // Enable GPIO25 pad
    CONTENT_OF(PAD_CONTROL_BASE + PAD_CONTROL_OFFSET) |= (1 << 6);  // Set bit 6 to enable input (Flag)

    // Select GPIO function for LED_PIN 
    CONTENT_OF(PAD_CONTROL_BASE + PAD_CONTROL_OFFSET) = (CONTENT_OF(PAD_CONTROL_BASE + PAD_CONTROL_OFFSET) & ~0x80) | FUNCTION_GPIO_F5;

    // Set LED_PIN as output
    CONTENT_OF(GPIO_OE_SET) &= ~(1 << LED_PIN);

    // TODO: Implement code to enable function (F5) to enable GPIO (check done correctly)
    // TODO: Check that all definitions are correct
    while (1) {
        // Turn on the LED
        CONTENT_OF(GPIO_OUT_SET) = (1 << LED_PIN);
        delay(DELAY_ITERATIONS);

        // Turn off the LED
        CONTENT_OF(GPIO_OUT_CLR) = (1 << LED_PIN);
        delay(DELAY_ITERATIONS);
    }

    return 0;
}