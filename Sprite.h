#pragma once
#include "GameObject.h"

class TextureDetails;

class Sprite :
    public GameObject
{
public:
    Sprite(std::string objectName = "Sprite");
    Sprite(TextureDetails* texture, std::string objectName = "Sprite") : GameObject(objectName);

    ~Sprite();

    void Draw() override;

protected:
    TextureDetails* _TextureInfo;


};

