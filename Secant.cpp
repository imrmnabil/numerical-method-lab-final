#include <iostream>
#include<cstdio>
#include <cmath>

using namespace std;

double x0, x1, x2, e, N, a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

void secant()
{
    int i = 1;
    if (f(x0) == f(x1))
    {
        cout << "Mathematical Error" << endl;
        return;
    }
    cout << "Iteration      x0       x1       x2     Error" << endl;
    while (true)
    {
        x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        printf("\t%d\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n",i,x0,x1,x2,fabs(f(x2)));
        if (i >= N)
        {
            cout << "Not Convergent" << endl;
            return;
        }
        if (fabs(f(x2)) > e)
        {
            x0 = x1;
            x1 = x2;
        }
        else
        {
            break;
        }
        i = i + 1;
    }
    cout << endl;
    printf("Accurate Root = %.4lf\n", x2);
}

int main()
{
    cout<<"Maximum Iteration?";
    cin>>N;

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

    cout << "Input x0 x1: ";
    cin >> x0 >> x1;
    secant();
    return 0;
}