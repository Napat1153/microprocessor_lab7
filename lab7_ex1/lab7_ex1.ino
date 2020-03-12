#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, 
OLED_RESET);
#define button1 9
#define button2 8
void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("SW 1");
  display.setTextSize(2);
  display.println("SW 2");
  display.setTextColor(BLACK, WHITE);
  display.drawCircle(100, 7, 6, WHITE);
  display.drawCircle(100, 22, 6, WHITE);
  display.display();
}


void loop() {
  if(digitalRead(button1)==0){
    display.fillCircle(100, 7, 6, WHITE);
    Serial.println("1");
    }
  else if(digitalRead(button1)==1){
    display.fillCircle(100, 7, 6, BLACK);
    }
  if(digitalRead(button2)==0){
    display.fillCircle(100, 22, 6, WHITE);
    Serial.println("2");
    }
  else if(digitalRead(button1)==1){
    display.fillCircle(100, 22, 6, BLACK);
    }
   Serial.println("AA");
   display.display();
}
