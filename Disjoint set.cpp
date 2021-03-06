struct disjointset
{
	vector<int>par, ranks;
	int forests;
	disjointset(int n)
	{
		forests = n;
		par.resize(n);
		ranks.resize(n);
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			ranks[i] = 1;
		}
	}
	int find(int u)
	{
		if (u == par[u])return u;
		return par[u] = find(par[u]);
	}
	void linker(int x, int y)
	{
		if (ranks[x] > ranks[y])
			swap(x, y);
		par[x] = y;
		if (ranks[x] == ranks[y])
			ranks[y]++;
	}
	bool unions(int x, int y)
	{
		x = find(x), y = find(y);
		if (x != y)
		{
			linker(x, y);
			forests--;
		}
		return x != y;
	}
};
