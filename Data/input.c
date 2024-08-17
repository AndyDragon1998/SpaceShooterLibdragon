/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : User input from all 4 controllers					     */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : input.c	                                                 */
/*                                                                           */
/*****************************************************************************/

#include "include/input.h"
#include <libdragon.h>

#include "extern/input.ext"

struct controller_data keys;

ControllerInput pad1;
ControllerInput pad2;
ControllerInput pad3;
ControllerInput pad4;

void InitializeControllers()
{

}

void inputCalibration()
{

}

void inputUpdate()
{
	controller_scan();
	keys = get_keys_held();
	getGamepadData(0,&pad1);
	getGamepadData(1,&pad2);
	getGamepadData(2,&pad3);
	getGamepadData(3,&pad4);
}

void getGamepadData(int i, ControllerInput* pad)
{
	pad->inputUp = keys.c[i].up;
	pad->inputDown = keys.c[i].down;
	pad->inputLeft = keys.c[i].left;
	pad->inputRight = keys.c[i].right;
	keys = get_keys_down();
	pad->inputL = keys.c[i].L;
	pad->inputR = keys.c[i].R;
	pad->inputA = keys.c[i].A;
	pad->inputB = keys.c[i].B;
	pad->inputZ = keys.c[i].Z;
	pad->inputCUp = keys.c[i].C_up;
	pad->inputCDown = keys.c[i].C_down;
	pad->inputCLeft = keys.c[i].C_left;
	pad->inputCRight = keys.c[i].C_right;
	pad->inputStart = keys.c[i].start;
	pad->analogStickX = keys.c[i].x;
	pad->analogStickY = keys.c[i].y;	
	
}
