#include "M3DString.h"

M3DString::M3DString(char * name)
{
#ifndef BM_OLD
	CallMethod<0x401460, M3DString*, char*>(this, name);
#endif // !BM_OLD


}
