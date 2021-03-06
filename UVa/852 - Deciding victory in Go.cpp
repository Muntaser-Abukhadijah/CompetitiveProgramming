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
void fast()
{
	stdios_basesync_with_stdio(0);
}
char grid[10][10];
bool vis[10][10];
setintst;
int dirx[] = { 0,0,1,-1 };
int diry[] = { 1,-1,0,0 };
bool valid(int x, int y)
{
	return x  -1 && x9 && y-1 && y  9;
}
int cnt,n;
void floodfill(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i  4; i++)
	{
		int tox = x + dirx[i], toy = y + diry[i];
		if (valid(tox, toy)&&!vis[tox][toy])
		{
			if (grid[tox][toy] == 'X')
			{
				st.insert(1);
				vis[tox][toy];
				continue;
			}
			else if (grid[tox][toy] == 'O')
			{
				st.insert(2);
				vis[tox][toy];
				continue;
			}
			else
				cnt++;
			floodfill(tox, toy);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen(input.txt, r, stdin);
	freopen(output.txt,w,stdout);
#endif
	cin  n;
	while (n--)
	{
		memset(vis, 0, sizeof(vis));
		int cntB = 0, cntW = 0;
		for (int i = 0; i  9; i++)
			for (int j = 0; j  9; j++)
			{
				scanf( %c, &grid[i][j]);
				if (grid[i][j] == 'O')
					cntW++;
				else if (grid[i][j] == 'X')
					cntB++;
			}
		for (int i = 0; i  9; i++)
		{
			for (int j = 0; j  9; j++)
			{
				if (grid[i][j] == '.' && !vis[i][j])
				{
					cnt = 1;
					st.clear();
					floodfill(i, j);
					if (st.size() == 1)
					{
						if ((st.begin()) == 1)
							cntB += cnt;
						else
							cntW += cnt;
					}
				}
			}
		}
		printf(Black %d White %dn, cntB, cntW);
	}
	return 0;
}
