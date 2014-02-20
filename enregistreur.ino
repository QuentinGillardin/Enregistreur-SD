#include <SD.h>



const int period = 1000;
boolean flag = false;

void setup(){ 
  pinMode(A0, INPUT); 
  pinMode(13, OUTPUT);  
  SD.begin(); 
}

void loop(){  
  int time = 0;
  int date = 0;
  int sample = 0;
  int i = 0;
  String dataString = "";
  int time_init = millis();
  flag = true; 
   
  
  if (flag == true){
    while(1){
      time = millis() - time_init;
      sample = 0;
      i = 0;
      dataString = "";
      date = millis();
        
      while(millis() < date+period){
          sample += analogRead(A0);
          i++;
      }
      
      digitalWrite(13, HIGH);
      sample = map(sample, 0, 1023, 0, 5/0.01);
      sample /= i;
          
      
      dataString += String(time/1000);
      dataString += " "; 
      dataString += String(sample + 6) ;  
      
      File dataFile = SD.open("datalog.txt", FILE_WRITE);
    
      if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();
        digitalWrite(13, LOW);
      }      
    }
  }
}


    
