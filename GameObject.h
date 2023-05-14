#pragma once
#include <string>
#include "raylib.h"
#include <vector>

class GameObject
{
public:
	GameObject(std::string objectName = "GameObject");
	~GameObject();

	virtual void Initialize();						// Called before anything else
	virtual void Start();
	virtual void Update();							// Called each frame
	virtual void Draw();							// Draws each frame
	virtual void Destroy();							// Called when the object is destroyed

	// Parenting methods
	void SetParent(GameObject* go);
	void AddChild(GameObject* child);
	void RemoveChild(GameObject* child);

	std::string ObjectName;							// Reference to the name of the game object

	bool IsDrawable;								// if this object can be drawn
	bool IsActive;									// If this object is active

	GameObject* Parent;								// Reference to the parent of this object


	// Position getters and setters
	virtual Vector2 GetPosition() { return _GlobalPosition; }
	inline void SetPosition(float x, float y) { _LocalPosition = Vector2{ x, y }; }
	inline void SetPosition(Vector2 pos) { _LocalPosition = pos; }

	// Scale getters and setters
	inline float GetScale() { return _Scale; }
	inline void SetScale(float scale) { _Scale = scale; }
	
	// Rotation getters and setters
	inline float GetRotation() { return _Rotation; }
	inline void SetRotation(float rotation) { _Rotation = rotation; }
	
protected:
	void Deinitialize();							// Last thing called before destroying the object

	virtual void UpdateTransform();							// Updates the transform for children objects

	// Transform properties
	Vector2 _LocalPosition;
	Vector2 _GlobalPosition;
	float _Scale;
	float _Rotation;

	std::vector<GameObject*> _Children;					// Reference to all the children of this game object

};

