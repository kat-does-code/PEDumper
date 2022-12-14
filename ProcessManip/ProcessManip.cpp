// ProcessManip.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ProcessManip.h"
#include <malloc.h>
#include "ModuleManip.h"


bool ProcessManip::DumpProcess()
{
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQueryEx(this->hProcess, ModuleManip::FindModuleBaseAddress(this->szProcessName, this->szProcessName), &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	return DumpMemory(this->hProcess, mbi.BaseAddress, mbi.RegionSize);
}

LPCSTR ProcessManip::Suffix() const
{
	return ".exe";
}

ProcessManip::ProcessManip(LPCSTR szProcessName, SIZE_T uBufferSize, LPCSTR szBufferFilePath) 
	: MemManip(uBufferSize, szBufferFilePath)
{
	this->szProcessName = szProcessName;
	this->hProcess = OpenProcess(PROCESS_VM_READ, true, GetProcessIdByName(szProcessName));
	this->bufferSize = uBufferSize;
	this->bufferFilePath = szBufferFilePath;
	if (!OpenFile())
		throw exception("Could not open file for writing.");
}

ProcessManip::~ProcessManip()
{
	CloseHandle(this->hProcess);
}
