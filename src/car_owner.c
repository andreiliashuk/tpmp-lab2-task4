/*
 * Author: Андрей Ляшук, группа 10
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "car_owner.h"

int create_sample_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return -1;
    }

    fprintf(file, "Иванов;Иван;Иванович;+375291234567;220000;Беларусь;Минская;Минский;Минск;Ленина;10;15;ВАЗ;А123ВЕ;ТП123456\n");
    fprintf(file, "Петров;Петр;Петрович;+375297654321;210000;Беларусь;Витебская;Витебский;Витебск;Советская;25;3;Audi;В789ОР;ТП789012\n");
    fprintf(file, "Сидоров;Сидор;Сидорович;+375336661122;230000;Беларусь;Гродненская;Гродненский;Гродно;Октябрьская;7;42;ВАЗ;Е456КМ;ТП345678\n");
    fprintf(file, "Козлов;Алексей;Петрович;+375447778899;224000;Беларусь;Брестская;Брестский;Брест;Московская;15;8;Renault;К789АВ;ТП901234\n");
    fprintf(file, "Новиков;Дмитрий;Сергеевич;+375259991122;246000;Беларусь;Гомельская;Гомельский;Гомель;Кирова;33;5;ВАЗ;М123ОР;ТП567890\n");

    fclose(file);
    printf("Создан пример файла: %s\n", filename);
    return 0;
}
/*
 * Function: read_owners_from_file
 *   Reads and parses car owner data from a semicolon-separated file.
 */
int read_owners_from_file(const char *filename, CarOwner owners[], int max_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[512];

    while (count < max_count && fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = 0;

        CarOwner *o = &owners[count];
        char *token = strtok(line, ";");

        if (token) strcpy(o->lastname, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->firstname, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->patronymic, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->phone, token);


        token = strtok(NULL, ";");
        if (token) strcpy(o->address.postal_code, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.country, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.region, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.district, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.city, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.street, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.house, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->address.apartment, token);

        token = strtok(NULL, ";");
        if (token) strcpy(o->car_make, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->car_number, token);
        token = strtok(NULL, ";");
        if (token) strcpy(o->tech_passport, token);

        count++;
    }

    fclose(file);
    return count;
}
/*
 * Function: print_owner
 *   Prints owner information to console in formatted way.
 */
void print_owner(const CarOwner *o) {
    printf("%s %s %s | Тел: %s | Адрес: %s, %s, %s, %s, %s, %s %s-%s | "
           "Авто: %s %s | ТП: %s\n",
           o->lastname, o->firstname, o->patronymic, o->phone,
           o->address.postal_code, o->address.country, o->address.region,
           o->address.district, o->address.city, o->address.street,
           o->address.house, o->address.apartment,
           o->car_make, o->car_number, o->tech_passport);
}
/*
 * Function: print_owner_to_file
 *   Writes owner information to file in semicolon-separated format.
 */
void print_owner_to_file(FILE *file, const CarOwner *o) {
    fprintf(file, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n",
           o->lastname, o->firstname, o->patronymic, o->phone,
           o->address.postal_code, o->address.country,
           o->address.region, o->address.district,
           o->address.city, o->address.street,
           o->address.house, o->address.apartment,
           o->car_make, o->car_number, o->tech_passport);
}
/*
 * Function: filter_by_car_make
 *   Filters owners by specified car make.
 */
int filter_by_car_make(const CarOwner owners[], int count, 
                       CarOwner result[], const char *make) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(owners[i].car_make, make) == 0) {
            result[found++] = owners[i];
        }
    }
    return found;
}
/*
 * Function: save_filtered_to_file
 *   Saves filtered owners to output file.
 */
int save_filtered_to_file(const char *filename, 
                          const CarOwner owners[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка: не удалось создать файл %s\n", filename);
        return -1;
    }

    for (int i = 0; i < count; i++) {
        print_owner_to_file(file, &owners[i]);
    }

    fclose(file);
    printf("Сохранено %d записей в файл %s\n", count, filename);
    return 0;
}
