//SWARM BOTS UNIVERSAL REMOTE FOR TESTING 
//UPDATED TO 3.1 LIB
//FOR MORE INFO CHECK OUT SwarmBots.online

#include <Arduino.h>
#include <ButtonDebounce.h>
#include <IRremote.h>

#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif


const int ACTIVATIONPin = 2; 
const int BUMPleftPin = 3;
const int STALLPin = 4;
const int BUMPrightPin = 6;
const int NOPEleftPin = 7;
const int NOPEbackPin = 8;
const int NOPErightPin = 9;
const int ZAPPERredPin = 10;
const int ZAPPERbluePin = 16;
const int ZAPPERgreenPin = 14;
const int ZAPPERredBluePin = 15;
const int ZAPPERredGreenPin = 18;
const int ZAPPERblueGreenPin = 19;
const int IR_SEND_PIN = 5;
const int debounceDelay = 10;
int buttonState = 0;   


void setup() {   
    pinMode(ACTIVATIONPin, INPUT);
    pinMode(BUMPleftPin, INPUT);
    pinMode(STALLPin, INPUT);
    pinMode(BUMPrightPin, INPUT);
    pinMode(NOPEleftPin, INPUT);
    pinMode(NOPEbackPin, INPUT);
    pinMode(NOPErightPin, INPUT);
    pinMode(ZAPPERredPin, INPUT);
    pinMode(ZAPPERgreenPin, INPUT);
    pinMode(ZAPPERbluePin, INPUT);
    pinMode(ZAPPERredBluePin, INPUT);
    pinMode(ZAPPERredGreenPin, INPUT);
    pinMode(ZAPPERblueGreenPin, INPUT);

    
     
    Serial.begin(115200);
    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)  || defined(ARDUINO_attiny3217)
    delay(4000); // To be able to connect Serial monitor after reset or power up and before first printout
#endif
    // Just to know which program is running on my Arduino
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

    Serial.print(F("Ready to send IR signals at pin "));
    Serial.println(IR_SEND_PIN);
}
uint32_t botON = 0xFFC23D;
uint32_t botLEFT = 0xFFA25D;
uint32_t botSTALL = 0xFF629D;
uint32_t botRIGHT = 0xFFE21D;
uint32_t botNOPEleft = 0xFFE01F;
uint32_t botNOPEback = 0xFFA857;
uint32_t botNOPEright = 0xFF906F;
uint32_t botZAPPERred = 0xFF30CF;
uint32_t botZAPPERgreen = 0xFF18E7;
uint32_t botZAPPERblue = 0xFF7A85;
uint32_t botZAPPERredBlue = 0xFF10EF;
uint32_t botZAPPERredGreen = 0xFF38C7;
uint32_t botZAPPERblueGreen = 0xFF5AA5;

uint8_t nbits = 32;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

  void loop() {
   
    if (digitalRead(ACTIVATIONPin) == HIGH){
    delay(debounceDelay);
    IrSender.sendNEC(botON, sCommand, sRepeats);
    delay(600);
}
      if (digitalRead(BUMPleftPin) == HIGH){
      delay(debounceDelay);
      IrSender.sendNEC(botLEFT, sCommand, sRepeats);
      delay(600);
}
        if (digitalRead(STALLPin) == HIGH){
        delay(debounceDelay);
        IrSender.sendNEC(botSTALL, sCommand, sRepeats);
        delay(600);
}
          if (digitalRead(BUMPrightPin) == HIGH){
          delay(debounceDelay);
          IrSender.sendNEC(botRIGHT, sCommand, sRepeats);
          delay(600);
}
            if (digitalRead(NOPEleftPin) == HIGH){
            delay(debounceDelay);
            IrSender.sendNEC(botNOPEleft, sCommand, sRepeats);
            delay(600);
}
              if (digitalRead(NOPEbackPin) == HIGH){
              delay(debounceDelay);
              IrSender.sendNEC(botNOPEback, sCommand, sRepeats);
              delay(600);
}
                if (digitalRead(NOPErightPin) == HIGH){
                delay(debounceDelay);
               IrSender.sendNEC(botNOPEright, sCommand, sRepeats);
                delay(600);
}
                  if (digitalRead(ZAPPERredPin) == HIGH){
                  delay(debounceDelay);
                  IrSender.sendNEC(botZAPPERred, sCommand, sRepeats);
                  delay(600);
}
                    if (digitalRead(ZAPPERgreenPin) == HIGH){
                    delay(debounceDelay);
                    IrSender.sendNEC(botZAPPERgreen, sCommand, sRepeats);
                    delay(600);
}
                      if (digitalRead(ZAPPERbluePin) == HIGH){
                      delay(debounceDelay);
                      IrSender.sendNEC(botZAPPERblue, sCommand, sRepeats);
                      delay(600);
}
                        if (digitalRead(ZAPPERredBluePin) == HIGH){
                        delay(debounceDelay);
                       IrSender.sendNEC(botZAPPERredBlue, sCommand, sRepeats);
                        delay(600);
}
                          if (digitalRead(ZAPPERredGreenPin) == HIGH){
                          delay(debounceDelay);
                          IrSender.sendNEC(botZAPPERredGreen, sCommand, sRepeats);
                          delay(600);
}
                            if (digitalRead(ZAPPERblueGreenPin) == HIGH){
                            delay(debounceDelay);
                            IrSender.sendNEC(botZAPPERblueGreen, sCommand, sRepeats);
                            delay(600);
  }
}
