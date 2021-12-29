﻿#include <Windows.h>
#include <iostream>
using namespace std;
#define FILE_PATH L"E:/os/Lab_9/OS09_01.txt"

BOOL printFileInfo(LPWSTR FileName);
string getFileName(wchar_t* filePath);
LPCWSTR getFileType(HANDLE file);
BOOL printFileTxt(LPWSTR FileName);

int main()
{
    setlocale(LC_CTYPE, "Rus");
    LPWSTR path = (LPWSTR)FILE_PATH;
    printFileInfo(path);
    printFileTxt(path);
}

BOOL printFileInfo(LPWSTR path) {


    HANDLE file = CreateFile(
        path,
        GENERIC_READ,
        NULL,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    SYSTEMTIME sysTime;
    BY_HANDLE_FILE_INFORMATION fi;
    BOOL fResult = GetFileInformationByHandle(file, &fi);
    if (fResult) {
        FileTimeToSystemTime(&fi.ftCreationTime, &sysTime);
        cout << "Creation time: " << sysTime.wDay << '.' << sysTime.wMonth << '.' << sysTime.wYear << " " << sysTime.wHour + 3 << '.' << sysTime.wMinute << '.' << sysTime.wSecond;
        FileTimeToSystemTime(&fi.ftLastWriteTime, &sysTime);
        cout << "\nLast update time: " << sysTime.wDay << '.' << sysTime.wMonth << '.' << sysTime.wYear << " " << sysTime.wHour + 3 << '.' << sysTime.wMinute << '.' << sysTime.wSecond;
        cout << "\nFile name: " << getFileName((wchar_t*)FILE_PATH);
        wcout << "\nFile type: " << getFileType(file);
        cout << "\nFile size: " << fi.nFileSizeHigh << '.' << fi.nFileSizeLow;
    }
    CloseHandle(file);
    return true;
}
BOOL printFileTxt(LPWSTR path) {
    HANDLE file = CreateFile(
        path,
        GENERIC_READ,
        NULL,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    char buf[1024];
    DWORD countBytes = NULL;
    ZeroMemory(buf, sizeof(buf));
    BOOL b = ReadFile(file, &buf, 200, &countBytes, NULL);
    if (!b) throw "write file failed";
    cout << "\n-- Read file " << countBytes << " byte succesfull:\n" << buf << '\n';
}
LPCWSTR getFileType(HANDLE file) {
    switch (GetFileType(file)) {
    case FILE_TYPE_UNKNOWN:
        return L"FILE_TYPE_UNKNOWN";
    case FILE_TYPE_DISK:
        return L"FILE_TYPE_DISK";
    case FILE_TYPE_CHAR:
        return L"FILE_TYPE_CHAR";
    case FILE_TYPE_PIPE:
        return L"FILE_TYPE_PIPE";
    case FILE_TYPE_REMOTE:
        return L"FILE_TYPE_REMOTE";
    default:
        return L"ERROR: WRITE FILE TYPE";
    }
}
string getFileName(wchar_t* filePath) {
    wstring ws(filePath);
    string filename(ws.begin(), ws.end());
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (string::npos != last_slash_idx)
    {
        filename.erase(0, last_slash_idx + 1);
    }
    return filename;
}

