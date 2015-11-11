#include<iostream> // cout
#include<algorithm> // make_heap, sort_heap
#include<vector> // vector (do not know how many numbers will be sent in)
#include<fstream> // file instream
#include<ctime> // clock_t
using namespace std;

const int MAX = 256;
template <typename T>
void swapSort(T array[], int sizeArray);

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
  
  /* Sort integer */
  vector<int> vData;
  int temp = 0;
  while (fin >> temp)
    vData.push_back(temp);

  /*
  cout << "\nBefore sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
  cout << vData[i] << endl;*/
  
  clock_t time = clock();
  swapSort(&vData[0], vData.size());
  time = clock() - time;

  /*  cout << "\nAfter sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
  cout << vData[i] << endl;*/

  cout << "It took me " << time << " clicks." << endl;
  cout << ((float)time)/CLOCKS_PER_SEC << " seconds." << endl;
  return 0;
}

/**************************************************************************
* void swapSort(T array[], int sizeArray)
* Description: This will use a swap sort to sort the given array that is 
* passed in
*
* INPUT:  array - this is the array of data
* 		  sizeArray - this is the size of the array that was passed in
* OUTPUT: array - the updated array is given back to the caller function
* RETURN: NONE
****************************************************************************/
template <typename T>
void swapSort(T array[], int sizeArray)
{
  int smallestValIndx = 0;
  T tempArrayVal;

  // this will loop through the array and will keep track of the items that
  // are currently sorted and the items that need to be sorted
  for (int i = 0; i < sizeArray; i++)
    {
      // this will ensure that the sorted items are separated from the non sorted items
      smallestValIndx = i;

      // loops through the remainder of the array to find the smallest value so it can be swapped
      for (int j = i; j < sizeArray; j++)
    	{
	  // If the current smallest index value is greater than another value in the array the
	  // smallest index becomes the current index value of j
	  if (array[smallestValIndx] > array[j])
	    {

	      smallestValIndx = j;
	    }


    	}

      // swap the array values using a temporary variable
      tempArrayVal = array[i];
      array[i] = array[smallestValIndx];
      array[smallestValIndx] = tempArrayVal;
    }
}
