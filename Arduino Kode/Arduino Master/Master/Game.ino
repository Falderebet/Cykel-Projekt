/*
int vibPin1 = 3;
int vibPin2 = 5;
int vibPin3;

int button1 = 2;
int button2 = 4;
int button3 = 7;

long timei = 0;

#define NUM_USER_BUTTONS 4
int userButtonReadPins[NUM_USER_BUTTONS];
*/

long mainGame() {
  // put your main code here, to run repeatedly:
  countdown();
  delay (random(1000, 6000));
  timei += activate();

  delay (random(1000, 6000));
  timei += activate();

  delay (random(1000, 6000));
  timei += activate();
  Serial.println(timei);
  return timei;
  
}

long activate()
{
  int timeStart = millis();
  int randNumber = random(1, 3);
  switch (randNumber)
  {
    case 1:
      vibrate(vibPin1, button1);
      break;
    case 2:
      vibrate(vibPin2, button2);
      break;
  }
  int timeEnd = millis();
  return  timeEnd - timeStart;

}

void vibrate(int vib, int button)
{
  //Tænd vibrator
  digitalWrite(vib, HIGH);
  //Vent til knappen bliver trykket
  while (digitalRead(button) == LOW)
  {
    Serial.println(millis());
  }
  digitalWrite(vib, LOW);
}

void countdown() {
  digitalWrite(vibPin1, HIGH);
  delay(500);
  digitalWrite(vibPin1, LOW);
  delay(500);
  digitalWrite(vibPin1, HIGH);
  delay(500);
  digitalWrite(vibPin1, LOW);
  delay(500);
  digitalWrite(vibPin1, HIGH);
  delay(500);
  digitalWrite(vibPin1, LOW);
}
