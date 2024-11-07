#include <stdio.h>
#include <stdlib.h>

#include "ParseArgs.h"
#include "Hanlers.h"
#include "employee.h"

int main(int argc,  char **argv) {
    kOption opt;



    char* file1;
    char* file2;
    kState code = ParseArgs(argc, argv, &file1, &opt, &file2);
    if (code != kS_OK) {
        LogErrors(code);
        return 1;
    }
    void (*Handlers[2])(Employee*, int) = {
        HandlerOptA,
        HandlerOptD
    };

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
        free(employees);
        fclose(input);
        fclose(output);
        return kE_INVALID_MEMORY_ALLOCATION;
    }

    int i = 0;
    while ( fscanf(input, "%d;%49[^;];%49[^;];%lf",
        &employees[i].id,
        employees[i].lastName,
        employees[i].firstName,
        &employees[i].salary ) == 4) {
        ++i;
        }


    fclose(input);

    Handlers[opt](employees, lines);

    for (int k = 0; k < lines; ++k) {
        fprintf(output, "%d;%s;%s;%.2lf\n",employees[k].id, employees[k].lastName, employees[k].firstName, employees[k].salary );
    }


    return kS_OK;
}
