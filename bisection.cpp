#include <iostream>
#include <cmath>

using namespace std;

double coef1, coef2, coef3, coef4, e, c;

double fn0(double x);
void bisec(double, double);

int main()
{
    double x1, x2;

    cout << "Enter the coefficients for the equation 'ax^3 + bx^2 + cx + d = 0'" << endl;
    cout << "a ? ";
    cin >> coef1;
    cout << "b ? ";
    cin >> coef2;
    cout << "c ? ";
    cin >> coef3;
    cout << "d ? ";
    cin >> coef4;
    cout << endl;

    cout << "Minimum acceptable Error: ";
    cin >> e;

    cout << "Input x1 x2: ";
    cin >> x1 >> x2;
    bisec(x1, x2);

    cout << endl;
    printf("Accurate Root = %.4lf\n", c);
    return 0;
}

double fn(double x)
{
    return coef1 * pow(x, 3) + coef2 * pow(x, 2) + coef3 * x + coef4;
}
void bisec(double x1, double x2)
{
    int it = 1;
    double er;
    if (fn(x1) * fn(x2) >= 0)
    {
        cout << "Incorrect x1 and x2" << endl;
        return;
    }

    cout << "Iteration        x1       x2       xr     Error" << endl;
    while (fabs(x2 - x1) >= e)
    {
        printf("        %02d     ", it);
        c = (x1 + x2) / 2;
        er = x2 - x1;
        printf("%.4lf   %.4lf   %.4lf   %.4lf\n", x1, x2, c, er);
        if (fn(c) == 0.0)
        {
            break;
        }
        else if (fn(c) * fn(x1) > 0)
        {
            x1 = c;
        }
        else
        {
            x2 = c;
        }
        it++;
    }
}