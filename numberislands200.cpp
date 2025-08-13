/*
    TimeStamps
    Problema 56

 - Resolução: 20 min
 - Código: 20min

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int total = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs({i, j}, grid);
                    total++;
                }
            }
        }
        return total;
    }

    void dfs(pair<int, int> current, vector<vector<char>> &grid)
    {
        if (current.first < 0 || current.first >= grid.size() || current.second < 0 || current.second >= grid[current.first].size())
        {
            return;
        }
        if (grid[current.first][current.second] == '0')
        {
            grid[current.first][current.second] = '2';
            return;
        }
        if (grid[current.first][current.second] == '2')
        {
            return;
        }

        grid[current.first][current.second] = '2';
        dfs({current.first + 1, current.second}, grid);
        dfs({current.first - 1, current.second}, grid);
        dfs({current.first, current.second + 1}, grid);
        dfs({current.first, current.second - 1}, grid);
    }
};