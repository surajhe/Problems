#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// your code goes here
 
	int A = 5;
	int num = 1;
	vector<vector<int>> V(A, vector<int>(A));
	int i=0, j=0;
	while(A>1)
	{
	//	vector<int> X;
	for(int k=1; k<A; k++)
	{
		V[i][j] = num;
		cout << num ;
		j++; num++;
	}
 
	cout << endl;
 
	for(int k=1; k<A; k++)
	{
		V[i][j] = num;
		cout << num;
		i++; num++;
	}
 
	cout << endl;
 
	for(int k=1; k<A; k++)
	{
		V[i][j] = num;
		cout << num;
		j--; num++;
	}
 
	cout << endl;
 
	for(int k=1; k<A; k++)
	{
		V[i][j] = num;
		cout << num;
		i--; num++;
	}
 
	cout << endl;
 
	i++; j++; A = A-2;
 
    }
 
    if(A%2 == 1)
    {
    	V[i][j] = num;
    	cout << num << endl;
    }
 
    for(int i=0; i<V.size(); i++)
    {
    	for(int j=0; j<V[0].size(); j++)
    	{
    		cout << V[i][j] = num;
    	}
 
    	cout << endl;
    }
	return 0;
}
