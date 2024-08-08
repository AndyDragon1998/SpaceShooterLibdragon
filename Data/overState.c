/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : Game over state right when player dies		             */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : overState.c                                              */
/*                                                                           */
/*****************************************************************************/

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"

extern StateMachine GameMachineState;

void OverStart()
{

}

void OverUpdate()
{

}

void OverDraw()
{

}

void OverEnd()
{

}

StateManager OverState =
{
	OverStart,
	OverUpdate,
	OverDraw,
	OverEnd
};
