#include <IRremote.h>

#define JVCPower              0xC0E8
#define JVCVolDown            0xC0F8
#define JVCVolUp              0xC078

IRsend irsend;
int power = 2;
int volup = 4;
int voldown = 5;

void setup() {
  Serial.begin(9600);
  pinMode(power, INPUT);
  pinMode(volup, INPUT);
  pinMode(voldown, INPUT);
}

void loop() {
  if(digitalRead(power)) {
    signal(JVCPower);
  } else if(digitalRead(volup)) {
    signal(JVCVolUp);
  } else if(digitalRead(voldown)) {
    signal(JVCVolDown);
  }
  delay(1);
}

void signal(int sig) {
  irsend.sendJVC(sig, 16,0);
  delayMicroseconds(75);
  irsend.sendJVC(sig, 16,1);
  delayMicroseconds(75);
  irsend.sendJVC(sig, 16,1);
}
