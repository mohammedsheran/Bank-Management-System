
#include "Screen.h"
#include "Libraries/Utils.h"

using namespace std;

void Screen::ShowScreenHeader(const string& title, const string& subTitle)
{
    cout << Utils::Divider(110) << '\n';
    cout << Utils::Tab(6) << title << '\n';

    if (!subTitle.empty())
    {
        cout << Utils::Tab(6) << "   " << subTitle << '\n';
    }
    cout << Utils::Divider(110) << "\n\n";
}
void Screen::PauseScreen(const string& message)
{
    cout << '\n' << message ;
    system("pause>nul");
}
void Screen::ClearScreen()
{
    system("cls");
}