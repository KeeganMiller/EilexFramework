#pragma once
#include <vector>
#include "GameState.h"

class GameObject;
class TextureDetails;

class AssetManager
{
public:
	AssetManager(GameState* state);
	~AssetManager();

	void Initialize();
	void Start();
	void Update();
	void Draw();
	void Deinitialize();

	void AddGameObject(GameObject* go);
	void RemoveGameObject(GameObject* go);

	TextureDetails* GenerateTexture(std::string filePath, std::string textureName = "TEXTURE");
	TextureDetails* GenerateTexture(std::string filePath);
	TextureDetails* RetrieveTexture(std::string fileName);


private:
	GameState* _OwningState;
	std::vector<GameObject*> _ObjectsInScene;


	std::vector<TextureDetails*> _LoadedTextures;



};
