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
	if (!IsActive)
		return;
}

void GameObject::Update()
{
	if (!IsActive)
		return;
}

void GameObject::Draw()
{
	if (!IsActive)
		return;
}

void GameObject::Destroy()
{
	if (!IsActive)
		return;
}

void GameObject::SetParent(GameObject* go)
{
	if (this->Parent != nullptr)
	{
		this->Parent->RemoveChild(this);
	}

	this->Parent = go;

	this->Parent->AddChild(this);

}

void GameObject::AddChild(GameObject* child)
{
	_Children.push_back(child);
}

void GameObject::RemoveChild(GameObject* child)
{
	int index = -1;
	for (int i = 0; i < _Children.size(); ++i)
	{
		if (child == _Children[i])
		{
			index = i;
			break;
		}
	}

	if (index > -1)
	{
		_Children.erase(_Children.begin() + index);
	}
}
