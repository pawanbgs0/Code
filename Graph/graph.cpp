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