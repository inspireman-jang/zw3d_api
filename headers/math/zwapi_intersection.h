/**
@file zwapi_intersection.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Intersection API
*/

#pragma once
#ifndef ZW_API_INTERSECTION_H /* this ifndef surrounds entire header */
#define ZW_API_INTERSECTION_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Ray With Objects */
    //====================================================================================================================
    /**
    @ingroup ZwIntersection

    Intersects the input ray with the input shapes and outputs the intersection points.

    @note
    The caller is responsible to free the intersectionPoints by using ZwMemoryFree.

    @param [in] nShapes number of shapes
    @param [in] shapes list of shape handles
    @param [in] faceTrim face trim option
    @param [in] ray ray defined by a point and a direction
    @param [in] infinite infinite flag     
                         1: calculate the positive and negative directions of the ray  
                         0: calculate only the positive direction of the ray
    @param [in] length the effective length of the ray (input 0.0, the length is unlimited)
    @param [out] count number of intersection point
    @param [out] intersectionPoints list of intersection points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int nShapes = 0;
    szwEntityHandle *shapes = nullptr;
    // some code to get the data of shapes
    ...

    int count = 0;
    szwIntersectionPoint *intersectionPoints = nullptr;
    ezwErrors ret = ZwRayShapeIntersect(nShapes, shapes, ZW_TRIM_ALL, ray, 1, 0.0, &count, &intersectionPoints);

    // free memory
    for (int i = 0; i < count; i++)
        ZwEntityHandleFree(&intersectionPoints[i].faceHandle);
    ZwMemoryFree(&intersectionPoints);
    ZwEntityHandleListFree(nShapes, &shapes);
    @endcode
    */
    ZW_API_C ezwErrors ZwRayShapeIntersect(int nShapes, const szwEntityHandle *shapes, ezwFaceTrim faceTrim, szwAxis ray, int infinite, double length, int *count, szwIntersectionPoint **intersectionPoints);

    /**
    @ingroup ZwIntersection

    Intersects the input ray with the input component and outputs the intersection points.

    @note
    The caller is responsible to free the intersectionPoints by using ZwMemoryFree.

    @param [in] component component handle (nullptr to calculate the active part)
    @param [in] faceTrim face trim option
    @param [in] onlyVisible intersect with only visible components or all components (1: just visible; 0: all)
    @param [in] ray ray defined by a point and a direction
    @param [in] infinite infinite flag     
                         1: calculate the positive and negative directions of the ray  
                         0: calculate only the positive direction of the ray
    @param [in] radius the intersection radius of the ray (input 0.0 to use ray intersection) 
    @param [in] length the effective length of the ray (input 0.0, the length is unlimited)
    @param [out] count number of intersection point
    @param [out] intersectionPoints list of intersection points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwAxis ray = {};
    // some code to get the data of ray
    ...

    int count = 0;
    szwIntersectionPoint *intersectionPoints = nullptr;
    ezwErrors ret = ZwRayComponentIntersectWithRadius(nullptr, ZW_TRIM_ALL, 1, ray, 1, 0.0, 0.0, &count, &intersectionPoints);

    // free memory
    for (int i = 0; i < count; i++)
        ZwEntityHandleFree(&intersectionPoints[i].faceHandle);
    ZwMemoryFree(&intersectionPoints);
    @endcode
    */
    ZW_API_C ezwErrors ZwRayComponentIntersectWithRadius(const szwEntityHandle *component, ezwFaceTrim faceTrim, int onlyVisible, szwAxis ray, int infinite, double radius, double length, int *count, szwIntersectionPoint **intersectionPoints);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_INTERSECTION_H */
