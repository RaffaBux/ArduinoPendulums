#define reedPin 8
#define led 13

int reedActualState = LOW;
int counter = 0;
unsigned long tParziale = 0;
unsigned long delta = 0;

void setup(){
pinMode(led, OUTPUT);
pinMode(reedPin, INPUT);
Serial.begin(9600);
}

void loop() {                       //riscontrato un bug quando il pendolo è vicino al sensore ma non abbastanza
  pendolo();
  resetValues();
}

void pendolo(){
  reedActualState = digitalRead(reedPin);
  if( reedActualState == HIGH && counter == 0 ){
    while( counter < 10 ){
      if( reedActualState == HIGH && counter == 0 ){
        while( reedActualState == HIGH && counter == 0 ){
          reedActualState = digitalRead(reedPin);
          Serial.println(counter);
          if( reedActualState == LOW ){
            tParziale = millis();
          }
        }
      }
      else if( reedActualState == HIGH && counter > 0){
        while( reedActualState == HIGH ){
          digitalWrite(led, HIGH);
          reedActualState = digitalRead(reedPin);
          if( reedActualState == LOW ){
            delta = delta + millis() - tParziale;
            tParziale = millis();
          }
        }
        digitalWrite(led, LOW);
      }
      else if ( reedActualState == LOW ){
        while( reedActualState == LOW ){
          reedActualState = digitalRead(reedPin);
          
          if ( millis() - tParziale > 5000){       //controllo afk
            return;
          }
          
          if( reedActualState == HIGH ){
            delta = delta + millis() - tParziale;
            tParziale = millis();
            counter++;
            Serial.println(counter);
          }
        }
      }     
    }
    Serial.println(delta);
  }
}

void resetValues(){
  reedActualState = LOW;
  counter = 0;
  tParziale = 0;
  delta = 0;
}
