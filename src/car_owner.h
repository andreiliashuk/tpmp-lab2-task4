/*
 * Author: Андрей Ляшук, группа 10
 */

#ifndef CAR_OWNER_H
#define CAR_OWNER_H

/*
 * This header file defines structures and function prototypes
 * for working with car owner data and file I/O operations.
 */

#include <stdio.h>

/*
 * Address structure representing a full postal address.
 */
typedef struct {
    char postal_code[20];   /* Postal code */
    char country[50];       /* Country */
    char region[50];        /* Region/oblast */
    char district[50];      /* District/raion */
    char city[50];          /* City */
    char street[50];        /* Street */
    char house[20];         /* House number */
    char apartment[20];     /* Apartment number */
} Address;

/*
 * CarOwner structure containing personal and vehicle information.
 */
typedef struct {
    char lastname[50];      /* Last name */
    char firstname[50];     /* First name */
    char patronymic[50];    /* Patronymic */
    char phone[20];         /* Phone number */
    Address address;        /* Home address */
    char car_make[50];      /* Car make/model */
    char car_number[20];    /* License plate number */
    char tech_passport[20]; /* Technical passport number */
} CarOwner;

/*
 * Function: create_sample_file
 *   Creates a sample text file with car owner data.
 *   filename: name of the file to create
 *   returns: 0 on success, -1 on error
 */
int create_sample_file(const char *filename);

/*
 * Function: read_owners_from_file
 *   Reads car owner data from a text file.
 *   filename: name of the file to read
 *   owners: array to store read data
 *   max_count: maximum number of records to read
 *   returns: number of successfully read records
 */
int read_owners_from_file(const char *filename, CarOwner owners[], int max_count);

/*
 * Function: print_owner
 *   Prints a single car owner record to stdout.
 *   owner: pointer to the owner structure to print
 */
void print_owner(const CarOwner *owner);

/*
 * Function: print_owner_to_file
 *   Prints a single car owner record to a file.
 *   file: file pointer to write to
 *   owner: pointer to the owner structure to print
 */
void print_owner_to_file(FILE *file, const CarOwner *owner);

/*
 * Function: filter_by_car_make
 *   Filters an array of owners by car make.
 *   owners: source array
 *   count: number of elements in source array
 *   result: array to store filtered results
 *   make: car make to search for
 *   returns: number of found owners
 */
int filter_by_car_make(const CarOwner owners[], int count, 
                       CarOwner result[], const char *make);

/*
 * Function: save_filtered_to_file
 *   Saves filtered array to a text file
 *   filename: name of the output file
 *   owners: array to save
 *   count: number of elements to save
 *   returns: 0 on success, -1 on error
 */
int save_filtered_to_file(const char *filename, 
                          const CarOwner owners[], int count);

#endif /* CAR_OWNER_H */
