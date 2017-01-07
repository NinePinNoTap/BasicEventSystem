#pragma once

#include <algorithm>
#include <vector>
#include "IEvent.h"

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	void update();

	void addEvent(IEvent* event);

	void destroyAllEvents();

	int getEventCount() const;

private:
	std::vector<IEvent*> m_events;
	std::vector<IEvent*>::iterator m_iterator;
};

