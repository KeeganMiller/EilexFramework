#include "pch.h"
#include "LaunchState.h"
#include "Game.h"
#include "Sprite.h"
#include "AssetManager.h"
#include <iostream>
#include <raymath.h>
#include "raylib.h"
#include "SplashScreenTimer.h"

float LaunchState::_AplhaLerpTime = 0;


LaunchState::~LaunchState()
{
	delete _EilexLogo;
}

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
	_EilexLogo->Tint = CLITERAL(Color) { 255, 255, 255, 0 };
	

	_ChangeSceneTimer = new SplashScreenTimer();
	_FadeInLogo = true;
	
}

void LaunchState::Start()
{
	Game::ClearColor = DARKGRAY;
}

void LaunchState::Update()
{
	GameState::Update();

	if (_FadeInLogo)
	{
		if (_EilexLogo != nullptr)
		{
			float tintValue = Lerp(0, 255, _AplhaLerpTime);
			_EilexLogo->Tint.a = tintValue;
			_AplhaLerpTime += 0.5f * Game::GetDeltaTime();

			if (_EilexLogo->Tint.a > 254)
				_FadeInLogo = false;
		}
	}
		

	
	if (_ChangeSceneTimer != nullptr)
		_ChangeSceneTimer->Update();
}

void LaunchState::OnChangeScene()
{
	Game::ClearColor = RAYWHITE;
}
