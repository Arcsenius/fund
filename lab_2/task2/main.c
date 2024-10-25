#include <stdio.h>
#include <functions.h>
#include <stdlib.h>

int main() {
    // проверка функции среднего геометрического
    double result1 = GeometricAverage(5, 1.0, 2.0, 3.0, 4.0, 5.0);

    printf("Geometric mean : %f\n", result1);



    // проверка возведения в степень
    double base = 2.0;
    int power = 5;
    double result2 = FastPower(base, power);
    printf("FastPower %f**%d = %f\n",base, power, result2);
}
