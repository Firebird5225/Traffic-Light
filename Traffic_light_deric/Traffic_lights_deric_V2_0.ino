// Project 5 - Controlling Traffic
// Deric Stutzman

int yellowDirection;
int trafficWestTrue;
int trafficEastTrue;
int pedLight;

#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedButton 8
#define white 9
#define yellowBlinkTime 100  // 0.1 seconds for yellow light blink 2
#define whiteBlinkTime 100

boolean trafficWest = true;  // west = true, east = false
boolean pedCrossingLight = false;
boolean forceWest = false;
boolean forceEast = false;

int flowTime = 1000;     // amount of time to let traffic flow4
int changeDelay = 2000;  // amount of time between color changes

void setup() {  // set up the digital I/O pins
  pinMode(pedButton, INPUT);
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(white, OUTPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);  // set initial state for lights - west side is green first

  digitalWrite(white, LOW);
  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}
void loop() {

  if ((digitalRead(westButton) == HIGH) || forceWest)  // request west>east traffic flow {
    if (trafficWest != true)
    // only continue if traffic flowing in the opposite (east) direction
    {
      trafficWest = true;
      delay(flowTime);
      if (pedCrossingLight == true) {
        changeGreentoRedLight(eastGreen, eastYellow, eastRed);
      }
      changeYellowLight(westYellow);

      changeRedLight(westGreen, westYellow, westRed);
      forceWest = false;
      forceEast = false;
    }

  if ((digitalRead(eastButton) == HIGH) || forceEast)  //when button is pressed starts the if statement
  {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      if (pedCrossingLight != true) {
        changeGreentoRedLight(westGreen, westYellow, westRed);
      }
      changeYellowLight(eastYellow);

      changeRedLight(eastGreen, eastYellow, eastRed);
      forceWest = false;
      forceEast = false;
    }
  }
  if (digitalRead(pedButton) == HIGH) {


    if (trafficWest) {
      forceEast = true;
      changeGreentoRedLight(westGreen, westYellow, westRed);
      pedCrossingLight = true;
    } else {
      forceWest = true;
      changeGreentoRedLight(eastGreen, eastYellow, eastRed);
      pedCrossingLight = false;
    }
    for (int i = 0; i < 5; i++) {
      delay(flowTime);

      digitalWrite(white, HIGH);

      delay(1);
    }

    pedCrossingWarning(white);

    digitalWrite(white, LOW);
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



void pedCrossingWarning(int pedLight) {
  for (int a = 0; a < 5; a++)  // blink yellow light
  {
    digitalWrite(white, LOW);
    delay(whiteBlinkTime);
    digitalWrite(white, HIGH);
    delay(whiteBlinkTime);
  }
}