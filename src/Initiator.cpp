#include "Initiator.h"
#include <stdlib.h>
#include <time.h>

Initiator::Initiator(void)
{

}

void Initiator::update()
{
	if(cooldown-- <= 0)
	{
			//srand(time(NULL)); //get a random node and copy its color
			newColor[0] = rand() % 255;
			newColor[1] = rand() % 255;
			newColor[2] = rand() % 255;
		cooldown = INITIATOR_COOLDOWN;
	}
}

Initiator::~Initiator(void)
{
}
