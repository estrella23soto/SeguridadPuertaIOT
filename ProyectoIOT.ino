#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <ESP32Servo.h>
//broker
#include <PubSubClient.h>
#include <WiFi.h>

#define ESP_ARDUINO_VERSION_VAL(major, minor, patch) (major*10000 + minor*100 + patch)

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);//crear un objeto lcd (DIRECCIÓN pantalla, Tamaño x, Tamño y)

//pin 21 y 22 sw la esp32 vcc y gnd para que funcione

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <IRremote.hpp>

#define DHTPIN 5
#define DHTTYPE DHT11
#define IR_PIN 27//////////////////++++++++++++++++++++++
#define SENSOR_Incli 18


int angle = 0;          // variable que almacena el ángulo del servo
Servo myservo;          // creamos un objeto del tipo Servo
unsigned long last = millis();


DHT_Unified dht(DHTPIN, DHTTYPE);

// Replace with your network credentials
const char* ssid = "2ccb68";
const char* password = "275532666";

// Initialize Telegram BOT
#define BOTtoken "6259351281:AAEclqY-rEHEPuCE98LtjYn9jYSR3gS_RrE"

// message you
#define CHAT_ID "2048831420"

#define SENSOR_PIN 2
#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 500;
unsigned long lastTimeBotRan;

const int buzzerPin = 12; // Cambia 16 al número de pin que estés usando
const int ledPin = 2;
bool ledState = LOW;

bool pirDetected = false;
float temperature;
float humidity;


// Definir el pin de entrada del sensor PIR
const int pirPin = 23;

//Servo configuration
const int servoPin = 14;
///////////////////////////////////////////////////////////////////////////777
//const char* password = "275532666";
const char* mqtt_server = "192.168.0.31";//cambiar por la ip del rasberry
const char* mqtt_topic = "micasa/plantabaja/temperatura";
const char* mqtt_inclinacion = "micasa/plantabaja/inclinacion";
const char* topicServo = "micasa/plantabaja/servo";
const char* topicbuzzer = "micasa/plantabaja/buzzer";

WiFiClient wifiClient;
PubSubClient cliente(wifiClient);


//////////////////////////////////////////////////////////////////////////////


// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/Abrir to turn GPIO ON \n";
      welcome += "/Cerrar to turn GPIO OFF \n";
      welcome += "/Estado to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/Abrir") {
      bot.sendMessage(chat_id, "Cerradura abierta", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
      myservo.write(0); //move servo to 90 degrees
      delay(500); //wait for servo to finish moving
      digitalWrite(buzzerPin, HIGH); // Enciende el buzzer
      delay(500); // Espera medio segundo
      digitalWrite(buzzerPin, LOW); // Apaga el buzzer
    }
    
    if (text == "/Cerrar") {
      bot.sendMessage(chat_id, "Cerradura bloqueada", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
      
      myservo.write(90); //move servo to 0 degrees
      delay(500); //wait for servo to finish moving
      digitalWrite(buzzerPin, HIGH); // Enciende el buzzer
    delay(500); // Espera medio segundo
    digitalWrite(buzzerPin, LOW); // Apaga el buzzer
    }
    
  //...
if (text == "/Estado") {

sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
      Serial.println(F("Error "));
      temperature = -1;
    }
    else {
      temperature = event.temperature;
    }
    
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
      Serial.println(F("Error"));
      humidity = -1;
    }
    else {
      humidity = event.relative_humidity;
    }
    
    String message = "PIR sensor state: ";
    if (pirDetected) {
      message += "HIGH - Movement detected\n";
    } else {
      message += "LOW - No movement detected\n";
    }
    message += "DHT11 sensor state:\nTemperature: " + String(temperature) + " °C\nHumidity: " + String(humidity) + " %";
    bot.sendMessage(chat_id, message, "");
  }  
  // Leemos el estado del sensor infrarrojo
  int sensorState = digitalRead(SENSOR_Incli);

  // Construimos el mensaje a enviar
  String message = "Actividad: ";
  if (pirDetected) {
    message += "Moviminto Detectado\n";
  } else {
    message += "No Hay Moviminto Detectado\n";
  }
  message += "Estado de la Cerradura: ";
  if (sensorState == HIGH) {
    message += "Cerradura Bloqueda\n";
  } else {
    message += "Cerradura Abierta\n";
  }
  message += "Valores de Temperatura:\nTemperatura: " + String(temperature) + " °C\nHumedad: " + String(humidity) + " %";

  // Enviamos el mensaje
  bot.sendMessage(chat_id, message, "");
}

  //...


    //     if (text == "/state") {
    //   String message;
    //   if (pirDetected) {
    //     message = "Sensor state is HIGH - Movement detected";
    //   } else {
    //     message = "Sensor state is LOW - No movement detected";
    //   }
    //   bot.sendMessage(chat_id, message, "");
    // }

    // if (text == "/state") {
    //   int sensorValue = digitalRead(SENSOR_PIN);
    //   String message = "Sensor state is " + String(sensorValue);
    //   bot.sendMessage(chat_id, message, "");
      
    // }
  }


void setup() {
  Serial.begin(115200);
    //Iniciamos la comunicación serial

  //Configuramos el pin del sensor como entrada
  pinMode(SENSOR_Incli, INPUT);


  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  myservo.attach(14);    // indicamos el pin al que está conectado el servo
  myservo.write(angle); // colocamos el servo en su posición inicial

  IrReceiver.begin(15, false);

  ////////////////////////////////////////////////////////////////
  // Initialize the PIR sensor pin as an input
pinMode(pirPin, INPUT);
// Initialize the IR sensor pin as an input
pinMode(IR_PIN, INPUT);

  ////////////////////////////////////////////////////////////////
  // Configurar el pin del sensor PIR como entrada
  pinMode(pirPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  WiFi.begin(ssid,password);
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
    client.setInsecure(); 

  // Initialize LED pin as output
  pinMode(ledPin, OUTPUT);

  //Initialize Servo
  myservo.attach(servoPin);

  // Start the bot
  Serial.println("Initializing Bot...");
  Serial.println("Bot Online!");
  
lcd.begin();//inicializar la pantalla lcd
  lcd.backlight();//Encender la luz de fondo Conecta el pin VCC del adaptador al pin 5V del ESP32.
//Conecta el pin GND del adaptador al pin GND del ESP32.
//Conecta el pin SDA del adaptador al pin GPIO 21 del ESP32.
//Conecta el pin SCL del adaptador al pin GPIO 22 del ESP32.

  sensor_t sensor;
  dht.begin();
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("DHT11 Temperature and Humidity Sensor");
  Serial.println("------------------------------------");
  Serial.println("Sensor: " + String(sensor.name));
  Serial.println("Driver Ver: " + String(sensor.version));
  Serial.println("Unique ID: " + String(sensor.sensor_id));
  Serial.println("Max Value: " + String(sensor.max_value) + "C");
  Serial.println("Min Value: " + String(sensor.min_value) + "C");
  Serial.println("Resolution: " + String(sensor.resolution) + "C");
  Serial.println("------------------------------------");
  //delay(2000);  
  
  cliente.setServer(mqtt_server, 1883);
  while (!client.connected()) {
    if (cliente.connect("ioTClient")) {
      Serial.println("Conexión MQTT establecida.");
      cliente.setCallback(callback);
    } else {
      Serial.print("Error de conexión MQTT, estado: ");
      Serial.println(cliente.state());
      delay(2000);
    }

  }

  // Suscribirse al topic del servo
  cliente.subscribe(topicServo);
}


void loop() {

  
   cliente.loop();

  // Leer el estado del sensor PIR
  int pirValue = digitalRead(pirPin);
  if (pirValue == HIGH) {
    pirDetected = true;
  } else {
    pirDetected = false;
  }
  delay(100);

    //Leemos el estado del sensor
  int sensorState = digitalRead(SENSOR_Incli);

  //Si el sensor está inclinado
  if (sensorState == HIGH) {

    Serial.println("Cerradura bloqueada");
  } else {
    Serial.println("Cerradura abierta");
  }
  char msg2[16];
  
  snprintf(msg2, 16, "%f,%f", sensorState);

  cliente.publish(mqtt_inclinacion, msg2);

  //Esperamos un segundo antes de volver a leer el sensor
  delay(1000);

  // Si el sensor detecta movimiento
  // if (pirState == HIGH) {
  //   Serial.println("¡Movimiento detectado!");
  // } else {
  //   Serial.println("No se detectó movimiento");
  // }
  
// if (pirState == HIGH) {
//   Serial.println("¡Movimiento detectado!");
//   pirDetected = true;
// } else {
//   Serial.println("No se detectó movimiento");
//   pirDetected = false;
// }


  // // Esperar 500 milisegundos antes de volver a leer el sensor
  // delay(500);
  if (IrReceiver.decode()) {
    if (millis() - last > 100) {
      angle = 90 - angle;     // cambiamos el ángulo del servo
      myservo.write(angle);    // movemos el servo al nuevo ángulo
      ///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
      digitalWrite(ledPin, HIGH); // Enciende el buzzer
    delay(500); // Espera medio segundo
    digitalWrite(ledPin, LOW); // Apaga el led
      digitalWrite(buzzerPin, HIGH); // Enciende el buzzer
    delay(500); // Espera medio segundo
    digitalWrite(buzzerPin, LOW); // Apaga el buzzer
      Serial.print(F("Servo angle: "));
      Serial.println(angle);
#if FLASHEND >= 0x3FFF
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.printIRSendUsage(&Serial);
      Serial.println();
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        IrReceiver.printIRResultRawFormatted(&Serial, true);
      }
#else
      IrReceiver.printIRResultMinimal(&Serial);
      Serial.println();
#endif // FLASHEND
    }
    last = millis();
    IrReceiver.resume();
  }

if (millis() > lastTimeBotRan + botRequestDelay) {
int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
while(numNewMessages) {
  Serial.println("new message");
  handleNewMessages(numNewMessages);
  numNewMessages = bot.getUpdates(bot.last_message_received + 1);
}

lastTimeBotRan = millis();
 }
 
 delay(2000);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error ");
  } else {
    float temperature = event.temperature;
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error ");
  } else {
    float humidity = event.relative_humidity;
    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity);
    lcd.print("%");
  }
  
  char msg[16];
  snprintf(msg, 16, "%f,%f", temperature, humidity);

  cliente.publish(mqtt_topic, msg);


  lcd.setCursor (0, 3);//poner el cursor en las coordenadas (x,y)
  lcd.print("Tiempo activo:");//muestra en la pantalla max 20 caracteres
  //La funcion millis() regresa los ms que lleva encendido
  //Lo dividimos entre 1000 para que nos muestre en segundos.
  lcd.print(millis()/1000);
  lcd.print("s");
  // delay(1000);//Esperamos 1 segundo antes de repetir el loop
}


void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Mensaje recibido en el topic ");
  Serial.print(topic);

  String messageTemp;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println(messageTemp);

  if (String(topic) == topicServo) {
    if (messageTemp == "true") {
      Serial.println("Encendiendo Actuadores");
   ledState = LOW;
      digitalWrite(ledPin, ledState);
      myservo.write(0); //move servo to 90 degrees
      delay(500); //wait for servo to finish moving
      digitalWrite(buzzerPin, HIGH); // Enciende el buzzer
      delay(500); // Espera medio segundo
      digitalWrite(buzzerPin, LOW); // Apaga el buzzer
    } else if (messageTemp == "false") {
      Serial.println("Apagando Los Actuadortes");
     ledState = HIGH;
      digitalWrite(ledPin, ledState);
      
      myservo.write(90); //move servo to 0 degrees
      delay(500); //wait for servo to finish moving
      digitalWrite(buzzerPin, HIGH); // Enciende el buzzer
    delay(500); // Espera medio segundo
    digitalWrite(buzzerPin, LOW); // Apaga el buzzer
    }
  } else if (String(topic) == topicbuzzer) {
    if (messageTemp ="true") {
      Serial.println("Encendiendo el buzzer");
    //  tone(BUZZER_PIN, 1000); // Hacemos sonar el buzzer a una frecuencia de 1000 Hz
      // client.publish(topicServo, "true");= "true"
    } else if (messageTemp == "false") {
      Serial.println("Apagando buzzer");
   
      // client.publish(topicServo, "false");
    }
  } else {
    Serial.println("Topic desconocido");
  }
}