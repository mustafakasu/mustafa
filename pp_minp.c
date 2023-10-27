/*
STUDENT MANAGMENT SYSTEM 
CREATED BY : MUSTAFA KASUBHAI WALA 
ROLL NO. 0801CS221093.
© COPYRIGHT 2023 BY MUSTAFA KASUBHAI WALA . THESE MATERIAL CANNOT BE
DUBLICATE FOR ANY PROFIT DRIVEN ENTERPRISE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 60
#define N 100
struct Grades {
    char subjects[size];
    char grade[size];
};

struct studentinfo {
    int year_admission;
    char enrollment_no[size];
    char name[size];
    char lastname[size];
    int phone_no;
    int age;
    char City[size];
    char Gender[size];
    char address[size];
    char email_id[size];
    char branch[size];
    int fees;
    struct Grades gradesshow[N];
    int num_subjects;
};

void add_student_details(struct studentinfo *student, int *serial_no);
void display_student_details(struct studentinfo *student, int *serial_no);
int search_the_student(struct studentinfo *student, int *serial_no, char *enrollment);
void delete_the_student_details(struct studentinfo *student, int *serial_no, char *enrollment);
void modify_the_student_details(struct studentinfo *student, int *serial_no, char *enrollment);
void Student_grades(struct studentinfo *student, int *serial_no, char *enrollment);
void Student_grades_show(struct studentinfo *student, int *serial_no, char *enrollment);

int main() {
    struct studentinfo *student = malloc(N * sizeof(struct studentinfo));

    if (student == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int serial_no = 0;
    int choice;
    char enrollment_no[size];

    while (1) {
        printf("Welcome to Student Management System:\n");
        printf("1. Add Student\n");
        printf("2. Display Student Details\n");
        printf("3. Search Student\n");
        printf("4. Delete Student Registration\n");
        printf("5. Modify Student Details\n");
        printf("6. Add Grades\n");
        printf("7. Display Grades\n");
        printf("8. Exit\n");
        printf("Enter your number ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            // CALL THE FUNCTIO WHICH TAKES DETAILS OF THE STUUDENT .
                add_student_details(&student[serial_no], &serial_no);
                break;
            case 2:
            // CALL THE FUNCTION WHICH DISPLAY THE DETAILS OF THE STUDENT .
                display_student_details(student, &serial_no);
                break;
            case 3:
            // CALL THE FUNCTION WHICH SEARCH THE STUDENT EXSIST OR NOT .
                printf("Enter the student Enrollment number for search:\n");
                scanf("%s", enrollment_no);
                int index = search_the_student(student, &serial_no, enrollment_no);
                if (index != -1) {
                    printf("****---------------------------------****\n");
                      printf("Enrollment No:%s\n", student[index].enrollment_no);
                      printf("Year of admission: %d\n", student[index].year_admission);
                      printf("Name: %s %s\n", student[index].name, student[index].lastname);
                      printf("Gender:%s",student[index].Gender);
                      printf("Branch: %s\n", student[index].branch);
                      printf("Address :%s\n",student[index].address);
                      printf("city: %s",student[index].City);
                      printf("Age of the student: %d\n", student[index].age);
                      printf("Student phone no is: %d\n", student[index].phone_no);
                      printf("Email Id:%s\n",student[index].email_id);
                      printf("Fees: %d\n", student[index].fees);
                      printf("****-----------------------****\n");
                } else {
                    printf("Student details not found.\n");
                }
                break;
            case 4:
            // CALL THE FUNCTION TO DELETE THE STUDENT DETAILS AND FREE THE SPACE.
                printf("Enter the student Enrollment number whose registration is cancelled: ");
                scanf("%s", enrollment_no);
                delete_the_student_details(student, &serial_no, enrollment_no);
                break;
            case 5:
            // CALL THE FUNCTION TO MODIFY THE DETAILS OF THE STUDENT 
                printf("Enter the Enrollment Number of the student to modify details:\n");
                scanf("%s", enrollment_no);
                modify_the_student_details(student, &serial_no, enrollment_no);
                break;
                
            case 6:
            // CALL THE FUNCTION FOR GRADING 
               printf("Enter the Enrollment number of student for grades:\n");
                scanf("%s", enrollment_no);
                Student_grades(student, &serial_no, enrollment_no);
                break;
            case 7:
            // CALL THE FUNCTION TO DISPLAY THE GRADES OF THE STUDENT 
                printf("Enter the Enrollment number of student to display grades:\n");
                scanf("%s", enrollment_no);
                Student_grades_show(student, &serial_no, enrollment_no);
                break;
            case 8:
            // IN THESE CASE WHILE TERMINATE .
                free(student);
                printf("Thank you for using Student Management System.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void add_student_details(struct studentinfo *student, int *serial_no) {
    printf("Enter the data for student %d:\n", (*serial_no) + 1);
    printf("*********************************\n");
    printf("Enter the year of admission: ");
    scanf("%d", &student->year_admission);
    printf("Enter the Enrollment no of student: ");
    scanf("%s", student->enrollment_no);
    printf("Enter the student name: ");
    scanf("%s", student->name);
    printf("Enter the surname: ");
    scanf("%s", student->lastname);
    printf("Enter the Gender :");
    scanf("%s",student->Gender);
    printf("Enter the branch: ");
    scanf("%s", student->branch);
    printf("Enter the phone number: ");
    scanf("%d",&student->phone_no);
    printf("Enter the address:");
    scanf("%s",student->address);
    printf("Enter the city :");
    scanf("%s",student->City );
    printf("Enter the age of the student: ");
    scanf("%d", &student->age);
    printf("Enter the Email Id: ");
    scanf("%s",student->email_id);
    printf("Enter the Fees: ");
    scanf("%d", &student->fees);
    printf("Detail of Student is Saved :\n");
    printf("\n******************************\n");

    (*serial_no)++; 
}

void display_student_details(struct studentinfo *student, int *serial_no) {
   printf("Details of students are as follows:\n");
    for (int i = 0; i < *serial_no; i++)
    {
        printf("______________________________________\n");
        printf("Enrollment No:%s\n", student[i].enrollment_no);
        printf("Year of admission: %d\n", student[i].year_admission);
        printf("Name: %s %s\n", student[i].name, student[i].lastname);
        printf("Gender:%s",student[i].Gender);
        printf("Branch: %s\n", student[i].branch);
        printf("Address :%s\n",student[i].address);
        printf("city: %s",student[i].City);
        printf("Age of the student: %d\n", student[i].age);
        printf("Student phone no is: %d\n", student[i].phone_no);
        printf("Email Id:%s\n",student[i].email_id);
        printf("Fees: %d\n", student[i].fees);
        printf("________________________________________\n");
    }
}

int search_the_student(struct studentinfo *student, int *serial_no, char *enrollment) {
       for (int i = 0; i < *serial_no; i++)
    {
        if (strcmp(student[i].enrollment_no, enrollment) == 0)
        {
            return i;
        }
    }
    return -1;
}

void delete_the_student_details(struct studentinfo *student, int *serial_no, char *enrollment) {
    int search = search_the_student(student, serial_no, enrollment);
    if (search != -1)
    {
        for (int i = search; i < *serial_no - 1; i++)
        {
            student[i] = student[i + 1];
        }
        (*serial_no)--;
        printf("Student with enrollment number: %s has been deleted.\n", enrollment);
    }
    else
    {
        printf("Student with enrollment number: %s is not found.\n", enrollment);
    }
}

void modify_the_student_details(struct studentinfo *student, int *serial_no, char *enrollment) {
   int index = search_the_student(student, serial_no, enrollment);
    if (index != -1)
    {
        printf("Enter the modified details for student with Enrollment Number %s:\n", enrollment);
        printf("Enter the new Year of Admission: ");
        scanf("%d", &student[index].year_admission);
        printf("Enter the new Name and Last Name of the student: ");
        scanf("%s %s", student[index].name, student[index].lastname);
        printf("Enter the new Phone Number: ");
        scanf("%d", &student[index].phone_no);
        printf("Enter the new Age of Student: ");
        scanf("%d", &student[index].age);
        printf("Enter the new Email Address: ");
        scanf("%s", student[index].email_id);
        printf("Enter the new City: ");
        scanf("%s", student[index].City);
        printf("Student details updated successfully.\n");
    }
    else
    {
        printf("Student with Enrollment Number %s not found.\n", enrollment);
    }  
}

void Student_grades(struct studentinfo *student, int *serial_no, char *enrollment) {
    int index = search_the_student(student, serial_no, enrollment);
    if (index != -1) {
        printf("Enter the number of subjects:\n");
        scanf("%d", &student[index].num_subjects);
        for (int i = 0; i < student[index].num_subjects; i++) {
            printf("Enter subject %d: ", i + 1);
            scanf("%s", student[index].gradesshow[i].subjects);
            printf("Enter the grade for %s: ", student[index].gradesshow[i].subjects);
            scanf("%s", student[index].gradesshow[i].grade);
        }
        printf("Grades for student with Enrollment No. %s successfully added.\n", enrollment);
    } else {
        printf("Student with Enrollment %s not found.\n", enrollment);
    }
}
void Student_grades_show(struct studentinfo *student, int *serial_no, char *enrollment) {
    int index = search_the_student(student, serial_no, enrollment);
    if (index != -1) {
        printf("Grades for student with Enrollment No. %s:\n", student[index].enrollment_no);
        for (int i = 0; i < student[index].num_subjects; i++) {
            printf("Subject: %s, Grade: %s\n", student[index].gradesshow[i].subjects, student[index].gradesshow[i].grade);
        }
    } else {
        printf("Enrollment %s not found.\n", enrollment);
    }
}
