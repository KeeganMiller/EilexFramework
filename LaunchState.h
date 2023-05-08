#pragma once
#include "GameState.h"

class GameObject;

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
    GameObject* testObject;
};

