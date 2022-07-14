#include "graph.h"

Graph::Graph()
{
    cout << "Enter the number of Edges: ";
    cin >> this->no_edge;

    cout << "Enter the number of Vertices: ";
    cin >> this->no_vertex;

    this->adj_matrix.resize(this->no_vertex + 1, vector<int> (this->no_vertex + 1, 0));
    this->visited_bfs.resize(no_vertex + 1, false);
    this->visited_dfs.resize(no_vertex + 1, false);

}

Graph::Graph(int no_edge, int no_vertex)
{
    this->no_edge = no_edge;
    this->no_vertex = no_vertex;

    this->adj_matrix.resize(no_vertex + 1, vector<int> (no_vertex + 1, 0));
    // this->adj_list.resize(no_vertex, vector<int> (0));
    this->visited_bfs.resize(no_vertex + 1, false);
    this->visited_dfs.resize(no_vertex + 1, false);

}

void Graph::undirected_adj()
{
    for (int i = 0; i < no_edge; i++)
    {
        vector<int> address(2);
        cout << "Edge from Vertex: ";
        cin >> address[0];
        cout << "To the Vertex: ";
        cin >> address[1];

        this->edges.push_back(address);
        this->adj_matrix[address[0]][address[1]] = 1;
        this->adj_matrix[address[1]][address[0]] = 1;
    }
}

void Graph::undirected_adj_list()
{
    for (int i = 0; i < no_edge; i++)
    {
        vector<int> address(2);
        cout << "Edge from Vertex: ";
        cin >> address[0];
        cout << "To the Vertex: ";
        cin >> address[1];

        this->edges.push_back(address);
        
        this->adj_list[address[0]].push_back(address[1]);
        this->adj_list[address[1]].push_back(address[0]);
    }
}

void Graph::bfs(int start_index)
{
    queue<int> line;
       
    line.push(start_index);
    visited_bfs[start_index] = true;

    while (!line.empty())
    {
        int temp = line.front();
        cout << temp << " ";
        line.pop();

        if (temp < no_vertex)
        {   
            for (int i = 0; i < this->adj_list[temp].size(); i++)
            {
                if (!visited_bfs[this->adj_list[temp][i]])
                {
                    line.push(this->adj_list[temp][i]);
                    visited_bfs[this->adj_list[temp][i]] = true;
                }
            }
        }
    }

}

void Graph::bfs_comp() //complicated
{
    for (int i = 1; i <= no_vertex; i++)
    {
        if (!visited_bfs[i])
            this->bfs(i);
    }
}

void Graph::dfs(int startIndex)
{
    cout << startIndex;
    visited_dfs[startIndex] = true;

    for (int i = 0; i < no_vertex; i++)
    {
        if (!visited_dfs[this->adj_list[startIndex][i]])
            dfs(adj_list[startIndex][i]);
    }
}



bool Graph::helper_cycle_bfs(int startIndex)
{
	queue<pair<int, int>> line;
	
	line.push({startIndex, -1});
	visited_bfs[startIndex] = true;
	
	while (!line.empty())
	{
		int node = line.front().first;
		int parent = line.front().second;
		line.pop();
		
		for (auto it : adj_list[node])
		{
			if (!visited_bfs[it])
			{
				line.push({it, node});
				visited_bfs[it] = true;
			}
			else 
			{
				if (it != parent)
					return true;
			}
		}
	}
	return false;
}

bool Graph::isCyclic_bfs()
{
    // add your logic here	
	for (int i = 0; i < no_vertex; i++)
	{
		if (!visited_bfs[i])
		{
			if (helper_cycle_bfs(i))
				return true;
		}
	}
	return false;
}


bool Graph::helper_cycle_dfs(int startIndex, int parent)
{
	visited_dfs[startIndex] = true;
	
	for (int i = 0; i < adj_list[startIndex].size(); i++)
	{
		if (!visited_dfs[adj_list[startIndex][i]])
			helper_cycle_dfs(adj_list[startIndex][i], startIndex);
		else 
		{
			if (adj_list[startIndex][i] != parent)
				return true;
		}
	}
	return false;
}

bool Graph::isCyclic_dfs()
{
	for (int i = 0; i < no_vertex; i++)
	{
		if (!visited_dfs[i])
		{
			if (helper_cycle_dfs(i, -1))
				return true;
		}
	}
	return false;
}

bool Graph::is_bipartite_bfs(int startIndex, vector<int> &coloured)
{
    queue<item> line;

    coloured[startIndex] = 1;
    line.push(startIndex);

    while (!line.empty())
    {
        int node = line.front();
        line.pop();

        for (int i = 0; i < adj_list[node].size(); i++)
        {
            if (coloured[adj_list[node][i]] == -1)
            {
                coloured[adj_list[node][i]] = 1 - coloured[node];
                line.push(adj_list[node][i]);
            }
            else 
            {
                if (coloured[node] == coloured[adj_list[node][i]])
                    return false;
            }
        }
    }
    return true;
}

bool Graph::is_bipartit_bfs_component()
{
    vector<int> coloured(no_vertex, -1);

    for (int i = 0; i < no_vertex; i++)
    {
        if (coloured[i] == -1)
        {
            if (!is_bipartite_bfs(i, coloured))
                return false;
        }
    }
    return true;
}

bool Graph::detect_cycle_directed_dfs(vector<bool> &visited, vector<bool> &visited_dfs, int startIndex)
{
    visited[startIndex] = true;
    visited_dfs[startIndex] = true;

    for (auto it : adj_list[startIndex])
    {
        if (!visited[it])
        {
            if (detect_cycle_directed_dfs(visited, visited_dfs, it))
                return true;
        }
        else 
        {
            if (visited[it] == visited_dfs[it])
                return true;
        }
    }

    visited_dfs[startIndex] = false;
    return false;
}

bool Graph::detect_cycle_directed_dfs_comp()
{
    vector<bool> visited(no_vertex, false);
    vector<bool> visited_dfs(no_vertex, false);

    for (int i = 0; i < no_vertex; i++)
    {
        if (detect_cycle_directed_dfs(visited, visited_dfs, i))
            return true;
    }

    return false;
}


void Graph::topological_sort_dfs(vector<bool> &visited, int node, stack<item> &res)
{
    visited[node] = true;

    for (auto it : adj_list[node])
    {
        if (!visited[it])
        {
            topological_sort_dfs(visited, it, res);
        }
    }
    res.push(node);
}

vector<int> Graph::topological_sort_dfs_comp()
{
    vector<bool> visited(no_vertex, false);
    stack<item> res;
    vector<int> ans;

    for (int i = 0; i < no_vertex; i++)
    {
        if (!visited[i])
            topological_sort_dfs(visited, i, res);
    }

    while (!res.empty())
    {
        ans.push_back(res.top());
        res.pop();
    }

    return ans;
}

vector<item> Graph::topological_sort_bfs() // kahn's algorithm
{
    vector<int> inDegree(no_vertex, 0);
    vector<item> res;
    queue<item> line;

    for (int i = 0; i < no_vertex; i++)
    {
        for (auto it : adj_list[i])
            inDegree[it]++;
    }

    for (int i = 0; i < no_vertex; i++)
    {
        if (inDegree[i] == 0)
            line.push(i);
    }

    while (!line.empty())
    {
        int node = line.front();
        res.push_back(node);
        line.pop();

        for (auto it : adj_list[node])
        {
            inDegree[it]--;

            if (inDegree[it] == 0)
                line.push(it);
        }
    }
    return res;
}