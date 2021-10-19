// Problem Description

//  You are given an array of distinct integers A, you have to find and return all elements in array which have at-least two greater elements than themselves.

//  NOTE: The result should have the order in which they are present in the original array.
// Example 
// Input:

//  A = [11, 17, 100, 5]

// Output:

//  [11, 5]


vector<int> Solution::solve(vector<int> &A) {
     
     int first = INT_MIN, second = INT_MIN;
     vector<int> N;
    for(int i=0; i<A.size();i++)
    {
        if(A[i] > first)
        {
            second = first;
            first = A[i];
        }
        else if(A[i] > second)
        {
            second = A[i];
        }
    }
    
    for(int i=0; i<A.size();i++)
    {
        if(A[i] < second)
        {
            N.push_back(A[i]);
        }
    }
    
    return N;
    
}
