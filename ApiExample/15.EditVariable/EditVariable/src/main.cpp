/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

#include "..\inc\EditVariablePr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int EditVariableInit()
   {
   RegisterEditVariable();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int EditVariableExit()
   {
   UnloadEditVariable();
   return 0;
   }