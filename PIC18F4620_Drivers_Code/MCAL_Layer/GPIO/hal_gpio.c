/* 
 * @File:   hal_gpio.h
 * @Author: Mostafa Ahmed Allam
 * @email:  maag7503@gmail.com
 * @LinkedIn: https://www.linkedin.com/in/mostafa-allam-58869624a/
 */

#include "hal_gpio.h"


/* ---------------------- Datatype Section ---------------------- */

/*reference to port register, reads pin status*/
volatile uint8 *PORT[] = { &PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
/*reference to tris register, output or input*/
volatile uint8 *TRIS[] = { &TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
/*reference to lat register, out HIGH or LOW*/
volatile uint8 *LAT [] = { &LATA,&LATB,&LATC,&LATD,&LATE};


/* ---------------------- Function definition Section ---------------------- */
STD_ReturnType gpio_pin_initialize                  (const pin_config_t *pin)
{
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(pin);
        gpio_pin_write_logic(pin,GPIO_LOW);
        ret = E_OK;
    }
    
    return ret;
}
STD_ReturnType gpio_pin_direction_initialize        (const pin_config_t *pin)
{
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == pin) 
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(pin->direction)
        {
            case GPIO_OUTPUT:
                CLEAR_BIT(*(TRIS[pin->port]),pin->pin);
                ret = E_OK;
                break;
            case GPIO_INPUT:
                SET_BIT(*(TRIS[pin->port]),pin->pin);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;              
        }
    }
    return ret;
}

STD_ReturnType gpio_pin_get_direction_status        (const pin_config_t *pin,direction_t *dir)
{
    STD_ReturnType ret = E_NOT_OK;
    if((NULL == pin) || (NULL == dir))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dir = READ_BIT(*TRIS[pin->port],pin->pin);
        ret = E_OK;
    }
    
    return ret;
}

STD_ReturnType gpio_pin_write_logic                 (const pin_config_t *pin,logic_t logic)
{
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
         switch(logic)
        {
            case GPIO_LOW:
                CLEAR_BIT(*(LAT[pin->port]),pin->pin);
                ret = E_OK;
                break;
            case GPIO_HIGH:
                SET_BIT(*(LAT[pin->port]),pin->pin);
                ret = E_OK;
                break;
            default:
                ret = E_NOT_OK;              
        }
        ret = E_OK;
    }
    
    return ret;
}

STD_ReturnType gpio_pin_read_logic                  (const pin_config_t *pin,logic_t* logic)
{
    STD_ReturnType ret = E_NOT_OK;
    if((NULL == pin) || (NULL == logic))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = READ_BIT(*LAT[pin->port],pin->pin);
        ret = E_OK;
    }
    
    return ret;
}

STD_ReturnType gpio_pin_toggle_logic                (const pin_config_t *pin)
{
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == pin)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*LAT[pin->port],pin->pin);
        ret = E_OK;
    }
    
    return ret;
}


STD_ReturnType gpio_port_direction_initialize        (port_t port, uint8 dir)
{
    STD_ReturnType ret = E_NOT_OK;
    
    *TRIS[port] = dir;
    return ret;
}
STD_ReturnType gpio_port_get_direction_status        (port_t port,uint8 *dir)
{
    STD_ReturnType ret = E_NOT_OK;
    
    *dir = *TRIS[port];
    return ret;
}

STD_ReturnType gpio_port_write_logic                 (port_t port,uint8 logic)
{
    STD_ReturnType ret = E_NOT_OK;
    
    *LAT[port]= logic;
    return ret;
}

STD_ReturnType gpio_port_read_logic                  (port_t port,uint8* logic)
{
    STD_ReturnType ret = E_NOT_OK;
    
    *logic = *LAT[port];
    return ret;
}

STD_ReturnType gpio_port_toggle_logic                (port_t port)
{
    STD_ReturnType ret = E_NOT_OK;
    
    *LAT[port] ^= 0xFF;
    return ret;
}
