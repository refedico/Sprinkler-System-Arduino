//pin Arduino I/O
const int sensorpin = 11;  
const int ledpin = 7;        
const int buzzerpin = 3;
const int fumopin = 5;

//Variabili
int statofiamma = 0;     
int statofumo = 0;
double temperatura{};
double val{};
//Stato
int stato = 1;

void setup()
{
  pinMode(sensorpin,INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(fumopin, INPUT);
  Serial.begin(9600);  
}

void loop()
{
    state_loop(stato);
}

void state_loop(int& state) //Stato parametrizzato
{   
   Serial.println("Stato fumo:");
   Serial.println (statofumo);
   Serial.println("Stato fiamma:");
   Serial.println (statofiamma);
   
   statofumo = digitalRead(fumopin);
   statofiamma = digitalRead(sensorpin);
   temperatura = ((analogRead(A2) * (5.0/1024))-0.5)/0.01;
  
   if (state == 1){
   digitalWrite(ledpin,LOW);
   }
  
   if (state == 2){
   digitalWrite(ledpin,HIGH);
   }
  
   if (state == 3){
   digitalWrite(ledpin,HIGH);
   inter_buzz();
   }
  
   if (state == 4{
   digitalWrite(ledpin,HIGH);
   cont_buzz();
   }
   
   state = statofiamma?4:statofumo?3:temperatura>3000?2:1;
}
       
void inter_buzz()
{
   tone(buzzerpin,400,200);
   delay (300); 
   tone(buzzerpin,400,200); 
}
       
void cont_buzz()
{
   tone(buzzerpin,400,5000); 
}
