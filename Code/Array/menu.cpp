#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (1)
    {

        cout << "1. First Option\n";
        cout << "2. Second Option\n";
        cout << "3. Third Option\n";
        cout << "0. Exit\n";

        cout << "Enter you option: ";
        cin >> n;

        if (n == 0)
        {
            break;
        }
        else if (n == 1)
        {
            // here write the code
            cout << "First Option\n";
        }
        else if (n == 2)
        {
            // here write the code
            cout << "Second Option\n";
        }
        else if (n == 3)
        {
            // here write the code
            cout << "Third Option\n";
        }
        else
        {
            cout << "Wrong input try again\n";
        }
    }

    return 0;
}