//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * PhoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    if (matchPtr != NULL) {
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);

    } else {
        printf("Employee ID is NOT found in the record\n");
    }

    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL) {
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee Tony Bobcat is NOT found in the record \n");
    }

    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr != NULL) {
        printf("Employee with phone number 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with phone number 310-555-1215 is NOT found in the record \n");
    }

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if (matchPtr != NULL) {
        printf("Employee with salary $8.32 is in record %d\n", matchPtr - EmployeeTable);
    } else {
        printf("Employee with salary $8.32 is NOT found in the record \n");
    }
    return EXIT_SUCCESS;
}