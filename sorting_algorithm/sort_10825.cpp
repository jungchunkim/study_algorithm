#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Point {
	string name;
	int kor;
	int eng;
	int math;
};

bool compare(Point a, Point b)
{
	if (a.kor > b.kor)
	{
		return true;
	}
	else if (a.kor == b.kor)
	{
		if (a.eng < b.eng)
		{
			return true;
		}
		else if (a.eng == b.eng)
		{
			if (a.math > b.math)
			{
				return true;
			}
			else if (a.math == b.math)
			{
				if (a.name < b.name)
					return true;
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
int main()
{
	int N;
	cin >> N;
	vector<Point> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
	}

	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].name <<"\n";
	}
}