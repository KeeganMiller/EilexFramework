#pragma once
#include "UIElement.h"
class VBox :
    public UIElement
{
public:
    VBox(std::string elementName = "VBox");
    ~VBox();

    void Update() override;


    int Spacing;

private:
    void UpdateElementPositions();


};

