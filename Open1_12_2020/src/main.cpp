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
// void centerBlock();
void inertialCodeWoot();

void pre_auton( void ) {
  // DO NOT REMOVE!
  vexcodeInit();
}

void autonomous( void ) {
  positionTracker();
  // ArmL.spin(reverse);
  // ArmR.spin(reverse);
  // Drivetrain.driveFor(directionType::fwd, 15, inches, 80, velocityUnits::pct);
  // Drivetrain.driveFor(directionType::rev, 15, inches, 80, velocityUnits::pct);
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
  // goTo();
  // 
  positionTracker();
  inertialCodeWoot();
  goTo(900,900,900,0,0,0,0);
}

void inertialCodeWoot() {
  inertial::quaternion  Inertial_quaternion;

    Inertial.calibrate();

    while(1) {
        // get the quaternion data
        Inertial_quaternion = Inertial.orientation();

        Brain.Screen.clearScreen();        

        Brain.Screen.setFont( mono15 );
        Brain.Screen.setPenColor( white );
        Brain.Screen.setFillColor( black );
        
        Brain.Screen.printAt( 20,  30, "GX  %8.3f", Inertial.gyroRate( xaxis, dps ) );
        Brain.Screen.printAt( 20,  45, "GY  %8.3f", Inertial.gyroRate( yaxis, dps ) );
        Brain.Screen.printAt( 20,  60, "GZ  %8.3f", Inertial.gyroRate( zaxis, dps ) );

        Brain.Screen.printAt( 20,  90, "AX  %8.3f", Inertial.acceleration( xaxis ) );
        Brain.Screen.printAt( 20, 105, "AY  %8.3f", Inertial.acceleration( yaxis ) );
        Brain.Screen.printAt( 20, 120, "AZ  %8.3f", Inertial.acceleration( zaxis ) );

        Brain.Screen.printAt( 20, 150, "A   %8.3f", Inertial_quaternion.a );
        Brain.Screen.printAt( 20, 165, "B   %8.3f", Inertial_quaternion.b );
        Brain.Screen.printAt( 20, 180, "C   %8.3f", Inertial_quaternion.c );
        Brain.Screen.printAt( 20, 195, "D   %8.3f", Inertial_quaternion.d );

        Brain.Screen.printAt( 150, 30, "Roll     %7.2f", Inertial.roll() );
        Brain.Screen.printAt( 150, 45, "Pitch    %7.2f", Inertial.pitch() );
        Brain.Screen.printAt( 150, 60, "Yaw      %7.2f", Inertial.yaw() );

        Brain.Screen.printAt( 150, 90, "Heading  %7.2f", Inertial.heading() );
        Brain.Screen.printAt( 150,105, "Rotation %7.2f", Inertial.rotation() );

        if( Inertial.isCalibrating() )
          Brain.Screen.printAt( 20,225, "Calibration  In Progress" );
        else
          Brain.Screen.printAt( 20,225, "Calibration  Done" );

        Brain.Screen.render();

        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
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