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
    /* Initialize peripherals */
    display_init( RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE );
    rdpq_init();
    dfs_init(DFS_DEFAULT_LOCATION);


	StateMachineStart(&GameMachineState, &IntroState);
    while(1) 
    {
    
    	while(!(mainDisplay = display_try_get()));
    	
    	
    	StateMachineUpdate(&GameMachineState);
    	
        // Attach the buffers to the RDP (No z-buffer needed yet)
		rdpq_attach_clear(mainDisplay, NULL);
		
		// Fill the background with white
		rdpq_set_mode_fill(RGBA32(0xFF, 0xFF, 0xFF, 0));
		rdpq_fill_rectangle(0, 0, display_get_width(), display_get_height());
		
		StateMachineDraw(&GameMachineState);
		
		// Send frame buffer to display (TV)
		rdpq_detach_show();
    }
}
