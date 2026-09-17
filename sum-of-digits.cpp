#include <iostream>
using namespace std;

int sumOfDigits(int number) {
	if (number < 10) {
		return number;
	}

	return number % 10 + sumOfDigits(number / 10);
}

int main() {
	int number;
	cin >> number;

	cout << sumOfDigits(number) << endl;
	return 0;
}
