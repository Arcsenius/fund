#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#define MAX_LEN 50
// Определение структуры String
typedef struct {
    char* data;    // Указатель на динамический массив символов
    int length;    // Длина строки
} String;


int strlen(char* str) {
    char *tmp = str;
    while (*tmp != '\0') {
        tmp++;
    }
        return (int)(str - tmp);
}

void strcpy(char* dest, char* src) {
    char *tmp = src;
    while (*tmp != '\0') {
        *dest++ = *tmp++;
    }
    *dest = '\0';

}


int strcmp( char* s1,  char* s2) {
    while (*s1 != '\0') {
        if (*s1 - *s2) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

void my_strcat(char* dest, char* src) {
    char *tmpdest = dest;
    char *tmpsrc = src;
    while (*tmpdest) {
        tmpdest++;
    }
    while (*tmpsrc) {
        *tmpdest++ = *tmpsrc++;
    }
}


int CheckLength(char* str) {
    int len = strlen(str);
    if (len - 1 > MAX_LEN) {
        return 0;
    }
    return 1;

}


// Функция для создания экземпляра String на основе значения типа char*
String createString(char* initialValue) {
    String str;
    if (!CheckLength(initialValue)) {
        return str;
    }
    str.length = strlen(initialValue);

    str.data = (char*)malloc(MAX_LEN * sizeof(char));  // +1 для завершающего символа '\0'
    if (str.data) {
        strcpy(str.data, initialValue); // Копируем значение строки
    }
    return str;
}

// Функция для удаления внутреннего содержимого экземпляра String
void deleteString(String* str) {
    free(str->data);
    str->data = NULL;
    str->length = 0;
}

// Функция для сравнения двух строк по длине, а затем лексикографически
int compareStrings(const String* str1, const String* str2) {
    if (str1->length < str2->length)
        return -1;
    if (str1->length > str2->length)
        return 1;
    return strcmp(str1->data, str2->data);
}

// Функция для проверки эквивалентности двух строк
int equals(const String* str1, const String* str2) {
    return strcmp(str1->data, str2->data) == 0;
}

// Функция для копирования содержимого одного экземпляра String в другой
void copyString(String* dest, const String* src) {
    dest->length = src->length;
    if (dest->data) {
        strcpy(dest->data, src->data);
    }
}

// Функция для копирования содержимого в новый экземпляр String, размещённый в динамической памяти
String cloneString(const String* src) {
    String newStr;
    newStr.length = src->length;
    newStr.data = (char*)malloc((MAX_LEN * sizeof(char)));
    if (newStr.data) {
        strcpy(newStr.data, src->data);
    }
    return newStr;
}

// Функция для конкатенации содержимого второй строки к первой строке
int concatenateStrings(String* str1, const String* str2) {
    if (str1->length + str2->length - 1 > MAX_LEN) {
        return 1;
    }
    if (str1->data) {
        my_strcat(str1->data, str2->data);
        str1->length += str2->length;
        return 0;
    }
    return 1;
}

// Пример использования реализованного функционала
int main() {
    // Создание строк
    String str1 = createString("Hello");
    String str2 = createString("World");

    // Демонстрация работы функций
    printf("str1: %s\n", str1.data);
    printf("str2: %s\n", str2.data);

    // Конкатенация
    concatenateStrings(&str1, &str2);
    printf("After concatenation, str1: %s\n", str1.data);

    // Копирование
    String str3;
    copyString(&str3, &str1);
    printf("Copied str3: %s\n", str3.data);

    // Сравнение
    int cmpResult = compareStrings(&str1, &str2);
    printf("Comparison result between str1 and str2: %d\n", cmpResult);

    // Проверка на эквивалентность
    int equalResult = equals(&str1, &str3);
    printf("Are str1 and str3 equal? %s\n", equalResult ? "Yes" : "No");

    // Очистка памяти
    deleteString(&str1);
    deleteString(&str2);
    deleteString(&str3);

    return 0;
}
