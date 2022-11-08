#pragma once

#include "stdafx.h"
#include <fstream>
#include "MemManip.h"
using namespace std;

class ProcessManip : MemManip
	{
	public:
		ProcessManip(LPCSTR szProcessName, SIZE_T uBufferSize, LPCSTR szBufferFilePath);
		~ProcessManip();
		bool DumpProcess();
		LPCSTR Suffix() const override;

	private:
		LPCSTR szProcessName;
		HANDLE hProcess;
	};
