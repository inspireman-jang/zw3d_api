#include "..\inc\ExTrudewithPreviewPr.h"

// Dynamic library entry function, called when the dll is loaded
// The function name must be dll name + "Init"
int ExTrudewithPreviewInit()
   {
   RegisterExTrudewithPreview();
   return 0;
   }

// Dynamic library entry function, called when the dll is unloaded
// The function name must be dll name + "Exit"
int ExTrudewithPreviewExit()
   {
   UnloadExTrudewithPreview();
   return 0;
   }