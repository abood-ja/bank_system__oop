#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

int main()
{
	/*clsMainScreen::showMainMenu();*/
	clsLoginScreen::showLoginScreen();
	system("pause>0");
	return 0;
}