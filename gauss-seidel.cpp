#include <iostream>
#include <cstdio>

using namespace std;

float x1 = 0, x2 = 0, x3 = 0, a[4] = {0}, b[4] = {0}, c[4] = {0}, d[4] = {0}, err;
int max_it;

void seidel()
{
    double err1, err2, err3, old_x1, old_x2, old_x3;
    int it = 0;
    while (true)
    {
        it++;
        old_x1 = x1;
        old_x2 = x2;
        old_x3 = x3;

        x1 = (d[1] - (b[1] * x2 + c[1] * x3)) / a[1];
        x2 = (d[2] - (a[2] * x1 + c[2] * x3)) / b[2];
        x3 = (d[3] - (a[3] * x1 + b[3] * x2)) / c[3];

        err1 = abs((x1 - old_x1) / x1) * 100;
        err2 = abs((x2 - old_x2) / x2) * 100;
        err3 = abs((x3 - old_x3) / x3) * 100;
        // if ((err1 < err) && (err2 < err) && (err3 < err))
        // {
        //     cout<<"    "<<x1<<"    "<<x2<<"    "<<x3<<endl;
        //     break;
        // }
        printf("%6.6lf\t%6.6lf\t%6.6lf\n",x1,x2,x3);
        if (it>=max_it)
        {
            
            break;
        }


    }
}

int main()
{
    cout << "Enter coefficients:"<<endl;
    cout<<"For equation 1:";
    cin>>a[1]>>b[1]>>c[1]>>d[1];
    cout<<"For equation 2:";
    cin>>a[2]>>b[2]>>c[2]>>d[2];
    cout<<"For equation 3:";
    cin>>a[3]>>b[3]>>c[3]>>d[3];

    cout<<"Maximum iteration ?";
    cin>>max_it;
    seidel();
    return 0;
}