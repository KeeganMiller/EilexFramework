#include "pch.h"
#include "AssetManager.h"
#include <raylib.h>
#include "TextureDetails.h"
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

TextureDetails* AssetManager::GenerateTexture(std::string filePath, std::string textureName)
{
	if (filePath == "")
		return nullptr;

	if (textureName == "")
		textureName = "TEXTURE";

	for (auto* texture : _LoadedTextures)
	{
		if (texture->TexturePath == filePath)
		{
			return texture;
		}
	}

	TextureDetails* generatedTexture = new TextureDetails(filePath, textureName, LoadTexture(filePath.c_str()));
	if (generatedTexture->IsValid)
	{
		_LoadedTextures.push_back(generatedTexture);
	}
	return generatedTexture;
}

TextureDetails* AssetManager::GenerateTexture(std::string filePath)
{
	GenerateTexture(filePath, "NewTexture");
}

TextureDetails* AssetManager::RetrieveTexture(std::string fileName)
{
	for (auto* texture : _LoadedTextures)
	{
		if (texture->TextureName == fileName)
		{
			return texture;
		}
	}

	return new TextureDetails();
}
