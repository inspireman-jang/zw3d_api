/**
@file zwapi_assembly_constraint_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the assembly constraint
*/

#pragma once

#ifndef ZW_API_ASM_CONSTRAINT_DATA_H
#define ZW_API_ASM_CONSTRAINT_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief assembly constraint type
    @ingroup ZwAssemblyConstraintData
    */
    typedef enum ezwAssemblyConstraintType
    {
        ZW_CONSTRAINT_NONE              = 0x00000L,   /**<@brief  Concentric constraint */
        ZW_CONSTRAINT_CONCENTRIC        = 0x00001L,   /**<@brief  Concentric constraint */
        ZW_CONSTRAINT_COINCIDENT        = 0x00002L,   /**<@brief  Coincident constraint */
        ZW_CONSTRAINT_TANGENT           = 0x00004L,   /**<@brief  Tangent constraint */
        ZW_CONSTRAINT_PARALLEL          = 0x00008L,   /**<@brief  Parallel constraint */
        ZW_CONSTRAINT_PERPENDICULAR     = 0x00010L,   /**<@brief  Perpendicular constraint */
        ZW_CONSTRAINT_AT_DISTANCE       = 0x00040L,   /**<@brief  Distance constraint */
        ZW_CONSTRAINT_AT_ANGLE_FULL     = 0x00080L,   /**<@brief  At angle constraint */
        ZW_CONSTRAINT_GEAR              = 0x00100L,   /**<@brief  Gear constraint */
        ZW_CONSTRAINT_SYMMETRIC         = 0x00200L,   /**<@brief  Symmetry constraint */
        ZW_CONSTRAINT_ADV_LOCKED        = 0x00400L,   /**<@brief  Lock constraint */
        ZW_CONSTRAINT_ADV_MIDDLE        = 0x00800L,   /**<@brief  Middle constraint */
        ZW_CONSTRAINT_ADV_FRAME         = 0x01000L,   /**<@brief  Frame constraint */
        ZW_CONSTRAINT_ADV_PATH          = 0x02000L,   /**<@brief  Path constraint */
        ZW_CONSTRAINT_MC_LINEAR_COUPLER = 0x04000L,   /**<@brief  Linear couple constraint */
        ZW_CONSTRAINT_MC_RACK_PINION    = 0x08000L,   /**<@brief  Rack and pinion constraint */
        ZW_CONSTRAINT_MC_SCREW          = 0x10000L,   /**<@brief  Screw constraint */
        ZW_CONSTRAINT_MC_SLOT           = 0x2000000L, /**<@brief  Slot constraint */
        ZW_CONSTRAINT_MC_CAM            = 0x4000000L, /**<@brief  Cam constraint */
        ZW_CONSTRAINT_MC_UNIV_JOINT     = 0x00104L,   /**<@brief  universal joint constraint */
    } ezwAssemblyConstraintType;

    /**
    @brief custom data for assembly common constraint
    @ingroup ZwAssemblyConstraintData
    */
    typedef struct szwAssemblyConstraintData
    {
        int useRange;      /**<@brief  whether to apply constraint range (0-default) */
        double value;      /**<@brief  exact value: offset distance or constraint angle (degree) (0.0-default) */
        szwLimit range;    /**<@brief  constraint range: offset distance or constraint angle (degree) */
        int sameDirection; /**<@brief  same direction (0-default) */
        int lockRotation;  /**<@brief  whether to lock rotation (0-default) */
        int positionOnly;  /**<@brief  only move position without creating constraint (0-default) */
    } szwAssemblyConstraintData;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_ASM_CONSTRAINT_DATA_H */
