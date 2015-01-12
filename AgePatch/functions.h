#pragma once
/*
--- AOE AGE PATCH :: CODECAVE-FUNKTIONEN :: DEFINITIONEN ---
*/

/* INCLUDES */

// Windows-Funktionen
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// C-Standard-I/O-Funktionen
#include <cstdio>


/* DEFINITIONEN */

// Erstellt an der angegebenen Zieladresse einen Aufruf für die gegebene Codecave-Funktion.
// Optional können danach mehrere NOPs (No-Operation) eingefügt werden, um ggf. zerstörte Befehle zu überschreiben.
// Parameter:
// -> destAddr: Die Adresse, an der Sprung eingefügt werden soll.
// -> func: Die auszuführende Codecave-Funktion.
// -> nopCount: Die Anzahl der einzufügenden NOPs nach den 5 CALL-Bytes.
void CreateCodecave(DWORD destAddr, void(*func)(void), size_t nopCount);

// Kopiert die angegeben Daten an eine Zieladresse.
// Parameter:
// -> destAddr: Die Zieladresse, an die die Daten kopiert werden sollen.
// -> data: Der Pointer auf die zu kopierenden Daten.
// -> byteCount: Die Länge der zu kopierenden Daten (Anzahl Bytes).
void CopyBytesToAddr(DWORD destAddr, void *data, size_t byteCount);