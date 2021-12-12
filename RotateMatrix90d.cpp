#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	vector<vector<int>> A
	// {
 //   {1,2,3,4,5},
 //   {6,7,8,9,10},
 //   {11,12,13,14,15},
 //   {16,17,18,19,20},
 //   {21,22,23,24,25}
	// };
	{
		{1,2},
		{3,4}
	};
	
	int row = A.size();
    int col = A[0].size();

    for(int i=1; i<row; i++)
    {
        for(int j=0; j<col-1; j++)
        {
            swap(A[i][j], A[j][i]);
            
            if(i == j)
        	{
        		break;
        	}
        }
    }

    for(int i=0; i<row; i++)
    {
        int lcol = col-1;
        int fcol = 0;
        while(fcol < col/2)
        {
            swap(A[i][fcol], A[i][lcol]);
            fcol++;
            lcol--;
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << A[i][j] << " ";
        }
        
        cout << endl;
    }
	
	return 0;
}
