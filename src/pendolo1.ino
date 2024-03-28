#define reedPin 8
#define led 13

int reedState = 0;
int counter = 0;
unsigned long tStart = 0;
unsigned long tEnd = 0;
unsigned long delta = 0;

void setup(){
pinMode(led, OUTPUT);
pinMode(reedPin, INPUT);
Serial.begin(9600);
}

void loop() {
  reedState = digitalRead(reedPin);
  while( reedState == HIGH && counter = 0 ){
    tStart = millis();
    reedState = digitalRead(reedPin);
  }

  counter++;
  
  while(reedState == LOW){
    reedState = digitalRead(reedPin);
  }

  if( reedState == HIGH && counter == 10 ){
    tEnd = millis();
    delta = tEnd - tStart;
    Serial.println(delta);
    counter = 0;
  }
  
  
  /*if (delta > 30000){
    counter = 0
  }
  if (reedState == HIGH){
    if(attivo == true && counter = 10){
      tEnd = millis();
      delta = tEnd - tStart;
      Serial.println(delta);     
      attivo = false;
      digitalWrite(led, LOW);
    }
    else{
      counter++;  
    }
  }
  else{
    if(attivo != true && counter = 0){
      tStart = millis();
      attivo = true;
      digitalWrite(led, HIGH);
    }
  }
  delay(1);*/
}
