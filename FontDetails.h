#pragma once
#include <raylib.h>
#include <string>
class FontDetails
{
public:
	FontDetails(std::string fontPath, std::string fontName, Font fontData)
	{
		this->FontPath = fontPath;
		this->FontName = fontName;
		this->FontData = fontData;
		IsValid = true;
	}
	~FontDetails()
	{}

	std::string FontPath;
	std::string FontName;
	Font FontData;
	bool IsValid;

private:

};