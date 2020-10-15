int vibPin1 = 2;
int vibPin2 = A2;
int vibPin3;

int button1 = A3;
int button2 = A4;
int button3 = A5;

long timei;

#define NUM_USER_BUTTONS 4
int userButtonReadPins[NUM_USER_BUTTONS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(vibPin1, OUTPUT);
  pinMode(vibPin2, OUTPUT);
  pinMode(vibPin3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(activate());
  delay(5000);
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
  return timeStart - timeEnd;

}

void vibrate(int vib, int button)
{
  //Tænd vibrator
  digitalWrite(vib, HIGH);
  //Vent til knappen bliver trykket
  while (digitalRead(button) == LOW)
  {
    Serial.println("test");
  }
  digitalWrite(vib, LOW);
}
