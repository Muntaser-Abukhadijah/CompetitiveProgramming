// ~/BAU/ACM-ICPC/Teams/Rampage/Abukhadijah
// ~/Remember,remember the 6th of March
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
#include <unordered_map>
#include<unordered_set>
#include <numeric>
#include <string>
#include<iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include<cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 109;
typedef unsigned long long ull;
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
vector<int>arr, seg;
void build(int p, int s, int e)
{
	if (s == e)
	{
		seg[p] = arr[s];
		return;
	}
	build(p * 2, s, (s + e) / 2);
	build(p * 2 + 1, (s + e) / 2 + 1, e);
	seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
}
void update(int p, int s, int e, int i, int v)
{
	if (s == e)
	{
		seg[p] = v;
		return;
	}
	if (i <= (s + e) / 2)
		update(p * 2, s, (s + e) / 2, i, v);
	else
		update(p * 2 + 1, (s + e) / 2 + 1, e, i, v);
	seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
}
int get(int p, int s, int e, int a, int b)
{
	if (s >= a && e <= b)
		return seg[p];
	if (s > b || e < a)
		return -1e9;
	return max(get(p * 2, s, (s + e) / 2, a, b), get(p * 2 + 1, (s + e) / 2 + 1, e, a, b));
}
int main()
{
	int n;
	scanf("%d", &n);
	arr.resize(n);
	seg.resize(4 * n);
	for (int &i : arr)
		scanf("%d", &i);
	build(1, 0, n - 1);
	return 0;
}
