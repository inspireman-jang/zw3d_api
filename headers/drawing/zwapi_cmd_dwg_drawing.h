/**
@file zwapi_cmd_dwg_drawing.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Command of Drawing API
*/
/**
@defgroup zwapi_cmd_dwg_drawing Drawing Commands
@ingroup DrawingCommands
@brief
@details THE MODULE FOR THE ZW3D Drawing Command of Drawing API
*/

#pragma once
#ifndef ZW_API_CMD_DRAWING_H /* this ifndef surrounds entire header */
#define ZW_API_CMD_DRAWING_H

#include "zwapi_cmd_dwg_data.h"
#include "zwapi_cmd_sk_cmds_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing */
    //====================================================================================================================
    /**********************************************************************
    *! -Line- : zwapi_cmd_sk_cmds_data.h
    *  cvxSkLine2pt(svxPoint2 *Start, svxPoint2 *End, int *idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Circle- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkCir3pt(svxPoint2 *P1, svxPoint2 *P2, svxPoint2 *P3, int *idEnt);
    *  ZW_API_C evxErrors cvxSkCirRad(svxPoint2 *Center, double Radius, int *idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Arc- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkArc3pt(svxPoint2*Start, svxPoint2*End, svxPoint2*Mid, int*idEnt);
    *  ZW_API_C evxErrors cvxSkArcRad(svxPoint2*Center, double R, double S, double E, int*idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Polygon- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkAddPolyline(int cntPnt, svxPoint2* pnts, int addCns);
    *  ZW_API_C evxErrors cvxSkArcRad(svxPoint2*Center, double R, double S, double E, int*idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Polygon- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkEllipseInit(svxEllipse* data);
    *  ZW_API_C evxErrors cvxSkEllipse(svxEllipse *ellipse, int *idEnt);
    **********************************************************************/
    /**
    @ingroup zwapi_cmd_dwg_drawing

    Initialize the parameters of the cvxDwgCrossHatch().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data hatch attributes(drawing)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxDwgCrossHatchInit(svxHatchAttr *data);

    /**
    @ingroup zwapi_cmd_dwg_drawing

    This function creates a hatch pattern within a boundary.

    @note
    Interface cvxDwgCrossHatchInit() initializes the svxHatchAttr structure.

    @deprecated This API will not be updated anymore, please use ZwDrawingCrossHatchCreate()
    @see ZwDrawingCrossHatchCreate

    @param [in] countEnts count of "idEnts"
    @param [in] idEnts list of entity id
    @param [in] countPnts count of "insides"
    @param [in] insides list of point
    @param [in] isSplit 1 if split boundary ,else 0
    @param [in] hatch hatch attributes (NULL to use default)
    @param [out] idEnt id of hatch (NULL to ignore).idEnt=0 means that it was not created successfully.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C evxErrors cvxDwgCrossHatch(int countEnts, int *idEnts, int countPnts, svxPoint2 *insides, int isSplit, svxHatchAttr *hatch, int *idEnt);

    /**********************************************************************
    *! -Text- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxEntTextNew(char* String, int Type, svxPoint2 Pnt[2], int* idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Point- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkPnt(svxPoint2 *Point, int *idEnt);
    **********************************************************************/
    /**********************************************************************
    *! -Sketch- : zwapi_sk_create.h
    *  ZW_API_C evxErrors cvxPartSkNew(svxMatrix* Plane, int* idEnt);
    *  ZW_API_C evxErrors cvxPartSkPlane(svxSketchData* SkData, int* idSketch);
    **********************************************************************/

    //====================================================================================================================
    /** @name Curve */
    //====================================================================================================================
    /**********************************************************************
    *! -Spline- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkSplineInit(svxSplineData* data, int count);
    *  ZW_API_C evxErrors cvxSkSpline(const svxSplineData* PntData, int* idEnt);
    *  ZW_API_C evxErrors cvxSkCrvIntInit(svxCrvIntData* data);
    *  ZW_API_C evxErrors cvxSkCrvInt(svxCrvIntData *Crv, int *idEnt);
    **********************************************************************/

    //====================================================================================================================
    /** @name Edit Curve */
    //====================================================================================================================
    /**********************************************************************
    *! -Fillet- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkFilletInit(svxSkFilletData* data);
    *  ZW_API_C evxErrors cvxSkFillet(const svxSkFilletData* filletData, int* idFillet);
    **********************************************************************/

    /**********************************************************************
    *! -Chamfer- : zwapi_cmd_sk_cmds_data.h
    *  ZW_API_C evxErrors cvxSkChamferInit(svxSkChamferData* data);
    *  ZW_API_C evxErrors cvxSkChamfer(const svxSkChamferData* chmData, int* idChamfer);
    **********************************************************************/

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_drawing

    Moves the specified entity within the active drawing from one point
    "Start" to another "End".

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] idEnt id of entity to move
    @param [in] Start start point
    @param [in] End end point
    @param [in] type direction type
    @param [in] angle angle
    @param [in] scale scale

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C evxErrors cvxDwgEntMovePntToPnt(int idEnt, svxPoint2 *Start, svxPoint2 *End, evxDrawingMoveDirType type, double angle, double scale);

    /**
    @ingroup zwapi_cmd_dwg_drawing

    The specified entity within the active drawing moves "Distance" distance in the direction of "Direction".

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] idEnt id of entity to move
    @param [in] Direction direction
    @param [in] Distance distance
    @param [in] BasePoint base point
    @param [in] angle angle
    @param [in] scale scale

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C evxErrors cvxDwgEntMoveAlongDirection(int idEnt, svxVector2 *Direction, double Distance, svxPoint2 *BasePoint, double angle, double scale);


/**********************************************************************
*! -Move- : zwapi_cmd_sk_cmds_data.h
*  ZW_API_C evxErrors cvxSkMoveInit(evxMoveType2D type, svxMoveData2D* data);
*  ZW_API_C evxErrors cvxSkMove(const svxMoveData2D* data);
**********************************************************************/

/**********************************************************************
*! -Scale- : zwapi_cmd_sk_cmds_data.h
*  ZW_API_C evxErrors cvxSkScale(int Count, int* idEnts, double X, double Y, svxPoint2* Pnt);
**********************************************************************/


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_H */
