#pragma once
class MemManip
	{
	protected:
		MemManip(SIZE_T uBufferSize, LPCSTR szBufferFilePath);
		~MemManip();

	public:
		bool DumpMemory(HANDLE hProcess, LPCVOID dwStart, DWORD dwLength);
		static bool GetProcessByName(LPCSTR processName, OUT LPPROCESSENTRY32 pe32);
		static int GetProcessIdByName(LPCSTR processName);
		virtual LPCSTR Suffix() const;

	protected:
		bool WriteMemToFile(LPSTR bArray, SIZE_T length);
		bool OpenFile();
		bool CloseFile();
		bool CheckFileStatus() const;

		LPCSTR targetName;
		LPCSTR bufferFilePath;
		SIZE_T bufferSize;
		std::fstream File;
	};
