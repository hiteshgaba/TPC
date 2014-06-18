#include <iostream>
#include <list>

using namespace std;

struct vertex 
{
	int v;
	int edge; //Edge No
};

int * edgearray;	//Global array of edge for weights
int endnode;		//For the ending node
bool flag;	//Bool for checking when to stop
int maxweight;

class Graph
{
public:
	Graph (int V);
	void AddEdge (int u, int v, int w);
	bool IsReachable(int s, int d);
	void DFS (int u);
		
private:
	void DFSUtil(int u, bool visited[], int weight);
	int V;	
	list<vertex> * adj;
};

Graph::Graph(int V)
{
    this->V = V;    
	adj = new list<vertex>[V];
	edgearray = new int[V];
}

void Graph::AddEdge(int u, int v, int edge)
{
	vertex v1 = {v, edge};
	vertex u1 = {u, edge};

    adj[u].push_back(v1); 
	adj[v].push_back(u1);
}

void Graph::DFS (int u)
{
	bool * visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

	visited[u] = true;
 
	DFSUtil(u, visited, 0);
}

void Graph::DFSUtil (int u, bool visited[], int weight)
{
	if(flag) return;

	if(u == endnode)
	{
		flag = true;
		maxweight = weight;
		return;
	}

    list<vertex>::iterator i;

    for(i = adj[u].begin(); i != adj[u].end(); ++i) {
	
		if(!visited[(*i).v]) {
			visited[u] = true;
		
			DFSUtil((*i).v, visited, edgearray[(*i).edge] > weight ? edgearray[(*i).edge] : weight);
		}
	}
}

int main()
{
	int t,n;
	char str[7];
	int a;
	int b;
	int c;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		Graph g(n);
		
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			edgearray[i] = c;
			g.AddEdge(a-1,b-1,i);
		}

		while(1)
		{
				scanf("%s", str);

				if(str[0]=='Q')
				{
					scanf("%d%d", &a, &b);
					flag = false;
					maxweight = 0;
					endnode = b-1;
					g.DFS(a-1);
					printf("%d\n", maxweight);
				}
				
				if(str[0]=='C')
				{
					scanf("%d%d", &a, &b);
					edgearray[a-1] = b;
				}

				if(str[0]=='D')
					break;
		}
		printf("\n");
	}	

	return 0;
}