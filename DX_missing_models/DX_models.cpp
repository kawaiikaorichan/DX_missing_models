#include "pch.h"
#include "KidnappedAmy.h"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum Amy { DXoriginal, LikeDream, DXcleanshoes, DCtext };

static int AmyText = DXoriginal;

void Init_KidAmy()
{
	//Head
	*(NJS_MODEL_SADX*)0x0319F6E8 = attach_02D9F6E8;
	WriteData((NJS_MOTION**)0x031C1C7C, &head_motion);
	//Body
	WriteData((NJS_OBJECT**)0x031AD68C, &object_02D9C3EC);

}

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		//Choose textures
		std::string AmyText_String = "LikeDream";
		AmyText_String = config->getString("Textures", "Kidnapped Amy", "LikeDream");

		if (AmyText_String == "DXoriginal") AmyText = DXoriginal;
		if (AmyText_String == "DXcleanshoes") AmyText = DXcleanshoes;
		if (AmyText_String == "LikeDream") AmyText = LikeDream;
		if (AmyText_String == "DCtext") AmyText = DCtext;

		Init_KidAmy();

		ReplacePVM("amy_eggrobo", "amy_eggrobo_dx");

		if (AmyText == DXcleanshoes)
		{
			//Legs
			((NJS_OBJECT*)0x319900C)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x31982A4)->basicdxmodel->mats[0].attr_texId = 11;
			//Shoes
			((NJS_OBJECT*)0x3197B9C)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x3197EF4)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x31988FC)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x3198C54)->basicdxmodel->mats[0].attr_texId = 11;
		}

		if (AmyText == LikeDream)
		{
			//Head
			((NJS_OBJECT*)0x319F714)->basicdxmodel->mats[1].attr_texId = 8;
			((NJS_OBJECT*)0x319F714)->basicdxmodel->mats[2].attr_texId = 1;
			//Dress
			((NJS_OBJECT*)0x3197380)->basicdxmodel->mats[2].attr_texId = 8;
			//Arms
			((NJS_OBJECT*)0x319A2AC)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x31992BC)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319A43C)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319944C)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319AFD8)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319AFD8)->basicdxmodel->mats[1].attr_texId = 15;
			((NJS_OBJECT*)0x3199860)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x3199860)->basicdxmodel->mats[1].attr_texId = 15;
			//Legs
			((NJS_OBJECT*)0x319853C)->basicdxmodel->mats[0].attr_texId = 8;
			((NJS_OBJECT*)0x31977DC)->basicdxmodel->mats[0].attr_texId = 8;
			((NJS_OBJECT*)0x31986CC)->basicdxmodel->mats[0].attr_texId = 8;
			((NJS_OBJECT*)0x319796C)->basicdxmodel->mats[0].attr_texId = 8;
			((NJS_OBJECT*)0x319900C)->basicdxmodel->mats[0].attr_texId = 12;
			((NJS_OBJECT*)0x319900C)->basicdxmodel->mats[1].attr_texId = 8;
			((NJS_OBJECT*)0x31982A4)->basicdxmodel->mats[0].attr_texId = 12;
			((NJS_OBJECT*)0x31982A4)->basicdxmodel->mats[1].attr_texId = 8;
			//Tail
			((NJS_OBJECT*)0x31975B0)->basicdxmodel->mats[0].attr_texId = 8;
			//Shoes
			((NJS_OBJECT*)0x3197B9C)->basicdxmodel->mats[0].attr_texId = 12;
			((NJS_OBJECT*)0x3197EF4)->basicdxmodel->mats[0].attr_texId = 12;
			((NJS_OBJECT*)0x31988FC)->basicdxmodel->mats[0].attr_texId = 12;
			((NJS_OBJECT*)0x3198C54)->basicdxmodel->mats[0].attr_texId = 12;
		}

		if (AmyText == DCtext)
		{
			//Head
			((NJS_OBJECT*)0x319F714)->basicdxmodel->mats[1].attr_texId = 7;
			((NJS_OBJECT*)0x319F714)->basicdxmodel->mats[2].attr_texId = 1;
			//Dress
			((NJS_OBJECT*)0x3197380)->basicdxmodel->mats[2].attr_texId = 7;
			//Arms
			((NJS_OBJECT*)0x319A2AC)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x31992BC)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319A43C)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319944C)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319AFD8)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x319AFD8)->basicdxmodel->mats[1].attr_texId = 14;
			((NJS_OBJECT*)0x3199860)->basicdxmodel->mats[0].attr_texId = 1;
			((NJS_OBJECT*)0x3199860)->basicdxmodel->mats[1].attr_texId = 14;
			//Legs
			((NJS_OBJECT*)0x319853C)->basicdxmodel->mats[0].attr_texId = 7;
			((NJS_OBJECT*)0x31977DC)->basicdxmodel->mats[0].attr_texId = 7;
			((NJS_OBJECT*)0x31986CC)->basicdxmodel->mats[0].attr_texId = 7;
			((NJS_OBJECT*)0x319796C)->basicdxmodel->mats[0].attr_texId = 7;
			((NJS_OBJECT*)0x319900C)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x319900C)->basicdxmodel->mats[1].attr_texId = 7;
			((NJS_OBJECT*)0x31982A4)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x31982A4)->basicdxmodel->mats[1].attr_texId = 7;
			//Tail
			((NJS_OBJECT*)0x31975B0)->basicdxmodel->mats[0].attr_texId = 7;
			//Shoes
			((NJS_OBJECT*)0x3197B9C)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x3197EF4)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x31988FC)->basicdxmodel->mats[0].attr_texId = 11;
			((NJS_OBJECT*)0x3198C54)->basicdxmodel->mats[0].attr_texId = 11;
		}
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}