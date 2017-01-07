#pragma once

enum EventState
{
	OnStart,
	OnUpdate,
	OnFinish,
	Completed
};

class IEvent
{
public:
	IEvent();
	~IEvent();

	virtual void onEventStart() = 0;
	virtual void onEventUpdate() = 0;
	virtual void onEventFinish() = 0;

	virtual void restart() = 0;

	void pause(bool flag);
	bool isPaused() const;

	void forceStop();

	void setDestroyOnFinished(bool flag);
	bool isDestroyable() const;

	void setState(EventState state);
	EventState getState() const;

protected:
	EventState m_eventState = EventState::OnStart;
	bool m_destroyOnFinish = false;
	bool m_paused = false;
};

