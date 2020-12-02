//pin Arduino I/O
const int sensorpin = 11;  
const int ledpin = 7;        
const int buzzerpin = 3;
const int fumopin = 5;

//Variabili
int statofiamma = 0;     
int statofumo = 0;
double temperatura;
double val;
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
  switch(stato){
    case 1:
      loop1();
    break;

    case 2:
      loop2();
    break;

    case 3:
      loop3();
    break;

    case 4:
      loop4();
    break;
  }
}

void loop1() //Stato 1 Tutto Spento
{   
   Serial.println("Stato fumo:");
   Serial.println (statofumo);
   Serial.println("Stato fiamma:");
   Serial.println (statofiamma);
   
   statofumo = digitalRead(fumopin);
   statofiamma = digitalRead(sensorpin);
   temperatura = ((analogRead(A2) * (5.0/1024))-0.5)/0.01;
   digitalWrite(ledpin,LOW);

   if(statofiamma)
   {
    stato = 4;
   }
   else if (statofumo)
   {
    stato = 3;
   }
   else if (temperatura > 30)
   {
    stato = 2;
   }
   else
   {
    stato = 1;
   }
}
void loop2() //Stato 2 Led Acceso
{   
   Serial.println("Stato fumo:");
   Serial.println (statofumo);
   Serial.println("Stato fiamma:");
   Serial.println (statofiamma);
   
   statofumo = digitalRead(fumopin);
   statofiamma = digitalRead(sensorpin);
   temperatura = ((analogRead(A2) * (5.0/1024))-0.5)/0.01;
   digitalWrite(ledpin,HIGH);

   if(statofiamma)
   {
    stato = 4;
   }
   else if (statofumo)
   {
    stato = 3;
   }
   else if (temperatura > 3000)
   {
    stato = 2;
   }
   else
   {
    stato = 1;
   }
}
void loop3() //Stato 3 Buzzer Intermittenza
{   
   Serial.println("Stato fumo:");
   Serial.println (statofumo);
   Serial.println("Stato fiamma:");
   Serial.println (statofiamma);
   
   statofumo = digitalRead(fumopin);
   statofiamma = digitalRead(sensorpin);
   temperatura = ((analogRead(A2) * (5.0/1024))-0.5)/0.01;
   digitalWrite(ledpin,HIGH);
   inter_buzz();

   if(statofiamma)
   {
    stato = 4;
   }
   else if (statofumo)
   {
    stato = 3;
   }
   else if (temperatura > 3000)
   {
    stato = 2;
   }
   else
   {
    stato = 1;
   }
}
void loop4() //Stato 4 Buzzer Continuo
{   
   Serial.println("Stato fumo:");
   Serial.println (statofumo);
   Serial.println("Stato fiamma:");
   Serial.println (statofiamma);
   
   statofumo = digitalRead(fumopin);
   statofiamma = digitalRead(sensorpin);
   temperatura = ((analogRead(A2) * (5.0/1024))-0.5)/0.01;
   digitalWrite(ledpin,HIGH);
   cont_buzz();

   if(statofiamma)
   {
    stato = 4;
   }
   else if (statofumo)
   {
    stato = 3;
   }
   else if (temperatura > 3000)
   {
    stato = 2;
   }
   else
   {
    stato = 1;
   }
}

void inter_buzz()
{
   tone(buzzerpin,400,200);
   delay (300); 
   tone(buzzerpin,400,200); 
}
void cont_buzz()
{
   tone(buzzerpin,400,10000); 
}
