
#include <Windows.h>
#include <iostream>
#include <thread>
using namespace std;
const int n = 5;
const int m = 5;
int matr[m][n];
double d;
DWORD WINAPI generateDate() {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matr[i][j] = rand() % 21 - 10;
        }
    }

    return 0;
}
INT WINAPI Determinant()
{
    d = 1;
    for (int i = 0; i < n; i++) {
        d *= matr[i][i];
    }
    d = (d / 10 - d * 2) * 3 ;
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    HANDLE hThread1;
    HANDLE hThread2;
    HANDLE hThread3;
    HANDLE hThread4;
    HANDLE hThread5;
    HANDLE hThread6;
    DWORD IDThread;
    hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)generateDate, NULL, 0, &IDThread);
    hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)generateDate, NULL, 0, &IDThread);
    hThread3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)generateDate, NULL, 0, &IDThread);
    if (hThread1 == NULL) {
        return GetLastError();
    }
    if (hThread2 == NULL) {
        return GetLastError();
    }
    if (hThread3 == NULL) {
        return GetLastError();
    }
    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);
    WaitForSingleObject(hThread3, INFINITE);
    CloseHandle(hThread1);
    CloseHandle(hThread2);
    CloseHandle(hThread3);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matr[i][j] << " ";
        }
        cout << "\n" << endl;
    }
    hThread4 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Determinant, NULL, 0, &IDThread);
    hThread5 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Determinant, NULL, 0, &IDThread);
    hThread6 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Determinant, NULL, 0, &IDThread);
    if (hThread4 == NULL) {
        return GetLastError();
    }
    if (hThread5 == NULL) {
        return GetLastError();
    }
    if (hThread6 == NULL) {
        return GetLastError();
    }
    WaitForSingleObject(hThread4, INFINITE);
    WaitForSingleObject(hThread5, INFINITE);
    WaitForSingleObject(hThread6, INFINITE);
    CloseHandle(hThread4);
    CloseHandle(hThread5);
    CloseHandle(hThread6);
    cout << fixed << "\nMatrix determinant: " << d << "\n";
    
}

