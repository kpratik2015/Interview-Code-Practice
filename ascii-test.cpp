#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str = "abc)+";

	if( str[1] >= 'a' && str[1] <= 'z' && str[3] == ')' && str[4] == '+')
		cout<<"TRUE"<<endl;

	stack<char> s1;

	for(int i = 0 ; i < str.size() ; i++){
		s1.push(str[i]);
		cout<<"PUSHING: "<<str[i]<<endl;
	}

	int size = s1.size();

	for(int i = 0 ; i < size ; i++){
		cout<<s1.top()<<endl;
		s1.pop();
	}

	cout<<s1.size()<<endl;

	return 0;
}