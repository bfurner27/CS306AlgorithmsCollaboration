#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
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

  make_heap(&vData[0],&vData[0] + vData.size());
  sort_heap(&vData[0],&vData[0] + vData.size());
  
  cout << "\nAfter sort:" << endl;
  for(int i = 0; i < vData.size(); i++)
    cout << vData[i] << endl;
  return 0;
}
