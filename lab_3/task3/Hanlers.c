#include "Hanlers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "states.h"
#include "employee.h"



int CountLines(FILE *file) {
    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        count++;
    }

    rewind(file);  // Возвращаем указатель в начало файла
    return count;
}


int CompareEmployeesA(const void *a, const void *b) {
    const Employee *emp1 = (const Employee *)a;
    const Employee *emp2 = (const Employee *)b;

    if (emp1->salary - emp2->salary) {
        return emp1->salary - emp2->salary;
    }


    int lastNameCmp = strcmp(emp1->lastName, emp2->lastName);


    if (lastNameCmp) {
        return lastNameCmp;
    }


    int firstNameCmp = strcmp(emp1->firstName, emp2->firstName);


    if (firstNameCmp) {
        return firstNameCmp;
    }
    return emp1->id - emp2->id;
}

int CompareEmployeesD(const void *a, const void *b) {
    return CompareEmployeesA(b, a);
}


void HandlerOptA(Employee* employees, int lines) {


    qsort(employees, lines, sizeof(Employee), CompareEmployeesA);

}






void LogErrors(kState error) {
    switch (error) {
        case kE_INVALID_MEMORY_ALLOCATION:
            printf("Invalid memory allocation\n");
        break;
        case kE_FILE_IS_EMPTY:
            printf("Input file is empty\n");
        break;
        case kE_PATH1_NOT_FOUND:
            printf("Path 1 not found\n");
        break;
        case kE_PATH2_NOT_FOUND:
            printf("Path 2 not found\n");
        break;
        case kE_INVALID_FLAG:
            printf("Invalid flag\n");
        break;
        case kE_INVALID_NUMBER_ARGS:
            printf("Invalid number of arguments\n");
        break;
        default:
            printf("Unknown error\n");
        break;
    }
    return;
}









void HandlerOptD(Employee* employees, int lines) {


    qsort(employees, lines, sizeof(Employee), CompareEmployeesD);


}