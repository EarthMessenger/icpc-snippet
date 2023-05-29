#include <stack>
#include <vector>

struct tarjan_algorithm
{
	int n;
	std::vector<std::vector<int>> adj;

	std::vector<int> dfn, low;
	int dfn_cnt;
	std::stack<int> stack;
	std::vector<bool> in_stack;
	std::vector<int> scc;
	int scc_cnt;

	tarjan_algorithm(int n)
			: n(n), adj(n), dfn(n, -1), low(n), dfn_cnt(0), in_stack(n), scc(n),
				scc_cnt(0)
	{
	}

	void add_edge(int u, int v) { adj[u].emplace_back(v); }

	void dfs(int u)
	{
		low[u] = dfn[u] = dfn_cnt++;
		stack.emplace(u);
		in_stack[u] = true;

		for (auto v : adj[u]) {
			if (dfn[v] == -1) {
				dfs(v);
				low[u] = std::min(low[u], low[v]);
			} else if (in_stack[v]) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			int tmp;
			do {
				tmp = stack.top();
				stack.pop();
				in_stack[tmp] = false;
				scc[tmp] = scc_cnt;
			} while (tmp != u);
			scc_cnt++;
		}
	}

	bool same_scc(int i, int j) { return scc[i] == scc[j]; }
};
