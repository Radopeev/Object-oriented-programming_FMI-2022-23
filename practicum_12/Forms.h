#pragma once
#include "Controls.h"
class Forms
{
	Control** controls;
	size_t size = 0;
	size_t capacity;

	void move(Forms&& other);
	void copyFrom(const Forms& other);
	void free();
	void resize();
public:
	Forms(size_t initialCapacity);
	Forms(const Forms& other);
	Forms(Forms&& other);
	Forms& operator=(const Forms& other);
	Forms& operator=(Forms&& other);
	~Forms();

	void addControl(Control* newControl);
	void setSize(size_t index, const Size& newSize);

};

