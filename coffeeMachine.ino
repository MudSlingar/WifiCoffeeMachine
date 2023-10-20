// SERVO INITIALIZATION
//#include <Servo.h>
//Servo myservo;  // create servo object to control a servo
//int potpin = 0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin


// DISPLAY INITIALIZATION
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);


// WIFI INITIALIZATION
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid      ="FASTWEB-E09023";
const char *password  ="K1YJYG9T2R";

WiFiUDP ntpUDP;


// TIME MANAGER INITIALIZATION
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7200, 60000);
const char *daysOfTheWeek[7] = {"Domenica", "Lunedi", "Martedi", "Mercoledi", "Giovedi", "Venerdi", "Sabato"};


// LED INITIALIZATION
int led = 22;

void setup() {
    //attaches the servo on pin 9 to the servo object
    //myservo.attach(9);

    // ATTIVAZIONE SCHERMO
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
      while(true);
    }
    display.clearDisplay(); //pulizia buffer
    display.display();      //applico la pulizia al display

    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);

    // ATTIVAZIONE WIFI
    WiFi.begin(ssid, password);
    // check connessione
    while(WiFi.status() != WL_CONNECTED) {
      display.setCursor(0, SCREEN_HEIGHT/2);
      display.print(".");
      delay(500);
    }

    // ATTIVAZIONE TIMEKEEPING
    timeClient.begin();

    //ATTIVAZIONE LED
    pinMode(led, OUTPUT);

    display.clearDisplay();
    display.setCursor(0, SCREEN_HEIGHT/2);
    display.println("INIZIO...");
    display.display();
    delay(500);
}

void loop() {
  // TIME UPDATE
  timeClient.update();

  // the if defines the alarm
  if(timeClient.getHours() == 17 && timeClient.getMinutes() == 50) {
    stampaTestoAttivo();
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
    // TESTO PER MACCHINA INATTIVA
    stampaTestoInattivo();
  }
  delay(6000);
}

void stampaTestoInattivo() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(45, 4);

  // Giorno della settimana
  display.print(daysOfTheWeek[timeClient.getDay()]);

  // Hour and minute print in big
  display.setTextSize(3);
  display.setCursor(0, SCREEN_HEIGHT/2);
  display.print(" ");
  display.print(timeClient.getHours());
  display.print(":");
  display.print(timeClient.getMinutes());
  
  // Stampa
  display.display();
}

void stampaTestoAttivo() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, SCREEN_HEIGHT/2);
  display.setTextSize(3);

  // Testo di prova
  display.println(" ATTIVO! ");

  // Stampa
  display.display();
}

void move() {
  //// reads the value of the potentiometer (value between 0 and 1023)
  //val = analogRead(potpin);            
  //// scale it to use it with the servo (value between 0 and 180)
  //val = map(val, 0, 1023, 0, 180);     
  //// sets the servo position according to the scaled value
  //myservo.write(val);                  
  //// waits for the servo to get there
  //delay(15);                           
}
