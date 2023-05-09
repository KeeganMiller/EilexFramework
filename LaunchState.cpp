#include "pch.h"
#include "LaunchState.h"
#include "Game.h"
#include "Sprite.h"
#include "AssetManager.h"
#include <iostream>
#include <raymath.h>
#include "raylib.h"



void LaunchState::Initialize()
{
	GameState::Initialize();
	EilexLogo = new Sprite(_StateAssets->GenerateTexture("Assets/Logos/EilexLogo.png", "EilexLogo"));
	_StateAssets->AddGameObject(EilexLogo);

	Vector2 screenPos = Vector2
	{
		static_cast<float>((Game::WindowWidth / 2) - (EilexLogo->GetTextureWidth() / 2)),
		static_cast<float>((Game::WindowHeight / 2) - (EilexLogo->GetTextureHeight() / 2))
	};

	EilexLogo->SetPosition(screenPos);
	
	
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