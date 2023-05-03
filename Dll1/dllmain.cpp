#include "pch.h"
#include "features.h"

DWORD WINAPI my_thread(void* hModule)
{
    //first parameter is for settings filename, second is callback for opening the menu
    //third is callback for closing the menu
    GDMO::Init("APITEST", nullptr, features::Save);
    //add a function that will get called in the imgui render function
    GDMO::addImGuiFunc(features::ImGuiTest);
    return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, my_thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

