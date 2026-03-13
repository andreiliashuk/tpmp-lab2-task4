/*
 * Author: Андрей Ляшук, группа 10
 */
#include <stdio.h>
#include "car_owner.h"

#define MAX_OWNERS 100
#define INPUT_FILE "data/owners.txt"
#define OUTPUT_FILE "data/vaz_owners.txt"
#define TARGET_MAKE "ВАЗ"

int main() {
    CarOwner owners[MAX_OWNERS];
    CarOwner filtered[MAX_OWNERS];
    int count, filtered_count;

    printf(" Программа 'Владельцы автомобилей' (Вариант 8) \n\n");


    printf("1. Создание примера файла...\n");
    if (create_sample_file(INPUT_FILE) != 0) {
        return 1;
    }


    printf("\n2. Чтение данных из файла %s...\n", INPUT_FILE);
    count = read_owners_from_file(INPUT_FILE, owners, MAX_OWNERS);
    if (count == 0) {
        printf("Нет данных для обработки.\n");
        return 1;
    }

    printf("\n Содержимое файла (%d записей) \n", count);
    for (int i = 0; i < count; i++) {
        printf("%d. ", i + 1);
        print_owner(&owners[i]);
    }


    printf("\n3. Поиск владельцев автомобилей марки '%s'...\n", TARGET_MAKE);
    filtered_count = filter_by_car_make(owners, count, filtered, TARGET_MAKE);

    printf("\n Найдено %d владельцев \n", filtered_count);
    for (int i = 0; i < filtered_count; i++) {
        printf("%d. ", i + 1);
        print_owner(&filtered[i]);
    }


    printf("\n4. Сохранение результатов в файл %s...\n", OUTPUT_FILE);
    if (save_filtered_to_file(OUTPUT_FILE, filtered, filtered_count) == 0) {
        printf("Готово! Результаты сохранены.\n");
    }

    return 0;
}
