/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
*******************************************************************************/

// Given an unsorted array A of size N of non- negative integers, find a continuous subarray which adds to a given number S.
// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output = {2,3,7} index = 2 4

#include <iostream>

using namespace std;

int main()
{
    int size;
    
    cin >> size;
    
    int arr[size];
    
    for(int i=0; i <size; i++)
    {
        cin >> arr[i];
    }
    
    for(int i = 0; i < size; i++)
    {
        int sum = 0;
        
        for(int j = i + 1; j <= size; j++)
        {
            sum = sum + arr[j];
            
            if((arr[i] + sum) == 12)
            {
                cout << i << " to " << j << endl;
                goto end;
            }
        }
    }
    cout << "No continuous subarray with sum 12" << endl;
    end:
    return 0;
}




  
