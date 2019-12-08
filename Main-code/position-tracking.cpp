#include "vex.h"

double pi = acos(-1);
int positionTracker(double zWithoutPi ) {
  Controller1.Screen.clearScreen();
  double x, y, z;
  int l, r, distanceMoved;
  while (true) {
  l = LeftDrive.position(deg);
  r = RightDrive.position(deg);
  distanceMoved = (l + r)/2;
  z = zWithoutPi*pi + fmod((((double)l - (double)r) / 2), 1080)*pi / 540; // avg of l and r signed for position, mod 1080 for full rotation, converted to rad
  x = distanceMoved*cos(z);
  y = distanceMoved*sin(z);
  Controller1.Screen.setCursor(0, 0);
  Controller1.Screen.print("xDeg: %.0f  yDeg: %.0f", x, y);
  Controller1.Screen.newLine();
  Controller1.Screen.print("angle: %.3f", z/pi); // tends to drift
  Controller1.Screen.newLine();
  Controller1.Screen.print("%f", LeftDrive.efficiency()); // will try doing smth with efficiency, power, current, velocity for motor
  }
  return 0;
}
