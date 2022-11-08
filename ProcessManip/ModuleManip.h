#pragma once
#include "MemManip.h"
#include <list>
class ModuleManip : MemManip
{
public:
	ModuleManip(LPCSTR szModuleName, HANDLE hModule, SIZE_T uBufferSize, LPCSTR szBufferFilePath);
	bool DumpModule();
	static FARPROC FindModuleBaseAddress(LPCSTR szModuleName, LPCSTR szProcessName);
	static std::list<MODULEENTRY32> EnumerateModules(DWORD processId);
	LPCSTR Suffix() const override;
private:

};
