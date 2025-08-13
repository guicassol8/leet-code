/*
    TimeStamps
    Problema 56

 - Resolução: 10 min
 - Código: 10min

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mapF;
        priority_queue<pair<int, int>> maxHeap;
        for (const auto num : nums)
        {
            if (mapF.find(num) == mapF.end())
            {
                mapF[num] = 1;
            }
            else
            {
                mapF[num]++;
            }
        }
        for (const auto num : mapF)
        {
            maxHeap.push({num.first, num.second});
        }

        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return result;
    }
};