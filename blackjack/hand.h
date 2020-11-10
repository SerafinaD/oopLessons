class Hand
{
    private:
    std::vector<Card*> Cards;
    public:
    void Add(Card* newcard)
    {
        Cards.push_back(newcard);
    }
    void Clear()
    {
        while (!Cards.empty())
        {
            delete Cards.back();
            Cards.pop_back();
        }
    }
    int GetValue()
    {
        int res = 0;
        int value;
        int ace = 0;
        for (int i = 0; i < Cards.size(); i++)
        {
            value = Cards[i]->GetValue();
            if (value == 1)
            {
                ace++;
            }
            else
            {
                res += value;
            }
        }
        while (ace)
        {
            res += (res > 10 ? 1 : 11);
            ace--;
        }
        return (res);
    }
};