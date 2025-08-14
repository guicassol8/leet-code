/*
    TimeStamps
    Problema 1192

 - Resolução: 1h 30min (Aprendi Tarjan)
 - Código: 40min

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct graph
{
    long int desc;
    long int low;
    bool visited;
    vector<int> neighbors;

    graph()
    {
        visited = false;
    }
};

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<graph> graphList(n);
        for (int i = 0; i < n; i++)
        {
            graphList[i] = graph();
        }

        for (const auto &connection : connections)
        {
            graphList[connection[0]].neighbors.push_back(connection[1]);
            graphList[connection[1]].neighbors.push_back(connection[0]);
        }
        vector<vector<int>> result;
        dfs(0, graphList, 0, 0, result);

        return result;
    }

    void dfs(int time, vector<graph> &graphList, int current, int passed, vector<vector<int>> &result)
    {
        graphList[current].visited = true;
        graphList[current].desc = time;
        graphList[current].low = time;

        for (const auto &neighbor : graphList[current].neighbors)
        {
            if (!graphList[neighbor].visited)
            {
                dfs(time + 1, graphList, neighbor, current, result);
                graphList[current].low = min(graphList[current].low, graphList[neighbor].low);

                if (graphList[neighbor].low > graphList[current].desc)
                {
                    result.push_back({neighbor, current});
                }
            }
            else if (neighbor != passed)
            {
                graphList[current].low = min(graphList[current].low, graphList[neighbor].desc);
            }
        }
    }
};