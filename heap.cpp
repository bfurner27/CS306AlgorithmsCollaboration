#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

const int MAX = 256;

int main(int argc, char ** argv) {
  ifstream fin(argv[1]);

  /* Sort integer */
  vector<int> vData;
  int temp = 0;
  while (fin >> temp)
    vData.push_back(temp);

  make_heap(&vData[0],&vData[0] + vData.size());
  sort_heap(&vData[0],&vData[0] + vData.size());
  return 0;
}
