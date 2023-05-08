#pragma once
#include <string>


class AssetManager;

class GameState
{
public:
	GameState(std::string stateName = "Game State");
	~GameState();

	// Update functions
	virtual void Initialize();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Deinitialize();

	inline std::string GetStateName() { return _StateName; }			// Getter for the name of the state
	inline AssetManager* GetAssetManager() { return _StateAssets; }		// Get reference to the asset manager

protected:
	std::string _StateName;
	AssetManager* _StateAssets;
};

