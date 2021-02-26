// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MemoryMgr.h"
#include "code/eCheatsExpander.h"
using namespace Memory::VP;

void Init()
{
	eCheatsExpander::Init();
}

extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		Init();
	}
}
