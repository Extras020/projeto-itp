#include <stdio.h>
#include <stdlib.h>

int main()
{
    float t_Celsius, t_Fahrenheit, t_Kelvin;
    scanf("%f", &t_Celsius);
    t_Fahrenheit = (t_Celsius*9/5)+32;
    t_Kelvin = t_Celsius + 273.15;
    printf("temperatura em Fahrenheit: %.1f", t_Fahrenheit);
    printf("temperatura em Kelvin: %.1f", t_Kelvin);
    return 0;
}
