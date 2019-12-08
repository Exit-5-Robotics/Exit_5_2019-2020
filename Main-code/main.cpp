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
// Arms                 motor         3, 4
// MiddleWheel          motor         13 (forward is to left)
// Vision               vision        14
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "vision.h"
#define RED 1
#define BLUE -1
#define RANGLE -1
#define BANGLE 0

using namespace vex;

competition Competition;

// double pi = acos(-1);
void back( int side );
void front(int side );
void centerBlock();

void drive( int degL, int degR, int left, int right ) {
  LeftDrive.spinFor(directionType::fwd, degL, rotationUnits::deg, left, velocityUnits::pct);
  RightDrive.spinFor(directionType::fwd, degR, rotationUnits::deg, right, velocityUnits::pct);
}

void pre_auton( void ) {
  // DO NOT REMOVE!
  vexcodeInit();
}

void autonomous( void ) {
  // ArmL.spin(reverse);
  // ArmR.spin(reverse);
  Drivetrain.driveFor(directionType::fwd, 15, inches, 80, velocityUnits::pct);
  Drivetrain.driveFor(directionType::rev, 15, inches, 80, velocityUnits::pct);
  // ArmL.spinFor(directionType::fwd, 400, rotationUnits::deg, 100, velocityUnits::pct, false);
  // ArmR.spinFor(directionType::fwd, 400, rotationUnits::deg, 100, velocityUnits::pct, false);
  // Tilter.spinFor(directionType::fwd, 100, rotationUnits::deg, 100, velocityUnits::pct);
  // Tilter.spinFor(directionType::rev, 100, rotationUnits::deg, 100, velocityUnits::pct);
  // task::sleep(1000);
  // ArmL.spinFor(directionType::rev, 400, rotationUnits::deg, 70, velocityUnits::pct, false);
  // ArmR.spinFor(directionType::rev, 400, rotationUnits::deg, 70, velocityUnits::pct);
  // ArmL.stop(brakeType::coast);
  // ArmR.stop(brakeType::coast);
  // Tilter.stop();
  // task::sleep(500);
  // back(BLUE);
  // // front(RED);
}

void usercontrol( void ) {
  //vision
  Controller1.ButtonY.released(centerBlock);
  positionTracker(RANGLE);
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}


// MODULAR FUNCTIONS BELOW | MODULAR FUNCTIONS BELOW | MODULAR FUNCTIONS BELOW | MODULAR FUNCTIONS BELOW
void front ( int side ) {
  IntakeL.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  MiddleWheel.spinFor(directionType::rev, side*500, rotationUnits::deg, 60, velocityUnits::pct);
  MiddleWheel.stop();
  Drivetrain.driveFor(directionType::fwd, 5, inches, 20, velocityUnits::pct);

}

void back ( int side ) {
  IntakeL.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  IntakeR.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  Drivetrain.driveFor(directionType::fwd, 12, inches, 80, velocityUnits::pct);
  Drivetrain.driveFor(directionType::fwd, 27, inches, 13, velocityUnits::pct);
  Drivetrain.setTurnVelocity(30, pct);
  Drivetrain.turnFor(side*135, degrees);
  MiddleWheel.spinFor(directionType::fwd, side*400, rotationUnits::deg, 60, velocityUnits::pct);
  IntakeL.stop(brakeType::brake);
  IntakeR.stop(brakeType::brake);

  Drivetrain.driveFor(directionType::fwd, 32, inches, 60, velocityUnits::pct);
  
  Tilter.spinFor(vex::directionType::fwd, 375, deg, 10, vex::velocityUnits::pct, false);
  vex::task::sleep(2000);
  while (Tilter.isSpinning()) {
    IntakeL.spin(vex::directionType::rev, 5, vex::velocityUnits::pct);
    IntakeR.spin(vex::directionType::rev, 5, vex::velocityUnits::pct);
  }
  IntakeL.stop();
  IntakeR.stop();
  for (int i=0; i<50; i++) {
    LeftDrive.spinFor(directionType::rev, 20, rotationUnits::deg);
    RightDrive.spinFor(directionType::rev, 20, rotationUnits::deg);
  }
}


















void centerBlock( void ) {
  int count = 0;
    float k;
    double base;
    int error;
    double speedHDrive;
    int ideal;
    ideal=158;
    int centerpoint;
    centerpoint=Vision.largestObject.originX+Vision.largestObject.width/2;
    int distance;
    distance = abs(centerpoint-ideal);


    while(distance > 5){ //can change ideal width
      //Tell the vision sensor to capture a frame and look objects of the color stored in SIG_ORANGE.     
      Vision.takeSnapshot(SIG_ORANGE);
      //  Vision.takeSnapshot(SIG_PURPLE);
      //  Vision.takeSnapshot(SIG_GREEN);
      //If it detects at least one object with the color stored in SIG_ORANGE...
      if(Vision.largestObject.exists){
        Brain.Screen.clearScreen();
        Brain.Screen.setOrigin(1,1);
        Brain.Screen.drawRectangle(0,0,316,212);

        Brain.Screen.print("distance: %d", distance);
        Brain.Screen.newLine();
        Brain.Screen.print("speed: %d", acos(-1));
        Brain.Screen.newLine();
        Brain.Screen.print("reps: %d", count);
      //...draw a rectangle of equal size on the V5 Screen
      Brain.Screen.drawRectangle(Vision.largestObject.originX,Vision.largestObject.originY, Vision.largestObject.width,Vision.largestObject.height,color::orange);

      centerpoint=Vision.largestObject.originX+Vision.largestObject.width/2;

      k = .2; //can change value of k
      error = (centerpoint-ideal);
      distance = abs(error);

      if (error > 0){
        base = 1;
      } else {
        base = -1;
      }
      if (distance < 20){
        speedHDrive = error*k*.2;
      } else {
        speedHDrive = error*k*.6;
      }
      MiddleWheel.setVelocity(speedHDrive, percent);
      MiddleWheel.spin(forward);
      
      count += 1;
    }
    task::sleep(200);
  } 
    MiddleWheel.stop();
}
