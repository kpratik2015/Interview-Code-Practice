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

    string str1 = "";
    string str2 = "";
    string swapstr = "";

    getline(cin, str1);
    getline(cin, str2);

    int correct_flag = 1;

    if (str1.size() < str2.size()) {
      swapstr = str1;
      str1 = str2;
      str2 = swapstr;
    }

    int open_flag = 1;
    int close_flag = 1;

    vector<int> flip_sign(str1.size());

    int flip = 1;
    int j = 0;
    int skip = 0;
    int skip_i = 0;

    string final = "";

    for (int i = 0 ; i < str1.size() ; i++) {

      cout << "i: " << i << " j: "<< j << endl;

      cout << str1[i] << "\t" << str2[j] << endl;

      for (int i = 0 ; i < flip_sign.size() ; i++) {
        cout << flip_sign[i] << " ";
      }

      cout << endl;

      cout << "SKIP: " << skip << endl;

      if (str1[i] == '-' && i < str1.size() - 2 && str1[i + 1] == '(' && str1[i + 2] == '-') {
        flip_sign[open_flag] = flip;
        flip = !flip;
        if(i != 0)
          skip_i = 1;
        skip++;
        // continue;
      }
      else if (str1[i] == '-' && i < str1.size() - 1 && str1[i + 1] == '(' ) {
        // cout << "POP: " << s1.top() << endl;
        flip_sign[open_flag] = flip;
        flip = !flip;
        skip++;
        // continue;

      }
      else if (str1[i] == ')') {
        // cout << "POP: " << s1.top() << endl;
        close_flag++;
        open_flag--;
        if (flip == 0)
          flip = !flip;
      }
      else if (str1[i] == '(') {
        // cout << "POP: " << s1.top() << endl;
        open_flag++;
        close_flag--;
      }
      else if (flip_sign[open_flag - 1] == 1) {
        cout << "INSIDE NEGATIVE" << endl;
        if (skip > 0) {
          final = final + str2[j];
          j += 1;
          skip--;
        }
        if(skip_i == 1){
          skip_i = 0;
          continue;
        }
        if (str1[i] == '+' && str2[j] == '-' || str1[i] == '-' && str2[j] == '+') {
          // cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
          final = final + str2[j];
          j += 1;
        }
        else if (str1[i] == '+' && str2[j] == '+' || str1[i] == '-' && str2[j] == '-') {
          correct_flag = 0;
          break;
        }
        else if (str1[i] == str2[j]) {
          final = final + str1[i];
          j += 1;
          // cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
        }
        else {
          correct_flag = 0;
          break;
        }

      }
      else if (flip_sign[open_flag - 1] == 0) {
        cout << "INSIDE POSITIVE" << endl;
        if (str1[i] == '+' && str2[j] == '-' || str1[i] == '-' && str2[j] == '+') {
          correct_flag = 0;
          break;
        }
        else if (str1[i] == '+' && str2[j] == '+' || str1[i] == '-' && str2[j] == '-') {
          // cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
          final = final + str1[i];
          j += 1;
        }
        else if (str1[i] >= 'a' && str1[i] <= 'z' && str2[j] >= 'a' && str2[j] <= 'z') {
          // cout << "POP: " << s1.top() << "\t" << s2.top() << endl;
          final = final + str1[i];
          j += 1;
        }
        else {
          correct_flag = 0;
          break;
        }
      }


    }

    cout << final << endl;

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
Wrong Answer!!!Wrong Answer
Possibly your code doesn't work correctly for multiple test-cases (TCs).
The first test case where your code failed:

Input:
-a+b+c
b+c-a

Its Correct output is:
YES

And Your Code's Output is:
NO
*/