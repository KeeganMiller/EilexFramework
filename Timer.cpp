#include "pch.h"
#include "Timer.h"
#include "Game.h"
#include <raylib.h>
#include <iostream>

Timer::Timer()
{
	TimerName = "Timer";
	CurrentTime = 0;
	TimerLength = 4.0;
	Loop = false;
	IsRunning = true;
}

Timer::Timer(std::string timerName, float length, bool loop)
{
	TimerName = timerName;
	TimerLength = length;
	Loop = loop;
	CurrentTime = 0;
	IsRunning = true;
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
