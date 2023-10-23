/*1.Napisati program koji prvo proèita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamièki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i uèitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128
#define MAX_STUDENTS 2024
#define MAX_LINE 1024
#define MAX_POINTS 15
#define FILE_NOT_OPEN -1

typedef struct Student {
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    double points;
    double relativePoints;
} Student;

double calculateRelativePoints(double points);
int showStudents(int noStudents, Student* students);
int readNoRowsInFile();
Student* allocateMemoryAndReadStudents(int noRows);

int main() {
    int noRows = 0;
    Student* students = NULL;

    noRows = readNoRowsInFile();
    if (noRows > 0) {
        students = allocateMemoryAndReadStudents(noRows);
        showStudents(noRows, students);

        free(students);
    }

    return 0;
}

int readNoRowsInFile() {
    int counter = 0;
    FILE* filePointer = NULL;
    char buffer[MAX_LINE];

    filePointer = fopen("students.txt", "r");
    if (filePointer == NULL) {
        printf("Neuspjesno otvaranje datoteke!\n");
        return -1;
    }

    while (!feof(filePointer)) {
        fgets(buffer, MAX_LINE, filePointer);
        counter++;
    }

    fclose(filePointer);

    return counter;
}

Student* allocateMemoryAndReadStudents(int noRows) {
    FILE* filePointer = NULL;
    Student* students = (Student*)malloc(noRows * sizeof(Student));

    if (students == NULL) {
        printf("Neuspjesna alokacija memorije!\n");
        return NULL;
    }

    filePointer = fopen("students.txt", "r");
    if (filePointer == NULL) {
        printf("Neuspjesno otvaranje datoteke!\n");
        free(students);
        return NULL;
    }

    for (int i = 0; i < noRows; i++) {
        if (fscanf(filePointer, "%s %s %lf", students[i].name, students[i].surname, &students[i].points) != 3) {
            printf("Greska pri citanju podataka iz datoteke.\n");
            free(students);
            fclose(filePointer);
            return NULL;
        }
        students[i].relativePoints = calculateRelativePoints(students[i].points);
    }

    fclose(filePointer);
    return students;
}

double calculateRelativePoints(double points) {
    return (points / MAX_POINTS) * 100;
}

int showStudents(int noStudents, Student* students) {
    for (int i = 0; i < noStudents; i++) {
        printf("Name: %s\t Surname: %s\t Absolute points: %.2lf\t Relative points: %.2lf%%\n",
            students[i].name, students[i].surname, students[i].points, students[i].relativePoints);
    }
    return 0;
}
