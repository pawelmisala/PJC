#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

std::vector<size_t> smallSum3(const std::vector<int>& a) {
	int smallestSum;
	int temp;
	std::vector<size_t> result;

	size_t n = a.size();

	if (n > 3) {
		smallestSum = a[0] + a[1] + a[2];
		for (int i = 0; i < n-2; i++){
			for (int j = i+1; j < n-1; j++){
				for (int k = j+1; k < n; k++){
					temp = a[i] + a[j] + a[k];
					if (abs(temp) < abs(smallestSum)) {
						result.erase(result.begin(), result.end());
						result.push_back(i);
						result.push_back(j);
						result.push_back(k);
						smallestSum = temp;
					} 
				}
			}
		}
	}
	return result;
}

int main() {
	std::vector<int> a {2, -13, 3, 6, 4, 5, -14, 1, -15};
	auto r = smallSum3(a);

	std:printf("Sum=%d for elements "
		"a[%zu]=%d, a[%zu]=%d, a[%zu]=%d\n",
		a[r[0]]+a[r[1]]+a[r[2]],
		r[0], a[r[0]], r[1], a[r[1]], r[2], a[r[2]]
	);

	return 0;
}
