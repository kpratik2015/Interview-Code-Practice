#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1 = "123";
	int n = stoi(str1);
	cout << n << endl;
	string sbstr = str1.substr(1); // from end
	string sbstr1 = str1.substr(0, 2); // from index 0 and length 2
	cout << "'123'.substr(1):\t" << sbstr << endl;
	cout << "'123'.substr1(0,2):\t" << sbstr1 << endl;

	string str2 = "214215135326264";
	long long int sn = stoll(str2);
	cout << "sn:\t" << sn << endl;

	char charwithint = '2';
	int intchar = charwithint - '0';
	cout << "intchar:\t" << intchar << endl;

	return 0;
}