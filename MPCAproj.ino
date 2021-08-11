// include the library code:
#include <LiquidCrystal.h>


//Initializes all trigger pins that handle the 4 sensors.

const int trigPinA = 7;
const int echoPinA = 6;
const int trigPinB = 9;
const int echoPinB = 8;
const int trigPinC = 11;
const int echoPinC = 10;
const int trigPinD = 13;
const int echoPinD = 12;


long area;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(0, 1, 2, 3 , 4, 5);

void setup() {
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Area is(cm^2):");//set the cursor to column 0 and line 0
  pinMode(trigPinA, OUTPUT);
  pinMode(echoPinA, INPUT);
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPinB, INPUT);
  pinMode(trigPinC, OUTPUT);
  pinMode(echoPinC, INPUT);
  pinMode(trigPinD, OUTPUT);
  pinMode(echoPinD, INPUT);
}

void loop() {

  lcd.setCursor(0, 1); //set the cursor to column 0 and line 1
  lcd.print(calc());
  lcd.print("   ");
  delay(2000);
}

/**
 * Function to calcluate area of the room, given the distance of the walls from the sensor.
 */

long calc() {
  long durationA, distanceA;
  long durationB, distanceB;
  long durationC, distanceC;
  long durationD, distanceD;

  digitalWrite(trigPinA, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPinA, LOW);
  delayMicroseconds(20);
  durationA = pulseIn(echoPinA, HIGH); //To receive the reflected signal.
  distanceA = durationA * 0.034 / 2;

  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPinB, LOW);
  delayMicroseconds(20);
  durationB = pulseIn(echoPinB, HIGH); //To receive the reflected signal.
  distanceB = durationB * 0.034 / 2;

  digitalWrite(trigPinC, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPinC, LOW);
  delayMicroseconds(20);
  durationC = pulseIn(echoPinC, HIGH); //To receive the reflected signal.
  distanceC = durationC * 0.034 / 2;

  digitalWrite(trigPinD, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPinD, LOW);
  delayMicroseconds(20);
  durationD = pulseIn(echoPinD, HIGH); //To receive the reflected signal.
  distanceD = durationD * 0.034 / 2;

  //Sum of the two oppositely placed sensors, and the distance between them , gives the length of one side.
  
  area = (distanceA + distanceD+10)*(distanceB + distanceC+15 );


  return area;
}
