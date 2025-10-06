#include <iostream>
using namespace std;

void minMaxRep(int a[], size_t size, int& mn, size_t& in, int& mx, size_t& ix){
	if (size == 0) {
		mn = mx = 0;
		in = ix = 0;
		return;
	}

	mn = mx = a[0];
	in = ix = 0;

	for (size_t i = 0; i < size; i++) {
		if (a[i] < mn) {
			mn = a[i];
			in = 1;
		}
		else if (a[i] == mn) {
			in++;
		}

		if (a[i] > mx) {
			mx = a[i];
			ix = 1;
		}
		else if (a[i] == mx) {
			ix++;
		}
	}
}
void zadanie1() {
	int input = -1;
	int numberWithHighestSum = 0;
	int highestSum = 0;
	int temp = 0;

	while (input != 0) {
		cout << "enter a natural number (0 if done): ";
		cin >> input;
		
		int inputedNumber = input;

		while (inputedNumber > 0) {
			temp += inputedNumber % 10;
			inputedNumber /= 10;
		}

		if (temp > highestSum) {
				highestSum = temp;
				numberWithHighestSum = input;
			}

		temp = 0;
		
	}
	
	cout << "Max sum of digits was " << highestSum << " for " << numberWithHighestSum << endl;
}
void zadanie2(){
	cout << "enter three non-negative numbers: ";
	int a, b, c;
	cin >> a >> b >> c;

	if (a < 0 || b < 0 || c < 0) {
		cout << "You entered a negative number!" << endl;
		return;
	}

	for (int i = 0; i < a; i++) cout << "*" << endl;
	cout << endl;

	for (int i = 0; i < b; i++) cout << "*" << endl;
	cout << endl;

	for (int i = 0; i < c; i++) cout << "*" << endl;
	cout << endl;
}
void zadanie3(){
	int n = -1;
	int longestSequence = 1;
	int currentSequence = 1;
	int longestSequenceNumber = 0;
	int temp = 0;

	while (n != 0){
		cout << "enter an integer (0 to exit): ";
		cin >> n;
		
		if (n == temp) currentSequence++;
		else currentSequence = 1;

		temp = n;

		if (currentSequence > longestSequence) {
			longestSequence = currentSequence;
			longestSequenceNumber = n;
		}
	}

	cout << "Longest sequence: " << longestSequence << " times " << longestSequenceNumber << endl;
}
void zadanie4(){
	int a[] {2,3,4,2,7,4,7,2};
	size_t size = sizeof(a)/sizeof(a[0]);
	int mn = 0, mx = 0;
	size_t in = 0, ix = 0;
	minMaxRep(a, size, mn, in, mx, ix);
	cout << "Array: [";
	for (size_t i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << "]" << endl;
	cout << "Min: " << mn << " " << in << " times" << endl;
	cout << "Max: " << mx << " " << ix << " times" << endl;
}
void zadanie5(){
	// not implemented
}

int main() {
	int enteredNumber = -1;

	while (true){
		cout << "enter exercise number (1-4) (0 to exit): ";
		cin >> enteredNumber;

		if (enteredNumber == 0) break;

		switch (enteredNumber) {
			case 1:
				zadanie1();
				break;
			case 2:
				zadanie2();
				break;
			case 3:
				zadanie3();
				break;
			case 4:
				zadanie4();
				break;
			case 5:
				zadanie5();
				break;
			
			default:
				cout << "invalid exercise number!" << endl;
				break;
		}
	}

	return 0;
}