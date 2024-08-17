#ifndef GAMEPADINPUT
#define GAMEPADINPUT

#include <stdbool.h>

typedef struct
{
	int inputUp;
	int inputDown;
	int inputLeft;
	int inputRight;
	int inputL;
	int inputR;
	int inputA;
	int inputB;
	int inputZ;
	int inputCUp;
	int inputCDown;
	int inputCLeft;
	int inputCRight;
	int inputStart;
	int analogStickX;
	int analogStickY;
}ControllerInput;

void inputCalibration();
void inputUpdate();
void getGamepadData(int i, ControllerInput* pad);

#endif
