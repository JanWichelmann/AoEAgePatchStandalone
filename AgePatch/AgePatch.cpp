/*
--- AOE AGE PATCH :: PATCH CODE ---
Semicolons in inline assembler are only for proper identation...
Return address (CALL command!) are popped from the stack to allow access to the "original stack" so we don't have to subtract 4 bytes when we access the stack or the stack pointer.
*/


/* INCLUDES */

// Codecave functions
#include "functions.h"


/* GLOBAL VARIABLES */

// Auxiliary variable to delete stack entries
DWORD _garbage = 0;

// Assembler function addresses
DWORD _funcUnknown1 = 0x004C05B0;
DWORD _funcGetString = 0x00562CB0;
DWORD _funcFormatString = 0x0061442B;
DWORD _funcComboBoxCreateEntry1 = 0x00550840;
DWORD _funcComboBoxCreateEntry2 = 0x00550870;
DWORD _funcUnknown2 = 0x00457F90;
DWORD _funcFloatToInt = 0x006139E4;
DWORD _funcUnknown3 = 0x00403996;
DWORD _funcUnknown4 = 0x004038ED;
DWORD _funcUnknown5 = 0x00403A2E;
DWORD _funcUnknown6 = 0x0040244D;

// Age constants
float RESEARCH_ID_DUNKEL = 105.0f;
float RESEARCH_ID_FEUDAL = 101.0f;
float RESEARCH_ID_RITTER = 102.0f;
float RESEARCH_ID_IMPERIAL = 103.0f;
float RESEARCH_ID_RENAISSANCE = 104.0f;


/* CODECAVE FUNCTIONS */

// Codecave function.
// 
DWORD _retAddr_Renaissance1 = 0;
__declspec(naked) void CC_Renaissance1()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance1;

		// Commands overwritten by codecave call
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x65;

		// Feudal age
		jne ritter;
		push 0;
		push 0;
		push 0;
		push 0;
		mov ecx, [ebp - 0x20];
		mov edx, [ecx + 0x0C];
		mov ecx, [edx + 0x000018E8];
		call[_funcUnknown1];
		jmp block1;

		// Castle age
	ritter:
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x66;
		jne imperial;
		push 0;
		push 0;
		push 0;
		push 1;
		mov ecx, [ebp - 0x20];
		mov edx, [ecx + 0x0C];
		mov ecx, [edx + 0x000018E8];
		call[_funcUnknown1];
		jmp block1;

		// Imperial age
	imperial:
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x67;
		jne renaissance;
		push 0;
		push 0;
		push 0;
		push 2;
		mov ecx, [ebp - 0x20];
		mov edx, [ecx + 0x0C];
		mov ecx, [edx + 0x000018E8];
		call[_funcUnknown1];
		jmp block1;

		// Renaissance
	renaissance:
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x68;
		jne block1;
		push 0;
		push 0;
		push 0;
		push 3;
		mov ecx, [ebp - 0x20];
		mov edx, [ecx + 0x0C];
		mov ecx, [edx + 0x000018E8];
		call[_funcUnknown1];

		// Block 1
	block1:
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x69;
		je end;
		movsx ecx, word ptr[ebp + 0x08];
		cmp ecx, 0x65;
		je end;
		movsx edx, word ptr[ebp + 0x08];
		cmp edx, 0x66;
		je end;
		movsx edx, word ptr[ebp + 0x08];
		cmp edx, 0x67;
		je end;
		movsx eax, word ptr[ebp + 0x08];
		cmp eax, 0x68;

		// Jump out of the codecave, push destination onto stack
		je end; // Inverted JNE (at 0x00402626)
		push 0x004026F7;
		ret;

	end:
		// Push return address onto stack
		push _retAddr_Renaissance1;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance2 = 0;
__declspec(naked) void CC_Renaissance2()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance2;

		// Block 1
		mov ecx, [ebp + 0x00];
		cmp ecx, 0x69;
		je block2;
		cmp ecx, 0x65;
		je block2;
		cmp ecx, 0x66;
		je block2;
		cmp ecx, 0x67;
		je block2;
		cmp ecx, 0x68;
		jne end;

		// Block 2
	block2:
		mov ecx, [esp + 0x24];
		cmp ecx, 0x69;
		je end;
		cmp ecx, 0x65;
		je end;
		cmp ecx, 0x66;
		je end;
		cmp ecx, 0x67;
		je end;
		cmp ecx, 0x68;

		// Jump out of the codecave, push destination onto stack
		je end; // Inverted JNE (at 0x005AAD8E)
		push 0x005AAEE8;
		ret;

	end:
		mov edx, [eax];

		// Push return address onto stack
		push _retAddr_Renaissance2;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance3 = 0;
__declspec(naked) void CC_Renaissance3()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance3;

		// Age block
		cmp ebx, 0x65;
		je end;
		cmp ebx, 0x66;
		je end;
		cmp ebx, 0x67;
		je end;
		cmp ebx, 0x68;

		// Jump out of the codecave, push destination onto stack
		je end; // Inverted JNE (an 0x0043FF68)
		push 0x0043FFD5;
		ret;

	end:
		mov eax, [esi + 0x00001820];

		// Push return address onto stack
		push _retAddr_Renaissance3;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance4 = 0;
__declspec(naked) void CC_Renaissance4()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance4;

		// Age block
		cmp ebx, 0x65;
		je block2;
		cmp ebx, 0x66;
		je block2;
		cmp ebx, 0x67;
		je block2;
		cmp ebx, 0x68;
		je block2;
		push 0x00;
		push 0x00;
		push 0x1B;
		jmp end;

		// Block 2
	block2:
		push 0x00;
		push 0x00;
		push 0x05;

	end:
		mov ecx, esi;

		// Push return address onto stack
		push _retAddr_Renaissance4;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance5 = 0;
__declspec(naked) void CC_Renaissance5()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance5;

		// Dark age
		cmp eax, 0;
		jne feudal;
		mov ecx, [esi + 0x000011BC];
		push 0x00001069;
		mov eax, [ecx];
		jmp end;

		// Feudal age
	feudal:
		cmp eax, 1;
		jne ritter;
		mov ecx, [esi + 0x000011BC];
		push 0x0000106A;
		mov eax, [ecx];
		jmp end;

		// Castle age
	ritter:
		cmp eax, 2;
		jne imperial;
		mov ecx, [esi + 0x000011BC];
		push 0x0000106B;
		mov eax, [ecx];
		jmp end;

		// Imperial age
	imperial:
		cmp eax, 3;
		jne renaissance;
		mov ecx, [esi + 0x000011BC];
		push 0x0000106C;
		mov eax, [ecx];
		jmp end;

		// Renaissance
	renaissance:
		mov ecx, [esi + 0x000011BC];
		push 0x0000106D;
		mov eax, [ecx];

	end:
		// Push return address onto stack
		push _retAddr_Renaissance5;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance6 = 0;
__declspec(naked) void CC_Renaissance6()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance6;

		// Perform jump
		cmp eax, 0;
		je dunkel;
		cmp eax, 1;
		je feudal;
		cmp eax, 2;
		je ritter;
		cmp eax, 3;
		je imperial;
		jmp renaissance;

		// Dark age
	dunkel:
		mov eax, [esp + 0x20];
		mov edx, [ecx];
		push eax;
		push esi;
		push 0x00001069;
		jmp end;

		// Feudal age
	feudal:
		mov eax, [esp + 0x20];
		mov edx, [ecx];
		push eax;
		push esi;
		push 0x0000106A;
		jmp end;

		// Castle age
	ritter:
		mov eax, [esp + 0x20];
		mov edx, [ecx];
		push eax;
		push esi;
		push 0x0000106B;
		jmp end;

		// Imperial age
	imperial:
		mov eax, [esp + 0x20];
		mov edx, [ecx];
		push eax;
		push esi;
		push 0x0000106C;
		jmp end;

		// Renaissance
	renaissance:
		mov eax, [esp + 0x20];
		mov edx, [ecx];
		push eax;
		push esi;
		push 0x0000106D;

	end:
		call dword ptr[edx + 0x28];
		pop edi;
		pop esi;
		pop ebp;

		// Push return address onto stack
		push _retAddr_Renaissance6;

		// Return
		ret;
	};
}

// Codecave function.
// 
DWORD _retAddr_Renaissance7 = 0;
__declspec(naked) void CC_Renaissance7()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance7;

		// Perform jump
		cmp eax, 0;
		je feudal;
		cmp eax, 1;
		je ritter;
		cmp eax, 2;
		je imperial;
		jmp renaissance;

		// Feudal age:
	feudal:
		mov edx, [esi];
		push 0x0000106A;
		mov ecx, esi;
		call dword ptr[edx + 0x000000FC];
		jmp end;

		// Castle age:
	ritter:
		mov eax, [esi];
		push 0x0000106B;
		mov ecx, esi;
		call dword ptr[eax + 0x000000FC];
		jmp end;

		// Imperial age:
	imperial:
		mov edx, [esi];
		push 0x0000106C;
		mov ecx, esi;
		call dword ptr[edx + 0x000000FC];
		jmp end;

		// Renaissance:
	renaissance:
		mov edx, [esi];
		push 0x0000106D;
		mov ecx, esi;
		call dword ptr[edx + 0x000000FC];

	end:
		// Push return address onto stack
		push _retAddr_Renaissance7;

		// Return
		ret;
	};
}

// Codecave function.
// Overwrites the UserPatch ComboBox changes.
__declspec(naked) void CC_Renaissance8()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _garbage;

		// Save EDI register
		push edi;

		// Generate entries for each age
		lea edi, [esp + 0x00000148];
		push 2; // Dark age
		call build_starting_age_entries;
		push 3; // Feudal age
		call build_starting_age_entries;
		push 4; // Castle age
		call build_starting_age_entries;
		push 5; // Imperial age
		call build_starting_age_entries;

		// Pop EDI register from stack
		pop edi;

		// Renaissance
		mov ecx, [esi + 0x00000B20];
		push 6;
		push 0x0000106D;
		call _funcComboBoxCreateEntry2;

		// Post Renaissance
		mov ecx, [esi + 0x00000B20];
		push 7;
		push 0x0000106F; // Post Renaissance language ID is 4207
		call _funcComboBoxCreateEntry2;

	end:
		// Jump behind the the segment originally skipped by the UserPatch
		push 0x005055EB;
		ret;

	build_starting_age_entries:
		// Save registers
		push ebx;
		push ebp;

		// EBX is the inverted maximum age: (maximum age - EBX) => The maximum ages are sorted descending
		xor ebx, ebx;

		// Begin with highest age, count down
		mov ebp, 6;

	build_starting_age_entries_loop:
		// Fetch starting age string
		mov ecx, [esp + 0x0C];
		lea edx, [edi + 0x40];
		lea eax, [ecx + 0x00002C63]; // New DLL IDs for abbrevations
		push 0x20;
		push edx;
		push eax;
		call[_funcGetString];

		// Fetch maximum age string
		mov ecx, [esp + 0x0C];
		lea edx, [edi + 0x60];
		lea eax, [ebp + 0x00002C63]; // New DLL IDs for abbrevations
		push 0x20;
		push edx;
		push eax;
		call[_funcGetString];

		// Concat the two strings
		lea edx, [edi + 0x60];
		lea ecx, [edi + 0x40];
		push edx;
		push ecx;
		push 0x0066FFC8;
		push edi;
		call[_funcFormatString];
		add esp, 0x10;
		mov edx, [esp + 0x0C];
		mov eax, ebx;

		// Shift the maximum age number by 3 bits and OR it with the starting age number
		shl eax, 3;
		or al, dl;

		// Call ComboBox function and insert entry
		push eax;
		push edi;
		mov ecx, [esi + 0x00000B20];
		call[_funcComboBoxCreateEntry1];

		// Put starting age into EAX
		mov eax, [esp + 0x0C];

		// Next maximum age
		dec ebp;
		inc ebx;

		// Done?
		cmp eax, ebp;

		// Jump to the top for next maximum age
		jle build_starting_age_entries_loop;

		// End of function
		pop ebp;
		pop ebx;
		ret 4;
	};
}

// Codecave function.
// Overwrites the recursive starting age call which researches all ages up to the desired starting age.
__declspec(naked) void CC_Renaissance10()
{
	__asm
	{
		// Retrieve resource ID
		mov eax, [esp + 0x04];
		push esi;

		// Subtract 23 from EAX
		add eax, -0x17;
		mov esi, ecx;

		//cmp eax, 23;
		//ja end2;

		// Jump to corresponding age block
		// The following numbers + 23 yield the civilization resource IDs for the age IDs
		cmp eax, 35; // (3A)
		je dunkle;
		cmp eax, 2; // (19)
		je feudal;
		cmp eax, 0; // (17)
		je ritter;
		cmp eax, 1; // (18)
		je imperial;
		cmp eax, 16; // (27)
		je renaissance;
		cmp eax, 200; // (DF) => The new Post Renaissance is coded to 217 (there shouldn't be conflicts with existing resource IDs)
		je post_renaissance;
		jmp end2;

		// Dark age in map editor?
	dunkle:
		mov edx, [esi + 0x000000A8];
		fld dword ptr[edx + 0x000000E8];
		jmp end1;

		// Feudal age
	feudal:
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_FEUDAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown3;
		mov ecx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_DUNKEL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown4;
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_FEUDAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown5;
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_FEUDAL];
		jmp end1;

		// Castle age
	ritter:
		// First call Feudal age
		push 0x19;
		mov ecx, esi;
		call CC_Renaissance10;

		// Continue
		mov ecx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RITTER];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown3;
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_FEUDAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown4;
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RITTER];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown5;
		mov ecx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RITTER];
		jmp end1;

		// Imperial age
	imperial:
		// First call castle age
		push 0x17;
		mov ecx, esi;
		call CC_Renaissance10;

		// Continue
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_IMPERIAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown3;
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RITTER];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown4;
		mov ecx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_IMPERIAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown5;
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_IMPERIAL];
		jmp end1;

		// Renaissance
	renaissance:
		// First call imperial age
		push 0x18;
		mov ecx, esi;
		call CC_Renaissance10;

		// Continue
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RENAISSANCE];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown3;
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_IMPERIAL];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown4;
		mov ecx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RENAISSANCE];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown5;
		mov edx, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RENAISSANCE];

		// End 1
	end1:
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown6;
		mov ecx, [esi + 0x000000A8];
		pop esi;
		mov[ecx + 0x0000018C], 0x00000000;
		ret 4;

		// Post Renaissance
	post_renaissance:
		// First call Renaissance
		push 0x27;
		mov ecx, esi;
		call CC_Renaissance10;

		// Continue
		mov eax, [esi + 0x000000A8];
		fld dword ptr[RESEARCH_ID_RENAISSANCE];
		call _funcFloatToInt;
		mov ecx, [esi + 0x000012A0];
		push eax;
		call _funcUnknown4;

		// End 2
	end2:
		mov ecx, [esi + 0x000000A8];
		pop esi;
		mov[ecx + 0x0000018C], 0x00000000;
		ret 4;
	};
}

// Codecave function.
// Overwrites the playerwise starting age call.
__declspec(naked) void CC_Renaissance9()
{
	__asm
	{
		// Pop return address from the stack and discard it
		pop _garbage;

		// Jump to corresponding age block
		cmp eax, 0;
		je dunkel;
		cmp eax, 1;
		je feudal;
		cmp eax, 2;
		je ritter;
		cmp eax, 3;
		je imperial;
		cmp eax, 4;
		je renaissance;
		cmp eax, 5;
		je post_renaissance;
		jmp end;

		// Dark age
	dunkel:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jng end;
	dunkel_player:
		mov edx, [ebp + 0x4C];
		mov ecx, [edx + esi * 4];
		call calc_max_age_id;
		movsx eax, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, eax;
		jnge dunkel_player;
		jmp end;

		// Feudal age
	feudal:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jle end;
	feudal_player: // Player loop
		mov edx, [ebp + 0x4C];
		push 0x19;
		mov ecx, [edx + esi * 4];
		{ // Formerly UserPatch function
			push esi;
			mov esi, ecx;
			mov eax, [esp + 0x04];
			push eax;
			call CC_Renaissance10;
			mov ecx, esi;
			call calc_max_age_id;
			pop esi;

			// Pop one int more from the stack and discard it
			pop _garbage;
		}
		movsx eax, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, eax;
		jnge feudal_player;
		jmp end;

		// Castle age
	ritter:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jle end;
	ritter_player: // Player loop
		mov ecx, [ebp + 0x4C];
		push 0x17;
		mov ecx, [ecx + esi * 4];
		{ // Formerly UserPatch function
			push esi;
			mov esi, ecx;
			mov eax, [esp + 0x04];
			push eax;
			call CC_Renaissance10;
			mov ecx, esi;
			call calc_max_age_id;
			pop esi;

			// Pop one int more from the stack and discard it
			pop _garbage;
		}
		movsx edx, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, edx;
		jnge ritter_player;
		jmp end;

		// Imperial age
	imperial:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jle end;
	imperial_player: // Player loop
		mov ecx, [ebp + 0x4C];
		push 0x18;
		mov ecx, [ecx + esi * 4];
		{ // Formerly UserPatch function
			push esi;
			mov esi, ecx;
			mov eax, [esp + 0x04];
			push eax;
			call CC_Renaissance10;
			mov ecx, esi;
			call calc_max_age_id;
			pop esi;

			// Pop one int more from the stack and discard it
			pop _garbage;
		}
		movsx edx, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, edx;
		jnge imperial_player;
		jmp end;

		// Renaissance
	renaissance:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jle end;
	renaissance_player: // Player loop
		mov eax, [ebp + 0x4C];
		push 0x27;
		mov ecx, [eax + esi * 4];
		call CC_Renaissance10;
		movsx ecx, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, ecx;
		jnge renaissance_player;
		jmp end;

		// Post Renaissance
	post_renaissance:
		cmp[ebp + 0x48], bx;
		mov esi, ebx;
		jle end;
	post_renaissance_player: // Player loop
		mov edx, [ebp + 0x4C];
		push 0xDF;
		mov ecx, [edx + esi * 4];
		call CC_Renaissance10;
		movsx eax, word ptr[ebp + 0x48];
		inc esi;
		cmp esi, eax;
		jnge post_renaissance_player;
		jmp end;

		// Calculates the technology ID of the maximum age.
	calc_max_age_id:
		xor edx, edx; // Workaround because the compiler messes up MOV with constant address...
		mov edx, [edx + 0x007912A0];
		mov eax, [edx + 0x00001440];
		shr eax, 3;
		test eax, eax;
		je calc_max_age_id_end;
		mov edx, 105; // Maximum possible age ID
		sub edx, eax;
		push 0;
		push edx;
		call _funcUnknown2;
	calc_max_age_id_end:
		ret;

	end:
		// Jump behind the overwritten function to save NOPs and improve performance
		push 0x0042A7BF;
		ret;
	};
}

// Codecave function.
// Overwrites the starting age call when the map editors "Test" button ist clicked.
DWORD _retAddr_Renaissance11 = 0;
__declspec(naked) void CC_Renaissance11()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance11;

		// Compare age number
		cmp eax, 4;
		ja end;

		// Perform jump
		cmp eax, 0;
		je feudal;
		cmp eax, 1;
		je ritter;
		cmp eax, 2;
		je imperial;
		cmp eax, 3;
		je renaissance;
		jmp post_renaissance;

		// Feudal age
	feudal:
		push 0x19;
		jmp age_call;

		// Castle age
	ritter:
		push 0x17;
		jmp age_call;

		// Imperial age
	imperial:
		push 0x18;
		jmp age_call;

		// Renaissance
	renaissance:
		push 0x27;
		jmp age_call;

		// Post Renaissance
	post_renaissance:
		push 0xDF;

	age_call:
		// Perform call
		mov ecx, edi;
		call CC_Renaissance10;

	end:
		// Push return address onto stack
		push _retAddr_Renaissance11;

		// Return
		ret;
	};
}

// Codecave function.
// Overwrites the starting age call when changing the starting age in the map editor.
DWORD _retAddr_Renaissance12 = 0;
__declspec(naked) void CC_Renaissance12()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance12;

		// Compare age number
		cmp esi, 5;
		ja end;

		// Perform jump
		cmp esi, 0;
		je dunkel;
		cmp esi, 1;
		je feudal;
		cmp esi, 2;
		je ritter;
		cmp esi, 3;
		je imperial;
		cmp esi, 4;
		je renaissance;
		jmp post_renaissance;

		// Dark age
	dunkel:
		push 0x3A;
		jmp age_call;

		// Feudal age
	feudal:
		push 0x19;
		jmp age_call;

		// Castle age
	ritter:
		push 0x17;
		jmp age_call;

		// Imperial age
	imperial:
		push 0x18;
		jmp age_call;

		// Renaissance
	renaissance:
		push 0x27;
		jmp age_call;

		// Post Renaissance
	post_renaissance:
		push 0xDF;

	age_call:
		// Perform call
		mov ecx, edi;
		call CC_Renaissance10;

	end:
		mov eax, [edi + 0x78];

		// Push return address onto stack
		push _retAddr_Renaissance12;

		// Return
		ret;
	};
}

// Codecave function.
// Overwrites the starting age call when changing the starting age in the map editor.
DWORD _retAddr_Renaissance13 = 0;
__declspec(naked) void CC_Renaissance13()
{
	__asm
	{
		// Pop return address from the stack and save it
		pop _retAddr_Renaissance13;

		// Dark age
		mov ecx, [esi + 0x00000A34];
		push 2;
		push 0x00001069;
		call _funcComboBoxCreateEntry2;

		// Feudal age
		mov ecx, [esi + 0x00000A34];
		push 3;
		push 0x0000106A;
		call _funcComboBoxCreateEntry2;

		// Castle age
		mov ecx, [esi + 0x00000A34];
		push 4;
		push 0x0000106B;
		call _funcComboBoxCreateEntry2;

		// Imperial age
		mov ecx, [esi + 0x00000A34];
		push 5;
		push 0x0000106C;
		call _funcComboBoxCreateEntry2;
		
		// Renaissance
		mov ecx, [esi + 0x00000A34];
		push 6;
		push 0x0000106D;
		call _funcComboBoxCreateEntry2;

		// Post Renaissance
		mov ecx, [esi + 0x00000A34];
		push 7;
		push 0x0000106F;
		call _funcComboBoxCreateEntry2;

		// Push return address onto stack
		push _retAddr_Renaissance13;

		// Return
		ret;
	};
}

/* DLL FUNCTION */

// DLL entry point.
int WINAPI DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)
{
	// Disable DLL thread messages
	if(ulReason == DLL_PROCESS_ATTACH)
		DisableThreadLibraryCalls(hModule);

	// Always load
	return TRUE;
}

// Initialization function.
// Initializes the codecaves and performs some additional changes in the logical memory.
extern "C" __declspec(dllexport) void Init()
{
	// Create Codecaves
	CreateCodecave(0x0040259A, CC_Renaissance1, 141);
	CreateCodecave(0x005AAD61, CC_Renaissance2, 48);
	CreateCodecave(0x0043FF59, CC_Renaissance3, 16);
	CreateCodecave(0x0043FFF8, CC_Renaissance4, 26);
	CreateCodecave(0x0051FF37, CC_Renaissance5, 72);
	CreateCodecave(0x0043D051, CC_Renaissance6, 87);
	CreateCodecave(0x004ACF51, CC_Renaissance7, 43);
	CreateCodecave(0x00505591, CC_Renaissance8, 0);
	CreateCodecave(0x0042A73A, CC_Renaissance9, 0);
	CreateCodecave(0x0043698E, CC_Renaissance11, 28);
	CreateCodecave(0x004DFE40, CC_Renaissance12, 35);
	CreateCodecave(0x004ED2CE, CC_Renaissance13, 85);

	// The function 0x00457FC0 was moved into Renaissance codecave 10
	CreateCodecave(0x00427291, CC_Renaissance10, 0);
	CreateCodecave(0x004272A4, CC_Renaissance10, 0);
	CreateCodecave(0x004272B7, CC_Renaissance10, 0);
	CreateCodecave(0x004272CA, CC_Renaissance10, 0);
	CreateCodecave(0x00429A41, CC_Renaissance10, 0);
	CreateCodecave(0x00429ACA, CC_Renaissance10, 0);
	CreateCodecave(0x00429C15, CC_Renaissance10, 0);
	CreateCodecave(0x007D8E8A, CC_Renaissance10, 0);

	// Renaissance mini patches
	{
		// Change ID of dark age
		BYTE patch1[1] = { 0x69 };
		CopyBytesToAddr(0x0040265F, patch1, 1);
		CopyBytesToAddr(0x00402689, patch1, 1);
		CopyBytesToAddr(0x004026B2, patch1, 1);
		CopyBytesToAddr(0x004026DB, patch1, 1);

		// Include Renaissance ID
		patch1[0] = 0x68;
		CopyBytesToAddr(0x0040282C, patch1, 1);
		CopyBytesToAddr(0x00402B07, patch1, 1);
		CopyBytesToAddr(0x00402ECB, patch1, 1);
		CopyBytesToAddr(0x0040313E, patch1, 1);
		CopyBytesToAddr(0x004864F5, patch1, 1);

		// Change age count
		patch1[0] = 0x04;
		CopyBytesToAddr(0x0051FF2E, patch1, 1);
		CopyBytesToAddr(0x0043D04A, patch1, 1);
		CopyBytesToAddr(0x005280D9, patch1, 1);

		// Change age count
		patch1[0] = 0x05;
		CopyBytesToAddr(0x0042A733, patch1, 1);

		// Change civilization age number resources
		patch1[0] = 0xDF; // Post Renaissance
		CopyBytesToAddr(0x00429A3D, patch1, 1);
		CopyBytesToAddr(0x00429AC6, patch1, 1);
		CopyBytesToAddr(0x00429C11, patch1, 1);

		// TODO: Add AI maximum age constant for Renaissance at 0x007AF140
	}

	// New ID for field sowing message (collosion with Renaissance advancement message)
	BYTE patch[2] = { 0x0A, 0x0C };
	CopyBytesToAddr(0x00529A76, patch, 2);
}

