#include <iostream>
#include <algorithm>
#include <fstream>

int main() {
	constexpr size_t N = 5;
	int greatest[N];
	std::ifstream inpfile("NGreatest.dat");
	size_t count{0}; // ile liczb zostało wczytanych
	int n{}; // n to ostatnio używana liczba
	size_t ile{}; // ile liczb zostało umieszczonych w tablicy greatest
	bool containsN = false; // domyslnie ustawiamy na false poniewaz zaczynamy od pustej tablicy
	int nextIndex = 0; // następny index tablicy greatest[], który zostanie zapełniony wczytaną liczbą

	while (inpfile >> n) {
		containsN = false;
		count++;

		for (size_t i = 0; i < N; i++) {
			if (greatest[i] ==  n){ // sprawdzamy czy wczytana liczba pojawila sie juz w tablicy
				containsN = true;
			}
		}

		if (!containsN) {
			greatest[nextIndex] = n;
			ile++;
			nextIndex++;
		}

		if (ile == N) { // w momencie w którym zapełnimy całą tablice wyszukujemy index dla którego wartość jest najmniejsza, aby potencjalnie w przyszłości zastąpić go większą wartoscią
			nextIndex = 0;
			for (size_t i = 1; i < N; i++) {
				if (greatest[i] < greatest[nextIndex]){
					nextIndex = i;
				}
			}
		}

	}

	// numData - liczba uzyskanych elementów
	// w greatest, może być mniejsza od N
	size_t numData = std::min(ile, N);
	std::cout << count << " numbers read. Greatest " << numData << " different are: ";
	for (size_t i = 0; i < numData; i++)
		std::cout << greatest[i] << " ";
	std::cout << "\n";
}