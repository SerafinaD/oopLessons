#include <iostream>
 
int main()
{
    int n;
    cout << "Enter int : ";
    while(!(cin >> n) || cin.get() != '\n') 
    {
        cout<<"It's not an int.\n";
        cin.clear();
        cin.sync();
        cout << "Enter int : ";
    }
    return 0;
}