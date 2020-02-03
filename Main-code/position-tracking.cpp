#include "vex.h"
#include <iostream>
#include <vex_thread.h>


double pi = acos(-1);

void positionTracker( void ) {
  Controller1.Screen.clearScreen();
  double x, y, z;
  std::cout << std::string(50, '\n');
  int l, r, distanceMoved;
  while (true) {
    l = LeftDrive.position(deg);
    r = RightDrive.position(deg);
    distanceMoved = (l + r)/2;
    z = Inertial.heading();
    x = distanceMoved*cos(z);
    y = distanceMoved*sin(z);
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print("x: %.3f  y: %.3f ", x, y);
    Controller1.Screen.newLine();
    Controller1.Screen.print("ang: %.3f", z);
    Controller1.Screen.newLine();
    Controller1.Screen.print("dis: %d", distanceMoved);
  }

}


int goTo( int x_0, int y_0, int z_0, int x, int y, int z, int speed ) {
  Drivetrain.driveFor(fwd, x - x_0, vex::distanceUnits::cm);
  vex::thread thread( &positionTracker );
  thread.join();
  return 0;
}

void drive( int degL, int degR, int left, int right ) {
  LeftDrive.spinFor(directionType::fwd, degL, rotationUnits::deg, left, velocityUnits::pct);
  RightDrive.spinFor(directionType::fwd, degR, rotationUnits::deg, right, velocityUnits::pct);
}
