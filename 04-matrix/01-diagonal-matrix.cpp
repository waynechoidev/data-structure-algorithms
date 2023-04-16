#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *_A;
    int _n;

public:
    Diagonal(int n)
    {
        _n = n;
        _A = new int[n];
    }

    ~Diagonal()
    {
        delete[] _A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Display()
{
    for (int i = 0; i < _n; i++)
    {
        for (int j = 0; j < _n; j++)
        {
            if (i == j)
                cout << _A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        _A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return _A[i - 1];
    else
        return 0;
}

int main()
{
    Diagonal m(4);

    m.Set(1, 1, 5);
    m.Set(2, 2, 6);
    m.Set(3, 3, 7);
    m.Set(4, 4, 8);

    cout << m.Get(1, 1) << endl;
    m.Display();

    return 0;
}