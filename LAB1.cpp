#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[50];
	int day, month, year;
	float mathmark, physicmark, languagemark;
	struct Student* next;
} sStudent;

//1. Viet ham in thong tin cua sinh vien
void printStudent(sStudent *st)
{
	printf("%s\n", st->name);
}

//2. Viet ham tao 1 hoc sinh co ten, ngay sinh, diem va tra ve mot con tro, tro den cau truc
sStudent* createStudent(char *name, int day, int month, int year, float mathmark, float physicmark, float languagemark)
{
	sStudent* st;
	st = (sStudent*) malloc(sizeof(sStudent));
	strcpy(st->name, name);
	st->day = day;
	st->month = month;
	st->year = year;
	st->mathmark = mathmark;
	st->physicmark = physicmark;
	st->languagemark = languagemark;
	st->next = NULL;
	return st;
}

//3. Viet ham them 1 hoc sinh vao danh sach
sStudent* addStudent(sStudent* list, char *name, int day, int month, int year, float mathmark, float physicmark, float languagemark)
{
	sStudent* temp = createStudent(name, day, month, year, mathmark, physicmark, languagemark);
	temp->next = list;
	list = temp;
	return list;
}

//4. Viet ham tra ve so luong hoc sinh co cung nam sinh
int getStudentCount(sStudent* list, int year)
{
	int dx = 0;
	sStudent* p = list;
	while (p) {
		if (p->year == year) dx++;
		p = p->next;
	}
	return dx;
}

//5. Viet ham kiem tra neu mot hoc sinh ton tai trong danh sach
bool checkStudent(sStudent* list, char *name)
{
	sStudent* p = list;
	while (p) {
		if (strcmp(p->name, name) == 0)
			 return true;
		p = p->next;
	}
	return false;
}

//6. Viet ham xoa mot hoc sinh trong danh sach
sStudent* removeStudent(sStudent *list, char *name)
{
	sStudent* p = list;
	sStudent* tmp;
	
	if (strcmp(list->name, name) == 0)
	{
		list = list->next;
		return list;
	}
	
	while (p) {
		if (strcmp(p->name, name) == 0) 
		{
			tmp->next = p->next;
			free(p);
			return list;
		}
		tmp = p;
		p = p->next;
	}
	return list;
}
// In ra danh sach hoc sinh
void printList(sStudent* list) 
{
	sStudent* p = list;
	while (p) {
		printf("%s\n", p->name);
		p = p->next;
	}
}

//7. Viet ham tim nhung hoc sinh có diem toan, li, ngoai ngu cao nhat
sStudent* findGoodStudent(sStudent* list)
{
	sStudent* st;
	float tongMax = 0;
	sStudent* p = list;
	while (p) {
		float tong = p->mathmark + p->physicmark + p->languagemark;
		
		if (tong > tongMax) 
		{
			tongMax = tong;
			st = p;
		}
		p = p->next;
	}
	return st;
}

int main(){
	sStudent* list = NULL;
	// Tao danh sach cua 5 hoc sinh Hung, Thi, Anh, Thu ,Hong
	list = addStudent(list,"Hung", 23,8,1995,2,3,8);
	list = addStudent(list,"Thi", 30,4,1998,9,6,10);
	list = addStudent(list,"Anh", 26,3,1997,2,3,5);
	list = addStudent(list,"Thu", 10,6,1995,9,6,10);
	list = addStudent(list,"Hong", 17,8,1993,4,7,5);
	
	// In ra danh sach 
	printf("List:\n");
	printList(list);
	printf("\n");

	// Dem so hoc sinh co cung nam sinh la 1995
	printf(" The number of students for a year of birth in 1995:\n");
	printf("%d\n\n\n", getStudentCount(list, 1995));

	// Kiem tra neu Hung ton tai
	if (checkStudent(list, "Hung")) 
		printf("Hung exist\n");
	else
		 printf("Hung doesn't exist \n");
	
	// Kiem tra neu Hong ton tai 
	if (checkStudent(list, "Hong")) 
		printf("Hong exist \n");
	else 
		printf("Hong doesn't exist\n");
	printf("\n");
	
	// Xoa Anh va Thu
	removeStudent(list, "Anh");
	removeStudent(list, "Tu");
	
	// In ra danh sach sau khi xoa la:
	printf("List after remove:\n");
	printList(list);
	return 0;
}
