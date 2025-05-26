/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

/*******************************************************************/
/* ZW3D API includes */
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"
#include "zwapi_feature_shape.h"
#include "zwapi_matrix_data.h"
#include "zwapi_general_ent.h"
#include "zwapi_part_facets.h"
#include "zwapi_face.h"
#include "zwapi_display.h"

/*******************************************************************/
/* Application includes */
#include "..\inc\ColoredBoxPr.h"

/*******************************************************************/
/* Data type definitions */
/* DESCRIPTION: form field id */
enum BoxedColorField
    {
    Field_Length = 1,    /* length of the box */
    Field_Width = 2,     /* width of the box */
    Field_Height = 3,    /* height of the box */
    Field_Origin = 4,    /* origin point of the box */
    Field_Color = 5,     /* color of the box */
    };

/*******************************************************************/
/* Function declarations */
static int ColoredBox(int idData);
static void ColoredBoxEcho(int idData, void* ohEcho);
static int ColoredBoxCb(char* form, int idField, int item);

/*******************************************************************/
/* Function definition */
int RegisterColoredBox(void)
/*
DESCRIPTION:
   Register callback function of template command.
*/
   {
   /* Start the command by entering command string "!ColoredBox" */
   ZwCommandFunctionLoad("ColoredBox", (void*)ColoredBox, ZW_LICENSE_CODE_GENERAL);
   ZwCommandCallbackLoad("ColoredBoxEcho", (void*)ColoredBoxEcho);

   /* Register callback function of form */
   ZwCommandCallbackLoad("ColoredBoxCb", (void*)ColoredBoxCb);
   return 0;
   }

/*******************************************************************/
/* Function definition */
int UnloadColoredBox(void)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
   {
    ZwCommandFunctionUnload("ColoredBox");
    ZwCommandFunctionUnload("ColoredBoxEcho");
    ZwCommandFunctionUnload("ColoredBoxCb");
   return 0;
   }

/*******************************************************************/
/* Function definition */
int ColoredBox
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

   cvxMsgDisp("ColoredBox");
   cvxEchoEnd();
   /* Inquire data of data container */
   svxData filedData[4] = {};
   szwCenterBoxData boxData{};
   if (ZwFeatureCenterBoxDataInit(&boxData))
       return 1;

   for (int i = Field_Length; i < Field_Color; i++)
       {
       if (cvxDataGet(idData, i, &filedData[i - 1]))
           return 1;
       switch (i)
           {
           case Field_Length:
               boxData.x = filedData[i - 1].Num;
               break;
           case Field_Width:
               boxData.y= filedData[i - 1].Num;
               break;
           case Field_Height:
               boxData.z = filedData[i - 1].Num;
               break;
           case Field_Origin:
               boxData.center = filedData[i - 1].Pnt;
               break;
           default:
               break;
           }
       }

   int count = 0;
   szwEntityHandle* boxList = nullptr;

   if(ZwFeatureBoxCreateByCenter(boxData,&count,&boxList))
       return 1;

   szwFaceDisplayAttribute dispAt{};
   if (ZwFaceDisplayAttributeGet(boxList[0], &dispAt))
       return 1;
   svxColor color{};
   cvxDataGetColor(idData, Field_Color, &color);
   dispAt.frontColor = color;

   if(ZwFaceDisplayAttributeSet(count, boxList, dispAt))
       return 1;

   ZwEntityHandleListFree(count, &boxList);

   return 0;
   }

/*******************************************************************/
/* Function definition */
void ColoredBoxEcho
(
   int idData,   /* I: index of data container */
   void* ohEcho  /* I: handle of preview object */
)
/*
DESCRIPTION:
   Preview callback function of command, the function is called when the parameters
of command change.
*/
   {
   cvxEchoStart();

   // TODO: Do something
   cvxMsgDisp("ColoredBoxEcho");
   /* Inquire data of data container */
   svxData filedData[4] = {};
   szwCenterBoxData boxData{};
   if (ZwFeatureCenterBoxDataInit(&boxData))
       return ;

   for (int i = Field_Length; i < Field_Color; i++)
       {
       if (cvxDataGet(idData, i, &filedData[i - 1]))
           return ;
       switch (i)
           {
           case Field_Length:
               boxData.x = filedData[i - 1].Num;
               break;
           case Field_Width:
               boxData.y = filedData[i - 1].Num;
               break;
           case Field_Height:
               boxData.z = filedData[i - 1].Num;
               break;
           case Field_Origin:
               boxData.center = filedData[i - 1].Pnt;
               break;
           default:
               break;
           }
       }

   int count = 0;
   szwEntityHandle* boxList = nullptr;

   if (ZwFeatureBoxCreateByCenter(boxData, &count, &boxList))
       return ;

   ZwEntityHandleListFree(count, &boxList);

   cvxEchoEnd();
   return;
   }

/*******************************************************************/
/* Function definition */
int ColoredBoxCb
(
   char* formName,    /* I: form name */
   int idField,       /* I: index of command parameter field */
   int idData         /* I: index of data container */
)
/*
DESCRIPTION:
   Callback function of command parameter field, the function is called when value
of the specify parameter field changes.
*/
   {
   // TODO: Do something

   cvxMsgDisp("ColoredBoxCb");

   int idxIn(idData);
   int ret(0);
   int iCmpNoAtFlag = false;
   if (idField == Field_Color)
       {
       svxColor color{};
       if(cvxDataGetColor(idData, Field_Color, &color))
           return 1;
       cvxDispRgbSet(VX_DISP_FACE, &color);
       cvxEchoDraw();
       }
   return 0;
   }
