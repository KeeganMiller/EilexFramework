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
    inline float GetElementWidth() { return _ElementWidth; }
    inline float GetElementHeight() { return _ElementHeight; }

    void Update() override;

    eventpp::EventDispatcher<int, void()> _OnMouseEnter;
    eventpp::EventDispatcher<int, void()> _OnMouseExit;

    inline float GetOffsetX() { return _OffSetX; }
    inline float GetOffsetY() { return _OffSetY; }

    inline void SetOffSetX(const float offset) { _LocalOffsetX = offset; }
    inline void SetOffSetY(const float offset) { _LocalOffsetY = offset; }

    Vector2 GetPosition() override;
    Vector2 GetTopLeftHandPosition();

protected:

    float _ElementWidth;
    float _ElementHeight;

    AnchorPoint _PositionAnchorPoint;
    OriginPoint _ElementOriginPoint;

    float _OffSetX;
    float _OffSetY;
    float _LocalOffsetX;
    float _LocalOffsetY;

    float _OriginX;
    float _OriginY;

    bool _IsMouseOver;


    bool _IsHovering;

    bool DetectMouseIsOver();
    Vector2 GenerateGlobalPosition();
    void UpdateTransform() override;


private:
    

  
    
};

