# TP_01
Título: Cerradura controlada por temperatura

Alumno: Sebastián Andrada

Objetivo: Desarrollar un sistema que abra una cerradura cuando se llega a la temperatura deseada o se pase de limtes inferiores o superiores de temperatura fijos.

Descripción: 

El sistema debe abrir una cerradura por 10 segundos cuando detecte que la temperatura pasa cierto umbral definido por el usuario o baja de una temperatura fija minima, para ello se define un tiempo de apertura fijo con un #define y se define con otro #define la temeperatura minima. Se usan grados Celsius.

Para saber si la temperatura usada se usa el sensor lm35 que se puede encontrar aca:
https://articulo.mercadolibre.com.ar/MLA-930151306-sensor-analogico-temperatura-lm35dz-lm35-55c-a-150c-_JM#polycard_client=search-nordic&position=9&search_layout=stack&type=item&tracking_id=ebca7547-7db6-4114-ad18-bfeb51baf674&wid=MLA930151306&sid=search

Si el usuario quiere cambiar el umbral del sistema se utiliza un potenciómetro.

Si el usuario pulsa un botón se abre la cerradura y se pulsa otro se cierra independientemente del estado del programa, esto se utilizaría como sistema de respaldo o de seguridad.

Cuando la cerradura está cerrada se prende un LED y cuando está abierta se prende otro.

La cerradura se controlaria con un servo motor como el siguiente:
https://www.mercadolibre.com.ar/mini-servo-tower-pro-sg90-9g-robotica-arduino-servomotor/p/MLA46735454#polycard_client=search-nordic&searchVariation=MLA46735454&wid=MLA2029850566&position=2&search_layout=stack&type=product&tracking_idws=6c7b7a13-4f65-46b4-a9e5-7da6822a7150&sid=search 
pero en esta etapa se utilizarn los LEDs testigo como fin del programa


Cada vez que haya un cambio se envía a través del puerto serie:
- Limite de temperatura superior
- Posicion del servo (Cerrado o abierto)

Plataforma de desarrollo: NUCLEO-F429ZI

Periféricos a utilizar:

DIGITAL IN 1: Controla el que la cerradura este abierta por 10 segundos

DIGITAL IN 2: Controla que la cerradura este cerrada

LED 1: Se enciende si la cerradura está cerrada

LED 2: Se enciende si la cerradura está apagada si

ANALOG IN 1: Se utiliza para leer el umbral de temperatura 

ANALOG IN 2: Se utiliza paea leer la temperatura del sensor

UART: Se utiliza para enviar información de estado del sistema


Diagrama en bloques del sistema:
![Copy of Blank diagram](https://github.com/user-attachments/assets/550db6d4-328b-4cfd-a40f-02f729abae89)

Diagrama en bloques del programa:



