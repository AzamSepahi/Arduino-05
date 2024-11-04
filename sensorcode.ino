int tring = 9;
int echo = 10;
int duration;
int dist;
int led = 11, value;

void setup() {
  Serial.begin(9600);
  pinMode(tring, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  digitalWrite(tring, LOW);
  delayMicroseconds(2);
  digitalWrite(tring, HIGH);
  delayMicroseconds(10);
  digitalWrite(tring, LOW);
  duration = pulseIn(echo, HIGH);
  dist = (duration / 2) * 0.0343;
  Serial.println(dist);
  int MAP =  map(dist, 30, 4, 0, 255);
  if (dist <= 30)
  {
    analogWrite(led, MAP);
  }
  else {
    analogWrite(led, LOW);
  }


  delay(500);

}
