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

int main(void)
{
    /* Initialize peripherals */
    display_init( RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE );
    dfs_init( DFS_DEFAULT_LOCATION );
    rdpq_init();
    controller_init();
    timer_init();


	StateMachineStart(&GameMachineState, &IntroState);
    while(1) 
    {
    
    	StateMachineUpdate(&GameMachineState);
        
		StateMachineDraw(&GameMachineState);

    }
}
