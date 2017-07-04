/*
There are N points on the road ,you can step ahead by 1 or 2 .
Find the number of ways you can reach at point N.
For example:  for n=4 we have 5 possible ways 
[1,1,1,1]  [1,1,2]  [1,2,1]  [2,1,1]  [2 2].
*/

#include <iostream>

using namespace std;

int main() {
	long long int num, tests, t1 = 1, t2 = 2, nextTerm = 0;
	// test cases
	cin>>tests;

	while(tests--) {
		cin>>num;
		if( num > 2 ) {
			for(int i = 2 ; i < num ; i++){
				nextTerm = t1;
				t1 = t2;
				t2 = nextTerm + t2;
			}
			cout<<t2;
		}
		else {
			cout<<num;
		}
		cout<<endl;
	}

	return 0;
}