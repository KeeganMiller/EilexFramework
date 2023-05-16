#include "pch.h"
#include "HBox.h"

HBox::HBox(std::string elementName) : UIElement(elementName)
{
	Spacing = 10;
}

HBox::~HBox()
{
}

void HBox::Update()
{
	UIElement::Update();
	UpdateElementPosition();
}

void HBox::UpdateElementPosition()
{
	Vector2 currentPos = Vector2();					// Initiialize the current position

	// Predefine the size of the HBox
	float currentHeight = 0;
	float currentWidth = 0;

	// Check that we have children
	if (_Children.size() > 0)
	{
		// Loop through each children
		for (auto* child : _Children)
		{
			// Cast and validate the element
			UIElement* element = dynamic_cast<UIElement*>(child);
			if (element != nullptr)
			{
				element->SetPosition(currentPos);					// Set the posiition of the element to the current position

				// Get the size of the elmenet
				float elementWidth = element->GetElementWidth();
				float elementHeight = element->GetElementHeight();

				currentWidth += (elementWidth + Spacing);					// Incremenet the current width of the hbox
				currentPos.x += (elementWidth + Spacing);					// Increment the next position of next element

				// If the height of this element is larger than the largest
				// than assign the current height to this
				if (elementHeight > currentHeight)
					currentHeight = elementHeight;
			}
		}
	}

	_ElementWidth = currentWidth;
	_ElementHeight = currentHeight;


}
