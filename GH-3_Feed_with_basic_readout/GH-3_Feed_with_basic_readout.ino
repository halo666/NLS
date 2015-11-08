//This is the first draft for the Nutrient Delivery Automator with a LCD readout
//RELAY MODULE #1
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define FLORALICIOUS  22
#define FLORAMICRO 23
#define FLORAGRO 24
#define FLORABLOOM 25
#define ARMORSI 26
#define CALMAG 27
#define KOOLBLOOMLIQUID 28
#define KOOLBLOOMDRY 29

//RELAY MODULE #2

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
  pinMode(PURGE_SOLENOID,OUTPUT);
  pinMode(FLORAGRO, OUTPUT);
  pinMode(FLORAMICRO, OUTPUT);
  pinMode(FLORABLOOM, OUTPUT);
  pinMode(ARMORSI, OUTPUT);
  pinMode(CALMAG, OUTPUT);
  pinMode(FLORALICIOUS, OUTPUT);
  pinMode(KOOLBLOOMLIQUID, OUTPUT);
  pinMode(KOOLBLOOMDRY, OUTPUT);
  
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
  digitalWrite (FLORALICIOUS,HIGH);
  digitalWrite (FLORAMICRO,HIGH);
  digitalWrite (FLORAGRO,HIGH);
  digitalWrite (FLORABLOOM,HIGH);
  digitalWrite (ARMORSI,HIGH);
  digitalWrite (CALMAG,HIGH);
  digitalWrite (KOOLBLOOMLIQUID,HIGH);
  digitalWrite (KOOLBLOOMDRY,HIGH);

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
   
 
  
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   lcd.setCursor(0, 0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Fill-3 Gal");
   delay(30000);   //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
   digitalWrite(FLORALICIOUS,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious");  
   delay(2400);                               
   digitalWrite(FLORALICIOUS,HIGH);  
   delay(2000);         
   digitalWrite(FLORAMICRO,LOW);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro"); 
   delay(6000);                               
   digitalWrite(FLORAMICRO,HIGH);         
   digitalWrite(FLORAGRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("FloraGro");    
   delay(0);                               
   digitalWrite(FLORAGRO,HIGH); 
   digitalWrite(FLORABLOOM,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");    
   delay(19200);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);          
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");  
   delay(0);                        
   digitalWrite(ARMORSI,HIGH);        
   digitalWrite(CALMAG,LOW); 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");    
   delay(0);                               
   digitalWrite(CALMAG,HIGH);              
   digitalWrite(KOOLBLOOMLIQUID,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("KoolBloom Liquid");    
   delay(6000);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        //No way to run KOOLBLOOMDRY yet
   //digitalWrite(KOOLBLOOMDRY,HIGH);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Fill");  
   
   delay(150000);    
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   delay(500); 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("PURGE");
   delay(500);
   digitalWrite(PURGE_SOLENOID,LOW);
   delay(2000);
   digitalWrite(PURGE_SOLENOID,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER5");
   lcd.setCursor(0,1);
   lcd.print ("Flush");    
   delay(500);
   digitalWrite(FLOWER5,LOW);         //OPEN THE SOLENOID TO THE RUN   
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER5,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
      delay(500);

  //FLOWER5^
  //FLOWER6\/
  digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
  lcd.setCursor(0,1);
  lcd.print ("Fill"); 
  delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
  digitalWrite(FLORALICIOUS,LOW);         
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
  lcd.setCursor(0,1);
  lcd.print ("Floralicious");  
  delay(3200);                               
  digitalWrite(FLORALICIOUS,HIGH); 
  delay(1000);
  digitalWrite(FLORAMICRO,LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
  lcd.setCursor(0,1);
  lcd.print ("Flora Micro");    
  delay(12800);                               
  digitalWrite(FLORAMICRO,HIGH);
  digitalWrite(FLORAGRO,LOW);       
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
  lcd.setCursor(0,1);
  lcd.print ("Flora Gro");    
  delay(12800);                               
  digitalWrite(FLORAGRO,HIGH);           
  digitalWrite(FLORABLOOM,LOW);  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
  lcd.setCursor(0,1);
  lcd.print ("Flora Bloom");    
  delay(16000);                        
  digitalWrite(FLORABLOOM,HIGH);   
  digitalWrite(ARMORSI,LOW);  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");   
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);    
   digitalWrite(CALMAG,LOW);        
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");   
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);                 
   digitalWrite(KOOLBLOOMLIQUID,LOW);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");    
   delay(0);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   // digitalWrite(KOOLBLOOMDRY,LOW);           
   // delay(0);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   
   delay(180000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   digitalWrite(FLOWER6,LOW);         //OPEN THE SOLENOID TO THE RUN
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER6");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER6,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
 
//F6^
//F1\/
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
   digitalWrite(FLORALICIOUS,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious");    
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro");    
   delay(12800);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro"); 
   delay(0);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");     
   delay(25600);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");    
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");   
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);      
   digitalWrite(KOOLBLOOMLIQUID,LOW);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid"); 
   delay(6400);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
  // digitalWrite(KOOLBLOOMDRY,LOW);           
  //  delay(2000);                        
  //  digitalWrite(KOOLBLOOMDRY,HIGH);  
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   delay(180000);   
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER1");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(FLOWER1,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   delay(2000);                    
   digitalWrite(FLOWER1,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
   
   //FLOWER1^
   //FLOWER2\/
   
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        

   digitalWrite(FLORALICIOUS,LOW);        
    lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious"); 
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro");   
   delay(12800);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro");    
   delay(3200);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");    
   delay(19200);                    
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");    
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW); 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");   
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);                
   digitalWrite(KOOLBLOOMLIQUID,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid"); 
   delay(6400);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   delay(180000);     
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER2");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(FLOWER2,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(FLOWER2,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(500);
   //FLOWER2^
   //FLOWER3\/
   
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
     lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
   digitalWrite(FLORALICIOUS,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious");    
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro");    
   delay(12800);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro"); 
   delay(12800);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");   
   delay(16000);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);           
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI"); 
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);           
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag"); 
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);                 
   digitalWrite(KOOLBLOOMLIQUID,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");    
   delay(0);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   
   delay(180000);      
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
                
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER3");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(FLOWER3,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(MIX_PUMP,HIGH);     //TURN OFF THE AGITATE PUMP
   delay(2000);                    
   digitalWrite(FLOWER3,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
   //^FLOWER3 
   //FLOWER4\/
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
 
   digitalWrite(FLORALICIOUS,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious");    
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);        
    lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro"); 
   delay(8000);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro");    
   delay(0);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW); 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");
   delay(25600);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI"); 
   delay(0);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");    
   delay(0);                               
   digitalWrite(CALMAG,HIGH);         
         
   digitalWrite(KOOLBLOOMLIQUID,LOW);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");       
   delay(8000);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(180000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full                   
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER4");
   lcd.setCursor(0,1);
   lcd.print ("Flush");
   digitalWrite(FLOWER4,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(MIX_PUMP,HIGH);     //TURN OFF THE AGITATE PUMP
   delay(2000);                    
   digitalWrite(FLOWER4,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
   //FLOWER4^
   //VEG5\/
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
 
   
   digitalWrite(FLORALICIOUS,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious"); 
   
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro"); 
   digitalWrite(FLORAMICRO,LOW);          
   delay(16000);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro");       
   delay(16000);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");         
   delay(8000);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");      
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");      
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);                 
   digitalWrite(KOOLBLOOMLIQUID,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");      
   delay(2000);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   digitalWrite(KOOLBLOOMDRY,LOW);           
   delay(2000);                        
   digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   delay(180000);
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full

                     
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG5");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(VEG5,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(MIX_PUMP,HIGH);     //TURN OFF THE AGITATE PUMP
   delay(2000);                    
   digitalWrite(VEG5,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
   //VEG5^
   //VEG3&4\/
   
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Fill"); 
   delay(60000);  
   digitalWrite(FLORALICIOUS,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Floralicious");       
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro");    
   delay(16000);                               
   digitalWrite(FLORAMICRO,HIGH);      
   digitalWrite(FLORAGRO,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro");         
   delay(16000);                               
   digitalWrite(FLORAGRO,HIGH);    
   digitalWrite(FLORABLOOM,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");         
   delay(8000);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);      
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");      
   delay(6400);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");    
   delay(6400);                               
   digitalWrite(CALMAG,HIGH);         
         
   digitalWrite(KOOLBLOOMLIQUID,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");   
   delay(0);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   delay(180000);        
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full 
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("VEG2,3&4"); 
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(VEG2,LOW);
   digitalWrite(VEG3,LOW);
   digitalWrite (VEG4,LOW);   //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(VEG2,HIGH);
   digitalWrite(VEG3,HIGH);
   digitalWrite(VEG4,HIGH);//CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
   //^VEG2,3&4 Each getting 1/3 batch
   //FLOWER7\/
   digitalWrite(FILL_SOLENOID,LOW);   //open the fill solenoid to fill the reservior.        
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Fill");
   delay(60000);      //this is the time it takes to fill the 5 gal bucket enough to prime the mixing pump        
   digitalWrite(FLORALICIOUS,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Floralicious"); 
   
   delay(3200);                               
   digitalWrite(FLORALICIOUS,HIGH);     
   digitalWrite(FLORAMICRO,LOW);    
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Flora Micro");       
   delay(8000);                               
   digitalWrite(FLORAMICRO,HIGH);      

   digitalWrite(FLORAGRO,LOW);       
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Flora Gro");     
   delay(0);                               
   digitalWrite(FLORAGRO,HIGH);    

  digitalWrite(FLORABLOOM,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Flora Bloom");         
   delay(25600);                        
   digitalWrite(FLORABLOOM,HIGH);          
   digitalWrite(ARMORSI,LOW);   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Armor SI");         
   delay(0);                        
   digitalWrite(ARMORSI,HIGH);       
   digitalWrite(CALMAG,LOW);     
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Cal Mag");       
   delay(0);                               
   digitalWrite(CALMAG,HIGH);         
   digitalWrite(KOOLBLOOMLIQUID,LOW);  
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Koolbloom Liquid");           
   delay(8000);                        
   digitalWrite(KOOLBLOOMLIQUID,HIGH);          
   //digitalWrite(KOOLBLOOMDRY,LOW);           
   //delay(2000);                        
   //digitalWrite(KOOLBLOOMDRY,HIGH);
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Fill");

   delay(180000);        
   digitalWrite(FILL_SOLENOID,HIGH);   //closes the fill solenoid once the reservior is full
   
   digitalWrite(FLUSH_PUMP,LOW);    //TURN ON THE 110V AC FLUSHING PUMP
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("FLOWER7");
   lcd.setCursor(0,1);
   lcd.print ("Flush"); 
   digitalWrite(FLOWER7,LOW);         //OPEN THE SOLENOID TO THE RUN
   delay(300000);                   //WAIT TO FLUSH THE BATCH TO THE RUN..CURRENTLY 4 MINUTES 30 SECONDS  
   digitalWrite(MIX_PUMP,HIGH);     //TURN OFF THE AGITATE PUMP
   delay(2000);                    
   digitalWrite(FLOWER7,HIGH);        //CLOSE THE SOLENOID AFTER THE BATCH IS DISTRUBUTED  
   digitalWrite (FLUSH_PUMP,HIGH);
   delay(5000);
//FLOWER7^
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
   lcd.print ("Flush"); 
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
   delay(240000);
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
   
   
 
   
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print ("22.5 HOUR DELAY");
   lcd.setCursor(0,1);
   lcd.print ("Between Cycles");  
  delay(81000000);   }
 
