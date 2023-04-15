#include "eMagesPatch.h"
#include "core.h"
void eMagesPatch::InitHooks()
{
	Patch<const char*>(0x421B55 + 1, "MagesPatch");
}

