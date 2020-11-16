#ifndef ENDLL_H
# define ENDLL_H
# include <iostream>

std::ostream& endll(std::ostream& stream)
{
    stream << std::endl << std::endl;
    stream.clear();
    return stream;
}

#endif