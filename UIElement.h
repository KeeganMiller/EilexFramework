#pragma once
#include "GameObject.h"
#include "AnchorPoint.h"

class UIElement :
    public GameObject
{
public:
    UIElement(std::string objectName);

    ~UIElement();

    void SetAnchor(AnchorPoint point);
    void SetOrigin(OriginPoint point);

protected:

    float _ElementWidth;
    float _ElementHeight;

    AnchorPoint _PositionAnchorPoint;
    OriginPoint _ElementOriginPoint;

    float _OffSetX;
    float _OffSetY;

    float _OriginX;
    float _OriginY;



private:
    
};

