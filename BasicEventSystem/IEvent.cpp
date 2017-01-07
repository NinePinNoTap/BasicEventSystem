#include "IEvent.h"



IEvent::IEvent()
{
}


IEvent::~IEvent()
{
}

void IEvent::pause(bool flag)
{
	m_paused = flag;
}

bool IEvent::isPaused() const
{
	return m_paused;
}

void IEvent::forceStop()
{
	m_eventState = EventState::OnFinish;
}

void IEvent::setDestroyOnFinished(bool flag)
{
	m_destroyOnFinish = flag;
}

bool IEvent::isDestroyable() const
{
	return m_eventState == EventState::Completed && m_destroyOnFinish;
}

void IEvent::setState(EventState state)
{
	m_eventState = state;
}

EventState IEvent::getState() const
{
	return m_eventState;
}
