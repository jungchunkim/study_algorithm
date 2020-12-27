#include <iostream>
using namespace std;
#define MAX 100

int R[MAX + 1][MAX];

struct nodetype {
	int key;
	nodetype* left;
	nodetype* right;
};
typedef nodetype* node_pointer;

void optsearchtree(int n, int p[])
{
	int i, j, k, diagonal;
	int min;
	int temp;
	int A[MAX + 1][MAX] = { 0 };

	for (int i = 1; i <= n; i++)
	{
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}

	A[n + 1][n] = 0;
	R[n + 1][n] = 0;	// 정해진 부분 초기화 시켜준 것 


	for (diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		
		for (i = 1; i <= n - diagonal; i++)
		{
			temp = 0;
			j = i + diagonal;
			min = 100000;	//충분히 큰 값 넣어준다
			for (k = i; k <= j; k++)
			{
				if (min > A[i][k - 1] + A[k + 1][j])
				{
					min = A[i][k - 1] + A[k + 1][j];
					A[i][j] = min;
					R[i][j] = k;
				}
				temp += p[k];
			}
			A[i][j] += temp;
		}
	}
}


node_pointer tree(int i,int j, int key[])
{
	int k;
	node_pointer p;
	k = R[i][j];

	if (k == 0)
		return NULL;
	else {
		p = new nodetype;
		p->key = key[k];
		p->left = tree(i, k - 1, key);
		p->right = tree(k + 1, j, key);
		return p;
	}
}

void preorder(node_pointer p)
{
	if (p == NULL)
		return;
	else
	{
		cout << p->key << " ";
		preorder(p->left);
		preorder(p->right);
	}
}

int main()
{
	int n,k,m;
	node_pointer p;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> k;

		for(int l=0;l<MAX;l++)
			for(int v=0;v<MAX-1;v++)
				R[l][v]=0;

		int *arr = new int[k+1];
		int *key = new int[k+1];

		for (int j = 1; j <=k; j++)
		{
			cin >> m;
			arr[j] = m;
			key[j] = j;
		}

		optsearchtree(k, arr);
		p = tree(1, k, key);
		preorder(p);
		cout<<"\n";

		delete []arr;
		delete []key;
	}

}