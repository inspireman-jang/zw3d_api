/**
@file zwapi_cm_op_param.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Operation Parameters.
*/


#pragma once
#ifndef ZW_API_CAM_OPERATION_PARAM_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_OPERATION_PARAM_H

#include "zwapi_util.h"
#include "zwapi_cm_op_param_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Operation Parameter Function */
    //====================================================================================================================
 
    /**
    @ingroup ZwCamOp

    Set the operation's parameter, which is the "double" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [in] value value to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpDoubleSet(int idx_Op, ezwCamOpParam param, double value);

    /**
    @ingroup ZwCamOp

    Set the operation's parameter, which is the "int" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [in] value value to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpIntSet(int idx_Op, ezwCamOpParam param, int value);

    /**
    @ingroup ZwCamOp

    Set the operation's parameter, which is the "string" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [in] str value to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpStrSet(int idx_Op, ezwCamOpParam param, const char *str);

    /**
    @ingroup ZwCamOp

    Set the operation's parameter, which is the "struct object" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [in] obj_ptr value to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpObjSet(int idx_Op, ezwCamOpParam param, void *obj_ptr);

    /**
    @ingroup ZwCamOp

    Get the operation's parameter, which is the "double" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [out] value value to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpDoubleGet(int idx_Op, ezwCamOpParam param, double *value);

    /**
    @ingroup ZwCamOp

    Get the operation's parameter, which is the "int" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [out] value value to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpIntGet(int idx_Op, ezwCamOpParam param, int *value);

    /**
    @ingroup ZwCamOp

    Get the operation's parameter, which is the "string" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [out] str value to get
    @param [in] strSize the max size of str

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpStrGet(int idx_Op, ezwCamOpParam param, char *str, int strSize);

    /**
    @ingroup ZwCamOp

    Get the operation's parameter, which is the "struct object" type.

    @param [in] idx_Op index of operation
    @param [in] param parameter enum
    @param [out] obj_ptr value to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CAM_OPTYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCamOpObjGet(int idx_Op, ezwCamOpParam param, void *obj_ptr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_OPERATION_PARAM_H */
