#include "hwid.h"
#pragma warning (disable: 4474)
#pragma warning (disable: 4172)

std::string hwid::get_hardware_id(const std::string id)
{
	HANDLE h_token = nullptr;
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &h_token))
	{
		GetLastError();
		return nullptr;
	}
	DWORD dw_buffer_size = 0;
	if (!GetTokenInformation(h_token, TokenUser, nullptr, 0, &dw_buffer_size) && (GetLastError() !=
		ERROR_INSUFFICIENT_BUFFER))
	{
		GetLastError();
		CloseHandle(h_token);
		h_token = nullptr;
		return nullptr;
	}
	std::vector<BYTE> buffer;
	buffer.resize(dw_buffer_size);
	const auto p_token_user = reinterpret_cast<PTOKEN_USER>(&buffer[0]);
	if (!GetTokenInformation(h_token, TokenUser, p_token_user, dw_buffer_size, &dw_buffer_size))
	{
		GetLastError();

		CloseHandle(h_token);
		h_token = nullptr;

		return nullptr;
	}
	if (!IsValidSid(p_token_user->User.Sid))
	{
		CloseHandle(h_token);
		h_token = nullptr;

		return nullptr;
	}
	CloseHandle(h_token);
	h_token = nullptr;
	LPTSTR psz_sid = nullptr;
	if (!ConvertSidToStringSid(p_token_user->User.Sid, &psz_sid))
	{
		return nullptr;
	}
	std::string psz_sid_str(psz_sid);
	psz_sid_str += id;
	return std::string(psz_sid_str);
}

std::string hwid::GetHWID()
{
	//get a handle to the first physical drive
	HANDLE h = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (h == INVALID_HANDLE_VALUE) return {};

	//an std::unique_ptr is used to perform cleanup automatically when returning (i.e. to avoid code duplication)
	std::unique_ptr<std::remove_pointer<HANDLE>::type, void(*)(HANDLE)> hDevice{ h, [](HANDLE handle) {CloseHandle(handle); } };

	//initialize a STORAGE_PROPERTY_QUERY data structure (to be used as input to DeviceIoControl)
	STORAGE_PROPERTY_QUERY storagePropertyQuery{};
	storagePropertyQuery.PropertyId = StorageDeviceProperty;
	storagePropertyQuery.QueryType = PropertyStandardQuery;

	//initialize a STORAGE_DESCRIPTOR_HEADER data structure (to be used as output from DeviceIoControl)
	STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader{};

	//the next call to DeviceIoControl retrieves necessary size (in order to allocate a suitable buffer)
	//call DeviceIoControl and return an empty std::string on failure
	DWORD dwBytesReturned = 0;
	if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
		&storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &dwBytesReturned, NULL))
		return {};

	//allocate a suitable buffer
	const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
	std::unique_ptr<BYTE[]> pOutBuffer{ new BYTE[dwOutBufferSize]{} };
	//call DeviceIoControl with the allocated buffer
	if (!DeviceIoControl(hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
		pOutBuffer.get(), dwOutBufferSize, &dwBytesReturned, NULL))
		return {};

	//read and return the serial number out of the output buffer
	STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(pOutBuffer.get());
	const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
	if (dwSerialNumberOffset == 0) return {};
	const char* serialNumber = reinterpret_cast<const char*>(pOutBuffer.get() + dwSerialNumberOffset);
	return serialNumber;
}

int WindowX()//Get the window's X resolution
{
	RECT desktop_rect_;// RECT struct {LONG left; LONG right; LONG top; LONG bottom;} || needed for the GetWindowRect()
	HWND desktop_ = GetDesktopWindow();//Handle to the desktop
	GetWindowRect(desktop_, &desktop_rect_);// Gets the RECT struct's four members ( left, right, top, bottom) ||Miért referencia?
	return desktop_rect_.right;//Return with the window's X resolution
}