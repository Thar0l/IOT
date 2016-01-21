### Aduino Stairs Light LED Controller ###

#### Overwiev ####
Device turns on LED strips from down stairs to up or from up to down. Direction depends on signals from two PIR motion sensors.

#### Hardvare ####

* Arduino Pro Mini x1
* Step-down voltage Converter x1
* IRL2905 xStepsCount

#### Hardware Limits ####

You can connect from 1 to 18 led strips and 2 motion sensors to controller.
This version is for 11 steps.

#### Adjusting params ####

Change const **stairs_count = 11** to your stairs count.

Change PIR motion sensors pins in **up_pir_pin** and **down_pir_pin**.

Change **stairs_pins** array initialisation to your pinout.

Change **light_delay** - delay between steps lightning up and **check_delay** - delay between sensors scanning.

#### About ####
This project is from Tharol`s IOT repo (https://github.com/Thar0l/IOT).

You can contact author throught github on VK (http://vk.com/Thar0l)
