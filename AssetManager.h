#pragma once
#include <vector>
#include "GameState.h"

class GameObject;
class TextureDetails;
class FontDetails;

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

	FontDetails* GenerateFont(std::string fontPath, std::string fontName);
	FontDetails* GenerateFont(std::string filePath);
	FontDetails* RetrieveFont(std::string fontName);


private:
	GameState* _OwningState;
	std::vector<GameObject*> _ObjectsInScene;


	std::vector<TextureDetails*> _LoadedTextures;
	std::vector<FontDetails*> _LoadedFonts;



};
