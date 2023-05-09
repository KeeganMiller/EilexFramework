#pragma once
#include <string>

class Timer
{
public:
	Timer();
	Timer(std::string timerName, float length, bool loop);
	~Timer();

	virtual void Update();
	virtual void Pause();
	virtual void Resume();

	std::string TimerName;
	float TimerLength;
	float CurrentTime;
	bool Loop;
	bool IsRunning;

protected:
	virtual void OnTimerComplete();
	

};

