# Arduino-05
Ultrasonic
## آزمایش 5:
### سنسور دنده عقب
### هدف:
#### در این آزمایش می خواهیم با استفاده از ماژول اولتراسونیک یک سنسوری مشابه سنسور دنده عقب ماشین پیاده سازی کنیم.
---
## ابزار:
![](/tools.jpg)
|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|6|
|2|LED|1|
|3|مقاومت|1|
|4|برد بورد|1|
|5|ریزپردازنده|1|
|6|اولترا سونیک|1|

---
## شرح مختصر :
#### در مدار LED قرار گرفته است که در هنگام نزدیک شدن مانعی به اولتراسونیک روشن می شود و نزدیک شدن این مانع با شدت روشنایی LED اندازه گرفته می شود.
#### به طوریکه وقتی مانع نزدیک می شود شدت روشنایی به حداکثر می رسد و وقتی مانع دور می شود شدت روشنایی به حداقل می رسد(خاموش می شود)
#### چیزی مشابه سنسور دنده عقب خودرو که به نوعی هشدار است وقتی مانی به خودرو نزدیک شود.
#### در بازه (4-30)سانتی متر
---
### کد برنامه : 
---

c++```int tring = 9;
int echo = 10;
int duration;
int dist;
int led = 11, value;`.

`setup() {
  Serial.begin(9600);
  pinMode(tring, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}```.

`void loop() {
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
}`.

---

## عملکرد مدار :
![](/gifsensor.gif)
## تصویر مدار:
![](/photo.jpg)
## شکل شماتیک مدار
![](/schema.jpg)
