/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

#include "..\inc\ChamferAddAndDeletePr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int ChamferAddAndDeleteInit()
   {
   RegisterChamferAddAndDelete();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int ChamferAddAndDeleteExit()
   {
   UnloadChamferAddAndDelete();
   return 0;
   }