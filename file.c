#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void createFile(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file) {
        printf("File created successfully!\n");
        fclose(file);
    } else {
        printf("Failed to create file!\n");
    }
}

void writeFile(const char *fileName, const char *data) {
    FILE *file = fopen(fileName, "w");
    if (file) {
        fputs(data, file);
        printf("Successfully written!\n");
        fclose(file);
    } else {
        printf("File not opened!\n");
    }
}

void deleteFile(const char *fileName) {
    if (remove(fileName) == 0) {
        printf("File deleted successfully!\n");
    } else {
        printf("Failed to delete file!\n");
    }
}

void copyFile(const char *source, const char *dest) {
    FILE *src = fopen(source, "r");
    FILE *dst = fopen(dest, "w");
    char ch;

    if (!src || !dst) {
        printf("Copy failed!\n");
        if (src) fclose(src);
        if (dst) fclose(dst);
        return;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }

    fclose(src);
    fclose(dst);
    printf("File copied successfully!\n");
}

void moveFile(const char *source, const char *dest) {
    if (rename(source, dest) == 0) {
        printf("File moved successfully!\n");
    } else {
        printf("Move failed!\n");
    }
}

int main() {
    int choice;
    char file1[100], file2[100], data[1024];

    while (1) {
        printf("\n1. Create File\n2. Write File\n3. Delete File\n4. Copy File\n5. Move File\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter file name to create: ");
                fgets(file1, sizeof(file1), stdin);
                file1[strcspn(file1, "\n")] = '\0';
                createFile(file1);
                break;
            case 2:
                printf("Enter file name to write to: ");
                fgets(file1, sizeof(file1), stdin);
                file1[strcspn(file1, "\n")] = '\0';

                printf("Enter text: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';

                writeFile(file1, data);
                break;
            case 3:
                printf("Enter file name to delete: ");
                fgets(file1, sizeof(file1), stdin);
                file1[strcspn(file1, "\n")] = '\0';
                deleteFile(file1);
                break;
            case 4:
                printf("Enter source file: ");
                fgets(file1, sizeof(file1), stdin);
                file1[strcspn(file1, "\n")] = '\0';

                printf("Enter destination file: ");
                fgets(file2, sizeof(file2), stdin);
                file2[strcspn(file2, "\n")] = '\0';

                copyFile(file1, file2);
                break;
            case 5:
                printf("Enter source file: ");
                fgets(file1, sizeof(file1), stdin);
                file1[strcspn(file1, "\n")] = '\0';

                printf("Enter destination file: ");
                fgets(file2, sizeof(file2), stdin);
                file2[strcspn(file2, "\n")] = '\0';

                moveFile(file1, file2);
                break;
            case 6:
                printf("Goodbye Sree🥺\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

}

