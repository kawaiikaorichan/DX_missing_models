#include "pch.h"
#include "KidnappedAmy.h"
#include "Tikal.h"
#include "Eggman.h"

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

void Init_Tikal()
{
	WriteData((NJS_OBJECT**)0x007B33A0, &object_004D484C);
	TikalWeldInfo[6].ModelA = &object_004D2D04;
	TikalWeldInfo[6].ModelB = &object_004D2EF8;
	TikalWeldInfo[6].VertexPairCount = 7;
	TikalWeldInfo[6].VertIndexes = (unsigned short*)&Tikal_Feet_DX;
	TikalWeldInfo[7].ModelA = &object_004D397C;
	TikalWeldInfo[7].ModelB = &object_004D3B70;
	TikalWeldInfo[7].VertexPairCount = 7;
	TikalWeldInfo[7].VertIndexes = (unsigned short*)&Tikal_Feet_DX;
}

void Init_Eggman()
{
	WriteData((NJS_OBJECT**)0x0089E254, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008A094C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008A3564, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008A513C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008A6BF4, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008A8A9C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008AC3F4, &object_0049C830);
	WriteData((NJS_OBJECT**)0x008B1CCC, &object_0049C830);
	WriteData((NJS_OBJECT**)0x0111B72C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D00DF4, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D027EC, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D03974, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D06F6C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D08DF4, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D0AC0C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02D64FBC, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02F9470C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x02FDF18C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x0303D284, &object_0049C830);
	WriteData((NJS_OBJECT**)0x0303EE9C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x03041A44, &object_0049C830);
	WriteData((NJS_OBJECT**)0x0304E9AC, &object_0049C830);
	WriteData((NJS_OBJECT**)0x030C3AD4, &object_0049C830);
	WriteData((NJS_OBJECT**)0x030C62BC, &object_0049C830);
	WriteData((NJS_OBJECT**)0x030C7E34, &object_0049C830);
	WriteData((NJS_OBJECT**)0x03136234, &object_0049C830);
	WriteData((NJS_OBJECT**)0x0313EB3C, &object_0049C830);
	WriteData((NJS_OBJECT**)0x03141254, &object_0049C830);
	WriteData((NJS_OBJECT**)0x03142C4C, &object_0049C830);
	WriteData((WeldInfo**)0x007B4FBF, (WeldInfo*)&EggmanWeldInfo_DX);

	//Eggman in Eggmobile for cutscenes (EV_EGGMOBLE0)
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
		
		Init_Eggman();

		ReplacePVM("amy_eggrobo", "amy_eggrobo_dx");
		ReplacePVM("tikal", "tikal_dx");
		ReplacePVM("eggman", "eggman_dx");
		ReplacePVM("ev_eggmoble0", "ev_eggmoble0_dx");

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