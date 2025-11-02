#include <iostream>
using namespace std;

int main()
{
    try
    {
        int *p = new int[10]; // Attempting to allocate a very large array
        cout << "Memory allocation successful." << endl;
        delete[] p;
    }
    catch (const exception &e)
    {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }

    return 0;
}