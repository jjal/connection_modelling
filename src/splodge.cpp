#include "Splodge.h"
#include "ofMain.h"

Splodge::Splodge(void)
{ 
	currentColor = new int[3];
	newColor = new int[3];
	for(int i = 0;i<3;i++)
		currentColor[i] = newColor[i] = 0;
	numNeighbours = 0;
	numLastSeen = 0;
}

void Splodge::update()
{}

void Splodge::draw(int x, int y)
{
	
	//let's draw a circle:
	ofSetColor(currentColor[0],currentColor[1],currentColor[2]);
	float radius = 10;
	ofFill();		// draw "filled shapes"
	ofCircle(x,y,radius);
}

bool Splodge::hasSeen(int r, int g, int b)
{
	for(int i=0; i<numLastSeen; i+=3)
	{
		if(lastSeen[i] == r && lastSeen[i+1] == g && lastSeen[i+2] == b)
			return true;
	}
	return false;
}

void Splodge::blip()
{
	bool isNewColor = false;
	for(int i = 0;i<3;i++)
	{
		if(newColor[i] != currentColor[i])
			isNewColor = true;
		currentColor[i] = newColor[i];
	}
	if(isNewColor)
	{
		for(int i=0;i<3;i++)
			lastSeen[numLastSeen+i] = currentColor[i];
		numLastSeen +=3;
		if(numLastSeen >= LASTSEEN_MEMORY)
			numLastSeen = 0;
	}
}

Splodge::~Splodge(void)
{
}
