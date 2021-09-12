#pragma once

namespace di8hook
{
	/// <summary>
	/// DirectInput8Create 関数の型
	/// </summary>
	typedef HRESULT(WINAPI DirectInput8CreateFunc)(
		HINSTANCE hinst,
		DWORD dwVersion,
		REFIID riidltf,
		LPVOID* ppvOut,
		LPUNKNOWN punkOuter
		);

	/// <summary>
	/// オリジナルの DirectInput8Create 関数を格納するポインタ
	/// </summary>
	extern DirectInput8CreateFunc* OriginalCreateFunction;

	/// <summary>
	/// オリジナルの dinput8.dll のハンドル
	/// </summary>
	extern HMODULE DirectInput8Dll;

	/// <summary>
	/// オリジナルの dinput8.dll を読み込む
	/// </summary>
	/// <returns></returns>
	extern bool LoadDirectInputDll();
}