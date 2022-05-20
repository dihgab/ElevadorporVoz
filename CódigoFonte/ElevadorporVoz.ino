#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

#define SOLO    2 //LED 1
#define PRIMEIRO  3 //LED 2
#define SEGUNDO   4 //LED 3
#define TERCEIRO  5 //LED 4

//---------------------------------------------------------------------------------------------------------------
#define VozBotaoT   (0) //voz gravada no 0
#define VozBotao1   (1) //voz gravada no 1
#define VozBotao2   (2) //voz gravada no 2
#define VozBotao3   (3) //voz gravada no 3
//---------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------
VR myVR(10,11);    // Original: 2:RX 3:TX, you can choose your favourite pins.  Modificado: 10:RX 11:TX, you can choose your favourite pins. 
//Na hora de monta encaixe o RX->11 e TX->10

uint8_t records[7]; // save record
uint8_t buf[64];

void printSignature(uint8_t *buf, int len){
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}
//---------------------------------------------------------------------------------------------------------------

void setup(){
//---------------------------------------------------------------------------------------------------------------
  /** initialize */
  myVR.begin(9600);
  
  Serial.begin(115200);
  Serial.println("V3 sendo usado junto com o Elevador");
  
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }
  
  else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)VozBotaoT) >= 0){
    Serial.println("BotaoT pressionado");
  }
  
  if(myVR.load((uint8_t)VozBotao1) >= 0){
    Serial.println("Botao1 pressionado");
  }

  if(myVR.load((uint8_t)VozBotao2) >= 0){
    Serial.println("Botao2 pressionado");
  }

  if(myVR.load((uint8_t)VozBotao3) >= 0){
    Serial.println("Botao3 pressionado");
  }

   pinMode(SOLO, OUTPUT);
   pinMode(PRIMEIRO, OUTPUT);
   pinMode(SEGUNDO, OUTPUT);
   pinMode(TERCEIRO, OUTPUT);
   
}

   
//---------------------------------------------------------------------------------------------------------------

void loop() {

  digitalWrite(SOLO, LOW);
  digitalWrite(PRIMEIRO, LOW);
  digitalWrite(SEGUNDO, LOW);
  digitalWrite(TERCEIRO, LOW);

  
 
//---------------------------------------------------------------------------------------------------------------
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){ 
      case VozBotaoT: // andar 0 
          digitalWrite(SOLO, HIGH);
          break;
          
      case VozBotao1: // andar 1
          digitalWrite(PRIMEIRO, HIGH);
          break;

      case VozBotao2: // andar 2
          digitalWrite(SEGUNDO, HIGH);
          break;
          
      case VozBotao3: // andar 3
          digitalWrite(TERCEIRO, HIGH);
          break;

      default:
        Serial.println("Comando nao reconhecido");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }

}
//---------------------------------------------------------------------------------------------------------------
