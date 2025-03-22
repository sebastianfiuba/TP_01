# TP_01
Título: Cerradura controlada a distancia

Alumno: Sebastián Andrada

Objetivo: Desarrollar un sistema que abra una cerradura sin tocarla.

Descripción: 

El sistema debe abrir una cerradura por 10 segundos cuando detecte que el usuario quiere hacerlo y esto debe pasar sin que la toque, para ello se define un tiempo de apertura fijo con un #define.

Para saber si el usuario quiere abrir la cerradura sin tocar nada se usa un sensor de proximidad como este:
https://articulo.mercadolibre.com.ar/MLA-665553469-hc-sr04-sensor-de-distancia-ultrasonico-para-desarrollo-_JM#polycard_client=search-nordic&position=17&search_layout=stack&type=item&tracking_id=b46a8c36-a5c8-448c-b6b0-85c1bf5a2924

Si el usuario quiere cambiar la sensibilidad del mismo se utiliza un potenciómetro.

Si el usuario pulsa un botón se abre la cerradura y se pulsa otro se cierra independientemente del estado del programa, esto se utilizaría como sistema de respaldo o de seguridad.

La cerradura se controla con un servo motor como el siguiente:
https://www.mercadolibre.com.ar/mini-servo-tower-pro-sg90-9g-robotica-arduino-servomotor/p/MLA46735454#polycard_client=search-nordic&searchVariation=MLA46735454&wid=MLA2029850566&position=2&search_layout=stack&type=product&tracking_idws=6c7b7a13-4f65-46b4-a9e5-7da6822a7150&sid=search

Cuando la cerradura está cerrada se prende un LED y cuando está abierta se prende otro.

Cada vez que haya un cambio se envía a través del puerto serie:
- Sensibilidad del sensor
- Posicion del servo (Cerrado o abierto)

Plataforma de desarrollo: NUCLEO-F429ZI

Periféricos a utilizar:

DIGITAL IN 1: Controla el que la cerradura este abierta por 10 segundos

DIGITAL IN 2: Controla que la cerradura este cerrada

LED 1: Se enciende si la cerradura está cerrada

LED 2: Se enciende si la cerradura está apagada si

ANALOG IN 1: Se utiliza para leer la sensibilidad del sensor 

DIGITAL OUT 1: Controla al sensor

DIGITAL IN 3: Controla al sensor

UART: Se utiliza para enviar información de estado del sistema

PWM: Se utiliza para controlar el servomotor

Diagrama en bloques:
![Copy of Blank diagram](https://github.com/user-attachments/assets/550db6d4-328b-4cfd-a40f-02f729abae89)

