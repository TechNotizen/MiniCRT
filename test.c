#include "minicrt.h"

int main(int argc, char* argv[])
{
    // printf("Program started with argc=%d\n", argc);
    
    int i;
    FILE* fp;
    char** v = malloc(argc * sizeof(char*));
    printf("First malloc result: %d\n", (int)v);
    
    if (!v) {
        printf("Failed to allocate memory for argv array\n");
        return 1;
    }
    
    for (i = 0; i < argc; i++) {
        printf("Allocating for argv[%d]: %s\n", i, argv[i]);
        v[i] = malloc(strlen(argv[i]) + 1);
        printf("malloc for argv[%d] returned: %d\n", i, (int)v[i]);
        
        if (!v[i]) {
            printf("Failed to allocate memory for argv[%d]\n", i);
            return 1;
        }
        strcpy(v[i], argv[i]);
    }

    printf("All allocations successful, proceeding to file operations\n");
    
    fp = fopen("test.txt", "w");
    if (!fp) {
        printf("Failed to open test.txt for writing\n");
        return 1;
    }
    
    for (i = 0; i < argc; i++) {
        int len = strlen(v[i]);
        fwrite(&len, 1, sizeof(int), fp);
        fwrite(v[i], 1, len, fp);
    }
    fclose(fp);

    printf("File written successfully\n");
    
    fp = fopen("test.txt", "r");
    if (!fp) {
        printf("Failed to open test.txt for reading\n");
        return 1;
    }
    
    printf("Starting to read file\n");
    
    for (i = 0; i < argc; i++) {
        int len;
        char* buf;
        fread(&len, 1, sizeof(int), fp);
        buf = malloc(len + 1);
        fread(buf, 1, len, fp);
        buf[len] = '\0';
        printf("%d %s\n", len, buf);
        free(buf);
        free(v[i]);
    }
    fclose(fp);
    
    free(v);
    printf("Program completed successfully\n");
    return 0;
}