#include "pch.h"
#include "SplashScreenTimer.h"
#include "Game.h"

SplashScreenTimer::SplashScreenTimer() : Timer("SplashScreenTimer", 5, false)
{
	
}

SplashScreenTimer::~SplashScreenTimer()
{
}

void SplashScreenTimer::OnTimerComplete()
{
	Game::RemoveGameState("LaunchState");
	Timer::OnTimerComplete();
}
