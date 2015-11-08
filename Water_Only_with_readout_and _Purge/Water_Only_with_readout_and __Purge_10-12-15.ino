//RELAY MODULE #2
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define FLOWER5 41
#define FLOWER6 40
#define FLOWER1 39
#define FLOWER2 38
#define FLOWER3 37
#define FLOWER4 36
#define VEG5 35
#define VEG3 34
 
//RELAY MODULE #3
 
#define VEG2 33
#define VEG4 32
#define VEG1 31
#define FLOWER7 30

#define FILL_SOLENOID 42                          
#define MIX_PUMP 43                   
#define PURGE_SOLENOID 44                         
#define FLUSH_PUMP 45


void setup()
{    
  
  
// Initialize the Arduino data pins for OUTPUT
  pinMode(FILL_SOLENOID, OUTPUT);       
  pinMode(MIX_PUMP, OUTPUT);
  pinMode(FLUSH_PUMP, OUTPUT);
  
  pinMode(FLOWER5, OUTPUT);
  pinMode(FLOWER6, OUTPUT);
  pinMode(FLOWER1, OUTPUT);
  pinMode(FLOWER2, OUTPUT);
  pinMode(FLOWER3, OUTPUT);
  pinMode(FLOWER4, OUTPUT);
  pinMode(VEG5, OUTPUT);
  pinMode(VEG3, OUTPUT);
  pinMode(VEG2, OUTPUT);
  pinMode(VEG4, OUTPUT);
  pinMode(VEG1, OUTPUT);
  pinMode(FLOWER7, OUTPUT);
    lcd.begin(16,2);

}
 void loop()
 {
     //make sure the relays start OFF  and the solenoids are CLOSED
  digitalWrite (FILL_SOLENOID,HIGH);
  digitalWrite (MIX_PUMP,HIGH);
  digitalWrite (PURGE_SOLENOID,HIGH);
  digitalWrite (FLUSH_PUMP,HIGH);
  
  digitalWrite (FLOWER5,HIGH);
  digitalWrite (FLOWER6,HIGH);
  digitalWrite (FLOWER1,HIGH);
  digitalWrite (FLOWER2,HIGH);
  digitalWrite (FLOWER3,HIGH);
  digitalWrite (FLOWER4,HIGH);
  digitalWrite (VEG5,HIGH);
  digitalWrite (VEG3,HIGH);
  digitalWrite (VEG2,HIGH);
  digitalWrite (VEG4,HIGH);
  digitalWrite (VEG1,HIGH);
  digitalWrite (FLOWER7,HIGH);


   //begin the cycle
   
  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Fill");  
   
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);              
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
  digitalWrite (PURGE_SOLENOID,LOW);
     lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("PURGE 10 SEC"); 
   delay(10000);
     digitalWrite (PURGE_SOLENOID,LOW);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Feed");    
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER5,LOW);         //OPEN THE SOLENOID TO THE RUN   
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER5,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   delay(500);
   digitalWrite (FLUSH_PUMP,HIGH);
  
 //that's a batch for FLOWER5
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
  
   delay(240000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Feed");        
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER6,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 5 MINUTES 30 SECONDS  
   digitalWrite(FLOWER6,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
  
 
   //That should be a cycle for FLOWER6
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER1,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);
   digitalWrite(FLOWER1,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   
   
   //That should be a cyclefor FLOWER1
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Feed"); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER2,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER2,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   //That should be a cycle FLOWER2
     lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   delay(240000);  
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Feed"); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER3,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER3,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   //^FLOWER3 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Feed");
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER4,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER4,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   //^FLOWER4
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Feed"); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(VEG5,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                    
   digitalWrite(VEG5,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   //That should be a cycleVEG5
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);        
   digitalWrite(FILL_SOLENOID,HIGH);
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4");
   lcd.setCursor(0,1);
   lcd.print ("Feed"); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(VEG2,LOW);
   digitalWrite(VEG3,LOW);
   digitalWrite (VEG4,LOW);   //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(VEG2,HIGH);
   digitalWrite(VEG3,HIGH);
   digitalWrite(VEG4,HIGH);//CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);

//^VEG2,3&VEG4 Each getting 1/3 batch
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   delay(240000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Feed"); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER7,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(330000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER7,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   
   //now we flush the system.
   

   digitalWrite(FILL_SOLENOID,LOW);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLUSH RUN");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(240000); //fill 3gal 
   digitalWrite(FILL_SOLENOID,HIGH);
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLUSH RUN");
   lcd.setCursor(0,1);
   lcd.print ("Drink"); 
   digitalWrite(FLUSH_PUMP,LOW);
   digitalWrite(FLOWER7,LOW);
   delay(5000);
   digitalWrite(VEG5,LOW);
   delay(5000);
   digitalWrite(VEG3,LOW);
   digitalWrite(VEG4,LOW);
   delay(5000); 
   digitalWrite(FLOWER1,LOW);
   digitalWrite(FLOWER2,LOW);
   digitalWrite(FLOWER3,LOW);
   digitalWrite(FLOWER4,LOW);
   digitalWrite(FLOWER5,LOW);
   digitalWrite(FLOWER6,LOW);
   digitalWrite(VEG2,LOW);
   delay(100000);
   digitalWrite(FLOWER1,HIGH);
   digitalWrite(FLOWER2,HIGH);
   digitalWrite(FLOWER3,HIGH);
   digitalWrite(FLOWER4,HIGH);
   digitalWrite(FLOWER5,HIGH);
   digitalWrite(FLOWER6,HIGH); 
   digitalWrite(FLOWER7,HIGH);
   digitalWrite(VEG1,HIGH);
   digitalWrite(VEG2,HIGH); 
   digitalWrite(VEG3,HIGH);
   digitalWrite(VEG4,HIGH);    
   digitalWrite(VEG5,HIGH);
   digitalWrite(FLUSH_PUMP,HIGH);
   
 
  delay(2700000);                   //2.7 MINUTE DELAY IN BETWEEN READINGS
 }
   //That should be a cycle, triggered by the value of ANALOG 12 dropping dropping below 500. Rinse and repeat and whenever the soil dries it will fire up.
   
  
