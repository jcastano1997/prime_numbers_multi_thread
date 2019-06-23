#include <iostream>
#include <time.h> 
#include <stdio.h> 
#include <dos.h>
#include <thread>
using namespace std;

bool is_prime_number(int n, bool *result, int start, int end) {
    if (n <= 1)
    	return *result = false;
    	
    if (n <= 3)
    	return *result = true;
    	
    if (start <= 1)
		start = 2;
  
    for (int i = start; i <= end; i++)
        if (n % i == 0 || *result == false)
        	return *result = false;
}

int main(void) {
	clock_t start, end; 
	start = clock();
	//cout << "Start: "<<start<<endl;
	
	const int number_to_check = 2147483647;
	int number_of_threads = 4;
	thread myThreads[number_of_threads];
	bool prime = true;
	int jump = (number_to_check/2)/number_of_threads;
	if (jump < 1) {
		jump = number_to_check/2;
		number_of_threads = 1;
	}
	for(int i=0; i<number_of_threads; i++) {
		//cout<<"Hilo: "<<i<<endl;
		int start = i * jump;
		int end = start + jump;
		myThreads[i] = thread(is_prime_number, number_to_check, &prime, start, end);
	}
	for (int i=0; i<number_of_threads; i++){
		//cout<<"Join hilo: "<<i<<endl;
        myThreads[i].join();
    }
	prime ? cout<<"True\n" : cout<<"False\n";
	
	end = clock();
	//cout << "End: "<<end<<endl;
	printf("The time was: %i\n", (end - start)); 
	return 0;
}
