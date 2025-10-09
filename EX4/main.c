#include <stdio.h>

int main(void) {
    FILE *fp;

    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    // === 寫入階段 ===
    fp = fopen("a.bin", "wb");  // 以 binary 寫入模式開啟
    if (fp == NULL) {
        printf("檔案開啟失敗\n");
        return 1;
    }

    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);

    fclose(fp);

    // === 讀取階段 ===
    int ra[3];
    char rb[3];
    float rc[3];

    fp = fopen("a.bin", "rb");  // 以 binary 讀取模式開啟
    if (fp == NULL) {
        printf("檔案讀取失敗\n");
        return 1;
    }

    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);

    fclose(fp);

    // === 輸出結果 ===
    for (int i = 0; i < 3; i++)
        printf("%d ", ra[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        printf("%c ", rb[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        printf("%.6f ", rc[i]);
    printf("\n");

    return 0;
}
