#include "pch.h"
#include "Eggman.h"
#include "KidnappedAmy.h"
#include "Tikal.h"
#pragma warning(disable : 4996)

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
HelperFunctions HelperFunctionsGlobal;

wchar_t* ConvertCharToWChar(const char* value)
{
	const size_t cSize = strlen(value) + 1;
	wchar_t* wcharVariable = new wchar_t[cSize];
	mbstowcs(wcharVariable, value, cSize);
	return wcharVariable;
}

void ReplaceCharacter(const char* iniFile, const char* modDirectory, const HelperFunctions& helper)
{
	std::string iniFilePathString = modDirectory + (std::string)"\\" + iniFile + ".ini";

	const char* iniFilePathChar = iniFilePathString.c_str();
	wchar_t* iniFileFullPath = ConvertCharToWChar(iniFilePathChar);
	wchar_t* modPath = ConvertCharToWChar(modDirectory);

	helper.LoadDLLData(iniFileFullPath, modPath);
	delete[] iniFileFullPath;
	delete[] modPath;
}

void ReplaceEXEData(const char* iniFile, const char* modDirectory, const HelperFunctions& helper)
{
	std::string fullPath = modDirectory + (std::string)"\\" + iniFile + ".ini";

	const char* path_ = fullPath.c_str();

	const size_t cSize2 = strlen(path_) + 1;
	wchar_t* iniFileFullPath = new wchar_t[cSize2];
	mbstowcs(iniFileFullPath, path_, cSize2);

	const size_t cSize = strlen(modDirectory) + 1;
	wchar_t* modPath = new wchar_t[cSize];
	mbstowcs(modPath, modDirectory, cSize);

	helper.LoadEXEData(iniFileFullPath, modPath);
}

void Init_KidAmy()
{
	*(NJS_MODEL_SADX*)0x0319F6E8 = attach_02D9F6E8;
	WriteData((NJS_MOTION**)0x031C1C7C, &head_motion);
}

void Init_Eggman()
{
	WriteData((NJS_OBJECT**)0x2CD393C, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2CD46F4, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2CD594C, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2CD6904, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2D41A34, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2D42BBC, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2D44434, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2DCDB14, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2E2C844, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x2EEC334, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x3018C44, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x3019E5C, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x301B074, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x301C41C, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x301DE94, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x302015C, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x3021854, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x30220EC, &object_02AEB524);
	WriteData((NJS_OBJECT**)0x321A55C, &object_02AEB524);
	WriteData((WeldInfo**)0x006F08FB, (WeldInfo*)&EventEggmobileWeldInfo_DX);
}

void Init_Tikal()
{
	WriteData((NJS_OBJECT**)0x07B37F8, &object_004D8AE8);
	WriteData((NJS_MOTION**)0x07B382D, &animation_004EE3D0);	
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		ReplaceEXEData("KidnappedAmy", path, helperFunctions);
		ReplaceEXEData("eggman", path, helperFunctions);
		std::string fullPath = path + (std::string)"\\eg_jvlist.ini";
		helperFunctions.RegisterCharacterWelds(Characters_Eggman, fullPath.c_str());
		ReplaceEXEData("tikal", path, helperFunctions);
		fullPath = path + (std::string)"\\ti_jvlist.ini";
		helperFunctions.RegisterCharacterWelds(Characters_Tikal, fullPath.c_str());
		ReplaceEXEData("metal", path, helperFunctions);
		ReplaceEXEData("adv03_dll_data", path, helperFunctions);
		Init_Eggman();
		Init_KidAmy();
		Init_Tikal();

		ReplacePVM("amy_eggrobo", "amy_eggrobo_dx");
		ReplacePVM("tikal", "tikal_dx");
		ReplacePVM("eggman", "eggman_dx");
		ReplacePVM("ev_eggman_body", "eggman_dx");
		ReplacePVM("chaos6_eggman", "eggman_dx");
		ReplacePVM("egm1eggman", "eggman_dx");
		ReplacePVM("egm2_common", "egm2_common_dx");
		ReplacePVM("egm3mdl", "egm3mdl_dx");
		ReplacePVM("ev_eggmoble0", "ev_eggmoble0_dx");		
		ReplacePVM("ev_s_msbody", "ev_s_msbody_dx");
		ReplacePVM("ev_alife", "ev_alife_dx");
		ReplacePVM("mrace_eggmoble", "mrace_eggmoble_dx");
		ReplacePVM("amy_eggrobo_dc", "amy_eggrobo_dx");
		ReplacePVM("tikal_dc", "tikal_dx");
		ReplacePVM("eggman_dc", "eggman_dx");
		ReplacePVM("ev_eggman_body_dc", "eggman_dx");
		ReplacePVM("chaos6_eggman_dc", "eggman_dx");
		ReplacePVM("egm1eggman_dc", "eggman_dx");
		ReplacePVM("egm2_common_dc", "egm2_common_dx");
		ReplacePVM("egm3mdl_dc", "egm3mdl_dx");
		ReplacePVM("ev_eggmoble0_dc", "ev_eggmoble0_dx");
		ReplacePVM("ev_s_msbody_dc", "ev_s_msbody_dx");
		ReplacePVM("ev_alife_dc", "ev_alife_dx");
		ReplacePVM("mrace_eggmoble_dc", "mrace_eggmoble_dx");
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}