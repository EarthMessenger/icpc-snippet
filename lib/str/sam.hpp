struct suffix_automaton
{
  struct node_t
  {
    std::array<int, 26> next;
    int link;
    int len;
    node_t() : link(0), len(0) { std::fill(next.begin(), next.end(), -1); }
  };

  int n;
  std::vector<node_t> t;
  int last;

  suffix_automaton() : n(0), t(1), last(0) {}

  int new_node()
  {
    int id = t.size();
    t.emplace_back();
    return id;
  }

  int size() const { return t.size(); }

  void append(char ch)
  {
    int cv = ch - 'a';
    int x = new_node();
    t[x].len = n + 1;
    int p = last;
    while (p != 0 && t[p].next[cv] == -1) {
      t[p].next[cv] = x;
      p = t[p].link;
    }
    if (t[p].next[cv] == -1) {
      t[p].next[cv] = x;
    } else {
      int q = t[p].next[cv];
      if (t[p].len + 1 == t[q].len) {
        t[x].link = q;
      } else {
        int nq = new_node();
        t[nq].next = t[q].next;
        t[nq].link = t[q].link;
        t[q].link = nq;
        t[nq].len = t[p].len + 1;
        while (p != 0 && t[p].next[cv] == q) {
          t[p].next[cv] = nq;
          p = t[p].link;
        }
        if (t[p].next[cv] == q) t[p].next[cv] = nq;
        t[x].link = nq;
      }
    }
    last = x;
    n++;
  }
};
