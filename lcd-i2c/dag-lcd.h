#ifndef DAG_LCD_H
#define DAG_LCD_H

#include "Arduino.h"
#include <Wire.h>
#include <LCD_I2C.h>

#include "../dag-timer/dag-timer.h"

// typedef void (*Page)(void);

// char t[8];
// dtostrf(geo.temp, 3, 1, t); // arrotonda al primo decimale e lo passa nella variabile t
// lcd.print(t);               // cambiare float con int per avere la lettura arrotondata all'intero
// lcd.print("\xDF"
//           "C");

void page_main(void) {}





void (*pages[])(void) = {page_main};

class DagLCD
{
private:
    void (*pages[8])(void);           // Array di pagine
    LCD_I2C *lcd;                        // Display LCD
    int active_page = 0;                 // Pagina attiva
    bool bl = true;                      // Backlight
    unsigned long timer_duration = 5000; // Durata del timer
    DagTimer timer;                      // Timer

public:
    /**
     * Inizializza il display LCD
     * deve essere passato un istanze d LCD_I2C
     * LCD_I2C lcd(0x27, 16, 2);
     * SDA => A4: SCL => A5
     */
    DagLCD(LCD_I2C *_lcd);

    /**
     * Inizializza il display LCD ( da chiamre nel setup)
     * row1: stringa da visualizzare sulla prima riga
     * row2: stringa da visualizzare sulla seconda riga
     */
    void init(String row1, String row2);

    // passa alla pagina successiva contenuta nell'array pages
    int next();

    // esegue la pagina attiva
    int run();

    // visualizza una pagina definita dall'index
    void zap(int index);

    // toggle backlight
    uint8_t backlight(void);
};
#endif