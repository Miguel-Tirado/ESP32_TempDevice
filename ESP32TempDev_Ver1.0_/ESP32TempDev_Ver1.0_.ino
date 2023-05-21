/*
 *  Made By: Miguel Tirado 
 *  Date: 2023-05-06
 *  Board Type Used: ESP32 Dev Module
 *  Decvices Used: ESP32, DHT11 Temp & Humidity Sensor, MakorFocus I^2C OLED Display SSD1306
 *  Version: 1.0
 */
//Import Adafruit libraries
#include <Adafruit_SSD1306.h>
#include "DHTesp.h"

//Set Constants for readability purposes
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
// I2C address 
#define SCREEN_ADDRESS 0x3C

#define DHTPIN 4

DHTesp dht;
TaskHandle_t tempTaskHandle = NULL;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);
  dht.setup(DHTPIN, DHTesp::DHT11);


  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
}

void loop() {
  // Adding a 4 Sec delay before getting temp
  delay(4000);
  TempAndHumidity lastvalues = dht.getTempAndHumidity();
  float f = dht.toFahrenheit(lastvalues.temperature);

  // Check to see if the value of F is not a number
  // Then output a Fail Responce through serial and Display
  if (isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("TMP: Fail!");
    display.display();
    return;
  }

  // Print Serial to test and debug using the serial monitor
  Serial.println("Temperature: " + String(f,0) + "°F");

  // Wipe the OLED Screen and set the Cursor to start to print the temp
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("TMP: "+ String(f,0) + "F");
  display.display();
  delay(1000);
  
}
