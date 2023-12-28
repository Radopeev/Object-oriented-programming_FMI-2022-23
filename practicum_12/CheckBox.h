#pragma once
#include "MyString.h"
#include "Controls.h"
class CheckBox:public Control
{
	MyString text;
	bool state;
public:
	CheckBox();
	void setDataDialog()override;
	virtual Control* clone()const override;
};

