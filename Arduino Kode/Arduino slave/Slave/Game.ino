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
  int randNumber = random(1, 4);

  switch (randNumber)
  {
    case 1:
      vibrate(vibPin1, button1);
      break;
    case 2:
      vibrate(vibPin2, button2);
      break;
    case 3:
      vibrate(vibPin3, button3);
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
