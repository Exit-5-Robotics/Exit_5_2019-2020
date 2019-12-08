using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor Motor1;
extern motor Motor2;
extern signature Vision3__SIG_PURPLE;
extern signature Vision3__SIG_ORANGE;
extern signature Vision3__SIG_GREEN;
extern signature Vision3__SIG_4;
extern signature Vision3__SIG_5;
extern signature Vision3__SIG_6;
extern signature Vision3__SIG_7;
extern vision Vision3;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );