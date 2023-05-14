#include "pch.h"
#include "UIElement.h"
#include "Game.h"
#include <raylib.h>
#include <raymath.h>

UIElement::UIElement(std::string objectName)
{
	_PositionAnchorPoint = AnchorPoint::NONE;
	_ElementOriginPoint = OriginPoint::ORIGIN_CENTER;

	_OffSetX = 0;
	_OffSetY = 0;

	_OriginX = _ElementWidth / 2;
	_OriginY = -_ElementHeight / 2;

	_IsHovering = false;
}

UIElement::~UIElement()
{
}

void UIElement::SetAnchor(AnchorPoint point)
{
	_PositionAnchorPoint = point;
	int maxWidth;
	int maxHeight;

	// Determine the size of the object
	if (Parent != nullptr)
	{
		UIElement* parentElement = dynamic_cast<UIElement*>(Parent);
		if (parentElement)
		{
			maxWidth = parentElement->_ElementWidth;
			maxHeight = parentElement->_ElementHeight;
		}
		else
		{
			maxWidth = Game::WindowWidth;
			maxHeight = Game::WindowHeight;
		}
	}
	else
	{
		maxWidth = Game::WindowWidth;
		maxHeight = Game::WindowHeight;
	}


	switch (_PositionAnchorPoint)
	{
	case AnchorPoint::NONE:
		_LocalOffsetX = 0;
		_LocalOffsetY = 0;
		break;
	case AnchorPoint::MIDDLE:
		_LocalOffsetX = maxWidth / 2;
		_LocalOffsetY = maxHeight / 2;
		break;
	case AnchorPoint::TOP_LEFT:
		_LocalOffsetX = 0;
		_LocalOffsetY = 0;
		break;
	case AnchorPoint::TOP:
		_LocalOffsetX = maxWidth / 2;
		_LocalOffsetY = 0;
		break;
	case AnchorPoint::TOP_RIGHT:
		_LocalOffsetX = maxWidth;
		_LocalOffsetY = 0;
		break;
	case AnchorPoint::MIDDLE_LEFT:
		_LocalOffsetX = 0;
		_LocalOffsetY = maxHeight / 2;
		break;
	case AnchorPoint::MIDDLE_RIGHT:
		_LocalOffsetX = maxWidth;
		_LocalOffsetY = maxHeight / 2;
		break;
	case AnchorPoint::BOTTOM_LEFT:
		_LocalOffsetX = 0;
		_LocalOffsetY = maxHeight;
		break;
	case AnchorPoint::BOTTOM:
		_LocalOffsetX = maxWidth / 2;
		_LocalOffsetY = maxHeight;
		break;
	case AnchorPoint::BOTTOM_RIGHT:
		_LocalOffsetX = maxWidth;
		_LocalOffsetY = maxHeight;
		break;
	default:
		_LocalOffsetX = 0;
		_LocalOffsetY = 0;
		break;
	}
}

void UIElement::SetOrigin(OriginPoint point)
{
	_ElementOriginPoint = point;
	switch (_ElementOriginPoint)
	{
	case OriginPoint::ORIGIN_TOP_LEFT:
		_OriginX = 0;
		_OriginY = 0;
		break;
	case OriginPoint::ORIGIN_TOP:
		_OriginX = _ElementWidth / 2;
		_OriginY = 0;
		break;
	case OriginPoint::ORIGIN_TOP_RIGHT:
		_OriginX = _ElementWidth;
		_OriginY = 0;
		break;
	case OriginPoint::ORIGIN_CENTER_LEFT:
		_OriginX = 0;
		_OriginY = _ElementHeight / 2;
		break;
	case OriginPoint::ORIGIN_CENTER:
		_OriginX = _ElementWidth / 2;
		_OriginY = _ElementHeight / 2;
		break;
	case OriginPoint::ORIGIN_CENTER_RIGHT:
		_OriginX = _ElementWidth;
		_OriginY = _ElementHeight / 2;
		break;
	case OriginPoint::ORIGIN_BOTTOM_LEFT:
		_OriginX = 0;
		_OriginY = _ElementHeight;
		break;
	case ORIGIN_BOTTOM:
		_OriginX = _ElementWidth / 2;
		_OriginY = _ElementHeight;
		break;
	case ORIGIN_BOTTOM_RIGHT:
		_OriginX = _ElementWidth;
		_OriginY = _ElementHeight;
		break;
	default:
		_OriginX = 0;
		_OriginY = 0;
		break;

	}
}

void UIElement::Update()
{
	GameObject::Update();
	_IsMouseOver = DetectMouseIsOver();
	if (_IsMouseOver)
	{
		if (!_IsHovering)
		{
			_OnMouseEnter.dispatch(0);
			_IsHovering = true;
		}
	}
	else
	{
		if (_IsHovering)
		{
			_OnMouseExit.dispatch(0);
			_IsHovering = false;
		}
	}

}

Vector2 UIElement::GetPosition()
{
	Vector2 position = Vector2();
	position.x = _GlobalPosition.x + _OffSetX;
	position.y = _GlobalPosition.y + _OffSetY;
	return position;
}

Vector2 UIElement::GetTopLeftHandPosition()
{
	Vector2 position = this->GetPosition();
	switch (_PositionAnchorPoint)
	{
		case AnchorPoint::TOP_LEFT:
			return position;
		case AnchorPoint::TOP:
			position.x -= (_OriginX / 2);
			return position;
		case AnchorPoint::TOP_RIGHT:
			position.x -= _OriginX;
			return position;
		case AnchorPoint::MIDDLE_LEFT:
			position.y -= (_OriginY / 2);
			return position;
		case AnchorPoint::MIDDLE:
			position.x -= (_OriginX / 2);
			position.y -= (_OriginY / 2);
			return position;
		case AnchorPoint::MIDDLE_RIGHT:
			position.x -= _OriginX;
			position.y -= (_OriginY / 2);
			return position;
		case AnchorPoint::BOTTOM_LEFT:
			position.y -= _OriginY;
			return position;
		case AnchorPoint::BOTTOM:
			position.x -= (_OriginX / 2);
			position.y -= _OriginY;
			return position;
		case AnchorPoint::BOTTOM_RIGHT:
			position.x -= _OriginX;
			position.y -= _OriginY;
			return position;
		default:
			return position;
	}
}

bool UIElement::DetectMouseIsOver()
{
	Vector2 mousePos = GetMousePosition();
	if (mousePos.x > GetPosition().x && mousePos.x < (GetPosition().x + _ElementWidth))
	{
		if (mousePos.y > GetPosition().y && mousePos.y < (GetPosition().y + _ElementHeight))
		{
			return true;
		}
	}
	return false;
}

Vector2 UIElement::GenerateGlobalPosition()
{
	Vector2 globalPos = Vector2();
	globalPos.x = _GlobalPosition.x + _OffSetX;
	globalPos.y = _GlobalPosition.y + _OffSetY;
	return globalPos;
}

void UIElement::UpdateTransform()
{
	if (Parent)
	{
		UIElement* parentUI = dynamic_cast<UIElement*>(Parent);
		if (parentUI)
		{
			_GlobalPosition = Vector2Add(parentUI->GetTopLeftHandPosition(), _LocalPosition);
		}
		else
		{
			_GlobalPosition = Vector2Add(Parent->GetPosition(), _LocalPosition);
		}
	}
	else
	{
		_GlobalPosition = _LocalPosition;
	}

	_OffSetX = _LocalOffsetX;
	_OffSetY = _LocalOffsetY;
}
