#include <IRremote.h>
#include <SoftwareSerial.h>
#include <Wire.h>

IRsend irsend;
int bluetoothTx = 6;
int bluetoothRx = 7;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup() {
  Serial.begin(9600);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(115200);
  bluetooth.print("$$$");
  delay(100);
  bluetooth.println("U,9600,N");
  bluetooth.begin(9600);
}
 
void loop() {
  if(bluetooth.available())
  {
    char toSend = (char)bluetooth.read();
    
    if(toSend == 'S'){
      SBT();
    }
    
    if(toSend == 'C'){
      CN();
    }
    
    if(toSend == 'G'){
      GLOBO();
    }
    
    if(toSend == 'N'){
      NICK();
    }

    if(toSend == 'Y'){
      DISNEY();
    }

    if(toSend == 'I'){
      DISCOVERY();
    }

    if(toSend == 'T'){
      DISCTURBO();
    }

    if(toSend == 'E'){
      DISCSCIENCE();
    }
    
    if(toSend == 'L'){
      LigarDesligarTudo();
    }
    
    Serial.println(toSend);
  }
}

void DISCSCIENCE(){
  Oito();
  Cinco();
  OK();
}

void DISCTURBO(){
  Oito();
  Quatro();
  OK();
}

void DISCOVERY(){
  Oito();
  Um();
  OK();
}

void DISNEY(){
  Um();
  Zero();
  Dois();
}

void NICK(){
  Um();
  Zero();
  Dois();
}

void SBT(){
  Um();
  Sete();
  OK();
}

void GLOBO(){
  Um();
  Oito();
  OK();
}

void CN(){
  Um();
  Zero();
  Quatro();
}

void Zero(){
  irsend.sendNEC(0xE17A00FF, 32);
  delay(50);
}

void Um(){
  irsend.sendNEC(0xE17A807F, 32);
  delay(50);
}

void Dois(){
  irsend.sendNEC(0xE17A40BF, 32);
  delay(50);
}

void Tres(){
  irsend.sendNEC(0xE17AC03F, 32);
  delay(50);
}

void Quatro(){
  irsend.sendNEC(0xE17A20DF, 32);
  delay(50);
}

void Cinco(){
  irsend.sendNEC(0xE17AA05F, 32);
  delay(50);
}

void Seis(){
  irsend.sendNEC(0xE17A609F, 32);
  delay(50);
}

void Sete(){
  irsend.sendNEC(0xE17AE01F, 32);
  delay(50);
}

void Oito(){
  irsend.sendNEC(0xE17A10EF, 32);
  delay(50);
}

void Nove(){
  irsend.sendNEC(0xE17A906F, 32);
  delay(50);
}

void OK(){
  irsend.sendNEC(0xE17AA857, 32);
  delay(50);
}

void LigarDesligarTudo(){
  irsend.sendNEC(0xE17A48B7, 32);
  delay(50);  
  irsend.sendNEC(0x34347887, 32);
  delay(50);  
  irsend.sendNEC(0x1818D02F, 32);
  delay(50);
}

