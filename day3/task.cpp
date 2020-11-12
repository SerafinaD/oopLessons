#include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>
#define ABS(X) ((X) > 0 ? (X) : -(X))

///////////////////////////////////////////////////////////////
/////////////////////TASK 1////////////////////////////////////
///////////////////////////////////////////////////////////////

class Figure
{
    protected:
    virtual double area() const = 0;
};

class Circle: protected Figure
{
    private:
    double rad;
    public:
    Circle(double r): rad(r)
    {
    }
    double area() const
    {
        return (3.1415 * rad * rad);
    }
};

class Parallelogram: protected Figure
{
    private:
    double a, b, angle;
    public:
    Parallelogram(double w, double l, double ang): a(w), b(l), angle(ang)
    {
    }
    double area()const
    {
        return (a * b * sin(angle * 3.14159265 / 180));
    }
};

class Rectangle: public Parallelogram
{
    public:
    Rectangle(double w, double h):  Parallelogram(w, h, 90)
    {
    }
    double area() const
    {
        return (Parallelogram::area());
    }
};

class Square: public Parallelogram
{
    public:
    Square(double w): Parallelogram(w, w, 90)
    {
    }
    double area() const
    {
        return (Parallelogram::area());
    }
};

class Rhombus: public Parallelogram
{
    public:
    Rhombus(double w, double l, double ang): Parallelogram(w, l, ang)
    {
    }
    double area() const
    {
        return (Parallelogram::area());
    }
};

///////////////////////////////////////////////////////////////
/////////////////////TASK 2////////////////////////////////////
///////////////////////////////////////////////////////////////

class Car
{
    private:
    std::string company, model;
    public:
    Car(std::string c, std::string m): company(c), model(m)
    {
        std::cout << "Car: " << company << '\t' << model << std::endl;
    }
};

class PassengerCar: virtual public Car
{
    public:
    PassengerCar(std::string c, std::string m): Car(c, m)
    {
        std::cout << "PassengerCar: " << c << '\t' << m << std::endl;
    }
};

class Bus: virtual public Car
{
    public:
    Bus(std::string c, std::string m): Car(c, m)
    {
        std::cout << "Bus: " << c << '\t' << m << std::endl;
    }
};

class Minivan: public PassengerCar, public Bus
{
    public:
    Minivan(std::string c, std::string m): PassengerCar(c, m), Bus(c, m), Car(c, m)
    {
        std::cout << "Minivan: " << c << '\t' << m << std::endl;
    }
};

///////////////////////////////////////////////////////////////
/////////////////////TASK 3////////////////////////////////////
///////////////////////////////////////////////////////////////

class Fraction
{
    private:
    int divident, divisor;
    public:
    Fraction(): divident(0), divisor(1)
    {
    }
    Fraction(int dent, int dsor) : divident(dent), divisor(dsor)
    {
        if (dsor == 0)
            throw std::logic_error("Divisor is 0!\n");
    }
    Fraction operator+(Fraction F2) const
    {
        int com_dent, com_dsor;
        com_dent = divident * F2.divisor + F2.divident * divisor;
        com_dsor = divisor * F2.divisor;
        for (int i = (ABS(com_dent) > ABS(com_dsor) ? ABS(com_dsor) : ABS(com_dent)); i > 1 ; i--)
        {
            if (!(ABS(com_dent) % i) && !(ABS(com_dsor) % i))
            {
                com_dsor /= i;
                com_dent /= i;
            }
        }
        return(Fraction(com_dent, com_dsor));
    }
    Fraction operator-(Fraction F2) const
    {
        int com_dent, com_dsor;
        com_dent = divident * F2.divisor - F2.divident * divisor;
        com_dsor = divisor * F2.divisor;
        for (int i = (ABS(com_dent) > ABS(com_dsor) ? com_dsor : ABS(com_dent)); i > 1 ; i--)
        {
            if (!(ABS(com_dent) % i) && !(ABS(com_dsor) % i))
            {
                com_dsor /= i;
                com_dent /= i;
            }
        }
        return(Fraction(com_dent, com_dsor));
    }
    Fraction operator*(Fraction F2) const
    {
        int com_dent, com_dsor;
        com_dent = divident * F2.divident;
        com_dsor = divisor * F2.divisor;
        for (int i = (ABS(com_dent) > ABS(com_dsor) ? ABS(com_dsor) : ABS(com_dent)); i > 1 ; i--)
        {
            if (!(ABS(com_dent) % i) && !(ABS(com_dsor) % i))
            {
                com_dsor /= i;
                com_dent /= i;
            }
        }
        return(Fraction(com_dent, com_dsor));
    }
    Fraction operator/(Fraction F2) const
    {
        int com_dent, com_dsor;
        com_dent = divident * F2.divisor;
        com_dsor = divisor * F2.divident;
        for (int i = (ABS(com_dent) > ABS(com_dsor) ? ABS(com_dsor) : ABS(com_dent)); i > 1 ; i--)
        {
            if (!(ABS(com_dent) % i) && !(ABS(com_dsor) % i))
            {
                com_dsor /= i;
                com_dent /= i;
            }
        }
        return(Fraction(com_dent, com_dsor));
    }
    Fraction operator-() const
    {
        return (Fraction(-divident, divisor));
    }
    bool operator==(Fraction F2) const
    {
        return ((divident == F2.divident) && (divisor == F2.divisor));
    }
    bool operator!=(Fraction F2) const
    {
        return ((divident != F2.divident) || (divisor != F2.divisor));
    }
    bool operator>(Fraction F2) const
    {
        return (divident * F2.divisor > F2.divident * divisor);
    }
    bool operator<(Fraction F2) const
    {
        return (divident * F2.divisor < F2.divident * divisor);
    }
    bool operator<=(Fraction F2) const
    {
        return (!(*this > F2));
    }
    bool operator>=(Fraction F2) const
    {
        return (!(*this < F2));
    }
    void printFraction()
    {
        if (divisor < 0)
        {
            divisor *= -1;
            divident *= -1;
        }
        std::cout << divident << "/" << divisor << std::endl;
    }
};

///////////////////////////////////////////////////////////////
/////////////////////TASK 4////////////////////////////////////
///////////////////////////////////////////////////////////////

enum e_value {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10};

enum e_suit {hearts = 1, diamond, spades, clubs};

class Card
{
    private:
    e_value value;
    e_suit suit;
    bool faceUp;
    public:
    Card()
    {
        value = ace;
        faceUp = false;
    }
    Card(e_suit s, e_value v): value(v), suit(s)
    {
    }
    void Flip()
    {
        faceUp = !faceUp;
    }
    e_value GetValue() const
    {
        return (value);
    }
};

///////////////////////////////////////////////////////////////
///////////////////// MAIN ////////////////////////////////////
///////////////////////////////////////////////////////////////

int main(void)
{
///////////////////////////////////////////////////////////////
/////////////////////TASK 1////////////////////////////////////
///////////////////////////////////////////////////////////////

    Rectangle test1(5, 4);
    std::cout << test1.area() << std::endl;

///////////////////////////////////////////////////////////////
/////////////////////TASK 2////////////////////////////////////
///////////////////////////////////////////////////////////////

    Minivan test2("cmp", "mdl");

///////////////////////////////////////////////////////////////
/////////////////////TASK 3////////////////////////////////////
///////////////////////////////////////////////////////////////

    try 
    {
        Fraction test3(3, 0);
    }
    catch (std::exception const &a)
    {
        std::cerr << a.what();
    }
    Fraction F1(1, 3), F2(1,2), res;
    res = F1 + F2;
    res.printFraction();
    res = F1 - F2;
    res.printFraction();
    res = F1 * F2;
    res.printFraction();
    res = F1 / F2;
    res.printFraction();
    res = -F2;
    res.printFraction();
    if (-res == F2) std::cout << "True" << std::endl;
    if (!(-res != F2)) std::cout << "False" << std::endl;
    if (!(res == F2)) std::cout << "False" << std::endl;
    if ((res != F2)) std::cout << "True" << std::endl;
    if (!(F1 > F2)) std::cout << "False" << std::endl;
    if ((F1 <= F2)) std::cout << "True" << std::endl;
    if ((-res >= F2)) std::cout << "True" << std::endl;
    if (!(-res < F2)) std::cout << "False" << std::endl;

///////////////////////////////////////////////////////////////
/////////////////////TASK 4////////////////////////////////////
///////////////////////////////////////////////////////////////

    Card testc;
    testc.Flip();
    std::cout << testc.GetValue() << std::endl;
}