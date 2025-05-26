/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

/*******************************************************************/
/* ZW3D API includes */
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"

#include "zwapi_feature_shape.h"
#include "zwapi_cmd_shape.h"
#include "zwapi_cmd_freeform.h"
#include "zwapi_cmd_wireframe.h"
#include "zwapi_general_ent.h"
#include "zwapi_feature_wireframe.h"
#include "zwapi_entity.h"


/*******************************************************************/
/* Application includes */
#include "..\inc\ExTrudewithPreviewPr.h"
#include <vector>

/*******************************************************************/
/* Data type definitions */
/* DESCRIPTION: form field id */
enum ExTrudewithPreviewField
    {
    Field_PROFILE = 1,
    Field_START_DISTANCE = 2,
    Field_END_DISTANCE = 3,
    Field_DIRECTION = 4,
    };

/*******************************************************************/
/* Function declarations */
static int ExTrudewithPreview(int idData);
static void ExTrudewithPreviewInit(int idData);
static void ExTrudewithPreviewEcho(int idData, void* ohEcho);

int RegisterExTrudewithPreview(void)
/*
DESCRIPTION:
   Register callback function of template command.
*/
    {
    /* Start the command by entering command string "!ExTrudewithPreview" */
    ZwCommandFunctionLoad("ExTrudewithPreview", (void*)ExTrudewithPreview, ZW_LICENSE_CODE_GENERAL);
    ZwCommandCallbackLoad("ExTrudewithPreviewInit", (void*)ExTrudewithPreviewInit);
    ZwCommandCallbackLoad("ExTrudewithPreviewEcho", (void*)ExTrudewithPreviewEcho);
    return 0;
    }

int UnloadExTrudewithPreview(void)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
   {
   ZwCommandFunctionUnload("ExTrudewithPreview");
   ZwCommandFunctionUnload("ExTrudewithPreviewInit");
   ZwCommandFunctionUnload("ExTrudewithPreviewEcho");
   return 0;
   }

int ExTrudewithPreview
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

   cvxMsgDisp("ExTrudewithPreview");

   /* Inquire data of data container */
   svxFldData* fldData = nullptr;
   int numField = 0;
   if (cvxDataGetAll(idData, &numField, &fldData))
       return 1;

   if (numField >= 3 && fldData[0].count > 0)
       {
       std::vector<szwEntityHandle> curves{};
       std::vector<szwEntityHandle> curveList{};
       std::vector<szwEntityHandle> sketches{};
       std::vector<szwEntityHandle> sketch3Ds{};
       int entCount = fldData[0].count;

       /*classify*/
       for (int i = 0; i < entCount; i++)
           {
           int idEnt = 0;
           idEnt = fldData[0].fld_data[i].idEntity;
           szwEntityHandle tempEnt{};
           ZwEntityIdTransfer(1, &idEnt, &tempEnt);

           int isCurve = 0;
           ezwEntityType type = ZW_ENTITY_ALL;
           if(ZwEntityTypeNumberGet(tempEnt, &type))
               return 1;
           ZwEntityCurveCheck(tempEnt, &isCurve);
           if (type == ZW_ENTITY_CURVE_LIST)
               {
               curveList.push_back(tempEnt);
               }
           else if (type != ZW_ENTITY_CURVE_LIST && isCurve )
               {
               curves.push_back(tempEnt);
               }
           else if (type == ZW_ENTITY_SKETCH)
               {
               sketches.push_back(tempEnt);
               }
           else if (type == ZW_ENTITY_SKETCH_3D)
               {
               sketch3Ds.push_back(tempEnt);
               }
           }

       /*init*/
       szwExtrudeData extrudeData{};
       if (ZwFeatureExtrudeInit(&extrudeData))
           return 1;
       extrudeData.startS = fldData[1].fld_data->Num;
       extrudeData.endE = fldData[2].fld_data->Num;
       if (numField == 4)
           extrudeData.direction = (szwVector)fldData[3].fld_data->Dir;

       /*EXTRUDE*/
       if (curves.size() > 0)
           {
           szwEntityHandle crvList{};
           if (ZwFeatureCurvelistCreate(curves.size(), curves.data(), &crvList))
               return 1;

           extrudeData.profileHandle = crvList;
           szwEntityHandle shape{};
           if (ZwFeatureExtrudeCreate(extrudeData, &shape))
               return 1;
           ZwEntityHandleFree(&crvList);
           ZwEntityHandleFree(&shape);
           }

       for (int i = 0; i < curveList.size(); i++)
           {
           extrudeData.profileHandle = curveList[i];
           szwEntityHandle shape{};
           if (ZwFeatureExtrudeCreate(extrudeData, &shape))
               return 1;
           ZwEntityHandleFree(&shape);       
           ZwEntityHandleFree(&curves[i]);
           }

       for (int i = 0; i < sketches.size(); i++)
           {
           extrudeData.profileHandle = sketches[i];
           szwEntityHandle shape{};
           if (ZwFeatureExtrudeCreate(extrudeData, &shape))
               return 1;
           ZwEntityHandleFree(&shape);
           ZwEntityHandleFree(&sketches[i]);
           }

       for (int i = 0; i < sketch3Ds.size(); i++)
           {
           extrudeData.profileHandle = sketch3Ds[i];
           szwEntityHandle shape{};
           if (ZwFeatureExtrudeCreate(extrudeData, &shape))
               return 1;
           ZwEntityHandleFree(&shape);
           ZwEntityHandleFree(&sketch3Ds[i]);
           }

       }

   return 0;
   }

void ExTrudewithPreviewEcho
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

    cvxMsgDisp("ExTrudewithPreviewEcho");
    svxFldData* fldData = nullptr;
    int numField = 0;
    if (cvxDataGetAll(idData, &numField, &fldData))
        return;

    if (numField >= 3 && fldData[0].count > 0)
        {
        std::vector<int> curves{};
        std::vector<szwEntityHandle> curveList{};
        std::vector<szwEntityHandle> sketches{};
        std::vector<szwEntityHandle> sketch3Ds{};
        int entCount = fldData[0].count;

        /*classify*/
        for (int i = 0; i < entCount; i++)
            {
            int idEnt = 0;
            idEnt = fldData[0].fld_data[i].idEntity;
            szwEntityHandle tempEnt{};
            ZwEntityIdTransfer(1, &idEnt, &tempEnt);

            int isCurve = 0;
            ezwEntityType type = ZW_ENTITY_ALL;
            if (ZwEntityTypeNumberGet(tempEnt, &type))
                return;
            ZwEntityCurveCheck(tempEnt, &isCurve);
            if (type == ZW_ENTITY_CURVE_LIST)
                {
                curveList.push_back(tempEnt);
                }
            else if (type != ZW_ENTITY_CURVE_LIST && isCurve)
                {
                curves.push_back(idEnt);
                }
            else if (type == ZW_ENTITY_SKETCH)
                {
                sketches.push_back(tempEnt);
                }
            else if (type == ZW_ENTITY_SKETCH_3D)
                {
                sketch3Ds.push_back(tempEnt);
                }
            }


        szwExtrudeData extrudeData{};
        if (ZwFeatureExtrudeInit(&extrudeData))
            return ;
        extrudeData.startS = fldData[1].fld_data->Num;
        extrudeData.endE = fldData[2].fld_data->Num;
        if (numField == 4)
            extrudeData.direction = (szwVector)fldData[3].fld_data->Dir;

        /*EXTRUDE*/
        if (curves.size() > 0)
            {
            szwEntityHandle crvList{};
            int idCrvlist = 0;
            if (cvxPartCrvList(curves.size(), curves.data(), &idCrvlist))
                return;

            if(ZwEntityIdTransfer(1, &idCrvlist, &crvList))
                return;

            extrudeData.profileHandle = crvList;
            if (ZwFeatureExtrudeCreate(extrudeData, NULL))
                return;

            ZwEntityHandleFree(&crvList);
            }

        for (int i = 0; i < curveList.size(); i++)
            {
            extrudeData.profileHandle = curveList[i];
            if (ZwFeatureExtrudeCreate(extrudeData, NULL))
                return;
            }

        for (int i = 0; i < sketches.size(); i++)
            {
            extrudeData.profileHandle = sketches[i];
            if (ZwFeatureExtrudeCreate(extrudeData, NULL))
                return;
            ZwEntityHandleFree(&sketches[i]);
            }

        for (int i = 0; i < sketch3Ds.size(); i++)
            {
            extrudeData.profileHandle = sketch3Ds[i];
            if (ZwFeatureExtrudeCreate(extrudeData, NULL))
                return;
            ZwEntityHandleFree(&sketch3Ds[i]);
            }

        }

    cvxEchoEnd();
    }

void ExTrudewithPreviewInit
(
   int idData    /* I: index of data container */
)
/*
DESCRIPTION:
   Initialize callback function of command. the function is called when the command
is initialized. In this callback function, you can initialize the data of command, 
but the command form has not yet been created at this time, so should not initialize
the command form in this callback function.
*/
   {
   // TODO: Do something
   svxData endDis{};
   endDis.isNumber = 1;
   endDis.Num = 15;
   endDis.NumType = VX_DST;
   cvxDataSet(idData, Field_END_DISTANCE, &endDis);

   svxData stDis{};
   stDis.isNumber = 1;
   stDis.Num = 0;
   stDis.NumType = VX_DST;
   cvxDataSet(idData, Field_START_DISTANCE, &stDis);

   cvxMsgDisp("ExTrudewithPreviewInit");
   }

