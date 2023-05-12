#pragma once
#include "UIElement.h"

class TextureDetails;

class UISprite :
    public UIElement
{
public:
    UISprite(std::string objectName = "UISprite");
    UISprite(TextureDetails* texture, std::string objectName = "UISprite");
    ~UISprite();

    void Draw() override;
    void SetTexture(TextureDetails* texture);

    Color Tint;
protected:


private:
    TextureDetails* _Image;

    Vector2 GetDrawPosition();

};

