#pragma once
#include "t_api.h"
#include "xorstr.hpp"
#include <Windows.h>
#include <TlHelp32.h>

#pragma comment(lib, "ntdll.lib")

using namespace std;

string replaceAll(string subject, const string& search,
    const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

static const char consoleNameAlphanum[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int consoleNameLength = sizeof(consoleNameAlphanum) - 1;

extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);

void bsod()
{
    BOOLEAN bl;
    ULONG Response;
    RtlAdjustPrivilege(19, TRUE, FALSE, &bl); // Enable SeShutdownPrivilege
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
}

void DebuggerPresent()
{
    if (IsDebuggerPresent())
    {
        bsod();
    }
}

DWORD_PTR FindProcessId2(const std::string& processName)
{
    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);

    HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (processesSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    Process32First(processesSnapshot, &processInfo);
    if (!processName.compare(processInfo.szExeFile))
    {
        CloseHandle(processesSnapshot);
        return processInfo.th32ProcessID;
    }

    while (Process32Next(processesSnapshot, &processInfo))
    {
        if (!processName.compare(processInfo.szExeFile))
        {
            CloseHandle(processesSnapshot);
            return processInfo.th32ProcessID;
        }
    }

    CloseHandle(processesSnapshot);
    return 0;
}

void killProcessByName(const char* filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

void ScanProccessListForBlacklistedProcess()
{
    if (FindProcessId2(_xors("http.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("https.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("HttpRequester.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("HTTP Toolkit.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("Toolkit.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("memory.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("memoryview.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("viewmemory.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("SmartSniff.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("NetworkMiner.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("SwagBellaSetup.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("SwagBella.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("KsDumper.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("KsDump.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("view.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("outbuilt.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("ida.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("de3dot.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("KsDumperClient.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("outbuilt.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("bypass.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("Bypass.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("BYPASS.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("Outbuilt.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("OUTBUILT.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("ollydbg.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ProcessHacker.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("tcpview.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("autoruns.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("autorunsc.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("filemon.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("procmon.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("regmon.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("procexp.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("idaq.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("idaq64.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ImmunityDebugger.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Wireshark.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("dumpcap.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("HookExplorer.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ImportREC.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("PETools.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("LordPE.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("dumpcap.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("SysInspector.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("proc_analyzer.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("sysAnalyzer.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("sniff_hit.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("windbg.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("joeboxcontrol.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Fiddler.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("joeboxserver.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ida64.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ida.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Vmtoolsd.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Vmwaretrat.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Vmwareuser.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("Vmacthlp.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("vboxservice.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("vboxtray.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("ReClass.NET.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("x64dbg.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("OLLYDBG.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("HTTPDebuggerSvc.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("HTTPDebuggerUI.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("FolderChangesView.exe")) != 0)
    {
        bsod();
    }
    else if (FindProcessId2(_xors("FileSystemWatcher.exe")) != 0)
    {
        bsod();
    }
    if (FindProcessId2(_xors("ollydbg.exe")) != 0)
    {
        bsod();
    }
}

void ScanBlacklistedWindows()
{
    if (FindWindow(NULL, _xors("The Wireshark Network Analyzer").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("Progress Telerik Fiddler Web Debugger").c_str()))
    {

        bsod();
    }

    if (FindWindow(NULL, _xors("Fiddler").c_str()))
    {
        bsod();
    }


    if (FindWindow(NULL, _xors("HTTP Debugger").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("x64dbg").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("Process Monitor").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("http").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("Http").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("Bypass").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("ZeraX").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("GayCrack").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("BandCrack").c_str()))
    {
        bsod();
    }

    if (FindWindow(NULL, _xors("NIGGER CRACK").c_str()))
    {
        bsod();
    }
}



DWORD init(LPVOID) {
    while (1)
    {
        DebuggerPresent();
        ScanBlacklistedWindows();
        ScanProccessListForBlacklistedProcess();
    }
}