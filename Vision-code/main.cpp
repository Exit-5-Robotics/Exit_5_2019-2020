/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\alame                                            */
/*    Created:      Fri Nov 08 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// motorLeft            motor         1               
// motorRight           motor         2               
// Vision3              vision        3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true){
    Brain.Screen.clearScreen();
    Brain.Screen.setOrigin(1,1);
    Brain.Screen.drawRectangle(0,0,316,212);

    //Tell the vision sensor to capture a frame and look objects of the color stored in SIG_ORANGE.     
    Vision3.takeSnapshot(Vision3__SIG_ORANGE);
    //If it detects at least one object with the color stored in SIG_ORANGE...
    if(Vision3.largestObject.exists){
      //...draw a rectangle of equal size on the V5 Screen
      Brain.Screen.drawRectangle(Vision3.largestObject.originX,Vision3.largestObject.originY, Vision3.largestObject.width,Vision3.largestObject.height,color::orange);
    }
    int ideal;
    ideal=158;
    while(Vision3.largestObject.width<216){ //can change ideal width
      int centerpoint;
      centerpoint=Vision3.largestObject.originX+Vision3.largestObject.width/2;
      float k;
      k=.4; //can change value of k
      int error;
      error=centerpoint-ideal;
      int speedLeft;
      int base;
      base = 20; //can change value of base
      speedLeft=error*k+base;
      int speedRight;
      speedRight=base-error*k;
      motorLeft.setVelocity(speedLeft, percent);
      motorRight.setVelocity(speedRight, percent);

      motorLeft.spin(forward);
      motorRight.spin(forward);
          //Tell the vision sensor to capture a frame and look objects of the color stored in SIG_ORANGE.     
    Vision3.takeSnapshot(Vision3__SIG_ORANGE);
    }
    task::sleep(200);
  }
}