#include <iostream>
#include <time.h> 
#include <stdio.h> 
#include <dos.h>
using namespace std;

bool is_prime_number(int number) {
	if (number > 1) {
		int limit = number/2;
		for(int count = 2; count <= limit; count++)
		{
			if(number % count == 0) {
				return false;
			}
		}
		return true;
	} else {
		cout<<"The number must be greater than 1"<<endl;
		return false;
	}
}

int main(void) {
	clock_t start, end; 
	start = clock();
	cout << "Start: "<<start<<endl;
	const unsigned long number_to_check = 2147483647;
	if (is_prime_number(number_to_check)) {
		cout << "Number is Prime."<<endl;
	} else {
		cout << "Number is not Prime."<<endl;
	}
	end = clock();
	cout << "End: "<<end<<endl;
	printf("The time was: %i\n", (end - start)); 
	return 0;
}
