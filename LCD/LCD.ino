#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

//pin 21 y 22 sw la esp32 vcc y gnd para que funcione

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin();//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo Conecta el pin VCC del adaptador al pin 5V del ESP32.
//Conecta el pin GND del adaptador al pin GND del ESP32.
//Conecta el pin SDA del adaptador al pin GPIO 21 del ESP32.
//Conecta el pin SCL del adaptador al pin GPIO 22 del ESP32.

  lcd.setCursor (0, 0);//poner el cursor en las coordenadas (x,y)
  lcd.print("Temp: ");//muestra en la pantalla max 20 caracteres
  lcd.setCursor (0, 1);//poner el cursor en las coordenadas (x,y)
  lcd.print("Hum:  % ");//muestra en la pantalla max 20 caracteres
  
}

void loop() {
  lcd.setCursor (0, 3);//poner el cursor en las coordenadas (x,y)
  lcd.print("Tiempo activo:");//muestra en la pantalla max 20 caracteres
  //La funcion millis() regresa los ms que lleva encendido
  //Lo dividimos entre 1000 para que nos muestre en segundos.
  lcd.print(millis()/1000);
  lcd.print("s");
  delay(1000);//Esperamos 1 segundo antes de repetir el loop
}