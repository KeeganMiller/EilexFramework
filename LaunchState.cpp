#include "pch.h"
#include "LaunchState.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "AssetManager.h"
#include <iostream>



void LaunchState::Initialize()
{
	GameState::Initialize();
	testObject = new Sprite();
	_StateAssets->AddGameObject(testObject);
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