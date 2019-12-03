using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Tilter;
extern drivetrain Drivetrain;
extern controller Controller1;
extern motor IntakeL;
extern motor IntakeR;
extern motor LeftDrive;
extern motor RightDrive;
extern motor MiddleWheel;
extern motor Arms;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void );