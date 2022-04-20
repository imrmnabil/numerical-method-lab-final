#include<iostream>

using namespace std;

int n;
double x[100] ,y[100];

void lireg() ;
double sumx(double[]);
double sumxy(double[],double[]);

void lireg() {
    double a1, a0;

    a1 = ((n*sumxy(x,y) -(sumx(x)*sumx(y))))/((n*sumxy(x,x))-sumx(x)*sumx(x));
    a0 = (sumx(y)-a1*sumx(x))/n;

    cout<<"a0 = "<<a0<<endl;
    cout<<"a1 = "<<a1<<endl;

}

double sumx(double a[])
{
    double sum = 0;
    for(int i = 0 ; i < n;i++)
    {
        sum = sum + a[i];
    }
    return sum;
}

double sumxy(double a[],double b[])
{
    double sum = 0;
    for(int i = 0 ; i < n;i++)
    {
        sum = sum + a[i]*b[i];
    }
    return sum;
}

int main()
{
    cout<<"Total number of points ?";
    cin>>n;
    cout<<"x: ";
    for(int i = 0 ; i < n;i++)
    {
        cin>>x[i];
    }

    cout<<"y: ";
    for(int i = 0 ; i < n;i++)
    {
        cin>>y[i];
    }

    lireg();
    return 0;
}