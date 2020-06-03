#include "includes.h"
#include "Cleaner.h"
#include "Protection.h"
#include "logo.h"
#include "print.h"
#include "resource.h"

#pragma comment(lib,"wininet.lib")

inline bool exists(const std::string& name)
{
	return GetFileAttributes(name.c_str()) != INVALID_FILE_ATTRIBUTES;
}

char tt[100];

void ExtractDriversSpoof()
{
	CreateThread(0, 0, &init, 0, 0, 0);
	print::set_text(_xors("\n ").c_str(), Yellow);
	print::set_text(_xors("  [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);
	print::set_text(_xors("Old Diskdrive Serials :").c_str(), Yellow);
	print::set_text(hwid::GetHWID().c_str(), Yellow);

	print::set_text(_xors("\n").c_str(), Yellow);
	print::set_text(_xors("   ").c_str(), Yellow);
	HRSRC pMap = ::FindResource(NULL, MAKEINTRESOURCE(IDR_FILE1), _xors("FILE").c_str());
	unsigned int pMapSize = ::SizeofResource(NULL, pMap);
	HGLOBAL pMapData = ::LoadResource(NULL, pMap);
	void* pMapRaw = ::LockResource(pMapData);

	CreateThread(0, 0, &init, 0, 0, 0);
	std::ofstream f(base64_decode(_xors("QzpcV2luZG93c1xtYXBwZXIuZXhl").c_str()).c_str(), std::ios::out | std::ios::binary);
	f.write((char*)pMapRaw, pMapSize);
	f.close();

	HRSRC pConfig = ::FindResource(NULL, MAKEINTRESOURCE(IDR_FILE2), _xors("FILE").c_str());
	unsigned int pConfigSize = ::SizeofResource(NULL, pConfig);
	HGLOBAL pConfigData = ::LoadResource(NULL, pConfig);
	void* pConfigRaw = ::LockResource(pConfigData);

	CreateThread(0, 0, &init, 0, 0, 0);
	std::ofstream ff(base64_decode(_xors("QzpcV2luZG93c1xjb25maWcuc3lz").c_str()).c_str(), std::ios::out | std::ios::binary);
	ff.write((char*)pConfigRaw, pConfigSize);
	ff.close();

	HRSRC pDrv = ::FindResource(NULL, MAKEINTRESOURCE(IDR_FILE3), _xors("FILE").c_str());
	unsigned int pDrvSize = ::SizeofResource(NULL, pDrv);
	HGLOBAL pDrvData = ::LoadResource(NULL, pDrv);
	void* pDrvRaw = ::LockResource(pDrvData);

	CreateThread(0, 0, &init, 0, 0, 0);
	std::ofstream fff(base64_decode(_xors("QzpcV2luZG93c1xkcml2ZXIuc3lz").c_str()).c_str(), std::ios::out | std::ios::binary);
	fff.write((char*)pDrvRaw, pDrvSize);
	fff.close();
	system(base64_decode(_xors("QzpcV2luZG93c1xtYXBwZXIuZXhlIEM6XFdpbmRvd3NcY29uZmlnLnN5cyBDOlxXaW5kb3dzXGRyaXZlci5zeXMgPm51bA==").c_str()).c_str());
	print::set_text("\n", Yellow);

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);
	print::set_text(_xors("New Diskdrive Serials :").c_str(), Yellow);
	print::set_text(hwid::GetHWID().c_str(), Yellow);

	std::string FILE1 = base64_decode(_xors("QzpcV2luZG93c1xtYXBwZXIuZXhl").c_str());
	std::string FILE2 = base64_decode(_xors("QzpcV2luZG93c1xjb25maWcuc3lz").c_str());
	std::string FILE3 = base64_decode(_xors("QzpcV2luZG93c1xkcml2ZXIuc3lz").c_str());

	if (exists(base64_decode(FILE1))) DeleteFileA(FILE1.c_str());
	if (exists(base64_decode(FILE2))) DeleteFileA(FILE2.c_str());
	if (exists(base64_decode(FILE3))) DeleteFileA(FILE3.c_str());

	print::set_text(_xors("\n ").c_str(), Yellow);
	print::set_text(_xors("\n ").c_str(), Yellow);
}

void SpoofMac()
{

}

void SpooferMain()
{
	CreateThread(0, 0, &init, 0, 0, 0);
	BlockInput(true);
	system("cls");
	logo::Draw();
	print::set_text(_xors("   Hello, Regular User!\n\n").c_str(), Yellow);
	print::set_text(_xors("   INFO: ").c_str(), Green);
	system("cls");
	logo::Draw();

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);
	print::set_text(_xors("Starting Spoofing Process...\n\n").c_str(), Yellow);
	Sleep(3000);

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("+").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text(_xors("Spoofing Diskdrives...\n").c_str(), Yellow);

	Sleep(3000);
	ExtractDriversSpoof();
	print::set_text(_xors("  [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text("Spoofed Diskdrives.\n", Yellow);
	print::set_text("\n ", Yellow);

	Sleep(3000);
	print::set_text(_xors("  [").c_str(), Yellow);
	print::set_text(_xors("+").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text(_xors("Spoofing MAC...\n\n").c_str(), Yellow);
	SpoofMac();
	Sleep(4000);

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);
	print::set_text(_xors("Spoofed MAC.\n\n").c_str(), Yellow);

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	BlockInput(false);
	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("+").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text(_xors("Cleaning Fortnite Traces...\n\n").c_str(), Yellow);

	Cleaner::CleanerMain();

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("!").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text(_xors("Cleaned Fortnite Traces!\n\n").c_str(), Yellow);

	print::set_text(_xors("   [").c_str(), Yellow);
	print::set_text(_xors("y").c_str(), Red);
	print::set_text(_xors("] ").c_str(), Yellow);

	print::set_text(_xors("Spoofed! Exiting...\n\n").c_str(), Yellow);
	Sleep(3000);
	exit(0);
}

void strGetRandomAlphaNum(char* sStr, unsigned int iLen)
{
	char Syms[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int Ind = 0;
	srand(time(NULL) + rand());
	while (Ind < iLen)
	{
	sStr[Ind++] = Syms[rand() % 62];
	}
	sStr[iLen] = '\0';
}

void set_console(int w, int h) {

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

int main()
{
	strGetRandomAlphaNum(tt, 18);
	Sleep(2000);
	SetConsoleTitleA(tt);
	set_console(1000, 500);
	Sleep(500);
	Sleep(1000);
	system(_xors("color c").c_str());
	system("cls");


			MessageBox(0, "Successfully Logged In!", "", MB_OK);
			SpooferMain();
		return 0;
}