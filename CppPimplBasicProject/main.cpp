#include "Widget.h"

#include<iostream>
#include<memory>

int main() {
	
	std::unique_ptr<Widget> WidgetUPtr = std::make_unique<Widget>();
	WidgetUPtr->RenderWidget();

	return 0;
}