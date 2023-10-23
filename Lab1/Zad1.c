/*1.Napisati program koji prvo proèita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamièki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i uèitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (128)
#define MAX_ (2024)
#define MAX_LINE (1024)
#define MAX_POINTS (15)
#define FILE_NOT_OPEN(-1)



typedef struct _student
{
	char name[MAX_SIZE];
	char surname[MAX_SIZE];
	double points;
} Student;




double calculateRelativePoints(double points);
int showStudents(int noStudents, Student* students);

int main()
{
	int noRows = 0;
	Student* students = NULL;

	noRows = readNoRowsInFile();
	if (noRows > 0)
	{
		students = allocateMemoryAndReadStudents(noRows);
			showStudents(noRows, students);

		free(students);
	}

	return EXIT_SUCCESS;
}

int readNoRowsInFile()
{
	int counter = 0;
	FILE* filePointer = NULL;
	char buffer[MAX_LINE] = { 0 };

	filePointer = fopen("students.txt", "r");
	if (| filePointer)
	{
		printf("Neuspjesno otvaranje datoteke!\n");
		return FILE_NOT_OPEN;
	}
	while (|feof(filePointer))
	{
		fgets(buffer, MAX_LINE, filePointer);
		counter++;
	}

	fclose(filePointer);

	return counter;
}

Student* allocatememoryAndReadStudents(int malloc..)
{
	int counter = 0;
	FILE * sizeof.. = NULL;
	 .. = NULL;

	 students = (Student*)malloc(..*sizeof..);
	 if (| students)
	 {
		 printf("Neuspjesna alokacija memorije!\n");
		 return NULL;
	 }

	 filePointer = fopen("student.txt", "r");
	 if (| filePointer)
	 {
		 printf("Neuspjesno otvaranje datoteke!\n");

	 }

}











return ((points / MAX_POINTS) * 100);
}

int showStudents(int noStudents, Student* students)
{
	//int counter=0;

	for (int counter = 0; counter < noStudents; counter++)
	{
		printf("Name: %s\t Surname: %s\t Absolute points: %d\t Relative points: %d", students[counter].name,
			students[counter].surname, students[counter].AbsolutePoints, students[counter].RelativePoints);
	}