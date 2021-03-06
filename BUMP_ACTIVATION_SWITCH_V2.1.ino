// BUMP CODE TESTING 
// MOVED BUTTON INPUTS
// MULTIPLE IF STATEMENTS WORKING

#include <ButtonDebounce.h>
#include <IRremote.h>
IRsend IrSender;

#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

const int LED_0 = 9;
const int LED_1 = 8;
const int LED_2 = 7;
//const int LED_3 = 6;
//const int LED_4 = 4;
//const int LED_5 = 3;
const int LED_6 = 15;
const int LED_7 = 14;
const int LED_8 = 16;
const int LED_9 = 10;

const int buttonRIGHT = 3;
const int buttonLEFT = 4;
const int buttonSTALL = 6;
const int ACTIVATIONPin = 2; 
int buttonState = 0;   


void setup() {
    pinMode(LED_0, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
//    pinMode(LED_3, OUTPUT);
//    pinMode(LED_4, OUTPUT);
//    pinMode(LED_5, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(LED_8, OUTPUT);
    pinMode(LED_9, OUTPUT);
    
    pinMode(buttonRIGHT, INPUT);
    pinMode(buttonLEFT, INPUT);
    pinMode(buttonSTALL, INPUT);
    pinMode(ACTIVATIONPin, INPUT);
    
    
     
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)
    delay(2000);
#endif
    Serial.println(F("START " __FILE__ " from " __DATE__));
    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}
uint32_t botON = 0xFFC23D; // BOTS ON
uint32_t botRIGHT = 0xFFE21D; // BOT BUMP RIGHT
uint32_t botLEFT = 0xFFA25D; // BOT BUMP LEFT
uint32_t botSTALL = 0xFF629D; // BOT SWITCHES TO REVERSE 
uint8_t nbits = 32;
uint8_t sRepeats = 0;

void loop() 
{
if (digitalRead(ACTIVATIONPin) == HIGH)
{
delay(50);
IrSender.sendNEC(botON, nbits);
delay(200);
}
if (digitalRead(buttonRIGHT) == HIGH)
{
delay(50);
IrSender.sendNEC(botRIGHT, nbits);
delay(200);
}
if (digitalRead(buttonLEFT) == HIGH)
{
delay(50);
IrSender.sendNEC(botLEFT, nbits);
delay(200);
}
if (digitalRead(buttonSTALL) == HIGH)
{
delay(50);
IrSender.sendNEC(botSTALL, nbits);
delay(200);
}
}
