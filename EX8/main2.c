#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_SET 5

int num_in_numset(int num, int numset[], int Len) {
    for (int i = 0; i < Len; i++) {
        if (num == numset[i]) {
            return 1;
        }
    }
    return 0;
}

void print_lotto_row(FILE *tmpfp, int n) {
    int numset[MAX_LOTTO_NUM] = {0};

    fprintf(tmpfp, "[%d]: ", n);

    // 產生前 6 個號碼（1~69）
    for (int i = 0; i < MAX_LOTTO_NUM - 1;) {
        int num = (rand() % 69) + 1;
        if (!num_in_numset(num, numset, MAX_LOTTO_NUM - 1)) {
            numset[i] = num;
            i++;
        }
    }

    // 第 7 個特別號（1~10）
    for (int i = 0; i < 1;) {
        int num = (rand() % 10) + 1;
        if (!num_in_numset(num, numset, MAX_LOTTO_NUM - 1)) {
            numset[MAX_LOTTO_NUM - 1] = num;
            i++;
        }
    }

    // 排序前 6 個號碼
    for (int i = 0; i < MAX_LOTTO_NUM - 2; ++i) {
        for (int j = i + 1; j < MAX_LOTTO_NUM - 1; ++j) {
            if (numset[j] < numset[i]) {
                int temp = numset[i];
                numset[i] = numset[j];
                numset[j] = temp;
            }
        }
    }

    // 印出結果
    for (int i = 0; i < MAX_LOTTO_NUM; i++) {
        fprintf(tmpfp, "%02d ", numset[i]);
    }
    fprintf(tmpfp, "\n");
}

void print_lottofile(int num_set, int counter, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand((unsigned) time(NULL));

    FILE *tmpfp = fopen(lotto_file, "w+");
    fprintf(tmpfp, "========= lotto649 ==========\n");
    fprintf(tmpfp, "========+ NO.%05d +========\n", counter);
    fprintf(tmpfp, "= %s", ctime(&curtime));

    for (int i = 0; i < MAX_LOTTO_SET; i++) {
        if (i < num_set) {
            print_lotto_row(tmpfp, i + 1);
        } else {
            fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i + 1);
        }
    }

    fprintf(tmpfp, "========= csie@CGU ==========\n");
    fclose(tmpfp);
}

void init_file() {
    int write_array[1] = {0};
    FILE *fp = fopen(COUNTER_FILE, "wb");
    fwrite(write_array, sizeof(int), 1, fp);
    fclose(fp);
}

void do_lotto_main(int counter) {
    char lotto_file[32];
    int num_set = 0;

    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩: ");
    scanf("%d", &num_set);

    print_lottofile(num_set, counter, lotto_file);
    printf("已將您購買的 %d 組樂透組合輸出至 %s\n", num_set, lotto_file);
}

int main(void) {
    int counter = 1;
    do_lotto_main(counter);
    return 0;
}

