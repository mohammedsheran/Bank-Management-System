#pragma once

#include <iostream>

class Screen
{
protected:
	static void ShowScreenHeader(const std::string& title, const std::string& subTitle = "");
	static void PauseScreen(const std::string& message);
	static void ClearScreen();
};

