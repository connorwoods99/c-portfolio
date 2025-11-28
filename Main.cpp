#include<iostream>
#include<string>
using namespace std;

void encrypt(string P)//converts to ascii
{
	for (int i = 0; i < P.length(); i++) {

		cout << (int)P[i] ;//*3 -12 +55;

	}
}
void decrypt(string D, int len)//converts back from ascii to strong
{
	int number = 0;
	for (int j = 0; j < len; j++)
	{
		number = number*10 +(D[j]-'0');
		if (number >= 32 && number <= 122) {
			char ch = (char)number ; //-55 +12 /3;
			cout << ch;
			number = 0;
		}
		//cout << (char)D[j] -55 +12 /3 << endl;
	}
}
int main()
{
	cout << "type new for new password or old to decrypt an old one?\n";
	string answer;
	cin >> answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores the new line
	if (answer == "new")
	{
		string password;
		cout << "enter the password you want encrypted\n";
		getline(cin, password);
		encrypt(password);
	}
	else if (answer == "old")
	{
		cout << "eneter your numbers for your encrypted password\n";
		string EP;
		getline(cin, EP);
		int len = EP.length();
		decrypt(EP, len);

	}
	else
	{
		return 0;
	}

	return (0);
};
