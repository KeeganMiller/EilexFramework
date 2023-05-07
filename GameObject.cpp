#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(std::string objectName)
{
	ObjectName = objectName;
	IsActive = true;
	IsDrawable = false;
}

GameObject::~GameObject()
{
	for (auto* go : _Children)
	{
		delete go;
	}
}

void GameObject::Initialize()
{
}

void GameObject::Update()
{
}

void GameObject::Draw()
{
}

void GameObject::Destroy()
{
}

void GameObject::SetParent(GameObject* go)
{
}

void GameObject::AddChild(GameObject* child)
{
}

void GameObject::RemoveChild(GameObject* child)
{
}
