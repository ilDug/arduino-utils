# Shift Register 

## 74hc595 - pinout

![pinout]("./74HC595-Shift-Register-pinout.png")


Il **74HC595** è un registro a scorrimento a 8 bit comunemente utilizzato in progetti di elettronica. Ecco una descrizione dei suoi pin:

- **SER** (Serial Input): Questo pin prende l'input seriale che sarà trasferito nei registri a scorrimento.

- **OE** (Output Enable): Questo pin è usato per abilitare o disabilitare l'output. Quando è basso, l'output è abilitato e quando è alto, l'output è disabilitato.  _COLLEGARE A GND_

- **Q0 - Q7** (Output Pins): Questi sono i pin di output del registro a scorrimento. Dopo che i dati sono stati spostati, possono essere letti da questi pin.

- **SRCLK** (Shift Register Clock): Questo pin è usato per sincronizzare lo spostamento dei dati nel registro a scorrimento. positive edge triggered. 

- **RCLK** (Register Clock / LATCH): Questo pin è usato per sincronizzare il trasferimento dei dati dal registro a scorrimento ai pin di output. positive edge triggered

- **SRCLR** (Shift Register Clear): Questo pin è usato per cancellare il registro a scorrimento. Quando è basso, il registro a scorrimento viene cancellato. _COLLEGARE A Vcc_

- **Q7'** (Serial Output): Questo pin è usato per la cascata dei dati da un 74HC595 all'altro. I dati vengono spostati da Q7' a SER dell'altro 74HC595.

- **GND** (Ground): Questo pin è collegato alla terra del circuito.

- **Vcc** (Power): Questo pin è collegato all'alimentazione del circuito.

| Pin  | Nome                          | Pin Arduino      |
|------|-------------------------------|------------------|
| 1    | SER (Serial Input)            | 11 (MOSI)        |
| 2    | OE (Output Enable)            | GND              |
| 3-10 | Q0 - Q7 (Output Pins)         | Dipende dall'uso |
| 11   | SRCLK (Shift Register Clock)  | 13 (SCK)         |
| 12   | RCLK (Register Clock / LATCH) | 10 (SS)          |
| 13   | SRCLR (Shift Register Clear)  | VCC              |
| 14   | Q7' (Serial Output)           | -                |
| 15   | GND (Ground)                  | GND              |
| 16   | Vcc (Power)                   | VCC              |

