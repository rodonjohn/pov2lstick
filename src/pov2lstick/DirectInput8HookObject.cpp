#include "stdafx.h"
#include "DirectInput8HookObject.h"

namespace di8hook
{
	STDMETHODIMP_(HRESULT) CDinput8HookW::QueryInterface(REFIID riid, LPVOID* ppvObj)
	{
		return p->QueryInterface(riid, ppvObj);
	}

	STDMETHODIMP_(ULONG) CDinput8HookW::AddRef(void)
	{
		return p->AddRef();
	}

	STDMETHODIMP_(ULONG) CDinput8HookW::Release(void)
	{
		ULONG refCount = p->Release();
		if (refCount == 0)
		{
			delete this;
		}
		return refCount;
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::CreateDevice(REFGUID guid, LPDIRECTINPUTDEVICE8W* ppDevice, LPUNKNOWN pUnk)
	{
		CDinput8DeviceHookW* pOut = new CDinput8DeviceHookW();
		*ppDevice = pOut;
		pOut->mDeviceGuid = guid;
		
		if (FAILED(p->CreateDevice(guid, (LPDIRECTINPUTDEVICE8W*)&pOut->p, pUnk)))
		{
			return S_FALSE;
		}

		// 現在設定されている X 軸の最大最小を取得する
		DIPROPRANGE diprg = { 0 };
		diprg.diph.dwSize = sizeof(diprg);
		diprg.diph.dwHeaderSize = sizeof(diprg.diph);
		diprg.diph.dwObj = 0x0002;
		diprg.diph.dwHow = DIPH_BYID;
		diprg.lMin = 0;
		diprg.lMax = 0;

		if (SUCCEEDED(pOut->p->GetProperty(DIPROP_RANGE, &diprg.diph)))
		{
			pOut->mRangeX.SetRange(diprg.lMin, diprg.lMax);
		}

		// 現在設定されている Y 軸の最大最小を取得する
		diprg.diph.dwObj = 0x0102;
		diprg.lMin = 0;
		diprg.lMax = 0;

		if (SUCCEEDED(pOut->p->GetProperty(DIPROP_RANGE, &diprg.diph)))
		{
			pOut->mRangeY.SetRange(diprg.lMin, diprg.lMax);
		}

		return S_OK;
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::EnumDevices(DWORD a, LPDIENUMDEVICESCALLBACKW b, LPVOID c, DWORD d)
	{
		return p->EnumDevices(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::GetDeviceStatus(REFGUID a)
	{
		return p->GetDeviceStatus(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::RunControlPanel(HWND a, DWORD b)
	{
		return p->RunControlPanel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::Initialize(HINSTANCE a, DWORD b)
	{
		return p->Initialize(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::FindDevice(REFGUID a, LPCWSTR b, LPGUID c)
	{
		return p->FindDevice(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::EnumDevicesBySemantics(LPCWSTR a, LPDIACTIONFORMATW b, LPDIENUMDEVICESBYSEMANTICSCBW c, LPVOID d, DWORD e)
	{
		return p->EnumDevicesBySemantics(a, b, c, d, e);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookW::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK a, LPDICONFIGUREDEVICESPARAMSW b, DWORD c, LPVOID d)
	{
		return p->ConfigureDevices(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::QueryInterface(REFIID riid, LPVOID* ppvObj)
	{
		return p->QueryInterface(riid, ppvObj);
	}

	STDMETHODIMP_(ULONG) CDinput8HookA::AddRef(void)
	{
		return p->AddRef();
	}

	STDMETHODIMP_(ULONG) CDinput8HookA::Release(void)
	{
		ULONG refCount = p->Release();
		if (refCount == 0)
		{
			delete this;
		}
		return refCount;
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::CreateDevice(REFGUID guid, LPDIRECTINPUTDEVICE8A* ppDevice, LPUNKNOWN pUnk)
	{
		CDinput8DeviceHookA* pOut = new CDinput8DeviceHookA();
		*ppDevice = pOut;
		pOut->mDeviceGuid = guid;

		if (FAILED(p->CreateDevice(guid, (LPDIRECTINPUTDEVICE8A*)&pOut->p, pUnk)))
		{
			return S_FALSE;
		}

		// 現在設定されている X 軸の最大最小を取得する
		DIPROPRANGE diprg = { 0 };
		diprg.diph.dwSize = sizeof(diprg);
		diprg.diph.dwHeaderSize = sizeof(diprg.diph);
		diprg.diph.dwObj = 0x0002;
		diprg.diph.dwHow = DIPH_BYID;
		diprg.lMin = 0;
		diprg.lMax = 0;

		if (SUCCEEDED(pOut->p->GetProperty(DIPROP_RANGE, &diprg.diph)))
		{
			pOut->mRangeX.SetRange(diprg.lMin, diprg.lMax);
		}

		// 現在設定されている Y 軸の最大最小を取得する
		diprg.diph.dwObj = 0x0102;
		diprg.lMin = 0;
		diprg.lMax = 0;

		if (SUCCEEDED(pOut->p->GetProperty(DIPROP_RANGE, &diprg.diph)))
		{
			pOut->mRangeY.SetRange(diprg.lMin, diprg.lMax);
		}

		return S_OK;
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::EnumDevices(DWORD a, LPDIENUMDEVICESCALLBACKA b, LPVOID c, DWORD d)
	{
		return p->EnumDevices(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::GetDeviceStatus(REFGUID a)
	{
		return p->GetDeviceStatus(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::RunControlPanel(HWND a, DWORD b)
	{
		return p->RunControlPanel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::Initialize(HINSTANCE a, DWORD b)
	{
		return p->Initialize(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::FindDevice(REFGUID a, LPCSTR b, LPGUID c)
	{
		return p->FindDevice(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::EnumDevicesBySemantics(LPCSTR a, LPDIACTIONFORMATA b, LPDIENUMDEVICESBYSEMANTICSCBA c, LPVOID d, DWORD e)
	{
		return p->EnumDevicesBySemantics(a, b, c, d, e);
	}

	STDMETHODIMP_(HRESULT) CDinput8HookA::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK a, LPDICONFIGUREDEVICESPARAMSA b, DWORD c, LPVOID d)
	{
		return p->ConfigureDevices(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::QueryInterface(REFIID riid, LPVOID* ppvObj)
	{
		return p->QueryInterface(riid, ppvObj);
	}

	STDMETHODIMP_(ULONG) CDinput8DeviceHookW::AddRef(void)
	{
		return p->AddRef();
	}

	STDMETHODIMP_(ULONG) CDinput8DeviceHookW::Release(void)
	{
		ULONG refCount = p->Release();
		if (refCount == 0)
		{
			delete this;
		}
		return refCount;
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetCapabilities(LPDIDEVCAPS a)
	{
		return p->GetCapabilities(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKW a, LPVOID b, DWORD c)
	{
		return p->EnumObjects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetProperty(REFGUID a, LPDIPROPHEADER b)
	{
		return p->GetProperty(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SetProperty(REFGUID diprop, LPCDIPROPHEADER pHeader)
	{
		// 範囲指定かつ X軸・Y軸 を設定しているときをフックする
		if (&diprop == &DIPROP_RANGE && DIDFT_GETTYPE(pHeader->dwObj) == DIDFT_ABSAXIS)
		{
			LPCDIPROPRANGE d = (LPCDIPROPRANGE)pHeader;

			// 最大最小
			LONG* pMin = (LONG*)((BYTE*)pHeader + pHeader->dwHeaderSize);
			LONG* pMax = pMin + 1;

			// X軸
			if (DIDFT_GETINSTANCE(pHeader->dwObj) == 0)
			{
				mRangeX.SetRange(*pMin, *pMax);
			}

			// Y軸
			if (DIDFT_GETINSTANCE(pHeader->dwObj) == 1)
			{
				mRangeY.SetRange(*pMin, *pMax);
			}
		}

		return p->SetProperty(diprop, pHeader);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::Acquire(void)
	{
		return p->Acquire();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::Unacquire(void)
	{
		return p->Unacquire();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetDeviceState(DWORD size, LPVOID pData)
	{
		HRESULT hr = p->GetDeviceState(size, pData);

		if (mDeviceGuid == GUID_SysMouse ||
			mDeviceGuid == GUID_SysKeyboard ||
			mDeviceGuid == GUID_SysMouseEm ||
			mDeviceGuid == GUID_SysMouseEm2 ||
			mDeviceGuid == GUID_SysKeyboardEm ||
			mDeviceGuid == GUID_SysKeyboardEm2
			)
		{
			// ジョイパッド以外
			return hr;
		}
		else if (size >= sizeof(DIJOYSTATE))
		{
			// DIJOYSTATE より大きいサイズであればここをいじる
			if (SUCCEEDED(hr))
			{
				DIJOYSTATE* pKey = (DIJOYSTATE*)pData;

				pKey->lX = mRangeX.GetCenter();
				pKey->lY = mRangeY.GetCenter();

				if (LOWORD(pKey->rgdwPOV[0]) != 0xFFFF)
				{
					int n = pKey->rgdwPOV[0];
					if (n < 2750) { pKey->lY = mRangeY.GetMin(); }
					else if (n < 7250) { pKey->lX = mRangeX.GetMax(); pKey->lY = mRangeY.GetMin(); }
					else if (n < 11750) { pKey->lX = mRangeX.GetMax(); }
					else if (n < 15250) { pKey->lX = mRangeX.GetMax(); pKey->lY = mRangeY.GetMax(); }
					else if (n < 20750) { pKey->lY = mRangeY.GetMax(); }
					else if (n < 24250) { pKey->lX = mRangeX.GetMin(); pKey->lY = mRangeY.GetMax(); }
					else if (n < 29750) { pKey->lX = mRangeX.GetMin(); }
					else if (n < 33250) { pKey->lX = mRangeX.GetMin(); pKey->lY = mRangeY.GetMin(); }
					else { pKey->lY = mRangeY.GetMin(); }

					pKey->rgdwPOV[0] = 0xFFFF;
				}
			}
			return hr;
		}
		else
		{
			// ここに来るパターン？
			return hr;
		}
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetDeviceData(DWORD a, LPDIDEVICEOBJECTDATA b, LPDWORD c, DWORD d)
	{
		return p->GetDeviceData(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SetDataFormat(LPCDIDATAFORMAT a)
	{
		return p->SetDataFormat(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SetEventNotification(HANDLE a)
	{
		return p->SetEventNotification(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SetCooperativeLevel(HWND a, DWORD b)
	{
		return p->SetCooperativeLevel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEW a, DWORD b, DWORD c)
	{
		return p->GetObjectInfo(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetDeviceInfo(LPDIDEVICEINSTANCEW a)
	{
		return p->GetDeviceInfo(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::RunControlPanel(HWND a, DWORD b)
	{
		return p->RunControlPanel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::Initialize(HINSTANCE a, DWORD b, REFGUID c)
	{
		return p->Initialize(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::CreateEffect(REFGUID a, LPCDIEFFECT b, LPDIRECTINPUTEFFECT* c, LPUNKNOWN d)
	{
		return p->CreateEffect(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::EnumEffects(LPDIENUMEFFECTSCALLBACKW a, LPVOID b, DWORD c)
	{
		return p->EnumEffects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetEffectInfo(LPDIEFFECTINFOW a, REFGUID b)
	{
		return p->GetEffectInfo(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetForceFeedbackState(LPDWORD a)
	{
		return p->GetForceFeedbackState(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SendForceFeedbackCommand(DWORD a)
	{
		return p->SendForceFeedbackCommand(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK a, LPVOID b, DWORD c)
	{
		return p->EnumCreatedEffectObjects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::Escape(LPDIEFFESCAPE a)
	{
		return p->Escape(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::Poll(void)
	{
		return p->Poll();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SendDeviceData(DWORD a, LPCDIDEVICEOBJECTDATA b, LPDWORD c, DWORD d)
	{
		return p->SendDeviceData(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::EnumEffectsInFile(LPCWSTR a, LPDIENUMEFFECTSINFILECALLBACK b, LPVOID c, DWORD d)
	{
		return p->EnumEffectsInFile(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::WriteEffectToFile(LPCWSTR a, DWORD b, LPDIFILEEFFECT c, DWORD d)
	{
		return p->WriteEffectToFile(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::BuildActionMap(LPDIACTIONFORMATW a, LPCWSTR b, DWORD c)
	{
		return p->BuildActionMap(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::SetActionMap(LPDIACTIONFORMATW a, LPCWSTR b, DWORD c)
	{
		return p->SetActionMap(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookW::GetImageInfo(LPDIDEVICEIMAGEINFOHEADERW a)
	{
		return this->GetImageInfo(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::QueryInterface(REFIID riid, LPVOID* ppvObj)
	{
		return p->QueryInterface(riid, ppvObj);
	}

	STDMETHODIMP_(ULONG) CDinput8DeviceHookA::AddRef(void)
	{
		return p->AddRef();
	}

	STDMETHODIMP_(ULONG) CDinput8DeviceHookA::Release(void)
	{
		ULONG refCount = p->Release();
		if (refCount == 0)
		{
			delete this;
		}
		return refCount;
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetCapabilities(LPDIDEVCAPS a)
	{
		return p->GetCapabilities(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA a, LPVOID b, DWORD c)
	{
		return p->EnumObjects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetProperty(REFGUID a, LPDIPROPHEADER b)
	{
		return p->GetProperty(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SetProperty(REFGUID diprop, LPCDIPROPHEADER pHeader)
	{
		// 範囲指定かつ X軸・Y軸 を設定しているときをフックする
		if (&diprop == &DIPROP_RANGE && DIDFT_GETTYPE(pHeader->dwObj) == DIDFT_ABSAXIS)
		{
			LPCDIPROPRANGE d = (LPCDIPROPRANGE)pHeader;

			// 最大最小
			LONG* pMin = (LONG*)((BYTE*)pHeader + pHeader->dwHeaderSize);
			LONG* pMax = pMin + 1;

			// X軸
			if (DIDFT_GETINSTANCE(pHeader->dwObj) == 0)
			{
				mRangeX.SetRange(*pMin, *pMax);
			}

			// Y軸
			if (DIDFT_GETINSTANCE(pHeader->dwObj) == 1)
			{
				mRangeY.SetRange(*pMin, *pMax);
			}
		}

		return p->SetProperty(diprop, pHeader);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::Acquire(void)
	{
		return p->Acquire();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::Unacquire(void)
	{
		return p->Unacquire();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetDeviceState(DWORD size, LPVOID pData)
	{
		HRESULT hr = p->GetDeviceState(size, pData);

		if (mDeviceGuid == GUID_SysMouse ||
			mDeviceGuid == GUID_SysKeyboard ||
			mDeviceGuid == GUID_SysMouseEm ||
			mDeviceGuid == GUID_SysMouseEm2 ||
			mDeviceGuid == GUID_SysKeyboardEm ||
			mDeviceGuid == GUID_SysKeyboardEm2
			)
		{
			// ジョイパッド以外
			return hr;
		}
		else if (size >= sizeof(DIJOYSTATE))
		{
			// DIJOYSTATE より大きいサイズであればここをいじる
			if (SUCCEEDED(hr))
			{
				DIJOYSTATE* pKey = (DIJOYSTATE*)pData;

				pKey->lX = mRangeX.GetCenter();
				pKey->lY = mRangeY.GetCenter();

				if (LOWORD(pKey->rgdwPOV[0]) != 0xFFFF)
				{
					int n = pKey->rgdwPOV[0];
					if (n < 2750) { pKey->lY = mRangeY.GetMin(); }
					else if (n < 7250) { pKey->lX = mRangeX.GetMax(); pKey->lY = mRangeY.GetMin(); }
					else if (n < 11750) { pKey->lX = mRangeX.GetMax(); }
					else if (n < 15250) { pKey->lX = mRangeX.GetMax(); pKey->lY = mRangeY.GetMax(); }
					else if (n < 20750) { pKey->lY = mRangeY.GetMax(); }
					else if (n < 24250) { pKey->lX = mRangeX.GetMin(); pKey->lY = mRangeY.GetMax(); }
					else if (n < 29750) { pKey->lX = mRangeX.GetMin(); }
					else if (n < 33250) { pKey->lX = mRangeX.GetMin(); pKey->lY = mRangeY.GetMin(); }
					else { pKey->lY = mRangeY.GetMin(); }

					pKey->rgdwPOV[0] = 0xFFFF;
				}
			}
			return hr;
		}
		else
		{
			// ここに来るパターン？
			return hr;
		}
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetDeviceData(DWORD a, LPDIDEVICEOBJECTDATA b, LPDWORD c, DWORD d)
	{
		return p->GetDeviceData(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SetDataFormat(LPCDIDATAFORMAT a)
	{
		return p->SetDataFormat(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SetEventNotification(HANDLE a)
	{
		return p->SetEventNotification(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SetCooperativeLevel(HWND a, DWORD b)
	{
		return p->SetCooperativeLevel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA a, DWORD b, DWORD c)
	{
		return p->GetObjectInfo(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetDeviceInfo(LPDIDEVICEINSTANCEA a)
	{
		return p->GetDeviceInfo(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::RunControlPanel(HWND a, DWORD b)
	{
		return p->RunControlPanel(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::Initialize(HINSTANCE a, DWORD b, REFGUID c)
	{
		return p->Initialize(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::CreateEffect(REFGUID a, LPCDIEFFECT b, LPDIRECTINPUTEFFECT* c, LPUNKNOWN d)
	{
		return p->CreateEffect(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::EnumEffects(LPDIENUMEFFECTSCALLBACKA a, LPVOID b, DWORD c)
	{
		return p->EnumEffects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetEffectInfo(LPDIEFFECTINFOA a, REFGUID b)
	{
		return p->GetEffectInfo(a, b);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetForceFeedbackState(LPDWORD a)
	{
		return p->GetForceFeedbackState(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SendForceFeedbackCommand(DWORD a)
	{
		return p->SendForceFeedbackCommand(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK a, LPVOID b, DWORD c)
	{
		return p->EnumCreatedEffectObjects(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::Escape(LPDIEFFESCAPE a)
	{
		return p->Escape(a);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::Poll(void)
	{
		return p->Poll();
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SendDeviceData(DWORD a, LPCDIDEVICEOBJECTDATA b, LPDWORD c, DWORD d)
	{
		return p->SendDeviceData(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::EnumEffectsInFile(LPCSTR a, LPDIENUMEFFECTSINFILECALLBACK b, LPVOID c, DWORD d)
	{
		return p->EnumEffectsInFile(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::WriteEffectToFile(LPCSTR a, DWORD b, LPDIFILEEFFECT c, DWORD d)
	{
		return p->WriteEffectToFile(a, b, c, d);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::BuildActionMap(LPDIACTIONFORMATA a, LPCSTR b, DWORD c)
	{
		return p->BuildActionMap(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::SetActionMap(LPDIACTIONFORMATA a, LPCSTR b, DWORD c)
	{
		return p->SetActionMap(a, b, c);
	}

	STDMETHODIMP_(HRESULT) CDinput8DeviceHookA::GetImageInfo(LPDIDEVICEIMAGEINFOHEADERA a)
	{
		return this->GetImageInfo(a);
	}
}