/**
@file zwapi_vector.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Vector API
*/

#pragma once
#ifndef ZW_API_VECTOR_H /* this ifndef surrounds entire header */
#define ZW_API_VECTOR_H

#include "zwapi_math_data.h"
#include "zwapi_math_vector_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Vector */
    //====================================================================================================================
    /**
    @ingroup ZwVector
    
    Determine whether two vectors of Two-dimensional are perpendicular within a specified angular tolerance.
    Vectors of zero length are considered perpendicular to any other vectors by this function.
    
    @code
       int isPerpendicular = -1;
       // assume that there's a variable named vector1(szwVector2), a variable named vector2(szwVector2) and
       // a variable named cosineTolerance(double)
       ZwVector2IsPerpendicular(vector1, vector2, cosineTolerance, &isPerpendicular);
       ...
    @endcode
    
    The CosTol tolerance is the cosine of the maximum angle allowed between the
    vectors for them to be considered perpendicular. The table below shows the maximum
    angle allowed between the vectors (right) for several values of CosTol (left):
    @verbatim
                      CosTol                  degrees
                      0.0871         -        85
                      0.0523         -        87
                      0.0175         -        89
                      0              -        90
                      -0.0017        -        90.1
                      -0.0087        -        90.5
                      -0.0175        -        91
                      -0.0349        -        92
                      -0.0872        -        95
    @endverbatim
    The tolerance of this function is realized with the absolute value of cosineTolerance. Therefore,
    please note that if cosineTolerance = 0.0175 or -0.0175 is entered, the two vectors are considered
    perpendicular at an angle ranging from 89 degrees to 91 degrees.
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] cosineTolerance cosine of maximum angle allowed for perpendicular
    @param [out] isPerpendicular 1-vectors are perpendicular, 0-vectors are NOT perpendicular
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2IsPerpendicular(szwVector2 vector1, szwVector2 vector2, double cosineTolerance, int *isPerpendicular);

    /******************************************************************************/ /**
    @ingroup ZwVector
    
    Determine whether two vectors of Three-dimensional are perpendicular within a specified angular tolerance.
    Vectors of zero length are considered perpendicular to any other vectors by this function.
    
    @code
       int isPerpendicular = -1;
       // assume that there's a variable named vector1(szwVector), a variable named vector2(szwVector) and
       // a variable named cosineTolerance(double)
       ZwVectorIsPerpendicular(vector1, vector2, cosineTolerance, &isPerpendicular);
       ...
    @endcode
    
    The CosTol tolerance is the cosine of the maximum angle allowed between the
    vectors for them to be considered perpendicular. The table below shows the maximum
    angle allowed between the vectors (right) for several values of CosTol (left):
    @verbatim
                  cosineTolerance           degrees
                      0.0871         -        85
                      0.0523         -        87
                      0.0175         -        89
                      0              -        90
                      -0.0017        -        90.1
                      -0.0087        -        90.5
                      -0.0175        -        91
                      -0.0349        -        92
                      -0.0872        -        95
    @endverbatim
    The tolerance of this function is realized with the absolute value of cosineTolerance. Therefore,
    please note that if cosineTolerance = 0.0175 or -0.0175 is entered, the two vectors are considered
    perpendicular at an angle ranging from 89 degrees to 91 degrees.
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] cosineTolerance cosine of maximum angle allowed for perpendicular
    @param [out] isPerpendicular 1-vectors are perpendicular, 0-vectors are NOT perpendicular
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorIsPerpendicular(szwVector vector1, szwVector vector2, double cosineTolerance, int *isPerpendicular);

    /**
    @ingroup ZwVector
    
    Compute the triple scalar product of three Three-dimensional vectors.
    
    @code
       double tripleScaleProduct= 0;
       // assume that there's a variable named vector1(szwVector), a variable named vector2(szwVector) and
       // a variable named vector3(szwVector) 
       ZwVectorTripleScaleProduct(vector1, vector2, vector3, &tripleScaleProduct);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] vector3 third vector
    @param [out] tripleScaleProduct The triple scale product of vector1 vector2 and vector3.   ( tripleScaleProduct = vector1 * (vector2 x vector3 ) )
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorTripleScaleProduct(szwVector vector1, szwVector vector2, szwVector vector3, double *tripleScaleProduct);

    /**
    @ingroup ZwVector
    
    Scale the two-dimensional vector according to the scale factor.
    
    @code
       szwVector2 scaleVector;
       // assume that there's a variable named inputVector(szwVector2) and a variable named scaleFactor(double) 
       ZwVector2Scaling(scaleFactor, inputVector, &scaleVector);
       ...
    @endcode
    
    @param [in] scaleFactor scaling factor
    @param [in] inputVector vector before scaling
    @param [out] scaleVector vector after scaling
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Scaling(double scaleFactor, szwVector2 inputVector, szwVector2 *scaleVector);

    /**
    @ingroup ZwVector
    
    Scale the three-dimensional vector according to the scale factor.
    
    @code
       szwVector scaleVector;
       // assume that there's a variable named inputVector(szwVector) and a variable named scaleFactor(double)
       ZwVectorScaling(scaleFactor, inputVector, &scaleVector);
       ...
    @endcode
    
    @param [in] scaleFactor scaling factor
    @param [in] inputVector vector before scaling
    @param [out] scaleVector vector after scaling
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorScaling(double scaleFactor, szwVector inputVector, szwVector *scaleVector);

    /**
    @ingroup ZwVector
    
    Scale the four-dimensional vector according to the scale factor.
    
    @code
       szwVector4 scaleVector;
       // assume that there's a variable named inputVector(szwVector4) and a variable named scaleFactor(double)
       ZwVector4Scaling(scaleFactor, inputVector, &scaleVector);
       ...
    @endcode
    
    @param [in] scaleFactor scaling factor
    @param [in] inputVector vector before scaling
    @param [out] scaleVector vector after scaling
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector4Scaling(double scaleFactor, szwVector4 inputVector, szwVector4 *scaleVector);

    /**
    @ingroup ZwVector
    
    Calculate the two-dimensional vector subtraction.
    
    @code
       szwVector2 subtractionVector;
       // assume that there's a variable named vector1(szwVector2) and a variable named vector2(szwVector2)
       ZwVector2Subtraction(vector1, vector2, &subtractionVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] subtractionVector the vector from vector1-vector2(two-dimensional)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Subtraction(szwVector2 vector1, szwVector2 vector2, szwVector2 *subtractionVector);

    /**
    @ingroup ZwVector
    
    Calculate the three-dimensional vector subtraction.
    
    @code
       szwVector subtractionVector;
       // assume that there's a variable named vector1(szwVector) and a variable named vector2(szwVector)
       ZwVectorSubtraction(vector1, vector2, &subtractionVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] subtractionVector the vector from vector1-vector2(three-dimensional)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorSubtraction(szwVector vector1, szwVector vector2, szwVector *subtractionVector);

    /**
    @ingroup ZwVector
    
    Calculate the magnitude of two-dimensional vector.
    
    @code
       double vectorMagnitude = -1;
       // assume that there's a variable named vector(szwVector2)
       ZwVector2Magnitude(vector, &vectorMagnitude);
       ...
    @endcode
    
    @param [in] vector the vector
    @param [out] vectorMagnitude the magnitude of two-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Magnitude(szwVector2 vector, double *vectorMagnitude);

    /**
    @ingroup ZwVector
    
    Calculate the magnitude of three-dimensional vector.
    
    @code
       double vectorMagnitude = -1;
       // assume that there's a variable named vectorData(szwVector)
       ZwVectorMagnitude(vectorData, &vectorMagnitude);
       ...
    @endcode
    
    @param [in] vectorData the vector
    @param [out] vectorMagnitude the magnitude of three-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorMagnitude(szwVector vectorData, double *vectorMagnitude);

    /**
    @ingroup ZwVector
    
    Calculate the dot product of two-dimensional vector.
    
    @code
       double dotPorduct = 0;
       // assume that there's a variable named vector1(szwVector2) and a variable named vector2(szwVector2)
       ZwVector2Dot(vector1, vector2, &dotPorduct);
       ...
    @endcode
    
    @param [in] vector1 the first vector
    @param [in] vector2 the second vector
    @param [out] dotPorduct the dot product of two-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Dot(szwVector2 vector1, szwVector2 vector2, double *dotPorduct);

    /**
    @ingroup ZwVector
    
    Calculate the dot product of three-dimensional vector.
    
    @code
       double dotPorduct = 0;
       // assume that there's a variable named vector1(szwVector) and a variable named vector2(szwVector)
       ZwVectorDot(vector1, vector2, &dotPorduct);
       ...
    @endcode
    
    @param [in] vector1 the first vector
    @param [in] vector2 the second vector
    @param [out] dotPorduct the dot product of three-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorDot(szwVector vector1, szwVector vector2, double *dotPorduct);

    /**
    @ingroup ZwVector
    
    Calculate the negative of two-dimensional vector.
    
    @code
       szwVector2 negativeV;
       // assume that there's a variable named vector(szwVector2)
       ZwVector2Negated(vector, &negativeV);
       ...
    @endcode
    
    @param [in] vector the input vector
    @param [out] negativeV the negative vector of two-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Negated(szwVector2 vector, szwVector2 *negativeV);

    /**
    @ingroup ZwVector
    
    Calculate the negative of three-dimensional vector.
    
    @code
       szwVector negativeV;
       // assume that there's a variable named vectorData(szwVector)
       ZwVectorNegated(vectorData, &negativeV);
       ...
    @endcode
    
    @param [in] vectorData the input vector
    @param [out] negativeV the negative vector of three-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorNegated(szwVector vectorData, szwVector *negativeV);

    /**
    @ingroup ZwVector
    
    Determine whether two vectors of two-dimensional are equal within a specified tolerance.
    
    @code
       int isEqual = -1;
       // assume that there's a variable named vector1(szwVector2),a variable named vector2(szwVector2)
       // and a variable named tolerance(double)
       ZwVector2IsEqual(vector1, vector2, tolerance, &isEqual);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] tolerance max tolerance allowed for equal
    @param [out] isEqual 1-vectors are equal, 0-vectors are NOT equal
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2IsEqual(szwVector2 vector1, szwVector2 vector2, double tolerance, int *isEqual);

    /**
    @ingroup ZwVector
    
    Determine whether two vectors of three-dimensional are equal within a specified tolerance.
    
    @code
       int isEqual = -1;
       // assume that there's a variable named vector1(szwVector),a variable named vector2(szwVector)
       // and a variable named tolerance(double)
       ZwVectorIsEqual(vector1, vector2, tolerance, &isEqual);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] tolerance max tolerance allowed for equal
    @param [out] isEqual 1-vectors are equal, 0-vectors are NOT equal
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorIsEqual(szwVector vector1, szwVector vector2, double tolerance, int *isEqual);

    /**
    @ingroup ZwVector
    
    Determine whether two vectors of four-dimensional are equal within a specified tolerance.
    
    @code
       int isEqual = -1;
       // assume that there's a variable named vector1(szwVector4),a variable named vector2(szwVector4)
       // and a variable named tolerance(double)
       ZwVector4IsEqual(vector1, vector2, tolerance, &isEqual);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] tolerance max tolerance allowed for equal
    @param [out] isEqual 1-vectors are equal, 0-vectors are NOT equal
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector4IsEqual(szwVector4 vector1, szwVector4 vector2, double tolerance, int *isEqual);

    /**
    @ingroup ZwVector
    
    Determine whether the two-dimensional is zero-vector within a specified tolerance.
    
    @code
       int isZero = -1;
       // assume that there's a variable named vector(szwVector2) and a variable named tolerance(double)
       ZwVector2IsZero(vector, tolerance, &isZero);
       ...
    @endcode
    
    @param [in] vector the vector
    @param [in] tolerance max tolerance allowed for zero
    @param [out] isZero 1-vector is zero, 0-vectors is NOT zero
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2IsZero(szwVector2 vector, double tolerance, int *isZero);

    /**
    @ingroup ZwVector
    
    Determine whether the three-dimensional is zero-vector within a specified tolerance.
    
    @code
       int isZero = -1;
       // assume that there's a variable named vectorData(szwVector) and a variable named tolerance(double)
       ZwVectorIsZero(vectorData,tolerance,&isZero);
       ...
    @endcode
    
    @param [in] vectorData the vector
    @param [in] tolerance max tolerance allowed for zero
    @param [out] isZero 1-vector is zero, 0-vectors is NOT zero
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorIsZero(szwVector vectorData, double tolerance, int *isZero);

    /**
    @ingroup ZwVector
    
    Determine whether the four-dimensional is zero-vector within a specified tolerance.
    
    @code
       int isZero = -1;
       // assume that there's a variable named vector(szwVector4) and a variable named tolerance(double)
       ZwVector4IsZero(vector, tolerance, &isZero);
       ...
    @endcode
    
    @param [in] vector the vector
    @param [in] tolerance max tolerance allowed for zero
    @param [out] isZero 1-vector is zero, 0-vectors is NOT zero
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector4IsZero(szwVector4 vector, double tolerance, int *isZero);

    /**
    @ingroup ZwVector
    
    Compute the sum of two vectors of two-dimensional.
    
    @code
       szwVector2 sumVector;
       // assume that there's a variable named vector1(szwVector2),a variable named vector2(szwVector2)
       ZwVector2Sum(vector1, vector2, &sumVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] sumVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2Sum(szwVector2 vector1, szwVector2 vector2, szwVector2 *sumVector);

    /**
    @ingroup ZwVector
    
    Compute the sum of two vectors of three-dimensional.
    
    @code
       szwVector sumVector;
       // assume that there's a variable named vector1(szwVector),a variable named vector2(szwVector)
       ZwVectorSum(vector1, vector2, &sumVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] sumVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorSum(szwVector vector1, szwVector vector2, szwVector *sumVector);

    /**
    @ingroup ZwVector
    
    Compute the affine combine of two vectors of two-dimensional, the first vector is not
    scaled, the second vector is scaled according to the scale factor.
    
    @code
       szwVector2 combinedVector;
       // assume that there's a variable named vector1(szwVector2),a variable named vector2(szwVector2)
       // and a variable named scaleFactor(double)
       ZwVector2AffineCombine(vector1, vector2, scaleFactor, &combinedVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] scaleFactor the scaling factor of vector2
    @param [out] combinedVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2AffineCombine(szwVector2 vector1, szwVector2 vector2, double scaleFactor, szwVector2 *combinedVector);

    /**
    @ingroup ZwVector
    
    Compute the affine combine of two vectors of three-dimensional, the first vector is not
    scaled, the second vector is scaled according to the scale factor.
    
    @code
       szwVector combinedVector;
       // assume that there's a variable named vector1(szwVector),a variable named vector2(szwVector)
       // and a variable named scaleFactor(double)
       ZwVectorAffineCombine(vector1, vector2, scaleFactor, &combinedVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] scaleFactor the scaling factor of vector2
    @param [out] combinedVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorAffineCombine(szwVector vector1, szwVector vector2, double scaleFactor, szwVector *combinedVector);

    /**
    @ingroup ZwVector
    
    Compute the affine combine of two vectors of two-dimensional, the first vector is scaled according to the scalefactor1,
    the second vector is scaled according to the scalefactor2.
    
    @code
       szwVector2 combinedVector;
       // assume that there's a variable named vector1(szwVector2),a variable named vector2(szwVector2),
       // a variable named scaleFactor1(double) and a variable named scaleFactor2(double)
       ZwVector2LinearCombine(vector1, vector2, scaleFactor1, scaleFactor2, &combinedVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] scaleFactor1 the scaling factor of vector1
    @param [in] scaleFactor2 the scaling factor of vector2
    @param [out] combinedVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2LinearCombine(szwVector2 vector1, szwVector2 vector2, double scaleFactor1, double scaleFactor2, szwVector2 *combinedVector);

    /**
    @ingroup ZwVector
    
    Compute the affine combine of two vectors of two-dimensional, the first vector is scaled according to the scalefactor1,
    the second vector is scaled according to the scalefactor2.
    
    @code
       szwVector combinedVector;
       // assume that there's a variable named vector1(szwVector),a variable named vector2(szwVector),
       // a variable named scaleFactor1(double) and a variable named scaleFactor2(double)
       ZwVectorLinearCombine(vector1, vector2, scaleFactor1, scaleFactor2, &combinedVector);
       ...
    @endcode
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] scaleFactor1 the scaling factor of vector1
    @param [in] scaleFactor2 the scaling factor of vector2
    @param [out] combinedVector the sum of two vectors
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorLinearCombine(szwVector vector1, szwVector vector2, double scaleFactor1, double scaleFactor2, szwVector *combinedVector);

    /**
    @ingroup ZwVector
    
    Convert a two-dimensional vector to a three-dimensional vector and z = 0.
    
    @code
       szwVector vector2;
       // assume that there's a variable named vector1(szwVector2)
       ZwVector2ToVector3(vector1, &vector2);
       ...
    @endcode
    
    @param [in]  vector1 two-dimensional vector
    @param [out] vector2 three-dimensional vector ( z = 0 )
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2ToVector3(szwVector2 vector1, szwVector *vector2);

    /**
    @ingroup ZwVector
    
    Convert a three-dimensional vector to a two-dimensional vector. The Z coordinate of the
    three-dimensional vector is deleted.
    
    @code
       szwVector2 vector2;
       // assume that there's a variable named vector1(szwVector)
       ZwVector3ToVector2(vector1, &vector2);
       ...
    @endcode
    
    @param [in]  vector1 three-dimensional vector
    @param [out] vector2 two-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector3ToVector2(szwVector vector1, szwVector2 *vector2);

    /**
    @ingroup ZwVector
    
    Convert a three-dimensional vector to a four-dimensional vector. The weight of the
    four-dimensional vector is 1.
    
    @code
       szwVector4 vector2;
       // assume that there's a variable named vector1(szwVector)
       ZwVector3ToVector4(vector1, &vector2);
       ...
    @endcode
    
    @param [in]  vector1 three-dimensional vector
    @param [out] vector2 four-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector3ToVector4(szwVector vector1, szwVector4 *vector2);

    /**
    @ingroup ZwVector
    
    Convert a three-dimensional vector to a four-dimensional vector. The weight of the
    four-dimensional vector is vectorWeight.
    
    @code
       szwVector4 vector2;
       // assume that there's a variable named vector1(szwVector) and a variable named vectorWeight(double)
       ZwVector3ToVector4WithWeight(vector1, vectorWeight ,&vector2);
       ...
    @endcode
    
    @param [in] vector1 three-dimensional vector
    @param [in] vectorWeight weight of the four-dimensional vector
    @param [out] vector2 four-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector3ToVector4WithWeight(szwVector vector1, double vectorWeight, szwVector4 *vector2);

    /**
    @ingroup ZwVector
    
    Convert a four-dimensional vector to a three-dimensional vector. The weight of the
    four-dimensional vector is deleted.
    
    @code
       szwVector vector2;
       // assume that there's a variable named vector1(szwVector4) 
       ZwVector4ToVector3(vector1, &vector2);
       ...
    @endcode
    
    @param [in]  vector1 four-dimensional vector
    @param [out] vector2 three-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector4ToVector3(szwVector4 vector1, szwVector *vector2);

    /**
    @ingroup ZwVector
    
    Convert a four-dimensional vector which divides the weight to a three-dimensional vector, then delete
    the weight of the four-dimensional vector.
    
    @code
       szwVector vector2;
       // assume that there's a variable named vector1(szwVector4) 
       ZwVector4ToVector3WithWeight(vector1, &vector2);
       ...
    @endcode
    
    @param [in]  vector1 four-dimensional vector
    @param [out] vector2 three-dimensional vector
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector4ToVector3WithWeight(szwVector4 vector1, szwVector *vector2);

    /**
    @ingroup ZwVector
    
    Determine whether exist scale1 and scale2 let scale1 * vector1 +scale2 * vector2 = combineVector
    within a specified tolerance.If vector1 and vector2 are zero vector, this function isExist will 
    be return as 0.
    
    @code
       int isExist = -1;
       double scale1 = 0;
       double scale2 = 0;
       // assume that there's a variable named vector1(szwVector2), a variable named vector1(szwVector2), 
       // a variable named combineVector(szwVector2) ,and a variable named tolerance(double)
       ZwVector2LinearComponents(vector1, vector2, combineVector, tolerance, &isExist, &scale1, &scale2);
       ...
    @endcode
    
    @param [in]  vector1 the first vector
    @param [in]  vector2 the second vector
    @param [in]  combineVector the target vector of linear combination
    @param [in]  tolerance max tolerance allowed for linear combination
    @param [out]  isExist   1-exist  0-Not exist
    @param [out]  scale1 parameters of linear combinations
    @param [out]  scale2 parameters of linear combinations
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVector2LinearComponents(szwVector2 vector1, szwVector2 vector2, szwVector2 combineVector, double tolerance, int *isExist, double *scale1, double *scale2);

    /**
    @ingroup ZwVector
    
    Determine whether exist scale1 and scale2 let scale1 * vector1 +scale2 * vector2 = combineVector 
    within a specified tolerance.If vector1 and vector2 are zero vector, this function isExist will
    be return as 0.
    
    @code
       int isExist = -1;
       double scale1 = 0;
       double scale2 = 0;
       // assume that there's a variable named vector1(szwVector), a variable named vector1(szwVector), 
       // a variable named combineVector(szwVector), and a variable named tolerance(double)
       ZwVectorLinearComponents(vector1, vector2, combineVector, tolerance, &isExist, &scale1, &scale2);
       ...
    @endcode
    
    @param [in]  vector1 the first vector
    @param [in]  vector2 the second vector
    @param [in]  combineVector the target vector of linear combination
    @param [in]  tolerance max tolerance allowed for linear combination
    @param [out]  isExist  1-exist  0-Not exist
    @param [out]  scale1 parameters of linear combinations
    @param [out]  scale2 parameters of linear combinations
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorLinearComponents(szwVector vector1, szwVector vector2, szwVector combineVector, double tolerance, int *isExist, double *scale1, double *scale2);

    /**
    @ingroup ZwVector
    
    Normalizes a direction vector to unit magnitude with a length of 1 unit.
    
    @param [in,out] vector direction vector
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwVectorNormalize(szwVector *vector);
    
    /**
    @ingroup ZwVector
    
    Initializes a normalized "vector" that points along the direction from "point1" to "point2" with a length of 1 unit.
    
    @param [in] point1 first point
    @param [in] point2 second point
    @param [out] vector direction vector
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorInit(szwPoint point1, szwPoint point2, szwVector *vector);
    
    /**
    @ingroup ZwVector
    
    Calculates the angle (radians) between the input vectors.
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] angle angle (radians) between vectors
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwVectorAngleGet(szwVector vector1, szwVector vector2, double *angle);
    
    /**
    @ingroup ZwVector
    
    Gets the cross product of two vectors.
    
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [out] cross cross product of vector1 and vector2
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorCrossProduct(szwVector vector1, szwVector vector2, szwVector *cross);
    
    /**
    @ingroup ZwVector
    
    Creates a vector that is perpendicular to another vector.
    
    @param [in] vector reference vector
    @param [out] perpendicular vector perpendicular to input "vector"
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwVectorPerpendicularGet(szwVector vector, szwVector *perpendicular);
    
    
    /**
    @ingroup ZwVector
    
    Reverses the direction of the input vector.
    
    @param [in,out] vector vector
    
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwVectorReverse(szwVector *vector);
    
    /**
    @ingroup ZwVector
    
    Determine whether two vectors are parallel within a specified angular tolerance.  
    
    The cosineTolerance tolerance is the cosine of the maximum angle allowed between the  
    vectors for them to be considered parallel. The table below shows the maximum  
    angle allowed between the vectors (right) for several values of cosTol (left):  
    @verbatim
                   cosineTolerance            degrees
                         0.9          -        25.84
                         0.9848       -          10
                         0.9962       -          5
                         0.9986       -          3
                         0.9994       -          2
                         0.99985      -          1
                         0.99996      -         0.5
                         0.999998     -         0.1
    @endverbatim
    
    @param [in] orient 0 = parallel vectors can be in same or opposite direction
                       1 = Parallel vectors must point in same direction
                       2 = Parallel vectors must point in opposite directions
    @param [in] vector1 first vector
    @param [in] vector2 second vector
    @param [in] cosineTolerance cosine of maximum angle allowed for parallelism
    @param [out] ifParallel
    -        1: vectors are parallel; if Orient is 1, the vectors also point in the same
                direction; if Orient is 2, the vectors point in opposite directions.
    -        0: vectors are NOT parallel, or are not oriented with respect to each other
                as required by Orient, or at least one vector degenerates to zero length,
                or error occurs.
    @retval return
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwVectorParallelCheck(int orient, szwVector vector1, szwVector vector2, double cosineTolerance, int *ifParallel);

    /**
    @ingroup zwapi_geometry_vector

    Applies transformation matrix "inputMatrix" to "vector".

    @param [in] inputMatrix transformation matrix
    @param [in,out] vector vector to transformation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
    szwMatrix inputMatrix;
    ...
    szwVector vector;
    ZwVectorTransform(inputMatrix,&vector);
    @endcode
    */
    ZW_API_C ezwErrors ZwVectorTransform(szwMatrix inputMatrix, szwVector *vector);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VECTOR_H */
