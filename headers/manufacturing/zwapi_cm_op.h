/**
@file zwapi_cm_op.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the  Cam Operation.
*/
/**
@defgroup zwapi_cam_op Cam Operation API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the  Cam Operation.
*/

#pragma once
#ifndef ZW_API_CAM_OPERATION_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_OPERATION_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Operation Data */
    //====================================================================================================================
    /**
    @brief cam operation type
    @ingroup zwapi_cam_op
    */
    typedef enum evxCmOpType
    {
        /* Drill:0-19*/
        ZW_CAM_OPERATION_CENTER = 0,
        ZW_CAM_OPERATION_DRILL,
        ZW_CAM_OPERATION_PECK,
        ZW_CAM_OPERATION_CHIP,
        ZW_CAM_OPERATION_REAM,
        ZW_CAM_OPERATION_BORE,
        ZW_CAM_OPERATION_FINEBORE,
        ZW_CAM_OPERATION_COUNTERBORE,
        ZW_CAM_OPERATION_COUNTERSINK,
        ZW_CAM_OPERATION_TAP,
        /* 2X:20-34*/
        ZW_CAM_OPERATION_PROFILECUT = 20,
        ZW_CAM_OPERATION_SPIRAL,
        ZW_CAM_OPERATION_ZIGZAG,
        ZW_CAM_OPERATION_BOX,
        ZW_CAM_OPERATION_CONTOUR,
        ZW_CAM_OPERATION_CHAMFER,
        ZW_CAM_OPERATION_COURNER_ROUND,
        ZW_CAM_OPERATION_HELICAL,
        ZW_CAM_OPERATION_RAMP,
        ZW_CAM_OPERATION_TOPFACE_CUT,
        ZW_CAM_OPERATION_NESTING,
        ZW_CAM_OPERATION_INTER_PATH_MOVE,
        ZW_CAM_OPERATION_THREADMILL,
        /* Turning:35-49*/
        ZW_CAM_OPERATION_DRILL_TURNING = 35,
        ZW_CAM_OPERATION_FACING,
        ZW_CAM_OPERATION_ROUGH,
        ZW_CAM_OPERATION_FINISH,
        ZW_CAM_OPERATION_GROOVE,
        ZW_CAM_OPERATION_THREADING,
        ZW_CAM_OPERATION_PARTOFF,
        /* 3X:50-79*/
        ZW_CAM_OPERATION_SPIRAL_ROUGH = 50,
        ZW_CAM_OPERATION_ZIGZAG_ROUGH,
        ZW_CAM_OPERATION_BOX_ROUGH,
        ZW_CAM_OPERATION_CONTOUR_ROUGH,
        ZW_CAM_OPERATION_SPIRAL_CAST = 55,
        ZW_CAM_OPERATION_ZIGZAG_CAST,
        ZW_CAM_OPERATION_BOX_CAST,
        ZW_CAM_OPERATION_CONTOUR_CAST,
        ZW_CAM_OPERATION_SPIRAL_FINISH = 60,
        ZW_CAM_OPERATION_ZIGZAG_FINISH,
        ZW_CAM_OPERATION_BOX_FINISH,
        ZW_CAM_OPERATION_CONTOUR_FINISH,
        ZW_CAM_OPERATION_PROFILE_FINISH,
        ZW_CAM_OPERATION_SIDE,
        ZW_CAM_OPERATION_PEELING,
        ZW_CAM_OPERATION_ISO,
        ZW_CAM_OPERATION_3XISO,
        ZW_CAM_OPERATION_MAP,
        ZW_CAM_OPERATION_REST,
        ZW_CAM_OPERATION_PENCIL_TRACE,
        ZW_CAM_OPERATION_SCALLOP_REMOVAL,
        ZW_CAM_OPERATION_SURFACE_ENGRAVING,
        /* QM:80-109*/
        ZW_CAM_OPERATION_SMOOTHFLOW = 80,
        ZW_CAM_OPERATION_OFFSET2D,
        ZW_CAM_OPERATION_LACE_ROUGH,
        ZW_CAM_OPERATION_PLUNGE,
        ZW_CAM_OPERATION_PRE_DRILL,
        ZW_CAM_OPERATION_OFFSET3D,
        ZW_CAM_OPERATION_LACE_FINISH,
        ZW_CAM_OPERATION_ANGLE_LIMITING_FINISHING,
        ZW_CAM_OPERATION_DRIVE_CURVE,
        ZW_CAM_OPERATION_ZLEVEL,
        ZW_CAM_OPERATION_PENCIL,
        ZW_CAM_OPERATION_FLOW_3D,
        ZW_CAM_OPERATION_BULGE,
        ZW_CAM_OPERATION_ENGRAVE_2D,
        ZW_CAM_OPERATION_SMOOTHFLOW_HSM = 95,
        ZW_CAM_OPERATION_OFFSET2D_HSM,
        ZW_CAM_OPERATION_LACE_HSM,
        ZW_CAM_OPERATION_FLOW_HSM,
        ZW_CAM_OPERATION_CORNERFINISH,
        ZW_CAM_OPERATION_FLATFINISH,
        /* 5X:110-129*/
        ZW_CAM_OPERATION_PLANE = 110,
        ZW_CAM_OPERATION_SWARF,
        ZW_CAM_OPERATION_DRIVECURVE_5X,
        ZW_CAM_OPERATION_INTERACTIVE,
        ZW_CAM_OPERATION_FLOW_5X,
        ZW_CAM_OPERATION_SIDE_5X,
        ZW_CAM_OPERATION_GUIDE_SURFACE_ISO
    } evxCmOpType;

    /**
    @brief cam mill2 operation attribute
    @ingroup zwapi_cam_op
    */
    typedef enum evxCm2XOpAttr
    {
        ZW_CAM_2X_OPERATION_ATTR_NAME = 300,
        ZW_CAM_2X_OPERATION_ATTR_FRAME,
        ZW_CAM_2X_OPERATION_ATTR_PATH_TOL,
    } evxCm2XOpAttr;

    /**
    @brief cam qm operation attribute
    @ingroup zwapi_cam_op
    */
    typedef enum evxCmQmOpAttr
    {
        ZW_CAM_QM_OPERATION_ATTR_NAME = 400,
        ZW_CAM_QM_OPERATION_ATTR_FRAME,
        ZW_CAM_QM_OPERATION_ATTR_PATH_TOL,
        ZW_CAM_QM_OPERATION_ATTR_SURF_THICK,
        ZW_CAM_QM_OPERATION_ATTR_Z_SURF_THICK,
        ZW_CAM_QM_OPERATION_ATTR_TOOL,
        ZW_CAM_QM_OPERATION_ATTR_MINTOOLHEIGHT,
        ZW_CAM_QM_OPERATION_ATTR_CLASS,
        ZW_CAM_QM_OPERATION_ATTR_LIMIT_TOPZ,
        ZW_CAM_QM_OPERATION_ATTR_LIMIT_BOTTOMZ,
        ZW_CAM_QM_OPERATION_ATTR_LIMIT_BOTTOM_CURVE,
        ZW_CAM_QM_OPERATION_ATTR_LIMIT_BOTTOM_CURVE_ZDISPLACEMENT,
        ZW_CAM_QM_OPERATION_ATTR_LIMIT_BOTTOM_CURVE_OFFSET
    } evxCmQmOpAttr;

    /**
    @brief cam operation class: finish or rough
    @ingroup zwapi_cam_op
    */
    typedef enum evxCmOpClass
    {
        CM_OP_ROUGH  = 0, /**<@brief rough operation */
        CM_OP_FINISH = 1, /**<@brief finish operation */
    } evxCmOpClass;

    //====================================================================================================================
    /** @name Cam Operation Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cam_op

    Create an operation in the active CamPlan.

    @param [in] opType Operation type
    @param [out] idx_Op index of this inserted Operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxCmOpInsert(evxCmOpType opType, int *idx_Op);

    /**
    @ingroup zwapi_cam_op

    Delete an operation in the active CamPlan.

    @param [in] idx_Op index of operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpDelete(int idx_Op);

    /**
    @ingroup zwapi_cam_op

    Duplicate an operation in the active CamPlan.

    @param [in] idx_Op index of source operation
    @param [out] cpyOp index of destination op

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpDuplicate(int idx_Op, int *cpyOp);

    /**
    @ingroup zwapi_cam_op

    Add the component into the operation.

    @param [in] idx_Op index of the operation
    @param [in] idx_CmComp index of the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_CAM_GETTACNAME_ERROR
    */
    ZW_API_C evxErrors cvxCmOpAddComp(int idx_Op, int idx_CmComp);

    /**
    @ingroup zwapi_cam_op

    Remove the component of the operation.

    @param [in] idx_Op index of the operation
    @param [in] idx_CmComp index of the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpRemoveComp(int idx_Op, int idx_CmComp);

    /**
    @ingroup zwapi_cam_op

    Add the feature into the operation.

    @param [in] idx_Op index of the operation
    @param [in] idx_FtrGrp index of the feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_GETFTRGRP_ERROR
    -        ZW_API_CAM_GETFTRDBNAME_ERROR
    */
    ZW_API_C evxErrors cvxCmOpAddFtr(int idx_Op, int idx_FtrGrp);

    /**
    @ingroup zwapi_cam_op

    Remove the feature of the operation.

    @param [in] idx_Op index of the operation
    @param [in] idx_ftrgrp index of the feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpRemoveFtr(int idx_Op, int idx_ftrgrp);

    /**
    @ingroup zwapi_cam_op

    Calculate the operation.

    @param [in] idx_Op index of the operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpCalTPath(int idx_Op);

    /**
    @ingroup zwapi_cam_op

    Add a tool in the target operation.

    @param [in] idx_Op index of the operation
    @param [in] idx_Tool index of the tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpAddTool(int idx_Op, int idx_Tool);

    /**
    @ingroup zwapi_cam_op

    Remove the tool of the target operation.

    @param [in] idx_Op index of the operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxCmOpRemoveTool(int idx_Op);

    /**
    @ingroup zwapi_cam_op

    Set speed & feed for the operation. 
    The speed & feed is from active Cam plan or current Library or default Library in proper order.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_op idx of opdef
    @param [in] spdfdName name of speed & feed

    */
    ZW_API_C evxErrors cvxCmOpSetSpeed(int idx_op, vxName spdfdName);

    /**
    @ingroup zwapi_cam_op

    Modify the attributes of the operation.

    @param [in] idx_op index of the operation
    @param [in] field field id of the attribute
    @param [in] item item id of the attribute
    @param [in] value value of the attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpSetAttr2(int idx_op, int field, int item, const char *value);

    /**
    @ingroup zwapi_cam_op

    Inquire the attributes of the operation.

    @param [in] idx_op index of the operation
    @param [in] field field id of the attribute
    @param [in] item item id of the attribute
    @param [out] is_on on/off flag (MAYBE NULL)
    @param [out] value value of the attribute, caller should allocate memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpGetAttr2(int idx_op, int field, int item, int *is_on, char *value);

    /**
    @ingroup zwapi_cam_op

    Get the operation index with the specified name.

    @param [in] op_name name of operation
    @param [out] op_index index of operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETOPBYTAC_ERROR
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpGetIdxFromName(vxLongName op_name, int *op_index);

    /**
    @ingroup zwapi_cam_op

    Set one point to operation parameter.

    @param [in] idx_op index of operation
    @param [in] p0 point value
    @param [in] field operation parameter's field

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmSetOpPoint(int idx_op, svxPoint p0, int field);

    /**
    @ingroup zwapi_cam_op

    Set points to operation parameter.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_op index of operation
    @param [in] num number of points
    @param [in] pts points value
    @param [in] field operation parameter's field

    */
    ZW_API_C evxErrors cvxCmSetOpPoints(int idx_op, int num, svxPoint *pts, int field);

    /**
    @ingroup zwapi_cam_op

    Change the operation name.

    @param [in] idx_op operation index
    @param [in] op_newName new name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpRename(int idx_op, vxLongName op_newName);

    /**
    @ingroup zwapi_cam_op

    Replace two tree nodes position.

    @param [in] drag_idx index of to be drag
    @param [in] drag_type type of to be drag
    @param [in] drop_idx index of to be drop
    @param [in] drop_type type of to be drop
    @param [in] iPos position of to be drop 0:in,1:above,2:below

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpDrag(int drag_idx, evxCmTreeType drag_type, int drop_idx, evxCmTreeType drop_type, int iPos);



    /**
    @ingroup zwapi_cam_op

    Modify the attributes of the operation.

    @param [in] idx_op index of the operation
    @param [in] field field id of the attribute
    @param [in] item item id of the attribute
    @param [in] value value of the attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV

    */
    ZW_API_C evxErrors cvxCmOpSetBasicAttr(int idx_op, int field, int item, const char *value);

    /**
    @ingroup zwapi_cam_op

    Inquire operation's class

    @param [in] idx_Op index of operation
    @param [out] opClass class of operation 0:rough,1:finish

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmOpInqClass(int idx_Op, evxCmOpClass *opClass);

    /**
    @ingroup zwapi_cam_op

    Set the operation's class parameter

    @param [in] idx_Op index of operation
    @param [in] opClass class of operation 0:rough,1:finish


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR

    */
    ZW_API_C evxErrors cvxCmOpSetClass(int idx_Op, evxCmOpClass opClass);

    /**
    @ingroup zwapi_cam_op

    Get the operation's type

    @param [in] idx_Op index of operation
    @param [out] opType type of operation
    @param [in] nByte size of type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR

    */
    ZW_API_C evxErrors cvxCmOpInqTypeS(int idx_Op, char *opType, int nByte);

    /**
    @ingroup zwapi_cam_op

    Set the operation's spindle speed.

    @param [in] idx_op index of the operation
    @param [in] spdValue spindle speed value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmOpSetSpindleSpd(int idx_op, double spdValue);

    /**
    @ingroup zwapi_cam_op

    Set operation's feed rate.

    @param [in] idx_op index of the operation
    @param [in] pzFeedRate Feed rate data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETOPNAME_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxCmOpSetFeedRate(int idx_op, const svxFeedRate *pzFeedRate);

    /**
    @ingroup zwapi_cam_op

    Get operation's spindle speed.

    @param [in] idx_op index of the operation
    @param [out] spdValue spindle speed value
    @param [out] spdUnit spindle speed unit
    @param [in] spdUnitSize spindle speed unit size

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmOpGetSpindleSpd(int idx_op, double *spdValue, char *spdUnit, int spdUnitSize);

    /**
    @ingroup zwapi_cam_op

    Get operation's feed rate.

    @param [in] idx_op index of the operation
    @param [out] pzFeedRate feed rate data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmOpGetFeedRate(int idx_op, svxFeedRate *pzFeedRate);

    //====================================================================================================================
    /** @name Cam Operation Function */
    //====================================================================================================================

    /******************************************************************************/ /**
    @ingroup ZwCamOp

    After using this function, you should use ZwCamTreeRefresh function to update the CAM tree.

    @param [in] idx_op index of the operation
    @param [in] idx_folder index of the folder

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETFOLDER_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpSetFolder(int idx_op, int idx_folder);

    /******************************************************************************/ /**
    @ingroup ZwCamOp

    Save operation's parameters to xml file.

    @param [in] idx_op index of the operation
    @param [in] xmlPath xml file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwCamOpSaveToXml(int idx_op, const char *xmlPath);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_OPERATION_H */
