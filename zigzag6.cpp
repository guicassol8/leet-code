/*
    TimeStamps
    Problema 6

 - Resolução: 20 min
 - Código: 30 min

 (Estou muito enferrujado)
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string result;
        result.resize(s.size());
        int current = 0;

        if (numRows == 1)
        {
            return s;
        }
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            bool down = true;
            while (j < s.size())
            {
                if (current >= result.size())
                    break;
                result[current++] = s[j];
                if (i == 0 || i == numRows - 1)
                {
                    j += 2 * (numRows - 1);
                }
                else
                {
                    j += down ? 2 * (numRows - i - 1) : 2 * i;
                    down = !down;
                }
            }
        }
        return result;
    }
};