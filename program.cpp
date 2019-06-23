#include <iostream>
#include <time.h> 
#include <stdio.h> 
#include <dos.h>
using namespace std;

bool is_prime_number(int n) {
	// Casos de esquina
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false; 
  
    return true;
}

int main(void) {
	clock_t start, end; 
	start = clock();
	cout << "Start: "<<start<<endl;
	
	const int number_to_check = 2147483647;
	is_prime_number(number_to_check) ? cout<<"True\n" : cout<<"False\n";
	
	end = clock();
	cout << "End: "<<end<<endl;
	printf("The time was: %i\n", (end - start)); 
	return 0;
}
