/**
@file zwapi_cm_op_param_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Operation Parameters.
*/

#pragma once
#ifndef ZW_API_CAM_OPERATION_PARAM_ENUM_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_OPERATION_PARAM_ENUM_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief cam opdef stepover type
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOpStepoverType
    {
        ZW_CAM_OP_STEPOVER_TYPE_NONE                  = 0, /**<@brief Invalid stepover type */
        ZW_CAM_OP_STEPOVER_TYPE_PERCENT_TOOL_DIAMETER = 1, /**<@brief Stepover type of % Tool Diameter */
        ZW_CAM_OP_STEPOVER_TYPE_ABSOLUTE              = 2, /**<@brief Stepover type of absolute value */
        ZW_CAM_OP_STEPOVER_TYPE_SCALLOP               = 3, /**<@brief Stepover type of scallop height */
    } ezwCamOpStepoverType;

    /**
    @brief cam opdef feed unit
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOpFeedUnit
    {
        ZW_CAM_OP_FEED_NONE           = 0, /**<@brief Invalid feed unit type */
        ZW_CAM_OP_FEED_PER_MINUTE     = 1, /**<@brief Feed unit type of value per minute */
        ZW_CAM_OP_FEED_PER_REVOLUTION = 2  /**<@brief Feed unit type of value per revolution */
    } ezwCamOpFeedUnit;

    /**
    @brief cam opdef spindle mode
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOpSpindleMode
    {
        ZW_CAM_OP_SPINDLE_MODE_NONE = 0, /**<@brief Invalid spindle mode */
        ZW_CAM_OP_SPINDLE_MODE_RPM  = 1, /**<@brief Spindle mode of Revolution Per Minute */
        ZW_CAM_OP_SPINDLE_MODE_SMM  = 2  /**<@brief Spindle mode of Surface Meter/Min */
    } ezwCamOpSpindleMode;

    /**
    @brief cam opdef thick type
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOpThickType
    {
        ZW_CAM_OP_THICK_TYPE_NONE  = 0, /**<@brief Invalid thick type */
        ZW_CAM_OP_THICK_TYPE_SIDE  = 1, /**<@brief Thick type of dividing thick and axial thick */
        ZW_CAM_OP_THICK_TYPE_TOTAL = 2, /**<@brief Thick type of not dividing thick and aixal thick */
    } ezwCamOpThickType;

    /**
    @brief cam opdef lead mode for 2x mill
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOp2xMillLeadMode
    {
        ZW_CAM_OP_LEAD_MODE_INTELLIGENT = 0, /**<@brief opdef lead mode intelligent */
        ZW_CAM_OP_LEAD_MODE_MANUAL      = 1  /**<@brief opdef lead mode manual */
    } ezwCamOp2xMillLeadMode;

    /**
    @brief cam opdef intelligent lead in/out type for 2x mill
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOp2xMillIntelLeadType
    {
        ZW_CAM_OP_INTEL_LEAD_TYPE_INVALID                = 0, /**<@brief opdef lead type invalid */
        ZW_CAM_OP_INTEL_LEAD_TYPE_LINEAR                 = 1, /**<@brief opdef lead type linear */
        ZW_CAM_OP_INTEL_LEAD_TYPE_LINEAR_LINEAR          = 2, /**<@brief opdef lead type linear linear */
        ZW_CAM_OP_INTEL_LEAD_TYPE_CIRCULAR_LINEAR        = 3, /**<@brief opdef lead type circular linear */
        ZW_CAM_OP_INTEL_LEAD_TYPE_CIRCULAR_LINEAR_LINEAR = 4, /**<@brief opdef lead type circular linear linear */
        ZW_CAM_OP_INTEL_LEAD_TYPE_CIRCULAR_SLOPE         = 5, /**<@brief opdef lead type circular slope */
        ZW_CAM_OP_INTEL_LEAD_TYPE_NONE                   = 6  /**<@brief opdef lead type none */
    } ezwCamOp2xMillIntelLeadType;

    /**
    @brief cam operation parameters
    @ingroup ZwCamOpParam
    */
    typedef enum ezwCamOpParam
    {
        /**
        @brief Stepover type
        @note Input type should be "ezwCamOpStepoverType"
        @see ezwCamOpStepoverType
        */
        ZW_CAM_OP_STEPOVER_TYPE = 1,

        /**
        @brief Scallop height
        @note Input type should be "double"
        @see ezwCamOpStepoverType
        */
        ZW_CAM_OP_STEPOVER_SCALLOP,

        /**
        @brief Percent value of tool diameter used by stepover.
        @note Input type should be "double"
        @see ezwCamOpStepoverType
        */
        ZW_CAM_OP_STEPOVER_PERCENT_TOOL_DIAMETER,

        /**
        @brief Absolute value of stepover.
        @note Input type should be "double"
        @see ezwCamOpStepoverType
        */
        ZW_CAM_OP_STEPOVER_ABSOLUTE,

        /**
        @brief Thick type.
        @note Input type should be "ezwCamOpThickType"
        @see ezwCamOpThickType
        */
        ZW_CAM_OP_THICK_TYPE,

        /**
        @brief Part side thick.
        @note Input type should be "double"
        */
        ZW_CAM_OP_THICK,

        /**
        @brief Axial thick.
        @note Input type should be "double"
        */
        ZW_CAM_OP_AXIAL_THICK,

        /**
        @brief Spindle speed in RPM.
        @note Input type should be "double"
        */
        ZW_CAM_OP_SPINDLE_RPM,

        /**
        @brief Cut feedrate.
        @note Input type should be a pointer to cut feedrate structure.
        */
        ZW_CAM_OP_FEED_CUT,

        /**
        @brief Absolute value of stepover.
        @note Input type should be "double"
        @see ezwCamOpStepoverType
        */
        ZW_CAM_OP_STEPDOWN_ABSOLUTE,

        /**
        @brief Tool db index.
        @note Input type should be "int"
        */
        ZW_CAM_OP_TOOL,

        /**
        @brief String of operation type.
        @note Input type should be "string"
        */
        ZW_CAM_OP_TYPE_STR,

        /**
        @brief Name of operation.
        @note Input type should be "string"
        */
        ZW_CAM_OP_NAME,

        /**
        @brief Value of operation travel total cut distance.
        @note Input type should be "double"
        */
        ZW_CAM_OP_TRAVEL_DIST_TOTAL,

        /**
        @brief Value of operation travel no-cut cut distance.
        @note Input type should be "double"
        */
        ZW_CAM_OP_TRAVEL_DIST_NOCUT,

        /**
        @brief Value of operation travel total cut time.
        @note Input type should be "double"
        */
        ZW_CAM_OP_TRAVEL_TIME_TOTAL,

        /**
        @brief Value of operation travel no-cut cut time.
        @note Input type should be "double"
        */
        ZW_CAM_OP_TRAVEL_TIME_NOCUT,

        /**
        @brief 2x Mill opdef lead mode.
        @note Input type should be "ezwCamOp2xMillLeadMode"
        @see ezwCamOp2xMillLeadMode
        */
        ZW_CAM_OP_MILL2_LEAD_MODE,

        /**
        @brief 2x Mill opdef intelligent lead in type.
        @note Input type should be "ezwCamOp2xMillIntelLeadType"
        @see ezwCamOp2xMillIntelLeadType
        */
        ZW_CAM_OP_MILL2_INTEL_LEAD_IN_TYPE,

        /**
        @brief 2x Mill opdef intelligent lead out type.
        @note Input type should be "ezwCamOp2xMillIntelLeadType"
        @see ezwCamOp2xMillIntelLeadType
        */
        ZW_CAM_OP_MILL2_INTEL_LEAD_OUT_TYPE,

        ZW_CAM_OP_PARAM_SIZE
    } ezwCamOpParam;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_OPERATION_PARAM_ENUM_H */
