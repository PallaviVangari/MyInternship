#pragma once

#pragma once
#ifdef CREATING_DLL_EXPORTS    
#define CREATING_DLLAPI extern "C" __declspec(dllexport)
#else
#define CREATING_DLLAPI extern "C" __declspec(dllimport)
#endif

CREATING_DLLAPI int add( int nLeft, int nRight );
CREATING_DLLAPI int sub( int nLeft, int nRight );
