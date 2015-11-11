#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(int argc, char ** argv)
{
  if (argc < 2)
  {
    cout << "ERROR: Not enough aurguments\n";
    exit(0);
  }
  int sizeToGenerate = atoi(argv[2]); 
  ofstream fout(argv[1]);
  if (fout.fail())
  {
    cout << "ERROR: Failed to open the file\n";
    exit(0);
  }

  srand(time(NULL));

  int i = 0;
  while (i < sizeToGenerate)
  {
    fout << rand() << endl;
    i++;
  }


  fout.close();
}
