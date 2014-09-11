#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Added some comments to change this file


int main()
{


        for (int i = 0; i < 200; i++) {
            int size_x = rand() % (19 - 3 + 1) + 3;
            int size_y = rand() % (19 - 3 + 1) + 3;
            cout << size_x << ", " << size_y << endl;
        }

    }

