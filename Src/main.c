/**
 * Project template
 * RT & Embedded Systems course material
 *
 * Prepared by: Jakub Mnich (jakub.mnich@pwr.edu.pl)
 * Wrocław University of Science and Technology
 * March 2022
 *
 * Works with STM32F407VGT6 (STM32F407G-DISC1)
 ******************************************************************************
 */

/*
 * Note:
 * "stm32xxxxxx.h" are header files delivered by the MCU manufacturer. These files
 * contain information allowing us to refer to registers by their names rather than
 * their actual addresses in the memory. This makes it much easier to write the
 * code and it will also be more readable.
 */
/**
 * Project template
 * RT & Embedded Systems course material
 *
 * Prepared by: Jakub Mnich (jakub.mnich@pwr.edu.pl)
 * Wrocław University of Science and Technology
 * March 2022
 *
 * Works with STM32F407VGT6 (STM32F407G-DISC1)
 ******************************************************************************
 */

/*
 * Note:
 * "stm32xxxxxx.h" are header files delivered by the MCU manufacturer. These files
 * contain information allowing us to refer to registers by their names rather than
 * their actual addresses in the memory. This makes it much easier to write the
 * code and it will also be more readable.
 */
#include "stm32f407xx.h"

#define GREEN_LED_PIN (1 << 12)
#define BLUE_LED_PIN (1 << 15)
#define RED_LED_PIN (1 << 14)
#define ORANGE_LED_PIN (1 << 13)
#define GPIO_PORT GPIOD

void delay(uint32_t count);

int main(void)
{
	// Enable GPIO clock for GPIOD
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // GPIODEN is a AHB1ENR register's bit that used to reach D port.

	// Configure LED pins as output.
	GPIO_PORT -> MODER |= (GPIO_MODER_MODER12_0 | GPIO_MODER_MODER13_0 | GPIO_MODER_MODER14_0 | GPIO_MODER_MODER15_0);
	// Configure the desired I/O as output or input in the GPIOx_MODER register
	while(1) {
		// Toggle green LED
		// GPIOx_ODR stores the data to be output, it is read/write accessible. The data input through the I/O are stored into the input data register. (GPIOx_IDR), a read-only register
		GPIO_PORT->ODR ^= GREEN_LED_PIN;
		delay(2e6);
		GPIO_PORT->ODR ^= BLUE_LED_PIN;
		delay(2e6);
		GPIO_PORT->ODR ^= RED_LED_PIN;
		delay(2e6);
		GPIO_PORT->ODR ^= ORANGE_LED_PIN;
		delay(2e6);
	}
}

void delay(uint32_t count){

	for(volatile uint32_t i =0; i < count; i++);
}





