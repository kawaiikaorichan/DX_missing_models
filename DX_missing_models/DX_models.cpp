#include "pch.h"
#include "IniFile.hpp"
#include "Eggman.h"
#include "KidnappedAmy.h"
#include "Tikal.h"
#pragma warning(disable : 4996)

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");
HelperFunctions HelperFunctionsGlobal;

static bool EnableAmy = true;
static bool EnableEggman = true;
static bool EnableTikal = true;
static bool EnableMetal = true;
static bool EnableDXChao = true;

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
	*(NJS_OBJECT*)0x02EE83E0 = object_02AE83E0;
	*(NJS_OBJECT*)0x02EE7808 = object_02AE7808;
	*(NJS_OBJECT*)0x02EE588C = object_02AE588C;
	*(NJS_OBJECT*)0x02EE4FE0 = object_02AE4FE0;
	*(NJS_OBJECT*)0x02EE4AFC = object_02AE4AFC;
	*(NJS_OBJECT*)0x02EE43D8 = object_02AE43D8;
	*(NJS_OBJECT*)0x02EE4194 = object_02AE4194;
	*(NJS_OBJECT*)0x02EE3E98 = object_02AE3E98;
	*(NJS_OBJECT*)0x02EE33F8 = object_02AE33F8;
	*(NJS_OBJECT*)0x02EE2F14 = object_02AE2F14;
	*(NJS_OBJECT*)0x02EE27F0 = object_02AE27F0;
	*(NJS_OBJECT*)0x02EE25AC = object_02AE25AC;
	*(NJS_OBJECT*)0x02EE22C0 = object_02AE22C0;
	*(NJS_OBJECT*)0x02EE1804 = object_02AE1804;
	*(NJS_OBJECT*)0x02EE1584 = object_02AE1584;
	*(NJS_OBJECT*)0x02EE12C8 = object_02AE12C8;
	*(NJS_OBJECT*)0x02EE11DC = object_02AE11DC;
	*(NJS_OBJECT*)0x02EE10DC = object_02AE10DC;
	*(NJS_OBJECT*)0x02EE0FB4 = object_02AE0FB4;
	*(NJS_OBJECT*)0x02EE0EA0 = object_02AE0EA0;
	*(NJS_OBJECT*)0x02EE0DB4 = object_02AE0DB4;
	*(NJS_OBJECT*)0x02EE0CB4 = object_02AE0CB4;
	*(NJS_OBJECT*)0x02EE0B8C = object_02AE0B8C;
	WriteData((WeldInfo**)0x006F08FB, (WeldInfo*)&EventEggmobileWeldInfo_DX);
}

void Init_Tikal()
{
	*(NJS_MOTION*)0x8EE3D0 = animation_004EE3D0;
	WriteData((NJS_OBJECT**)0x007B37EA, ((NJS_OBJECT*)0x8D4880)->getnode(50));
	WriteData((NJS_OBJECT**)0x007B37F1, ((NJS_OBJECT*)0x8D4880)->getnode(54));
}

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		EnableAmy = config->getBool("Characters", "EnableAmy", true);
		EnableEggman = config->getBool("Characters", "EnableEggman", true);
		EnableTikal = config->getBool("Characters", "EnableTikal", true);
		EnableMetal = config->getBool("Characters", "EnableMetal", true);
		EnableDXChao = config->getBool("Characters", "EnableChao", true);
		
		if (EnableAmy)
		{
			ReplaceEXEData("KidnappedAmy", path, helperFunctions);
			Init_KidAmy();
			ReplacePVM("amy_eggrobo", "amy_eggrobo_dx");
			ReplacePVM("amy_eggrobo_dc", "amy_eggrobo_dx");
		}

		if (EnableEggman)
		{
			ReplaceEXEData("eggman", path, helperFunctions);
			std::string fullPath = path + (std::string)"\\eg_jvlist.ini";
			helperFunctions.RegisterCharacterWelds(Characters_Eggman, fullPath.c_str());
			Init_Eggman();
			ReplacePVM("eggman", "eggman_dx");
			ReplacePVM("ev_eggman_body", "eggman_dx");
			ReplacePVM("chaos6_eggman", "chaos6_eggman_dx");
			ReplacePVM("egm1eggman", "eggman_dx");
			ReplacePVM("egm2_common", "egm2_common_dx");
			ReplacePVM("egm3mdl", "egm3mdl_dx");
			ReplacePVM("ev_eggmoble0", "ev_eggmoble0_dx");
			ReplacePVM("mrace_eggmoble", "mrace_eggmoble_dx");
			ReplacePVM("eggman_dc", "eggman_dx");
			ReplacePVM("ev_eggman_body_dc", "eggman_dx");
			ReplacePVM("chaos6_eggman_dc", "chaos6_eggman_dx");
			ReplacePVM("egm1eggman_dc", "eggman_dx");
			ReplacePVM("egm2_common_dc", "egm2_common_dx");
			ReplacePVM("egm3mdl_dc", "egm3mdl_dx");
			ReplacePVM("ev_eggmoble0_dc", "ev_eggmoble0_dx");
			ReplacePVM("mrace_eggmoble_dc", "mrace_eggmoble_dx");
		}

		if (EnableTikal)
		{
			ReplaceEXEData("tikal", path, helperFunctions);
			std::string fullPath = path + (std::string)"\\ti_jvlist.ini";
			helperFunctions.RegisterCharacterWelds(Characters_Tikal, fullPath.c_str());
			Init_Tikal();
			ReplacePVM("tikal", "tikal_dx");
			ReplacePVM("tikal_dc", "tikal_dx");
		}
		
		if (EnableMetal)
		{
			ReplaceEXEData("metal", path, helperFunctions);
			ReplacePVM("ev_s_msbody", "ev_s_msbody_dx");
			ReplacePVM("ev_s_msbody_dc", "ev_s_msbody_dx");
		}
		
		if (EnableDXChao)
		{
			ReplaceEXEData("adv03_dll_data", path, helperFunctions);
			ReplacePVM("ev_alife", "ev_alife_dx");
			ReplacePVM("ev_alife_dc", "ev_alife_dx");
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}