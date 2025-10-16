#pragma once
#include "clsScreen.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static short _ReadManageUsersMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}
	static void _GoBackToManageUsersScreen() {
		cout << setw(37) << left << "" << "\nPress any key to go back to Manage Users Menu...";
		system("pause>0");
		showManageUsersScreen();
	}
	static void _PerformManageUsersMenuOption(enManageUsersMenueOptions option) {
		switch (option)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eMainMenue:
			break;
		}
	}
	static void _ShowListUsersScreen() {
		clsUsersListScreen::showClientListScreen();
	}
	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::showDeleteUserScreen();

	}
	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();

	}
	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
	}
public:
	static void showManageUsersScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		string title = "\t Manage Users Screen";
		_DrawScreenHeader(title);
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUsersMenuOption((enManageUsersMenueOptions)_ReadManageUsersMenuOption());
	}
};

