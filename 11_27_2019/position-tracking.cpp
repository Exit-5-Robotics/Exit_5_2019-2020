#include "vex.h"
#define MAX_COORDINATE 3600

double pi = acos(-1);

int *positionTracker( double x, double y, double z ) {
  double driveL = LeftDrive.position(deg);
  double driveR = RightDrive.position(deg);
  double avg = (driveL + driveR)/2/600; // each block is about 600 degrees of turning a motor
  if (avg < 10 && avg > -10) { // might have turned
    z;
  }
  x += avg*cos(z);
  y += avg*sin(z);
  // probably separate
  if ((LeftDrive.current() - LeftDrive.efficiency()) > 0) { // then it's probably against a wall or stuck
    if (z >= pi/4 && z < 3*pi/4 ) { // up
      y = MAX_COORDINATE;
    } else if (z >= 3*pi/4 && z < 5*pi/4) { // left
      x = 0;
    } else if (z >= 5*pi/4 && z < 7*pi/4) { // down
      y = 0;
    } else if (z >= 7*pi/4 || z < pi/4) { // right
      x = MAX_COORDINATE;
    }
  }
  return 0;
}

void positionTrack ( int input[] ) {
  positionTracker(0.0, 0.0, 0.0);
}
