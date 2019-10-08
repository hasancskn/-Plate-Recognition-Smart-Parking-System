char serialData;

#include <Servo.h>

Servo myservo;


void setup() {
  Serial.begin(9600);
  myservo.attach(8);

            myservo.write(0);
}

void loop() {

  if(Serial.available()>0){
    
    serialData=Serial.read();
    Serial.print(serialData);
    if(serialData=='1'){
      
         myservo.write(100); 
         
         serialData=0;
        
          
      }else if(serialData=='0')
      {
        myservo.write(10); 
      }
    
    }


}
