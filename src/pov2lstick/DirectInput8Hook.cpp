#include "stdafx.h"
#include "DirectInput8Hook.h"
#include "DirectInput8HookObject.h"

namespace di8hook
{
	DirectInput8CreateFunc* OriginalCreateFunction = nullptr;
	HMODULE DirectInput8Dll = NULL;

	bool LoadDirectInputDll()
	{
		char dllPath[MAX_PATH];

		// システムディレクトリにある dinput8.dll を読み込む
		GetSystemDirectoryA(dllPath, MAX_PATH);
		strcat_s(dllPath, "\\dinput8.dll");
		DirectInput8Dll = LoadLibraryA(dllPath);

		// 読み込めたかチェック
		if (DirectInput8Dll == NULL) { return false; }

		// 関数 DirectInput8Create を取得する
		OriginalCreateFunction = reinterpret_cast<DirectInput8CreateFunc*>(GetProcAddress(DirectInput8Dll, "DirectInput8Create"));
	
		return true;
	}
}

HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	if (di8hook::OriginalCreateFunction == nullptr)
	{
		// 読み込みに失敗している
		return S_FALSE;
	}
	else
	{
		if (riidltf == IID_IDirectInput8A)
		{
			// マルチバイト版の関数
			di8hook::CDinput8HookA* pOut = new di8hook::CDinput8HookA();
			*ppvOut = pOut;
			HRESULT hr = di8hook::OriginalCreateFunction(hinst, dwVersion, riidltf, (LPVOID*)&pOut->p, punkOuter);
			return hr;
		}
		else if (riidltf == IID_IDirectInput8W)
		{
			// Unicode版の関数
			di8hook::CDinput8HookW* pOut = new di8hook::CDinput8HookW();
			*ppvOut = pOut;
			HRESULT hr = di8hook::OriginalCreateFunction(hinst, dwVersion, riidltf, (LPVOID*)&pOut->p, punkOuter);
			return hr;
		}
		else
		{
			return S_FALSE;
		}

	}
}
