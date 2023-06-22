#include <limits>
#include <queue>
#include <vector>

struct edge_t
{
	int v, w;
};

std::pair<std::vector<int>, bool>
bellmanford(const std::vector<std::vector<edge_t>> &adj, int st)
{
	const int n = adj.size();
	std::vector<int> dis(n, std::numeric_limits<int>::max());
	std::vector<bool> vis(n);
	std::queue<int> q;
	std::vector<int> cnt(n, 0);
	dis[st] = 0;
	vis[st] = true;
	q.emplace(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[st] = false;
		for (auto [v, w] : adj[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) return {{}, false};
				if (!vis[v]) {
					vis[v] = true;
					q.emplace(v);
				}
			}
		}
	}
	return {dis, true};
}
