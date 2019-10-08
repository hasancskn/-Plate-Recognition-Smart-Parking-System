const int buton=10 ;

char serialData;
#include <LiquidCrystal.h>
#include <Servo.h>

int trigPin = 7; 
int echoPin = 6; 

long sure;
long uzaklik;


int yer,sayac=0;

Servo myservo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  myservo.write(0);

  pinMode(10,INPUT) ;
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin,INPUT); 


lcd.begin(16, 2);
lcd.print("Hosgeldiniz!");
lcd.setCursor(0, 1);
lcd.print("Otopark :)");

  
}

void loop() {


  if(digitalRead(buton)==HIGH) //Eğer buton basılırsa yani HIGH olursa
  {
    Serial.println("butona basıldı") ;

    sayac--;
    
    while(1)
    {
      if(digitalRead(buton)==LOW)
      break ;
    }

        yer=5-sayac; 
        
        lcd.begin(16, 2);
        lcd.print("Mevcut: ");
        lcd.print(sayac);
        lcd.setCursor(0, 1);
        lcd.print("Kalan: ");
        lcd.print(yer);

    
  }


  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);   
  sure = pulseIn(echoPin, HIGH); 
  uzaklik= sure /29.1/2;             
  if(uzaklik > 200)
    uzaklik = 200;
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik); 
  Serial.println(" CM ");  
  delay(100); 

  if(uzaklik < 20){


    digitalWrite(9, HIGH);
    
    }
    else{

      

    digitalWrite(9, LOW);
      
      }


  

  if(Serial.available()>0){
    
    serialData=Serial.read();
    Serial.print(serialData);
    if(serialData=='1'){
      
        lcd.clear();
        
        sayac++;
        
        yer=5-sayac;

        lcd.begin(16, 2);
        lcd.print("Mevcut: ");
        lcd.print(sayac);
        lcd.setCursor(0, 1);
        lcd.print("Kalan: ");
        lcd.print(yer);

      
         myservo.write(100); 
         
         serialData=0;
        
          
      }else if(serialData=='0')
      {
        myservo.write(10); 
      }
    
    }


}
