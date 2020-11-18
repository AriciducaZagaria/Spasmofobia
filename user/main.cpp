// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "il2cpp-init.h"
#include "il2cpp-appdata.h"
#include "helpers.h"
#include "../MS Detours/detours.h"

extern "C" __declspec(dllexport) void __stdcall Spasmofobia();
void __stdcall Spasmofobia() { std::cout << "Spasmofobia is here" << std::endl; }

using namespace app;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

typedef void(*PhotonNetwork_ConnectUsingSettings_Hook)(MethodInfo*);
typedef void(*Text_set_Text_Hook)(Text*, String*, MethodInfo*);

int LoadSettings();
void PhotonNetwork_ConnectUsingSettings_Detour(MethodInfo*);
void Text_set_Text_Detour(Text*, String*, MethodInfo*);

PhotonNetwork_ConnectUsingSettings_Hook _photonNetwork_ConnectUsingSettings;
Text_set_Text_Hook _text_set_Text;

const char* appidFileName = "spasmofobia_appid.txt";
const char* serverVersionText = " ArciducaZagaria's Spasmofobia";
const char* appId;

// Custom injected code entry point
void Run(){
	if (!LoadSettings()) 
		exit(1);

	_photonNetwork_ConnectUsingSettings = (PhotonNetwork_ConnectUsingSettings_Hook)app::PhotonNetwork_ConnectUsingSettings;
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)_photonNetwork_ConnectUsingSettings, &PhotonNetwork_ConnectUsingSettings_Detour);
	DetourTransactionCommit();
}

void PhotonNetwork_ConnectUsingSettings_Detour(MethodInfo* method) {
	load_il2cpp_types_ptr();
	String* _appId = app::Marshal_PtrToStringAnsi((void*)appId, NULL);

	if (!app::ServerSettings_IsAppId(_appId, NULL)) {
		MessageBox(
			NULL,
			(LPCWSTR)L"Invalid photon app id.",
			(LPCWSTR)L"Spasmofobia",
			MB_ICONERROR | MB_OK
		);
		exit(1);
	}

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

int LoadSettings() {
	std::ifstream appidFile(appidFileName);
	if (appidFile.fail()) {
		MessageBox(
			NULL,
			(LPCWSTR)L"Missing spasmofobia_appid file.",
			(LPCWSTR)L"Spasmofobia",
			MB_ICONERROR | MB_OK
		);
		std::ofstream appidFile(appidFileName);
		appidFile << "Insert your photon app id here";
		appidFile.close();
		return 0;
	} else {
		std::string appIdBuff;
		std::getline(appidFile, appIdBuff);
		appidFile.close();
		appId = appIdBuff.c_str();
	}
	return 1;
}

