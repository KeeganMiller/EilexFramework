#pragma once
#include <raylib.h>
#include <string>

class TextureDetails
{
public:
	std::string TexturePath;
	std::string TextureName;
	Texture2D TextureAsset;
	bool IsValid;

	TextureDetails()
	{
		TexturePath = "NA";
		TextureName = "NA";
		IsValid = false;
	}

	TextureDetails(std::string texturePath, std::string textureName, Texture2D asset)
	{
		TexturePath = texturePath;
		TextureName = textureName;
		TextureAsset = asset;

		if (TextureAsset.id > 0)
		{
			IsValid = true;
		}
		else
		{
			IsValid = false;
		}
	}
};