/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

/*******************************************************************/
/* ZW3D API includes */
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"
#include "zwapi_layer.h"
#include "zwapi_ui_form.h"
#include "zwapi_entity.h"
#include "zwapi_global_apply.h"

/*******************************************************************/
/* Application includes */
#include "..\inc\LayerEntityManagerPr.h"
#include <string>
#include <vector>

/*******************************************************************/
/* Application includes */
#define FormName "LayerEntityManager"

/*******************************************************************/
/* Data type definitions */
/* DESCRIPTION: form field id */
enum LayerEntityManagerField
    {
    Field_Layer = 1,                  /* layer */
    Field_EntityList = 2,             /* length of the box */
    Field_Color = 3,                  /* entity color */
    };

/*******************************************************************/
/* Function declarations */
static int LayerEntityManager(int idData);
static int LayerEntityManagerInitA(int idData);

/*******************************************************************/
/* Function definition */
int RegisterLayerEntityManager(void)
/*
DESCRIPTION:
   Register callback function of template command.
*/
    {
    /* Start the command by entering command string "!LayerEntityManager" */
    ZwCommandFunctionLoad("LayerEntityManager", (void*)LayerEntityManager, ZW_LICENSE_CODE_GENERAL);
    ZwCommandCallbackLoad("LayerEntityManagerInitA", (void*)LayerEntityManagerInitA);
    return 0;
    }

/*******************************************************************/
/* Function definition */
int UnloadLayerEntityManager(void)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
    {
    ZwCommandFunctionUnload("LayerEntityManager");
    ZwCommandFunctionUnload("LayerEntityManagerInitA");
    return 0;
    }

/*******************************************************************/
/* Function definition */
int LayerEntityManager
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

    cvxMsgDisp("LayerEntityManager");
    /*ui data get -- layer*/
    int idOpt = cvxDataGetOpt(idData, Field_Layer);
    zwString64 layerName{};
    if (ZwUiFormItemGet(FormName, Field_Layer, idOpt, sizeof(zwString64), layerName))
        return 1;
    /*ui data get -- entity list*/
    int nEnts = 0, * idEnts = 0;
    if (cvxDataGetEnts(idData, Field_EntityList, &nEnts, &idEnts))
        return 1;
    szwEntityHandle* ents = nullptr;
    ZwMemoryAlloc(nEnts * sizeof(szwEntityHandle), (void**)&ents);
    if (ZwEntityIdTransfer(nEnts, idEnts, ents))
        return 1;
    /*ui data get -- color*/
    svxColor inputRGB{};
    if (cvxDataGetColor(idData, Field_Color, &inputRGB))
        return 1;

    /*assign entities to the selected layer*/
    if (cvxLayerAssign(layerName, nEnts, idEnts))
        return 1;
    /*set ents color*/
    if (ZwEntityColorRgbSet(inputRGB, nEnts, ents))
        return 1;

    ZwMemoryFree((void**)&idEnts);
    for (int i = 0; i < nEnts; i++)
        ZwEntityHandleFree(&ents[i]);
    return 0;
    }

/*******************************************************************/
/* Function definition */
int LayerEntityManagerInitA
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

    cvxMsgDisp("LayerEntityManagerInitA");

    /* Inquire layer list*/
    int numLayer = 0;
    vxName* layerList = nullptr;
    if (cvxLayerList(&numLayer, &layerList))
        return 1;

    for (int i = 0; i < numLayer; i++)
        {
        cvxItemAdd(FormName, Field_Layer, layerList[i]);
        }
    cvxMemFree((void**)&layerList);
    return 0;
    }

