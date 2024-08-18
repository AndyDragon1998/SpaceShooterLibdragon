/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : The body where the main gameplay takes place             */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : gameState.c                                              */
/*                                                                           */
/*****************************************************************************/

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"
#include "include/starfield.h"
#include "include/entities.h"

#include <stdbool.h>
#include <libdragon.h>


/****** User External Files ********/
#include "extern/gameState.ext"

/****** User Table Files ***********/


/****** User Define Files ***********/
#include "define/gameState.def"

bool GameOverBoolean;

wav64_t GameMusic;

void GameStart()
{
	initializeStarfield();
	initializeEntities();
	
	wav64_open(&GameMusic, "rom:/Audio/BGM/Labyrinth-of-Time.wav64");
	mixer_ch_set_freq(0, GameMusic.wave.frequency);
	
	wav64_play(&GameMusic, 0);
	GameOverBoolean = false;
	
}

void GameUpdate()
{
	updateStarfield();
	UpdateInput();
	updateEntities();
	
	if(GameOverBoolean == true)
	{
		StateMachineChange(&GameMachineState, &OverState);
	}
}

void GameDraw()
{
	rdpq_set_mode_copy(true);
	drawStarfield();
	drawEntities();
}

void GameEnd()
{
	
}

StateManager GameState =
{
	GameStart,
	GameUpdate,
	GameDraw,
	GameEnd
};
