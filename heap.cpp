/******************************************************************************
 * @file          heap.cpp
 * @author        Amit P/Ghansham K
 * ----------------------------------------------------------------------------
 * Revision History   :
 * ============================================================================
 * Date       Author               Description
 * ----------------------------------------------------------------------------
 * 02-Dec-2016   Amit P/Ghansham K      Creation
 *****************************************************************************
 * Copyright (c) Nokia 2016
 * All rights reserved.
 * Licensed material - property of Nokia
 *****************************************************************************/


/*
 *     cout << "Hello World \n" << endl;
    //std::vector<int> heap(10,5);
    std::vector<int> heap;

    cout << heap.size() <<endl;
    heap.push_back(1);
    heap.push_back(2);
    heap.push_back(3);
    heap.push_back(4);
   // heap.push_back(5);

    cout << heap.size() <<endl;
    cout << heap.capacity() <<endl;
    cout << heap.max_size() <<endl;
   // cout << heap.reserve() <<endl;

   for( auto a : heap)
   {   cout << a ; }
   cout << endl;

   for(int i=0 ; i < heap.size(); i++)
       cout << heap[i];
   heap.pop_back();

   for( auto a : heap)
   {  cout << a ; }

 */

#include<iostream>
#include<vector>

using namespace std;

class MinHeap
{
    public:
        void insertKey(int);
        void deleteKey(int);
        int parent(int);
        int left(int);
        int right(int);
        int extractMin();
        void decreaseKey(int, int);
        int getMin();
        void heapifyDown(int);
        void heapifyUp(int);
        void printHeap();
        std::vector<int> data;


    private:
        void swap(int, int);
       // std::vector<int> data;
 };

void MinHeap::printHeap()
{
    cout << endl;
    for(auto i: data) {   cout << i << " " ;   }
    cout << endl;
}


void MinHeap::heapifyUp(int index)
{
    while(index != 0 && data[index]< data[parent(index)] )
    {
        swap(index, parent(index));
        index = parent(index);
    }
}

void MinHeap::heapifyDown(int index)
{
    int l = left(index);
    int r = right(index);
    bool flag = false;

    if (data[l] < data[r])
    {
        if (l < (data.size() - 1) && data[l] < data[index])
        {
            swap(l, index);
            flag = true;
            index = l;
        }
    }
    else
    {
        if(r < (data.size()-1) && data[r] < data[index])
        {
            swap(r, index); flag = true; index = r;
        }
    }
    if (flag) /* this condition will avoid the multiple unnecessary recursion */
    {
        heapifyDown(index);
    }
}

void MinHeap::insertKey(int key)
{
    data.push_back(key);
    heapifyUp(data.size()-1);
}

void MinHeap::deleteKey(int index)
{
    decreaseKey(index, -1);
    heapifyUp(index);
    extractMin();
}

void MinHeap::decreaseKey(int index, int newVal)
{
    data[index] = newVal;
    heapifyUp(index);
}

int MinHeap::extractMin()
{
    int min = data.front();
    swap(0, data.size()-1);
    data.erase(data.end()-1);
    heapifyDown(0);
    return min;
}

void MinHeap::swap(int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int MinHeap::parent(int i){    return (i-1)/2; }
int MinHeap::left(int i){     return 2*i+1; }
int MinHeap::right(int i){     return 2*i+2; }
int MinHeap::getMin() {   return data.front(); }


int main()
{
    cout << "Mean Heap Problem" << endl;
    MinHeap h;
    int arr[11] = {8,12,9,7,22,3,26,14,11,15,22};
    for(auto a : arr)
        h.insertKey(a);

    cout << "After Min Heap Insertion" << endl;
    h.printHeap();


    cout << "After Min Heap DecreaseKey" << endl;
    h.decreaseKey(5,1);
    h.printHeap();

    cout << h.getMin();

    cout << "After Min Heap extractMin" << endl;
    h.extractMin();
    h.printHeap();

    cout << "After Min Heap DeleteKey" << endl;
    h.deleteKey(6);
    h.printHeap();
}

