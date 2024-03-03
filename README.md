# Fan-Controller-project
Implementation of the Fan Controller system using ATmega32

Based on your requirements, you're planning to develop a temperature-controlled fan system using an ATmega32 microcontroller. This project incorporates several drivers for components like the ADC, GPIO, LCD, temperature sensor, DC motor, and PWM generation through Timer0. Each of these components plays a crucial role in the overall system, working together to control the fan speed based on the temperature readings from the LM35 sensor.

To design and implement this system, you'll follow a layered architecture approach. This involves developing drivers for each hardware component that abstracts the hardware-specific details away from the main application logic. Below is an outline of how each driver could be implemented, adhering to your specified requirements:
