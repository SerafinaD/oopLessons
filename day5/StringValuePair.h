#ifndef STRINGVALUEPAIR_H
# define STRINGVALUEPAIR_H
# include <string>
# include "Pair.h"

template <class T>
class StringValuePair: public Pair<std::string, T>
{
    private:
    
    public:
    StringValuePair(std::string str, T item): Pair<std::string, T>(str, item)
    {
    }
};
#endif