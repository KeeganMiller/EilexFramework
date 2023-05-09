#include "pch.h"
#include "Timer.h"
#include "Game.h"

Timer::Timer()
{
	TimerName = "Timer";
	TimerLength = 4.0;
	Loop = false;
	IsRunning = true;
}

Timer::Timer(std::string timerName, float length, bool loop)
{
	TimerName = timerName;
	TimerLength = length;
	Loop = loop;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	if (!IsRunning)
		return;

	CurrentTime += 1 * Game::GetDeltaTime();
	if (CurrentTime > TimerLength)
	{
		OnTimerComplete();
	}
}

void Timer::Pause()
{
	IsRunning = false;
}


void Timer::Resume()
{
	IsRunning = true;
}

void Timer::OnTimerComplete()
{
	CurrentTime = 0;
	if (!Loop)
		IsRunning = false;
}
