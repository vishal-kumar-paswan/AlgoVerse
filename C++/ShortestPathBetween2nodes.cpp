// C++ representation of finding shortest
// distance between node i and j
#include <bits/stdc++.h>
using namespace std;

// prints the path between node i and node j
void ShortestPath(int i, int j, int k, int m, int n)
{
	// path1 stores path of node i to lca and
	// path2 stores path of node j to lca
	vector<int> path1, path2;
	int x = m - 1;

	// push node i in path1
	path1.push_back(i);

	// keep pushing parent of node labelled
	// as i to path1 until lca is reached
	while (x != k) {
		path1.push_back(i / 2);
		i = i / 2;
		x--;
	}
	int y = n - 1;

	// push node j to path2
	path2.push_back(j);

	// keep pushing parent of node j till
	// lca is reached
	while (y != k)
	{
		path2.push_back(j / 2);
		j = j / 2;
		y--;
	}

	// printing path from node i to lca
	for (int l = 0; l < path1.size(); l++)
		cout << path1[l] << " ";

	// printing path from lca to node j
	for (int l = path2.size() - 2; l >= 0; l--)
		cout << path2[l] << " ";
	cout << endl;
}

// returns the shortest distance between
// nodes labelled as i and j
int ShortestDistance(int i, int j)
{
	// vector to store binary form of i and j
	vector<int> v1, v2;

	// finding binary form of i and j
	int p1 = i;
	int p2 = j;
	while (i != 0) 
	{
		v1.push_back(i % 2);
		i = i / 2;
	}
	while (j != 0) {
		v2.push_back(j % 2);
		j = j / 2;
	}

	// as binary form will be in reverse order
	// reverse the vectors
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());

	// finding the k that is lca (i, j)
	int m = v1.size(), n = v2.size(), k = 0;
	if (m < n)
	{
		while (k < m && v1[k] == v2[k])
			k++;
	}
	else {
		while (k < n && v1[k] == v2[k])
			k++;
	}

	ShortestPath(p1, p2, k - 1, m, n);
	return m + n - 2 * k;
}

// Driver Code
int main()
{
	cout << ShortestDistance(1, 2) << endl;
	cout << ShortestDistance(4, 3) << endl;
	return 0;
}
