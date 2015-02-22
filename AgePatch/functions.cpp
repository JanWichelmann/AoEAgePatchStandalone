/*
--- AOE AGE PATCH :: CODECAVE FUNCTIONS :: IMPLEMENTATION ---
*/

/* INCLUDES */

// Definition header
#include "functions.h"


/* FUNCTIONS */

void CopyBytesToAddr(DWORD destAddr, void *data, size_t byteCount)
{
	// Change page protection to enable writing
	DWORD pageProtectOld = 0;
	VirtualProtect((void *)destAddr, byteCount, PAGE_EXECUTE_READWRITE, &pageProtectOld);

	// Copy data
	memcpy((void *)destAddr, data, byteCount);

	// Restore page protection
	VirtualProtect((void *)destAddr, byteCount, pageProtectOld, &pageProtectOld);
}

void CreateCodecave(DWORD destAddr, void(*func)(void), size_t nopCount)
{
	// Calculate relative jump offset excluding the 5 CALL bytes
	DWORD callOffset = (PtrToUlong(func) - destAddr) - 5;
	
	// Create patch for codecave call:
	// call relAddr
	// -> Call function at relAddr bytes offset
	BYTE patch[5] = { 0xE8, 0x00, 0x00, 0x00, 0x00 }; // call relAddr
	memcpy(patch + 1, &callOffset, sizeof(DWORD));
	CopyBytesToAddr(destAddr, patch, 5);

	// If NOPs are required, create them
	if(nopCount > 0)
	{
		// Create array with nopCount size and fill it with NOPs
		BYTE *nops = new BYTE[nopCount];
		memset(nops, 0x90, nopCount);

		// Copy NOP array
		CopyBytesToAddr(destAddr + 5, nops, nopCount);

		// Free NOP array memory
		delete nops;
	}
}