#include <iostream>  
#include <clocale>  
#include <math.h>  
using namespace std;
double a, b; // объявление интервал 
double e; // объявление точности 
double x0;// объявление точки x0  
double x;// объявление точки x  

double f(double z) // значение функции в точке касания  
{
    return acos(z) - sqrt(1 - 0.3 * pow(z, 3));
}

double fp(double z) // значение производной функции в точке касания  
{
    return (9 * pow(z, 2)) / (20 * sqrt(1 - 3 * pow(z, 3) / 10)) - 1 / sqrt(1 - pow(z, 2));
}

int main()
{
    setlocale(LC_ALL, "RU");
    e = 0.0001; // задаём точность  

    cout << "Введите интревал: ";
    cin >> a >> b;

    cout << "Введите точку x0: ";
    cin >> x0;
   
    x = x0 - f(x0) / fp(x0);
    int k = 1;
    cout << "Итерация " << k << ": " << x << endl;
    while (fabs(x0 - x) >= e)
    {
        x0 = x;
        x = x0 - f(x0) / fp(x0);
        k++;
        cout << "Итерация " << k << ": " << x << endl;
    }
    cout << "Итог: " << x;
    return 0;
}