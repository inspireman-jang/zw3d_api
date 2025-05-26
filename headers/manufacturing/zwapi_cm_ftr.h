/**
@file zwapi_cm_ftr.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D API of the Cam Features.
*/
/**
@defgroup zwapi_cm_ftr Cam Feature API
@ingroup CamModel
@brief
@details THE MODULE FOR THE ZW3D API of the Cam Features.
*/

#pragma once
#ifndef ZW_API_CAM_FEATURE_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_FEATURE_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Features Data */
    //====================================================================================================================
    /**
    @brief cam feature type
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmFtrType
    {
        ZW_CAM_FEATURE_SOLID   = 1,  /**<@brief  solid feature */
        ZW_CAM_FEATURE_POCKET  = 2,  /**<@brief  pocket feature */
        ZW_CAM_FEATURE_HOLE    = 3,  /**<@brief  hole feature */
        ZW_CAM_FEATURE_SLOT    = 4,  /**<@brief  slot feature */
        ZW_CAM_FEATURE_PROFILE = 5,  /**<@brief  profile feature */
        ZW_CAM_FEATURE_STEP    = 6,  /**<@brief  step feature */
        ZW_CAM_FEATURE_SURFACE = 7,  /**<@brief  surface feature */
        ZW_CAM_FEATURE_CHAMFER = 8,  /**<@brief  chamfer feature */
        ZW_CAM_FEATURE_CRND    = 9,  /**<@brief  cround feature */
        ZW_CAM_FEATURE_FACE    = 10, /**<@brief  face feature */
        ZW_CAM_FEATURE_BOSS    = 11, /**<@brief  boss feature */
        ZW_CAM_FEATURE_FLAT    = 12  /**<@brief  flat region feature */
    } evxCmFtrType;

    /**
    @brief cam feature attribute
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmFtrAttr
    {
        CM_FEATURE_TYPE
    } evxCmFtrAttr;

    /**
    @brief cam profile feature class, rename from evxCmFtrProfileType
    @ingroup zwapi_cm_ftr
    */
    typedef enum ezwCamFtrProfileClass
    {
        ZW_CAM_FTR_PRF_CLASS_PART    = 0, /**<@brief CAM profile feature part class */
        ZW_CAM_FTR_PRF_CLASS_CONTAIN = 1, /**<@brief CAM profile feature contain class */
        ZW_CAM_FTR_PRF_CLASS_STOCK   = 2  /**<@brief CAM profile feature stock class */
    } ezwCamFtrProfileClass;

    /**
    @brief cam profile feature curve attribute
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmProfileCuvAttr
    {
        V_CM_PRF_OFFSET  = 0, /**<@brief curve's offset */
        V_CM_PRF_DRAFT   = 1, /**<@brief curve's draft */
        V_CM_PRF_TOOLLOC = 2, /**<@brief curve's tool location */
    } evxCmProfileCuvAttr;

    /**
    @brief cam profile feature tool location type
    @ingroup zwapi_cm_ftr
    */
    typedef enum evxCmProfileTolLoc
    {
        V_CM_PRF_ON   = 0, /**<@brief tool is on curve */
        V_CM_PRF_TAN  = 1, /**<@brief tool is tangent curve */
        V_CM_PRF_PAST = 2, /**<@brief tool is past curve */
    } evxCmProfileTolLoc;

    //====================================================================================================================
    /** @name Cam Feature Parameter */
    //====================================================================================================================
 
    /**
    @brief cam profile feature Join Method
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamProfileJoinMethod
    {
        ZW_CAM_FTR_PRF_JOIN_LINEAR    = 0, /**<@brief profile join method is linear */
        ZW_CAM_FTR_PRF_JOIN_CIRCULAR  = 1, /**<@brief profile join method is curcular */
        ZW_CAM_FTR_PRF_JOIN_INTERSECT = 2  /**<@brief profile join method is intersect */
    } ezwCamProfileJoinMethod;

    /**
    @brief cam profile feature Tool Side
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamProfileToolSide
    {
        ZW_CAM_FTR_PRF_TOL_SIDE_INSIDE  = 1, /**<@brief profile tool side is inside */
        ZW_CAM_FTR_PRF_TOL_SIDE_OUTSIDE = 2, /**<@brief profile tool side is outside */
        ZW_CAM_FTR_PRF_TOL_SIDE_LEFT    = 3, /**<@brief profile tool side is left */
        ZW_CAM_FTR_PRF_TOL_SIDE_RIGHT   = 4  /**<@brief profile tool side is right */
    } ezwCamProfileToolSide;

    /**
    @brief cam profile feature Part Side
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamProfilePartSide
    {
        ZW_CAM_FTR_PRF_PART_SIDE_NONE          = 0, /**<@brief profile part side is none, used in part and stock class */
        ZW_CAM_FTR_PRF_PART_SIDE_LEFT_ON       = 1, /**<@brief profile part side is left-on */
        ZW_CAM_FTR_PRF_PART_SIDE_LEFT_TANGENT  = 2, /**<@brief profile part side is left-tangent */
        ZW_CAM_FTR_PRF_PART_SIDE_RIGHT_ON      = 3, /**<@brief profile part side is right-on */
        ZW_CAM_FTR_PRF_PART_SIDE_RIGHT_TANGENT = 4  /**<@brief profile part side is right-tangent */
    } ezwCamProfilePartSide;

    /**
    @brief cam profile attribute value
    @ingroup ZwCamFeatureParam
    */
    typedef struct szwCamFtrProfileAttr
    {
        double tolerance;                   /**<@brief  profile feature tolerance */
        int openClose;                      /**<@brief  profile feature open/close, 0: close; 1: open */
        ezwCamProfileJoinMethod joinMethod; /**<@brief  profile feature join method */
        int reverseDir;                     /**<@brief  profile feature reverse dir, 0: No; 1: Yes */
        ezwCamProfileToolSide toolSide;     /**<@brief  profile feature tool side */
        ezwCamProfilePartSide partSide;     /**<@brief  profile feature part side */
    } szwCamFtrProfileAttr;


    /**
    @brief cam feature hole attribute value
    @ingroup ZwCamFeatureParam
    */
    typedef struct szwCamFtrHoleAttr
    {
        int holeCnt;         /**<@brief  hole count */
        double diameter;     /**<@brief  hole feature diameter */
        double depth;        /**<@brief  hole feature depth */
        double taperAng;     /**<@brief  hole feature taper angle */
        double tolerance;    /**<@brief  hole feature tolerance */
        double finish;       /**<@brief  hole feature finish */
        double CSinkDia;     /**<@brief  hole feature csink diameter */
        double CSinkAng;     /**<@brief  hole feature csink angle */
        double CBoreDia;     /**<@brief  hole feature cbore diameter */
        double CBoreDepth;   /**<@brief  hole feature cbore depth */
        double threadDia;    /**<@brief  hole feature thread diameter */
        double threadDepth;  /**<@brief  hole feature thread depth */
        double threadPitch;  /**<@brief  hole feature thread pitch */
        svxVector normVec;   /**<@brief  hole feature norm vector */
        svxPoint startPoint; /**<@brief  hole feature start point */
    } szwCamFtrHoleAttr;

    /**
    @brief cam cround feature Machining Side
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamCroundMachiningSide
    {
        ZW_CAM_FTR_CRND_SIDE_LEFT_INSIDE   = 0, /**<@brief cround feature machining side is left or inside */
        ZW_CAM_FTR_CRND_SIDE_RIGHT_OUTSIDE = 1, /**<@brief cround feature machining side is right or outside */
    } ezwCamCroundMachiningSide;

    /**
    @brief cam cround feature Spine curves
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamCroundSpineCurves
    {
        ZW_CAM_FTR_CRND_SPINE_NO  = 0, /**<@brief cround feature spine curves is no */
        ZW_CAM_FTR_CRND_SPINE_YES = 1, /**<@brief cround feature spine curves is yes */
    } ezwCamCroundSpineCurves;

    /**
    @brief cam feature cround attributes value
    @ingroup ZwCamFeatureParam
    */
    typedef struct szwCamFtrCroundAttr
    {
        double offset;                  /**<@brief  cround feature offset */
        double radius;                  /**<@brief  cround feature radius */
        ezwCamCroundMachiningSide side; /**<@brief  cround feature machining side */
        ezwCamCroundSpineCurves spine;  /**<@brief  cround feature spine curves */

    } szwCamFtrCroundAttr;
    /**
    @brief cam feature slot attribute value
    @ingroup ZwCamFeatureParam
    */

    typedef struct szwCamFtrSlotAttr
    {
        double tolerance; /**<@brief  slot feature tolerance */
        double offset;    /**<@brief  slot feature offset */
        double draft;     /**<@brief  slot feature draft */
        double depth;     /**<@brief  slot feature depth */
    } szwCamFtrSlotAttr;
    /**
    @brief cam chamfer feature Machining Side
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamChamferMachiningSide
    {
        ZW_CAM_FTR_CHAMF_SIDE_LEFT_INSIDE   = 0, /**<@brief chamfer feature machining side is left or inside */
        ZW_CAM_FTR_CHAMF_SIDE_RIGHT_OUTSIDE = 1, /**<@brief chamfer feature machining side is right or outside */
    } ezwCamChamferMachiningSide;

      /**
    @brief cam chamfer feature Spine curves
    @ingroup ZwCamFeatureParam
    */
    typedef enum ezwCamChamferSpineCurves
    {
        ZW_CAM_FTR_CHAMF_SPINE_NO  = 0, /**<@brief chamfer feature spine curves is no */
        ZW_CAM_FTR_CHAMF_SPINE_YES = 1, /**<@brief chamfer feature spine curves is yes */
    } ezwCamChamferSpineCurves;

    /**
    @brief cam feature chamfer attributes value
    @ingroup ZwCamFeatureParam
    */
    typedef struct szwCamFtrChamferAttr
    {
        double tolerance;                /**<@brief  chamfer feature tolerance */
        double offset;                   /**<@brief  chamfer feature offset */
        double draft;                    /**<@brief  chamfer feature draft */
        double depth;                    /**<@brief  chamfer feature depth */
        ezwCamChamferMachiningSide side; /**<@brief  chamfer feature machining side */
        ezwCamChamferSpineCurves spine;  /**<@brief  chamfer feature spine curves */

    } szwCamFtrChamferAttr;

    //====================================================================================================================
    /** @name Cam Features Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.

    @param [in] ftrType type of the feature
    @param [in] idx_CmComp index of the component
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [out] idx_FtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C evxErrors cvxCmFtrInsert(evxCmFtrType ftrType, int idx_CmComp, int cnt, int *geom, int *idx_FtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] ftrType type of the feature
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [in] depths depths of holes
    @param [out] idx_FtrGrp index of feature

    */
    ZW_API_C evxErrors cvxCmFtrInsertNew(evxCmFtrType ftrType, int cnt, int *geom, double *depths, int *idx_FtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the component.
    This function provides the ability to generate features other than holes.
    Currently, profile,surface,chamfer and cround are supported.
    If it exists the feature with the feature name, it will insert the geometry to
    the feature. If it does not exist, it will create a new feature with the default name.

    @param [in] ftrType type of the feature
    @param [in] ftrName feature name which needs to be added to the new member
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrInsertWithoutHoles(evxCmFtrType ftrType, const vxName ftrName, int cnt, int *geom, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Add a feature in the sketch.

    @param [in] ftrType type of the feature
    @param [in] ftrName feature name which needs to be added to the new member
    @param [in] idxSk index of the sketch where the geom is located.
    @param [in] cnt feature data
    @param [in] geom index of geom
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrInsertSK(evxCmFtrType ftrType, const vxName ftrName, int idxSk, int cnt, int *geom, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Get component's geom index.

    The idxComp output array must be deallocated with cvxMemFree().
    @param [out] comp_cnt count of components
    @param [out] idxComp index of components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrGetComp(int *comp_cnt, int **idxComp);

    /**
    @ingroup zwapi_cm_ftr

    Get curves' index in part

    @param [out] numLine number of curve
    @param [out] lstLines list of curve id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmGetCrvId(int *numLine, int **lstLines);

    /**
    @ingroup zwapi_cm_ftr

    Add a hole feature in the component.
    If it exists the feature with the feature name, it will insert the geometry to
    the feature. If it does not exist, it will create a new feature with the default name.

    @param [in] ftrName feature name
    @param [in] cnt count of the geometries
    @param [in] geom geometry indexes
    @param [in] depths depths of holes
    @param [out] idxFtrGrp index of feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CAM_GETCMCOMP_ERROR
    -        ZW_API_CAM_GETCOMPVDATA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrInsertHole(const vxName ftrName, int cnt, int *geom, double *depths, int *idxFtrGrp);

    /**
    @ingroup zwapi_cm_ftr

    Set cam plan display mode.

    @param [in] iMode display mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmPlanDispSetMode(evxCmPlanDispMode iMode);

    /**
    @ingroup zwapi_cm_ftr

    Reset cam plan display mode to CM_ACTIVE_PROCESS.

    @param

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmPlanDispResetMode();

    /**
    @ingroup zwapi_cm_ftr

    Delete the feature.

    @param [in] idx_ftrgrp index of the feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrDelete(int idx_ftrgrp);

    /**
    @ingroup zwapi_cm_ftr

    Change the feature name.

    @param [in] idx_ftr cam tree index
    @param [in] newFtrName new name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrRename(int idx_ftr, vxLongName newFtrName);

    /**
    @ingroup zwapi_cm_ftr

    Change the profile curve parameters

    @param [in] prof_idx profile feature index
    @param [in] curve_idx curve in profile feature index
    @param [in] newOffset offset value
    @param [in] newDraft draft value
    @param [in] tolloc tool location value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFTRGRP_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmProfSetAttr(int prof_idx, int curve_idx, double newOffset, double newDraft, int tolloc);

    /**
    @ingroup zwapi_cm_ftr

    Inquire the type of feature

    @param[in] idx_Ftr profile feature index
    @param [out] ftrType feature class

    @retval succeeds
    - ZW_API_NO_ERROR
    @retval fail
    - ZW_API_GENERAL_ERROR
    - ZW_API_INVALID_OUTPUT
    - ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCmFtrInqType(int idx_Ftr, evxCmFtrType *ftrType);


    //====================================================================================================================
    /** @name Cam Features Function */
    //====================================================================================================================

    /**
    @ingroup ZwCamFeature

    Get the feature group's feature count and index list.

    The list referenced by "**featIdxList" is allocated by this function and
    must be deallocated by the calling procedure.  A NULL pointer is
    output if no data is found.

    @param [in] idx_ftrgrp feature group index
    @param [out] featCnt feature count
    @param [out] featIdxList feature index list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTRGRP_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwCamFtrGrpFeatListGet(int idx_ftrgrp, int *featCnt, int **featIdxList);

    /**
    @ingroup ZwCamFeature

    Get the feature group's feature count and index list. Now, we support 
    profile, hole, chamfer, corner cround and slot features.

    The list referenced by "**elementIdxList" is allocated by this function and
    must be deallocated by the calling procedure.  A NULL pointer is
    output if no data is found.

    @param [in] feat_idx feature index
    @param [out] elementCnt element count in feature
    @param [out] elementIdxList element index list in feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwCamFtrElementListGet(int feat_idx, int *elementCnt, int **elementIdxList);

    /**
    @ingroup ZwCamFeature

    Get the hole feature's attributes by hole index.

    @param [in] feat_idx hole feature index in Feature group
    @param [out] holeAttr hole attribute in Feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamHoleFeatDataGet(int feat_idx, szwCamFtrHoleAttr *holeAttr);

    /**
    @ingroup ZwCamFeature

    Set the hole feature's attributes by hole index.

    @note If the x, y and z absolute values are larger than or equal to 1.0e20, 
          it will set the start point empty.

    @param [in] feat_idx hole feature index in feature group
    @param [in] holeAttr hole attribute in Feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_CAM_SETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C ezwErrors ZwCamHoleFeatDataSet(int feat_idx, const szwCamFtrHoleAttr *holeAttr);

    /**
    @ingroup ZwCamFeature

    Get the profile feature's attributes by profile index.

    @param [in] feat_idx profile feature index in Feature group
    @param [out] profAttr profile attribute in Feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamProfFeatDataGet(int feat_idx, szwCamFtrProfileAttr *profAttr);

    /**
    @ingroup ZwCamFeature

    Set the profile feature's attributes by profile index.

    @param [in] feat_idx profile feature index in feature group
    @param [in] profAttr profile attribute in Feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_CAM_SETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C ezwErrors ZwCamProfFeatDataSet(int feat_idx, const szwCamFtrProfileAttr *profAttr);

    /**
    @ingroup ZwCamFeature

    Get the profile feature element's (curve) by feature and element index.

    @param [in] feat_idx profile feature index in Feature group
    @param [in] element_idx profile feature index in Feature group
    @param [out] offset offset value
    @param [out] draft draft value
    @param [out] tolloc tool location value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamProfElementDataGet(int feat_idx, int element_idx, double *offset, double *draft, evxCmProfileTolLoc *tolloc);

    /**
    @ingroup ZwCamFeature

    Change the profile curve parameters

    @param [in] prof_idx profile feature index
    @param [in] curve_idx curve in profile feature index
    @param [in] newOffset offset value
    @param [in] newDraft draft value
    @param [in] tolloc tool location value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETFTRGRP_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwCamProfElementDataSet(int prof_idx, int curve_idx, double newOffset, double newDraft, evxCmProfileTolLoc tolloc);

     /**
    @ingroup ZwCamFeature

    Get the cround feature's attributes by cround index.

    @param [in] feat_idx cround feature index in feature group
    @param [out] crndAttr cround attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamCroundFeatDataGet(int feat_idx, szwCamFtrCroundAttr *crndAttr);

    /**
    @ingroup ZwCamFeature

    Set the cround feature's attributes by cround index.

    @param [in] feat_idx cround feature index in feature group
    @param [in] crndAttr cround attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_CAM_SETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C ezwErrors ZwCamCroundFeatDataSet(int feat_idx, const szwCamFtrCroundAttr *crndAttr);


    /**
    @ingroup ZwCamFeature

    Get the slot feature's attributes by slot index.

    @param [in] feat_idx slot feature index in feature group
    @param [out] slotAttr slot attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamSlotFeatDataGet(int feat_idx, szwCamFtrSlotAttr *slotAttr);

    /**
    @ingroup ZwCamFeature

    Set the slot feature's attributes by slot index.

    @param [in] feat_idx slot feature index in feature group
    @param [in] slotAttr slot attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_CAM_SETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C ezwErrors ZwCamSlotFeatDataSet(int feat_idx, const szwCamFtrSlotAttr *slotAttr);

    /**
    @ingroup ZwCamFeature

    Get the chamfer feature's attributes by chamfer index.

    @param [in] feat_idx chamfer feature index in feature group
    @param [out] chamfAttr chamfer attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_GETFTR_ERROR
    */
    ZW_API_C ezwErrors ZwCamChamferFeatDataGet(int feat_idx, szwCamFtrChamferAttr *chamfAttr);

    /**
    @ingroup ZwCamFeature

    Set the chamfer feature's attributes by chamfer index.

    @param [in] feat_idx chamfer feature index in feature group
    @param [in] chamfAttr chamfer attribute in feature group

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETFTR_ERROR
    -        ZW_API_CAM_SETFTR_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    */
    ZW_API_C ezwErrors ZwCamChamferFeatDataSet(int feat_idx, const szwCamFtrChamferAttr *chamfAttr);



    /**
    @ingroup ZwCamFeature

    Set the profile feature group class. See ezwCamFtrProfileClass.

    @param [in] ftrgrp_idx feature group index
    @param [in] profClass profile class

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwCamFtrGrpProfClassSet(int ftrgrp_idx, ezwCamFtrProfileClass profClass);

    /**
    @ingroup ZwCamFeature

    Get the profile feature group class. See ezwCamFtrProfileClass.

    @param [in] ftrgrp_idx feature group index
    @param [out] profClass profile class

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwCamFtrGrpProfClassGet(int ftrgrp_idx, ezwCamFtrProfileClass *profClass);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_FEATURE_H */
