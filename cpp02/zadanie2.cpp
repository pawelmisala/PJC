#include <iostream>
#include <cmath>

const double* aver(const double* arr, size_t size, double& average) {
    for (int i = 0; i < size; i++) {
		average += arr[i];
	}	
	average /= size;

	double temp = arr[0];
	double absToAverage = abs(average - temp);
	double resultValue;
	double* pResult = &temp;

	for (int i = 0; i < size; i++){
		if (abs(average - arr[i]) < absToAverage) {
				resultValue = arr[i];
		} 
	}

	pResult = &resultValue;

	return pResult;
}

int main () {
    using std::cout; using std::endl;

	double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
	size_t size = sizeof arr / sizeof arr[0];

    double average = 0;
    const double* p = aver(arr, size, average);
    cout << *p << " " << average << endl;
}