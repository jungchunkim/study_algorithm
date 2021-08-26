#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b)
{
	if (a.second > b.second)
	{
		return true;
	}
	else
	{
		if (a.second == b.second)
		{
			if (a.first < b.first)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	sort(stages.begin(), stages.end());

	//N+1 까지 담아야하므로!
	vector<double> arr(N + 2, 0);
	
	for (int i = 0; i < stages.size(); i++)
	{// (1~N+1)개수 배열에 담아
		arr[stages[i]]++;
	}

	vector<pair<int, double>> sol;

	double num_people = stages.size();
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			sol.push_back({ i,0 });
		}
		else
		{
			sol.push_back({ i,arr[i] / num_people });
		}
		num_people -= arr[i];
	}

	sort(sol.begin(), sol.end(), compare);

	for (int i = 0; i < sol.size(); i++)
	{
		answer.push_back(sol[i].first);
	}
	return answer;
}