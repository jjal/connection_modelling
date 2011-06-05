#pragma once
#include "splodge.h"
class Initiator :
	public Splodge
{
	static const int INITIATOR_COOLDOWN = 100;
public:
	Initiator(void);
	virtual void update();
	~Initiator(void);
};

