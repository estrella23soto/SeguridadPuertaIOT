# SeguridadPuertaIOT
## Integrantes 
1. Cesar Alejandro Ordoñez Osorio
3. Angel Gerardo Velazquez Salazar 
3. Cruz Estrella Juarez Soto
## Objetivo General
El objetivo de este proyecto es proponer una solución a un cierto grupo de personas que buscan seguridad, privacidad y resguardo de su información hoy en día la información vale más que el dinero este proyecto de internet de la cosas tiene como objetivo especifico salva guardar los más preciado de una habitación la intimidad haciendo esto posible con algo que jamás dejas que es tu celular además este prototipo tendrá las funcione de sentir la presencia y dar alarmas con luz y sonido, así como mandar el estatus a tu teléfono celular, y en simultaneo a un pantalla lcd y como plus también pasar el clima.


## Objetivos especificos(por completar) 
1. Diseñar prototipo 
2. Codificar la aplicación 
3. Ensanlaje de piezas 
4. Probrar prototipo
5. Liberar prototipo 

## Tabla de Software utilizado
|id | Sofware  | Version  |Tipo   
|---|---|---|---|
| 1 |Visual Studio Code   | 1.71.2  |Freeware   |  
| 2 | Arduino IDE  |2   |   2|   Freeware
| 3 | Libreria para sensor proximidad  |  x  | x  |  
| 4| Mosquitto  |   5.0, 3.1.1  | Freeware  | 
| 5| NODE-RED  |  3.0 | Freeware  |  
| 6| Motor de base de datos  |  x  | Freeware | 
| 7 | LIbreria para el buzzer |    | Freeware |
| 8 | Libreria de wifi esp32 |  se actulizara en el momento de la codificacion para obtener la ultima version ocupada(x)   | Freeware  |
| 9 | Libreria Bluetooth esp32 | x   | Freeware |
| 10 | Libreria para el sensor de temperatura | x   | Freeware |
| 10 | Libreria para el sensor de lcd | x   | Freeware |


## Tabla con el hardware utilizado

| Id  |Componente   | Descripción | Imagen | Cantidad |Costo Total |
|---- |------------ |------------ |------- | -------- | ---------  |
| 1   |   Esp32 @ 240 Mhz, Con Wifi, Bluetooth Y Ble    |   La placa ESP32 está basada en el modulo ESP32-WROOM-32 que trae integrado Wi-Fi, Bluetooth y BLE (Bluetooth Low Energy). El modulo ESP32-WROOM-32 ha sido diseñado para una gran variedad de aplicaciones que van desde redes de sensores de bajo consumo hasta las tareas más exigentes, como codificación de voz, transmisión de música y decodificación de MP3.| ![image](https://user-images.githubusercontent.com/106614070/214468798-4a2ca8ec-510a-43d5-82c8-5b31b9dbc32a.png)| 1 |    $179|
| 2   | Raspberry Pi 4 B 4gb         |    Ésta nueva versión incluye 4GB de memoria RAM DDR4 y permite conectar dos monitores 4K a la vez a través de dos puertos micro HDMI. Además de dos puertos USB 2.0, la Raspberry Pi 4 también tiene dos puertos USB 3.0 que hacen que las transferencias de datos sean mucho más rápidas a través de USB.|<img  src= "https://user-images.githubusercontent.com/106614070/214469274-f2f560df-0885-4fcd-95ee-3a434b0d50a4.png" width="200" height="200" />|1|$2,767|
| 3   |   Sensor De Movimiento Pir Hc-sr505 Mini Presencia Deteccion          |  Este pequeño modulo PIR HC-SR505, es usado para la detección de movimiento cuenta con una excelente sensibilidad, fiabilidad y estabilidad, puede ser ampliamente utilizado en muchos tipos de equipos eléctricos de inducción automática.|<img  src= "https://user-images.githubusercontent.com/106614070/214469755-bf5b4626-8ed1-402e-b3a0-162a04ec8f0d.png" width="200" height="200" />|1| $54|
| 4   |     Buzer Activo         |    También conocido como zumbador es un pequeño transductor capaz de convertir la energía eléctrica en sonido. Para hacerlos funcionar solo basta conectar el positivo con el + y la tierra o negativo con el – de una batería o cualquier fuente de|<img  src= "https://user-images.githubusercontent.com/106614070/214469963-c4d8d5b9-03d3-48ae-ba49-d985c0ca5646.png" width="200" height="200" />| 1| $0 |
|   5| Sensor De Temperatura Y Humedad Dht11 C | El DHT11 es un sensor digital de temperatura y humedad relativa de bajo costo y fácil uso. Integra un sensor capacitivo de humedad y un termistor para medir el aire circundante, y muestra los datos mediante una señal digital en el pin de datos (no posee salida analógica) | <img  src= "https://http2.mlstatic.com/D_NQ_NP_2X_638466-MLM29979046786_042019-F.webp" width="200" height="200" />  |  1 | $67  |
|   6| 100 Leds Difusos 5mm Rojo, Ambar, Azul, Verde, Blanco  | Un diodo LED es un dispositivo que permite el paso de corriente en un solo sentido y que al ser polarizado emite un haz de luz. Trabaja como un diodo normal pero al recibir corriente eléctrica emite luz. Los LED trabajan aproximadamente con corriente de 2V|!<img  src= "https://user-images.githubusercontent.com/106614070/193472526-db15e319-4390-4c06-8c58-0bf9736962b8.png" width="200" height="200" />| 1| $59 | 
|   8|  Protoboard 830 Puntos Mb-102 | El Protoboard 830 pts MB-102 es una tablilla de pruebas, que cuenta con 830 perforaciones divididas en filas horizontales y columnas verticales para realizar conexiones eléctricas, puedes conectar cualquier elemento electrónico para realizar prototipos, prácticas y simulaciones de circuitos electrónicos  | <img  src= "https://user-images.githubusercontent.com/106614070/193472640-0e12c7f3-c74e-4f16-9562-9829b3982a2d.png" width="200" height="200" />|1|$52 |
|   8| Cables Jumpers Dupont H-h, M-m, H-m 20cm 120 Pzas|  Un cable puente para prototipos (o simplemente puente para prototipos), es un cable con un conector en cada punta (o a veces sin ellos), que se usa normalmente para interconectar entre sí los componentes en una placa de pruebas. | <img  src= "https://user-images.githubusercontent.com/106614070/193472720-f2f6cb77-627d-4a3d-acd6-4f6ec8571d7f.png" width="200" height="200" />|1  |$103|
|  9 | Motor A Pasos 28byj-48 Con Driver Unl2003 Arduino, Pic| Dentro de los servos económicos el MG 995 Tower Pro destaca por su gran torque, engranajes metálicos y gran robustez. Funciona con la mayoría de tarjetas electrónicas con microcontroladores y además con la mayoría de los sistemas de radio control comerciales. Es utilizado principalmente en proyectos de robótica y modelismo de mediano tamaño | <img  src= "https://http2.mlstatic.com/D_NQ_NP_2X_646120-MLM43516676181_092020-F.webp" width="200" height="200" /> |1 |$117.80 |
| 10 | Display Lcd 16x2, 1602a Para Arduino, Con Pines Soladados| Este display tiene un tamaño de 16×2 que hace referencia a que la pantalla cuenta con 2 filas y cada fila tiene la capacidad de mostrar 16 caracteres o símbolos, por lo general alfanuméricos, los cuales se pueden definir desde programación utilizando un microcontrolador o tarjeta de desarrollo.|  <img  src= "https://user-images.githubusercontent.com/106614070/214472674-cea987e2-3abc-48dc-8021-204001db7697.png" width="200" height="200" />|1 |$115|
| 11 | Baquelita 20x30 Cm 1 Cara Placa Fenolica Cobre Pcb| Una Placa Fenólica PCB o Baquelita es una lámina de cobre recubierta por un sustrato aislante. Las placas fenólicas pueden ser perforadas o o planas.También pueden ser usadas en el proceso de fabricación de circuitos impresos. En esta categoría podrás encontrar distintos tipos y categorías de baquelitas, placa fenólicas o PCB.|  <img  src= "https://user-images.githubusercontent.com/106614070/215226423-5f93fdbb-4ffc-42c2-8c63-0627cf4bca79.png" width="200" height="200" />|1 |$99|
| 12 | Modulo Ky-022 Sensor Receptor Infrarrojo | El KY-022 Sensor Receptor Infrarrojo IR es un módulo sensor de detección de infrarrojos utilizado para detectar la presencia de objetos cercanos que emiten luz infrarroja. El sensor consiste en un diodo emisor de infrarrojos y un fototransistor que detecta la luz emitida por el diodo.|  <img  src= "https://http2.mlstatic.com/D_NQ_NP_2X_784241-MLM44269656298_122020-F.webp" width="200" height="200" />|1 |$59|




## Epicas del proyecto (Minimo debe de haber una épica por integrante de equipo)
- Quiero poder abrir la puerta desde cualquier lugar del mundo donde me encuentre  
- Como usuario quiero poder visualializar el estatus de mi seguridad desde el celular 
- Como usuario quiero poder ver el clima en una pantalla lcd y como el clima 


## Tabla de historias de usuario
| Id  | Historia de usuario  |Prioridad |Estimación|Como probarlo | Responsable |
|---|---|---|---|---|---|
| 1  |Quiero poder abrir la puerta desde cualquier lugar del mundo donde me encuentre| Alta  | 3 semanas | Con conexion mqqt y un celular | Cesar Alegandro Ordoñez Osorio |
|  2| Como usuario quiero poder ver el clima en una pantalla lcd y como el clima   | Media  | 2 semanas | Probando mando los valores que mandan los se nsores ala pantalla | Cruz Estrella Juárez Soto |
|  3 | Yo como usuario quiero poder visualizar el estatus de la puerta desde mi celular en una aplicación web responsiva   | Media  | 3 semanas | Probando mando los valores que mandan los sensores ala aplicacion web | Cruz Estrella Juárez Soto |
|  4 | Yo como usuario quiero poder escuchar una alerta de luz y sonido cuando una puerta en especifico se abierta o cerrada  | Alta  | 2 semanas    | Con las aplicacion web resposiva probando que el seguro abre y cierra correctamete  | Angel Gerardo Velazquez Salazar |
|  5 | Yo como usuario quiero poder visualizar el estatus de mi seguro inteligente en una pantalla lcd además de visualizar el clima del momento en el que me encuentro de salida de una habitación en especifico  | media  | 2 semanas    | Captando los valores que viene de los sensores y pasandolos ala pantalla  | Angel Gerardo Velazquez Salazar |
| 1  |Como usuario de la cerradura inteligente quiero poder  asegurar la puerta cada 5 minutos de no haber detectado presencia humana| Alta  | 3 semanas | Reciviendo los valores deuna sensor mandar indicaciones al motor y activar la seguridad | Cesar Alegandro Ordoñez Osorio |


## Prototipo en dibujo
![image](https://user-images.githubusercontent.com/106614070/215230514-35a28abd-c354-423b-8a5c-ee398c13c89a.png)
## Prototipo Terminado
![image](https://user-images.githubusercontent.com/106614070/233870853-0b588b15-18d0-48d0-9bba-20d92202bc13.png)
![image](https://user-images.githubusercontent.com/106614070/234384622-7ba1c738-f47a-49bf-977b-b09dc500d2d5.png)
![image](https://user-images.githubusercontent.com/106614070/234384656-e5f66f39-0a27-43ff-b860-10200155e36a.png)

## Diagrama de Conexion
![image](https://user-images.githubusercontent.com/106614070/234058592-eb3bd900-5076-40a1-84c1-fd3bd3e72eea.png)
## Link del Tiktok
https://vm.tiktok.com/ZMY3N2oFs/

## Dasboard
![image](https://user-images.githubusercontent.com/106614070/234384083-d5dfaa07-6655-48f1-adf8-aaae18794250.png)









