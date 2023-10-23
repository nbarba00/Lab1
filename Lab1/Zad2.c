/*. Definirati strukturu osoba (ime, prezime, godina rođenja) i napisati program koji:
A. dinamički dodaje novi element na početak liste,
B. ispisuje listu,
C. dinamički dodaje novi element na kraj liste,
D. pronalazi element u listi (po prezimenu),
E. briše određeni element iz liste,
U zadatku se ne smiju koristiti globalne varijable.
*/

#include<stdio.h>
#include<stdlib.h>
#include<atring.h>


typedef struct _person*Position

typedef struct _person {

	char ime[50];
	char prezime[50];
	int birthyear;
	Position Next;
}Person;

int main() {
	Person Head = { ime = {0},prezime = {0},birthyear = 0,Next = NULL };

}

Position create Person() {
	Position newPerson = NULL; 
	newPerson = (Position)malloc(sizeof(Person));
}
if (newPerson == NULL) {
	perror("Neuspjesno alociranje memorije za novu osobu!");
	exit(EXIT_FAILURE);
}

	char ime[50] = { 0 };
	char prezime[50] = { 0 };
	char birthyear = 0;



printf("Unesi neko ime:");
scanf("%s", ime);
printf("Unesi neko prezime:");
scanf("%s", prezime);
printf("Unesi neku godinu rodenja:");
scanf("%d", birthyear);

strcpy(newPerson->ime, ime);
trcpy(newPerson->prezime, prezime);
newPerson->birthyear = birthyear;
return newPerson;

//dodavanje na pocetak liste

int add_to_front(Position Head) {
	Position newPerson = NULL;
	newPerson = createPerson();
	if (newPerson == NULL) {
		return 0;
	}
		newPerson->Next = Head->Next;
		Head->Next = newPerson;
		return 1;
	}
}
