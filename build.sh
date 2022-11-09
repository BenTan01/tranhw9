#!/bin/bash
config-pin p9.12 gpio
echo out > /sys/class/gpio/gpio60/direction
config-pin p8.16 gpio_pu
g++ control_GPIO.cpp -o control_GPIO -pthread
