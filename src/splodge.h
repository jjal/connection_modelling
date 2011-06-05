#pragma once
class Splodge
{
	static const int NUM_NEIGHBOURS = 8;
	static const int LASTSEEN_MEMORY = 300;
public:
	Splodge* neighbours[NUM_NEIGHBOURS];
	int numUpdates;
	int* currentColor;
	int* newColor;
	int cooldown;
	int numNeighbours;
	int index;
	int numLastSeen;
	int lastSeen[LASTSEEN_MEMORY];
	Splodge(void);
	~Splodge(void);
	virtual void update();
	bool hasSeen(int r, int g, int b);
	void blip();
	void draw(int x, int y);
};

