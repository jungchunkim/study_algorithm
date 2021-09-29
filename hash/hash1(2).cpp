#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

	map<string, int> m;

	for (int i = 0; i < completion.size(); i++) {
		m[completion[i]]++;
	}

	for (int i = 0; i < participant.size(); i++) {
		m[participant[i]]--;

		if (m[participant[i]] < 0) {
			return participant[i];
		}
	}
}