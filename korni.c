#include <stdio.h>
#include <math.h>


int main()
{
    double a,b,c,d,x1,x2;
    printf("Введите a,b,c через пробел\n");
    scanf("%lf %lf %lf",&a,&b,&c);

    if (a==0)
    {
        printf("a не может быть равен 0 в квадратном уравнении\n");

        return 1;
    }
    d = b*b-4*a*c;
    if (d < 0)
    {
        printf("Уравнение не имеет действительных корней\n");
    }
    if (d == 0)
    {
        x1 = (-b+(sqrt(d)))/(2*a);
        printf("Корень уравнения: %lf\n",x1);
    }
    if (d>0)
    {
        x1 = (-b+(sqrt(d)))/(2*a);
        x2 = (-b-(sqrt(d)))/(2*a);
        printf("1-й корень уравнения: %lf\n",x1);
        printf("2-й корень уравнения: %lf\n",x2);
    }
}