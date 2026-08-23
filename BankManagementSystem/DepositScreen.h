#pragma once

#include "Screen.h"

class DepositScreen : public Screen
{
private:
	static double _ReadDepositAmount();

public:
	static void ShowDepositScreen();
};