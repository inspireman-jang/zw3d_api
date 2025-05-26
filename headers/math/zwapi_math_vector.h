/**
@file zwapi_math_vector.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Vector API
*/
/**
@defgroup zwapi_math_vector Vector API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Vector API
*/

#pragma once
#ifndef ZW_API_MATH_VECTOR_H /* this ifndef surrounds entire header */
#define ZW_API_MATH_VECTOR_H

#include "zwapi_math_data.h"
#include "zwapi_math_vector_data.h"
#include "zwapi_vector.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Vector */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_vector
    
    Initializes a normalized "Vector" that points along  
    the direction from "Point1" to "Point2". 
    
    @deprecated This API will not be updated anymore, please use ZwVectorInit()
    @see ZwVectorInit
    
    @param [in] Point1 first point
    @param [in] Point2 second point
    @param [out] Vector direction vector
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxVecInit(svxPoint *Point1, svxPoint *Point2, svxVector *Vector);

    /**
    @ingroup zwapi_math_vector
    
    Normalizes a direction vector to unit magnitude (1.0).
    
    @deprecated This API will not be updated anymore, please use ZwVectorNormalize()
    @see ZwVectorNormalize
    
    @param [in,out] Vector direction vector
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxVecNormalize(svxVector *Vector);

    /**
    @ingroup zwapi_math_vector
    
    Calculates the angle (radians) between the input vectors.
    
    @deprecated This API will not be updated anymore, please use ZwVectorAngleGet()
    @see ZwVectorAngleGet
    
    @param [in] V1 first vector
    @param [in] V2 second vector
    @param [out] Angle angle (radians) between vectors
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C void cvxVecAngle(svxVector *V1, svxVector *V2, double *Angle);

    /**
    @ingroup zwapi_math_vector
    
    Gets the cross product of two vectors.
    
    @deprecated This API will not be updated anymore, please use ZwVectorCrossProduct()
    @see ZwVectorCrossProduct
    
    @param [in] V1 first vector
    @param [in] V2 second vector
    @param [out] Cross cross product of V1 and V2
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxVecCross(svxVector *V1, svxVector *V2, svxVector *Cross);

    /**
    @ingroup zwapi_math_vector
    
    Creates a vector that is perpendicular to another vector.
    
    @deprecated This API will not be updated anymore, please use ZwVectorPerpendicularGet()
    @see ZwVectorPerpendicularGet
    
    @param [in] Vector reference vector
    @param [out] Perp vector perpendicular to input "Vector"
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxVecPerp(svxVector *Vector, svxVector *Perp);

    /******************************************************************************/ /**
    @ingroup zwapi_math_vector
    
    Reverses the direction of the input vector.
    
    @deprecated This API will not be updated anymore, please use ZwVectorReverse()
    @see ZwVectorReverse
    
    @param [in,out] Vector vector
    
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxVecReverse(svxVector *Vector);

    /**
    @ingroup zwapi_math_vector
    
    Determine whether two vectors are parallel within a specified angular tolerance.
    
    The CosTol tolerance is the cosine of the maximum angle allowed between the  
    vectors for them to be considered parallel. The table below shows the maximum  
    angle allowed between the vectors (right) for several values of CosTol (left):
    @verbatim
                         CosTol               degrees
                         0.9          -        25.84
                         0.9848       -          10
                         0.9962       -          5
                         0.9986       -          3
                         0.9994       -          2
                         0.99985      -          1
                         0.99996      -         0.5
                         0.999998     -         0.1
    @endverbatim
    
    @deprecated This API will not be updated anymore, please use ZwVectorParallelCheck()
    @see ZwVectorParallelCheck
    
    @param [in] Orient 0 = parallel vectors can be in same or opposite direction  
                       1 = Parallel vectors must point in same direction  
                       2 = Parallel vectors must point in opposite directions
    @param [in] V1 first vector
    @param [in] V2 second vector
    @param [in] CosTol cosine of maximum angle allowed for parallelism
    
    @retval return
    -        1: vectors are parallel; if Orient is 1, the vectors also point in the same
                direction; if Orient is 2, the vectors point in opposite directions.
    -        0: vectors are NOT parallel, or are not oriented with respect to each other
                as required by Orient, or at least one vector degenerates to zero length,
                or error occurs.
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxVecParallelChk(int Orient, svxVector *V1, svxVector *V2, double CosTol);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATH_VECTOR_H */
