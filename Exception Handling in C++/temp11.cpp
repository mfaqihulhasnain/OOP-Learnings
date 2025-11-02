#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    try
    {
        if (b == 0)
        {
            throw runtime_error("Division by zero error");
        }

        int result = a / b;
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error &e) 
    {
        cerr << "Exception Occured: " << e.what() << endl;
    }

    return 0;
}