#pragma once
/*
--- AOE AGE PATCH :: CODECAVE FUNCTIONS :: DEFINITIONS ---
*/

/* INCLUDES */

// Windows definitions
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// C standard I/O functions
#include <cstdio>


/* DEFINITIONS */

// Creates a call for the given codecave function at the given destination address.
// Optionally after the call several NOPs can be inserted to overwrite damaged opcodes / functions.
// Parameters:
// -> destAddr: The address where the codecave call should be performed.
// -> func: The codecave function to be called.
// -> nopCount: The count of the NOPs to be inserted after the 5 CALL bytes.
void CreateCodecave(DWORD destAddr, void(*func)(void), size_t nopCount);

// Copies the given data to a given address.
// Parameters:
// -> destAddr: The address where the data should be copied to.
// -> data: The pointer to the data.
// -> byteCount: The length of the data to be copied (byte count).
void CopyBytesToAddr(DWORD destAddr, void *data, size_t byteCount);