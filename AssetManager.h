#pragma once
#include <vector>
#include "GameState.h"

class GameObject;

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


private:
	GameState* _OwningState;
	std::vector<GameObject*> _ObjectsInScene;

};
