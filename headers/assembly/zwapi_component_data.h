/**
@file zwapi_component_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for the component.
*/

#pragma once
#ifndef ZW_API_COMPONENT_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_COMPONENT_DATA_H

#include "zwapi_util.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Component Data */
    //====================================================================================================================

    /**
    @brief component insertion layout type
    @ingroup ZwComponentData
    */
    typedef enum ezwComponentInsertLayoutType
    {
        ZW_COMPONENT_INSERT_LAYOUT_CIRCULAR = 1, /**<@brief  circular */
        ZW_COMPONENT_INSERT_LAYOUT_LINEARE  = 2, /**<@brief  linear */
    } ezwComponentInsertLayoutType;

    /**
    @brief component insertion position type
    @ingroup ZwComponentData
    */
    typedef enum ezwComponentInsertPositionType
    {
        ZW_COMPONENT_INSERT_POSITION_DIAMETER     = 1, /**<@brief  diameter */
        ZW_COMPONENT_INSERT_POSITION_CENTERTPOINT = 1, /**<@brief  center point */
        ZW_COMPONENT_INSERT_POSITION_OFFSET       = 2, /**<@brief  offset */
    } ezwComponentInsertPositionType;

    /**
    @brief component insertion auto hole match filter type
    @ingroup ZwComponentData
    */
    typedef enum ezwComponentInsertHoleFilterType
    {
        ZW_COMPONENT_INSERT_HOLE_FILTER_ALL          = 0, /**<@brief  get all holes */
        ZW_COMPONENT_INSERT_HOLE_FILTER_SIMPLE       = 1, /**<@brief  get simple hole */
        ZW_COMPONENT_INSERT_HOLE_FILTER_TAPERED      = 2, /**<@brief  get tapered hole */
        ZW_COMPONENT_INSERT_HOLE_FILTER_COUNTER_BORE = 3, /**<@brief  get counter bore hole */
        ZW_COMPONENT_INSERT_HOLE_FILTER_COUNTER_SINK = 4, /**<@brief  get counter sink hole */
        ZW_COMPONENT_INSERT_HOLE_FILTER_SPOT_FACE    = 5, /**<@brief  get spot face hole */
    } ezwComponentInsertHoleFilterType;

    /**
    @brief component file save as option
    @ingroup ZwComponentData
    */
    typedef enum ezwComponentSaveAsOption
    {
        ZW_COMPONENT_SAVE_AS_OPTION_ALL        = -1, /**<@brief  save all components with same name */
        ZW_COMPONENT_SAVE_AS_OPTION_SINGLE     = 0,  /**<@brief  only save specified component */
        ZW_COMPONENT_SAVE_AS_OPTION_SAME_LEVEL = 1,  /**<@brief  save  components with same name in the same level */
    } ezwComponentSaveAsOption;
    /**
    @brief component insertion instance data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInsertInstanceData
    {
        int autoRegen;  /**<@brief  0 is default. 0 to set manual regen
                                       ** 1 to set auto regen before insert
                                       ** 2 to set auto regen after insert
                                       */
        int autoDelete; /**<@brief  0 is default. 1 to delete component when parent is deleted, or 0 */

        int copyPart;               /**<@brief  0 is default. 1 to copy "Part" before instancing, or 0. */
        zwString256 copyName;       /**<@brief  name to assign to copied part
                                       ** if no name is given, the default name is output
                                       ** this param will take effect only when copyPart = 1.
                                       */
        int copyEntireAssemblyPart; /**<@brief  0 is default. 1 to copy "Part" before instancing, or 0
                                       ** this param will take effect only when copyPart = 1.
                                       */
        int overwrite;              /**<@brief  1(default) to prompt whether to overwrite existing part
                                       ** 0 to automatically avoid overwriting existing part
                                       ** -1 to automatically overwrite existing part
                                       */
    } szwComponentInsertInstanceData;

    /**
    @brief component insertion settings data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInsertSettingsData
    {
        int pocket;                                    /**<@brief  set pocket component. 0 is default, not to pocket. 1 to pocket */
        int pocketColorFromPart;                       /**<@brief  set color of pocket component.
                                       ** 0 is default, use user specified color. 1 to user color from part.
                                       ** this param will take effect only when pocket = 1.
                                       */
        szwColor color;                                /**<@brief  set color of pocket component
                                       ** this param will take effect only when pocketColorFromPart = 0.
                                       */
        szwEntityHandle *intersectionEntityHandleList; /**<@brief  intersection entity handles list
                                       ** this param will take effect only when pocket = 1.
                                       */
        int numIntersectionEntity;                     /**<@brief  number of intersection entity handles in list.
                                       ** this param will take effect only when pocket = 1.
                                       */

        int envelope;         /**<@brief  envelope component. 0 is default, not to envelope. 1 to envelope. */
        int insertToLayer;    /**<@brief  insert component into specified layer, 0 is default.
                                       ** 0 - insert to active layer
                                       ** 1 - insert to specified layer
                                       */
        zwString32 layerName; /**<@brief  name of layer that component insert to.
                                       ** this param will take effect only when insertToLayer = 1.
                                       */
        int inheritLayer;     /**<@brief  inherit component's layer, 1 is default.
                                       ** this param will take effect only when assembly layer is open.
                                       */
    } szwComponentInsertSettingsData;

    /**
    @brief component insertion data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInsertData
    {
        /* Required */
        zwPath pathFile; /**<@brief  path/file, must include file name, path is optional.
                          **for more detail please see the description of ZwComponentInsert */

        zwRootName root;       /**<@brief  root of multiroot file to instance as a component */
        zwString32 configName; /**<@brief  config name, set "configName[0]=0" to use active config */

        /* Placement */
        int anchor;                             /**<@brief  0 is default. 1 to anchor component, or 0 */
        szwEntityHandle *alignFaceDatumHandle;  /**<@brief  handle of face or datum you want to align when inserting. NULL to ignore. */
        szwEntityHandle *referenceEntityHandle; /**<@brief  handle of entity you want to reference when inserting. NULL to ignore. */
        szwMatrix *frame;                       /**<@brief  frame to locate component's position. 
                                                 **It can set to NULL when alignFaceDatumHandle is not NULL,
                                                 **in this situation, the type of alignFaceDatumHandle only can be ZW_ENTITY_DATUM,
                                                 **and will add "frame" constraint to component */

        /* Instance */
        szwComponentInsertInstanceData instanceData; /**<@brief  instance data */
        /* Settings */
        szwComponentInsertSettingsData settingsData; /**<@brief  settings data */
    } szwComponentInsertData;

    /**
    @brief new component insertion settings data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInsertNewSettingsData
    {
        int autoActivated;    /**<@brief  auto activate new inserted component, 1 is default.
                                       ** this param will take effect only when inserting a new component.
                                       */
        int envelope;         /**<@brief  envelope component. 0 is default, not to envelope. 1 to envelope. */
        int virtualFlag;      /**<@brief  make new inserted component virtual, 0 is default.
                                       ** this param will take effect only when inserting a new component.
                                       */
        int insertToLayer;    /**<@brief  insert component into specified layer, 0 is default.
                                       ** 0 - insert to active layer
                                       ** 1 - insert to specified layer
                                       */
        zwString32 layerName; /**<@brief  name of layer that component insert to.
                                       ** this param will take effect only when insertToLayer = 1.
                                       */
    } szwComponentInsertNewSettingsData;

    /**
    @brief new component insertion data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInsertNewData
    {
        /* Required */
        zwPath file;              /**<@brief  file name, for more detail please see the description of ZwComponentInsertNew */
        zwRootName root;          /**<@brief  root of multiroot file to instance as a component */
        zwString256 templateName; /**<@brief  template name, set "templateName[0]=0" to use system template
                                             **taking effect only when inserting a new component.
                                             */
        /* Placement */
        int anchor;                             /**<@brief  0 is default. 1 to anchor component, or 0 */
        szwEntityHandle *alignFaceDatumHandle;  /**<@brief  handle of face or datum insert to. NULL to ignore. */
        szwEntityHandle *referenceEntityHandle; /**<@brief  handle of entity you want to reference when inserting. NULL to ignore. */
        szwMatrix *frame;                       /**<@brief  frame to locate component's position. 
                                                 **It can set to NULL when alignFaceDatumHandle is not NULL,
                                                 **in this situation, the type of alignFaceDatumHandle only can be ZW_ENTITY_DATUM,
                                                 **and will add "frame" constraint to component */

        /* Settings */
        szwComponentInsertNewSettingsData settingsData; /**<@brief  settings data */
    } szwComponentInsertNewData;

    /**
    @brief interference data for interference check
    @ingroup ZwComponentData
    */
    typedef struct szwInterferenceData
    {
        szwEntityHandle componentHandle; /**<@brief  component handle for interference check */
        int subAssemblyAsWhole;          /**<@brief  1: consider sub-assembly as a whole, don't check interference inside sub-assembly
                                                     0: check interference inside sub-assembly */
    } szwInterferenceData;

    /**
    @brief Component interference check data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInterferenceCheckData
    {
        int countComponent;                     /**<@brief  count of components that need to check interference */
        szwInterferenceData *componentDataList; /**<@brief  interference data for interference check */
        int ignoreHidden;                       /**<@brief  1 to ignore the hidden components within the sub-assembly,  else 0 */
        int ignoreSuppress;                     /**<@brief  1 to ignore the suppressed component, else 0 */
        int ignoreOpen;                         /**<@brief  1 to ignore the open shape in component, else 0 */
        int saveInterferenceGeometry;           /**<@brief  1 to save interference geometry, else 0 */
    } szwComponentInterferenceCheckData;

    /**
    @brief Component interference result data
    @ingroup ZwComponentData
    */
    typedef struct szwComponentInterferenceResultData
    {
        szwEntityHandle baseComponentHandle;  /**<@brief  base component handle for interference check */
        zwString256 baseComponentName;        /**<@brief  base component name for interference check */
        szwEntityHandle checkComponentHandle; /**<@brief  check component handle for interference check */
        zwString256 checkComponentName;       /**<@brief  check component name for interference check */
        double interferenceVolme;             /**<@brief  volume of interference (mm^3) */
        szwEntityHandle interferenceHandle;   /**<@brief  interference shape handle,
                                                          invalid if szwComponentInterferenceCheckData::saveInterferenceGeometry = 0 */
    } szwComponentInterferenceResultData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_ASM_DATA_H */
