/* 
 * @File:   hal_gpio.h
 * @Author: Mostafa Ahmed Allam
 * @email:  maag7503@gmail.com
 * @LinkedIn: https://www.linkedin.com/in/mostafa-allam-58869624a/
 */


#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* ---------------------- Include Section ---------------------- */

#include "pic18f4620.h"
#include "../../MCAL_Layer/device_cfg.h"
#include "../../MCAL_Layer/std_types.h"
#include "hal_gpio_cfg.h"

/* ---------------------- Macro definition Section ---------------------- */

#define BIT_MASK                            (uint8)1
/* ---------------------- Macro Function Section ---------------------- */
#define SET_BIT(REG, POS)                   (REG |= (BIT_MASK << POS))
#define CLEAR_BIT(REG, POS)                 (REG &= ~(BIT_MASK << POS))
#define TOGGLE_BIT(REG, POS)                (REG ^= (BIT_MASK << POS))

#define READ_BIT(REG,POS)                   (( REG >> POS) & BIT_MASK)


/* ---------------------- Datatype Section ---------------------- */


typedef enum
{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}pin_t;

typedef enum
{
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
}port_t;

typedef enum
{
    GPIO_OUTPUT = 0,
    GPIO_INPUT = 1
}direction_t;

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1
}logic_t;

typedef struct
{
    uint8 port : 3;
    uint8 pin  : 3;
    uint8 direction : 1;
    uint8 logic : 1;
}pin_config_t;
/* ---------------------- Function declaration Section ---------------------- */
/**
 * @brief: This function used in initializing pins as output and low logic.
 * @param pin: this is a pointer to the required pin.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_initialize                  (const pin_config_t *pin);
/**
 * @brief: This function used in initializing pins direction(output or input).
 * @param pin: this is a pointer to the required pin.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_direction_initialize        (const pin_config_t *pin);
/**
 * @brief: This function used in getting pin directions status(output or input) .
 * @param pin: this is a pointer to the required pin.
 * @param dir: this is a pointer to carry direction status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_get_direction_status        (const pin_config_t *pin,direction_t *dir);
/**
 * @brief: This function used in controlling pin logic (High or Low).
 * @param pin: this is a pointer to the required pin(High or Low).
 * @param logic: this is used to identify pin status .
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_write_logic                 (const pin_config_t *pin,logic_t logic);
/**
 * @brief: This function used in getting pin status.
 * @param pin: this is a pointer to the required pin.
 * @param logic: this is a pointer to carry pin status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_read_logic                  (const pin_config_t *pin,logic_t* logic);
/**
 * @brief: This function used in toggling pin status.
 * @param pin: this is a pointer to the required pin.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_pin_toggle_logic                (const pin_config_t *pin);

/**
 * @brief: This function used in initializing port direction(output or input).
 * @param port: this is the port that will be accessed.
 * @param dir: this is variable used in identifying port pins status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_port_direction_initialize        (port_t port, uint8 dir);
/**
 * @brief: This function used in getting port direction(output or input).
 * @param port: this is the port that will be accessed.
 * @param dir: this is pointer used in carrying port pins status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_port_get_direction_status        (port_t port,uint8 *dir);
/**
 * @brief: This function used in accessing port logic status(High or Low).
 * @param port: this is the port that will be accessed.
 * @param logic: this is variable used in identifying port pins status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_port_write_logic                 (port_t port,uint8 logic);
/**
 * @brief: This function used in getting port logic status.
 * @param port: this is the port that will be accessed.
 * @param logic: this is pointer used in identifying port pins status.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_port_read_logic                  (port_t port,uint8* logic);
/**
 * @brief: This function used in toggling port pins status.
 * @param port: this is the port that will be accessed.
 * @return STD_ReturnType: this is an indicator if the functions succeeded or not.
 */
STD_ReturnType gpio_port_toggle_logic                (port_t port);

#endif	/* HAL_GPIO_H */

