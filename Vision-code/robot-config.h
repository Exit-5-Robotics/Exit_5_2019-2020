using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor leftWheel;
extern motor rightWheel;
extern signature Vision__SIG_ORANGE;
extern signature Vision__SIG_2;
extern signature Vision__SIG_3;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;
extern motor MiddleWheel;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );