#pragma once
#include "splodge.h"
class Connector :
	public Splodge
{
	static const int CONNECTOR_COOLDOWN = 10;
public:
	Connector(void);
	virtual void update();
	~Connector(void);
};

