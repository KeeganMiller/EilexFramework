#include "pch.h"
#include "TextElement.h"
#include "FontDetails.h"

TextElement::TextElement(FontDetails* fontData, std::string objectName) : UIElement(objectName)
{
	IsDrawable = true;
	_FontData = fontData;
	FontSize = 16;
	FontColor = BLACK;
	Text = "";
}

TextElement::~TextElement()
{
	delete _FontData;
}

void TextElement::Draw()
{
	Vector2 drawPos = this->GetPosition();
	drawPos.x -= _OriginX;
	drawPos.y -= _OriginY;
	if (_FontData != nullptr)
	{
		DrawTextEx(_FontData->FontData, Text.c_str(), drawPos, FontSize, 0, FontColor);
	}
	else
	{
		DrawText(Text.c_str(), drawPos.x, drawPos.y, FontSize, FontColor);
	}
}

void TextElement::SetText(std::string text)
{
	Text = text;
	Vector2 textLength;
	if (_FontData != nullptr)
	{
		textLength = MeasureTextEx(_FontData->FontData, Text.c_str(), FontSize, 0);
		SetElementSize(textLength.x, textLength.y);
	}
	else
	{
		SetElementSize(MeasureText(Text.c_str(), FontSize), 0);
	}
}
