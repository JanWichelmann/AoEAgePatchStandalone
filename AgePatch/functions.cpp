/*
--- AOE AGE PATCH :: CODECAVE-FUNKTIONEN :: IMPLEMENTIERUNG ---
*/

/* INCLUDES */

// Definitionsheader
#include "functions.h"


/* FUNKTIONEN */

void CopyBytesToAddr(DWORD destAddr, void *data, size_t byteCount)
{
	// Page-Protection ändern, damit geschrieben werden kann
	DWORD pageProtectOld = 0;
	VirtualProtect((void *)destAddr, byteCount, PAGE_EXECUTE_READWRITE, &pageProtectOld);

	// Daten kopieren
	memcpy((void *)destAddr, data, byteCount);

	// Page-Protection wiederherstellen
	VirtualProtect((void *)destAddr, byteCount, pageProtectOld, &pageProtectOld);
}

void CreateCodecave(DWORD destAddr, void(*func)(void), size_t nopCount)
{
	// Relativen Sprung-Offset berechnen
	// Die 5 Bytes des call-Befehls müssen berücksichtigt werden!
	DWORD callOffset = (PtrToUlong(func) - destAddr) - 5;
	
	// Patch für den Codecave-Aufruf erstellen:
	// call relAddr
	// -> Funktion relAddr Bytes weiter ausführen
	BYTE patch[5] = { 0xE8, 0x00, 0x00, 0x00, 0x00 }; // call relAddr
	memcpy(patch + 1, &callOffset, sizeof(DWORD));
	CopyBytesToAddr(destAddr, patch, 5);

	// Falls NOPs gesetzt werden sollen, diese erstellen
	if(nopCount > 0)
	{
		// Array mit nopCount Größe erstellen und mit NOP-Befehlen füllen
		BYTE *nops = new BYTE[nopCount];
		memset(nops, 0x90, nopCount);

		// NOPs kopieren
		CopyBytesToAddr(destAddr + 5, nops, nopCount);

		// Speicher wieder freigeben
		delete nops;
	}
}