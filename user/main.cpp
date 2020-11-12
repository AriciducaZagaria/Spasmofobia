// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Custom injected code entry point

#include "pch-il2cpp.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include "../MS Detours/detours.h"
#include "il2cpp-appdata.h"
#include "helpers.h"

using namespace app;

typedef void(*PhotonHandler_FixedUpdate_Hook)(PhotonHandler*, MethodInfo*);
typedef void(*Text_set_Text_Hook)(Text*, String*, MethodInfo*);

void PhotonHandler_FixedUpdate_Detour(PhotonHandler*, MethodInfo*);
void Text_set_Text_Detour(Text*, String*, MethodInfo*);

PhotonHandler_FixedUpdate_Hook _photonHandler_FixedUpdate;
Text_set_Text_Hook _text_set_Text;
bool reconnectPhoton = true;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

// Custom injected code entry point
void Run(){
	String* _appId = app::Marshal_PtrToStringAnsi((void*)"76ffcfb5-d1aa-4efe-b5f0-9d95d7ef4d7a", NULL);
	AppSettings* _appSettings = (*PhotonNetwork__TypeInfo).static_fields->photonServerSettings->fields.AppSettings;
	_appSettings.
	
	_photonHandler_FixedUpdate = (PhotonHandler_FixedUpdate_Hook)app::PhotonHandler_FixedUpdate;
	_text_set_Text = (Text_set_Text_Hook)app::Text_set_text;

	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)_photonHandler_FixedUpdate, &PhotonHandler_FixedUpdate_Detour);
	DetourDetach(&(PVOID&)_text_set_Text, &Text_set_Text_Detour);
	DetourTransactionCommit();
}

void PhotonHandler_FixedUpdate_Detour(PhotonHandler* __this, MethodInfo* method) {
	if (reconnectPhoton){
		reconnectPhoton = false;
		app::PhotonNetwork_Disconnect(NULL);
		app::PhotonNetwork_ConnectUsingSettings(NULL);
	}
	_photonHandler_FixedUpdate(__this, method);
}

void Text_set_Text_Detour(Text* __this, String* value, MethodInfo* method) {
	MainManager* _mainManager = (*MainManager__TypeInfo).static_fields->___________;

	if (__this == _mainManager->fields.serverVersionText) {
		String* _serverVersionText = app::Marshal_PtrToStringAnsi((void*)"Spasmofobia", NULL);
		_text_set_Text(__this, _serverVersionText, method);
	}

	_text_set_Text(__this, value, method);
}