/*
    TimeStamps
    Problema 56

 - Resolução: 8 min
 - Código: 18min

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<vector<int>> result;
        vector<int> current = intervals[0];

        for (int i = 1; i < (int)intervals.size(); ++i)
        {
            if (intervals[i][0] <= current[1])
            {
                current[1] = max(current[1], intervals[i][1]);
            }
            else
            {
                result.push_back(current);
                current = intervals[i];
            }
        }

        result.push_back(current);

        return result;
    }
};
