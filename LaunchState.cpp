#include "pch.h"
#include "LaunchState.h"
#include "Game.h"
#include <iostream>

void LaunchState::Initialize()
{
	GameState::Initialize();
	
}

void LaunchState::Start()
{
	Game::ClearColor = DARKGRAY;
}

void LaunchState::Update()
{
	GameState::Update();
	std::cout << "Launch state is updating" << std::endl;
}