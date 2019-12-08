#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision2__SIG_1 = signature (1, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision2__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision2 = vision (PORT2, 50, Vision2__SIG_1, Vision2__SIG_2, Vision2__SIG_3, Vision2__SIG_4, Vision2__SIG_5, Vision2__SIG_6, Vision2__SIG_7);
/*vex-vision-config:end*/
motor LeftDriveSmart = motor(PORT12, ratio18_1, false);
motor RightDriveSmart = motor(PORT20, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 130, mm, 1);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}