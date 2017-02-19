#include <IRremote.h>

int RECV_PIN = 11;
int RECV_PIN2 = 5;
int t1 = 10; //horario
int t2 = 6;  //anti-horario
int ledv1 = 2;
int ledv2 = 3;
int lverd1 = 4;
int lverd2 = 7;
int senha[4];
int count = 0;
float valor;
float valor2;

IRrecv irrecv(RECV_PIN);
IRrecv irrecv2(RECV_PIN2);

decode_results results;
decode_results results2;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(ledv1, OUTPUT);
  pinMode(ledv2, OUTPUT);
  pinMode(lverd1, OUTPUT);
  pinMode(lverd2, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results) || irrecv2.decode(&results2)) {
    //Serial.println(results.value, HEX);  
    valor = (results.value);
    valor2 = (results2.value);
    if (valor == 0xC9767F76 || valor2 == 0xC9767F76) {  
      putSenha(1);
      Serial.println("1");
    }  
    if (valor == 0xC8155AB1 || valor2 == 0xC8155AB1){
      putSenha(2);
      Serial.println("2");
    }
    if (valor == 0xB6996DAE || valor2 == 0xB6996DAE){
      putSenha(3);
      Serial.println("3");
    }
    if (valor == 0x969AE844 || valor2 == 0x969AE844){
      putSenha(4);
      Serial.println("4");
    }
    if (valor == 0x4AAFAC67 || valor2 == 0x4AAFAC67){
      putSenha(5);
      Serial.println("5");
    }
    if (valor == 0x9C2A936C || valor2 == 0x9C2A936C){
      putSenha(6);
      Serial.println("6");
    }
    if (valor == 0x833ED333 || valor2 == 0x833ED333){
      putSenha(7);
      Serial.println("7");
    }
    if (valor == 0x55F2B93 || valor2 == 0x55F2B93){
      putSenha(8);
      Serial.println("8");
    }
    if (valor == 0xDE78B0D0 || valor2 == 0xDE78B0D0){
      putSenha(9);
      Serial.println("9");
    }
    if (valor == 0xF32F72D7 || valor2 == 0xF32F72D7){
      putSenha(0);
      Serial.println("0");
    }
    irrecv.resume();
    count++;
  }
  
  /*
  * os delays precisam ser configurados de acordo com o circuito
  * com a senha certa ela abre, e depois de 10 segundos volta a fechar
  */
  if(count == 4){
    if(senha[0] == 3 && senha[1] == 5 && senha[2] == 7 && senha[3] == 0){
      Serial.println("Acesso liberado");
      digitalWrite(t2, HIGH);
      digitalWrite(lverd1, HIGH);
       digitalWrite(lverd2, HIGH);
      delay(2000);
      digitalWrite(lverd1, LOW);
      digitalWrite(lverd2, LOW);
      digitalWrite(t2, LOW);
      delay(10000);
      digitalWrite(t1, HIGH);
      delay(2000);
      digitalWrite(t1, LOW);
    }else{
      Serial.println("Acesso negado");
      digitalWrite(t1, HIGH);
      digitalWrite(ledv1, HIGH);
      digitalWrite(ledv2, HIGH);
      delay(2000);
      digitalWrite(t1, LOW);
      digitalWrite(ledv1, LOW);
      digitalWrite(ledv2, LOW);
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
