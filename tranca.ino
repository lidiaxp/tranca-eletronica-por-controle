#include <IRremote.h>

int RECV_PIN = 11;
int senha[4];
int count = 0;
float valor;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);  
    valor = (results.value);
    if (valor == 0xC9767F76) {  
      putSenha(1);
      Serial.println("1");
    }  
    if (valor == 0xC8155AB1){
      putSenha(2);
      Serial.println("2");
    }
    if (valor == 0xB6996DAE){
      putSenha(3);
      Serial.println("3");
    }
    if (valor == 0x969AE844){
      putSenha(4);
      Serial.println("4");
    }
    if (valor == 0x4AAFAC67){
      putSenha(5);
      Serial.println("5");
    }
    if (valor == 0x9C2A936C){
      putSenha(6);
      Serial.println("6");
    }
    if (valor == 0x833ED333){
      putSenha(7);
      Serial.println("7");
    }
    if (valor == 0x55F2B93){
      putSenha(8);
      Serial.println("8");
    }
    if (valor == 0xDE78B0D0){
      putSenha(9);
      Serial.println("9");
    }
    if (valor == 0xF32F72D7){
      putSenha(0);
      Serial.println("0");
    }
    irrecv.resume();
    count++;
  }
  if(count == 4){
    if(senha[0] == 3 && senha[1] == 5 && senha[2] == 7 && senha[3] == 0){
      Serial.println("Acesso liberado");
    }else{
      Serial.println("Acesso negado");
    }
    count = 0;
  }    
}

void putSenha(int n){
  if(count == 0){
        senha[count] = n;
      }
      if(count == 1){
        senha[count] = n;
      }
      if(count == 2){
        senha[count] = n;
      }
      if(count == 3){
        senha[count] = n;
      }
     delay(500); 
}
