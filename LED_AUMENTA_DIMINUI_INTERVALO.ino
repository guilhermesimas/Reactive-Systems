#define LED_PIN 13
#define BUT1_PIN 2
#define BUT2_PIN 3
#define FREEZE_INTERVAL 500
#define INTERVAL_DIFFERENCE 100

unsigned long interval=1000;
unsigned long timeLastBlink=0;
unsigned long timeBut1 = LOW;
unsigned long timeBut2 = LOW;

int flagBut1=0;
int flagBut2=0;

void setup () {
   pinMode(LED_PIN,OUTPUT);
   pinMode(BUT1_PIN,INPUT);
   pinMode(BUT2_PIN,INPUT);
}

void loop () {
  int but1 = digitalRead(BUT1_PIN);
  int but2 = digitalRead(BUT2_PIN);
  unsigned long time = millis();
  if(time - timeLastBlink >= interval)  {
      digitalWrite(LED_PIN,!digitalRead(LED_PIN));
      timeLastBlink=time;
  }
  if(but1){
     if(!flagBut1){
       interval -= INTERVAL_DIFFERENCE ;
       flagBut1=HIGH;
     }
     timeBut1=millis();
     if(timeBut1-timeBut2 <= FREEZE_INTERVAL || timeBut2-timeBut1 <= FREEZE_INTERVAL )
     while(1); 
  }
  else flagBut1=LOW;
  if(but2){
     if(!flagBut2){
       interval += INTERVAL_DIFFERENCE ;
       flagBut2=HIGH;
     }
     timeBut2=millis();
     if(timeBut1-timeBut2 <= FREEZE_INTERVAL || timeBut2-timeBut1 <= FREEZE_INTERVAL )
     while(1); 
  }   
  else flagBut2=LOW;
}
