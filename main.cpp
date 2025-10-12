#include "clsBankClient.h"
int main()
{
	clsBankClient client1 = clsBankClient::find("A101");
	client1.print();
	clsBankClient client2 = clsBankClient::find("A101", "12345");
	client2.print();
	cout << clsBankClient::isClientExist("A1001231");
	system("pause>0");
	return 0;
}