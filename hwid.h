#pragma once
#include <Windows.h>
#include <intrin.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sddl.h>
#include <string>
#include <iostream>
#include <TlHelp32.h>
#pragma comment(lib, "wininet.lib")
class hwid
{
public:
	static std::string get_hardware_id(const std::string id);
	static std::string GetHWID();
};
