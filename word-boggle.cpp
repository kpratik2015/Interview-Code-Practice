/*
http://practice.geeksforgeeks.org/problems/word-boggle/0

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ


Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int tests;
	cin >> tests;

	while (tests--) {
		int num_of_words, m, n;
		cin >> num_of_words;
		vector<string> words(num_of_words);
		vector<string> final_words;
		for (int i = 0 ; i < num_of_words ; i++) {
			cin >> words[i];
		}

		cin >> n >> m;

		char arr[m][n];

		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				cin >> arr[i][j];
			}
		}

		vector<char> hash_letter(125);
		vector<char> hash_letter_copy(125);

		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n ; j++) {
				hash_letter[(int)arr[i][j]]++;
			}
		}

		int flag = 1;

		for (int i = 0 ; i < num_of_words ; i++) {
			hash_letter_copy = hash_letter;
			string test_word = words[i];
			for (int j = 0; j < test_word.size() ; j++) {
				if (hash_letter_copy[test_word[j]] >= 1) {
					hash_letter_copy[test_word[j]]--;
					flag = 1;
				}
				else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				if (find(final_words.begin(), final_words.end(), test_word) == final_words.end())
					final_words.push_back(test_word);
			}
		}

		sort(final_words.begin(), final_words.end());
		if (!final_words.empty()) {
			for (int i = 0 ; i < final_words.size() ; i++) {
				cout << final_words[i] << " ";
			}

		}
		else
			cout<<"-1";

		cout << endl;


	}
	return 0;
}