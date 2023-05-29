#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

struct dinic_algorithm
{
	int n;
	int s, t;

	struct flow_edge
	{
		int u, v;
		int cap, flow;
		flow_edge(int u, int v, int cap) : u(u), v(v), cap(cap), flow(0)
		{
		}
	};
	std::vector<flow_edge> edges;
	std::vector<std::vector<int>> adj;

	std::vector<int> level, ptr;

	dinic_algorithm(int n, int s, int t)
	    : n(n), s(s), t(t), adj(n), level(n), ptr(n)
	{
	}

	void add_edge(int u, int v, int cap)
	{
		adj[u].emplace_back((int)edges.size());
		edges.emplace_back(u, v, cap);
		adj[v].emplace_back((int)edges.size());
		edges.emplace_back(v, u, 0);
	}

	bool bfs()
	{
		std::fill(level.begin(), level.end(), -1);
		level[s] = 0;
		std::queue<int> q;
		q.emplace(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto id : adj[u]) {
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].v] != -1) continue;
				level[edges[id].v] = level[u] + 1;
				q.emplace(edges[id].v);
			}
		}
		return level[t] != -1;
	}

	int dfs() { return dfs(s, std::numeric_limits<int>::max()); }

	int dfs(int u, int flow_limit)
	{
		if (u == t || flow_limit == 0) return flow_limit;
		int res = 0;
		for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
			int id = adj[u][cid];
			int v = edges[id].v;
			if (level[v] != level[u] + 1 ||
			    edges[id].cap - edges[id].flow < 1)
				continue;
			int d = dfs(v, std::min(flow_limit, edges[id].cap - edges[id].flow));
			if (d == 0) continue;
			res += d;
			edges[id].flow += d;
			edges[id ^ 1].flow -= d;
			if (res == flow_limit) return res;
		}
		return res;
	}

	int flow()
	{
		int res = 0;
		while (true) {
			if (!bfs()) break;
			std::fill(ptr.begin(), ptr.end(), 0);
			while (int f = dfs()) { res += f; }
		}
		return res;
	}
};
