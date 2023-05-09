#pragma once
#include "Timer.h"
class SplashScreenTimer :
    public Timer
{
public:
    SplashScreenTimer();
    ~SplashScreenTimer();

protected:
    void OnTimerComplete() override;
};

