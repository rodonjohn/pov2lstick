#pragma once

namespace di8hook
{
	/// <summary>
	/// DirectInput8Create �֐��̌^
	/// </summary>
	typedef HRESULT(WINAPI DirectInput8CreateFunc)(
		HINSTANCE hinst,
		DWORD dwVersion,
		REFIID riidltf,
		LPVOID* ppvOut,
		LPUNKNOWN punkOuter
		);

	/// <summary>
	/// �I���W�i���� DirectInput8Create �֐����i�[����|�C���^
	/// </summary>
	extern DirectInput8CreateFunc* OriginalCreateFunction;

	/// <summary>
	/// �I���W�i���� dinput8.dll �̃n���h��
	/// </summary>
	extern HMODULE DirectInput8Dll;

	/// <summary>
	/// �I���W�i���� dinput8.dll ��ǂݍ���
	/// </summary>
	/// <returns></returns>
	extern bool LoadDirectInputDll();
}