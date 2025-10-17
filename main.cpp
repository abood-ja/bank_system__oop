#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

int main()
{
	while (true) {
		if (!clsLoginScreen::showLoginScreen())
			break;
	}
		return 0;
}