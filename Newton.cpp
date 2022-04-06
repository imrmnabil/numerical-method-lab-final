#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double x0, x1, N, a, b, c, d, e, err;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

double g(double x)
{
    return (3 * a * x * x) + (2 * b * x) + c;
}

void newton()
{
    int i = 1;
    cout << "Iteration      x0       x1       Error" << endl;
    while (true)
    {
        x1 = x0 - (f(x0) / g(x0));
        err = (x1 - x0) / x1;
        printf("\t%d\t%.4lf\t%.4lf\t%.4lf\n", i, x0, x1, err);
        if (err <= e)
        {
            break;
        }
        x0 = x1;
        i++;
    }
}

int main()
{
    cout << "Maximum Iteration?";
    cin >> N;

    cout << "Enter the coefficients for the equation 'ax^3 + bx^2 + cx + d = 0'" << endl;
    cout << "a ? ";
    cin >> a;
    cout << "b ? ";
    cin >> b;
    cout << "c ? ";
    cin >> c;
    cout << "d ? ";
    cin >> d;
    cout << endl;

    cout << "  Error: ";
    cin >> e;

    cout << "Input x0: ";
    cin >> x0;
    newton();
    return 0;
}