#include<iostream> // cout
#include<algorithm> // make_heap, sort_heap
#include<vector> // vector (do not know how many numbers will be sent in)
#include<fstream> // file instream
#include<ctime> // clock_t
using namespace std;

const int MAX = 256;

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

  // cout << "\nBefore sort:" << endl;
  // for(int i = 0; i < vData.size(); i++) cout << vData[i] << endl;
  clock_t time = clock();
  make_heap(&vData[0],&vData[0] + vData.size());
  sort_heap(&vData[0],&vData[0] + vData.size());
  time = clock() - time;
  // cout << "\nAfter sort:" << endl;
  // for(int i = 0; i < vData.size(); i++) cout << vData[i] << endl;
  cout << "It took me " << time << " clicks." << endl;
  cout << ((float)time)/CLOCKS_PER_SEC << " seconds." << endl;
  return 0;
}
