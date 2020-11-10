#ifndef GENERICPLAYER_H
# define GENERICPLAYER_H
# include <iostream>
# include <string>
# include "hand.h"

class GenericPlayer: public Hand
{
    private:
    std::string name;
    public:
    virtual IsHitting() = 0;
    bool IsBoosted()
    {
        return (GetValue() > 21);
    }
    void Bust()
    {
        std::cout << name << " busted!" << std::endl;
    }
};

#endif