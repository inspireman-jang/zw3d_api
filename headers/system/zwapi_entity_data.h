/**
@file zwapi_entity_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Entity General Data
*/

#ifndef ZW_API_ENTITY_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_ENTITY_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Entity Get */
    //====================================================================================================================
    /**
    @brief entity input options
    @ingroup ZwEntityData
    */
    typedef enum ezwEntityInputOption
    {
        ZW_INPUT_UNDEFINED          = 0,  /**<@brief  undefined */
        ZW_INPUT_GENERAL_3D         = 1,  /**<@brief  pick 3d general entity */
        ZW_INPUT_GENERAL_2D         = 2,  /**<@brief  pick 2d general entity */
        ZW_INPUT_SHAPE              = 3,  /**<@brief  pick shape */
        ZW_INPUT_FACE               = 4,  /**<@brief  pick face */
        ZW_INPUT_SHAPE_OR_FACE      = 5,  /**<@brief  pick shape or face */
        ZW_INPUT_EDGE               = 6,  /**<@brief  pick edge */
        ZW_INPUT_CURVE              = 7,  /**<@brief  pick curve */
        ZW_INPUT_EDGE_OR_CURVE      = 8,  /**<@brief  pick edge or curve */
        ZW_INPUT_CURVE_LIST         = 9,  /**<@brief  pick curve list */
        ZW_INPUT_PARTING_CURVE      = 10, /**<@brief  pick parting curve */
        ZW_INPUT_POINT              = 11, /**<@brief  pick point */
        ZW_INPUT_FEATURE            = 12, /**<@brief  pick feature */
        ZW_INPUT_SKETCH             = 13, /**<@brief  pick sketch */
        ZW_INPUT_DATUM_PLANE        = 14, /**<@brief  pick datum plane */
        ZW_INPUT_REFERENCE_PLANE    = 15, /**<@brief  pick reference plane */
        ZW_INPUT_3D_BLOCK           = 16, /**<@brief  pick 3d block */
        ZW_INPUT_LIGHT              = 17, /**<@brief  pick light */
        ZW_INPUT_LAYER              = 18, /**<@brief  pick layer */
        ZW_INPUT_REFERENCE_GEOMETRY = 19, /**<@brief  pick reference geometry */
        ZW_INPUT_WIREFRAME          = 20, /**<@brief  pick wireframe */
        ZW_INPUT_MOVE               = 21, /**<@brief  pick move */
        ZW_INPUT_BLANK              = 22, /**<@brief  pick blank */
        ZW_INPUT_ERASE              = 23, /**<@brief  pick erase */
        ZW_INPUT_INQUIRE            = 24, /**<@brief  pick inquire */
        ZW_INPUT_3D_GEOMETRY        = 25, /**<@brief  pick 3d geometry */
        ZW_INPUT_TEXT               = 26, /**<@brief  pick text */
        ZW_INPUT_PROFILE            = 27, /**<@brief  pick profile */
        ZW_INPUT_COMPONENT          = 28, /**<@brief  select the top-level component */
        ZW_INPUT_ASSEMBLY_SHAPE     = 29, /**<@brief  pick shape in the assembly */
        ZW_INPUT_FACE_ON_SHAPE      = 30, /**<@brief  pick face on shape */
        ZW_INPUT_SUB_COMPONENT      = 31, /**<@brief  pick sub-component in pick-path, instead of the top-level component */
        ZW_INPUT_CSYS               = 32, /**<@brief  pick CSYS */
        ZW_INPUT_AXIS_3D            = 33, /**<@brief  pick 3d axis */
        ZW_INPUT_AXIS_2D            = 34, /**<@brief  pick 2d axis */
        ZW_INPUT_CURVE_2D           = 35, /**<@brief  pick curve in 2d */
    } ezwEntityInputOption;

    //====================================================================================================================
    /** @name Entity Regen */
    //====================================================================================================================
    /**
    @brief entity regenerate mode
    @ingroup ZwEntityData
    */
    typedef enum ezwEntityRegenMode
    {
        ZW_REGEN_FOR_HISTORY                = 0, /**<@brief  regen history for the activated file. */
        ZW_REGEN_FOR_OUTDATED_OBJECTS       = 1, /**<@brief  regen outdated for the activated file. */
        ZW_REGEN_FOR_ASSEMBLY_ALL_COMPONENT = 2, /**<@brief  regen all component for the activated assembly. */
    } ezwEntityRegenMode;

    /**
    @brief View reference geometry list
    @ingroup ZwEntityData
    */
    typedef struct szwReferenceViewGeometryList
    {
        szwEntityHandle sheetHandle;            /**<@brief  Sheet handle. */
        szwEntityHandle viewHandle;             /**<@brief  View handle. */
        int geometryCount;                      /**<@brief the count of geometry list . */
        szwEntityHandle *referenceGeometryList; /**<@brief view geometry list . */
    } szwReferenceViewGeometryList;


    /**
    @brief sheet reference geometry list
    @ingroup ZwEntityData
    */
    typedef struct szwReferenceSheetGeometryList
    {
        szwEntityHandle sheetHandle;                     /**<@brief  View referenced sheet. */
        int viewCount;                                   /**<@brief the count of geometry list . */
        szwReferenceViewGeometryList *referenceViewList; /**<@brief sheet geometry list . */
    } szwReferenceSheetGeometryList;
    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_ENTITY_DATA_H */
