#pragma once
#include <string>

typedef void(*TimerCompleteFunction)();
class Timer
{
public:
	Timer();
	Timer(std::string timerName, float length, bool loop, TimerCompleteFunction timerComplete);
	~Timer();

	void Update();
	void Pause();
	void Resume();
	void OnTimerComplete();

	std::string TimerName;
	TimerCompleteFunction TimerComplete;
	float TimerLength;
	float CurrentTime;
	bool Loop;
	bool IsRunning;

private:
	

};

