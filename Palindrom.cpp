#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& text, int left, int right) {
	if (left >= right) {
		return true;
	}

	if (text[left] != text[right]) {
		return false;
	}

	return isPalindrome(text, left + 1, right - 1);
}

int main() {
	string text;
	cin >> text;

	if (isPalindrome(text, 0, static_cast<int>(text.length()) - 1)) {
		cout << "Palindrome" << endl;
	} else {
		cout << "Not a palindrome" << endl;
	}

	return 0;
}