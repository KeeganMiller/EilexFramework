#pragma once
#include "GameState.h"
class LaunchState :
    public GameState
{
public:
    LaunchState(std::string stateName) : GameState(stateName)
    {}
    
    ~LaunchState()
    {}

    void Initialize() override;

   

protected:

private:

};

