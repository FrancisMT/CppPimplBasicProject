#include <vector>
#include <iostream>

#include "Widget.h"

class Widget::Impl {
	// Put all private and nonvirtual members here.
private:
	int InternalVar = 0;

public:
	
	std::vector<int> PublicVector;

	Impl() {
		PublicVector.reserve(42);
		ProcessInternalVar();
	}

	void ProcessInternalVar() {
		InternalVar = 42;
	}
	
	void RenderWidget(Widget const& Widget) const {
		if (Widget.ShowWidget()) {
			std::cout << "Showing Widget\n";
		}
	}
};

void Widget::RenderWidget() const {
	Pimpl->RenderWidget(*this);
}

Widget::Widget()
	: Pimpl(std::make_unique<Impl>()) {
	Pimpl->ProcessInternalVar();
}

Widget::~Widget() = default;

Widget::Widget(const Widget& OtherWidget) {
	Pimpl = std::make_unique<Impl>();
	Pimpl->PublicVector = OtherWidget.Pimpl->PublicVector;
}

Widget::Widget(Widget && OtherWidget) {
	Pimpl = std::move(OtherWidget.Pimpl);
}
