#include "..\inc\EntityNamePr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int EntityNameInit()
   {
   RegisterEntityName();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int EntityNameExit()
   {
    UnloadEntityName();
   return 0;
   }