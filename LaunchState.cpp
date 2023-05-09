#include "pch.h"
#include "LaunchState.h"
#include "Game.h"
#include "Sprite.h"
#include "AssetManager.h"
#include <iostream>
#include <raymath.h>
#include "raylib.h"
#include "SplashScreenTimer.h"



void LaunchState::Initialize()
{
	GameState::Initialize();
	_EilexLogo = new Sprite(_StateAssets->GenerateTexture("Assets/Logos/EilexLogo.png", "EilexLogo"));
	_StateAssets->AddGameObject(_EilexLogo);

	Vector2 screenPos = Vector2
	{
		static_cast<float>((Game::WindowWidth / 2) - (_EilexLogo->GetTextureWidth() / 2)),
		static_cast<float>((Game::WindowHeight / 2) - (_EilexLogo->GetTextureHeight() / 2))
	};

	_EilexLogo->SetPosition(screenPos);
	_EilexLogo->Tint = CLITERAL(Color) { 255, 255, 255, 255 };

	_ChangeSceneTimer = new SplashScreenTimer();
	
}

void LaunchState::Start()
{
	Game::ClearColor = DARKGRAY;
}

void LaunchState::Update()
{
	GameState::Update();
	if (_ChangeSceneTimer != nullptr)
		_ChangeSceneTimer->Update();
}

void LaunchState::OnChangeScene()
{
	Game::ClearColor = RAYWHITE;
}
