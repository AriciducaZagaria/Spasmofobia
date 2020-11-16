// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "../MS Detours/detours.h"
#include "il2cpp-init.h"
#include "il2cpp-appdata.h"
#include "helpers.h"

extern "C" __declspec(dllexport) void __stdcall Spasmofobia();
void __stdcall Spasmofobia() { std::cout << "Spasmofobia is here" << std::endl; }

using namespace app;

typedef void(*PhotonNetwork_ConnectUsingSettings_Hook)(MethodInfo*);
typedef void(*Text_set_Text_Hook)(Text*, String*, MethodInfo*);

void PhotonNetwork_ConnectUsingSettings_Detour(MethodInfo*);
void Text_set_Text_Detour(Text*, String*, MethodInfo*);

PhotonNetwork_ConnectUsingSettings_Hook _photonNetwork_ConnectUsingSettings;
Text_set_Text_Hook _text_set_Text;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

const char* serverVersionText = " ArciducaZagaria's Spasmofobia";
const char* appId = "76ffcfb5-d1aa-4efe-b5f0-9d95d7ef4d7a";

// Custom injected code entry point
void Run(){
	Sleep(10000);
	init_il2cpp();

	_photonNetwork_ConnectUsingSettings = (PhotonNetwork_ConnectUsingSettings_Hook)app::PhotonNetwork_ConnectUsingSettings;

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)_photonNetwork_ConnectUsingSettings, &PhotonNetwork_ConnectUsingSettings_Detour);
	DetourTransactionCommit();
}

void PhotonNetwork_ConnectUsingSettings_Detour(MethodInfo* method) {

	String* _appId = app::Marshal_PtrToStringAnsi((void*)appId, NULL);
	AppSettings* _appSettings = (*app::PhotonNetwork__TypeInfo).static_fields->photonServerSettings->fields.AppSettings;
	_appSettings->fields.AppIdRealtime = _appId;
	_appSettings->fields.AppIdVoice = _appId;

	_text_set_Text = (Text_set_Text_Hook)app::Text_set_text;

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)_text_set_Text, &Text_set_Text_Detour);
	DetourTransactionCommit();

	_photonNetwork_ConnectUsingSettings(method);
}


void Text_set_Text_Detour(Text* __this, String* value, MethodInfo* method) {
	MainManager* _mainManager = (*app::MainManager__TypeInfo).static_fields->___________;
	if (__this == _mainManager->fields.serverVersionText) {
		String* _serverVersionText = app::Marshal_PtrToStringAnsi((void*)serverVersionText, NULL);
		return _text_set_Text(__this, _serverVersionText, method);
	}
	_text_set_Text(__this, value, method);
}

