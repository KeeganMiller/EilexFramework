#pragma once    
#include "UISprite.h"
#include "eventpp/eventdispatcher.h"

class Button :
    public UISprite
{
public:
    Button(std::string objectName);
    ~Button();


    void Update() override;
    void Draw() override;

    void SetHovered(TextureDetails* texture);
    void SetNormal(TextureDetails* texture);

    Color Tint;
    bool NoHover;

    eventpp::EventDispatcher<int, void()> OnClick;
    

private:

protected:
    TextureDetails* Hovered;
    TextureDetails* Normal;

    TextureDetails* CurrentSelectedTexture;

    void UpdateSelectedTexture();
   
    



};

