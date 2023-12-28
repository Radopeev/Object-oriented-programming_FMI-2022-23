#pragma once
#include "Controls.h"
#include"MyString.h"
#include "Vector.hpp"
class RadioButton:public Control
{
	Vector<bool> states;
	size_t optionCount;
	Vector<MyString> options;
public:
	RadioButton();
	void setDataDialog() override;
	virtual Control* clone()const override;
};

