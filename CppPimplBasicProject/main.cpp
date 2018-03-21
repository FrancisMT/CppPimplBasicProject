#include "Widget.h"

#include<iostream>
#include<memory>

int main() {
	
	Widget A;
	Widget B = A; // call copy constructor
	Widget C = std::move(A); // call move constructor

	std::unique_ptr<Widget> WidgetUPtr = std::make_unique<Widget>(B);	// call copy constructor
	std::unique_ptr<Widget> WidgetUPtrB = std::make_unique<Widget>(std::move(C));	// call move constructor

	WidgetUPtr->RenderWidget();

	return 0;
}