/**
@file zwapi_feature_shape_data.h
@copyright (C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Commands of Sketch functions.
*/

#pragma once
#ifndef ZW_API_FEATURE_SHAPE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_FEATURE_SHAPE_DATA_H

#include "zwapi_feature_general_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Feature Shape Data */
    //====================================================================================================================

    /**
    @brief offset type
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwOffsetType
    {
        ZW_OFFSET_NONE         = 0, /**<@brief  none */
        ZW_OFFSET_SHRINK       = 1, /**<@brief  Shrink / Expand */
        ZW_OFFSET_THICKEN      = 2, /**<@brief  Thicken */
        ZW_OFFSET_THICKEN_SAME = 3, /**<@brief  Thicken same */
    } ezwOffsetType;
    
    /**
    @brief End caps
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwCapType
    {
        ZW_END_CAP_BOTH  = 0, /**<@brief  both */
        ZW_END_CAP_START = 1, /**<@brief  start */
        ZW_END_CAP_END   = 2, /**<@brief  end */
        ZW_END_CAP_NONE  = 3, /**<@brief  none */
    } ezwCapType;
    
    /**
    @brief the distance method of the distance field, it can set the value by the specified sub-command
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwDistanceMethod
    {
        ZW_INPUT_VALUE    = 0, /**<@brief  the start/end field by the input number*/
        ZW_BY_THROUGH_ALL = 1, /**<@brief  the start/end field by the through all method */
        ZW_TO_POINT       = 2, /**<@brief  the start/end field by the to point method */
        ZW_TO_FACES       = 3, /**<@brief  the start/end field by the to faces method */
        ZW_TO_EXTEND_FACE = 4, /**<@brief  the start/end field by the to extend face method(extrude) */
        ZW_TO_FACE        = 5, /**<@brief  the start/end field by the to extend face method (normal cut) */
    } ezwDistanceMethod;

    /**
    @brief the type of extrude draft blend
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwExtrudeDraftBlend
    {
        ZW_DRFAT_BLEND_VARIABLE = 0, /**<@brief  0-variable*/
        ZW_DRFAT_BLEND_CONSTANT = 1, /**<@brief  1-constant  */
        ZW_DRFAT_BLEND_ROUND    = 2, /**<@brief  2-round */

    } ezwExtrudeDraftBlend;

    /**
    @brief the type of extrude 
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwExtrudeType
    {
        ZW_DRFAT_ONE_SIDE          = 1, /**<@brief  1 side */
        ZW_DRFAT_TWO_SIDES         = 2, /**<@brief  2 sides  */
        ZW_DRFAT_SYMMETRICAL       = 3, /**<@brief  symmetrical */
        ZW_DRFAT_TOTAL_SYMMETRICAL = 4, /**<@brief  total symmetrical */

    } ezwExtrudeType;

    /**
    @brief extruded shape
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwExtrudeData
    {
        zwString32 featureName; /**<@brief  feature name for "FtAllExt", 0 default */

        szwEntityHandle profileHandle; /**<@brief  profile (sketch or curveList) */

        ezwExtrudeType extrudeType; /**<@brief  extrude type */

        double startS; /**<@brief  start distance (mm) */
        double endE;   /**<@brief  end distance (mm) */

        szwVector direction; /**<@brief  optional extrusion direction */

        int flipFaceDirection; /**<@brief  1-flip face direction, else 0 (0:default value, valid when the profileHandle is open or capType == ZW_END_CAP_NONE) */

        struct szwExtrudeBoolean
        {
            ezwBoolType combine;                /**<@brief  combination method */
            int numberBooleanEntityList;        /**<@brief  count of shapes in booleanEntityList array, use 0 if BooleanEnts is NULL*/
            szwEntityHandle *booleanEntityList; /**<@brief  handle list of shapes to combine with extrusion, use NULL if combine is ZW_BOOL_NONE or to
                                    combine extrusion with all visible shapes */
            int reverseRemoveArea;              /**<@brief  1-flip bool remove area, else 0 (0:default value, valid when combine == ZW_BOOL_REMOVE) */
        } boolean;

        struct szwExtrudeDraft
        {
            double draftAngle;                /**<@brief  draft angle (deg) */
            ezwExtrudeDraftBlend blendOption; /**<@brief  corner blend option */
                                              /**<@brief  (0-variable, 1-constant, 2-round) */
            int isUseExtrusionDirection;      /**<@brief  1 to use optional extrusion direction, else 0 */
        } draft;


        struct szwExtrudeOffset
        {
            ezwOffsetType offsetType; /**<@brief  option of offset(set the value of offset and thickness)*/
            double outerOffset;       /**<@brief  outer offset (mm) (0 if undefined) */
            double innerOffset;       /**<@brief  inner offset (mm) (0 if undefined) */

        } offset;


        struct szwExtrudeTransform
        {
            double twistAngle;           /**<@brief  twist angle (deg) */
            szwPointOnEntity twistPoint; /**<@brief  pivot point if twist is non-zero */
        } transform;


        struct szwExtrudeSettings
        {
            ezwCapType capType;           /**<@brief  end cap type (ZW_END_CAP_BOTH as default, invalid if the profileHandle is open) */
            int countCap;                 /**<@brief  count cap face (0 to ignore;
                                    valid if combine is ZW_BOOL_ADD or ZW_BOOL_Remove and the profileHandle is open;
                                    valid if combine is ZW_BOOL_ADD and the profileHandle is close) */
            szwEntityHandle *capFaceList; /**<@brief  cap face handle list (NULL to ignore) */

        } settings;

        ezwDistanceMethod startType;       /**<@brief  start type (0 = input value, 1 = through all, 2= to point, 3 = to faces, 4=to Extend Face) */
        ezwDistanceMethod endType;         /**<@brief  end type (0 = input value, 1 = through all, 2= to point, 3 = to faces, 4=to Extend Face) */
        szwEntityHandle startEntityHandle; /**<@brief  the entity handle of start field if startType > 1 */
        szwEntityHandle endEntityHandle;   /**<@brief  the entity handle of end field if endType > 1 */
        double startOffset;                /**<@brief  start offset value if startType >= 3 */
        double endOffset;                  /**<@brief  end offset value if endType >= 3 */
        szwPoint *startToPoint;            /**<@brief  set the point if startType > 1 , (NULL to ignore, it will use the start point of startEntityHandle) */
        szwPoint *endToPoint;              /**<@brief  set the point if endType > 1 , (NULL to ignore, it will use the start point of endEntityHandle) */


    } szwExtrudeData;

    /**
    @brief block data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwCenterBoxData
    {
        ezwBoolType combine;         /**<@brief  combination method */
        int baseCount;               /**<@brief  base shape count */
        szwEntityHandle *baseList;   /**<@brief  base shape list */
        szwEntityHandle planeHandle; /**<@brief  optional datum plane, or NULL to ignore */
        int useAxis;                 /**<@brief  flag to use axis, 0 default */
        szwAxis axis;                /**<@brief  optional axis */
        szwPoint center;             /**<@brief  center of box volume */
        double x;                    /**<@brief  length along X */
        double y;                    /**<@brief  length along Y */
        double z;                    /**<@brief  length along Z */
        zwString32 featureName;      /**<@brief  feature name for "FtAllBox", empty then use default */
        double tolerance;            /**<@brief  tolerance */
    } szwCenterBoxData;


    /**
    @brief data for creating bool shape
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwBoolData
    {
        int baseCount;                  /**<@brief  the count of base shapes*/
        szwEntityHandle *baseShapes;    /**<@brief  the handle list of base shapes*/
        int toolCount;                  /**<@brief  the count of tool shapes*/
        szwEntityHandle *toolShapes;    /**<@brief  the handle list of tool shapes*/
        int boundaryCount;              /**<@brief  optional, the count of boundary faces*/
        szwEntityHandle *boundaryFaces; /**<@brief  optional, the handle list of boundary faces*/
        int isKeepBase;                 /**<@brief  optional, if keep base shapes, only used in ZwFeatureIntersectCreate, otherwise ignore, the default value is 0*/
        int isKeepTool;                 /**<@brief  optional, if keep tool shapes, the default value is 1*/
        double tolerance;               /**<@brief  optional, tolerance when creating boolean shape, the default value is 0.01*/
    } szwBoolData;

    /**
    @brief loft method
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwLoftType
    {
        ZW_LOFT_PROFILES,             /**<@brief  loft profiles in the order of profiles selection */
        ZW_LOFT_START_POINT_PROFILES, /**<@brief  loft based on starting point and profiles */
        ZW_LOFT_END_POINT_PROFILES,   /**<@brief  loft based on ending point and profiles */
        ZW_LOFT_BOTH_POINTS_PROFILES  /**<@brief  loft based on both end points and profiles */
    } ezwLoftType;

    /**
    @brief loft profile data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwLoftProfile
    {
        szwEntityHandle parent;  /**<@brief  handle of profile curve's parent sketch or curve list (it is recommended to specify the profile curves using the variables count and profiles) */
        szwEntityHandle profile; /**<@brief  handle of profile curve for loft (curve, edge, parting line) */
        int profileDirection;    /**<@brief  specify the orientation of the profile (0 = from start point to end point, otherwise 1) */
        int useStartPoint;       /**<@brief  1 = use the specified starting point, 0 = use the default starting point */
        szwPoint startPoint;     /**<@brief  starting point coordinate, only setting when useStartPnt = 1 */

        int count;               /**<@brief  number of handles of profile curve for loft (curve, edge, parting line) */
        szwEntityHandle *curves; /**<@brief  list of handles of profile curve for loft (curve, edge, parting line) */
    } szwLoftProfile;

    /**
    @brief loft boundary constraints
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwLoftBoundaryConstraints
    {
        int continuity;       /**<@brief  specify the continuity level at end of loft (0 = None, 1 = tangent, 2 = curvature, 3 = flow) */
        int direction;        /**<@brief  specify direction of loft at start and end profiles (0 = perpendicular, 1 = along edges) */
        double weight;        /**<@brief  specify the amount of the loft affected by the enforcement of tangency */
        szwEntityHandle face; /**<@brief  handle of tangency, it's ignored when a single face on the edges or continuity = 0,
                  0 to use default face */
    } szwLoftBoundaryConstraints;

    /**
    @brief loft data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwLoftData
    {
        ezwBoolType combine;              /**<@brief  combination method */
        int baseCount;                    /**<@brief  base shape count */
        szwEntityHandle *baseList;        /**<@brief  base shape list */
        ezwLoftType type;                 /**<@brief  loft method */
        szwEntityHandle startPointParent; /**<@brief  handle of the parent entity where the starting point is located */
        szwPoint startPoint;              /**<@brief  starting point coordinate */
        int profilesNumber;               /**<@brief  number of profiles for loft */
        szwLoftProfile *profiles;         /**<@brief  list of profiles data */
        szwEntityHandle endPointParent;   /**<@brief  handle of the parent entity where the ending point is located */
        szwPoint endPoint;                /**<@brief  ending point coordinate */

        szwLoftBoundaryConstraints boundaryConstraints[2]; /**<@brief  boundary constraints data of start and end profiles */
        int endCap;                                        /**<@brief  end cap option (0-both, 1-start, 2-end, 3-none) */
        int close;                                         /**<@brief  whether to generate a closed loft (1 = yes, 0 = no) */

        zwString32 featureName; /**<@brief  feature name for "FtAllLft1", empty then use default */
        double tolerance;       /**<@brief  tolerance */
    } szwLoftData;

    /**
    @brief stock type
    @ingroup ZwFeatureShapeData
    */
    typedef enum ezwStockOption
    {
        ZW_STOCK_BLOCK    = 1, /**<@brief  block type */
        ZW_STOCK_CYLINDER = 2, /**<@brief  cylinder type */
    } ezwStockOption;

    /**
    @brief stock data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwStockData
    {
        ezwStockOption option;        /**<@brief  stock type(1:Block, 2:Cylinder) */
        int entityCount;              /**<@brief  number of entities to enclose */
        szwEntityHandle *encloseList; /**<@brief  list of entities to enclose (shape, face, block) */
        int adjustType;               /**<@brief  Type of adjust value (0 = By side, 1 = By total) */
        int decimal;                  /**<@brief  number of decimal place */
        zwString32 featureName;       /**<@brief  feature name for "FtExtStock2", empty then use default */

        /*  the relevant setting for stock type ZW_STOCK_BLOCK */
        szwEntityHandle planeHandle; /**<@brief  handle of reference plane to orient the stock, NULL to use default
                      plane paralleled to XY datum (datum, planar face, sketch) */
        double length[2];            /**<@brief  when adjustType = 0, increment of length in the positive and negative directions
                      when adjustType = 1, stock total length, just set the first value */
        double width[2];             /**<@brief  when adjustType = 0, increment of width in the positive and negative directions
                      when adjustType = 1, stock total width, just set the first value */
        double height[2];            /**<@brief  when adjustType = 0, increment of height in the positive and negative directions
                      when adjustType = 1, stock total height, just set the first value */

        /*  the relevant setting for stock type ZW_STOCK_CYLINDER */
        szwAxis axis;             /**<@brief  spiral axis to specify the rotational center of the cylinder */
        int axisPosition;         /**<@brief  specify the center axis position of the cylinder
                      (0 = on the setting axis, 1 = on the center of the shape */
        double radius;            /**<@brief  when adjustType = 0, increment of radius
                      when adjustType = 1, stock radius */
        double cylinderHeight[2]; /**<@brief  when adjustType = 0, increment of cylinder height in the positive and negative directions
                      when adjustType = 1, cylinder total height, just set the first value */
        int faceAttributeEnabled; /*<@brief if it is 0, then transparency and color is not used*/
        int transparency;         /**<@brief  face transparency 0~100 */
        ezwColor color;           /**<@brief  face color */
        double tolerance;         /**<@brief  tolerance */
    } szwStockData;

    /**
    @brief sphere data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwSphereData
    {
        ezwBoolType combine;       /**<@brief  combination method */
        int baseCount;             /**<@brief  base shape count */
        szwEntityHandle *baseList; /**<@brief  base shape list */
        szwPoint center;           /**<@brief  sphere center point */
        double radius;             /**<@brief  sphere radius (mm) */

        zwString32 featureName; /**<@brief  feature name for "FtAllSph", empty then use default */
        double tolerance;       /**<@brief  tolerance */
    } szwSphereData;

    /**
    @brief Swept Rod data
    @ingroup ZwFeatureShapeData
    */
    typedef struct szwSweptRodData
    {
        /* Required */
        int curveCount;           /**<@brief  the count of curves */
        szwEntityHandle *curvesC; /**<@brief  the handle list of curves */
        double diameterD;         /**<@brief  the value of 'Diameter D', default value : 40.0 */
        double interiorD;         /**<@brief  the value of 'Interior D',  must be less than diameterD */
        /* Settings */
        int isJoinRods;      /**<@brief  whether to join rods together or not, 1 to apply and else 0, default value : 1 */
        int isFilletCorner;  /**<@brief  whether to create fillet corner or not, 1 to apply and else 0, default value : 0 */
        double filletRadius; /**<@brief  the value of 'Fillet Radius', at least half of diameterD, it will be used when isFilletCorner is 1 */
    } szwSweptRodData;


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FEATURE_SHAPE_DATA_H */