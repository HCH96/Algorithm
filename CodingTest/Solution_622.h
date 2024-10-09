#pragma once

using namespace std;

#include <vector>

class MyCircularQueue 
{
private:
    int m_Size;
    int m_Capacity;
    int m_First;
    int m_Last;
    int* m_Arr;

public:
    MyCircularQueue(int k) 
    : m_Size(0)
    , m_First(-1)
    , m_Last(-1)
    , m_Capacity(k)
    , m_Arr(nullptr)
    {
        m_Arr = new int[k];
        
        for (int i = 0; i < k; ++i)
        {
            m_Arr[i] = -1;
        }
    }

    bool enQueue(int value) 
    {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            m_First = 0;
            m_Last = -1;
        }

        ++m_Last;

        if (m_Last >= m_Capacity)
        {
            m_Last = 0;
        }

        m_Arr[m_Last] = value;
        ++m_Size;

        return true;
    }

    bool deQueue() 
    {
        if (isEmpty())
        {
            return false;
        }

        m_Arr[m_First++] = -1;
        if (m_First >= m_Capacity)
        {
            m_First = 0;
        }

        --m_Size;

        return true;
    }

    int Front() 
    {
        if (isEmpty())
            return -1;

        return m_Arr[m_First];
    }

    int Rear() 
    {
        if (isEmpty())
            return -1;

        return m_Arr[m_Last];
    }

    bool isEmpty() 
    {
        if (m_Size == 0)
            return true;
        
        return false;
    }

    bool isFull() 
    {
        if (m_Size == m_Capacity)
            return true;

        return false;
    }
};
