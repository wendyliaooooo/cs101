#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;

    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    // === 寫入階段 ===
    fp = fopen("a.bin", "wb");  // 在目前資料夾建立 a.bin
    if (fp == NULL) {
        printf("❌ 開啟檔案失敗！\n");
        return 1;
    }

    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);

    printf("✅ 成功建立 a.bin 並寫入內容！\n");

    // === 驗證檔案存在 ===
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("⚠️ 找不到 a.bin！\n");
        return 1;
    } else {
        printf("📁 a.bin 已存在於目前資料夾中。\n");
    }

    // === 讀取三個陣列 ===
    int ra[3];
    char rb[3];
    float rc[3];

    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);
    fclose(fp);

    // === 輸出結果 ===
    printf("\n=== 檔案內容 ===\n");
    for (int i = 0; i < 3; i++) printf("%d ", ra[i]);
    printf("\n");
    for (int i = 0; i < 3; i++) printf("%c ", rb[i]);
    printf("\n");
    for (int i = 0; i < 3; i++) printf("%.6f ", rc[i]);
    printf("\n");

    // === 額外：印出 a.bin 的 16 進位內容 ===
    printf("\n=== a.bin 的十六進位內容 ===\n");
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("❌ 無法再次開啟 a.bin！\n");
        return 1;
    }

    unsigned char byte;
    int count = 0;
    while (fread(&byte, 1, 1, fp) == 1) {
        printf("%02X ", byte); // 以兩位16進位顯示
        count++;
        if (count % 16 == 0) printf("\n");
    }
    fclose(fp);
    printf("\n");

    // === 提示使用者如何將檔案加入 Git ===
    printf("\n💡 若要把 a.bin 加到 GitHub，請在終端機輸入：\n");
    printf("   git add a.bin\n");
    printf("   git commit -m \"Add binary file\"\n");
    printf("   git push\n");

    return 0;
}
