/*
SIMPLER SOLUTION:

Input  : num = “1234”
Output : 1670
Sum = 1 + 2 + 3 + 4 + 12 + 23 +
       34 + 123 + 234 + 1234
    = 1670
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

	string num = "1234";

	int length = num.length();

	// cout << "String length: " << length << endl;

	int sum = 0;

	// Adding individual digits

	for (int i = 0 ; i < length ; i++) {
		sum += num[i] - '0';
	}

	// Adding sub string of lengths 2 to length - 1

	int iteration = length - 1;

	for (int i = 2 ; i < length ; i++) {
		for (int j = 0 ; j < iteration ; j++ ) {
			string substr = num.substr(j, i);
			sum += stoi(substr);
		}
		iteration -= 1;
	}

	// Adding whole of string num

	sum += stoi(num);

	cout << sum << endl;

	return 0;
}