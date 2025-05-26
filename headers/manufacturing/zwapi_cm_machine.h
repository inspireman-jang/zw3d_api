/**
@file zwapi_cm_machine.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Machine.
*/
/**
@defgroup zwapi_cm_machine Cam Machine API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Machine.
*/

#pragma once
#ifndef ZW_API_CAM_MACH_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_MACH_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Machine Data */
    //====================================================================================================================
    /**
    @brief cam machine class
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachClass
    {
        TWO_AXIS_MC,  /**<@brief  CAM 2 axis machine class */
        THREE_AXIS_MC /**<@brief  CAM 3 axis machine class */
    } evxCmMachClass;

    /**
    @brief cam machine type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachType
    {
        CM_MACH_TYPE_VERTICAL, /**<@brief  CAM machine vertical type */
        CM_MACH_TYPE_HORIZNTAL /**<@brief  CAM machine horizontal type */
    } evxCmMachType;

    /**
    @brief cam machine sub type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachSubType
    {
        CM_MACH_SUBTYPE_ROTATING_HEAD, /**<@brief  CAM machine rotating head subtype */
        CM_MACH_SUBTYPE_ROTATING_TABLE /**<@brief  CAM machine rotating table subtype */
    } evxCmMachSubType;

    /**
    @brief cam machine cut compensation type
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachCutCompenation
    {
        CM_MACH_CUT_COMPENSATION_NONE,   /**<@brief  CAM cutting compensation None */
        CM_MACH_CUT_COMPENSATION_LENGTH, /**<@brief  CAM cutting compensation Length */
        CM_MACH_CUT_COMPENSATION_CENTER  /**<@brief  CAM cutting compensation Center */
    } evxCmMachCutCompenation;

    /**
    @brief cam machine multax
    @ingroup zwapi_cm_machine
    */
    typedef enum ezwCamMachMultax
    {
        ZW_CAM_MACH_MULTAX_NO, /**<@brief  CAM machine uses Multi-Axis Position or Interpolation */
        ZW_CAM_MACH_MULTAX_YES /**<@brief  CAM machine does not use Multi-Axis Position or Interpolation */
    } ezwCamMachMultax;

    /**
    @brief cam machine attribute
    @ingroup zwapi_cm_machine
    */
    typedef enum evxCmMachAttr
    {
        CM_MACH_NAME,               /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_CLASS,              /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_TYPE,               /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_SUBTYPE,            /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_POST_CONFIGURATION, /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_CUT_COMPENSATION,   /**  <@brief CAM machine attribute using with cvxCmMachineGetAttr and cvxCmMachineSetAttr */
        CM_MACH_DEF_FILE,           /**  <@brief CAM machine attribute using with ZwCamMachineStrGet and ZwCamMachineStrSet */
        CM_MACH_MULTAX,             /**  <@brief CAM machine attribute using with ZwCamMachineIntGet and ZwCamMachineIntSet */
        CM_MACH_PRECISION_NUM       /**  <@brief CAM machine attribute using with ZwCamMachineIntGet and ZwCamMachineIntSet */
    } evxCmMachAttr;

    //====================================================================================================================
    /** @name Cam Machine Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_machine

    Insert a machine to the cam plan.

    @param [in] machine_class machine class
    @param [in] machine_type machine type
    @param [in] sub_type machine sub_type
    @param [out] idx_machine index of machine

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_CAM_GETMACH_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmMachineInsert(evxCmMachClass machine_class, evxCmMachType machine_type, evxCmMachSubType sub_type, int *idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Set the machine to active.

    @param [in] idx_machine machine index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmMachineActive(int idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Delete the machine.

    @param [in] idx_machine machine index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmMachineDelete(int idx_machine);

    /**
    @ingroup zwapi_cm_machine

    Get attribute of a machine.

    @param [in] idx_machine index of machine
    @param [in] attr type of attribute
    @param [out] value value of attribute, user need to free the memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETMACHNAME_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmMachineGetAttr(int idx_machine, evxCmMachAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_machine

    Modify the machine's attribute .

    @verbatim
    "value->type"          &     "value->cnt"   &value->data depends on     "attr", as follows:
    ZW_CAM_ATTR_VALUE_TYPE_STRING       <=32                                CM_MACH_NAME
                                                                            CM_MACH_POST_CONFIGURATION
    ZW_CAM_ATTR_VALUE_TYPE_INTEGER      1       evxCmMachClass              CM_MACH_CLASS
                                                evxCmMachType               CM_MACH_TYPE
                                                evxCmMachSubType            CM_MACH_SUBTYPE
                                                evxCmMachCutCompenation     CM_MACH_CUT_COMPENSATION
    @endverbatim

    @param [in] idx_machine index of the machine
    @param [in] attr type of attribute
    @param [in] value value of attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmMachineSetAttr(int idx_machine, evxCmMachAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_machine

    Insert a tool to the active machine's tool changer.

    @param [in] idx_toolchanger tool index
    @param [in] Location location
    @param [in] Diameter cutter compensation along Diameter
    @param [in] Height cutter compensation along Hight

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C evxErrors cvxCmToolChangerInsert(int idx_toolchanger, int Location, int Diameter, int Height);

    /**
    @ingroup zwapi_cm_machine

    Delete the tool changer in the active machine.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.

    @param [in] idx_toolchanger tool index

    */
    ZW_API_C evxErrors cvxCmToolChangerDelete(int idx_toolchanger);

    //====================================================================================================================
    /** @name Cam Machine Function */
    //====================================================================================================================

    /**
    @ingroup ZwCamMachine

    Set the CAM machine parameter which is the int type.

    @note This function support CM_MACH_MULTAX and CM_MACH_PRECISION_NUM now.
          Other machine attribute can be set with cvxCmMachineSetAttr or ZwCamMachineStrSet.

    @param [in] idx_mach index of machine
    @param [in] param parameter enum
    @param [in] value value to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCamMachineIntSet(int idx_mach, evxCmMachAttr param, int value);

    /**
    @ingroup ZwCamMachine

    Get the CAM machine parameter which is the int type.

    @note This function support CM_MACH_MULTAX and CM_MACH_PRECISION_NUM now.
          Other machine attribute can be get with cvxCmMachineGetAttr or ZwCamMachineStrGet.

    @param [in] idx_mach index of machine
    @param [in] param parameter enum
    @param [out] value value to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCamMachineIntGet(int idx_mach, evxCmMachAttr param, int *value);

    /**
    @ingroup ZwCamMachine

    Get the CAM machine parameter which is the string type.

    @note This function support CM_MACH_DEF_FILE now.
          Other machine attribute can be get with cvxCmMachineGetAttr or ZwCamMachineIntGet.

    @param [in] idx_mach index of machine
    @param [in] param parameter enum
    @param [in] strSize str size
    @param [out] str str to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCamMachineStrGet(int idx_mach, evxCmMachAttr param, int strSize, char *str);

    /**
    @ingroup ZwCamMachine

    Set the CAM machine parameter which is the string type.

    @note This function support CM_MACH_DEF_FILE now.
          Other machine attribute can be set with cvxCmMachineSetAttr or ZwCamMachineIntSet.

    @param [in] idx_mach index of machine
    @param [in] param parameter enum
    @param [in] str string to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCamMachineStrSet(int idx_mach, evxCmMachAttr param, const char *str);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_MACH_H */
