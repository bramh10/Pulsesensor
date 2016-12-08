
int pulsePin = 0;                 // Pulse sensor pin
int blinkPin = 13;                // led die op de hartslag aan en uit gaat.

volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

static boolean serialVisual = false;   // Zet op true als je de vizualisatie in de seriële monitor wilt bekijken.


void setup(){
  pinMode(blinkPin,OUTPUT);         // led die op de hartslag aan en uit gaat.
  Serial.begin(115200);             
  interruptSetup();                
}


void loop(){
  
    serialOutput() ;       
    
  if (QS == true){     // Hartslag is gevonden
                       // BPM en IBI zijn bepaald
                       // QS = 'true' als er een hartslag is gevonden
        serialOutputWhenBeatHappens();   // Dataviz in serial    
        QS = false;                      // QS terug naar false zetten voor de volgende hartslag.    
  }
}




