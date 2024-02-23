#include "dag-lcd.h"

DagLCD::DagLCD(LCD_I2C *_lcd) : timer()
{
    lcd = _lcd;
    timer.init(timer_duration, true);
}

void DagLCD::init(String row1, String row2)
{
    lcd->begin();
    lcd->backlight();
    lcd->home();
    lcd->print(row1);
    lcd->setCursor(0, 1);
    lcd->print(row2);
    delay(2000);
    lcd->clear();
}

int DagLCD::next()
{
    active_page = active_page >= sizeof(pages) ? 0 : active_page + 1;
    timer.init(timer_duration, true);
    return active_page;
}

int DagLCD::run()
{
    // se il timer è scaduto passa alla pagina principale
    active_page = timer.clock() ? 0 : active_page;
    pages[active_page]();
    return active_page;
}

void DagLCD::zap(int index)
{
    active_page = index;
}

uint8_t DagLCD::backlight(void)
{
    bl = !bl;
    switch (bl)
    {
    case HIGH:
        lcd->backlight();
        break;
    case LOW:
        lcd->noBacklight();
        break;
    }
    return bl;
}
