/*
--- AOE AGE PATCH :: LOADER ---
*/

/* INCLUDES */

// Windows-Funktionen
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// C-Standard-input/Output-Funktionen
#include <cstdio>

// __argc, __argv-Variablen für das Befehlszeilen-Parsing
#include <cstdlib>

// C++-String-Funktionen
#include <string>

// Injection-Funktionen
#include "injection.h"


/* FUNKTIONEN */

// Programm-Einstiegsfunktion.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
	// Pfad zum Arbeitsverzeichnis ist der aktuelle Ordner
	// Der String hat MAX_STRING_LENGTH-Länge, um bei den Ladefunktionen einfacher kopiert werden zu können
	char workdir[MAX_STRING_LENGTH + 1] = { 0 };
	GetCurrentDirectory(MAX_STRING_LENGTH, workdir);

	// Pfad zur EXE
	char exepath[MAX_STRING_LENGTH + 1] = { 0 };

	// Parameter für die EXE
	std::string cmdLine("age2_x1.exe game=X2AddOn_1 nostartup");
	if(__argc > 1)
		cmdLine = std::string("");
	for(int i = 1; i < __argc; ++i)
	{
		// Parameter-String zusammensetzen
		cmdLine.append(__argv[i]).append(" ");
	}

	// EXE-Parameter mit Pfad verknüpfen
	// nostartup: Keine Videos am Anfang
	_snprintf_s(exepath, MAX_STRING_LENGTH, MAX_STRING_LENGTH, "%s\\%s", workdir, cmdLine);

	// Pfad zur DLL
	char dllpath[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(dllpath, MAX_STRING_LENGTH, MAX_STRING_LENGTH, "AgePatch.dll");
	
	// Prozessstart-Variablen
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi = { 0 };

	// Größe der STARTUPINFO-Struktur übergeben
	si.cb = sizeof(STARTUPINFO);

	// EXE starten, aber noch nicht ausführen (suspend)
	int res = CreateProcess(NULL, exepath, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, workdir, &si, &pi);
	if(res == 0)
	{
		// Mist
		MessageBoxA(0, "Couldn't run specified executable!", "Error", MB_ICONERROR);

		// Abbruch
		return -1;
	}

	// DLL-Injection durchführen
	InjectDLL(pi.hProcess, dllpath, "Init");
	
	// Prozess-Ausführung beginnen
	ResumeThread(pi.hThread);

	// Alles gut
	return 0;
}


