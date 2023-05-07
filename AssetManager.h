#pragma once
#include <vector>
#include "GameState.h"
class AssetManager
{
public:
	AssetManager(GameState* state);
	~AssetManager();


private:
	GameState* _OwningState;

};
