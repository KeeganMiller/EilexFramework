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
}

void GameState::Start()
{
}

void GameState::Update()
{
}

void GameState::Draw()
{
}

void GameState::Deinitialize()
{
}
