#pragma once
/*
--- AOE AGE PATCH :: INJECTION-CODE ---
*/

/* INCLUDES */

// Windows-Funktionen
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// C-Standard-I/O-Funktionen
#include <cstdio>


/* MAKROS */

// Maximale Stringlänge.
// Hier die maximale Pfadlänge, da primär Pfade übergeben werden.
#define MAX_STRING_LENGTH MAX_PATH


/* FUNKTIONEN */

// Lädt die angegebene DLL-Funktion in den gegebenen Prozess und führt diese aus.
// Parameter:
// -> process: Der Prozess, bei dem die DLL-Injection durchgeführt werden soll.
// -> dllPath: Der Pfad zur DLL-Datei, die in den Prozess geladen werden soll.
// -> dllFunc: Die DLL-Funktion, die ausgeführt werden soll, sobald die DLL geladen wurde (Initialisierung).
void InjectDLL(HANDLE process, const char* dllPath, const char* dllFunc)
{
	// Pfad zur Inject-DLL
	DWORD addrInjectDLLPath = 0;
	char injectDLLPath[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(injectDLLPath, MAX_STRING_LENGTH + 1, MAX_STRING_LENGTH, "%s", dllPath);

	// Initialisierungsfunktion der Inject-DLL
	DWORD addrInjectDLLFunc = 0;
	char injectDLLFunc[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(injectDLLFunc, MAX_STRING_LENGTH + 1, MAX_STRING_LENGTH, "%s", dllFunc);

	// Titel der Fehlermeldungs-Fenster
	DWORD addrInjectErrorTitle = 0;
	char injectErrorTitle[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(injectErrorTitle, MAX_STRING_LENGTH + 1, MAX_STRING_LENGTH, "Error");
	
	// Fehlermeldung, wenn die Inject-DLL nicht geladen werden konnte
	DWORD addrInjectError1 = 0;
	char injectError1[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(injectError1, MAX_STRING_LENGTH + 1, MAX_STRING_LENGTH, "Couldn't load the inject DLL '%s'.\nThe program will exit now.", injectDLLPath);

	// Fehlermeldung, wenn die Inject-DLL-Initialisierungsfunktion nicht aufgerufen werden konnte
	DWORD addrInjectError2 = 0;
	char injectError2[MAX_STRING_LENGTH + 1] = { 0 };
	_snprintf_s(injectError2, MAX_STRING_LENGTH + 1, MAX_STRING_LENGTH, "Couldn't load the inject DLL init function '%s'.\nThe program will exit now.", injectDLLFunc);

	// Kernel32-DLL laden
	HMODULE kernel32 = LoadLibraryA("kernel32.dll");

	// Kernel32-Funktionen abrufen
	FARPROC procLoadLibraryA = GetProcAddress(kernel32, "LoadLibraryA");
	FARPROC procGetProcAddress = GetProcAddress(kernel32, "GetProcAddress");
	FARPROC procExitProcess = GetProcAddress(kernel32, "ExitProcess");
	FARPROC procExitThread = GetProcAddress(kernel32, "ExitThread");

	// User32-DLL laden
	// Age of Empires II lädt diese bereits von sich aus
	HMODULE user32 = LoadLibraryA("user32.dll");

	// User32-Funktionen abrufen
	FARPROC procMessageBoxA = GetProcAddress(user32, "MessageBoxA");
	
	// Start-Adresse der Ausführung im reservierten Speicher
	DWORD addrExecBegin = 0;

	// Lokal Speicher reservieren für den Patch und dann im Ziel-Prozess allokieren
	LPBYTE mem = (LPBYTE)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 1024);
	LPVOID memProcAddr = VirtualAllocEx(process, 0, 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	DWORD memProcAddrVal = PtrToUlong(memProcAddr);


	/*** DATENBEREICH ***/

	// Aktuelle Schreibeposition im reservierten Speicher
	DWORD memPos = 0;

	// Hilfsvariable
	DWORD tempSize = 0;
	
	// Platzhalter für Handle der injizierten DLL schreiben
	DWORD dllAddr = memProcAddrVal + memPos;
	tempSize = 0;
	memcpy(mem + memPos, &tempSize, 4);
	memPos += 4;

	// DLL-Name schreiben
	addrInjectDLLPath = memProcAddrVal + memPos;
	tempSize = (DWORD)strlen(injectDLLPath) + 1; // Null-Byte am Ende nicht vergessen
	memcpy(mem + memPos, injectDLLPath, tempSize);
	memPos += tempSize;

	// DLL-Funktions-Name schreiben (Initialisierungsfunktion)
	addrInjectDLLFunc = memProcAddrVal + memPos;
	tempSize = (DWORD)strlen(injectDLLFunc) + 1;
	memcpy(mem + memPos, injectDLLFunc, tempSize);
	memPos += tempSize;

	// Fehlertitel schreiben
	addrInjectErrorTitle = memProcAddrVal + memPos;
	tempSize = (DWORD)strlen(injectErrorTitle) + 1;
	memcpy(mem + memPos, injectErrorTitle, tempSize);
	memPos += tempSize;

	// Fehlermeldung 1 schreiben
	addrInjectError1 = memProcAddrVal + memPos;
	tempSize = (DWORD)strlen(injectError1) + 1;
	memcpy(mem + memPos, injectError1, tempSize);
	memPos += tempSize;

	// Fehlermeldung 2 schreiben
	addrInjectError2 = memProcAddrVal + memPos;
	tempSize = (DWORD)strlen(injectError2) + 1;
	memcpy(mem + memPos, injectError2, tempSize);
	memPos += tempSize;

	// Ausführungs-Startadresse speichern
	addrExecBegin = memProcAddrVal + memPos;


	/*** INJECT-DLL-LADE-CODE ***/
	// Nachfolgende Befehle sind handassembliert.
	// Die Befehle stehen einzeln, um das ganze wartbarer und übersichtlicher zu machen.

	// push addr
	// -> Inject-DLL-Name für LoadLibraryA auf den Stack legen
	mem[memPos++] = 0x68;
	memcpy(mem + memPos, &addrInjectDLLPath, 4);
	memPos += 4;

	// mov eax, addr
	// -> Adresse von LoadLibraryA in EAX legen
	mem[memPos++] = 0xB8;
	memcpy(mem + memPos, &procLoadLibraryA, 4);
	memPos += 4;

	// call eax
	// -> LoadLibraryA aufrufen
	mem[memPos++] = 0xFF;
	mem[memPos++] = 0xD0;

	// Fehlerprüfung => EAX ist bei Fehlern 0
	{
		// cmp eax, 0
		// -> Fehler aufgetreten?
		mem[memPos++] = 0x83;
		mem[memPos++] = 0xF8;
		mem[memPos++] = 0x00;

		// jnz eip+0x1E
		// -> Fehlercode überspringen (30 Bytes)
		mem[memPos++] = 0x75;
		mem[memPos++] = 0x1E;

		// push 0x10
		// -> Messagebox-Icon-ID (MB_ICONHAND) auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x10;

		// push addr
		// -> Adresse vom Fehlermeldungstitel auf den Stack legen
		mem[memPos++] = 0x68;
		memcpy(mem + memPos, &addrInjectErrorTitle, 4);
		memPos += 4;

		// push addr
		// -> Adresse vom Fehlertext auf den Stack legen
		mem[memPos++] = 0x68;
		memcpy(mem + memPos, &addrInjectError1, 4);
		memPos += 4;

		// push 0
		// -> Fensterhandle der MessageBox auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x00;

		// mov eax, addr
		// -> Adresse von MessageBoxA in EAX legen
		mem[memPos++] = 0xB8;
		memcpy(mem + memPos, &procMessageBoxA, 4);
		memPos += 4;

		// call eax
		// -> MessageBoxA aufrufen, Fehlermeldung anzeigen
		mem[memPos++] = 0xFF;
		mem[memPos++] = 0xD0;
		
		// push 0
		// -> Fehlercode für ExitProcess auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x00;

		// mov eax, addr
		// -> Adresse von ExitProcess in EAX legen
		mem[memPos++] = 0xB8;
		memcpy(mem + memPos, &procExitProcess, 4);
		memPos += 4;

		// call eax
		// -> ExitProcess aufrufen, Programmende
		mem[memPos++] = 0xFF;
		mem[memPos++] = 0xD0;
	}

	// mov [addr], eax
	// -> Inject-DLL-Adresse in Speicher ablegen
	mem[memPos++] = 0xA3;
	memcpy(mem + memPos, &dllAddr, 4);
	memPos += 4;

	// push addr
	// -> Adresse der Initialisierungsfunktion für GetProcAddress auf den Stack legen
	mem[memPos++] = 0x68;
	memcpy(mem + memPos, &addrInjectDLLFunc, 4);
	memPos += 4;

	// push eax
	// -> Adresse der Inject-DLL für GetProcAddress auf den Stack legen (ist noch in EAX)
	mem[memPos++] = 0x50;

	// mov eax, addr
	// -> Adresse von GetProcAddress in EAX legen
	mem[memPos++] = 0xB8;
	memcpy(mem + memPos, &procGetProcAddress, 4);
	memPos += 4;

	// call eax
	// -> GetProcAddress aufrufen
	mem[memPos++] = 0xFF;
	mem[memPos++] = 0xD0;

	// Fehlerprüfung => EAX ist bei Fehlern 0
	{
		// cmp eax, 0
		// -> Fehler aufgetreten?
		mem[memPos++] = 0x83;
		mem[memPos++] = 0xF8;
		mem[memPos++] = 0x00;

		// jnz eip+0x1C
		// -> Fehlercode überspringen (28 Bytes)
		mem[memPos++] = 0x75;
		mem[memPos++] = 0x1C;

		// push 0x10
		// -> Messagebox-Icon-ID (MB_ICONHAND) auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x10;

		// push addr
		// -> Adresse vom Fehlermeldungstitel auf den Stack legen
		mem[memPos++] = 0x68;
		memcpy(mem + memPos, &addrInjectErrorTitle, 4);
		memPos += 4;

		// push addr
		// -> Adresse vom Fehlertext auf den Stack legen
		mem[memPos++] = 0x68;
		memcpy(mem + memPos, &addrInjectError1, 4);
		memPos += 4;

		// push 0
		// -> Fensterhandle der MessageBox auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x00;

		// mov eax, addr
		// -> Adresse von MessageBoxA in EAX legen
		mem[memPos++] = 0xB8;
		memcpy(mem + memPos, &procMessageBoxA, 4);
		memPos += 4;

		// call eax
		// -> MessageBoxA aufrufen, Fehlermeldung anzeigen
		mem[memPos++] = 0xFF;
		mem[memPos++] = 0xD0;

		// push 0
		// -> Fehlercode für ExitProcess auf den Stack legen
		mem[memPos++] = 0x6A;
		mem[memPos++] = 0x00;

		// mov eax, addr
		// -> Adresse von ExitProcess in EAX legen
		mem[memPos++] = 0xB8;
		memcpy(mem + memPos, &procExitProcess, 4);
		memPos += 4;
	}

	// call eax
	// Je nach Wert in EAX (siehe Fehlerbehandlung):
	// -> ExitProcess aufrufen, Programmende
	// -> Initialisierungsfunktion aufrufen (Adresse ist in EAX, wenn kein Fehler aufgetreten ist)
	mem[memPos++] = 0xFF;
	mem[memPos++] = 0xD0;

	
	/*** LADE-CODE-ENDE ***/
	// Die Inject-DLL bleibt geladen, der Lade-Code-Thread wird beendet.

	// push 0
	// -> Fehlercode für ExitThread auf den Stack legen
	mem[memPos++] = 0x6A;
	mem[memPos++] = 0x00;

	// mov eax, addr
	// -> Adresse von ExitThread in EAX legen
	mem[memPos++] = 0xB8;
	memcpy(mem + memPos, &procExitThread, 4);
	memPos += 4;

	// call eax
	// -> ExitThread aufrufen, Threadende
	mem[memPos++] = 0xFF;
	mem[memPos++] = 0xD0;


	/*** INJECTION DES LADE-CODES ***/

	// Page-Protection ändern, um den Patch einschleusen zu können
	DWORD pageProtectOld = 0;
	VirtualProtectEx(process, memProcAddr, memPos, PAGE_EXECUTE_READWRITE, &pageProtectOld);

	// Patch in den Prozessspeicher schreiben
	DWORD writtenByteCount = 0;
	WriteProcessMemory(process, memProcAddr, mem, memPos, &writtenByteCount);

	// Page-Protection wiederherstellen
	VirtualProtectEx(process, memProcAddr, memPos, pageProtectOld, &pageProtectOld);

	// Instruction-Cache des Prozesses leeren, damit die eingeschleusten neuen Befehle auch ausgeführt werden
	FlushInstructionCache(process, memProcAddr, memPos);

	// Lokalen Patch-Speicher wieder freigeben
	HeapFree(GetProcessHeap(), 0, mem);

	// Lade-Code-Thread ausführen
	// Die Start-Adresse ist die Adresse, wo der Lade-Code beginnt (addrExecBegin), davor ist ein Datenbereich!
	HANDLE loaderThread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)ULongToPtr(addrExecBegin), 0, 0, NULL);
	
	// Warten, bis der Lade-Code-Thread beendet ist
	WaitForSingleObject(loaderThread, INFINITE);

	// Den im Prozess allokierten Speicher wieder freigeben
	VirtualFreeEx(process, memProcAddr, 0, MEM_RELEASE);
}