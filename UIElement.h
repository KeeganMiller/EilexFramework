#pragma once
#include "GameObject.h"
#include "AnchorPoint.h"
#include "eventpp/eventdispatcher.h"

class UIElement :
    public GameObject
{
public:
    UIElement(std::string objectName);

    ~UIElement();

    void SetAnchor(AnchorPoint point);
    void SetOrigin(OriginPoint point);

    inline void SetElementSize(float width, float height) { _ElementWidth = width; _ElementHeight = height; }

    void Update() override;

    eventpp::EventDispatcher<int, void()> _OnMouseEnter;
    eventpp::EventDispatcher<int, void()> _OnMouseExit;

protected:

    float _ElementWidth;
    float _ElementHeight;

    AnchorPoint _PositionAnchorPoint;
    OriginPoint _ElementOriginPoint;

    float _OffSetX;
    float _OffSetY;

    float _OriginX;
    float _OriginY;

    bool _IsMouseOver;


    bool _IsHovering;

    bool DetectMouseIsOver();
    Vector2 GenerateGlobalPosition();

private:
    

  
    
};

