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
	_ObjectsInScene.push_back(go);
	go->Initialize();
	go->Start();
}

void AssetManager::RemoveGameObject(GameObject* go)
{
	int index = -1;
	for (int i = 0; i < _ObjectsInScene.size(); ++i)
	{
		if (go == _ObjectsInScene[i])
		{
			index = i;
			break;
		}
	}

	if (index > -1)
	{
		_ObjectsInScene.erase(_ObjectsInScene.begin() + index);
	}
}
