#include <iostream>
using namespace std;

void towerOfHanoi(int diskCount, char source, char auxiliary, char destination) {
	if (diskCount == 1) {
		cout << "Move disk 1 from " << source << " to " << destination << endl;
		return;
	}

	towerOfHanoi(diskCount - 1, source, destination, auxiliary);
	cout << "Move disk " << diskCount << " from " << source << " to " << destination << endl;
	towerOfHanoi(diskCount - 1, auxiliary, source, destination);
}

int main() {
	int diskCount;
	cin >> diskCount;

	if (diskCount > 0) {
		towerOfHanoi(diskCount, 'A', 'B', 'C');
	}

	return 0;
}
