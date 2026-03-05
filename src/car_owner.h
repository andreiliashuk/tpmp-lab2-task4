#ifndef CAR_OWNER_H
#define CAR_OWNER_H

typedef struct {
    char postal_code[20];
    char country[50];
    char region[50];
    char district[50];
    char city[50];
    char street[50];
    char house[20];
    char apartment[20];
} Address;


typedef struct {
    char lastname[50];
    char firstname[50];
    char patronymic[50];
    char phone[20];
    Address address;
    char car_make[50];
    char car_number[20];
    char tech_passport[20];
} CarOwner;


int create_sample_file(const char *filename);


int read_owners_from_file(const char *filename, CarOwner owners[], int max_count);


void print_owner(const CarOwner *owner);


void print_owner_to_file(FILE *file, const CarOwner *owner);


int filter_by_car_make(const CarOwner owners[], int count, 
                       CarOwner result[], const char *make);


int save_filtered_to_file(const char *filename, 
                          const CarOwner owners[], int count);

#endif // CAR_OWNER_H
