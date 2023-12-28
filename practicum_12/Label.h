#pragma once
#include "MyString.h"
#include "Controls.h"
class Label : public Control
{
	MyString label;
public:
	Label();
	void setDataDialog() override ;
	virtual Control* clone()const override;
};

