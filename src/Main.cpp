#define WIN32_LEAN_AND_MEAN

#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <vector>
#include <WinSock2.h>
#include <WS2tcpip.h>

#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

SOCKET Connection;
bool IsConnected = false;
std::vector<std::string> packets = {};

void ClientHandler() {
	char msg[4096];
	while (true) {
		if (!IsConnected) return;
		try {
			recv(Connection, msg, sizeof(msg), 0);
			packets.emplace_back(msg);
		} catch (const std::exception& e) {
		}
	}
}

bool ClientDisconnect() {
	if (!IsConnected) return false;
	closesocket(Connection);
	WSACleanup();
	IsConnected = false;
	return true;
}
void MPIsConnected(RED4ext::IScriptable *aContext, RED4ext::CStackFrame *aFrame, bool *aOut, int64_t a4) {
	*aOut = IsConnected;
}

void MPConnect(RED4ext::IScriptable *aContext, RED4ext::CStackFrame *aFrame, bool *aOut, int64_t a4) {
	*aOut = false;
	RED4ext::CString ip;
	int port;
	RED4ext::GetParameter(aFrame, &ip);
	RED4ext::GetParameter(aFrame, &port);

	if (IsConnected) {
		std::cout << "MPConnect() > uzhe connected" << std::endl;
		return;
	}

	WSAData wsaData{};
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "MPConnect() > oshibka wsastartup" << std::endl;
		return;
	}

	SOCKADDR_IN addr;
	InetPton(AF_INET, ip.c_str(), &addr.sin_addr.s_addr);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR *) &addr, sizeof(addr)) != 0) {
		std::cout << "MPConnect() > server ne nayden" << std::endl;
		return;
	}
	std::cout << "MPConnect() > connected to " << ip.c_str() << ":" << port << std::endl;

	IsConnected = true;
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) ClientHandler, nullptr, 0, nullptr);
	*aOut = true;
}

void MPDisconnect(RED4ext::IScriptable *aContext, RED4ext::CStackFrame *aFrame, bool *aOut, int64_t a4) {
	*aOut = ClientDisconnect();
}

void MPSend(RED4ext::IScriptable *aContext, RED4ext::CStackFrame *aFrame, bool *aOut, int64_t a4) {
	*aOut = false;
	RED4ext::CString message;
	RED4ext::GetParameter(aFrame, &message);
	std::cout << "MPSend() > msg: " << message.c_str() << " len: " << message.Length() << std::endl;
	try {
		send(Connection, message.c_str(), message.Length(), 0);
		std::cout << "MPSend() > success";
	} catch (const std::exception& e) {
		return;
	}
	*aOut = true;
}

void MPReceive(RED4ext::IScriptable *aContext, RED4ext::CStackFrame *aFrame, RED4ext::CString *aOut, int64_t a4) {
	if (!packets.empty()) {
		*aOut = packets[0].c_str();
		packets.erase(packets.begin());
	}
}

RED4EXT_C_EXPORT void RED4EXT_CALL RegisterTypes() {}

RED4EXT_C_EXPORT void RED4EXT_CALL PostRegisterTypes() {
	auto rtti = RED4ext::CRTTISystem::Get();
	RED4ext::CBaseFunction::Flags flags = {.isNative = true, .isStatic = true};

	{
		auto func = RED4ext::CGlobalFunction::Create("MPIsConnected", "MPIsConnected", &MPIsConnected);
		func->flags = flags;
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("MPConnect", "MPConnect", &MPConnect);
		func->flags = flags;
		func->AddParam("String", "ip");
		func->AddParam("Int32", "port");
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("MPDisconnect", "MPDisconnect", &MPDisconnect);
		func->flags = flags;
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("MPSend", "MPSend", &MPSend);
		func->flags = flags;
		func->AddParam("String", "message");
		func->SetReturnType("Bool");
		rtti->RegisterFunction(func);
	}
	{
		auto func = RED4ext::CGlobalFunction::Create("MPReceive", "MPReceive", &MPReceive);
		func->flags = flags;
		func->SetReturnType("String");
		rtti->RegisterFunction(func);
	}
}


RED4EXT_C_EXPORT bool RED4EXT_CALL Main(RED4ext::PluginHandle aHandle, RED4ext::EMainReason aReason, const RED4ext::Sdk *aSdk) {
	switch (aReason) {
		case RED4ext::EMainReason::Load: {
			/*
			 * Here you can register your custom functions, initalize variable, create hooks and so on.
			 *
			 * Be sure to store the plugin handle and the interface because you cannot get it again later. The plugin handle
			 * is what identify your plugin through the extender.
			 *
			 * Returning "true" in this function loads the plugin, returning "false" will unload it and "Main" will be
			 * called with "Unload" reason.
			 */

//			{
//				try {
//					RED4ext::CName cName = "test";
//					auto rtti = RED4ext::CRTTISystem::Get();
//					auto type = rtti->GetType(cName);
//					std::cout << "test: " << type << std::endl;
//				} catch (_exception) {
//					std::cout << "test: " << "error" << std::endl;
//				}
//			}
//			{
//				RED4ext::CName cName = "Float";
//				auto rtti = RED4ext::CRTTISystem::Get();
//				auto type = rtti->GetType(cName);
//				std::cout << "Float: " << type << std::endl;
//			}
//			{
//				RED4ext::CName cName = "String";
//				auto rtti = RED4ext::CRTTISystem::Get();
//				auto type = rtti->GetType(cName);
//				std::cout << "String: " << type << std::endl;
//			}

			RED4ext::RTTIRegistrator::Add(RegisterTypes, PostRegisterTypes);

			break;
		}
		case RED4ext::EMainReason::Unload: {
			/*
			 * Here you can free resources you allocated during initalization or during the time your plugin was executed.
			 */
			break;
		}
	}

	return true;
}

RED4EXT_C_EXPORT void RED4EXT_CALL Query(RED4ext::PluginInfo *aInfo) {
	/*
	 * This function supply the necessary information about your plugin, like name, version, support runtime and SDK. DO
	 * NOT do anything here yet!
	 *
	 * You MUST have this function!
	 *
	 * Make sure to fill all of the fields here in order to load your plugin correctly.
	 *
	 * Runtime version is the game's version, it is best to let it set to "RED4EXT_RUNTIME_LATEST" if you want to target
	 * the latest game's version that the SDK defined, if the runtime version specified here and the game's version do
	 * not match, your plugin will not be loaded. If you want to use RED4ext only as a loader and you do not care about
	 * game's version use "RED4EXT_RUNTIME_INDEPENDENT".
	 */
	aInfo->name = L"Multipunk";
	aInfo->author = L"MelonHell";
	aInfo->version = RED4EXT_SEMVER(1, 0, 0);
	aInfo->runtime = RED4EXT_RUNTIME_LATEST;
	aInfo->sdk = RED4EXT_SDK_LATEST;
}

RED4EXT_C_EXPORT uint32_t RED4EXT_CALL Supports() { return RED4EXT_API_VERSION_LATEST; }