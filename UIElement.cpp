#include "pch.h"
#include "UIElement.h"
#include "Game.h"
#include <raylib.h>

UIElement::UIElement(std::string objectName)
{
	_PositionAnchorPoint = AnchorPoint::NONE;
	_ElementOriginPoint = OriginPoint::ORIGIN_CENTER;

	_OffSetX = 0;
	_OffSetY = 0;

	_OriginX = _ElementWidth / 2;
	_OriginY = -_ElementHeight / 2;
}

UIElement::~UIElement()
{
}

void UIElement::SetAnchor(AnchorPoint point)
{
	_PositionAnchorPoint = point;
	switch (_PositionAnchorPoint)
	{
	case AnchorPoint::NONE:
		_OffSetX = 0;
		_OffSetY = 0;
		break;
	case AnchorPoint::MIDDLE:
		_OffSetX = Game::WindowWidth / 2;
		_OffSetY = Game::WindowHeight / 2;
		break;
	case AnchorPoint::TOP_LEFT:
		_OffSetX = 0;
		_OffSetY = 0;
		break;
	case AnchorPoint::TOP:
		_OffSetX = Game::WindowWidth / 2;
		_OffSetY = 0;
		break;
	case AnchorPoint::TOP_RIGHT:
		_OffSetX = Game::WindowWidth;
		_OffSetY = 0;
		break;
	case AnchorPoint::MIDDLE_LEFT:
		_OffSetX = 0;
		_OffSetY = Game::WindowHeight / 2;
		break;
	case AnchorPoint::MIDDLE_RIGHT:
		_OffSetX = Game::WindowWidth;
		_OffSetY = Game::WindowHeight / 2;
		break;
	case AnchorPoint::BOTTOM_LEFT:
		_OffSetX = 0;
		_OffSetY = Game::WindowHeight;
		break;
	case AnchorPoint::BOTTOM:
		_OffSetX = Game::WindowWidth / 2;
		_OffSetY = Game::WindowHeight;
		break;
	case AnchorPoint::BOTTOM_RIGHT:
		_OffSetX = Game::WindowWidth;
		_OffSetY = Game::WindowHeight;
		break;
	default:
		_OffSetX = 0;
		_OffSetY = 0;
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
