 ~Remember,remember the 6th of March
#include functional
#include iomanip
#include stdio.h
#include vector
#include algorithm
#includecomplex
#include unordered_map
#includeunordered_set
#include numeric
#include string
#includeiostream
#include fstream
#include assert.h
#include ctype.h
#include limits.h
#include math.h
#includecmath
#include stdlib.h
#include math.h
#include string.h
#include time.h
#include bitset
#include map
#include queue
#include set
#include stack
#include sstream
using namespace std;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 100000 + 7;
typedef unsigned long long ull;
freopen(input.txt,r,stdin);
freopen(output.txt,w,stdout);
void fast()
{
	stdios_basesync_with_stdio(0);
}
struct edge
{
	int from, to, nelev, cost;
	edge(int f, int t, int ne, int co)
	{
		from = f, to = t, nelev = ne, cost = co;
	}
	bool operator (const edge &e)const
	{
		return cost  e.cost;
	}
};
int n, k, x;
priority_queueedgepq;
vectorintt, temp, dist;
vectorvectoredgeadjl;
void dijkstra(int dest)
{
	while (!pq.empty())
	{
		edge e = pq.top(); pq.pop();
		if (dist[e.to]  e.cost)continue;
		for (int i = 0; i  adjl[e.to].size(); i++)
		{
			edge ne = adjl[e.to][i];
			int cost = 0;
			if (ne.nelev != e.nelev)
				cost += 60;
			cost += (abs(ne.from - ne.to))t[ne.nelev] + e.cost;
			if (cost  dist[ne.to])
			{
				dist[ne.to] = ne.cost = cost;
				pq.push(ne);
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(input.txt, r, stdin);
#endif
	while (scanf(%d%d, &n, &k) != EOF)
	{
		pq = priority_queueedge();
		dist.clear();
		dist.resize(101, 2e9);
		t.clear();
		t.resize(n);
		for (int i = 0; i  n; i++)
			scanf(%d, &t[i]);
		adjl.clear();
		adjl.resize(101);
		for (int i = 0; i  n; i++)
		{
			string s;
			if(i==0)
				getline(cin, s);
			getline(cin, s);
			stringstream iss(s);
			while (1)
			{
				iss  x;
				if (!iss)
					break;
				temp.push_back(x);
				if (x == 0)
				{
					pq.push({ -1,0,i,0 });
					dist[0] = 0;
				}
			}
			for (int k = 0; k  temp.size(); k++)
				for (int j = 0; j  temp.size(); j++)
				{
					if (j == k)continue;
					adjl[temp[k]].push_back({ temp[k],temp[j],i,t[i] });
				}
			temp.clear();
		}
		dijkstra(k);
		if (dist[k] == 2e9)
			puts(IMPOSSIBLE);
		else
			printf(%dn, dist[k]);
	}
	return 0;
}
