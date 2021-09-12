#pragma once

namespace di8hook
{
    class CStickRange
    {
    public:
        void SetRange(LONG min, LONG max)
        {
            mMin = min;
            mMax = max;
            mCenter = (min + max) / 2;
        }

        void SetRange(LONG min, LONG max, LONG center)
        {
            mMin = min;
            mMax = max;
            mCenter = center;
        }

        LONG GetMin() const { return mMin; }
        LONG GetMax() const { return mMax; }
        LONG GetCenter() const { return mCenter; }

    protected:
        LONG mMin = 0;
        LONG mMax = 65535;
        LONG mCenter = 32767;
    };

    class CDinput8HookW : public IDirectInput8W
    {
    public:
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
        STDMETHOD_(ULONG, AddRef)(THIS);
        STDMETHOD_(ULONG, Release)(THIS);
        STDMETHOD(CreateDevice)(THIS_ REFGUID, LPDIRECTINPUTDEVICE8W*, LPUNKNOWN);
        STDMETHOD(EnumDevices)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKW, LPVOID, DWORD);
        STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
        STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
        STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);
        STDMETHOD(FindDevice)(THIS_ REFGUID, LPCWSTR, LPGUID);
        STDMETHOD(EnumDevicesBySemantics)(THIS_ LPCWSTR, LPDIACTIONFORMATW, LPDIENUMDEVICESBYSEMANTICSCBW, LPVOID, DWORD);
        STDMETHOD(ConfigureDevices)(THIS_ LPDICONFIGUREDEVICESCALLBACK, LPDICONFIGUREDEVICESPARAMSW, DWORD, LPVOID);

        IDirectInput8W* p = nullptr;
    };

    class CDinput8HookA : public IDirectInput8A
    {
    public:
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
        STDMETHOD_(ULONG, AddRef)(THIS);
        STDMETHOD_(ULONG, Release)(THIS);
        STDMETHOD(CreateDevice)(THIS_ REFGUID, LPDIRECTINPUTDEVICE8A*, LPUNKNOWN);
        STDMETHOD(EnumDevices)(THIS_ DWORD, LPDIENUMDEVICESCALLBACKA, LPVOID, DWORD);
        STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
        STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
        STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD);
        STDMETHOD(FindDevice)(THIS_ REFGUID, LPCSTR, LPGUID);
        STDMETHOD(EnumDevicesBySemantics)(THIS_ LPCSTR, LPDIACTIONFORMATA, LPDIENUMDEVICESBYSEMANTICSCBA, LPVOID, DWORD);
        STDMETHOD(ConfigureDevices)(THIS_ LPDICONFIGUREDEVICESCALLBACK, LPDICONFIGUREDEVICESPARAMSA, DWORD, LPVOID);

        IDirectInput8A* p = nullptr;
    };

    class CDinput8DeviceHookW : public IDirectInputDevice8W
    {
    public:
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
        STDMETHOD_(ULONG, AddRef)(THIS);
        STDMETHOD_(ULONG, Release)(THIS);
        STDMETHOD(GetCapabilities)(THIS_ LPDIDEVCAPS);
        STDMETHOD(EnumObjects)(THIS_ LPDIENUMDEVICEOBJECTSCALLBACKW, LPVOID, DWORD);
        STDMETHOD(GetProperty)(THIS_ REFGUID, LPDIPROPHEADER);
        STDMETHOD(SetProperty)(THIS_ REFGUID, LPCDIPROPHEADER);
        STDMETHOD(Acquire)(THIS);
        STDMETHOD(Unacquire)(THIS);
        STDMETHOD(GetDeviceState)(THIS_ DWORD, LPVOID);
        STDMETHOD(GetDeviceData)(THIS_ DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
        STDMETHOD(SetDataFormat)(THIS_ LPCDIDATAFORMAT);
        STDMETHOD(SetEventNotification)(THIS_ HANDLE);
        STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
        STDMETHOD(GetObjectInfo)(THIS_ LPDIDEVICEOBJECTINSTANCEW, DWORD, DWORD);
        STDMETHOD(GetDeviceInfo)(THIS_ LPDIDEVICEINSTANCEW);
        STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
        STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD, REFGUID);
        STDMETHOD(CreateEffect)(THIS_ REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT*, LPUNKNOWN);
        STDMETHOD(EnumEffects)(THIS_ LPDIENUMEFFECTSCALLBACKW, LPVOID, DWORD);
        STDMETHOD(GetEffectInfo)(THIS_ LPDIEFFECTINFOW, REFGUID);
        STDMETHOD(GetForceFeedbackState)(THIS_ LPDWORD);
        STDMETHOD(SendForceFeedbackCommand)(THIS_ DWORD);
        STDMETHOD(EnumCreatedEffectObjects)(THIS_ LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD);
        STDMETHOD(Escape)(THIS_ LPDIEFFESCAPE);
        STDMETHOD(Poll)(THIS);
        STDMETHOD(SendDeviceData)(THIS_ DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD);
        STDMETHOD(EnumEffectsInFile)(THIS_ LPCWSTR, LPDIENUMEFFECTSINFILECALLBACK, LPVOID, DWORD);
        STDMETHOD(WriteEffectToFile)(THIS_ LPCWSTR, DWORD, LPDIFILEEFFECT, DWORD);
        STDMETHOD(BuildActionMap)(THIS_ LPDIACTIONFORMATW, LPCWSTR, DWORD);
        STDMETHOD(SetActionMap)(THIS_ LPDIACTIONFORMATW, LPCWSTR, DWORD);
        STDMETHOD(GetImageInfo)(THIS_ LPDIDEVICEIMAGEINFOHEADERW);

        IDirectInputDevice8W* p = nullptr;
        GUID mDeviceGuid;
        CStickRange mRangeX;
        CStickRange mRangeY;
    };

    class CDinput8DeviceHookA : public IDirectInputDevice8A
    {
    public:
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
        STDMETHOD_(ULONG, AddRef)(THIS);
        STDMETHOD_(ULONG, Release)(THIS);

        STDMETHOD(GetCapabilities)(THIS_ LPDIDEVCAPS);
        STDMETHOD(EnumObjects)(THIS_ LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD);
        STDMETHOD(GetProperty)(THIS_ REFGUID, LPDIPROPHEADER);
        STDMETHOD(SetProperty)(THIS_ REFGUID, LPCDIPROPHEADER);
        STDMETHOD(Acquire)(THIS);
        STDMETHOD(Unacquire)(THIS);
        STDMETHOD(GetDeviceState)(THIS_ DWORD, LPVOID);
        STDMETHOD(GetDeviceData)(THIS_ DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
        STDMETHOD(SetDataFormat)(THIS_ LPCDIDATAFORMAT);
        STDMETHOD(SetEventNotification)(THIS_ HANDLE);
        STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
        STDMETHOD(GetObjectInfo)(THIS_ LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD);
        STDMETHOD(GetDeviceInfo)(THIS_ LPDIDEVICEINSTANCEA);
        STDMETHOD(RunControlPanel)(THIS_ HWND, DWORD);
        STDMETHOD(Initialize)(THIS_ HINSTANCE, DWORD, REFGUID);
        STDMETHOD(CreateEffect)(THIS_ REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT*, LPUNKNOWN);
        STDMETHOD(EnumEffects)(THIS_ LPDIENUMEFFECTSCALLBACKA, LPVOID, DWORD);
        STDMETHOD(GetEffectInfo)(THIS_ LPDIEFFECTINFOA, REFGUID);
        STDMETHOD(GetForceFeedbackState)(THIS_ LPDWORD);
        STDMETHOD(SendForceFeedbackCommand)(THIS_ DWORD);
        STDMETHOD(EnumCreatedEffectObjects)(THIS_ LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD);
        STDMETHOD(Escape)(THIS_ LPDIEFFESCAPE);
        STDMETHOD(Poll)(THIS);
        STDMETHOD(SendDeviceData)(THIS_ DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD);
        STDMETHOD(EnumEffectsInFile)(THIS_ LPCSTR, LPDIENUMEFFECTSINFILECALLBACK, LPVOID, DWORD);
        STDMETHOD(WriteEffectToFile)(THIS_ LPCSTR, DWORD, LPDIFILEEFFECT, DWORD);
        STDMETHOD(BuildActionMap)(THIS_ LPDIACTIONFORMATA, LPCSTR, DWORD);
        STDMETHOD(SetActionMap)(THIS_ LPDIACTIONFORMATA, LPCSTR, DWORD);
        STDMETHOD(GetImageInfo)(THIS_ LPDIDEVICEIMAGEINFOHEADERA);

        IDirectInputDevice8A* p = nullptr;
        GUID mDeviceGuid;
        CStickRange mRangeX;
        CStickRange mRangeY;
    };
}