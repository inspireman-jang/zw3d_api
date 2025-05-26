/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

#include "..\inc\MatrixOperationsPr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int MatrixOperationsInit()
    {
    RegisterFormCommand();
    return 0;
    }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int MatrixOperationsExit()
    {
    UnloadFormCommand();
    return 0;
    }