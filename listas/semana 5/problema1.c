#include <stdio.h>
#include <stdlib.h>

void define_rondasf0(int x, int y, int z);
void define_rondasf1(int x, int y, int z);

int main()
{
    int hora, minuto, formato;
    printf("defina a hora:\n");
    scanf("%d", &hora);
    printf("defina os minutos:\n");
    scanf("%d", &minuto);
    printf("defina o formato:\n");
    scanf("%d", &formato);
    if(minuto > 59){
        minuto -= 60;
        hora += 1;
    }
    if(hora > 23) hora -= 24;
    if(formato == 0) define_rondasf0(hora, minuto, formato);
    else if(formato == 1) define_rondasf1(hora, minuto, formato);
    return 0;
}
void define_rondasf0(int x, int y, int z){
    int a, b;
    a = 0;
    b = 0;
    printf("%d:%d\n", x, y);

    a = x + 1;
    if(a > 23) a = 00;
    printf("%d:%d\n", a, y);

    b = 0;
    a = 0;
    b = y + 10;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 2;
    if(a > 23) a = a - 24;
    printf("%d:%d\n", a, b);

    b = 0;
    a = 0;
    b = y + 40;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 4;
    if(a > 23) a = a - 24;
    printf("%d:%d\n", a, b);

    b = 0;
    a = 0;
    b = y + 5;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 12;
    if(a > 23) a = a - 24;
    printf("%d:%d\n", a, b);
}
define_rondasf1(int x, int y, int z){
    int a, b;
    a = 0;
    b = 0;
    printf("%d:%d\n", x, y);

    a = x + 1;
    if(a > 12) a = a - 12;
    printf("%d:%d\n", a, y);

    b = 0;
    a = 0;
    b = y + 10;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 2;
    if(a > 12) a = a - 12;
    printf("%d:%d\n", a, b);

    b = 0;
    a = 0;
    b = y + 40;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 4;
    if(a > 12) a = a - 12;
    printf("%d:%d\n", a, b);

    b = 0;
    a = 0;
    b = y + 5;
    if(b == 60){
        b = 0;
        a += 1;
    }
    else if(b > 60){
        b = b - 60;
        a += 1;
    }
    a = a + x + 12;
    if(a > 12) a = a - 12;
    printf("%d:%d\n", a, b);
}
