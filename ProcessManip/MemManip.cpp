#include "stdafx.h"
#include "MemManip.h"

MemManip::MemManip(SIZE_T uBufferSize, LPCSTR szBufferFilePath)
{
	this->bufferSize = uBufferSize;
	this->bufferFilePath = szBufferFilePath;
	if (!OpenFile())
		throw new std::exception("Could not open file for writing.");
}

//Closes filestream and handle to process
MemManip::~MemManip()
{
	CloseFile();
}

bool MemManip::WriteMemToFile(LPSTR bArray, SIZE_T length)
{
	this->File.write(bArray, length);
	return CheckFileStatus();
}

bool MemManip::OpenFile()
{
	this->File.open(this->bufferFilePath, std::fstream::out);
	return CheckFileStatus();
}

bool MemManip::CloseFile()
{
	this->File.close();
	return CheckFileStatus();
}

bool MemManip::CheckFileStatus() const
{
	return this->File.good();
}

bool MemManip::DumpMemory(HANDLE hProcess, LPCVOID dwStart, DWORD dwLength)
{
	SIZE_T len = dwLength > 0 ? dwLength : this->bufferSize;
	LPSTR buffer = new char[len];
	if (buffer)
		if (ReadProcessMemory(hProcess, dwStart, buffer, len, nullptr))
			return WriteMemToFile(buffer, len);
	return false;
}

bool MemManip::GetProcessByName(LPCSTR processName, OUT LPPROCESSENTRY32 pe)
{
	HANDLE ss = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Process32First(ss, pe))
		while (strcmp(pe->szExeFile, processName) != 0 || Process32Next(ss, pe))
		{ }
	return strcmp(pe->szExeFile, processName) != 0;
}

int MemManip::GetProcessIdByName(LPCSTR processName)
{
	PROCESSENTRY32 pe;
	GetProcessByName(processName, &pe);
	return pe.th32ProcessID;
}

LPCSTR MemManip::Suffix() const
{
	return ".bin";
}
