#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftWheel = motor(PORT12, ratio18_1, true);
motor rightWheel = motor(PORT20, ratio18_1, false);
/*vex-vision-config:begin*/
signature Vision__SIG_ORANGE = signature (1, 4119, 8569, 6344, -3283, -2355, -2819, 1.4, 0);
signature Vision__SIG_2 = signature (2, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision = vision (PORT14, 50, Vision__SIG_ORANGE, Vision__SIG_2, Vision__SIG_3, Vision__SIG_4, Vision__SIG_5, Vision__SIG_6, Vision__SIG_7);
/*vex-vision-config:end*/
motor MiddleWheel = motor(PORT13, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}