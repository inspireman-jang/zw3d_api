/**
@file zwapi_sketch_dimension.h
@copyright (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sketch Dimension API
*/

#pragma once
#ifndef ZW_API_SKETCH_DIMENSION_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_DIMENSION_H

#include "zwapi_dimension_data.h"
#include "zwapi_sketch_dimension_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Dimension Create */
    //====================================================================================================================
    /**
    @ingroup ZwSketchDimension

    Create a 2D linear dimension at the active sketch.

    Function Guide: Sketch->Dimension->Linear

    @param [in] linearType linear dimension type
    @param [in] dimensionPoint1 the first dimension point
    @param [in] dimensionPoint2 the second dimension point
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwSketchDimensionPoint dimensionPoint1 = {};
    // some code to get the data of dimensionPoint1
    ...

    szwSketchDimensionPoint dimensionPoint2 = {};
    // some code to get the data of dimensionPoint2
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchLinearDimensionCreate(ZW_SKETCH_LINEAR_HORIZONTAL, dimensionPoint1, dimensionPoint2, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&dimensionPoint1.entityHandle);
    ZwEntityHandleFree(&dimensionPoint2.entityHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchLinearDimensionCreate(ezwSketchLinearDimensionType linearType, szwSketchDimensionPoint dimensionPoint1, szwSketchDimensionPoint dimensionPoint2, const szwPoint2 *textPoint, double dimensionValue, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create a 2D linear offset dimension at the active sketch.

    Function Guide: Sketch->Dimension->Linear Offset

    @param [in] linearOffsetType linear offset dimension type
    @param [in] dimensionPoint1 the first dimension object
    @param [in] dimensionPoint2 the second dimension object
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwSketchDimensionPoint dimensionPoint1 = {};
    // some code to get the data of dimensionPoint1
    ...

    szwSketchDimensionPoint dimensionPoint2 = {};
    // some code to get the data of dimensionPoint2
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchLinearOffsetDimensionCreate(ZW_SKETCH_LINEAR_OFFSET, dimensionPoint1, dimensionPoint2, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&dimensionPoint1.entityHandle);
    ZwEntityHandleFree(&dimensionPoint2.entityHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchLinearOffsetDimensionCreate(ezwSketchLinearOffsetDimensionType linearOffsetType, szwSketchDimensionPoint dimensionPoint1, szwSketchDimensionPoint dimensionPoint2, const szwPoint2 *textPoint, double dimensionValue, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create a 2D angular dimension at the active sketch.

    Function Guide: Sketch->Dimension->Angular

    @note
    1. The function automatically matches the dimension quadrant if the dimension value is specified and the dimension value is consistent with the position of the lines.
    2. The function matches quadrants based on the specified text point if the dimension value is not specified and text point is specified.
    3. The function defaults to an acute angle quadrant if the dimension value is not specified or the value is not consistent with the position of the lines and text point is not specified.

    @param [in] angularType angular dimension type
    @param [in] count the number of the dimension points
    @param [in] dimensionPoint the list of the dimension points
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwSketchDimensionPoint dimensionPoint[2] = {};
    // some code to get the data of dimensionPoint
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchAngularDimensionCreate(ZW_SKETCH_TWO_CURVE_ANGULAR, 2, dimensionPoint, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&dimensionPoint[0].entityHandle);
    ZwEntityHandleFree(&dimensionPoint[1].entityHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchAngularDimensionCreate(ezwSketchAngularDimensionType angularType, int count, const szwSketchDimensionPoint *dimensionPoint, const szwPoint2 *textPoint, double dimensionValue, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create a 2D radial or diametric dimension at the active sketch.

    Function Guide: Sketch->Dimension->Radial/Diametric

    @param [in] radialType radial dimension type
    @param [in] arcHandle the handle of dimension arc
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwEntityHandle arcHandle = {};
    // some code to get the data of arcHandle
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchRadialDimensionCreate(ZW_SKETCH_RADIAL_DIMENSION, arcHandle, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&arcHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchRadialDimensionCreate(ezwSketchRadialDimensionType radialType, szwEntityHandle arcHandle, const szwPoint2 *textPoint, double dimensionValue, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create a 2D arc length dimension at the active sketch.

    Function Guide: Sketch->Dimension->Arc Length

    @param [in] arcHandle the handle of dimension arc
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwEntityHandle arcHandle = {};
    // some code to get the data of arcHandle
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchArcLengthDimensionCreate(arcHandle, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&arcHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchArcLengthDimensionCreate(szwEntityHandle arcHandle, const szwPoint2 *textPoint, double dimensionValue, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create a 2D symmetry dimension at the active sketch.

    Function Guide: Sketch->Dimension->Symmetry

    @param [in] symmetryType symmetry dimension type
    @param [in] dimensionPoint the dimension point
    @param [in] centerLineHandle the handle of center line
    @param [in] textPoint text location point, nullptr to using default point
    @param [in] dimensionValue dimension value, zwInvalidDimensionValue to using default value
    @param [in] autoSwitch whether to auto switch dimension attributes
    @param [out] dimensionHandle handle of new dimension, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwSketchDimensionPoint dimensionPoint = {};
    // some code to get the data of dimensionPoint
    ...

    szwEntityHandle centerLineHandle = {};
    // some code to get the data of centerLineHandle
    ...

    szwEntityHandle dimHandle = {};
    ezwErrors ret = ZwSketchSymmetryDimensionCreate(ZW_SKETCH_LINEAR_SYMMETRY, dimensionPoint, centerLineHandle, nullptr, zwInvalidDimensionValue, &dimHandle);

    // free memory
    ZwEntityHandleFree(&dimensionPoint.entityHandle);
    ZwEntityHandleFree(&centerLineHandle);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchSymmetryDimensionCreate(ezwSketchSymmetryDimensionType symmetryType, szwSketchDimensionPoint dimensionPoint, szwEntityHandle centerLineHandle, const szwPoint2 *textPoint, double dimensionValue, int autoSwitch, szwEntityHandle *dimensionHandle);

    /**
    @ingroup ZwSketchDimension

    Create 2D perimeter dimension at the sketch.

    Function Guide: Sketch->Dimension->Perimeter

    @note
    The caller is responsible to free the dimensionHandle by using ZwEntityHandleListFree().

    @param [in] data perimeter dimension data
    @param [out] dimensionHandle handle of dimension(NULL to ignore) 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwSketchPerimeterDimensionCreate(szwPerimeterDimensionData data, szwEntityHandle *dimensionHandle);

    //====================================================================================================================
    /** @name Sketch Dimension Query */
    //====================================================================================================================

    /**
    @ingroup ZwSketchDimension

    Retrieves all dimensions of active sketch.

    @note
    The caller is responsible to free the dimensionList by using ZwEntityHandleListFree().

    @param [out] count count of dimensions
    @param [out] dimensionList handles of dimensions

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwSketchDimensionListGet(int *count, szwEntityHandle **dimensionList);

    /**
    @ingroup ZwSketchDimension

    Retrieves all geometries of the specified dimension.

    @note
    The caller is responsible to free the geometryList by using ZwEntityHandleListFree().

    @param [in] dimension handle of the dimension
    @param [out] count count of geometries
    @param [out] geometryList handles of geometries

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
    */
    ZW_API_C ezwErrors ZwSketchDimensionGeometryListGet(szwEntityHandle dimension, int *count, szwEntityHandle **geometryList);

    /**
    @ingroup ZwSketchDimension

    Retrieves all dimensions of the specified geometry.

    @param [in] geometry handle of the geometry
    @param [out] count count of dimensions
    @param [out] dimensionList handles of dimensions

    @note
    The caller is responsible to free the dimensionList by using ZwEntityHandleListFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSketchGeometryDimensionListGet(szwEntityHandle geometry, int *count, szwEntityHandle **dimensionList);

    /**
    @ingroup ZwSketchDimension

    Gets the type and subtype of the specified sketch dimension.
    It can't get the corresponding type if "*type = ZW_SKETCH_DIMENSION_UNKNOW".

    @param [in] dimensionHandle handle of the dimension
    @param [out] type type of the dimension
    @param [out] subtype subtype of the dimension, nullptr to ignore
                         different dimension type correspond to different subtype, for details, see the following mapping relationships:
                         1. linear dimension refers to ezwSketchLinearDimensionType
                         2. linear offset dimension refers to ezwSketchLinearOffsetDimensionType
                         3. angular dimension refers to ezwSketchAngularDimensionType
                         4. radial/diametric dimension refers to ezwSketchRadialDimensionType
                         5. symmetry dimension refers to ezwSketchSymmetryDimensionType

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwSketchDimensionTypeGet(szwEntityHandle dimensionHandle, ezwSketchDimensionType *type, int *subtype);

    /**
    @ingroup ZwSketchDimension

    Gets the dimension point data of the specified sketch dimension.

    @note
    The caller is responsible to free the dimensionPoints by using ZwMemoryFree.

    @param [in] dimensionHandle handle of the dimension
    @param [out] count number of the dimension points
    @param [out] dimensionPoints the list of the dimension point data

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

    @code
    szwEntityHandle dimensionHandle = {};
    // some code to get the data of dimensionHandle
    ...

    int count = 0;
    szwSketchDimensionPoint *dimensionPoints = nullptr;
    ezwErrors ret = ZwSketchDimensionPointGet(dimensionHandle, &count, &dimensionPoints);

    // free memory
    for (int i = 0; i < count; i++)
        ZwEntityHandleFree(&dimensionPoints[i].entityHandle);
    ZwMemoryFree(&dimensionPoints);
    ZwEntityHandleFree(&dimHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchDimensionPointGet(szwEntityHandle dimensionHandle, int *count, szwSketchDimensionPoint **dimensionPoints);

    /**
    @ingroup ZwSketchDimension

    Checks whether the dimension is a weak dimension or not.  

    @param [in] dimensionHandle handle of the dimension
    @param [out] isWeak 1 is weak dimension, 0 is not

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
    ZW_API_C ezwErrors ZwSketchDimensionWeakCheck(szwEntityHandle dimensionHandle, int *isWeak);

    //====================================================================================================================
    /** @name Dimension State */
    //====================================================================================================================
    /**
    @ingroup ZwSketchDimension

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
    ZW_API_C ezwErrors ZwSketchDimensionReferenceStateGet(szwEntityHandle dimension, int *state);

    /**
    @ingroup ZwSketchDimension

    Sets the reference state of the specified dimension. The dimension of the reference state is not evaluated by the 2D constraint solver.  
    Function Guide: Dimension Popup Menu -> Toggle Reference

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
    ZW_API_C ezwErrors ZwSketchDimensionReferenceStateSet(int count, const szwEntityHandle *dimensions, int state);
    //====================================================================================================================
    /** @name Symbol Image */
    //====================================================================================================================
    /**
    @ingroup ZwSketchDimension

    Creates a new image with the symbol image data.

    If the lock of data is true, the width and the height's aspect ratio should be the same as the image.
    The width and the height can also be zero and it will be calculated based on the input points.

    If imageHandle != NULL, output the handle of new image.

    Function Guide: Sketch->Reference->Image

    @note
    Interface ZwSketchSymbolImageInit can initialize variables of this function.
    In this function, imageHandle will be allocated memory, so remember to deallocate it by ZwEntityHandleFree.
    Notice the value range in data below:
    Opaque:1~100
    flip:0,1,2
    firstPtType:0,1
    lock:0,1
    angle:0~360

    @see ZwSketchSymbolImageInit

    @param [in] data symbol image data
    @param [in] embed 1-embed image file,0 not
    @param [out] imageHandle image handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_PATH
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR

    @code
    szwSymbolImage image{};
    ZwSketchSymbolImageInit(&image);
    //set image variables
    ...
    int embed=...;
    szwEntityHandle imageHandle{};
    ZwSketchSymbolImageCreate(data, embed, &imageHandle);
    ...
    ZwEntityHandleFree(&imageHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchSymbolImageCreate(szwSymbolImage data, int embed, szwEntityHandle *imageHandle);

    /**
    @ingroup ZwSketchDimension

    Outputs a list of symbol images in the active sketch.

    @note
    In this function, imageList will be allocated memory, so remember to deallocate it by ZwEntityHandleListFree.

    @param [out] count number of symbol entities
    @param [out] imageList list of symbol entity handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
    int count =0;
    szwEntityHandle*symbolList=nullptr;
    ZwSketchSymbolImageListGet(&count, &symbolList);
    ...
    ZwEntityHandleListFree(count,&symbolList);
    @endcode
    */
    ZW_API_C ezwErrors ZwSketchSymbolImageListGet(int *count, szwEntityHandle **imageList);

    /**
    @ingroup ZwSketchDimension

    Initialize the parameters of the szwSymbolImage.

    @note
    Set parameters after using ZwSketchSymbolImageInit.

    @param [out] data image symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwSketchSymbolImageInit(szwSymbolImage *data);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_DIMENSION_H */
