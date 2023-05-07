#include "pch.h"
#include "AssetManager.h"
#include "GameObject.h"

AssetManager::AssetManager(GameState* state)
{
	_OwningState = state;
}

AssetManager::~AssetManager()
{
	for (auto* go : _ObjectsInScene)
	{
		delete go;
	}
}

void AssetManager::Initialize()
{
}

void AssetManager::Start()
{
	for (auto* go : _ObjectsInScene)
	{
		go->Start();
	}
}

void AssetManager::Update()
{
	for (auto* go : _ObjectsInScene)
	{
		go->Update();
	}
}

void AssetManager::Draw()
{
	for (auto* go : _ObjectsInScene)
	{
		go->Draw();
	}
}

void AssetManager::Deinitialize()
{
	for (auto* go : _ObjectsInScene)
	{
		go->Destroy();
	}
}

void AssetManager::AddGameObject(GameObject* go)
{
}

void AssetManager::RemoveGameObject(GameObject* go)
{
}
