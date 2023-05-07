#include "pch.h"
#include "Game.h"
#include <raylib.h>



int Game::WindowHeight = 0;
int Game::WindowWidth = 0;
std::string Game::WindowTitle = "Raylib - Eilex Framework";
bool Game::IsFullscreen = false;
bool Game::_IsRunning = true;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Initialize()
{
}

void Game::Start()
{
}

void Game::Update()
{
}

void Game::Draw()
{
}

void Game::Deintialize()
{
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

void Game::CloseGame()
{
	_IsRunning = false;

	CloseWindow();
}


