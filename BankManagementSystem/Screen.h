#pragma once

#include <iostream>

class Screen
{
protected:
	static void ShowScreenHeader(const std::string& title);
	static void PauseScreen(const std::string& message);
	static void ClearScreen();
};

