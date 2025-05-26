/**
@file zwapi_sheet_metal_data.h
@(C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sheet Metal Data Types and Structures of the
functions of sheet metal API
*/

#pragma once
#ifndef ZW_API_SHEET_METAL_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SHEET_METAL_DATA_H

#include "zwapi_util.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sheet Metal Attribute Data */
    //====================================================================================================================
    /**
    @brief sheet metal flange parameters position
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalPosition
    {
        ZW_SHEET_METAL_POSITION_MATERIAL_INSIDE,  /**<@brief  Material inside */
        ZW_SHEET_METAL_POSITION_MATERIAL_OUTSIDE, /**<@brief  Material outside */
        ZW_SHEET_METAL_POSITION_NATURAL,          /**<@brief  Natural */
        ZW_SHEET_METAL_POSITION_OFFSET,           /**<@brief  Offset */
        ZW_SHEET_METAL_POSITION_VIRTUAL_SHARP,    /**<@brief  Virtual sharp */
    } ezwSheetMetalPosition;

    /**
    @brief sheet metal bend length type
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalBendLengthType
    {
        ZW_SHEET_METAL_BEND_STANDARD_LENGTH,     /**<@brief  Standard length */
        ZW_SHEET_METAL_BEND_OUTER_HEIGHT,        /**<@brief  Outer height */
        ZW_SHEET_METAL_BEND_INNER_HEIGHT,        /**<@brief  Inner height */
        ZW_SHEET_METAL_BEND_EXTRAPOLATED_LENGTH, /**<@brief  Extrapolated length */
    } ezwSheetMetalBendLengthType;

    /**
    @brief sheet metal K-factor type
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalKFactorType
    {
        ZW_SHEET_METAL_SMD_KTYPE_CUSTOM,                 /**<@brief  custom */
        ZW_SHEET_METAL_SMD_KTYPE_FROM_MATERIAL,          /**<@brief  from material */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_TABLE,             /**<@brief  bend table */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_ALLOWANCE_TABLE,   /**<@brief  bend allowance table */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_ALLOWANCE_FORMULA, /**<@brief  bend allowance formula */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_DEDUCTION_TABLE,   /**<@brief  bend deduction table */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_DEDUCTIOIN,        /**<@brief  bend deduction */
        ZW_SHEET_METAL_SMD_KTYPE_BEND_ALLOWANCE,         /**<@brief  bend allowance, svxExtrudeFlangeData::kType do not apply it. */
    } ezwSheetMetalKFactorType;

    /**
    @brief sheet metal relief type
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalRelief
    {
        ZW_SHEET_METAL_RELIEF_RECTANGLE = 0, /**<@brief  Rectangle */
        ZW_SHEET_METAL_RELIEF_OBROUND   = 1, /**<@brief  Obround */
        ZW_SHEET_METAL_RELIEF_NONE      = 2, /**<@brief  None */
        ZW_SHEET_METAL_RELIEF_STRETCH   = 3, /**<@brief  Stretch */
    } ezwSheetMetalRelief;

    /**
    @brief sheet metal corner relief type
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalCornerRelief
    {
        ZW_SHEET_METAL_CORNER_RELIEF_CLOSED,             /**<@brief  closed */
        ZW_SHEET_METAL_CORNER_RELIEF_CIRCULAR_CUTOUT,    /**<@brief  circular cutout */
        ZW_SHEET_METAL_CORNER_RELIEF_RECTANGULAR_CUTOUT, /**<@brief  rectangular cutout */
        ZW_SHEET_METAL_CORNER_RELIEF_U_CUTOUT,           /**<@brief  U cutout */
        ZW_SHEET_METAL_CORNER_RELIEF_V_CUTOUT,           /**<@brief  V cutout */
    } ezwSheetMetalCornerRelief;

    /**
    @brief sheet metal attribute
    @ingroup ZwSheetMetalData
    */
    typedef struct szwSheetMetalAttribute
    {
        /*  Global Value */
        double thickness; /**<@brief  thickness (1.0 as default)*/
        double radius;    /**<@brief  radius (5.0 as default) */
        /*  Flange Parameters */
        ezwSheetMetalPosition position;         /**<@brief  sheet metal position.default:ZW_SHEET_METAL_POSITION_NATURAL */
        double offset;                          /**<@brief  specify the offset value of the flange 
                                                if position = ZW_SHEET_METAL_POSITION_OFFSET, else ignore.default:0 */
        ezwSheetMetalBendLengthType lengthType; /**<@brief  length type.default:ZW_SHEET_METAL_BEND_STANDARD_LENGTH */
        double length;                          /**<@brief  flange length.default:40 */
        /*  K-factor */
        ezwSheetMetalKFactorType kType; /**<@brief  active sheet metal K factor type*/
        double kFactor;                 /**<@brief  K-Factor (0.41 as default) */
        double kBendDed;                /**<@brief  bend deduction.default:3.5 */
        double kBendAllow;              /**<@brief  bend allowance.default:8.5 */
        /*  Relief */
        ezwSheetMetalRelief reliefType; /**<@brief  relief type.default:ZW_SHEET_METAL_RELIEF_OBROUND */
        double widthRatio;              /**<@brief  relief width ratio.default:1.5 */
        double widthValue;              /**<@brief  relief width value.default:1 */
        double depthRatio;              /**<@brief  relief depth ratio.default:0 */
        double depthValue;              /**<@brief  relief depth value.default:1 */
        /*  Corner Attributes */
        int isCloseCorner;                          /**<@brief  corner close type.default:0 */
        int isMiter;                                /**<@brief  corner miter type.default:1 */
        ezwSheetMetalCornerRelief reliefCornerType; /**<@brief  corner relief type.default: ZW_SHEET_METAL_CORNER_RELIEF_CLOSED */
        double cornerGap;                           /**<@brief  corner gap.default:0.1 */
        int cornerOrigin;                           /**<@brief  corner origin.default:0: Bend Center, 1 Center Point*/
        double cornerOffset;                        /**<@brief  corner offset.default:-1 */
        double cornerLength;                        /**<@brief  corner length.default:4 */
        double cornerWidth;                         /**<@brief  corner width.default:4 */
        double cornerDiameter;                      /**<@brief  corner diameter.default:4 */
        double cornerAngle1;                        /**<@brief  corner angle 1.default:30 */
        double cornerAngle2;                        /**<@brief  corner angle 2.default:30 */
        /*  setting */
        double flatTolerance; /**<@brief  flat tolerance.default:0.1 */
    } szwSheetMetalAttribute;
    
    /**
    @brief bend information
    @ingroup ZwSheetMetalData
    */
    typedef struct szwSmdBendInformation
    {
        double bendSurfaceRadius;    /**<@brief  Bend Surface Radius */
        double neutralSurfaceRadius; /**<@brief  Neutral Surface Radius */
        double angel;                /**<@brief  Angel */
        double thickness;            /**<@brief  Thickness */
        double kFactor;              /**<@brief  K-Factor */
        double flatTolerance;        /**<@brief  Flat Tolerance */
    } szwSmdBendInformation;

    /**
    @brief result data that find faces in sheet metal
    @ingroup ZwSheetMetalData
    */
    typedef struct szwSheetMetalFaceFindData
    {
        int countSameSideFaces;         /**<@brief  count of the same side faces with the seed face */
        szwEntityHandle *sameSideFaces; /**<@brief  handle list of the same side faces with the seed face */
        int countOppositeFaces;         /**<@brief  count of the opposite faces with the seed face */
        szwEntityHandle *oppositeFaces; /**<@brief  handle list of the opposite faces with the seed face */
        int countThickFaces;            /**<@brief  count of the thick faces with the seed face */
        szwEntityHandle *thickFaces;    /**<@brief  handle list of the thick faces with the seed face */
    } szwSheetMetalFaceFindData;

    /**
    @brief sheet metal fold status
    @ingroup ZwSheetMetalData
    */
    typedef enum ezwSheetMetalFoldStatus
    {
        ZW_SHEET_METAL_FOLD_NO_INFORMATION, /**<@brief  There is no information about fold faces, the shape might not be created with sheet metal feature*/
        ZW_SHEET_METAL_FOLD_ALL_FOLD,       /**<@brief  All faces with metal sheet attributes are folded */
        ZW_SHEET_METAL_FOLD_ALL_UNFOLD,     /**<@brief  All faces with metal sheet attributes are unfolded */
        ZW_SHEET_METAL_FOLD_NOT_FULLY_FOLD  /**<@brief  The faces with metal sheet attributes are not all folded */
    } ezwSheetMetalFoldStatus;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHEET_METAL_DATA_H */
