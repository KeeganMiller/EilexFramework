#pragma once
#include <string>


class AssetManager;

class GameState
{
public:
	GameState(std::string stateName = "Game State");
	~GameState();

	virtual void Initialize();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Deinitialize();

	inline std::string GetStateName() { return _StateName; }
	inline AssetManager* GetAssetManager() { return _StateAssets; }

private:
	std::string _StateName;
	AssetManager* _StateAssets;
};

