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

#include "include/input.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>

/****** User External Files ********/
#include "extern/menuState.ext"
#include "extern/input.ext"

/****** User Define Files ***********/
#include "define/menuState.def"

sprite_t* MenuSprite;
sprite_t* TextySprite;

// Position sprites for Texty
int textyX, textyY;
int textySpeed;

wav64_t  MenuMusic;
void MenuStart()
{
	// Loading Sprites into pointer variables for display
	MenuSprite = sprite_load("rom:/Graphics/Images/Title.sprite");
	TextySprite = sprite_load("rom:/Graphics/Sprites/Texty.sprite");
	
	textyX = 50;
	textyY = 50;
	textySpeed = 3;
	
	wav64_open(&MenuMusic, "rom:/Audio/BGM/SpaceBass.wav64");
	mixer_ch_set_freq(0, MenuMusic.wave.frequency);
	
	wav64_play(&MenuMusic, 0);
}

void MenuUpdate()
{
	// Move Texty box in the speed of the variable
	textyX += textySpeed;
	
	// We use logical operator to see if Text position X is within certain area.
	// That way if it's out of certain area, then we reverse X movment
	if(textyX > 300 || textyX < 20)
	{
		textySpeed = textySpeed * -1;
	}
	
	if(pad1.inputStart == 1)
	{
		StateMachineChange(&GameMachineState, &GameState);
	}

	
}

void MenuDraw()
{
	rdpq_set_mode_copy(true);
	// Draw Background
	rdpq_sprite_blit(MenuSprite, 0, 0, NULL);
	
	// Draw the text box
	rdpq_sprite_blit(TextySprite,textyX,textyY,NULL);
	
}

void MenuEnd()
{
	sprite_free(MenuSprite);
	sprite_free(TextySprite);
}

StateManager MenuState =
{
	MenuStart,
	MenuUpdate,
	MenuDraw,
	MenuEnd
};
