#include "pch.h"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum Amy { DXoriginal, LikeDream, DXcleanshoes, DCtext };

static int AmyText = DXoriginal;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		
		ReplacePVM("amy_eggrobo", "amy_eggrobo_dx");
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}