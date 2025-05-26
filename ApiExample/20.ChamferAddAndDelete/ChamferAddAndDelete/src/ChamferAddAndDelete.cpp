/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

/*******************************************************************/
/* ZW3D API includes */
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"
#include "zwapi_edge.h"
#include "zwapi_entity.h"
#include "zwapi_cmd_shape.h"
#include "zwapi_util.h"
#include "zwapi_history.h"
#include "zwapi_command.h"
#include "zwapi_message.h"
#include "zwapi_memory.h"
#include "zwapi_part_history.h"

/*******************************************************************/
/* Application includes */
#include <vector>
#include <set>
#include "..\inc\ChamferAddAndDeletePr.h"

/*******************************************************************/
/* Data type definitions */
/* DESCRIPTION: form field id */
enum ChamferAddAndDeleteField
{
    Field_Edge_List = 2,
    Field_Distance = 3,
    Field_Same_Face_Flag = 4,

    Field_Feature_List = 6,
    Field_Limit_Distance_Flag = 7,
    Field_Distance_Limit = 8,
};

#define CHAMFER_FIELD_CHAMFERLIST 2
#define CHAMFERLIST_FIELD_SETBACK 2

/*******************************************************************/
/* Global variable declarations */
int dataId = 0;
std::set<int> faceList{};

/*******************************************************************/
/* Function declarations */
static int ChamferAddAndDelete(int idData);
static void ChamferAddAndDeleteEcho(int idData, void *ohEcho);
static int ChamferAddAndDeleteCb(char *form, int idField, int item);
static int SameFaceEdge(int idEdge);
static int LimitDistance(int idFeature);
static std::set<int> SameFaceList(const int cntFace, szwEntityHandle *curfaces, const std::set<int> faceList);

/*******************************************************************/
/* Function definition */
int RegisterChamferAddAndDelete
(
void
)
/*
DESCRIPTION:
   Register callback function of template command.
*/
{
    /* Start the command by entering command string "!ChamferAddAndDelete" */
    ZwCommandFunctionLoad("ChamferAddAndDelete", (void *)ChamferAddAndDelete, ZW_LICENSE_CODE_GENERAL);
    ZwCommandCallbackLoad("ChamferAddAndDeleteEcho", (void *)ChamferAddAndDeleteEcho);
    ZwCommandCallbackLoad("ChamferAddAndDeleteCb", (void *)ChamferAddAndDeleteCb);
    ZwCommandCallbackLoad("LimitDistance", (void *)LimitDistance);
    ZwCommandCallbackLoad("SameFaceEdge", (void *)SameFaceEdge);
    return 0;
}

/*******************************************************************/
/* Function definition */
int UnloadChamferAddAndDelete
(
void
)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
{
    ZwCommandFunctionUnload("ChamferAddAndDelete");
    ZwCommandFunctionUnload("ChamferAddAndDeleteEcho");
    ZwCommandFunctionUnload("ChamferAddAndDeleteCb");
    ZwCommandFunctionUnload("LimitDistance");
    ZwCommandFunctionUnload("SameFaceEdge");
    return 0;
}

/*******************************************************************/
/* Function definition */
int ChamferAddAndDelete
(
int idData /* I: index of data container */
)
/*
DESCRIPTION:
   Execution function of command. the function is called when the command
is clicked on the OK or APPLY button.
*/
{
    // TODO: Do something

    cvxMsgDisp("ChamferAddAndDelete");
    cvxEchoEnd();
    int addFlag = 1; /*flag for add or del, 1:add, 0,:del*/

    /* Inquire data of data container */
    int cntEdges = 0;
    int *idEdge = nullptr;
    cvxDataGetEnts(idData, Field_Edge_List, &cntEdges, &idEdge);

    int cntFea = 0;
    int *idFea = nullptr;
    cvxDataGetEnts(idData, Field_Feature_List, &cntFea, &idFea);

    if (cntEdges)
    {
        /*Add chamfer*/
        svxChamFlltData chamfer{};
        cvxPartChamferAllInit(&chamfer);
        chamfer.type = VX_CHAMFLLT_SYMMETRIC;

        /* initialize set-list data */
        svxChamFlltSetData chamSet = {0};
        if (cvxChamFlltSetDataInit(&chamSet))
            return 1;
        double dis = 0.0;
        if (cvxDataGetNum(idData, Field_Distance, &dis))
            return 1;
        chamSet.setback1 = dis;
        chamSet.idEdge = idEdge;
        chamSet.nEdges = cntEdges;
        chamfer.cntList = 1;
        chamfer.pChamFlltDataList = &chamSet;

        int idChamfer = 0;
        if (cvxPartChamferAll(&chamfer, &idChamfer))
            return 1;
    }

    if (cntFea)
    {
        /*delete chamfer feature*/
        szwEntityHandle *feature = nullptr;
        ZwMemoryAlloc(cntFea * sizeof(szwEntityHandle), (void **)&feature);
        if (ZwEntityIdTransfer(cntFea, idFea, feature))
            return 1;
        if (ZwHistoryOperationDelete(cntFea, feature, ZW_DELETE_ASSOCIATED_OPERATION))
            return 1;
        ZwEntityHandleListFree(cntFea, &feature);
    }

    return 0;
}

/*******************************************************************/
/* Function definition */
void ChamferAddAndDeleteEcho
(
int idData,  /* I: index of data container */
void *ohEcho /* I: handle of preview object */
)
/*
DESCRIPTION:
   Preview callback function of command, the function is called when the parameters
of command change.
*/
{
    cvxEchoStart();

    // TODO: Do something

    cvxMsgDisp("ChamferAddAndDeleteEcho");
    /*------------------Add------------------------------*/

    int cntEdges = 0;
    int *idEdge = nullptr;
    cvxDataGetEnts(idData, Field_Edge_List, &cntEdges, &idEdge);
    if (cntEdges == 0)
        return;

    /*chamfer*/
    svxChamFlltData chamfer{};
    cvxPartChamferAllInit(&chamfer);
    chamfer.type = VX_CHAMFLLT_SYMMETRIC;

    /* set-list data */
    svxChamFlltSetData chamSet = {0};
    if (cvxChamFlltSetDataInit(&chamSet))
        return;

    chamSet.idEdge = idEdge;
    chamSet.nEdges = cntEdges;
    double dis = 0.0;
    if (cvxDataGetNum(idData, Field_Distance, &dis))
        return;
    chamSet.setback1 = dis;

    chamfer.cntList = 1;
    chamfer.pChamFlltDataList = &chamSet;


    int idChamfer = 0;
    if (cvxPartChamferAll(&chamfer, &idChamfer))
        return;

    cvxEchoEnd();
}


/*******************************************************************/
/* Function definition */
int ChamferAddAndDeleteCb
(
char *formName, /* I: form name */
int idField,    /* I: index of command parameter field */
int idData      /* I: index of data container */
)
/*
DESCRIPTION:
   Callback function of command parameter field, the function is called when value
of the specify parameter field changes.
*/

{
    // TODO: Do something

    cvxMsgDisp("ChamferAddAndDeleteCb");
    dataId = idData;
    if (idField <= Field_Same_Face_Flag)
    {
        double flag = 0;
        cvxDataGetNum(idData, Field_Same_Face_Flag, &flag);
        if ((int)flag == 1 && !cvxDataDelUnHi(idData, Field_Edge_List))
        {
            faceList.clear();
            return 0;
        }
    }
    else if (idField >= Field_Feature_List)
    {
        double flag = 0;
        cvxDataGetNum(idData, Field_Same_Face_Flag, &flag);
        if ((int)flag == 1)
        {
            int cntFeas = 0;
            int *idFea = nullptr;
            cvxDataGetEnts(idData, Field_Edge_List, &cntFeas, &idFea);
            if (cntFeas == 0)
                return 0;
            for (int i = 0; i < cntFeas; i++)
            {
                int sameDis = LimitDistance(idFea[i]);
                if (sameDis == -1)
                {
                    ZwMemoryFree((void **)&idFea);
                    return 1;
                }
                else if (sameDis == 0)
                {
                    cvxDataDelItem(idData, Field_Feature_List, idFea[i]);
                    szwEntityHandle tmpEntity{};
                    ZwEntityIdTransfer(1, &idFea[i], &tmpEntity);
                    ZwEntityUnHighlight(tmpEntity);
                }
            }
            ZwMemoryFree((void **)&idFea);
        }
    }
    return 0;
}

/*******************************************************************/
/* Function definition */
int LimitDistance
(
int idFeature /* I: index of feature */
)
/*
DESCRIPTION:
   Callback function of command parameter field, the function is called when value
of the specify parameter field changes.
*/
{
    // TODO: Do something

    cvxMsgDisp("LimitDistance");
    double limitFlag = 0;
    cvxDataGetNum(dataId, Field_Same_Face_Flag, &limitFlag);
    if ((int)limitFlag != 1)
        return 1;

    zwString32 formname{};
    strcpy_s(formname, cvxDataName(idFeature));

    if (strcmp("FtChamfers2", formname) == 0)
    {
        /*inquire the feature data*/
        double limitDis = 0, chamferDis = 0;
        int feaIdData = 0;
        if (cvxPartInqFtrData(idFeature, 0, &feaIdData))
            return -1;
        svxData *edgeListData = nullptr;
        int EdgeCount = 0;
        cvxDataGetList(feaIdData, CHAMFER_FIELD_CHAMFERLIST, &EdgeCount, &edgeListData);

        cvxDataGetNum(edgeListData[0].idEntity, CHAMFERLIST_FIELD_SETBACK, &chamferDis);

        ZwMemoryFree((void **)&edgeListData);

        /*get the limit distance*/
        if (cvxDataGetNum(dataId, Field_Distance_Limit, &limitDis))
            return -1;

        if (chamferDis == limitDis)
            return 1;
    }
    return 0;
}

/*******************************************************************/
/* Function definition */
std::set<int> SameFaceList
(
const int cntFace,
szwEntityHandle *curfaces,
const std::set<int> faceList
)
{
    std::set<int> newFaceList{};
    for (int i = 0; i < cntFace; i++)
    {
        int curFaceId = 0;
        ZwEntityIdGet(1, &curfaces[i], &curFaceId);
        std::set<int>::iterator it;
        for (it = faceList.begin(); it != faceList.end(); it++)
        {
            if (curFaceId == *it)
            {
                newFaceList.insert(*it);
                break;
            }
        }
    }
    return newFaceList;
}

/*******************************************************************/
/* Function definition */
int SameFaceEdge
(
int idEdge
)
{
    double sameFace = 0;
    cvxDataGetNum(dataId, Field_Same_Face_Flag, &sameFace);
    if ((int)sameFace != 1)
        return 1;

    szwEntityHandle curEdge{};
    ZwEntityIdTransfer(1, &idEdge, &curEdge);
    szwEntityHandle *faces = nullptr;
    int cntCurFace = 0;
    if (ZwEdgeFaceListGet(curEdge, &cntCurFace, &faces))
        return 1;
    ZwEntityHandleFree(&curEdge);

    /*if only support edges from the face and it is not the first edge, check current edge,
  else push it to the edge list and init the face list. */
    int cntExitEdge = 0;
    int *edgeId = nullptr;
    cvxDataGetEnts(dataId, Field_Edge_List, &cntExitEdge, &edgeId);

    ZwMemoryFree((void **)&edgeId);

    if (!cntExitEdge)
    {
        faceList.clear();
        for (int i = 0; i < cntCurFace; ++i)
        {
            int curFaceId = 0;
            ZwEntityIdGet(1, &faces[i], &curFaceId);
            faceList.insert(curFaceId);
        }
        return 1;
    }
    else
    {
        std::set<int> tmpFaceList = faceList;
        tmpFaceList = SameFaceList(cntCurFace, faces, faceList);
        if (!tmpFaceList.size())
            return 0;
        else
            std::swap(faceList, tmpFaceList);
    }
}