/**************************************************
 * LEDDriver.c
 * Drives LED display
 *
 * Copyright 2015 University of Strathclyde
 *
 *
 **************************************************/

#include "LedDriver.h"

//Current dial value
unsigned char ledValue_ = 0;

/**
Initialise LED Dial, setting GPIO parameters
*/
void initialiseLedDial()
{
  //GPIO 2.7
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN7);
    
  //GPIO 5.1, 5.2, 5.3
  //Inserted by student
  GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1  | GPIO_PIN2 | GPIO_PIN3);

    
  //GPIO 8.0
  //Inserted by student
  GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0);
}

/** 
Refresh the display
*/
void refreshLedDial()
{
  //Refresh lower bank (LEDs 1-4)
 //Inserted by student
  GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
  GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
  GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN2);
  GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN3);
  GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
  __delay_cycles(10000);  //Delay 10ms
  //Refresh lower bank (LEDs 5-9)
  //Inserted by student
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN1);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN2);
  GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN3);
  GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0);
  __delay_cycles(10000);  //Delay 10ms
}

/** 
Set dial value
*/
void setLedDial(unsigned char value)
{
  ledValue_ = value;
}
