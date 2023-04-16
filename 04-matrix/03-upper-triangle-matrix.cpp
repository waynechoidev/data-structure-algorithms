// Row major
#include <iostream>
using namespace std;

class UpperTriangle
{
private:
    int *_arr;
    int _n;

public:
    UpperTriangle(int n)
    {
        _n = n;
        _arr = new int[n * (n + 1) / 2];
    }

    ~UpperTriangle()
    {
        delete[] _arr;
    }

    void Display();
    void Set(int i, int j, int x);
    int Get(int i, int j);
};

void UpperTriangle::Display()
{
    for (int i = 1; i <= _n; i++)
    {
        for (int j = 1; j <= _n; j++)
        {
            if (i <= j)
                cout << _arr[((i - 1) * _n) - ((i - 2) * (i - 1) / 2) + j - i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void UpperTriangle::Set(int i, int j, int x)
{
    if (i <= j)
        _arr[((i - 1) * _n) - ((i - 2) * (i - 1) / 2) + j - i] = x;
}

int UpperTriangle::Get(int i, int j)
{
    if (i <= j)
        return _arr[((i - 1) * _n) - ((i - 2) * (i - 1) / 2) + j - i];
    else
        return 0;
}

int main()
{
    UpperTriangle m(5);

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            m.Set(i, j, i + j);
    m.Set(5, 5, 100);
    m.Set(2, 4, 100);

    cout << m.Get(4, 2) << endl;
    cout << m.Get(3, 3) << endl;

    m.Display();

    return 0;
}