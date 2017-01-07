#include "EventSystem.h"
#include "CountingEvent.h"
#include <iostream>

void main()
{
	bool runApp = true;
	EventSystem* eventSystem = new EventSystem;

	eventSystem->addEvent(new CountingEvent);
	
	while (runApp)
	{
		eventSystem->update();

		if(eventSystem->getEventCount() == 0)
		{
			runApp = false;
		}
	}

	std::cin.get();
}