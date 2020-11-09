#ifndef ARRAYINT_H
# define ARRAYINT_H

# include <cassert>
# include <iostream>

class ArrayInt
{
private:
    int m_length;
    int *m_data;
    void    quicksort(int *data, const int len)
    {
        int const lenD = len;
        int pivot = 0;
        int ind = lenD/2;
        int i,j = 0,k = 0;
        if(lenD>1)
        {
            int* L = new int[lenD];
            int* R = new int[lenD];
            pivot = data[ind];
            for(i=0;i<lenD;i++){
            if(i!=ind){
                if(data[i]<pivot){
                L[j] = data[i];
                j++;
                }
                else{
                R[k] = data[i];
                k++;
                }
            }
            }
            quicksort(L,j);
            quicksort(R,k);
            for(int cnt=0;cnt<lenD;cnt++){
            if(cnt<j){
                data[cnt] = L[cnt];;
            }
            else if(cnt==j){
                data[cnt] = pivot;
            }
            else{
                data[cnt] = R[cnt-(j+1)];
            }
            }
        }
    }
public:
    ArrayInt(): m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length): m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength() 
    {
        return m_length;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;
        if (newLength <= 0)
        {
            erase();
            return;
        }
        int *data = new int[newLength];
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index = 0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
            for (int index = elementsToCopy; index < (newLength > m_length) ? m_length : newLength ; ++index)
                data[index] = 0;
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];
        for (int before=0; before < index; ++before)
        {
            data[before] = m_data[before];
        }
        data [index] = value;
        for (int after=index; after < m_length; ++after)
        {
            data[after+1] = m_data[after];
        }
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value) 
    {
        insertBefore(value, m_length);
    }

    void pop_back()
    {
        if (!m_length)
        {
            return ;
        }
        --m_length;
    }
    void pop_front()
    {
        if (!m_length)
        {
            return;
        }
        --m_length;
        *m_data = *(m_data + m_length);
        int temp;
        for(int i = 0; i < m_length; i++)
        {
            temp = *(m_data + i);
            *(m_data + i) = *(m_data + i + 1);
            *(m_data + i + 1) = temp;
        }

    }
    void print_arr()
    {
        int i = 0;
        while (i < m_length)
        {
            std::cout << *(m_data + i) << std::endl;
            i++;
        }

    }
    void    sort()
    {
        quicksort(m_data, m_length);
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }
};

#endif
