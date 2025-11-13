#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("lotto.txt", "r");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt！\n");
        return 1;
    }

    // 跳過第一行 "========= lotto649 ========="
    char line[100];
    fgets(line, sizeof(line), fp);

    // 讀取五張樂透號碼
    int lotto[5][7];
    for (int i = 0; i < 5; i++) {
        fscanf(fp, "[%*d]: %d %d %d %d %d %d %d",
               &lotto[i][0], &lotto[i][1], &lotto[i][2],
               &lotto[i][3], &lotto[i][4], &lotto[i][5],
               &lotto[i][6]);
    }

    fclose(fp);

    // 使用者輸入三個中獎號碼
    int win[3];
    printf("請輸入中獎號碼三個：");
    scanf("%d %d %d", &win[0], &win[1], &win[2]);

    // 判斷是否中獎
    int is_win = 0;
    printf("輸入中獎號碼為：%02d %02d %02d\n", win[0], win[1], win[2]);
    printf("以下為中獎彩券：\n");

    for (int i = 0; i < 5; i++) {
        int match = 0;
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 3; k++) {
                if (lotto[i][j] == win[k]) {
                    match++;
                }
            }
        }
        if (match == 3) { // 剛好三個都中
            printf("第 %d 張中獎！號碼為：", i + 1);
            for (int j = 0; j < 7; j++) {
                printf("%02d ", lotto[i][j]);
            }
            printf("\n");
            is_win = 1;
        }
    }

    if (!is_win)
        printf("很可惜，沒有中獎！\n");

    return 0;
}
