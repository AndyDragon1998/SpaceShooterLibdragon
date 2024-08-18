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
#include "include/input.h"

#include "extern/input.ext"
#include <libdragon.h>

extern StateMachine GameMachineState;

sprite_t* OverSprite;
wav64_t OverMusic;

void OverStart()
{
// Loading Sprites into pointer variables for display
	OverSprite = sprite_load("rom:/Graphics/Images/GameOver.sprite");
	
	wav64_open(&OverMusic, "rom:/Audio/BGM/GameOver.wav64");
	mixer_ch_set_freq(0, OverMusic.wave.frequency);
	
	wav64_play(&OverMusic, 0);
}

void OverUpdate()
{
	if(pad1.inputStart == 1)
	{
		StateMachineChange(&GameMachineState, &MenuState);
	}
}

void OverDraw()
{
	rdpq_set_mode_copy(true);
	// Draw Background
	rdpq_sprite_blit(OverSprite, 0, 0, NULL);
}

void OverEnd()
{
	sprite_free(OverSprite);
}

StateManager OverState =
{
	OverStart,
	OverUpdate,
	OverDraw,
	OverEnd
};
