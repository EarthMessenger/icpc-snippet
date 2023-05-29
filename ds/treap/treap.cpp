#include <random>

std::mt19937 mt;

struct Treap
{
	struct node_t
	{
		using pnode_t = node_t *;

		int key;
		const int rank;
		int cnt;
		int size;

		pnode_t l, r;

		node_t(int key) : key(key), rank(mt()), cnt(1), size(1), l(nullptr), r(nullptr)
		{
		}

		void update_size()
		{
			size = cnt;
			if (l) size += l->size;
			if (r) size += r->size;
		}
	};

	using pnode_t = node_t::pnode_t;

	template <typename compare>
	std::tuple<pnode_t, pnode_t> split(pnode_t p, const int key, compare cmp)
	{
		if (p == nullptr) {
			return {nullptr, nullptr};
		} else if (cmp(p->key, key)) {
			pnode_t r;
			std::tie(p->r, r) = split(p->r, key, cmp);
			p->update_size();
			return {p, r};
		} else {
			pnode_t l;
			std::tie(l, p->l) = split(p->l, key, cmp);
			p->update_size();
			return {l, p};
		}
	}

	pnode_t merge(pnode_t p, pnode_t q)
	{
		if (p == nullptr && q == nullptr) return nullptr;
		if (p == nullptr) return q;
		if (q == nullptr) return p;
		if (p->rank < q->rank) {
			p->r = merge(p->r, q);
			p->update_size();
			return p;
		} else {
			q->l = merge(p, q->l);
			q->update_size();
			return q;
		}
	}

	pnode_t root;

	Treap() : root(nullptr) {}
};
