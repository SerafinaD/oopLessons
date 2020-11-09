#ifndef CARD_H
# define CARD_H

enum e_value {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

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
    Card(e_value v, e_suit s): value(v), suit(s)
    {
    }
    void Flip()
    {
        faceUp = !faceUp;
    }
    e_value GetValue() const
    {
        return (value < 10 ? value : 10);
    }
};

#endif