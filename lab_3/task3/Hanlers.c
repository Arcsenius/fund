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
    Employee *emp1 = (Employee *)a;
    Employee *emp2 = (Employee *)b;

    if (emp1->salary < emp2->salary) return -1;
    if (emp1->salary > emp2->salary) return 1;

    int last_name_cmp = strcmp(emp1->lastName, emp2->lastName);
    if (last_name_cmp != 0) return last_name_cmp;

    int first_name_cmp = strcmp(emp1->firstName, emp2->firstName);
    if (first_name_cmp != 0) return first_name_cmp;

    return emp1->id - emp2->id;
}


int CompareEmployeesD(const void *a, const void *b) {
    Employee *emp1 = (Employee *)a;
    Employee *emp2 = (Employee *)b;

    if (emp1->salary < emp2->salary) return 1;
    if (emp1->salary > emp2->salary) return -1;

    int last_name_cmp = -strcmp(emp1->lastName, emp2->lastName);
    if (last_name_cmp != 0) return last_name_cmp;

    int first_name_cmp = -strcmp(emp1->firstName, emp2->firstName);
    if (first_name_cmp != 0) return first_name_cmp;

    return -(emp1->id - emp2->id);
}


kState HandlerOptA( char* file1,  char* file2) {
    FILE* input = fopen(file1, "r");
    FILE* output = fopen(file2, "w");
    if (input == NULL) {
        fclose(output);
        return kE_PATH1_NOT_FOUND;
    }
    if (output == NULL) {
        fclose(input);
        return kE_PATH2_NOT_FOUND;
    }

    int lines = CountLines(input);
    if (!lines) {
        fclose(input);
        fclose(output);
        return kE_FILE_IS_EMPTY;
    }
    Employee* employees = (Employee*)malloc(sizeof(Employee) * lines );
    if (employees == NULL) {
        fclose(input);
        fclose(output);
        return kE_INVALID_MEMORY_ALLOCATION;
    }

    int i = 0;
    while ( fscanf(input, "%d;%49[^;];%49[^;];%lf", &employees[i].id, employees[i].lastName, employees[i].firstName, &employees[i].salary ) == 4) {
        ++i;
    }


    fclose(input);

    qsort(employees, lines, sizeof(Employee), CompareEmployeesA);

    for (int k = 0; k < lines; ++k) {
        fprintf(output, "%d;%s;%s;%.2lf\n",employees[k].id, employees[k].lastName, employees[k].firstName, employees[k].salary );
    }
    fclose(output);
    free(employees);

    return kS_OK;
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









kState HandlerOptD( char* file1,  char* file2) {
    FILE* input = fopen(file1, "r");
    FILE* output = fopen(file2, "w");
    if (input == NULL) {
        fclose(output);
        return kE_PATH1_NOT_FOUND;
    }
    if (output == NULL) {
        fclose(input);
        return kE_PATH2_NOT_FOUND;
    }

    int lines = CountLines(input);
    if (!lines) {
        fclose(input);
        fclose(output);
        return kE_FILE_IS_EMPTY;
    }
    Employee* employees = (Employee*)malloc(sizeof(Employee) * lines );
    if (employees == NULL) {
        fclose(input);
        fclose(output);
        return kE_INVALID_MEMORY_ALLOCATION;
    }

    int i = 0;
    while ( fscanf(input, "%d;%49[^;];%49[^;];%lf", &employees[i].id, employees[i].lastName, employees[i].firstName, &employees[i].salary ) == 4) {
        ++i;
    }


    fclose(input);

    qsort(employees, lines, sizeof(Employee), CompareEmployeesD);

    for (int k = 0; k < lines; ++k) {
        fprintf(output, "%d;%s;%s;%.2lf\n",employees[k].id, employees[k].lastName, employees[k].firstName, employees[k].salary );
    }
    fclose(output);
    free(employees);

    return kS_OK;
}