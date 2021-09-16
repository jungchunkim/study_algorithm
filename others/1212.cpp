#include <iostream>
#include <string>

using namespace std;


int main() {
	string s;
	cin >> s;

	if (s == "0") {
		cout << s;
		return 0;
	}


	string result = "";

	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';

		string k = "";

		if (num == 0) {
			cout << "000";
			continue;
		}

		while (num != 1) {
			int a = num / 2;
			int b = num % 2;

			k = to_string(b) + k;
			num = a;
		}
		k = "1" + k;

		if (i != 0) {
			if (k.size() == 2) {
				k = "0" + k;
			}
			else if (k.size() == 1) {
				k = "00" + k;
			}
		}

		cout << k;


	}

}