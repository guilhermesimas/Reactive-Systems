#define LED_PIN 13
#define BUT_PIN 2
unsigned long timeLastBlink = 0;

void setup () {
   pinMode(LED_PIN,OUTPUT);
   pinMode(BUT_PIN,INPUT); 
}

void loop () {
  int but = digitalRead(BUT_PIN);
  unsigned long time = millis();
  if(time - timeLastBlink >= 1000)  {
      digitalWrite(LED_PIN,!digitalRead(LED_PIN));
      timeLastBlink=time;
  }
  if(but)  {
     digitalWrite(LED_PIN,HIGH);
     while(1); 
  }
    
}
