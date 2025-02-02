#include<iostream>
using namespace std;
long long factorial(int n){
	if (n<=1)return 1;
	return n*factorial(n-1);
}
int main(){
	int number;
	cout<<"Enter a positive integer: ";
	cin>>number;
	if(number<0){
		cout<<"Factorial is not defined for negative numbers."<<endl;
	}else{
		long long result=factorial(number);
		cout<<"The factorial of "<<number<<"is "<<result<<"."<<endl;
	}
	return 0;
}