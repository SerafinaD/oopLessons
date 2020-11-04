#include <iostream>

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////TASK 1//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

class Person
{
    private:
    std::string name    = "\0";
    int         age     = 0;
    char        sex     = '\0';
    int         weight  = 0;
    public:
    void        setName(std::string n)
    {
        name = n;
    }
    void        setAge(int a)
    {
        age = a;
    }
    void        setSex(char s)
    {
        sex = s;
    }
    void        setWeight(int w)
    {
        weight = w;
    }
    std::string getName() const
    {
        return (name);
    }
    int         getAge() const
    {
        return (age);
    }
    char        getSex() const
    {
        return (sex);
    }
    int         getWeight() const
    {
        return (weight);
    }
};

class Student: public Person
{
    private:
    static int numberOfStudents;
    public:
    Student(std::string name, int age, char sex, int weight): Person(name, age, sex, weight)
    {
        numberOfStudents++;
    }
    void    defineStudent(std::string name, int age, char sex, int weight)
    {
        setName(name);
        setAge(age);
        setSex(sex);
        setWeight(weight);
    }
    void    printStudent()
    {
        std::cout << "Name:\t" << getName() << std::endl;
        std::cout << "Age:\t" << getAge() << std::endl;
        std::cout << "Sex:\t" << (getSex() == 'm' ? "male" : "female") << std::endl;
        std::cout << "Weight:\t" << getWeight() << std::endl;
        std::cout << "NofS:\t" << numberOfStudents << std::endl;
    }
    static int getNumber()
    {
        return (numberOfStudents);
    }
    ~Student()
    {
        numberOfStudents--;
    }
};
int Student::numberOfStudents = 0;

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////TASK 2//////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

class Fruit
{
    private:
    std::string color;
    std::string name;
    protected:
    Fruit(std::string c, std::string n): color(c), name(n)
    {
    }
    std::string getName()
    {
        return (name);
    }
    std::string getColor()
    {
        return (color);
    }
};

class Apple: protected Fruit
{
    public:
    Apple(std::string color): Fruit(color, "apple")
    {
    }
    std::string getName()
    {
        return (Fruit::getName());
    }
    std::string getColor()
    {
        return (Fruit::getColor());
    }
};

class Banana: protected Fruit
{
    public:
    Banana(): Fruit("yellow", "banana")
    {
    }
    std::string getName()
    {
        return (Fruit::getName());
    }
    std::string getColor()
    {
        return (Fruit::getColor());
    }
};

class GrannySmith: public Apple
{
    public:
    GrannySmith(): Apple("green")
    {}
    std::string getName()
    {
        return ("Granny Smith " + Fruit::getName());
    }
    std::string getColor()
    {
        return (Fruit::getColor());
    }
};

int main()
{
    Student test;
    Student test2;
    Student test3;
    Student test4;
    test.defineStudent("name", 18, 'f', 60);
    test.printStudent();


    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}