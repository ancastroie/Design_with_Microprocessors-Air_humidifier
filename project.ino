#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#include "DHT.h"

#define DHTPIN A0

#define DHTTYPE DHT11 

#define relay 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  dht.begin();

}

void loop() {
  float Humid = dht.readHumidity();
  float Temp = dht.readTemperature();
  
  Serial.print("Temp");
  Serial.print(Temp);
  delay(1000);
  Serial.print("Humid");
  Serial.print(Humid);
  delay(1000);

  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_9x18);
    u8g.setPrintPos(1,40);
    u8g.print("Temp: ");
    u8g.print(Temp);
    u8g.print("'C");
    u8g.setPrintPos(1,60);
    u8g.print("Humid: ");
    u8g.print(Humid);
    u8g.print("%");
  }while(u8g.nextPage());

if(Humid<80){
  digitalWrite(relay,LOW);
}else
{
  digitalWrite(relay,HIGH);

}


}



  
