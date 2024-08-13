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


void IntroStart()
{
	// Loading sprites in memory
    IntroSprite = sprite_load("rom:/Graphics/Images/Intro.sprite");
}

void IntroUpdate()
{

}

void IntroDraw()
{
 	// Attach and clear the screen
    surface_t *disp = display_get();
    rdpq_attach_clear(disp, NULL);

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
