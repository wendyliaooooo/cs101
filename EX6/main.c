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
    printf("employee salary = %f\n\n", emp.salary);
}

void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb");
    if (!fp) {
        perror("fopen write failed");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}

void emp_readfile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "rb");
    if (!fp) {
        perror("fopen read failed");
        return;
    }

    int i = 0;
    while (fread(&emp[i], sizeof(employee_t), 1, fp) == 1 && i < n) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
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

    // 寫入檔案
    emp_writefile(emp, 3);

    // 從檔案讀出，顯示 [index] id name
    emp_readfile(emp, 3);
    printf("\n");

    // 顯示完整員工資訊
    for (int i = 0; i < 3; i++) {
        emp_info(emp[i]);
    }

    return 0;
}
