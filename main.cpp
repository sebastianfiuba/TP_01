//=====[Libraries]=============================================================
#include "mbed.h"
#include "arm_book_lib.h"


//=====[Defines]===============================================================

#define OPEN_TIME  10000//in ms
#define BASE_TEMP  10   //in Celsius
#define MIN_TEMP   10   //in Celsius
#define MAX_TEMP   40   //in Celsius

//=====[Declaration and initialization of public global objects]===============


    AnalogIn limitPot(A0);
    AnalogIn lm35Sensor(A1);

    DigitalIn closeButton(D2);
    DigitalIn openButton(D3);

    DigitalOut closedLed(LED1);
    DigitalOut openedLed(LED2);

    UnbufferedSerial uartUsb(USBTX, USBRX, 9600);



//=====[Declaration and initialization of public global variables]=============

    bool  doorState     = OFF; // off: closed, on: open
    bool  doorState_ant = OFF;

    bool  limitState    = ON;  // on: on the limits, off: off the limits

    float potReading    = 0.0; 

    float limitTemp     = 0.0; // sensDistance with hc-s04 

    float limitTemp_ant = 0.0;

    float actualTemp    = 0.0;
    int   intTemp       = 0;



//=====[Declarations (prototypes) of public functions]========================= 

    void inputsInit();
    void outputsInit();
    void uartTask();
    void openDoor();
    void closeDoor();
    void getTemp();
    void getLimit();
    void checkLimit();
    void doorUpdate();
    void sendData();



//=====[Main function, the program entry point after power on or reset]========


int main(){

    inputsInit();
    outputsInit();
    getLimit();
    uartTask();

    while (true){

        getTemp();
        getLimit();
        checkLimit();
        doorUpdate();
        sendData();
    }
}


//=====[Implementations of public functions]===================================

void sendData{

    if(doorState != doorState_ant){
        uartTask();
    }
    if((int)limitTemp_ant != (int)limitTemp){
        uartTask();
    }

}

void checkLimit(){

    if( MIN_TEMP >= actualTemp <= MAX_TEMP){

        limitState = ON;

    }
    else{

        limitState = OFF;
    }
    

}
void doorUpdate(){

    doorState_ant = doorState;

    if(openButton || !limitState){
        openDoor();
    }
    else{
        if(closeButton || limitState){
            closeDoor();
        }
    }
}

void inputsInit(){

    closeButton.mode(PullDown);
    openButton.mode(PullDown);
}

void outputsInit(){

    closedLed = ON;
    openedLed = OFF;

}

void getLimit(){

    limitTemp_ant = limitTemp;
    potReading    = limitPot.read();
    limitTemp     = potReading * (MAX_TEMP - BASE_TEMP) + BASE_TEMP;

}

void getTemp(){

    actualTemp = lm35Sensor.read();
    actualTemp = actualTemp * 3.3 / 0.01;

}

void openDoor(){
    
    doorState = ON;

    closedLed = !doorState;
    openedLed = doorState;

    delay(OPEN_TIME);


}

void closeDoor(){
    
    doorState = OFF;

    closedLed = !doorState;
    openedLed = doorState;

}

void uartTask(){

    char str[100];
    int stringLength;

    sprintf ( str, "Temperature limit: %.2f\r\n", limitTemp );
    stringLength = strlen(str);
    uartUsb.write( str, stringLength );

    if(doorState){
        uartUsb.write("The door is open\r\n", 18);
    }
    else {
        uartUsb.write("The door is closed\r\n", 20);
    }


}
