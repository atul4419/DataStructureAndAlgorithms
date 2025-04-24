#include <iostream>
#include <vector>
using namespace std;

int  linearSearch(vector<int> arr, int size, int key)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[size - 1] == key)
        return size;

    return linearSearch(arr, size - 1, key);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    int pos = linearSearch(arr, arr.size(), 1);

    cout << pos << endl;
    return 0;
}