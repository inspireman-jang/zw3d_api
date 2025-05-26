#include "..\inc\LayerEntityManagerPr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int LayerEntityManagerInit()
   {
   RegisterLayerEntityManager();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int LayerEntityManagerExit()
   {
   UnloadLayerEntityManager();
   return 0;
   }