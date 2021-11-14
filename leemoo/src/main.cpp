/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\rachelle.hu                                      */
/*    Created:      Sun Nov 17 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Tilter               motor         11
// Drivetrain           drivetrain    12, 20
// LeftDrive            motor         12
// RightDrive           motor         20
// IntakeL              motor         1
// IntakeR              motor         10
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#define RIGHTFRONT 0
#define RIGHTBACK 1
#define LEFTFRONT 2
#define LEFTBACK 3

using namespace vex;


competition Competition;

//setup
void pre_auton( void ) {
  // DO NOT REMOVE!
  vexcodeInit();
  // with 4 inch drive, each block about 600 degrees
}

//autonomous
void autonomous( void ) {
  int posi[] = {0, 0, 0}; //the numbers in each place are {x position, y position, angle (from start)}
  int *currentCoordinates = positionTracker(posi);
  Arms.spinFor(vex::directionType::fwd, 90, vex::rotationUnits::deg, 40, vex::velocityUnits::pct, false );
  Drivetrain.driveFor(vex::directionType::fwd, 24, inches, 80, vex::velocityUnits::pct);
  LeftDrive.position(deg);
  Drivetrain.drive(forward);
}

//self-explanatory??
void usercontrol( void ) {
  int posi[] = {0, 0, 0}; //the numbers in each place are {x position, y position, angle (from start)}
  int *currentCoordinates = positionTracker(posi);
}



int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}

/*some stuff i learned:
c/cpp switch case:
  switch (expression or value) {
    case value:
      actions
      break;
    case other_value:
      actions
      break;
    default:
      oop
  }
  */