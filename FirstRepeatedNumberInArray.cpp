/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
*******************************************************************************/
// Find the first repeated number in array
// if array[8,4,3,10,16,4,12,3,8] then 4 is first repeated number 
// this program will print index of 4 

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
    
    for(int i=0; i < size; i++)
    {
        for(int j=i+1 ; j <= size;j++)
        {
            if(arr[i] == arr[j])
            {
                cout << "repeated number index = " << j << endl;
                cout << "repeated number is :" << arr[j] << " " << endl;
                goto end;
            }
            
        }
    }
  cout << "No number is repeated in array" << endl;
    end:
    return 0;
}
