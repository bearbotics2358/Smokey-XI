#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <CompPrefs.h>
#include <CompPrefsAutonomous.h>
#include <DiffDrive.h>
#include <Collector.h>
#include <CollectorArm.h>
#include <JrimmyGyro.h>
#include <AutonomousHelper.h>
#include <Underglow.h>
#include <UltrasonicSerial.h>
#include <Gunnar.h>


enum AutoStateU0 {
	kAutoIdleU0 = 0,
	kMoveToSwitchU0,
};

enum AutoStateU1 {
	kAutoIdleU1 = 0,
	kMoveToSwitchU1,
	kMoveArmU1,
	kReleaseCubeU1
};

enum AutoStateU2 {
	kAutoIdleU2 =0,
	kMoveToSideOfSwitchU2,
	kTurnNinetyU2,
	kMoveToEdgeOfSwitchU2,
	kMoveArmU2,
	kReleaseCubeU2,
};

enum AutoStateU3 {
	kAutoIdleU3 = 0,
	kMoveToSideOfScaleU3,
	kTurnNinetyU3,
	kMoveToEdgeOfScaleU3,
	kMoveArmU3,
	kReleaseCubeU3,
};

enum AutoStateU4
{
	kAutoIdleU4 = 0,
	kMoveHalfToSwitchU4,
	kTurnNinetyU4,
	kCenterWithSwitchU4,
	kTurnNinetyOppositeU4,
	kMoveToFrontOfSwitchU4,
	kMoveArmU4,
	kReleaseCubeU4,
};

enum AutoStateU5
{
	kAutoIdleU5 = 0,
	kMoveTopOfSwitchU5,
	kTurnNinetyU5,
	kMoveFlushWithScaleU5,
	kTurnNinetyOppositeU5,
	kMoveToFrontOfScaleU5,
	kMoveArmU5,
	kReleaseCubeU5,
};

enum AutoStateU6
{
	kAutoIdleU6 = 0,
	kMoveForwardThirdU6,
	kTurnFourtyFiveU6,
	kMoveDiagU6,
	kTurnFourtyFiveOppositeU6,
	kMoveToFrontOfSwitchU6,
	kMoveArmU6,
	kReleaseCubeU6,
};

enum AutoStateU7
{
	kAutoIdleU7 = 0,
	kMoveToScaleU7,
	kTurnNinetyU7,
	kMoveToEdgeOfScaleU7,
	kMoveArmScaleU7,
	kReleaseCubeScaleU7,
	kTurnToSwitchU7,
	kMoveToSwitchU7,
	kMoveArmRestU7,
	kTurnToCubeGunnarU7,
	kCollectCubeU7,
	kMoveBackU7,
	kMoveArmSwitchU7,
	kMoveForwardSwitchU7,
	kReleaseCubeSwitchU7
};

enum AutoStateU8
{
	kAutoIdleU8 = 0,
	kMoveToScaleU8,
	kTurnNinetyU8,
	kMoveToEdgeOfScaleU8,
	kMoveArmScaleU8,
	kReleaseCubeScaleU8,
	kTurnToSwitchU8,
	kMoveToSwitchU8,
	kMoveArmRestU8,
	kCollectCubeU8,
	kMoveToScaleDiagU8,
	kTurnToScaleDiagU8,
	kMoveArmScaleDiagU8,
	kReleaseCubeScaleDiagU8
};

enum AutoStateCol
{
	kAutoIdleCol = 0,
	kMoveDistCol,
	kMoveArmRestCol,
	kTurnToCubeGunnarCol,
	kCollectCubeCol,
	kMoveBackCol,
	kMoveArmSwitchCol,
	kMoveForwardCol,
	kReleaseCubeSwitchCol
};

enum AutoStateEyeDemo
{
	kAutoIdleEyeDemo = 0,
	kMoveArmRestEyeDemo,
	kTurnToCubeGunnarEyeDemo,
	kCollectCubeEyeDemo,
	kMoveArmSwitchEyeDemo,
	kReleaseCubeSwitchEyeDemo
};

enum AutoStateVx {
	kAutoIdlex = 0,
	kMoveToSwitchInitx,
	kMoveToSwitchx,
};
enum AutoStateV0 {
	kMoveToSwitch0 = 0,
	kAutoIdle0
};
enum AutoStateV1 {
	kMoveToSwitch1 = 0,
	kMoveArm1,
	kReleaseCube1,
	kAutoIdle1
};
enum AutoStateV2 {
	kMoveToSideOfSwitch = 0,
	kTurnLeft2,
	kMoveToEdgeOfSwitch,
	kMoveArm2,
	kReleaseCube2,
	kAutoIdle2
};
enum AutoStateV3 {
	kMoveToSideOfScale = 0,
	kTurnLeft3,
	kMoveToEdgeOfScale,
	kMoveArm3,
	kReleaseCube3,
	kAutoIdle3
};
enum AutoStateV4
{
	kMoveHalfToSwitch = 0,
	kTurnRight4,
	kMoveFlushWithSwitch,
	kTurnLeft4,
	kMoveToFrontOfSwitch,
	kMoveArm4,
	kReleaseCube4,
	kAutoIdle4
};
enum AutoStateV5
{
	kMoveTopOfSwitch = 0,
	kTurnRight5,
	kMoveFlushWithScale,
	kTurnLeft5,
	kMoveToFrontOfScale,
	kMoveArm5,
	kReleaseCube5,
	kAutoIdle5
};


class Autonomous
{
 public:
	Autonomous(AutonomousHelper &AutoBot, Joystick &ButtonBox, CollectorArm &CollectorArm, DiffDrive &DiffDrive, JrimmyGyro &Gyro, Underglow &Underglow, UltrasonicSerial &UltraSoul, Gunnar &Gunnar);
	virtual ~Autonomous() = default;
	void Init();
	void UpdateGameData();
	void DecidePath();
	void DecidePath(int intent);
	int GetCurrentPath();
	void StartPathMaster();
	void StartPathMaster(int path);
	void PeriodicPathMaster();
	void PeriodicPathMaster(int path);
	void AutonomousPeriodicVx();
	void AutonomousStartU0();
	void AutonomousPeriodicU0();
	void AutonomousPeriodicV0();
	void AutonomousStartU1();
	void AutonomousPeriodicU1();
	void AutonomousPeriodicV1();
	void AutonomousStartU2();
	void AutonomousPeriodicU2();
	void AutonomousPeriodicV2();
	void AutonomousStartU3();
	void AutonomousPeriodicU3();
	void AutonomousPeriodicV3();
	void AutonomousStartU4();
	void AutonomousPeriodicU4();
	void AutonomousPeriodicV4();
	void AutonomousStartU5();
	void AutonomousPeriodicU5();
	void AutonomousPeriodicV5();
	void AutonomousStartU6();
	void AutonomousPeriodicU6();
	void AutonomousStartU7();
	void AutonomousStartU7TESTING();
	void AutonomousPeriodicU7();
	void AutonomousStartU8();
	void AutonomousPeriodicU8();
	void AutonomousStartCol();
	void AutonomousPeriodicCol();
	void AutonomousStartEyeDemo();
	void AutonomousPeriodicEyeDemo();


 private:
	AutonomousHelper &a_AutoBot;

	Joystick &a_ButtonBox;

	CollectorArm &a_CollectorArm;

	DiffDrive &a_DiffDrive;

	JrimmyGyro &a_Gyro;

	Underglow &a_Underglow;

	UltrasonicSerial &a_UltraSoul;

	Gunnar &a_Gunnar;

	AutoStateVx a_AutoStateVx;
	AutoStateU0 a_AutoStateU0;
	AutoStateV0 a_AutoStateV0;
	AutoStateU1 a_AutoStateU1;
	AutoStateV1 a_AutoStateV1;
	AutoStateU2 a_AutoStateU2;
	AutoStateV2 a_AutoStateV2;
	AutoStateU3 a_AutoStateU3;
	AutoStateV3 a_AutoStateV3;
	AutoStateU4 a_AutoStateU4;
	AutoStateV4 a_AutoStateV4;
	AutoStateU5 a_AutoStateU5;
	AutoStateV5 a_AutoStateV5;
	AutoStateU6 a_AutoStateU6;
	AutoStateU7 a_AutoStateU7;
	AutoStateU8 a_AutoStateU8;
	AutoStateCol a_AutoStateCol;
	AutoStateEyeDemo a_AutoStateEyeDemo;

	float a_AngleSaved;
	double a_time_state = 0;
	int autoPathMaster;

	bool b_left = false;
	bool b_center = false;
	bool b_right = false;
	bool special = false;

	float x_T = 0.0;
	float x_Dist = 0.0;

	int playerStation = -1;
	bool blue = false;
	bool ourSwitch = false;
	bool scale = false;
	bool oppSwitch = false;

	/* Example internal auto function
	 * bool DriveStraight(int distance);*/

};

#endif
