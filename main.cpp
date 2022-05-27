#define _USE_MATH_DEFINES

#include <iostream>

#include <cmath>
using namespace std;

// Тут может быть любая функция
double f(double x){
    return x;
}

//Считает значения указаной в параметрах функции из диапазона [a,b] при количестве разбиений n
// и записывает эти значения в  массив
void func_sums(double (*f)(double), double a, double b,double *list,double n) {
    double step=(b-a)/n;
    int i=0;
    double x=a;
    while (i<n ){
        list[i]=f(x);
        x+=step;
        ++i;
    }
}



// Функция для вычисления интеграла, в неё мы передаем массив со значениями функций
// и считаем интеграл по методу прямоугольника
double integrate(double *list, double step,int n){
    double sum=0.0;
    int size= sizeof(list);
    int i=0;
    while (i<n){
        sum+=list[i];
        i++;
    }
    return sum*step;
}


int main() {
    double a, b;
    int n;
    cout << "Enter [a,b] : \n";
    cin >> a;
    cin >> b;
    cin >> n;
    double h = (b-a)/n ;

    double *arr = new double [n];
    double (*func)(double );
    func = &f;
    func_sums(func, a,  b, arr, n);
    double result= integrate(arr,h,n);
    cout<<result<<endl;
    return 0;
}