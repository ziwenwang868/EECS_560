#include "graph.h"
graph::graph()
{
    arr = nullptr;
}
graph::~graph()
{
}
void graph::setfree()
{
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void graph::KruskalMST()
{
    edgesListWith_Weight.clear();
    edgesListWithM_Weight.clear();

    dis_jointSet sets;
    for (int i = 0; i < size; i++)
    {
        //cout << "nima" << endl;
        sets.insert(i);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] != -1)
            {
                Edge newEdge = std::make_tuple(i, j);
                std::tuple<int, Edge> weightedEdge = std::make_tuple(arr[i][j], newEdge);
                edgesListWith_Weight.push_back(weightedEdge);
            }
        }
    }

    std::sort(edgesListWith_Weight.begin(), edgesListWith_Weight.end());

    for (int i = 0; i < (int)edgesListWith_Weight.size(); i++)
    {
        Edge edgeInList = std::get<1>(edgesListWith_Weight[i]);
        int u = sets.find_byValue(std::get<0>(edgeInList));

        int v = sets.find_byValue(std::get<1>(edgeInList));
        //cout<<"nima"<<endl;
        if (u != v)
        {
            edgesListWithM_Weight.push_back(edgesListWith_Weight[i]);
            sets.Union_set(u, v);
        }
    }

    int totalLength = 0;
    std::cout << "Edges followed by min weight: ";
    for (int i = 0; i < (int)edgesListWithM_Weight.size(); i++)
    {
        Edge edgeInList = std::get<1>(edgesListWith_Weight[i]);
        int edgeWeightInList = std::get<0>(edgesListWithM_Weight[i]);
        std::cout << "(" << islands[std::get<0>(edgeInList)] << ", " << islands[std::get<1>(edgeInList)] << "){" << edgeWeightInList << "} ";
        totalLength = totalLength + edgeWeightInList;
    }

    std::cout << "\nTotal length of the route = " << totalLength << "\n";
    std::cout << "Total estimate to construct the bridges in the route = " << totalLength << "*250K = " << totalLength * 250 << "K $\n";
    sets.set_empty();
}

void graph::DFS(int v)
{
    tree_DFS.clear();
    back_Edges.clear();
    if (v < 0 || v >= size)
    {
        std::cout << "Invalid starting vertex\n";
    }

    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
    DFS_Helper(v, visited);

    std::cout << "Tree Edges: ";
    for (int i = 0; i < (int)tree_DFS.size(); i++)
    {
        std::cout << "(" << islands[std::get<0>(tree_DFS[i])] << ", " << islands[std::get<1>(tree_DFS[i])] << ") ";
    }
    std::cout << "\n";
    std::cout << "Back Edges: ";
    for (int i = 0; i < (int)back_Edges.size(); i++)
    {
        std::cout << "(" << islands[std::get<0>(back_Edges[i])] << ", " << islands[std::get<1>(back_Edges[i])] << ") ";
    }

    delete[] visited;
}

void graph::DFS_Helper(int v, bool visited[])
{
    int w = 0;
    visited[v] = true;
    for (w = 0; w < size; w++)
    {
        if (!visited[w] && arr[v][w] != -1)
        {
            Edge edge = std::make_tuple(v, w);
            tree_DFS.push_back(edge);
            DFS_Helper(w, visited);
        }
        else if (v > 0 && visited[w] && arr[v][w] != -1)
        {
            if (v > w)
            {
                Edge edge = std::make_tuple(v, w);
                back_Edges.push_back(edge);
            }
        }
    }
}

void graph::PrimMST()
{
    edgesList_Prim.clear();
    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
    int numOfEdges = 0;
    int x;
    int y;
    visited[0] = true;
    while (numOfEdges < size - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < size; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < size; j++)
                {
                    if (!visited[j] && arr[i][j] != -1)
                    {
                        if (min > arr[i][j])
                        {
                            min = arr[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        Edge newEdge = std::make_tuple(x, y);
        std::tuple<int, Edge> minWeightedEdge = std::make_tuple(min, newEdge);
        edgesList_Prim.push_back(minWeightedEdge);
        visited[y] = true;
        numOfEdges++;
    }

    int totalLength = 0;
    std::cout << "Edges followed by min weight: ";
    for (int i = 0; i < (int)edgesList_Prim.size(); i++)
    {
        Edge edgeInList = std::get<1>(edgesList_Prim[i]);
        int edgeWeightInList = std::get<0>(edgesList_Prim[i]);
        std::cout << "(" << islands[std::get<0>(edgeInList)] << ", " << islands[std::get<1>(edgeInList)] << "){" << edgeWeightInList << "} ";
        totalLength = totalLength + edgeWeightInList;
    }

    std::cout << "\nTotal length of the route = " << totalLength << "\n";
    std::cout << "Total estimate to construct the bridges in the route = " << totalLength << "*250K = " << totalLength * 250 << "K $\n";

    delete[] visited;
}

void graph::build(int **inputarr, int inputSize, std::vector<std::string> islandsInput)
{
    size = inputSize;
    arr = new int *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = inputarr[i][j];
        }
    }
    for (int i = 0; i < (int)islandsInput.size(); i++)
    {
        islands.push_back(islandsInput[i]);
    }
}
void graph::BFS(int v)
{
    tree_BFS.clear();
    cross_Edges.clear();
    if (v < 0 || v >= size)
    {
        std::cout << "Invalid starting vertex\n";
    }

    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }

    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    int top;
    while (!q.empty())
    {
        top = q.front();
        q.pop();

        for (int i = 0; i < size; i++)
        {
            if (!visited[i] && arr[top][i] != -1)
            {
                Edge edge = std::make_tuple(top, i);
                tree_BFS.push_back(edge);
                q.push(i);
                visited[i] = true;
            }
            else if (i > 0 && visited[i] && arr[top][i] != -1)
            {
                if (top > i)
                {
                    Edge edge = std::make_tuple(top, i);
                    cross_Edges.push_back(edge);
                }
            }
        }
    }
    std::cout << "Tree Edges: ";
    for (int i = 0; i < (int)tree_BFS.size(); i++)
    {
        std::cout << "(" << islands[std::get<0>(tree_BFS[i])] << ", " << islands[std::get<1>(tree_BFS[i])] << ") ";
    }
    std::cout << "\n";
    std::cout << "Cross Edges: ";
    for (int i = 0; i < (int)cross_Edges.size(); i++)
    {
        std::cout << "(" << islands[std::get<0>(cross_Edges[i])] << ", " << islands[std::get<1>(cross_Edges[i])] << ") ";
    }

    delete[] visited;
}