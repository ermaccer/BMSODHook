// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "code/eCheatsExpander.h"
#include "code/eMagesPatch.h"
using namespace Memory::VP;

void Init()
{
#ifndef BM_OLD
	eMagesPatch::InitHooks();
#endif // !BM_OLD

	eCheatsExpander::Init();
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}
