
#include <iostream>

#include "LoginScreen.h"
#include "Logger.h"
#include "LogMessages.h"

using namespace std;

int main()
{
	Logger::Info(LogMessages::applicationStarted);

	while (true)
	{
		if (!LoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	Logger::Info(LogMessages::applicationClosed);

    cout << endl;

    system("pause>nul");
}