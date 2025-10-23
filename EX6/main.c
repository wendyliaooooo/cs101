#include <stdio.h>
#include <string.h>

typedef struct employee {
    int id;
    char name[12];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %.2f\n\n", emp.salary);
}

int emp_average(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    if (!fp) {
        perror("fopen failed");
        return;
    }
    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
}

void emp_readfile() {
    FILE* fp = fopen("employee.bin", "rb");
    if (!fp) {
        perror("fopen failed");
        return;
    }
    employee_t emp;
    int i = 0;
    while (fread(&emp, sizeof(employee_t), 1, fp)) {
        printf("[%d] %d %s %.2f\n", i, emp.id, emp.name, emp.salary);
        i++;
    }
    fclose(fp);
}

int main() {
    employee_t emp[3];

    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");

    printf("Size of employee_t = %zu bytes\n", sizeof(employee_t));

    for (int i = 0; i < 3; i++) emp_info(emp[i]);

    printf("Average age = %d\n", emp_average(emp, 3));

    emp_writefile(emp, 3);
    printf("\n=== From file ===\n");
    emp_readfile();

    return 0;
}
