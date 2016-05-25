#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {5,4,2,1,3};
    int j,i,key;
    int len = 5;

    cout<<"Before Sort:"<<endl;
    for(i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }

    for(j=1; j<len; j++)
    {
        key = arr[j];
        for(i=j-1; i>=0 && arr[i] > key; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[i+1] = key;
    }

    cout<<"\n\nInsertion Sort:"<<endl;
    for(i=0; i<len; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}
