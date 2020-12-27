#include <iostream>
#include <stdio.h>
using namespace std;

int RGB[3] = {0};
int n, r, g, b;
enum { R, G, B };


int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int ir = RGB[R];
		int ig = RGB[G];
		int ib = RGB[B];

		cin >> r >> g >> b;
		RGB[R] = r + min(ig, ib);
		RGB[G] = g + min(ir, ib);
		RGB[B] = b + min(ir, ig);
	}
	cout << min(RGB[R], min(RGB[G], RGB[B])) << endl;
	return 0;
}


