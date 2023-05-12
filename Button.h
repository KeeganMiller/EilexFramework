#pragma once
#include "UISprite.h"

class Button :
    public UISprite
{
public:
    Button(std::string objectName);
    ~Button();


    void Update() override;

    void SetHovered(TextureDetails* texture);
    void SetNormal(TextureDetails* texture);
    

private:

protected:
    UISprite* Hovered;
    UISprite* Normal;

};

