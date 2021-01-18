#include "native.h"

cell AMX_NATIVE_CALL Native::ProjectZ(AMX* amx, cell* params)
{
	int a = static_cast<int>(params[1]);
	int b = static_cast<int>(params[2]);
	return static_cast<cell>(a + b);
}