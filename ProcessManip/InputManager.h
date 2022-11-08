#pragma once

class InputManager
{
public:
	void ReadInput();

private:
	void PrintHelp();
	void PrintProcesses();
	void PrintModules(LPCSTR procName);
	void DumpProcess(LPCSTR procName);
	void DumpModule(LPCSTR procName, LPCSTR modName);
	void DumpRegion(LPCSTR procName, DWORD dwStart, SIZE_T dwLength);


	bool iscmd(PCHAR predefined_cmd);
	PCHAR help = "help";
	PCHAR list_procs = "list processes";
	PCHAR list_mods = "list modules";
	PCHAR dump_proc = "dump process";
	PCHAR dump_mod = "dump modules";
	PCHAR dump_reg = "dump region";
};
