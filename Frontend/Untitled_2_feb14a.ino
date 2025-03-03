#include "arduino_secrets.h"
#include <ESP32Servo.h>



#include <ESP32PWM.h>


#include "thingProperties.h"

Servo sr1;
Servo sr2;

int sp1 = 12;
int sp2 = 15;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
	sr1.setPeriodHertz(50);   
	sr1.attach(sp1, 1000, 3000);

    sr2.setPeriodHertz(50);    // standard 50 hz servo
	sr2.attach(sp2, 500, 3000);
  sr1.write(40);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
  int count=0;



void standby(){
  for (int i=40;i<180;i++){
    sr1.write(i);
    delay(10);
  }

if (count==5){
  delay(100);
  sr2.write(60);
  delay(100);
  sr2.write(180);
  delay(100);
count=0;
}

  for (int i=180;i>40;i--){
    sr1.write(i);
    delay(10);
  }
}



void loop() {
  ArduinoCloud.update();
  // Your code here


  sr1.write(d1);
  

  sr2.write(d2);
  
  if(sb==true){
    count+=1;
    standby();
  }
}

/*
  Since D1 is READ_WRITE variable, onD1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onD1Change()  {
  // Add your code here to act upon D1 change

}

/*
  Since D2 is READ_WRITE variable, onD2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onD2Change()  {
  // Add your code here to act upon D2 change
  
}

/*
  Since Sb is READ_WRITE variable, onSbChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSbChange()  {
  // Add your code here to act upon Sb change

}