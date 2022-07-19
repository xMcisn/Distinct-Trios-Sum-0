// Markus Cisneros 7/18/2022 Find Distinct Triples whose sum is 0 Example Code main.cpp
/* Pass a vector of integers to a function that will populate a vector of vector of integers.
 * The vector of vector of integers will only push back a vector of integers if  and only if that vector
 * of integers does not already exists within itself.
 * Constraints: The vector of integers must hold between 3 and 3000 integers.
 *              The values of said integers must not exceed 10^5 nor fall below -10^5
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printMyVectorOfVectorInts(vector<vector<int>> &vectOfVectOfInts);
vector<vector<int>> tripleValuesThatSum3(vector<int> &vNums);
bool trioExists(vector<vector<int>> &vectOfVectOfInts, vector<int> &tempV);
bool intsInRange(int monitoredInt);

int main()
{
    vector<int> myNumbers = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> v3SumNums;

    v3SumNums = tripleValuesThatSum3(myNumbers);
    printMyVectorOfVectorInts(v3SumNums);

    return 0;
}

void printMyVectorOfVectorInts(vector<vector<int>> &vectOfVectOfInts)
{
    for (int i = 0; i < vectOfVectOfInts.size(); i++)
    {
        for (int j = 0; j < vectOfVectOfInts[i].size(); j++)
        {
            cout << "vectOfVectOfInts[" << i << "][" << j << "]: " << vectOfVectOfInts[i][j] << endl;
        }
    }
}

vector<vector<int>> tripleValuesThatSum3(vector<int> &vNums)
{
    vector<vector<int>> v3SumNums;
    vector<vector<int>> emptyVect = {};

    if (vNums.size() < 3 || vNums.size() > 3000)
    {
        return v3SumNums;
    }

    for (int i = 0; i < vNums.size(); i++)
    {
        if(!intsInRange(vNums[i]))
        {
            return emptyVect;
        }
        for (int j = i + 1; j < vNums.size(); j++)
        {
            if(!intsInRange(vNums[j]))
            {
                return emptyVect;
            }
            for (int k = j + 1; k < vNums.size(); k++)
            {
                if(!intsInRange(vNums[k]))
                {
                    return emptyVect;
                }
                if ((vNums[i] + vNums[j] + vNums[k]) == 0)
                {
                    vector<int> tempV;
                    tempV.push_back(vNums[i]);
                    tempV.push_back(vNums[j]);
                    tempV.push_back(vNums[k]);
                    if(!trioExists(v3SumNums, tempV))
                    {
                        v3SumNums.push_back(tempV);
                    }
                }
            }
        }
    }

    return v3SumNums;
}

bool trioExists(vector<vector<int>> &vectOfVectOfInts, vector<int> &tempV)
{
    int numExists = 0;

    for (int i = 0; i < vectOfVectOfInts.size(); i++)
    {
        for (int j = 0; j < vectOfVectOfInts[i].size(); j++)
        {
            if(numExists !=3)
            {
                if (vectOfVectOfInts[i][j] == tempV[0] || vectOfVectOfInts[i][j] == tempV[1] || vectOfVectOfInts[i][j] == tempV[2])
                {
                    numExists++;
                }
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

bool intsInRange(int monitoredInt)
{
    if(monitoredInt < pow(-10, 5) || monitoredInt > pow(10, 5))
    {
        return false;
    }
    return true;
}