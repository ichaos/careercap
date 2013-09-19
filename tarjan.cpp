//strong connect components
#include <stack>
#include <algorithm>

using namespace std;

struct vertex
{
	int i;
	vector<int> edge;
	bool visited;
};

struct graph
{
	vector<vertex> vertexes;
};

std::vector<int> dfn;
std::vector<int> low;
int index = 0;
std::vector<bool> inStack;

void _tarjan(vector<vector<> > &sets, graph &g, vertex &v, stack &s) {
	s.push(v);
	dfn[v.i] = index++;
	low[v.i] = dfn[v.i];
	for (int i = 0; i < v.edge.size(); i++) {
		if (!g.vertexes[v.edge[i]].visited) {
			_tarjan(sets, g, g.vertexes[v.edge[i]], s);
			low[v.i] = min(low[v.i], low[v.edge[i]]);
		} else if (inStack[v.edge[i]]) {
			low[v.i] = min(low[v.i], low[v.edge[i]]);
			//it should same with the following sentence in this algorithm
			//low[v.i] = min(low[v.i], dfn[v.edge[i]]);
		}
	}

	if (low[v.i] == dfn[v.i]) {
		//find a new SCC
		vector<int> scc;
		int nv = 0;
		do {
			nv = s.top();
			s.pop();
			scc.push_back(nv);
			sets.push_back(scc);
		} while (nv != v.i)
	}
}

void tarjan(vector<vector<> > &sets, graph &g) {
	//dfs
	stack<int> s;
	for (int i = 0; i < g.vertexes.size(); i++) {
		if (!g.vertexes[i].visited)
			_tarjan(sets, g, g.vertexes[i]);
	}
}