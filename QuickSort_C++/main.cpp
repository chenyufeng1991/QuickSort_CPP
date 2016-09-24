//
//  main.cpp
//  QuickSort_C++
//
//  Created by chenyufeng on 9/24/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 *  快速排序的时间复杂度O(nlogn),空间复杂度O(nlogn),是一种不稳定的排序。
 *
 *  @param vec   <#vec description#>
 *  @param left  <#left description#>
 *  @param right <#right description#>
 *
 *  @return <#return value description#>
 */

int Partition(vector<int> &vec, int left, int right);
void QuickSort(vector<int> &vec, int left, int right);

int main(int argc, const char * argv[])
{
    int arr[] = {5,1,2,8,0,6};
    vector<int> vectorFromArray(arr,arr + sizeof(arr)/sizeof(int));

    QuickSort(vectorFromArray, 0, int32_t(vectorFromArray.size() - 1));

    vector<int>::iterator vecIte;
    for (vecIte = vectorFromArray.begin(); vecIte != vectorFromArray.end(); vecIte++)
    {
        cout << *vecIte << " ";
    }

    return 0;
}

void QuickSort(vector<int> &vec, int left, int right)
{
    if (left == right)
    {
        return;
    }

    int index = Partition(vec, left, right);
    if (index > left)
    {
        QuickSort(vec, left, index);
    }
    if (index < right)
    {
        QuickSort(vec, index + 1, right);
    }
}


int Partition(vector<int> &vec, int left, int right)
{
    int i = left, j = right,x = vec[left];

    while (i < j)
    {
        while (i < j && vec[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            vec[i++] = vec[j];
        }

        while (i < j && vec[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            vec[j--] = vec[i];
        }
    }
    vec[i] = x;

    return i;
}





