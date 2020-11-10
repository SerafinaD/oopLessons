#ifndef PAIR1_H
# define PAIR1_H

template<class T>
class Pair1
{
	private:
	T fItem, sItem;
	public:
	Pair1(T f, T s): fItem(f), sItem(s)
	{
	}
	T first() const
	{
		return (fItem);
	}
	T second() const
	{
		return (sItem);
	}
};

#endif