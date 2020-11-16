#include <iostream>
 
int main()
{
    int n;
    std::cout << "Enter int : ";
    while(!(std::cin >> n) || std::cin.get() != '\n') 
    {
        std::cout<<"It's not an int.\n";
        std::cin.clear();
        std::cin.sync();
        std::cout << "Enter int : ";
    }
    return 0;
}