/*
http://practice.geeksforgeeks.org/problems/similar-expressions/0

Given two expressions in the form of strings. 
The task is to compare them and check if they are similar. 
Expressions consist of lowercase alphabets, '+', '-' and  '( )'.

Input:
2
-(a+b+c)
-a-b-c
a-b-(c-d)
a-b-c-d

Output:
YES
NO


(THIS IS DONE WITH STACK WHICH GIVES SIGSEV ERROR)
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int tests;
	cin >> tests;
	cin.ignore(); // since we used cin before getline

	while (tests != 0) {

		string str1, str2, swapstr;
		
		getline(cin, str1);
		getline(cin, str2);

		int correct_flag = 1;
		int s1size, s2size;

		stack<char> s1, s2;

		if (str1.size() < str2.size()) {
			swapstr = str1;
			str1 = str2;
			str2 = swapstr;
		}

		for (int i = str1.size() - 1 ; i >= 0 ; i--) {
			s1.push(str1[i]);
		}
		s1size = s1.size();

		for (int i = str2.size() - 1 ; i >= 0 ; i--) {
			s2.push(str2[i]);
		}
		s2size = s2.size();

		int open_flag = 1;
		int close_flag = 1;

		vector<int> flip_sign(s1size);
		int flip = 1;

		cout << s1.size() << endl;

		for (int i = 0 ; i < s1size ; i++) {
			cout << "i: " << i << endl;
			// cout<<s1.top()<<"\t"<<s2.top()<<endl;
			if (s1.top() == '-' && i < s1size - 2) {
				if (str1[i + 1] == '(' && str1[i + 2] == '-') {
					cout << "POP: " << s1.top() << endl;
					s1.pop();
					s1.pop();
					s1.pop();
					flip_sign[open_flag] = flip;
					flip = !flip;
					open_flag++;
					close_flag--;
					// continue;
				}
			}
			else if (s1.top() == '-' && i < s1size - 1 ) {
				if (str1[i + 1] == '(') {
					cout << "POP: " << s1.top() << endl;
					s1.pop();
					flip_sign[open_flag] = flip;
					flip = !flip;
					// continue;
				}
			}
			else if (s1.top() == ')') {
				cout << "POP: " << s1.top() << endl;
				s1.pop();
				close_flag++;
				open_flag--;
			}
			else if (s1.top() == '(') {
				cout << "POP: " << s1.top() << endl;
				s1.pop();
				open_flag++;
				close_flag--;
			}
			else if (flip_sign[open_flag - 1] == 1 && str1[i - 1] == '(' && s1.top() >= 'a' && s1.top() <= 'z') {
				if (s2.top() == '-') {
					cout << "POP: " << s2.top() << endl;
					s2.pop();
					if (s2.top() >= 'a' && s1.top() <= 'z') {
						cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
						s2.pop();
						s1.pop();
					}
					else {
						correct_flag = 0;
						break;
					}
				}
				else {
					correct_flag = 0;
					break;
				}

			}
			else if (flip_sign[open_flag - 1] == 1) {
				if (s1.top() == '+' && s2.top() == '-' || s1.top() == '-' && s2.top() == '+') {
					cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
					s1.pop();
					s2.pop();
				}
				else if (s1.top() == '+' && s2.top() == '+' || s1.top() == '-' && s2.top() == '-') {
					correct_flag = 0;
					break;
				}
				else if (s1.top() == s2.top()) {
					cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
					s1.pop();
					s2.pop();
				}
				else {
					correct_flag = 0;
					break;
				}

			}
			else if (flip_sign[open_flag - 1] == 0) {
				if (s1.top() == '+' && s2.top() == '-' || s1.top() == '-' && s2.top() == '+') {
					correct_flag = 0;
					break;
				}
				else if (s1.top() == '+' && s2.top() == '+' || s1.top() == '-' && s2.top() == '-') {
					cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
					s1.pop();
					s2.pop();
				}
				else if (s1.top() >= 'a' && s1.top() <= 'z' && s2.top() >= 'a' && s2.top() <= 'z') {
					cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
					s1.pop();
					s2.pop();
				}
				else {
					correct_flag = 0;
					break;
				}
			}


		}

		cout << s1.size() << endl;

		if (correct_flag == 1)
			cout << "YES";
		else
			cout << "NO";

		cout << endl;

		tests--;
	}

	return 0;
}

/*
C:\Users\kpratik\Desktop>a.exe
1
-(-a+b-c)+(a+b+c)-(-(b+c))
a-b-c+a+b+c+b+c
26
i: 0
POP: -
i: 1
POP: (
i: 2
24
NO

*/