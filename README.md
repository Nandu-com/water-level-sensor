# Water Level Sensor

Arduino water-level monitor using three conductive probes, status LEDs, and a buzzer alarm.

## Hardware

- Arduino Uno, Nano, or compatible board
- Low-level probe
- Medium-level probe
- High-level probe
- Green LED for low level
- Yellow LED for medium level
- Red LED for high level
- Buzzer
- Appropriate LED current-limiting resistors

## Pin Connections

| Component | Arduino pin |
|---|---:|
| Low probe | D2 |
| Medium probe | D3 |
| High probe | D4 |
| Green LED | D8 |
| Yellow LED | D9 |
| Red LED | D10 |
| Buzzer | D11 |

The probes use `INPUT_PULLUP`. Connect the common/reference water electrode to GND. A probe is considered active when it touches water and the input reads `LOW`.

## Behavior

- Green LED: low-level probe detects water
- Yellow LED: medium-level probe detects water
- Red LED: high-level probe detects water
- Buzzer: active while the high-level probe detects water
- Serial Monitor: 9600 baud

Open `water_level_sensor.ino` in the Arduino IDE, select your board and port, and upload it.
