#include "vex.h"
#include <iostream>
#include <vex_thread.h>


double pi = acos(-1);
int positionTracker( double zWithoutPi ) {
  Controller1.Screen.clearScreen();
  double x, y, z, ch_z;
  double cumulative_z = 0;
  double cur_z = 0;
  std::cout << std::string(50, '\n');
  int l, r, distanceMoved;
  while (true) {
    l = LeftDrive.position(deg);
    r = RightDrive.position(deg);
    distanceMoved = (l + r)/2;
    z = zWithoutPi*pi + fmod((((double)l - (double)r) / 2), 1080)*pi / 540; // avg of l and r signed for position, mod 1080 for full rotation, converted to rad
    x = distanceMoved*cos(z);
    y = distanceMoved*sin(z);
    Controller1.Screen.setCursor(0, 0);
    Controller1.Screen.print("x: %.0f  y: %.0f ", x, y);
    Controller1.Screen.newLine();
    Controller1.Screen.print("ang: %.3f", z/pi);
    Controller1.Screen.newLine();
    Controller1.Screen.print("other ang:?? %.3f", cumulative_z/pi);
    double eff = (LeftDrive.efficiency() + RightDrive.efficiency())/2;
    double cur = (LeftDrive.current() + RightDrive.current())/2;
    double pow = (LeftDrive.power() + RightDrive.power())/2;
    ch_z = z - cur_z;
    cur_z = z;
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(8, 8);
    Brain.Screen.print("%f %f %f", 1.0, 1.0, 1.0); 
    if (ch_z > 0.05 || ch_z < -0.05) {
      cumulative_z += ch_z;
    }
    std::cout << "e: " << eff << "  c: " << cur << "  p: " << pow << "  ch_z: " << ch_z << "  z: " << z/pi << "  cumulative: " << cumulative_z/pi << std::endl;
  }
  return x, y, z;
}

int goTo( int x_0, int y_0, int z_0, int x, int y, int z, int speed ) {
  Drivetrain.driveFor(fwd, x - x_0, vex::distanceUnits::cm);
  vex::thread thread( positionTracker, x, y, z );
  // while (true) 
  // {
  //   Brain.Screen.clearScreen();
  //   Brain.Screen.setCursor(8, 8);
  //   Brain.Screen.print("%f %f %f", 1.0, 1.0, 1.0); //, x_0, y_0, z_0
  // }
  // int distance;
  // drive(distance, distance, speed, speed);
  return 0;
}

void drive( int degL, int degR, int left, int right ) {
  LeftDrive.spinFor(directionType::fwd, degL, rotationUnits::deg, left, velocityUnits::pct);
  RightDrive.spinFor(directionType::fwd, degR, rotationUnits::deg, right, velocityUnits::pct);
}
