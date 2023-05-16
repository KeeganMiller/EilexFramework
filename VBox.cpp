#include "pch.h"
#include "VBox.h"

VBox::VBox(std::string elementName) : UIElement(elementName)
{
	Spacing = 10;
}

VBox::~VBox()
{
}

void VBox::Update()
{
	UIElement::Update();
	UpdateElementPositions();

}

void VBox::UpdateElementPositions()
{
	Vector2 currentPosition = Vector2();
	float totalElementWidth = 0;
	float totalElementHeight = 0;
	if (_Children.size() > 0)
	{
		for (auto* child : _Children)
		{
			UIElement* element = dynamic_cast<UIElement*>(child);
			if (element != nullptr)
			{
				element->SetPosition(currentPosition);


				float elementLength = element->GetElementHeight();
				float elementWidth = element->GetElementWidth();

				totalElementHeight = (elementLength + Spacing);
				currentPosition.y += (elementLength + Spacing);

				if (elementWidth > totalElementWidth)
					totalElementWidth = elementWidth;
			}
		}
	}

	_ElementWidth = totalElementWidth;
	_ElementHeight = totalElementHeight;
}
