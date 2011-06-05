#include "Connector.h"
#include <stdlib.h>
#include <time.h>

Connector::Connector(void)
{
}

void Connector::update()
{
	if(cooldown-- <= 0)
	{
		int j=0;
		Splodge* changedSplodges[8];
		for(int i=numNeighbours-1;i>=0;i--)
		{
			if((currentColor[0] != neighbours[i]->currentColor[0] ||
				currentColor[1] != neighbours[i]->currentColor[1] ||
				currentColor[2] != neighbours[i]->currentColor[2]) && !hasSeen(neighbours[i]->currentColor[0],neighbours[i]->currentColor[1],neighbours[i]->currentColor[2]))
			{
				changedSplodges[j++] = neighbours[i];
			}
		}
		if(j > 0 && newColor[0] == currentColor[0] && newColor[1] == currentColor[1] && newColor[2] == currentColor[2])
		{
			int copy = rand() % j;
			newColor[0] = changedSplodges[copy]->currentColor[0];
			newColor[1] = changedSplodges[copy]->currentColor[1];
			newColor[2] = changedSplodges[copy]->currentColor[2];
			}
		//delete[] changedSplodges;
		cooldown = CONNECTOR_COOLDOWN;
	}
}


Connector::~Connector(void)
{
}
