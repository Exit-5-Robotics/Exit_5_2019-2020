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
// Arms                 motor         3
// MiddleWheel          motor         13
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#define RIGHTFRONT 0
#define RIGHTBACK 1
#define LEFTFRONT 2
#define LEFTBACK 3

using namespace vex;

competition Competition;

double pi = acos(-1);

void drive( int degL, int degR, int left, int right ) {
  LeftDrive.spinFor(directionType::fwd, degL, rotationUnits::deg, left, velocityUnits::pct);
  RightDrive.spinFor(directionType::fwd, degR, rotationUnits::deg, right, velocityUnits::pct);
}

void pre_auton( void ) {
  // DO NOT REMOVE!
  vexcodeInit();
  // with 4 inch drive, each block is about 600 degrees
}

void autonomous( void ) {
  MiddleWheel.spinFor(directionType::fwd, 300, rotationUnits::deg, 80, velocityUnits::pct);
  Arms.spin(directionType::fwd, 100, velocityUnits::pct);
  Drivetrain.driveFor(directionType::fwd, 24, inches, 80, velocityUnits::pct);
  drive(360, 360, 80, -80);
  Drivetrain.turnFor(90, degrees);
}

void usercontrol( void ) {
  // int posi[] = {0, 0, 0}; //the numbers in each place are {x position, y position, angle (from start)}
  // Controller1.Screen.setCursor(0, 0); 
  // for (int i=0; i<3; i++)
  //   Controller1.Screen.print("%d ", posi[i]);
  // int *currentCoordinates = positionTracker(posi);
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  printf("bruh");
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
