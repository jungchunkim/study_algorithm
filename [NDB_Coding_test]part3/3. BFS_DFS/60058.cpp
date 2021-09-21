
#include <string>
#include <stack>

using namespace std;
bool isRightstr(string s, int *p) {
	stack<char> st;

	bool ret = true;

	int left = 0;
	int right = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			left++;
			st.push(s[i]);
		}
		else {
			right++;
			if (st.empty()) {
				ret = false;
			}
			else {
				st.pop();
			}
		}

		if (right == left) {
			*p = i + 1;
			break;
		}
	}
	return ret;
}

string solution(string p) {
	string sol = "";
	// 균형자빈 문자열 , 올바른 문자열
	// 1. 입력이 빈 문자열일때
	if (p.size() == 0) {
		return sol;
	}

	int pos = 0;
	bool check_string = isRightstr(p, &pos);

	string u = p.substr(0, pos);
	string v = p.substr(pos);

	if (check_string) {
		return u + solution(v);

	}
	else {
		sol = '(' + solution(v) + ')';
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == ')') {
				sol += '(';
			}
			else {
				sol += ')';
			}
		}

		return sol;
	}


}