/**
@file zwapi_preedge.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D PreEdge API
*/

#pragma once
#ifndef ZW_API_PREEDGE_H /* this ifndef surrounds entire header */
#define ZW_API_PREEDGE_H

#include "zwapi_util.h"
#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name PreEdge Query */
    //====================================================================================================================
    /**
    @ingroup ZwPreEdge

    Acquire the minimum distance between the point and the curve on face, the difference
    from cvxPntEntDist() is that the function will be output the closest point on the UV line
    of the face.

    @param [in] preEdgeHandle handle data of pre-edge
    @param [in] point point coordinates of the inquiry
    @param [out] T parameter value at closest point (NULL to ignore)
    @param [out] targetPoint coordinates of closest point (NULL to ignore)
    @param [out] distance the minimum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR

    @code
        szwEntityHandle edgeHandle=...;
        ...
        szwPoint point{};
        ...
        double T = -1;
        szwPoint targetPoint{};
        ...
        double distance = -1;
        ...
        ZwPreEdgePointDistanceGet(edgeHandle, point, &T, &targetPoint, &distance);
    @endcode
    */
    ZW_API_C ezwErrors ZwPreEdgePointDistanceGet(szwEntityHandle preEdgeHandle, szwPoint point, double *T, szwPoint *targetPoint, double *distance);

    /**
    @ingroup ZwPreEdge

    Evaluates a pre-edge at a specified parameter value. Computes
    directional and point on the surface from the UV curve.

    @note
    "level" specifies the level of evaluation. The higher the level, more
    data gets returned (at the expense of greater computation).

    @verbatim
                         level
          |  0  |       1        |       2        |     3
          +-----+----------------+----------------+-------------
          | pnt |  derivative_1  |  derivative_2  | derivative_3
    @endverbatim

    @param [in] preedgeHandle handle of preedge
    @param [in] t t parameter value on curve
    @param [in] level level of evaluation(0 ~ 3). See description below
    @param [out] evaluation result

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
       szwEntityHandle preedgeHandle=...;
       double t = ...;
       int level = ...;
       ...
       szwCurveDerivative eval;
       ZwPreEdgeDifferentiate(preedgeHandle,t,level,&eval);
       ...
        ZwEntityHandleFree(&preedgeHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwPreEdgeDifferentiate(szwEntityHandle preedgeHandle, double t, int level, szwCurveDerivative *evaluation);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PREEDGE_H */
