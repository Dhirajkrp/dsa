#include <stdio.h>
#include <stdlib.h>

struct student {
	int roll;
	char name[10];
	float marks;
};

typedef struct student Student;

void takeInput(Student s[10]  ,int index ){


	printf("Enter Roll Number : ");
	scanf("%%d" ,&s[index].roll);
	
	printf("Enter Name : ");
	scanf("%s",s[index].name);
	
	printf("Enter Marks : " );
	scanf("%f" ,&s[index].marks);
	index++;	
}

void printData(int count,Student s[10]){
	
	for(int i =0 ; i< count ;i++){
		
	printf("Roll Number : %d \n" , s[i].roll);
	printf("Name : %s \n" , s[i].name);
	printf("Marks : %f \n" , s[i].marks);
	}
}

int main(){
	
	Student s[10];
	int index = 0;
	
	for(int i = 0; i< 3 ;i++)
	{
		takeInput(s,index);	
	}
	
	for(int i = 0; i< 3 ;i++)
	{
		printData(3,s);	
	}
	
	return 0;
}

