#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

int main()
{
	while (true) {
		clsLoginScreen::showLoginScreen();
	}
		return 0;
}