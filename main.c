/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : MAIN BODY                                                */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : main.c                                                   */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <libdragon.h>

#include "Data/include/introState.h"
#include "Data/include/menuState.h"
#include "Data/include/gameState.h"
#include "Data/include/overState.h"

#include "Data/include/input.h"

StateMachine GameMachineState;

char *format_type( int accessory )
{
    switch( accessory )
    {
        case ACCESSORY_RUMBLEPAK:
            return "(rumble)";
        case ACCESSORY_MEMPAK:
            return "(memory)";
        case ACCESSORY_VRU:
            return "(vru)";
        default:
            return "(none)";
    }
}

surface_t* mainDisplay;


int main(void)
{
    //Initialize Screen
    display_init( RESOLUTION_640x480, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE );
    rdpq_init();
    controller_init();
    // Initializing File System
    dfs_init(DFS_DEFAULT_LOCATION);

	// Initializing Audio
	audio_init(44100, 3);
	mixer_init(32);
	mixer_ch_set_limits(6, 0, 128000, 0);

	StateMachineStart(&GameMachineState, &IntroState);
    while(1) 
    {
    
    	while(!(mainDisplay = display_try_get()));
    	
    	inputUpdate();
    	
    	StateMachineUpdate(&GameMachineState);
    	
        // Attach the buffers to the RDP (No z-buffer needed yet)
		rdpq_attach_clear(mainDisplay, NULL);
		
		// Fill the background with white
		rdpq_set_mode_fill(RGBA32(0xFF, 0xFF, 0xFF, 0));
		rdpq_fill_rectangle(0, 0, display_get_width(), display_get_height());
		
		StateMachineDraw(&GameMachineState);
		
		// Send frame buffer to display (TV)
		rdpq_detach_show();
		
		if (audio_can_write()) 
		{
		// Select an audio buffer that we can write to
		short *buf = audio_write_begin();
		
		// Write to the audio buffer from the mixer
		mixer_poll(buf, audio_get_buffer_length());
		
		// Tell the audio system that the buffer has
		// been filled and is ready for playback
		audio_write_end();
	}
    }
}
