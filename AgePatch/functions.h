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

// Erstellt an der angegebenen Zieladresse einen Aufruf f�r die gegebene Codecave-Funktion.
// Optional k�nnen danach mehrere NOPs (No-Operation) eingef�gt werden, um ggf. zerst�rte Befehle zu �berschreiben.
// Parameter:
// -> destAddr: Die Adresse, an der Sprung eingef�gt werden soll.
// -> func: Die auszuf�hrende Codecave-Funktion.
// -> nopCount: Die Anzahl der einzuf�genden NOPs nach den 5 CALL-Bytes.
void CreateCodecave(DWORD destAddr, void(*func)(void), size_t nopCount);

// Kopiert die angegeben Daten an eine Zieladresse.
// Parameter:
// -> destAddr: Die Zieladresse, an die die Daten kopiert werden sollen.
// -> data: Der Pointer auf die zu kopierenden Daten.
// -> byteCount: Die L�nge der zu kopierenden Daten (Anzahl Bytes).
void CopyBytesToAddr(DWORD destAddr, void *data, size_t byteCount);