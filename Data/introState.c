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
    int fp = dfs_open(TESTYIMAGEPATH);
    IntroSprite = malloc(dfs_size(fp));
    dfs_read( IntroSprite, 1, dfs_size(fp),fp);
    dfs_close(fp);
}

void IntroUpdate()
{

}

void IntroDraw()
{
 	surface_t* disp = display_get();
       
    /*Fill the screen */
    graphics_fill_screen( disp, 0xFFFFFFFF );

    /* Set the text output color */
	graphics_set_color( 0x0, 0xFFFFFFFF );
	
	/* Display a stationary sprite to demonstrate backwards compatibility */
    graphics_draw_sprite_trans( disp, 50, 50, IntroSprite );

	/* Force backbuffer flip */
    display_show(disp);
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
