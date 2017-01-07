#pragma once

#include <iostream>
#include <string>

#include "IEvent.h"

class CountingEvent :	public IEvent
{
public:
	CountingEvent();
	~CountingEvent();

	// Inherited via IEvent
	virtual void onEventStart() override;
	virtual void onEventUpdate() override;
	virtual void onEventFinish() override;
	virtual void restart() override;

private:
	int m_counter = 0;
	int m_totalCounter = 10;
};

