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

    inline void SetOffsetX(float x) { _OffSetX = x; }
    inline void SetOffsetY(float y) { _OffSetY = y; }
protected:


private:
    TextureDetails* _Image;

    Vector2 GetDrawPosition();

};

