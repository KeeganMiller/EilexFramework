#pragma once
#include <string>
#include "raylib.h"
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Initialize();
	void Update();
	void Draw();
	void Destroy();

	void SetParent(GameObject* go);
	void AddChild(GameObject* child);
	void RemoveChild(GameObject* child);

	std::string ObjectName;

	bool IsDrawable;
	bool IsActive;

	GameObject* Parent;
	
private:
	void Deinitialize();

	void UpdateTransform();

	Vector2 _LocalPosition;
	Vector2 _GlobalPosition;
	float scale;
	float rotation;

	std::vector<GameObject*> _Children;

};
