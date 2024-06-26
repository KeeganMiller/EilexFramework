#include "pch.h"
#include "Sprite.h"
#include "TextureDetails.h"
#include <iostream>

Sprite::Sprite(std::string objectName)
{
	IsDrawable = false;
	Tint = WHITE;
}

Sprite::Sprite(TextureDetails* texture, std::string objectName) : GameObject(objectName)
{
	_TextureInfo = texture;
	
	if (_TextureInfo->IsValid)
	{
		IsDrawable = true;
	}
}

Sprite::~Sprite()
{
	delete _TextureInfo;
}

void Sprite::Draw()
{
	if (IsDrawable)
	{
		DrawTextureEx(_TextureInfo->TextureAsset, _GlobalPosition, _Rotation, _Scale, Tint);
	}
}
