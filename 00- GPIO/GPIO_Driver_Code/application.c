/* 
 * @File:   application.c
 * @Author: Mostafa Ahmed Allam
 * @email:  maag7503@gmail.com
 * @LinkedIn: https://www.linkedin.com/in/mostafa-allam-58869624a/
 */

#include "application.h"

pin_config_t pin1 = {
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN0,
    .port = GPIO_PORTC
};
int main() {
    
    /* Testing pin interfaces*/
#if 0 
    gpio_pin_initialize(&pin1);
    while(1){
        gpio_pin_write_logic(&pin1,GPIO_HIGH);
        __delay_ms(300);
        gpio_pin_write_logic(&pin1,GPIO_LOW);
        __delay_ms(300); 
    }
#endif
#if 0
    gpio_pin_initialize(&pin1);
    while(1){
        gpio_pin_toggle_logic(&pin1);
        __delay_ms(300);
    }
#endif
    
    
    /* Testing port interfaces*/
#if 0
    gpio_port_direction_initialize(GPIO_PORTC,0x00);
    while(1)
    {
        gpio_port_write_logic(GPIO_PORTC,0xf0);
        __delay_ms(300);
        gpio_port_write_logic(GPIO_PORTC,0xf0);
        __delay_ms(300);
                
    }
#endif
#if 0
    gpio_port_direction_initialize(GPIO_PORTC,0x00);
    while(1)
    {
        gpio_port_toggle_logic(GPIO_PORTC);
        __delay_ms(300);
    }
#endif
    
    return 0;
}

