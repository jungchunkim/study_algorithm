#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 1e9

using namespace std;

int arr[51][51];
int temp[51][51];

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;


int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back({ i,j });
			}
			if (arr[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	vector<int> brr(chicken.size(), 0);

	for (int i = 0; i < M; i++) {
		brr[i] = 1;
	}

	int min_solution = INF;
	do {
		int solution = 0;
		vector<pair<int, int>> chicken_temp;
		for (int i = 0; i < brr.size(); i++) {
			if (brr[i] == 1) {
				chicken_temp.push_back({ chicken[i].first,chicken[i].second });
			}
		}

		for (int i = 0; i < house.size(); i++) {
			int min_dist = INF;
			int x = house[i].first;
			int y = house[i].second;

			for (int j = 0; j < chicken_temp.size(); j++) {
				int a = chicken_temp[j].first;
				int b = chicken_temp[j].second;

				int dist = abs(x - a) + abs(y - b);
				min_dist = min(dist, min_dist);
			}
			solution += min_dist;
		}
		min_solution = min(solution, min_solution);

	} while (prev_permutation(brr.begin(), brr.end()));

	cout << min_solution;
}