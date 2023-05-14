#include "pch.h"
#include "UISprite.h"
#include "TextureDetails.h"

UISprite::UISprite(std::string objectName) : UIElement(objectName)
{
	_Image = nullptr;
	IsDrawable = true;
	Tint = WHITE;
}

UISprite::UISprite(TextureDetails* texture, std::string objectName) : UIElement(objectName)
{
	SetTexture(texture);
	IsDrawable = true;
	Tint = WHITE;
}

UISprite::~UISprite()
{
	delete _Image;
}

void UISprite::Draw()
{
	if (IsDrawable && _Image != nullptr)
	{
		Vector2 drawPos = GetDrawPosition();
		DrawTextureEx(_Image->TextureAsset, drawPos, _Rotation, _Scale, Tint);
	}
}

void UISprite::SetTexture(TextureDetails* texture)
{
	_Image = texture;
	if (_Image != nullptr)
	{
		_ElementWidth = texture->TextureAsset.width;
		_ElementHeight = texture->TextureAsset.height;
	}
}

Vector2 UISprite::GetDrawPosition()
{
	Vector2 drawPos = Vector2();
	drawPos.x = this->GetPosition().x - _OriginX;
	drawPos.y = this->GetPosition().y - _OriginY;
	return drawPos;
}
