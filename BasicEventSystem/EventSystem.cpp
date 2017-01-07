#include "EventSystem.h"

EventSystem::EventSystem()
{
}

EventSystem::~EventSystem()
{
	destroyAllEvents();
}

void EventSystem::update()
{
	if (m_events.size() == 0)
		return;
	
	// Update events
	for (m_iterator = m_events.begin(); m_iterator != m_events.end(); m_iterator++)
	{
		IEvent* selectedEvent = static_cast<IEvent*>(*m_iterator);

		if (selectedEvent->isPaused())
			continue;

		switch (selectedEvent->getState())
		{
			case EventState::OnStart:
				selectedEvent->onEventStart();
				selectedEvent->setState(EventState::OnUpdate);
				break;

			case EventState::OnUpdate:
				selectedEvent->onEventUpdate();
				break;

			case EventState::OnFinish:
				selectedEvent->onEventFinish();
				break;
		}
	}

	// Destroy events
	for (m_iterator = m_events.begin(); m_iterator != m_events.end(); )
	{
		IEvent* selectedEvent = static_cast<IEvent*>(*m_iterator);

		if (selectedEvent->isDestroyable())
		{
			m_iterator = m_events.erase(m_iterator);
			delete selectedEvent;
			selectedEvent = 0;
		}
		else
		{
			m_iterator++;
		}
	}
}

void EventSystem::addEvent(IEvent * newEvent)
{
	m_events.push_back(newEvent);
}

void EventSystem::destroyAllEvents()
{
	if (m_events.size() == 0)
		return;

	for (m_iterator = m_events.begin(); m_iterator != m_events.end(); )
	{
		IEvent* selectedEvent = static_cast<IEvent*>(*m_iterator);

		if (selectedEvent->isDestroyable())
		{
			m_iterator = m_events.erase(m_iterator);
			delete selectedEvent;
			selectedEvent = 0;
		}
		else
		{
			m_iterator++;
		}
	}
}

int EventSystem::getEventCount() const
{
	return m_events.size();
}
