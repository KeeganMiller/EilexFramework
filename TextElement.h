#pragma once
#include "UIElement.h"


class FontDetails;

class TextElement :
    public UIElement
{
public:
    TextElement(std::string objectName = "TextElement") : UIElement(objectName)
    {
        IsDrawable = true;
        _FontData = nullptr;
        FontSize = 16;
        FontColor = BLACK;
        Text = "";
    }
    TextElement(FontDetails* fontData, std::string objectName = "TextElement");
    ~TextElement();

    void Draw() override;

    
    void SetText(std::string text);

    // Font Settings
    Color FontColor;
    int FontSize;



protected:
    FontDetails* _FontData;
    std::string Text;

private:
};

