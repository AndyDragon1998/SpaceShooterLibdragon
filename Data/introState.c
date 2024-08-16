/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : The body where the main gameplay takes place             */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : introState.c                                             */
/*                                                                           */
/*****************************************************************************/

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

/****** User External Files ********/
#include "extern/introState.ext"

/****** User Table Files ***********/


/****** User Define Files ***********/
#include "define/introState.def"

// sprite variables
sprite_t *IntroSprite;

int introTimer;

void IntroStart()
{
	// Loading sprites in memory
    IntroSprite = sprite_load("rom:/Intro.sprite");
    introTimer = 0;
}

void IntroUpdate()
{
	introTimer++;
	
	if(introTimer > 300)
	{
		StateMachineChange(&GameMachineState, &MenuState);
	}
}

void IntroDraw()
{
 	rdpq_set_mode_copy(true);
	rdpq_sprite_blit(IntroSprite, 0, 0, NULL);
}

void IntroEnd()
{

}

StateManager IntroState =
{
	IntroStart,
	IntroUpdate,
	IntroDraw,
	IntroEnd
};
