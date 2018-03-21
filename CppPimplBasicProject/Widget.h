#pragma once
#include<memory>

class Widget {

private:
	class Impl;
	std::unique_ptr<Impl> Pimpl;

public:
	
	// Public API that will be forwarded to the implementation
	void RenderWidget() const;

	// Public API that the implementation has to call.
	inline bool ShowWidget() const {
		return true;
	}

	// Constructor
	Widget();

	// Destructor (defined in the implementation file, where impl is a complete type)
	~Widget();

	// Copy Constructor
	Widget(Widget const& OtherWidget);

	// Move Contructor
	Widget(Widget&&);

	// Assignment Operator
	Widget& operator=(Widget&&) = default;

	// Equality Operator
	bool operator==(Widget const& OtherWidget) {
		return Pimpl == OtherWidget.Pimpl;
	}

	// Inequality Operator
	bool operator!=(Widget const& OtherWidget) {
		return Pimpl != OtherWidget.Pimpl;
	}

	// Bool conversion operator
	operator bool() const {
		return !!Pimpl;
	}
};

