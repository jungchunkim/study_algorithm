#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	string s1 = "";
	string s2 = "";

	for (int i = 0; i < 3; i++) {
		s1 = s1 + a[2 - i];
		s2 = s2 + b[2 - i];
	}

	int num1 = stoi(s1);
	int num2 = stoi(s2);

	if (num1 > num2) {
		cout << num1;
	}
	else {
		cout << num2;
	}
}