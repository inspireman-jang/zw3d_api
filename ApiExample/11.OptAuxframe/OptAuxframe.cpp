/*
**  (C) Copyright 2022, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/

#include "..\VxApi.h"
#include <stdlib.h>

#pragma comment(lib, "..\\ZW3D.lib")

#define FIELD_ENT              1
#define FIELD_POSITION         101
#define FIELD_X_AXIS           102
#define FIELD_Y_AXIS           103
#define FIELD_Z_AXIS           104
#define FIELD_MATRIX           201


static int OptAuxframe(int idData);
static int OptAuxframeEO(int idData, void* ohEcho);
static int OptAuxframeTerm(void);
static int OptAuxframeCb(char* form, int idField, int idData);


int OptAuxframeInit(void)
/*
DESCRIPTION:
Register callback function.
*/
{
cvxCmdFunc("OptAuxframe", (void*)OptAuxframe, VX_CODE_GENERAL);
cvxCmdCallback("OptAuxframeEO", (void*)OptAuxframeEO);
cvxCmdCallback("OptAuxframeTerm", (void*)OptAuxframeTerm);
cvxCmdCallback("OptAuxframeCb", (void*)OptAuxframeCb);
return 0;
}


int OptAuxframeExit(void)
/*
DESCRIPTION:
Unregister callback function.
*/
{
cvxCmdFuncUnload("OptAuxframe");
cvxCmdFuncUnload("OptAuxframeEO");
cvxCmdFuncUnload("OptAuxframeTerm");
cvxCmdFuncUnload("OptAuxframeCb");
return 0;
}


int OptAuxframe(int idData)
/*
DESCRIPTION:
Execution function of command. the function is called when the command
is clicked on the OK or APPLY button.
*/
{
int idShape = -1;
cvxDataGetEnt(idData, FIELD_ENT, &idShape, NULL);

/* get the matrix of move handle */
svxMatrix matrix = { 0 };
cvxDataGetMatrix(idData, FIELD_MATRIX, &matrix);

/* mode entity */
cvxPartMoveTransform(idShape, &matrix);

/* hide the move handle */
OptAuxframeTerm();

return 0;
}


int OptAuxframeEO(int idData, void* ohEcho)
/*
DESCRIPTION:
Echo callback function of command form, the function is called when the parameters
of command change.
*/
{
cvxEchoStart();

int idShape = -1;
cvxDataGetEnt(idData, FIELD_ENT, &idShape, NULL);

/* get the matrix of move handle */
svxMatrix matrix = { 0 };
cvxDataGetMatrix(idData, FIELD_MATRIX, &matrix);

/* mode entity */
cvxPartMoveTransform(idShape, &matrix);

cvxEchoEnd();
return 0;
}


int OptAuxframeTerm(void)
/*
DESCRIPTION:
Terminate callback function of command form, the function is called when the command
is clicked on the CANCEL button to exit.
*/
{
/* hide the move handle */
cvxAuxFrameShow(-1, 0, 0);

return 0;
}


int OptAuxframeCb(char* form, int idField, int idData)
/*
DESCRIPTION:
Callback function of command field, the function is called when value
of specify field change.
*/
{
if (idField == FIELD_ENT)
   {
   cvxMoveSetAuxFrameElem(0);
   cvxAuxFrameShow(idData, FIELD_ENT, FIELD_MATRIX);
   cvxAuxFrameSetDirXYZOrgBuddy(idData, FIELD_X_AXIS, FIELD_Y_AXIS, FIELD_Z_AXIS, FIELD_POSITION);
   }
if (idField == FIELD_POSITION)
   {
   svxPoint origin = {};
   cvxDataGetPnt(idData, idField, &origin);
   cvxAuxFrameSetOrigin(&origin);
   }
if (idField == FIELD_X_AXIS || idField == FIELD_Y_AXIS || idField == FIELD_Z_AXIS)
   {
   evxAxisType axisType = evxAxisType::VX_AXIS_X;
   if (idField == FIELD_Y_AXIS) axisType = VX_AXIS_Y;
   if (idField == FIELD_Z_AXIS) axisType = VX_AXIS_Z;

   svxData fldData = {};
   cvxDataGet(idData, idField, &fldData);
   if (fldData.isDirection)
      {
      svxVector axisDir = {};
      axisDir = fldData.Dir;
      cvxAuxFrameSetAxisVec(axisType, &axisDir);
      }
   }
return 0;
}