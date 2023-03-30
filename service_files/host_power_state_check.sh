#!/bin/bash

# Set all output GPIOs as such and drive them with reasonable values.
function set_gpio_active_low() {
  if [ $# -ne 2 ]; then
    echo "set_gpio_active_low: need both GPIO# and initial level";
    return;
  fi

  echo $1 > /sys/class/gpio/export
  echo 1 > /sys/class/gpio/gpio$1/active_low
  echo $2 > /sys/class/gpio/gpio$1/direction
}

GPIO_BASE=$(cat /sys/devices/platform/ahb/ahb:apb/1e780000.gpio/gpio/*/base)
GPIOB3=$((${GPIO_BASE}+15))

set_gpio_active_low $GPIOB3 in

exit 0;                                