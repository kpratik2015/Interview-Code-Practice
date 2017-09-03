/*
http://practice.geeksforgeeks.org/problems/start-elements/0
Given an unsorted array. The task is to find all the star
and super star elements in the array. Star are those elements
which are strictly greater than all the elements on its right
side. Super star are those elements which are strictly greater
than all the elements on its left and right side.

Note: Assume first element (A[0]) is greater than all the
elements on its left side, And last element (A[n-1]) is
greater than all the elements on its right side.

Constraints:
1<=T<=200
1<=N<=106
1<=A[i]<=106

Example:
Input:
2
6
4 2 5 7 2 1
3
8 6 5

Output:
7 2 1
7
8 6 5
8
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tests = 0;
    cin >> tests;
    while (tests != 0) {
        int size = 5;
        cin >> size;
        vector<int> arr(size);
        vector<int> star;
        // vector<int> check(1000000);
        vector<int> superstar;
        for (int i = 0 ; i < size ; i++) {
            cin >> arr[i];
        }

        int max = arr[size - 1];
        int temp_size = size - 1;
        int first_time = 1;

        for (int i = size - 1 ; i >= 0; i--) {
            int num = arr[i];
            int left_flag = 1;
            int right_flag = 0;
            if(i == size - 1)
                right_flag = 1;
            if (num > max) {
                max = num;
                right_flag = 1;
            }
            else {
                left_flag = 0;
            }

            if(i == size - 1){
                right_flag = 1;
                left_flag = 1;
            }

            // cout<<"MAX: "<<max<<endl;
            try {
                // int flag = 1;
                // check[num] = num;
                // cout << check[num + 1] << " ";
                // if (num + 1 < max) {
                //     for (int i = num + 1 ; i <= max ; i++) {
                //         if (check[i] != 0) {
                //             flag = 0;
                //             break;
                //         }
                //     }
                // }

                // if (flag == 1) {
                if (right_flag == 1) {
                    star.push_back(num);
                }

                // if (left_flag == 1) {
                if (right_flag == 1 && left_flag == 1) {
                    int left_max = num;
                    for (int i = 0 ; i < temp_size ; i++) {
                        if (arr[i] >= left_max) {
                            left_flag = 0;
                            break;
                        }
                    }

                    if (left_flag == 1 || (first_time == 1 && left_flag == 1)) {
                        superstar.push_back(num);
                        first_time = 0;
                    }
                }

                temp_size -= 1;


            } catch (const char* msg) {
                cerr << msg << endl;
            }


        }

        // cout << endl;

        for (int i = star.size() - 1 ; i >= 0 ; i--) {
            cout << star[i] << " ";
        }
        cout << endl;

        for (int i = superstar.size() - 1 ; i >= 0  ; i--) {
            cout << superstar[i] << " ";
        }
        if (superstar.size() <= 0)
            cout << "-1";
        cout << endl;

        tests--;
    }
    return 0;
}
