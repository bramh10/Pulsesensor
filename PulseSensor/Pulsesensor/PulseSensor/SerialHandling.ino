void serialOutput(){   // Decide How To Output Serial. 
 if (serialVisual == true){  
     arduinoSerialMonitorVisual('-', Signal);   // gaat naar de vizualisatie functie
 } else{
      //sendDataToSerial('S', Signal);     // gaat naar de verzend data functie.
 }        
}


//  Bepalen hoe de data gevisualiseerd wordt.
void serialOutputWhenBeatHappens(){    
 if (serialVisual == true){            //  Als de visualisatie aan staat wordt dit gedaan 
    Serial.print("*** Heart-Beat Happened *** "); 
    Serial.print("BPM: ");
    Serial.print(BPM);
    Serial.print("  ");
 } else{
        Serial.print("#");
        Serial.print(BPM);
        Serial.print("%");
 }   
}

//  Data verzenden naar eventuele andere applicaties zoals Proccessing
void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);

    Serial.println(data);                
  }


void arduinoSerialMonitorVisual(char symbol, int data ){    
const int sensorMin = 0;      // minimale waarde die terug komt
const int sensorMax = 1024;    // maximale waarde die terug komt

  int sensorReading = data;
  // de waardes van de sensor data een waarde tussen de 0 en 11 geven
  int range = map(sensorReading, sensorMin, sensorMax, 0, 11);

  // op basis van de gemapte waarde wordt de visualisatie bepaald.
  switch (range) {
  case 0:     
    Serial.println("");    
    break;
  case 1:   
    Serial.println("---");
    break;
  case 2:    
    Serial.println("------");
    break;
  case 3:    
    Serial.println("---------");
    break;
  case 4:   
    Serial.println("------------");
    break;
  case 5:   
    Serial.println("--------------|-");
    break;
  case 6:   
    Serial.println("--------------|---");
    break;
  case 7:   
    Serial.println("--------------|-------");
    break;
  case 8:  
    Serial.println("--------------|----------");
    break;
  case 9:    
    Serial.println("--------------|----------------");
    break;
  case 10:   
    Serial.println("--------------|-------------------");
    break;
  case 11:   
    Serial.println("--------------|-----------------------");
    break;
  
  } 
}


