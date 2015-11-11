#include<iostream> // cout
#include<algorithm> // make_heap, sort_heap
#include<vector> // vector (do not know how many numbers will be sent in)
#include<fstream> // file instream
#include<ctime> // clock_t
using namespace std;

const int MAX = 256;
template <typename T>
void insertSort(T array[], int sizeArray);

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

  /*  cout << "\nBefore sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
  cout << vData[i] << endl;*/
  
  clock_t time = clock();
  insertSort(&vData[0], vData.size());
  time = clock() - time;


  /*cout << "\nAfter sort:" << endl;
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
void insertSort(T array[], int sizeArray)
{
  int smallestValIndx = 0;

  T tempVal;
  bool isInserted = false;
  // loop through the array and insert the values into their correct position
  // while also shifting the values up if they do not match
  for (int i = 0; i < sizeArray; i++)
  {
    // copy the value to be moved into this value
    tempVal = array[i];
    isInserted = false;
    for (int j = i - 1; j >= 0; j--)
      {
	
	// check if the array value at j is less than the value we are trying
	//to insert
	// this will ensure we are inserting only if the value immediately
	//preceeding it
	// is smaller
	if (array[j] < tempVal)
	  {
	    array[j+1] = tempVal;
	    isInserted = true;
	    break;
	  }
	// swap the values that are currently in the array to make room for
	//the inserted element
	array[j+1] = array[j];
      }
    
    // check if the value was inserted previously if not it will assign the
    //value to the first place
    // in the array because it means that the value belongs in index 0
    if (!isInserted)
      {
	array[0] = tempVal;  
      }
  }
}
