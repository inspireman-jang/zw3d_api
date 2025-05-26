/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

/*******************************************************************/
/* ZW3D API includes */
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"
#include "zwapi_layer.h"
#include "zwapi_general_ent.h"


/*******************************************************************/
/* Application includes */
#include <string>
#include "stdlib.h"
#include "..\inc\EntityNamePr.h"

/*******************************************************************/
/* Data type definitions */
/* DESCRIPTION: form field id */
enum EntityNameField
    {
    Field_Number_Start = 4,    /* start number of the layer */
    Field_Number_End = 5,      /* end number of the layer */
    Field_Name_Label = 6,      /* name label*/
    Field_Name_Number = 7,     /* name number */
    };

/*******************************************************************/
/* Function declarations */
static int EntityName(int idData);

/*******************************************************************/
/* Function definition */
int RegisterEntityName(void)
/*
DESCRIPTION:
   Register callback function of template command.
*/
   {
   /* Start the command by entering command string "!EntityName" */
    ZwCommandFunctionLoad("EntityName", (void*)EntityName, ZW_LICENSE_CODE_GENERAL);
   return 0;
   }

/*******************************************************************/
/* Function definition */
int UnloadEntityName(void)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
   {
    ZwCommandFunctionUnload("EntityName");
   return 0;
   }

/*******************************************************************/
/* Function definition */
int EntityName
(
   int idData    /* I: index of data container */
)
/*
DESCRIPTION:
   Execution function of command. the function is called when the command
is clicked on the OK or APPLY button.
*/
   {
   // TODO: Do something

   cvxMsgDisp("EntityName");

   double startLayer = 0, endLayer = 0, nameNumber = 0;
   if (cvxDataGetNum(idData, Field_Number_Start, &startLayer))
       return 1;
   if (cvxDataGetNum(idData, Field_Number_End, &endLayer))
       return 1;
   if (cvxDataGetNum(idData, Field_Name_Number, &nameNumber))
       return 1;

   svxData label{};
   if (cvxDataGet(idData, Field_Name_Label, &label))
       return 1;

   int exitLayerCnt = 0;
   vxName* layerName = nullptr;
   if (cvxLayerList(&exitLayerCnt, &layerName))
       return 1;

   ezwErrors err = ZW_API_NO_ERROR;
   for (int i = startLayer; i <= endLayer; i++)
       {
       if (cvxLayerExists2(i))
           {
           int numEntInCurLayer = 0;
           svxEntPath* entPathList = nullptr;
           cvxLayerInqEnts(i, &numEntInCurLayer, &entPathList);

           szwEntityHandle* entityList = nullptr;
           ZwMemoryAlloc(numEntInCurLayer*sizeof(szwEntityHandle),(void**)&entityList);
           if(ZwEntityPathTransfer(numEntInCurLayer,entPathList, entityList))
               return 1;

           for (int j = 0; j < numEntInCurLayer; j++)
               {
               std::string strname = label.Text + std::to_string((int)nameNumber);
               if(ZwEntityNameSet(entityList[j], strname.c_str()))
                   return 1;
               if (ZwEntityNameTagSet(entityList[j], strname.c_str()))
                   return 1;
               }
           for (int j = 0; j < numEntInCurLayer; j++)
               ZwEntityHandleFree(&entityList[j]);
           }
       nameNumber++;
       }

   return 0;
   }
