#include "eCheatsExpander.h"
#include "core.h"
char* szCheats[] =
{
	// default
   "iamgreatcornholio","arisemywarriors",
   "greatmage","perfectwarrior",
   "brainstorm","EasyWin","ShamefulLoss",
   "gimmegimmegimme",
   // cut cheats?
   "bmshuttle", "givetoradiskull", "god",
   // Mages Patch
   "SetMagicDark","SetMagicBlue","SetMagicGreen" , "SetMagicRed",
   "GiveLP","GiveMana","GiveExp",
   // Spawn Cheats
   "GetMilitia",
   "GetSwordsman",
   "GetPaladin",
   "GetKnight",
   "GetEmperor",
   "GetBrigand",
   "GetHunter",
   "GetFreelancer",
   "GetHeadHunter",
   "GetMagician",
   "GetMage",
   "GetBattleMage",
   "GetZoragon",
   "GetWildMage",
   "GetNecromancer",
   "GetGuru",
   "GetCaravan",
   "GetCivilian",
   "GetCivilian2",
   "GetGiant",
   "GetWarrior",
   "GetMasterWarrior",
   "GetForestGuardian",
   "GetUOakMonster",
   "GetArcher",
   "GetMasterArcher",
   "GetSniper",
   "GetAiron",
   "GetEnchanter",
   "GetMasterEnchanter",
   "GetElementalist",
   "GetTailon",
   "GetTailonWand",
   "GetForestSpirit",
   "GetForestSpiritBad",
   "GetPike",
   "GetSpear",
   "GetHalberdier",
   "GetBomber",
   "GetBalista",
   "GetTank",
   "GetScout",
   "GetSpy",
   "GetStalker",
   "GetStrategist",
   "GetGoblinCivilian",
   "GetGoblinCivilian2",
   "GetGramb",
   "GetFighter",
   "GetBerserker",
   "GetWarlord",
   "GetRaider",
   "GetMarauder",
   "GetBandit",
   "GetCrusher",
   "GetWildCrusher",
   "GetShaman",
   "GetDarkShaman",
   "GetBloodShaman",
   "GetDarkShaman",
   "GetOrcCaravan",
   "GetOrcCivilian",
   "GetOrcCivilian2",
   "GetSmallSkeleton",
   "GetSkeleton",
   "GetZombie",
   "GetLycanthrop",
   "GetBlackWarrior",
   "GetSteelZombie",
   "GetDeath",
   "GetOrcSkeleton",
   "GetGoblinSkeleton",
   "GetAcolyte",
   "GetHorrorMage",
   "GetHroll",
   "GetGarthog",
   "GetNatureEl",
   "GetEnergyEl",
   "GetChaosEl",
   "GetDrago",
   "GetMagma",
   "GetAnimals",
   "GetVorogs",
   "GetMonsters"

};

void eCheatsExpander::Init()
{
	unsigned char cheatsAmount = sizeof(szCheats) / sizeof(szCheats[0]);


	Patch<unsigned char>(0x46C8EA + 2, cheatsAmount);
	InjectHook(0x46C739, InitHook, PATCH_JUMP);

}

void __declspec(naked) eCheatsExpander::InitHook()
{
	static int cht_jmp = 0x46C743;
	_asm {
		mov     ecx, [esp + 10h]
		mov     esi, [szCheats + ecx * 4]
		push    esi
		lea     ecx, [esp + 60]
		mov     eax, 0x401460
		call    eax
		jmp     cht_jmp
		popad
	}
}
