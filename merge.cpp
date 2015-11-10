/*
 * Merge Sort Algorithm
 *
 * Authored by,
 * Vamsi Sangam
 * Edits by,
 * Daniel Miller
 */
#include <iostream>
#include <algorithm> // for std::inplace_merge
#include <vector>
#include <fstream>
using namespace std;

const int MAX = 256;
 
// Merges two sorted partitions into a bigger sorted array
void mergePartitions(int Array[], int low, int high, int LeftPartition[], int RightPartition[])
{
    int i, j, k;
    int mid = (low + high + 1) / 2;
 
    // Initialise carefully
    i = j = 0;
    k = low;
 
    while (i < mid - low && j <= high - mid) {
        if (LeftPartition[i] < RightPartition[j]) {
            Array[k] = LeftPartition[i];
            ++i;
        } else {
            Array[k] = RightPartition[j];
            ++j;
        }
 
        ++k;
    }
 
    // Copying any leftover elements
    if (i == mid - low && j <= high - mid) {
        while (j <= high - mid) {
            Array[k] = RightPartition[j];
            ++j;
            ++k;
        }
    } else {
        while (i < mid - low) {
            Array[k] = LeftPartition[i];
            ++i;
            ++k;
        }
    }
}
 
// Partitions the array into two
// Does nothing if array has only one element
void mergeSort(int Array[], int low, int high)
{
    if (low < high) {
        int mid = (low + high + 1) / 2;
        int LeftPartition[mid - low];
        int RightPartition[high - mid + 1];
        int i;
 
        // Copying elements
        for (i = low; i < mid; ++i) {
            LeftPartition[i - low] = Array[i];
        }
 
        // Copying elements
        for (i = mid; i <= high; ++i) {
            RightPartition[i - mid] = Array[i];
        }
 
        // Recursive call
        mergeSort(LeftPartition, 0, mid - low - 1);
        mergeSort(RightPartition, 0, high - mid);
        // Merge the two partitions
        mergePartitions(Array, low, high, LeftPartition, RightPartition);
    }
}
 
template<typename RandomAccessIterator, typename Order>
 void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
  if (last - first > 1)
  {
    RandomAccessIterator middle = first + (last - first) / 2;
    mergesort(first, middle, order);
    mergesort(middle, last, order);
    std::inplace_merge(first, middle, last, order);
  }
}
 
template<typename RandomAccessIterator>
 void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
  mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

int main(int argc, char ** argv) {
  // Read an from a file.
  char * inFileName = new char[256];
  if (argc > 1)
    {
      inFileName = argv[1];
    }
  else
    {
      cout << "Enter input filename: ";
      inFileName = new char[MAX];
      cin >> inFileName;
    }
  ifstream fin(inFileName);
  if (fin.fail())
    {
      cout << "Unable to open file " << inFileName << endl;
      return -1;
    }
  
  /* Sort integer*/
  vector<int> vData;
  int temp = 0;
  while (fin >> temp)
    vData.push_back(temp);
  cout << "\nBefore sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
    cout << vData[i] << endl;

  mergeSort(&vData[0], 0, vData.size());

  cout << "\nAfter sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
    cout << vData[i] << endl;
}
