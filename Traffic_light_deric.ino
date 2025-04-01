// Project 5 - Controlling Traffic
// define the pins that the buttons and lights are connected to:1
// Deric Stutzman

int yellowDirection;
//int trafficWestTrue;


#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500  // 0.5 seconds for yellow light blink 2

boolean trafficWest = true;  // west = true, east = false3

int flowTime = 1000;    // amount of time to let traffic flow4
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
      
      //trafficWestTrue;

      trafficWest = true;            // change traffic flow flag to west>east
      delay(flowTime);               // give time for traffic to flow
      digitalWrite(eastGreen, LOW);  // change east-facing lights from green  // to yellow to red
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);

     changeYellowLight(westYellow);

      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);  // change west-facing lights from red // to green
      digitalWrite(westGreen, HIGH);
    }

  if (digitalRead(eastButton) == HIGH) //when button is pressed starts the if statement
   {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);


      digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);

    changeYellowLight(eastYellow);

      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);
    }
  }
}





void changeYellowLight(int yellowDirection){
for (int a = 0; a < 5; a++)  // blink yellow light
      {
        digitalWrite(yellowDirection, LOW);
        delay(yellowBlinkTime);
        digitalWrite(yellowDirection, HIGH);
        delay(yellowBlinkTime);
      }
}


void changeGreenLight(int trafficWestTrue){
  trafficWest = true;            // change traffic flow flag to west>east
      delay(flowTime);               // give time for traffic to flow
      digitalWrite(eastGreen, LOW);  // change east-facing lights from green  // to yellow to red
      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);
}


//void changeRedLight(int trafficEast)