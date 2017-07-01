// Check if characters of a given string can be rearranged to form a palindrome
#include <iostream>

using namespace std;

bool CanBeMadePalindrome(string str) {
	
	int check[256] = {0}; // !! Init all to 0 !! Alphabets 0-255

	for(int i = 0 ; i < str.size() ; i++){
		check[str[i]]++;
	}
	int flag = 0; //this should only be 1
	for(int i = 0 ; i < 256 ; i++ ) {
		if( !(check[i] % 2 == 0) ) // if not even
			flag++;
	}

	return (flag == 1) ? true : false;
	
}

int main(){

	if( CanBeMadePalindrome("yakak") )
		cout<<"Yes, permutation of string can make palindrome";
	else
		cout<<"No, palindrome not possible";
	

	return 0;
}

/* SOLUTION:

Every character occurs twice except one character which is the center
e.g. mmo
yakak 

OUTPUT:

*/