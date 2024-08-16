/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : The body where the main menu takes place	             */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : menuState.c                                              */
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
#include "extern/menuState.ext"

/****** User Define Files ***********/
#include "define/menuState.def"

sprite_t* MenuSprite;
wav64_t  MenuMusic;
void MenuStart()
{
	MenuSprite = sprite_load("rom:/Graphics/Images/Title.sprite");
	
	wav64_open(&MenuMusic, "rom:/Audio/BGM/SpaceBass.wav64");
}

void MenuUpdate()
{
	wav64_play(&MenuMusic, 0);
}

void MenuDraw()
{
	rdpq_set_mode_copy(true);
	rdpq_sprite_blit(MenuSprite, 0, 0, NULL);
}

void MenuEnd()
{

}

StateManager MenuState =
{
	MenuStart,
	MenuUpdate,
	MenuDraw,
	MenuEnd
};
