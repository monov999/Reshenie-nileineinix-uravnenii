#include <iostream> 
#include <clocale> 
#include <math.h> 
using namespace std;
double a, b; //объявление координат интервала 
double с; //объявление середины интервала 

double f(double x)
{
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3)); // уравнение 
}

int main() {

    setlocale(LC_ALL, "RU");
    double e = 0.0001; //точность эпсилона 

    cout << "Введите интревал: ";
    cin >> a >> b;

    int k = 0;
    if (f(a) * f(b) < 0)
    {
        while (fabs(a - b) > e)
        {
            с = (b + a) / 2;
            if (f(a) * f(с) < 0)
            {
                b = с;
            }
            else
            {
                a = с;
            }
            k++;
            cout << "Итерация " << k << ": " << с << endl;
        }
        cout << "Итог: " << с;
    }
    else
    {
        cout << "Фунция не пересекает ось Ox в интервале (a,b)";
    }
    return 0;
}

