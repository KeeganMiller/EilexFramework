#pragma once
#include "UIElement.h"
class HBox :
    public UIElement
{
public:
    HBox(std::string elementName = "HBox");
    ~HBox();

    void Update() override;

    int Spacing;

private:
    void UpdateElementPosition();
};

