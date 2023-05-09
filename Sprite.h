#pragma once
#include <raylib.h>
#include "GameObject.h"
#include "TextureDetails.h"

class Sprite :
    public GameObject
{
public:
    Sprite(std::string objectName = "Sprite");
    Sprite(TextureDetails* texture, std::string objectName = "Sprite");

    ~Sprite();

    void Draw() override;

    inline int GetTextureWidth() { return _TextureInfo->TextureAsset.width; }
    inline int GetTextureHeight() { return _TextureInfo->TextureAsset.height; }

    Color Tint;

protected:
    TextureDetails* _TextureInfo;


};

