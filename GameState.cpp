#include "pch.h"
#include "GameState.h"
#include "AssetManager.h"

GameState::GameState(std::string stateName)
{
	_StateName = stateName;
	_StateAssets = new AssetManager(this);
}

GameState::~GameState()
{
	delete _StateAssets;
}

void GameState::Initialize()
{
	_StateAssets->Initialize();
}

void GameState::Start()
{
	_StateAssets->Start();
}

void GameState::Update()
{
	_StateAssets->Update();
}

void GameState::Draw()
{
	_StateAssets->Draw();
}

void GameState::Deinitialize()
{
	_StateAssets->Deinitialize();
}
