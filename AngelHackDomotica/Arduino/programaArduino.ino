/* sdds
Letra A = prener luz1
Letra B = prender luz2
Letra C = prender luz3
Letra D = prender Luz4

letra a = apagar luz1
Letra b = apagar luz2
Letra c = pagar Luz3
Letra d = apagar luz4


si recibe letra A = luz1 prendido a es apagada
si recibe letra B = luz2 prendida b es apagada
si recibe letra C = luz3  prendida c es apagada
Si recibe letra D = luz4 prendida d es apagada
*/



int option;
int led = 13;
int datoLeido = 0;

int status_Luz1 = 0;
int status_Luz2 = 0;
int status_Luz3 = 0;
int status_Luz4 = 0;
int status_Luz220 = 0;
int statusprueba = 0;

void setup(){
  Serial.begin(9600);
  
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(10,OUTPUT); 
  pinMode(8,OUTPUT);
 

  pinMode(9,OUTPUT); 
  pinMode(A0,INPUT);
}
 
void loop(){
  //si existe información pendiente
  if (Serial.available()>0){
    //leeemos la opcion
    datoLeido = Serial.read();
    
    if (datoLeido=='A') {
      digitalWrite(13,HIGH);
      int status_Luz4 = 0;
    }
     if (datoLeido=='B') {
      digitalWrite(12,HIGH);
      int status_Luz3 = 1;
    }
     if (datoLeido=='C') {
      digitalWrite(11,HIGH);
      int status_Luz2 = 1;
    }
     if (datoLeido=='D') {
      digitalWrite(10,HIGH);
      int status_Luz1 = 1;
    }
     if (datoLeido=='E') {
      digitalWrite(9,HIGH);
      int status_Luz220 = 1;   
    }

        if (datoLeido=='a') {
      digitalWrite(13,LOW);
      int status_Luz4 = 0;
    }
     if (datoLeido=='b') {
      digitalWrite(12,LOW);
      int status_Luz3 = 0;
    }
     if (datoLeido=='c') {
      digitalWrite(11,LOW);
      int status_Luz2 = 0;
    }
     if (datoLeido=='d') {
      digitalWrite(10,LOW);
      int status_Luz1 = 0;
    }
     if (datoLeido=='e') {
      digitalWrite(9,LOW);
      int status_Luz220 = 0;   
    }
    if(datoLeido=='P') {
       digitalWrite(8,HIGH);
       int statusprueba = 0;
      } 
    if(datoLeido=='p'){
        digitalWrite(8,LOW);
      }
    if (datoLeido=='v') {
      int analogValue = analogRead(0);
      int milliVolts = map(analogValue, 0, 1023, 0, 5000);
      Serial.println(milliVolts);
    }
 
    /**
    char option = Serial.read();
    //si la opcion esta entre '1' y '9'
    if (option >= '1' && option <= '9')
    {
      //restamos el valor '0' para obtener el numeroenviado
      option -= '0';
      for(int i=0;i<option;i++){
         digitalWrite(led, HIGH);
         delay(100);
         digitalWrite(led, LOW);
         delay(200);
      }
    }
    */
  }
}
