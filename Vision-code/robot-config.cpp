#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor motorLeft = motor(PORT1, ratio18_1, false);
motor motorRight = motor(PORT2, ratio18_1, false);
/*vex-vision-config:begin*/
signature Vision3__SIG_PURPLE = signature (1, 865, 2625, 1746, 3009, 7681, 5346, 0, 0);
signature Vision3__SIG_ORANGE = signature (2, 7039, 9083, 8060, -3041, -2081, -2562, 2.3, 0);
signature Vision3__SIG_GREEN = signature (3, -4111, -2801, -3456, -2377, -983, -1680, 2.5, 0);
signature Vision3__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision3__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision3__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision3__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision3 = vision (PORT3, 50, Vision3__SIG_PURPLE, Vision3__SIG_ORANGE, Vision3__SIG_GREEN, Vision3__SIG_4, Vision3__SIG_5, Vision3__SIG_6, Vision3__SIG_7);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}