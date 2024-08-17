/*****************************************************************************/
/*  Author        : Дракончик												 */
/*  Machine       : Nintendo 64      										 */
/*  Library		  : Libdragon												 */
/*  Language      : GNU C                                                    */
/*                                                                           */
/*  File Contents : Star field background that moves in the back		     */
/*  File Attribute: SOURCE                                                   */
/*  File Name     : starfield.c	                                             */
/*                                                                           */
/*****************************************************************************/

#include <libdragon.h>
#include "include/starfield.h"

#define SFBGHEIGHT 510

int sfX1, sfX2;
int sfY1, sfY2;
int sfScrollSpeed;

sprite_t* sfSprite;

void initializeStarfield()
{
	// Loading sprites in memory
    sfSprite = sprite_load("rom:/Graphics/Backgrounds/SF.sprite");
    
    // setting up default values for background
    sfX1 = 0;
    sfX2 = 0;
    sfY1 = 0;
    sfY2 = SFBGHEIGHT * -1;
    sfScrollSpeed = 1;
}

void updateStarfield()
{
	sfY1 += sfScrollSpeed;
	sfY2 += sfScrollSpeed;
	
	if(sfY1 > SFBGHEIGHT)
	{
		sfY1 = SFBGHEIGHT * -1;
	}
	
	if(sfY2 > SFBGHEIGHT)
	{
		sfY2 = SFBGHEIGHT * -1;
	}
}

void drawStarfield()
{
	rdpq_sprite_blit(sfSprite, sfX1, sfY1, NULL);
	rdpq_sprite_blit(sfSprite, sfX2, sfY2, NULL);
}

void unloadStarfield()
{
	sprite_free(sfSprite);
}
