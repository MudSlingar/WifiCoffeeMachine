# WifiCoffeeMachine
A project to run a simple NTPClient based alarm operated coffee machine

## Index
1. [Display](#display)
2. [WiFi](#wifi)
3. [Timekeeping](#timekeeping-with-ntpclient)
4. [Led](#led)
5. [Servo](#servo)

## Display
The display is a 128x64 OLED display, managed with the Adafruit_SSD1306 library.
See [Helpful guide](https://www.instructables.com/Arduino-and-the-SSD1306-OLED-I2C-128x64-Display/) on how to write or draw on it.
I only write the day of the week and hours, or a message when the time is right for coffee.
Here is how to write a simple message on the machine

```
#include <Adafruit_GFX.h>          // including libraries
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128           // setting the dimensions of the screen
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT); // initializing display

void writeMessage(){
  display.clearDisplay();          // clears the display
  display.setTextColor(COLOR);     // change COLOR with the desired color
  display.setTextSize(n);          // change n with the desired size
  display.setCursor(x,y);          // change x and y with the coordinates
  display.println("Hello world");  // writes Hello World in one line
  display.display();               // applies the changes
}
```

## WiFi

## Timekeeping with NTPClient

## Led

## Servo
