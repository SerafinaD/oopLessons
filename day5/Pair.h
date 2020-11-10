#ifndef PAIR_H
# define PAIR_H

template<class T1, class T2>
class Pair
{
	private:
	T1 fItem;
    T2 sItem;
	public:
	Pair(T1 f, T2 s): fItem(f), sItem(s)
	{
	}
	T1 first() const
	{
		return (fItem);
	}
	T2 second() const
	{
		return (sItem);
	}
};

#endif