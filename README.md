# ESP32_TempDevice
**Prerequisites: ** I used Arduinos IDE to create the code and load it onto my ESP 32. Note that the Arduino IDE needs to set up to load programs into the ESP 32 Microcontroller. I was able to find countless guides on Youtube to accomplish this. 

**Purpose:** I wanted to create a Temperature sensor device that I can place inside my PC and read the Temperature inside while in use. To accomplish this I decided to use a ESP 32 with Temperature and OLED Display. 

**Devices Used:** 

* ESP 32 Dev Board
  * Purchased on Amazon
  * Price: 11 - 20 Dollars
* Tiny OLED Screen (SSD1306)
  * DC Voltage: 3.3 ~5 V
  * Communication Protocol Used: I^2C
  * Dimensions: 0.91 Inch 
  * Resolution: 128 x 32.
* Temperature and Humidity Sensor (DHT11)
  * Measure Range: 20% - 95%
  * DC Voltage: 3.3 ~ 5V
  * 0 - 50 Celsius 

**Other Equipment Used: **

* Bread Board
* Wires
* 10 Kilo-ohmm Resistor (Not Needed with my DHT 11 Module)
* USB to Micro USB cable

**Connection Guide**

I first start off by connecting my 3.3 Volt and Ground pins from my esp 32 into the positive and negative rails on the bread board. I can then from the power rails connect my Tiny OLED Screen by connecting the positive power rail to VCC on the Screen and Negative rail to Ground (Note that Negative refers to ground). Next I connect the positive rail to Positive input for the DHT 11 Module, then I connect the Negative Input to the Negative Rail on my Bread board. Now I completed connecting all my power cables into their respective modules. 

For the data ports I connect OLED Screen SDA pin to my esp 32s GPIO 21 and then SCL pin to GPIO 22 (Note these are the default ESP 32 pins for I2C communication). Next is the DHT 11 Sensor which its Out Pin connects to my ESP 32's GPIO 4 port (Note some guide mention you will need to use a 10 Kilo Ohm Resister in series with the Out Port, however after some testing I did not need to use the 10 Kiloohm Resister, It worked with and without, Resistor may have already be built in the DHT module.). This conclude the Data port connections Guide. 

**Resources Used**

* https://web.archive.org/web/20220128170718/https://desire.giesecke.tk/index.php/2018/01/30/esp32-dht11/
* https://web.archive.org/web/20220715151117/https://github.com/beegee-tokyo/DHTesp/blob/master/DHTesp.cpp
* https://web.archive.org/web/20220715145824/https://github.com/beegee-tokyo/DHTesp
* https://www.amazon.com/dp/B08LQM9PQQ?ref=ppx_yo2ov_dt_b_product_details&th=1
  * Ronald P. Robertson Simple Sequence For Displaying Hello World 







