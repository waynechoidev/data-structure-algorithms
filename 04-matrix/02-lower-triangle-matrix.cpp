// Row major
#include <iostream>
using namespace std;

class LowerTriangle
{
private:
    int *_arr;
    int _n;

public:
    LowerTriangle(int n)
    {
        _n = n;
        _arr = new int[n * (n + 1) / 2];
    }

    ~LowerTriangle()
    {
        delete[] _arr;
    }

    void Display();
    void Set(int i, int j, int x);
    int Get(int i, int j);
};

void LowerTriangle::Display()
{
    for (int i = 1; i <= _n; i++)
    {
        for (int j = 1; j <= _n; j++)
        {
            if (i >= j)
                cout << _arr[(i * (i - 1) / 2) + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void LowerTriangle::Set(int i, int j, int x)
{
    if (i >= j)
        _arr[((i) * (i - 1) / 2) + j - 1] = x;
}

int LowerTriangle::Get(int i, int j)
{
    if (i >= j)
        return _arr[(i * (i - 1) / 2) + j - 1];
    else
        return 0;
}

int main()
{
    LowerTriangle m(5);

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            m.Set(i, j, i + j);

    cout << m.Get(2, 4) << endl;
    cout << m.Get(3, 3) << endl;

    m.Display();

    return 0;
}