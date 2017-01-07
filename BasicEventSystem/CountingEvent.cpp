#include "CountingEvent.h"

CountingEvent::CountingEvent()
{
}


CountingEvent::~CountingEvent()
{
}

void CountingEvent::onEventStart()
{
	std::cout << "Counting Event Started!" << std::endl;
}

void CountingEvent::onEventUpdate()
{
	m_counter++;
	std::cout << std::to_string(m_counter) << std::endl;
	if (m_counter >= m_totalCounter)
	{
		setState(EventState::OnFinish);
	}
}

void CountingEvent::onEventFinish()
{
	std::cout << "Counting Event Finished!" << std::endl;
	setState(EventState::Completed);
}

void CountingEvent::restart()
{
	std::cout << "Counting Event Restarted!" << std::endl;
}
