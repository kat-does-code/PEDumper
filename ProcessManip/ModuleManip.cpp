#include "stdafx.h"
#include "ModuleManip.h"
#include <list>

ModuleManip::ModuleManip(LPCSTR szModuleName, HANDLE hModule, SIZE_T uBufferSize, LPCSTR szBufferFilePath) : MemManip(uBufferSize, szBufferFilePath)
{

}

bool ModuleManip::DumpModule()
{
	return false;
}

FARPROC ModuleManip::FindModuleBaseAddress(LPCSTR szModuleName, LPCSTR szProcessName)
{
	auto hmod = GetModuleHandleA(szModuleName);
	auto hmod_addr = GetProcAddress(hmod, szProcessName);
	return hmod_addr;
}

std::list<MODULEENTRY32> ModuleManip::EnumerateModules(DWORD processId)
{
	MODULEENTRY32 me;
	std::list<MODULEENTRY32> modules;
	auto ss = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
	if (Module32First(ss, &me))
	{
		do
			modules.emplace_back(me);
		while (Module32Next(ss, &me));
	}
	return modules;
}

LPCSTR ModuleManip::Suffix() const
{
	return ".dll";
}
