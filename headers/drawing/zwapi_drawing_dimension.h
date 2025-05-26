/**
@file zwapi_drawing_dimension.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Dimension API
*/

#pragma once
#ifndef ZW_API_DRAWING_DIMENSION_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_DIMENSION_H

#include "zwapi_dimension_data.h"
#include "zwapi_drawing_dimension_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Dimension Query */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingDimension

    Gets annotated entities of the specified dimension.

    @note  
    The caller is responsible to free the entityList by using ZwEntityHandleListFree().  
    The function does not support feature dimension inherited from part in view.

    @param [in] dimensionHandle dimension handle
    @param [out] count number of entities
    @param [out] entityList list of entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_UNSUPPORTED_OBJ
    -        ZW_API_OBJECT_NO_UNIQUEID
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle dimensionHandle;
    // some code to get the data of dimensionHandle
    ...

    int count = 0;
    szwEntityHandle* entityList = NULL;
    ezwErrors ret = ZwDrawingDimensionEntityGet(dimensionHandle, &count, &entityList);

    // free memory of handles
    ZwEntityHandleListFree(count, &entityList);
    ZwEntityHandleFree(&dimensionHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDimensionEntityGet(szwEntityHandle dimensionHandle, int *count, szwEntityHandle **entityList);

    /**
    @ingroup ZwDrawingDimension

    Gets the reference state of the specified dimension.

    @param [in] dimension dimension handle
    @param [out] state the reference state (1: reference state; 0: non-reference state)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionReferenceStateGet(szwEntityHandle dimension, int *state);

    /**
    @ingroup ZwDrawingDimension

    Gets the position points of the dimension text.

    @param [in] dimension dimension handle
    @param [out] positionPoints the position points of dimension text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionTextPositionPointsGet(szwEntityHandle dimension, szwDrawingDimensionTextPositionPoints *positionPoints);

    //====================================================================================================================
    /** @name Dimension Set */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingDimension

    Sets the reference state of the specified dimension.  
    Function Guide: Drawing -> Dimension -> Edit Dimension -> Toggle Reference

    @param [in] count number of dimensions
    @param [in] dimensions list of dimension handles
    @param [in] state the reference state (1: reference state; 0: non-reference state)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionReferenceStateSet(int count, const szwEntityHandle *dimensions, int state);

    //====================================================================================================================
    /** @name Dimension Create */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingDimension

    Initializes the hole callout dimension data for ZwDrawingDimensionHoleCalloutCreate().

    @note
    Do not assign a value to variable "data" before calling the function, the ZwMemoryZero() is called inside the interface to empty everything.

    @see
    ZwDrawingDimensionHoleCalloutCreate

    @param [out] data hole callout dimension data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionHoleCalloutInit(szwDrawingHoleCalloutData *data);

    /**
    @ingroup ZwDrawingDimension

    Creates one or more hole callout dimensions and outputs the handles of new dimension.   
    Function Guide: Drawing -> Dimension -> Dimension -> Hole Callout

    @note  
    Interface ZwDrawingDimensionHoleCalloutInit() can initialize variable of the function.  
    The caller is responsible to free the dimensions by using ZwEntityHandleListFree().

    @see
    ZwDrawingDimensionHoleCalloutInit

    @param [in] data hole callout dimension data
    @param [out] count number of new dimension handles (input NULL to ignore)
    @param [out] dimensions list of new dimension handles (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_FORM_CREATE_FAIL

    @code
    // some code to init the data of hole
    szwDrawingHoleCalloutHole holes[2] = {};
    for (int i = 0; i < 2; i++)
        {
        // some code to get the data of hole curve
        ...
        }

    szwDrawingHoleCalloutData data = {};
    ezwErrors ret = ZwDrawingDimensionHoleCalloutInit(&data);
    // some code to get the data of view handle
    ...
    data.count = 2;
    data.holes = holes;

    int count = 0;
    szwEntityHandle* dimensions = NULL;
    ret = ZwDrawingDimensionHoleCalloutCreate(data, &count, &dimensions);

    // free memory of handles
    ZwEntityHandleListFree(count, &dimensions);
    for (int i = 0; i < 2; i++)
        ZwEntityHandleFree(&holes[i].hole);
    ZwEntityHandleFree(&data.viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDimensionHoleCalloutCreate(szwDrawingHoleCalloutData data, int *count, szwEntityHandle **dimensions);

    /**
    @ingroup ZwDrawingDimension

    Creates a datum target dimension in drawing and outputs the handle of new dimension.  
    Function Guide: Drawing -> Dimension -> Annotation -> Datum Target

    @note  
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data datum target data
    @param [out] dimension handle of new datum target dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwDatumTargetData data = {};
    data.type = ZW_DATUM_TARGET_POINT;

    // some code to get the data of target point
    szwPoint locPoint = { 100, 100, 0 };
    data.target.point.point = &locPoint;

    // some code to get the data of text point
    szwPoint textPoint = { 150, 100, 0 };
    data.textPoint.point = &textPoint;

    strcpy_s(data.datumText, sizeof(data.datumText), "A");

    szwEntityHandle dimension = {};
    ezwErrors ret = ZwDrawingDimensionDatumTargetCreate(data, &dimension);

    // free memory of handle
    ZwEntityHandleFree(&dimension);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDimensionDatumTargetCreate(szwDatumTargetData data, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension

    Creates a GD&T feature control symbol (FCS) and outputs the handle of new dimension.    
    Function Guide: Drawing -> Dimension -> Annotation -> Feature Control

    @note  
    The caller is responsible to free the featureControl by using ZwEntityHandleFree().

    @param [in] leaderPoint leader point, must be a point on entity (input NULL to ignore)
    @param [in] locationPoint location point
    @param [in] data feature control data
    @param [out] featureControl handle of new feature control (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    // some code to get the data of text point
    szwPoint tempPoint = { 100, 100, 0 };
    szwPointOnEntity textPoint = {};
    textPoint.point = &tempPoint;

    szwDrawingFeatureControlFrame frame = {};
    frame.symbol = ZW_FEATURE_CONTROL_CYLINDRICITY;
    strcpy_s(frame.tolerance1, sizeof(frame.tolerance1), "0.001");
    strcpy_s(frame.mainDatum, sizeof(frame.mainDatum), "A");

    szwDrawingFeatureControlData data = {};
    data.count = 1;
    data.frames = &frame;
    strcpy_s(data.topNote, sizeof(data.topNote), "Top");

    szwEntityHandle featureControl = {};
    ezwErrors ret = ZwDrawingDimensionFeatureControlCreate(NULL, textPoint, data, &featureControl);

    // free memory of handle
    ZwEntityHandleFree(&featureControl);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDimensionFeatureControlCreate(const szwPointOnEntity *leaderPoint, szwPointOnEntity locationPoint, szwDrawingFeatureControlData data, szwEntityHandle *featureControl);

    /**
    @ingroup ZwDrawingDimension

    Creates an intersection symbol to mark the intersection point of two lines or arcs and outputs the handle of new symbol.  
    Function Guide: Drawing -> Dimension -> Symbol -> Intersection Symbol

    @note  
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] curve1 the first line or arc
    @param [in] curve2 the second line or arc
    @param [out] dimension handle of new intersection symbol (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    // some code to get the data of curves
    szwEntityHandle curve1 = {};
    szwEntityHandle curve1 = {};
    ...

    szwEntityHandle dimension = {};
    ezwErrors ret = ZwDrawingDimensionIntersectionSymbolCreate(curve1, curve2, &dimension);

    // free memory of handle
    ZwEntityHandleFree(&curve1);
    ZwEntityHandleFree(&curve2);
    ZwEntityHandleFree(&dimension);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingDimensionIntersectionSymbolCreate(szwEntityHandle curve1, szwEntityHandle curve2, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension

    Initializes the szwDrawingDimensionOrdinate structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingDimensionOrdinateCreate

    @param [out] data drawing sheet hole mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionOrdinateInit(szwDrawingDimensionOrdinate *data);
    
    /**
    @ingroup ZwDrawingDimension

    Uses this function to create ordinate dimension in drawing sheet.  

    Function Guide: Drawing -> Dimension -> Dimension -> Ordinate

    @note
    Interface ZwDrawingDimensionOrdinateInit() can initialize variables data
    of this function.  
    The caller is responsible to free the dimensionList by using ZwEntityHandleListFree.

    @see ZwDrawingDimensionOrdinateInit

    @param [in] data  data of ordinate dimension
    @param [out] numberDimension number of dimension in list (input NULL to ignore)
    @param [out] dimensionList handle list of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionOrdinateCreate(szwDrawingDimensionOrdinate data, int *numberDimension, szwEntityHandle **dimensionList);

    /**
    @ingroup ZwDrawingDimension

    Initializes the szwDrawingDimensionSymmetryData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingDimensionSymmetryCreate

    @param [out] data drawing sheet symmetry data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionSymmetryInit(szwDrawingDimensionSymmetryData *data);

    /**
    @ingroup ZwDrawingDimension

    Creates a symmetry dimension in a drawing sheet.

    Function Guide: Drawing -> Dimension -> Dimension -> Symmetry

    @note
    Interface ZwDrawingDimensionSymmetryInit() can initialize variables data
    of this function.  
    The caller is responsible to free the dimension by using ZwEntityHandleFree.

    @see ZwDrawingDimensionSymmetryInit

    @param [in] symmetryData symmetry dimension input data
    @param [out] dimension symmetry dimension handle(input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_AIP_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionSymmetryCreate(szwDrawingDimensionSymmetryData symmetryData, szwEntityHandle *dimension);

    //====================================================================================================================
    /** @name Dimension Create */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingDimension

    Initialize the parameters of the szwAutoDimensionData.

    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingDimensionAutoCreate

    @param [out] data szwAutoDimensionData data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionAutoInit(szwAutoDimensionData *data);

    /**
    @ingroup ZwDrawingDimension

    Adds auto dimension by specified parameter.
    Function Guide: Drawing->Dimension->Dimension->Auto Dimension

    @note
    Interface ZwDrawingDimensionAutoInit initializes the szwAutoDimensionData structure.
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().
    @see ZwDrawingDimensionAutoInit

    @param [in] viewHandle view handle
    @param [in] data dimension parameters
    @param [out] count count of handles of dimensions (input NULL to ignore)
    @param [out] handleList handles of dimensions (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_DRAWING_VIEW_NOT_PREPARED
    */
    ZW_API_C ezwErrors ZwDrawingDimensionAutoCreate(szwEntityHandle viewHandle, szwAutoDimensionData data, int *count, szwEntityHandle **handleList);
	
	/**
    @ingroup ZwDrawingDimension

    Initializes the parameters of the ZwDrawingDimensionCenterLineCreate().

    @see ZwDrawingDimensionCenterLineCreate

    @param [out] data Center Line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionCenterLineInit(szwDrawingCenterLine *data);

    /**
    @ingroup ZwDrawingDimension

    Creates a center line dimension by two lines or two points.

    By two lines: should be the same type, one is a straight line, the other must be a straight line;
        one is an arc or a circle, the other must be an arc or circle;

    By two points: any point;   
    default value:   
        szwCenterDimensionAttribute 
        centerLineSize   : 4.254534   
        breakLength : 1.5   
        overRun  : 3.06324   
        scaleFactor : 1    

    Function Guide: Drawing->Dimension->Symbol->Center Line

    @see ZwDrawingDimensionCenterLineInit

    @note
    Interface ZwDrawingDimensionCenterLineInit() can initialize variables of this function.
    The caller is responsible to free the dimensionHandle by using ZwEntityHandleFree().

    @param [in] centerLine information of two lines or two points
    @param [out] dimensionHandle handle data of dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionCenterLineCreate(szwDrawingCenterLine centerLine, szwEntityHandle *dimensionHandle);

    
    /**
    @ingroup ZwDrawingDimension

    Initializes the parameters of the ZwDrawingDimensionContinuousCreate().

    @see ZwDrawingDimensionContinuousCreate

    @param [out] data center mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionContinuousInit(szwDrawingLineGroupDimension *data);

    /**
    @ingroup ZwDrawingDimension

    Creates a Continuous dimension between the specified object in drawing.

    pData->linearDimension.constraint.type is set by ezwDimensionLineType, as follows:       
    ZW_DIMENSION_LINE_HORIZONTAL -- horizontal       
    ZW_DIMENSION_LINE_VERTICAL -- vertical         
    ZW_DIMENSION_LINE_ALIGNED -- aligned          
    ZW_DIMENSION_LINE_ROTATED -- rotated          
    ZW_DIMENSION_LINE_PROJECTED -- projected   

    Function Guide: Drawing->Dimension->Dimension->Continous  

    @see ZwDrawingDimensionContinuousInit

    @note
    The caller is responsible to free the dimensionHandle by using ZwEntityHandleFree().

    @param [in] data data of continuous dimension
    @param [out] countDimension count of the dimension created (input NULL to ignore)
    @param [out] dimensionList handle data list of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionContinuousCreate(szwDrawingLineGroupDimension data, int *countDimension, szwEntityHandle **dimensionList);

    /**
    @ingroup ZwDrawingDimension

    Initializes the parameters of the ZwDrawingDimensionCenterMarkCreate().

    @see ZwDrawingDimensionCenterMarkCreate

    @param [out] data center mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionCenterMarkInit(szwDrawingCenterMark *data);

    /**
    @ingroup ZwDrawingDimension

    Creates center dimension with specify coordinate.

    Function Guide: Drawing->Dimension->Symbol->Center Mark  

    @see ZwDrawingDimensionCenterMarkInit

    @verbatim
    default value:   
        szwCenterDimensionAttribute     
        centerLineSize   : 4.254534   
        breakLength : 1.5   
        overRun  : 3.06324   
        scaleFactor : 1  

    @endverbatim

    @note
    Interface ZwDrawingDimensionCenterMarkInit() can initialize variables of this function.
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data center mark data
    @param [out] countDimension count of the dimensions (input NULL to ignore)
    @param [out] dimensionList handle data list of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionCenterMarkCreate(szwDrawingCenterMark data, int *countDimension, szwEntityHandle **dimensionList);

    /**
    @ingroup ZwDrawingDimension

    Initializes the parameters of the ZwDrawingDimensionLabelCreate().

    @see ZwDrawingDimensionLabelCreate

    @param [out] data Center Mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLabelInit(szwDimensionLabel *data);

    /**
    @ingroup ZwDrawingDimension

    Creates a label dimension.

    Function Guide: Drawing->Dimension->Annotation->Label  

    @see ZwDrawingDimensionLabelInit

    @param [in] label information needed by creating dimension label
    @param [out] dimension handle data of Dimension (input NULL to ignore)

    @note
    Interface ZwDrawingDimensionLabelInit() can initialize variables of this function.
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLabelCreate(szwDimensionLabel label, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension

    Initializes the parameters of the ZwDrawingAutoBalloonCreate().

    @see ZwDrawingAutoBalloonCreate

    @param [out] data Information of creating auto balloon

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingAutoBalloonInit(szwDrawingAutoBalloonData *data);

    //====================================================================================================================
    /** @name Dimension Create */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingDimension

    Creates auto balloon. 

    Function Guide: Drawing->Dimension->Annotation->Auto Balloon  

    @see ZwDrawingAutoBalloonInit

    @note
    Interface ZwDrawingAutoBalloonInit() can initialize variables of this function.
    The caller is responsible to free the dimensionList by using ZwEntityHandleListFree().

    @param [in] autoBalloonData the information of creating auto balloon
    @param [out] dimensionCount number of created balloon dimensions (input NULL to ignore)
    @param [out]  dimensionList list of created balloon dimension dimensions (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingAutoBalloonCreate(szwDrawingAutoBalloonData autoBalloonData, int *dimensionCount, szwEntityHandle **dimensionList);   
    
    /**
    @ingroup ZwDrawingDimension
    
    Initializes the parameters of the szwDrawingLinearChamferDimensionData.
    Function Guide: Drawing->Dimension->Dimension->Linear Chamfer
    
    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.  
    
    @see ZwDrawingDimensionLinearChamferCreate
    
    @param [out] data the info of the linear chamfer dimension
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLinearChamferInit(szwDrawingLinearChamferDimensionData *data);

    /**
    @ingroup ZwDrawingDimension

    Creates a linear chamfer dimension in sheeting. data must be initialized before using.
    Function Guide: Dimension -> Dimension ->Linear Chamfer  

    @note
    Interface ZwDrawingDimensionLinearChamferInit() can initialize variables of this function.  
    The caller is responsible to free the dimension by using ZwEntityHandleFree().  

    @see ZwDrawingDimensionLinearChamferInit

    @param [in] data the information of linear chamfer dim which will create
    @param [out] dimension handle of the linear chamfer dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INPUT_TYPE_eRROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLinearChamferCreate(szwDrawingLinearChamferDimensionData data, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension
    
    Creates a linear dimension between the specified objects in drawing.
    
    data.constraint is set by ezwDimensionLineType, as follows:  
    ZW_DIMENSION_LINE_HORIZONTAL -- horizontal  
    ZW_DIMENSION_LINE_VERTICAL -- vertical  
    ZW_DIMENSION_LINE_ALIGNED -- aligned  
    ZW_DIMENSION_LINE_ROTATE -- rotated  
    ZW_DIMENSION_LINE_PROJECTED -- projected  
    Function Guide: Drawing->Dimension->Dimension->Linear
    
    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().
    
    @param [in] data data of line dimension
    @param [out] dimension handle of the dimension created (input NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLinearCreate(szwDrawingLinearDimension data, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension
    
    Creates a linear offset dimension between the specified two entities in drawing.  
    Supported entities include two lines, a point and a line.  
    
    type of data  is as follows by ezwDimensionLinearOffsetType:  
    ZW_DIMENSION_OFFSET_LINE_TO_LINE offset dimension - line to line  
    ZW_DIMENSION_OFFSET_POINT_TO_LINE offset dimension - line to point  

    Function Guide: Drawing->Dimension->Dimension->Linear Offset

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().
    
    @param [in] data data of LineOffset dimension
    @param [out] dimension handle of the dimension created (input NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLinearOffsetCreate(szwDrawingLinearOffsetDimension data, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension
    
    Creates a radial or diametric dimension for the specified entity in drawing.

    Function Guide: Drawing->Dimension->Dimension->Radial/Diametric

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().
    
    @param [in] data radial or diametric input data
    @param [out] dimension handle of the dimension created (input NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionRadialCreate(szwRadialDimensionData data, szwEntityHandle *dimension);


    /**
    @ingroup ZwDrawingDimension

    Creates an angular dimension in a drawing sheet.

    Function Guide: Drawing->Dimension->Dimension->Angular

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data angular dimension input data
    @param [out] dimension handle of the angular dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionAngularCreate(szwDrawingAngularDimensionData data, szwEntityHandle *dimension);

    /**
    @ingroup ZwDrawingDimension

    Creates an arc length dimension in a drawing sheet.

    Function Guide: Drawing->Dimension->Dimension->ArcLength

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data arc dimension input data
    @param [out] dimension handle of the arc dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionArcCreate(szwDrawingArcDimensionData data, szwEntityHandle *dimension);
    
    /**
    @ingroup ZwDrawingDimension

    Creates a Balloon dimension between the specified points in drawing.  
    Drawing -> Dimension ->Balloon

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().  
    When data.texttype = ZW_DRAWING_DIMENSION_TEXT_USER_TEXT and you want to set data.text  
    like you set text by using "Custom Editor" in zw3d, the input format of text is like:  
        1.When you want to insert text of the corresponding type in "Insert column" e.g File-Name,  
    the text you want to insert be like:<TC_Name>. The format is <TC_YouVariable>.  
        2.When you want to insert text from "Insert variable" e.g "Sheet_scale"  
    the text you want to insert be like [$Sheet_scale]. The format is [$YouVariable].  

    @param [in] data data of balloon dimension
    @param [out] balloon balloon handle created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionBalloonCreate(szwDrawingBalloonDimension data, szwEntityHandle *balloon);

    /**
    @ingroup ZwDrawingDimension

    Creates a label coordinate dimension in drawing.  
    Drawing -> Dimension ->Label Coordinate

    @note
    The new lable coordinate dimension include some sub-dimension.  
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data data of label coordinate dimension 
    @param [out] coordinate handle of the new label coordinates (NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_WRONG_ROOT_ENV
    -       ZW_API_CMMD_INIT_ERROR
    -       ZW_API_INPUT_ERROR
    -       ZW_API_CMMD_eXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionLabelCoordinateCreate(szwDrawingLabelCoordinateDimension data, szwEntityHandle *coordinate);

    /**
    @ingroup ZwDrawingDimension

    Creates a datum feature dimension for the specified entity in drawing.  
    Drawing -> Dimension ->Datum Feature

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data data of datum feature dimension 
    @param [out] datumFeature datum feature handle created (input NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_WRONG_ROOT_ENV
    -       ZW_API_CMMD_INIT_ERROR
    -       ZW_API_INPUT_ERROR
    -       ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionDatumFeatureCreate(szwDrawingDatumFeatureDimension data, szwEntityHandle *datumFeature);

    /**
    @ingroup ZwDrawingDimension

    Creates a Baseline dimension between the specified object in drawing.  
    Drawing -> Dimension ->Base Line

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleListFree().
    data.type is set by ezwDrawingDimensionLineType, as follows:  
    ZW_DRAWING_DIMENSION_LINE_HORIZONTAL-- horizontal  
    ZW_DRAWING_DIMENSION_LINE_VERTICAL  -- vertical  
    ZW_DRAWING_DIMENSION_LINE_ALIGNED   -- aligned  
    ZW_DRAWING_DIMENSION_LINE_ROTATED   -- rotated  
    ZW_DRAWING_DIMENSION_LINE_PROJECTED -- projected  

    @param [in] data data of base line dimension
    @param [out] count number of base Line dimension created (NULL to ignore)
    @param [out] baseLine handle of new created base line (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionBaseLineCreate(szwDrawingBaseLineDimension data, int *count, szwEntityHandle **baseLine);

    /**
    @ingroup ZwDrawingDimension

    Creates a center mark circle dimension for the specified entities in drawing.  
    Drawing -> Dimension ->Center Mark Circle

    @note
    The caller is responsible to free the dimension by using ZwEntityHandleFree().

    @param [in] data center mark circle dimension data
    @param [out] circle center mark circle dimension handle created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_aPI_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingDimensionCenterMarkCircleCreate(szwCenterMarkCircleDimension data, szwEntityHandle *circle);
/*
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_DIMENSION_H */