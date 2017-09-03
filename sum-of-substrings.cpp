/*
GEEKSFORGEEKS SOLUTION (O(n)):

Input  : num = “1234”
Output : 1670
Sum = 1 + 2 + 3 + 4 + 12 + 23 +
       34 + 123 + 234 + 1234
    = 1670
*/

#include <iostream>
#include <string>

using namespace std;

int toDigit(char ch)
{
	return (ch - '0');
}

// Returns sum of all substring of num
int sumOfSubstrings(string num)
{
	int n = num.length();

	//  allocate memory equal to length of string
	int sumofdigit[n];

	//  initialize first value with first digit
	sumofdigit[0] = toDigit(num[0]);
	int res = sumofdigit[0];

	// cout << "sumofdigit[0]: " << res << endl;

	//  loop over all digits of string
	for (int i = 1; i < n; i++)
	{
		int numi = toDigit(num[i]);

		// cout << "numi = num[i] " << numi << " from index: " << i << endl;

		// update each sumofdigit from previous value
		sumofdigit[i] = (i + 1) * numi +
		                10 * sumofdigit[i - 1];

		// cout << "sumofdigit[" << i << "] = "
		//        << "(i+1) * numi + 10 * sumofdigit[i-1]: " << sumofdigit[i] << endl;

		// add current value to the result
		res += sumofdigit[i];
	}

	return res;
}

int main() {

	string num = "1234";
	// cout << "num: " << num << endl;
	cout << sumOfSubstrings(num) << endl;

	return 0;
}