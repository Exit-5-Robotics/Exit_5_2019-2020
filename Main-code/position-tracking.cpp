#include "vex.h"
#define MAX_COORDINATE 3600

double pi = acos(-1);

int *positionTracker( double x, double y, double z ) {
  double driveL = LeftDrive.position(deg);
  double driveR = RightDrive.position(deg);
  double avg = (driveL + driveR)/2/600; // each block is about 600 degrees of turning a motor
  double currentX = x + avg*cos(z);
  double currentY = y + avg*sin(z);
  // probably separate
  if ((LeftDrive.current() - LeftDrive.efficiency()) > 0) { // then it's probably against a wall
    if (z < 45 || z > 315) {
      y = 0;
    } else if (z > 45 && z < 135) {
      x = 0;
    } else if (z > 135 && z < 225) {
      y = MAX_COORDINATE;
    } else if (z > 225 && z < 315) {
      x = MAX_COORDINATE;
    }
  }
  return 0;
}

void positionTrack ( int input[] ) {
  positionTracker(0.0, 0.0, 0.0);
}