/**
@file zwapi_cm_tool.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE API of the Cam Tool.
*/
/**
@defgroup zwapi_cm_tool Cam Tool API
@ingroup CamModel
@brief
@details THE MODULE FOR THE API of the Cam Tool.
*/

#pragma once
#ifndef ZW_API_CAM_TOOL_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_TOOL_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Tool Data */
    //====================================================================================================================
    /**
    @brief cam tool type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolType
    {
        CM_TOOL_TYPE_MILL,    /**<@brief  mill */
        CM_TOOL_TYPE_FLAME,   /**<@brief  flame */
        CM_TOOL_TYPE_DRILL,   /**<@brief  drill */
        CM_TOOL_TYPE_TAP,     /**<@brief  tap */
        CM_TOOL_TYPE_CENTER,  /**<@brief  center */
        CM_TOOL_TYPE_CHAMFER, /**<@brief  chamfer */
        CM_TOOL_TYPE_REAM,    /**<@brief  ream */
        CM_TOOL_TYPE_BORE     /**<@brief  bore */
    } evxCmToolType;

    /**
    @brief cam tool sub type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolSubType
    {
        CM_TOOL_SUBTYPE_NULL = -1, /**<@brief  NULL */
        CM_TOOL_SUBTYPE_BALLNOSE,  /**<@brief  taperball */
        CM_TOOL_SUBTYPE_BULLNOSE,  /**<@brief  taperbull */
        CM_TOOL_SUBTYPE_ENDNOSE    /**<@brief  end */
    } evxCmToolSubType;

    /**
    @brief cam tool attribute
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolAttr
    {
        CM_TOOL_NAME = 400,     /**<@brief  tool name */
        CM_TOOL_TYPE,           /**<@brief  tool type */
        CM_TOOL_SUBTYPE,        /**<@brief  tool subtype */
        CM_TOOL_ID,             /**<@brief  tool id */
        CM_TOOL_LEN,            /**<@brief  tool_length*/
        CM_TOOL_CUTTERDIAMETER, /**<@brief  tool diameter*/
        CM_TOOL_HOLDER,         /**<@brief  tool holder name*/
        /*  tool register data in active machine */
        CM_TOOLCHANGER_LOCATION,
        CM_TOOLCHANGER_DIAMETER,
        CM_TOOLCHANGER_HEIGHT
    } evxCmToolAttr;

    /**
    @brief cam holder struct
    @ingroup zwapi_cm_tool
    */
    typedef struct svxCmToolHolderLayer
    {
        double top;    /**<@brief  cam holder top value */
        double bottom; /**<@brief  cam holder bottom value */
        double height; /**<@brief  cam holder height value */
    } svxCmToolHolderLayer;

    /**
    @brief cam tool coolant type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolCoolant
    {
        CM_TOOL_COOLANT_FLOOD = 1, /**<@brief  coolant Flood */
        CM_TOOL_COOLANT_MIST,      /**<@brief  coolant Mist */
        CM_TOOL_COOLANT_THROUGH,   /**<@brief  coolant Through */
        CM_TOOL_COOLANT_AIR,       /**<@brief  coolant Air */
        CM_TOOL_COOLANT_OFF        /**<@brief  coolant Off */
    } evxCmToolCoolant;

    //====================================================================================================================
    /** @name Cam Tool Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_tool

    Insert a tool into active CamPlan.

    @param [in] tltype tool type
    @param [in] subtype sub type of tool
    @param [out] idx_tool index of the new tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmToolInsert(evxCmToolType tltype, evxCmToolSubType subtype, int *idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Insert the tool from the library into CamPlan.
    @deprecated This API will not be updated anymore, please use ZwCamToolInsertFromLibrary()
    @see ZwCamToolInsertFromLibrary

    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] tool_name tool name
    @param [out] idx_tool tool index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETFORMSTATE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmToolInsertAsTemplate(const vxLongPath template_path, const vxName file_name, const vxName library_name, const vxName tool_name, int *idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Delete the tool in CamPlan.

    @param [in] idx_tool index of the tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxCmToolDelete(int idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Insert the holder from the library into CamPlan.
    @deprecated This API will not be updated anymore.

    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] holder_name holder name
    @param [out] idx_holder holder index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmHolderInsertAsTemplate(const vxLongPath template_path, const vxName file_name,
                                                   const vxName library_name, const vxName holder_name, int *idx_holder);

    /**
    @ingroup zwapi_cm_tool

    Insert the speed from the library into CamPlan.
    @deprecated This API will not be updated anymore.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] spdfd_name speed   name
    @param [out] idx_speed speed index

    */
    ZW_API_C evxErrors cvxCmSpeedInsertAsTemplate(const vxLongPath template_path, const vxName file_name,
                                                  const vxName library_name, const vxName spdfd_name, int *idx_speed);

    /**
    @ingroup zwapi_cm_tool

    Inquire the tool's attribute.

    @param [in] tool_idx index of the tool
    @param [in] attr enumeration of tool attribute
    @param [out] value value of the attribute, caller should allocate memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETTOOLNAME_ERROR
    -        ZW_API_CAM_GETTOOLTYPE_ERROR
    -        ZW_API_CAM_GETTOOLSUBTYPE_ERROR
    -        ZW_API_CAM_GETTOOLID_ERROR
    -        ZW_API_CAM_GETTOOLLEN_ERROR
    -        ZW_API_CAM_GETTOOLDIA_ERROR
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmToolGetData(int tool_idx, evxCmToolAttr attr, char *value);

    /**
    @ingroup zwapi_cm_tool

    Get the tool register

    @param [in] idx_tool index of the tool
    @param [out] toolId register tool id
    @param [in] sizeToolId size of Register tool id
    @param [out] Dreg register tool Diameter
    @param [in] sizeDreg Size of register tool Diameter
    @param [out] Hreg register tool Height
    @param [in] sizeHreg size of Register tool Height

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetRegister(int idx_tool, char *toolId, int sizeToolId, char *Dreg, int sizeDreg, char *Hreg, int sizeHreg);

    /**
    @ingroup zwapi_cm_tool

    Set the tool register

    @param [in] idx_tool index of the tool
    @param [in] toolId register tool id
    @param [in] Dreg register tool Diameter
    @param [in] Hreg register tool Height

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    */
    ZW_API_C evxErrors cvxCmToolSetRegister(int idx_tool, const char *toolId, const char *Dreg, const char *Hreg);


    /**
    @ingroup zwapi_cm_tool

    Set the tool coolant

    @param [in] idx_tool index of the tool
    @param [in] coolant tool coolant type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLCOOLANT_ERROR
    */
    ZW_API_C evxErrors cvxCmToolSetCoolant(int idx_tool, evxCmToolCoolant coolant);

    /**
    @ingroup zwapi_cm_tool

    Get the tool coolant

    @param [in] idx_tool index of the tool
    @param [out] coolant tool coolant type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLCOOLANT_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetCoolant(int idx_tool, evxCmToolCoolant *coolant);

    /**
    @ingroup zwapi_cm_tool

    Add a new holder or add a new holder layer

    @param [in] tool_idx index of the tool
    @param [in] holderLayer one holder layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    ZW_API_C evxErrors cvxCmToolAddHolderLayer(int tool_idx, const svxCmToolHolderLayer *holderLayer);

    /**
    @ingroup zwapi_cm_tool

    Delete a holder layer

    @param [in] tool_idx index of the tool
    @param [in] layerIndex holder layer index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOL_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    ZW_API_C evxErrors cvxCmToolDelHolderLayer(int tool_idx, int layerIndex);

    /**
    @ingroup zwapi_cm_tool

    Inquire the holder's attribute.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] tool_idx index of the tool
    @param [out] layerCnt holder layer count
    @param [out] holderLayers holder all layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_GETHOLDERINFO_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetHolderLayers(int tool_idx, int *layerCnt, svxCmToolHolderLayer **holderLayers);


    /**
    @ingroup zwapi_cm_tool

    Set the holder's attribute.

    @param [in] tool_idx index of the tool
    @param [in] layerIndex holder layer index
    @param [in] holderLayer holder one layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_GETHOLDERINFO_ERROR
    */
    ZW_API_C evxErrors cvxCmToolSetHolderLayer(int tool_idx, int layerIndex, const svxCmToolHolderLayer *holderLayer);

    /**
    @ingroup zwapi_cm_tool

    Set the spindle speed value

    @param [in] tool_idx index of the tool
    @param [in] rowIdx spindle speed row index
    @param [in] spdValue spindle speed value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmToolSetSpindleSpd(int tool_idx, int rowIdx, double spdValue);

    /**
    @ingroup zwapi_cm_tool

    Get the spindle speed value

    @param [in] tool_idx index of the tool
    @param [in] rowIdx spindle speed row index
    @param [out] spdValue spindle speed value
    @param [out] spdUnit spindle speed unit
    @param [in] spdUnitSize spindle speed unit size

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_INVALID_OUTPUT  
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetSpindleSpd(int tool_idx, int rowIdx, double *spdValue, char *spdUnit, int spdUnitSize);

    /**
    @ingroup zwapi_cm_tool

    Set the Feed Rate value

    @param [in] tool_idx index of the tool
    @param [in] rowIdx Feed Rate row index
    @param [in] pzFeedRate Feed Rate struct

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmToolSetFeedRate(int tool_idx, int rowIdx, const svxFeedRate *pzFeedRate);

    /**
    @ingroup zwapi_cm_tool

    Get the Feed Rate value

    @param [in] tool_idx index of the tool
    @param [in] rowIdx Feed Rate row index
    @param [out] pzFeedRate Feed Rate struct

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetFeedRate(int tool_idx, int rowIdx, svxFeedRate *pzFeedRate);

    /**
    @ingroup zwapi_cm_tool

    Get the Spindle speed, Feed Rate table row count

    @param [in] tool_idx index of the tool
    @param [out] rowCnt Spindle Speed, Feed Rate row count

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetSpdFdRowCnt(int tool_idx, int *rowCnt);


    /**
    @ingroup zwapi_cm_tool

    Set the Holder Name

    @param [in] idx_tool index of the tool
    @param [in] holderName Holder Name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    ZW_API_C evxErrors cvxCmToolRenameHolder(int idx_tool, const char *holderName);

    /**
    @ingroup zwapi_cm_tool

    Get the Holder Name

    @param [in] idx_tool index of the tool
    @param [out] holderName Holder Name
    @param [in] sizeHolderName size of holder name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETHOLDER_ERROR
    */
    ZW_API_C evxErrors cvxCmToolGetHolderName(int idx_tool, char *holderName, int sizeHolderName);

    /**
    @ingroup zwapi_cm_tool

    Open the tool form, default mill tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C evxErrors cvxCmToolOpenMillForm(void);

    //====================================================================================================================
    /** @name Cam Tool Function */
    //====================================================================================================================

    /**
    @ingroup ZwCamTool

    Insert a tool into active CamPlan from tool library. 
    If the library path is empty and the file name is not empty, it will search 
    the file from the resource path.

    @note
    This interface is not supported lathe tool now.

    @param [in] library_path library path. It may be empty but cannot be NULL.
    @param [in] file_name library file name.
    @param [in] tool_name tool name in library
    @param [out] idx_tool index of the new tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwCamToolInsertFromLibrary(const vxLongPath library_path, const vxLongName file_name, const vxLongName tool_name, int *idx_tool);


    /**
    @ingroup ZwCamTool

    Export all tools in the plan to the spec tool library file.

    @param [in] library_path library path
    @param [in] file_name file name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwCamToolExportAllToLibrary(const vxLongPath library_path, const vxLongName file_name);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_TOOL_H */
