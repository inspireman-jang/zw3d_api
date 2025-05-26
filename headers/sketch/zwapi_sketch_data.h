/**
@file zwapi_sketch_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Sketch
*/

#pragma once
#ifndef ZW_API_SKETCH_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Pattern Constraint Setting */
    //====================================================================================================================
    /**
    @brief sketch pattern type
    @ingroup ZwSketchData
    */
    typedef enum ezwSketchPatternType
    {
        ZW_SKETCH_PATTERN_LINEAR,    /**<@brief linear pattern */
        ZW_SKETCH_PATTERN_CIRCULAR,  /**<@brief circular pattern */
        ZW_SKETCH_PATTERN_AT_CURVES, /**<@brief pattern in space using one or more input curves */
    } ezwSketchPatternType;

    /**
    @brief sketch linear pattern data
    @ingroup ZwSketchData
    */
    typedef struct szwSketchLinearPatternData
    {
        szwVector2 patternDirection; /**<@brief pattern direction */
        int patternNum;              /**<@brief pattern number */
        double pitchDitance;         /**<@brief pattern pitch distance */
    } szwSketchLinearPatternData;

    /**
    @brief sketch pattern data
    @ingroup ZwSketchData
    */
    typedef struct szwSketchPatternData
    {
        ezwSketchPatternType type; /**<@brief pattern type */
        union uzwSketchPatternData /**<@brief union of sketch pattern data */
        {
            struct szwSketchLinear /**<@brief linear pattern */
            {
                szwSketchLinearPatternData patternDirection1; /**<@brief the setting of the first pattern direction */
                int secondDirection;                          /**<@brief whether the setting of the second pattern direction is valid (1: valid; 0: invalid) */
                szwSketchLinearPatternData patternDirection2; /**<@brief the setting of the second pattern direction */
            } linear;
            struct szwSketchCircular /**<@brief circular pattern */
            {
                szwPoint2 patternCenter; /**<@brief pattern rotation center point */
                int patternNum;          /**<@brief pattern number */
                double pitchAngle;       /**<@brief pattern pitch angle */
            } circular;
        } data;
    } szwSketchPatternData;

    //====================================================================================================================
    /** @name Sketch Constraint Query */
    //====================================================================================================================

    /**
    @brief sketch constraint data of geometries
    @ingroup ZwSketchData
    */
    typedef struct szwSketchGeometryConstraintData
    {
        int countOverDefined;              /**<@brief count of over defined geometries */
        szwEntityHandle *overDefinedList;  /**<@brief entity handles of over defined geometries */
        int countUnderDefined;             /**<@brief count of under defined geometries */
        szwEntityHandle *underDefinedList; /**<@brief entity handles of under defined geometries */
        int countWellDefined;              /**<@brief count of well defined geometries */
        szwEntityHandle *wellDefinedList;  /**<@brief entity handles of well defined geometries */
    } szwSketchGeometryConstraintData;


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_DATA_H */
