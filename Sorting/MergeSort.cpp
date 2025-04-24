#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    void mergeSubArray(vector<int> &vArr, int low, int high)
    {
       // cout << "mergeSubArray " << endl;
        int mid = low + (high - low) / 2;
        int lSize = (mid - low) + 1;
        int rSize = high - mid;

        vector<int> LsubArr(lSize);
        vector<int> RsubArr(rSize);

        // populate the values from OG array.
        
        for (int i = 0; i < LsubArr.size(); i++)
        {
            LsubArr[i] = vArr[low+i];
        }

        for (int i = 0; i < RsubArr.size(); i++)
        {
            RsubArr[i] = vArr[mid+1+i];
        }

        // Sort And merge(update the OG array)

        int nleft{0}, nRight{0};
        int ogIndex{low};
        while (nleft < LsubArr.size() && nRight < RsubArr.size())
        {
            if (LsubArr[nleft] < RsubArr[nRight])
            {
                vArr[ogIndex] = LsubArr[nleft];
                nleft++;
            }
            else
            {
                vArr[ogIndex] = RsubArr[nRight];
                nRight++;
            }
            ogIndex++;
        }
        // fill the remaining array

        while (nleft < LsubArr.size())
        {
            vArr[ogIndex] = LsubArr[nleft];
            nleft++;
            ogIndex++;
        }
        while (nRight < RsubArr.size())
        {
            vArr[ogIndex] = RsubArr[nRight];
            nRight++;
            ogIndex++;
        }
    }
    void mergeSort(vector<int> &vArr, int low, int high)
    {
        cout << "mergeSort " << endl;
       // cout << low << "  " << high << endl;
        if (low >= high)
        {
            return;
        }
        int mid = low + (high - low) / 2;

        mergeSort(vArr, low, mid);
        ///cout << " Right Pass" << endl;
        mergeSort(vArr, mid + 1, high);
        mergeSubArray(vArr,low,high);
    }
};

int main()
{
    vector<int> vArr = {4, 1, 3, 9, 7};
    int n = vArr.size();
    for(int i = 0; i < vArr.size();i++ ){
        cout << vArr[i] << "  ";
    }
    cout << endl;

    Sort s;
    s.mergeSort(vArr, 0, n-1);

    for(int i = 0; i < vArr.size();i++ ){
        cout << vArr[i] << "  ";
    }
    cout << endl;
}