// CS 2336
// Lab 01
// Kangmin Kim

#include <iostream>

 using namespace std;


unsigned int converter(unsigned int);


const string ID = "Kangmin Kim - CS 2336 - Lab 01";
int main() {
	
	cout << ID << endl << endl;
	
	
	unsigned int num, count = 0;

	while (cin >> num) {
		cout << num;
		for(; num >= 10; num = converter(num)) {
			cout  << " -> " << converter(num);
			count++;
				

		}
		cout << " persistence = " << count<< "\n";
		count = 0;
	}

		}
	



unsigned int converter(unsigned int num){
	int digit, product;
	
	product = num == 0 ? 0 : 1;
	
	while (num != 0) {
		digit = num % 10;
		product *= digit;
		num /= 10;
	}

	return product;
}
