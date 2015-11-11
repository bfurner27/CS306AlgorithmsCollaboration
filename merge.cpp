/*
 * Merge Sort Algorithm
 *
 * Authored by,
 * Vamsi Sangam
 * Edits by,
 * Daniel Miller
 */
#include <iterator>
#include <functional>
#include <ctime>
#include <iostream>
#include <algorithm> // for std::inplace_merge
#include <vector>
#include <fstream>
using namespace std;

const int MAX = 256;

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

  // cout << "\nBefore sort:" << endl;
  // for(int i = 0; i < vData.size(); i++) cout << vData[i] << endl;
  clock_t time = clock();
  
  mergesort(&vData[0], &vData[0 + vData.size()]);
  time = clock() - time;
  // cout << "\nAfter sort:" << endl;
  // for(int i = 0; i < vData.size(); i++) cout << vData[i] << endl;
  cout << "It took me " << time << " clicks." << endl;
  cout << ((float)time)/CLOCKS_PER_SEC << " seconds." << endl;
  return 0;
}
