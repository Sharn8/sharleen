#include<iostream>
#include<cmath>
int main(){
	double x;
	std::cout<<"Enter a number to find it's square root:";
	std::cin>>x;
	if (x<0){
		std::cout << "Error: Cannot compute the square root of a negative number." << std::endl;
    } else {
        // Calculate the square root
        double result = sqrt(x);
        // Display the result
        std::cout << "The square root of " << x << " is " << result << "." << std::endl;
    }

    return 0;
	}
