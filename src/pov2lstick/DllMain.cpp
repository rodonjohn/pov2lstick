#include "stdafx.h"
#include "DirectInput8Hook.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  dwReasonForCall,
	LPVOID lpReserved)
{
	switch (dwReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		return di8hook::LoadDirectInputDll();

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
