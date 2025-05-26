/**
@file zwapi_shape.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Shape API
*/

#pragma once

#ifndef ZW_API_SHAPE_H /* this ifndef surrounds entire header */
#define ZW_API_SHAPE_H

#include "zwapi_util.h"
#include "zwapi_brep_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Shape Get */
    //====================================================================================================================
    /**
    @ingroup ZwShape
    
    Outputs a list of handles of the shapes that belong to
    the active part.
    @note
    The caller is responsible to free the shapes by using ZwEntityHandleListFree().
    
    @param [out] count number of shapes
    @param [out] shapes list of shape handles
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwShapeListGet(int *count, szwEntityHandle **shapes);

    //====================================================================================================================
    /** @name Shape Operate */
    //====================================================================================================================
    /**
    @ingroup ZwShape

    Matches and sews free edges in the active part using the input proximity
    tolerance.  If "tolerance" is input as 0.0, the active part's default proximity
    tolerance is used.

    @note
    Input NULL for "openEdgesCount" and/or "maxGap" if you are not interested in
    the information returned via those variables.

    @param [in] tolerance 3D proximity tolerance (mm) (0.0 for default)
    @param [out] openEdgesCount number of unmatched/open edges after sew (or NULL)
    @param [out] maxGap maximum gap between all matched edges after sew(or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MODELING_DATA_ERROR

    @code
       double tolerance = ...;
       int openEdgesCount = 0;
       double maxGap = 0;
       ZwShapeEdgeSewAll(tolerance,&openEdgesCount,&maxGap);
    @endcode
    */
    ZW_API_C ezwErrors ZwShapeEdgeSewAll(double tolerance, int *openEdgesCount, double *maxGap);

    //====================================================================================================================
    /** @name Shape Query */
    //====================================================================================================================
    /**
    @ingroup ZwShape
    
    Outputs a list of handle of the faces that belong to
    the specified shape in the active file.
    
    @note
    The caller is responsible to free the faceList by using ZwEntityHandleListFree().
    
    @param [in] shapeHandle shape handle
    @param [out] count number of faces
    @param [out] faceList list of face handle
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwShapeFaceListGet(szwEntityHandle shapeHandle, int *count, szwEntityHandle **faceList);

    /**
    @ingroup ZwShape

    Outputs a list of handles of the edge that belong to
    the specified shape in the active file.

    @note
    TThe caller is responsible to free the edgeList by using ZwEntityHandleListFree.

    @param [in] shapeHandle shape handle
    @param [out] count number of edges
    @param [out] edgeList list of edge handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INP
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwShapeEdgeListGet(szwEntityHandle shapeHandle, int *count, szwEntityHandle **edgeList);

    /**
    @ingroup ZwShape

    Analyzes thickness of surfaces, then get the information of minimum and maximum.

    @note
    If the faceCount is 0, it will try to analyze all faces of the input shape.
    All the elements of input parameter 'faces' should belong to the input shape. Or this function will return ZW_API_INVALID_INPUT.

    @code
    szwEntityHandle shapeHandle;
    double minimum = 0.0, maximum = 0.0;
    ... // code to get data of shapeHandle
    // case that not input the faces
    ezwErrors result = ZwShapeThicknessGet(shapeHandle, 0, nullptr, ZW_PART_THICKNESS_BALL_ROLLING, &minimum, &maximum);
    // case that input the faces
    int faceCount = 3;
    szwEntityHandle faces[3];
    ... // code to get data of faces
    result = ZwShapeThicknessGet(shapeHandle, faceCount, faces, ZW_PART_THICKNESS_BALL_ROLLING, &minimum, &maximum);
    @endcode

    @param [in] shape shape handle that to analyze
    @param [in] faceCount count of surfaces, can be 0
    @param [in] faces array of surfaces, can be NULL
    @param [in] method method of thickness analysis
    @param [out] minimum minimum of thickness
    @param [out] maximum maximum of thickness

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwShapeThicknessGet(szwEntityHandle shape, int faceCount, const szwEntityHandle *faces, ezwPartThicknessMethods method, double *minimum, double *maximum);

    /**
    @ingroup ZwShape

    Gets the flag indicating if shape is open.
    "Open" means the faces of the shape are not close.

    @param [in] shape shape handle (in active file)
    @param [out] isOpen open flag for shape (1=open, 0=closed)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwShapeOpenCheck(szwEntityHandle shape, int *isOpen);

    /**
    @ingroup ZwShape

    Get internal area of shape specified by shapeHandle.

    @param [in] shapeHandle shape handle
    @param [out] area internal area

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR

    @code
       szwEntityHandle shapeHandle{};
       double area = 0.0;
       ... // some code to get the data of variables
       ZwShapeInternalAreaGet(shapeHandle, &area);
       ...
       ZwEntityHandleFree(&shapeHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwShapeInternalAreaGet(szwEntityHandle shapeHandle, double *area);

    //====================================================================================================================
    /** @name Shape Interference */
    //====================================================================================================================
    /**
    @ingroup ZwShape

    Gets the position relationship between two closed shapes in the active part, such as inclusion, interference, contact or no contact.

    @note
    The function only supports shape in the active part, and does not support shape in sub-assembly or component.

    @param [in] shapeA the first shape
    @param [in] shapeB the second shape
    @param [out] type interference type

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
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwShapeInterferenceTypeGet(szwEntityHandle shapeA, szwEntityHandle shapeB, ezwInterferenceType *type);

    /**
    @ingroup ZwShape

    Makes an interference check between two closed shapes in the active part, this function will save the interference area as shape objects 
    with red color if the input 'saveGeomtry' is 1.  

    @note
    When saveGeomtry' is 1, if the input shapes belong to the same component, the new generated interference shapes will be in the component, 
    else will be in the top-level assembly file.  

    @param [in] shapeA the first shape
    @param [in] shapeB the second shape
    @param [in] saveGeomtry whether to save to interference shapes(1-yes, 0-no)
    @param [out] interferenceCount the count of interference shapes
    @param [out] interferenceShapes the handles of interference shapes (NULL to ignore)
    @param [out] totalVolume the total volume of interference shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwShapeInterferenceCheck(szwEntityHandle shapeA, szwEntityHandle shapeB, int saveGeomtry, int *interferenceCount, szwEntityHandle **interferenceShapes, double *totalVolume);


    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHAPE_H */