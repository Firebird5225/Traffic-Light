// Project 5 - Controlling Traffic
// Deric Stutzman

int yellowDirection;
int trafficWestTrue;
int trafficEastTrue;

#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 100  // 0.1 seconds for yellow light blink 2

boolean trafficWest = true;  // west = true, east = false3

int flowTime = 1000;     // amount of time to let traffic flow4
int changeDelay = 2000;  // amount of time between color changes

void setup() {  // set up the digital I/O pins
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);  // set initial state for lights - west side is green first

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}
void loop() {
  if (digitalRead(westButton) == HIGH)  // request west>east traffic flow {
    if (trafficWest != true)
    // only continue if traffic flowing in the opposite (east) direction
    {
      trafficWest = true;
      delay(flowTime);

      changeGreentoRedLight(eastGreen, eastYellow, eastRed);

      changeYellowLight(westYellow);

      changeRedLight(westGreen, westYellow, westRed);
    }

  if (digitalRead(eastButton) == HIGH)  //when button is pressed starts the if statement
  {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);

      changeGreentoRedLight(westGreen, westYellow, westRed);

      changeYellowLight(eastYellow);

      changeRedLight(eastGreen, eastYellow, eastRed);
    }
  }
}



//Functions

void changeYellowLight(int yellowDirection) {
  for (int a = 0; a < 5; a++)  // blink yellow light
  {
    digitalWrite(yellowDirection, LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowDirection, HIGH);
    delay(yellowBlinkTime);
  }
}


void changeGreentoRedLight(int green, int yellow, int red) {

  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(changeDelay);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(changeDelay);
}


void changeRedLight(int green, int yellow, int red) {

  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}
