#include "pch.h"
#include "Button.h"
#include "TextureDetails.h"

Button::Button(std::string objectName)
{
	_IsHovering = false;
	IsDrawable = true;
	NoHover = true;
	Tint = WHITE;
}

Button::~Button()
{
	delete Hovered;
	delete Normal;
	delete CurrentSelectedTexture;
}

void Button::Update()
{
	UISprite::Update();

	UpdateSelectedTexture();
}

void Button::Draw()
{
	if (IsDrawable && CurrentSelectedTexture != nullptr && CurrentSelectedTexture->IsValid)
	{
		Vector2 drawPos = GenerateGlobalPosition();
		drawPos.x - _OriginX;
		drawPos.y - _OriginY;
		DrawTextureEx(CurrentSelectedTexture->TextureAsset, drawPos, _Rotation, _Scale, Tint);
	}
}

void Button::SetHovered(TextureDetails* texture)
{
	Hovered = texture;
}

void Button::SetNormal(TextureDetails* texture)
{
	Normal = texture;
}

void Button::UpdateSelectedTexture()
{
	if (!NoHover)
	{
		if (_IsHovering)
		{
			CurrentSelectedTexture = Hovered;
		}
		else
		{
			CurrentSelectedTexture = Normal;
		}
	}
	else
	{
		CurrentSelectedTexture = Normal;
	}
}


