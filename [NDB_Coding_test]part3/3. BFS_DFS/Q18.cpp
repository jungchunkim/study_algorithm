#include <string>
#include <stack>

using namespace std;

bool isCorrect(string k, int* p) {
	// 올바른 문자열인지 확인하는 함수 
	bool ret = true;
	int left = 0, right = 0;
	stack<char> arr;

	for (int i = 0; i < k.length(); i++) {
		if (k[i] == '(') {
			left++;
			arr.push('(');
		}
		else {
			right++;
			if (arr.empty()) {
				ret = false;
			}
			else
			{
				arr.pop();
			}

		}
		if (left == right) {
			*p = i + 1;
			return ret;
		}
	}
}

string solution(string p) {

	if (p.empty()) {
		return p;
	}

	int pos = 0;
	bool check_string = isCorrect(p, &pos);

	string u = p.substr(0, pos);
	string v = p.substr(pos, p.length() - pos);

	if (check_string) {
		//u가 올바른 괄호 문자열이라면
		return u + solution(v);
	}
	else {
		//u가 올바른 괄호 문자열이 아니라면
		string sol = "(" + solution(v) + ")";
		for (int i = 1; i < u.length() - 1; i++) {
			if (u[i] == '(') {
				sol += ")";
			}
			else {
				sol += "(";
			}
		}
		return sol;
	}
}