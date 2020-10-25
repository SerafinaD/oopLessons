#include <iostream>
#include <cstdint>
#include <cmath>

////////////////////////////////////////////////////////////////
//////////////////////TASK 1////////////////////////////////////
////////////////////////////////////////////////////////////////

class Power
{
    private:
    int powr, num;
    public:
    Power() : powr(0), num(0)
    {}
    void set(int pwr, int nmbr)
    {
        powr = pwr;
        num = nmbr;
    }
    int calculate()
    {
        int res = pow(num, powr);
        std::cout << res << std::endl;
        return(res);
    }
};

////////////////////////////////////////////////////////////////
//////////////////////TASK 2////////////////////////////////////
////////////////////////////////////////////////////////////////

class RGBA
{
    private:
    std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
    public:
    RGBA(){}
    RGBA(int red, int green, int blue, int alpha): m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {}
    void print()
    {
        std::cout << "red: " << static_cast<int>(m_red) << std::endl << "green: " << static_cast<int>(m_green) << std::endl << "blue: " << static_cast<int>(m_blue) << std::endl<< "alpha: " << static_cast<int>(m_alpha) << std::endl;
    }

};

////////////////////////////////////////////////////////////////
//////////////////////TASK 3////////////////////////////////////
////////////////////////////////////////////////////////////////

class Stack
{
    private:
    int stack[10];
    int quantity;
    public:
    Stack()
    {
        for (quantity = 0; quantity < 10; quantity++)
            stack[quantity] = 0;
        quantity = 0;
    }
    void reset()
    {
        while (quantity > 0)
            stack[--quantity] = 0;
    }
    bool push(int num)
    {
        if (quantity == 10) 
            return (false);
        stack[quantity++] = num;
        return (true);
    }
    int pop()
    {
        int num;
        if (quantity == 0)
        {
            std::cout << "Empty stack!" << std::endl;
            return (0);
        }
        num = stack[--quantity];
        stack[quantity + 1] = 0;
        return (num);
    }
    void print()
    {
        std::cout << "(";
        for (int i = 0; i < quantity; i++)
            std::cout << " " << stack[i];
        std::cout << " )" << std::endl;
    }
};

////////////////////////////////////////////////////////////////
////////////////////// MAIN ////////////////////////////////////
////////////////////////////////////////////////////////////////

int main(void)
{
////////////////////////////////////////////////////////////////
//////////////////////TASK 1////////////////////////////////////
////////////////////////////////////////////////////////////////
    
    Power Ptest;
    Ptest.set(5, 2);
    Ptest.calculate();
    
////////////////////////////////////////////////////////////////
//////////////////////TASK 2////////////////////////////////////
////////////////////////////////////////////////////////////////    
    
    RGBA Rtest;
    Rtest.print();

////////////////////////////////////////////////////////////////
//////////////////////TASK 3////////////////////////////////////
////////////////////////////////////////////////////////////////

    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();


    return(0);
}
