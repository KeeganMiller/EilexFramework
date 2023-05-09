#include "pch.h"
#include "Game.h"
#include <raylib.h>
#include "GameState.h"
#include "LaunchState.h"


int Game::WindowHeight = 0;
int Game::WindowWidth = 0;
std::string Game::WindowTitle = "Raylib - Eilex Framework";
bool Game::IsFullscreen = false;
bool Game::_IsRunning = true;
Color Game::ClearColor = RAYWHITE;
std::vector<GameState*> Game::_ActiveStates;
float Game::_DeltaTime = 0;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
	_ActiveStates.push_back(new LaunchState("LaunchState"));
	if (_ActiveStates.size() > 0)
	{
		for (auto state : _ActiveStates)
		{
			state->Initialize();
		}
	}
}

void Game::Start()
{
	if (_ActiveStates.size() > 0)
	{
		for (auto state : _ActiveStates)
		{
			state->Start();
		}
	}
}

void Game::Update()
{
	_DeltaTime = GetFrameTime();
	if (_ActiveStates.size() > 0)
	{
		for (auto state : _ActiveStates)
		{
			state->Update();
		}
	}
}

void Game::Draw()
{
	if (_ActiveStates.size() > 0)
	{
		for (auto state : _ActiveStates)
		{
			state->Draw();
		}
	}
}

void Game::Deintialize()
{
	if (_ActiveStates.size() > 0)
	{
		for (auto state : _ActiveStates)
		{
			state->Deinitialize();
		}
	}
}

void Game::CreateWindow(int windowWidth, int windowHeight, std::string windowTitle, bool fullscreen)
{
	WindowWidth = windowWidth;
	WindowHeight = windowHeight;
	WindowTitle = windowTitle;
	IsFullscreen = fullscreen;

	InitWindow(WindowWidth, WindowHeight, windowTitle.c_str());
	SetTargetFPS(60);

	ToggleWindowFullscreen(IsFullscreen);

}

void Game::ToggleWindowFullscreen(bool fullscreen)
{
	if (fullscreen && !IsWindowFullscreen)
	{
		ToggleFullscreen();
	}
	else if (!fullscreen && IsWindowFullscreen)
	{
		ToggleFullscreen();
	}
}

void Game::AddGameState(GameState* state)
{
	_ActiveStates.push_back(state);
	state->Initialize();
	state->Start();
	
}

void Game::RemoveGameState(GameState* state)
{
	int index = -1;
	for (int i = 0; i < _ActiveStates.size(); ++i)
	{
		if (state == _ActiveStates[i])
		{
			index = i;
			break;
		}
	}

	if (index > -1)
	{
		_ActiveStates.erase(_ActiveStates.begin() + index);
		state->Deinitialize();

		delete state;
	}
	
}

void Game::RemoveGameState(std::string stateName)
{
	int index = -1;
	for (int i = 0; i < _ActiveStates.size(); ++i)
	{
		if (_ActiveStates[i]->GetStateName() == stateName)
		{
			index = i;
			break;
		}
	}

	if (index > -1)
	{
		GameState* state = _ActiveStates[index];
		if (state != nullptr)
		{
			state->Deinitialize();
			_ActiveStates.erase(_ActiveStates.begin() + index);

			delete state;
		}
	}
}

void Game::CloseGame()
{
	_IsRunning = false;

	CloseWindow();
}


