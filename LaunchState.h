#pragma once
#include "GameState.h"

class Sprite;

class LaunchState :
    public GameState
{
public:
    LaunchState(std::string stateName) : GameState(stateName)
    {}
    
    ~LaunchState()
    {}

    void Initialize() override;
    void Start() override;
    void Update() override;
    

   

protected:

private:
    Sprite* EilexLogo;
};

