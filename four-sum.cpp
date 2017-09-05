/*
http://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

Given an array A of size N, find all combination of four elements
in the array whose sum is equal to a given value K. For example,
if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of
the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

Input:
2
5 3
0 0 2 1 1
7 23
10 2 3 4 5 7 8
Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/

#include <bits/stdc++.h>
using namespace std;
int t, n, k, arr[110], flag = 0;

int main()
{
  cin >> t;
  while (t--) {
    cin >> n >> k;
    flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {

      cout << "i: " << i << endl;

      // If arr[i] element is same as previous element
      // then skip this element using continue
      if (i != 0 and arr[i] == arr[i - 1]) {
        cout << "i != 0 and arr[" << i << "] == arr[" << i - 1 << "]" << endl;
        cout << "CONTINUE" << endl;
        continue;
      }

      // j starts ahead of i
      for (int j = i + 1; j < n; j++) {

        cout << "\nj: " << j << endl;

        // If arr[j] element is same as previous element
        // then skip this element using continue
        if (j != i + 1 and arr[j] == arr[j - 1]) {
          cout << " j != i + 1 and arr[" << j << "] == arr[" << j - 1 << "]" << endl;
          continue;
        }

        // x is starts ahead of j
        // y starts from last element of array
        int x = j + 1;
        int y = n - 1;

        cout << "x: " << x << "  " << "y: " << y << endl;

        cout << "WHILE x < y: " << endl;

        while (x < y) {
          
          cout << "x: " << x << "  " << "y: " << y << endl;

          // if sum of 4 pointer (i,j,x,y) elements is 'less' than
          // asked sum then 'advance' x pointer
          if (arr[i] + arr[j] + arr[x] + arr[y] < k)
            x++;
          // if sum of 4 pointer (i,j,x,y) elements is 'greater' than
          // asked sum then 'decrement' y pointer since array is sorted
          // in ascending order 
          else if (arr[i] + arr[j] + arr[x] + arr[y] > k)
            y--;
          else {
            cout << arr[i] << " " << arr[j] << " " << arr[x] << " " << arr[y] << " $";
            int p = arr[x];
            // after finding needed sum, advance x until the element is not
            // same as arr[x]
            while (arr[x] == p)
              x++;
            flag = 1;
          }
        }
      }
    }
    if (flag == 0)
      cout << -1 << endl;
    else
      cout << endl;
  }
  return 0;
}