#include <stdio.h>
#include <stdlib.h>

struct student{
	
	int roll;
	char name[10];
	float marks;
};

typedef struct student Student;

int main(){
	
	Student s1 = {1,"Dhiraj" ,67};
	Student s2;
	printf("Enter the roll number for student 2 :");
	scanf("%d" ,&s2.roll);
	
	printf("Enter the namer for student 2 :");
	scanf("%s" ,s2.name);
	
	printf("Enter the marks for student 2 :");
	scanf("%f" ,&s2.marks);	
	
	printf("Roll Number : %d \n" , s1.roll);
	printf("Name : %s \n" , s1.name);
	printf("Marks : %f \n" , s1.marks);
	
	printf("Roll Number : %d \n" , s2.roll);
	printf("Name : %s \n" , s2.name);
	printf("Marks : %f \n" , s2.marks);
	
	return 0;
}

