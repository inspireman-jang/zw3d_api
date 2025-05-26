/**
@file zwapi_matrix.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures
*/

#pragma once
#ifndef ZW_API_MATRIX_H /* this ifndef surrounds entire header */
#define ZW_API_MATRIX_H

#include "zwapi_math_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Transformation Matrix */
    //====================================================================================================================

    /**
    @ingroup ZwMatrix

    Calculates the eigenvalues and eigenvectors of a 3x3 matrix.

    @note
    The caller is responsible to free the values & vectors by using ZwMemoryFree.  
    The caller may pass NULL for the Values argument if the eigenvalues are not wanted.  
    This function always computes three eigenvalues, repeating values in
    the Values array if necessary.  
    The caller may pass NULL for the Vectors argument if the
    eigenvectors are not wanted.  
    Vectors[i] is the eigenvector corresponding to the eigenvalue
    Values[i], but the eigenvalues are not sorted.  
    The largest or smallest eigenvalue may be in any element of the Values array.

    @param [in] inputMatrix matrix
    @param [out] values three real-valued eigenvalues (or NULL)
    @param [out] vectors three eigenvectors for the eigenvalues (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
      szwMatrix3 inputMatrix=...;
      ...
       double *values = NULL;
       szwVector *vectors = NULL;
       ZwMatrix3Eigen(inputMatrix,&values,&vectors);
       ...
       ZwMemoryFree((void**)&values);
       ZwMemoryFree((void**)&vectors);
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix3Eigen(szwMatrix3 inputMatrix, double **values, szwVector **vectors);

    /**
    @ingroup ZwMatrix

    Initializes "inputMatrix" to the identity matrix.

    @param [out] inputMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix;
       ZwMatrixInit(&inputMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInit(szwMatrix *inputMatrix);

    /**
    @ingroup ZwMatrix

    Calculates the inverse of the matrix.

    @note
    If the matrix is not invertible, the entries of inverseMatrix are all 0.

    @param [in] inputMatrix transformation matrix
    @param [out] inverseMatrix inverted transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR

    @code
       szwMatrix inputMatrix{};
       ...
       szwMatrix inverseMatrix=...;
       ZwMatrixInvert(inputMatrix,&inverseMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInvert(szwMatrix inputMatrix, szwMatrix *inverseMatrix);

    /**
    @ingroup ZwMatrix

    Matrix multiply (resultMatrix = inputMatrix1 * inputMatrix2).

    @param [in] inputMatrix1 first transformation matrix
    @param [in] inputMatrix2 second transformation matrix
    @param [out] resultMatrix resulting matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwMatrix inputMatrix1=...;
       szwMatrix inputMatrix2=...;
       ...
       szwMatrix resultMatrix{};
       ZwMatrixCrossProduct(inputMatrix1,inputMatrix2,&resultMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixCrossProduct(szwMatrix inputMatrix1, szwMatrix inputMatrix2, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Composes a transformation matrix that defines a reference
    frame whose origin coincides with "Origin", whose Z axis
    points in the direction of "zAxis", with arbitrary X and
    Y axis.

    @param [in] origin origin
    @param [in] zAxis direction of Z axis
    @param [out] resultMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwPoint origin=...;
       szwVector zAxis=...;
       ...
       szwMatrix resultMatrix{};
       ZwMatrixGetByPointAndZAxis(origin,zAxis,&resultMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixGetByPointAndZAxis(szwPoint origin, szwVector zAxis, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Composes a transformation matrix that defines a reference
    frame whose origin coincides with "Origin", whose Z axis
    points in the direction of "zAxis", with arbitrary X and
    Y axis.

    @param [in] origin origin point
    @param [in] xAxis direction of x axis
    @param [in] yAxis direction of y axis
    @param [out] resultMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR

    @code
       szwPoint origin=...;
       szwVector xAxis=...;
       szwVector yAxis=...;
       ...
       szwMatrix resultMatrix{};
       ZwMatrixGetByPointAndXYAxis(origin,xAxis,yAxis,&resultMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixGetByPointAndXYAxis(szwPoint origin, szwVector xAxis, szwVector yAxis, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Gets the origin, x-direction, y-direction and z-direction of matrix.

    @param [in] inputMatrix matrix to query
    @param [out] origin origin point (NULL to ignore)
    @param [out] xAxis x direction (NULL to ignore)
    @param [out] yAxis y direction (NULL to ignore)
    @param [out] zAxis z direction (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR

    @code
       szwMatrix inputMatrix=...;
       ...
       szwPoint orign=...;
       szwVector xAxis{};
       szwVector yAxis{};
       szwVector zAxis{};
       ZwMatrixCoordinateSystemGet(inputMatrix,&orign,&xAxis,&yAxis,&zAxis);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixCoordinateSystemGet(szwMatrix inputMatrix, szwPoint *origin, szwVector *xAxis, szwVector *yAxis, szwVector *zAxis);

    /**
    @ingroup ZwMatrix

    Initializes a transformation matrix "matrix" to perform rotations
    by the specified angle about the specified axis.

    @param [in] angle rotation angle (deg)
    @param [in] axis axis of rotation
    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix matrix{};
       szwVector axis = ...;
       double angle = ...;
       ...
       ZwMatrixInitByRotation(angle, axis, &matrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInitByRotation(double angle, szwAxis axis, szwMatrix *matrix);

    /**
    @ingroup ZwMatrix

    Initializes "matrix" so that it will scale points by scaleX, scaleY, scaleZ
    relative to  the specified point.

    @param [in] refrencePoint reference point
    @param [in] scaleX scale factor of X 
    @param [in] scaleY scale factor of Y 
    @param [in] scaleZ scale factor of Z 
    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix matrix{};
       szwPoint refrencePoint=...;
       double scaleX = ...;
       double scaleY = ...;
       double scaleZ = ...;
       ...
       ZwMatrixInitByPoint(refrencePoint,scaleX,scaleY,scaleZ, matrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInitByPoint(szwPoint refrencePoint, double scaleX, double scaleY, double scaleZ, szwMatrix *matrix);

    /**
    @ingroup ZwMatrix

    Makes sure "identity" flag associated with "inputMatrix" is set correctly.

    @param [in,out] inputMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix=...;
       ...
       ZwMatrixIdentityFlagRefresh(&inputMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixIdentityFlagRefresh(szwMatrix *inputMatrix);

    /**
    @ingroup ZwMatrix

    Applies transformation matrix "tranformationMatrix" to "resultMatrix".

    @param [in] tranformationMatrix transformation matrix
    @param [in,out] resultMatrix coordinate frame (i.e. transform)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix tranformationMatrix=...;
       szwMatrix resultMatrix{};
       ...
       ZwMatrixTransform(tranformationMatrix,&resultMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixTransform(szwMatrix tranformationMatrix, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Initializes "matrix" so that it will translate points by distanceX, distanceY and distanceZ.

    @param [in] distanceX X distance
    @param [in] distanceY Y distance
    @param [in] distanceZ Z distance
    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix matrix{};
       double distanceX = ...;
       double distanceY = ...;
       double distanceZ = ...;
       ...
       ZwMatrixInitByTranslation(&distanceX,&distanceY,&distanceZ,&matrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInitByTranslation(double distanceX, double distanceY, double distanceZ, szwMatrix *matrix);

    /**
    @ingroup ZwMatrix

    Initializes "inputMatrix" to the specified standard view.

    @param [in] viewType standard view type
    @param [out] resultMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT

    @code
       ezwViewStandard viewType=...;
       ...
       szwMatrix inputMatrix{};
       ZwMatrixInitByView(viewType,&inputMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixInitByView(ezwViewStandard viewType, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Conversion Transform Matrix to Euler Angles.

    @note
    Two categories of rotation sequence:  
       1. Proper Euler Angle - when the first and third rotation are around the same axes.  
          ZW_EULER_XYX: X-axis, Y-axis, X-axis  
          ZW_EULER_XZX: X-axis, Z-axis, X-axis  
          ZW_EULER_YXY: Y-axis, X-axis, Y-axis  
          ZW_EULER_YZY: Y-axis, Z-axis, Y-axis  
          ZW_EULER_ZXZ: Z-axis, X-axis, Z-axis  
          ZW_EULER_ZYZ: Z-axis, Y-axis, Z-axis  
       2. Tait-Bryan or Roll-Pitch-Yaw Angles - when three rotations are around different axes.  
          ZW_EULER_RPY: X-axis (Roll), Y-axis (Pitch), Z-axis (Yaw)  
          ZW_EULER_RYP: X-axis (Roll), Z-axis (Yaw), Y-axis (Pitch)  
          ZW_EULER_PRY: Y-axis (Pitch), X-axis (Roll), Z-axis (Yaw)  
          ZW_EULER_PYR: Y-axis (Pitch), Z-axis (Yaw), X-axis (Roll)  
          ZW_EULER_YRP: Z-axis (Yaw), X-axis (Roll), Y-axis (Pitch)  
          ZW_EULER_YPR: Z-axis (Yaw), Y-axis (Pitch), X-axis (Roll)

    @param [in] sequenceType rotation sequence type, see description
    @param [in] inputMatrix transformation matrix
    @param [out] eulerData Euler angles and translate vector

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT

    @code
       ezwEulerAngleSequence sequenceType=...;
       szwMatrix inputMatrix=...;
       ...
       szwEulerMatrix eulerData{};
       ZwMatrixToEulerAngle(sequenceType,inputMatrix,&eulerData);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixToEulerAngle(ezwEulerAngleSequence sequenceType, szwMatrix inputMatrix, szwEulerMatrix *eulerData);

    /**
    @ingroup ZwMatrix

    Conversion from Euler Angles to Transform Matrix.

    @note
    Two categories of rotation sequence:  
       1. Proper Euler Angle - when the first and third rotation are around the same axes.  
          ZW_EULER_XYX: X-axis, Y-axis, X-axis  
          ZW_EULER_XZX: X-axis, Z-axis, X-axis  
          ZW_EULER_YXY: Y-axis, X-axis, Y-axis  
          ZW_EULER_YZY: Y-axis, Z-axis, Y-axis  
          ZW_EULER_ZXZ: Z-axis, X-axis, Z-axis  
          ZW_EULER_ZYZ: Z-axis, Y-axis, Z-axis  
       2. Tait-Bryan or Roll-Pitch-Yaw Angles - when three rotations are around different axes.  
          ZW_EULER_RPY: X-axis (Roll), Y-axis (Pitch), Z-axis (Yaw)  
          ZW_EULER_RYP: X-axis (Roll), Z-axis (Yaw), Y-axis (Pitch)  
          ZW_EULER_PRY: Y-axis (Pitch), X-axis (Roll), Z-axis (Yaw)  
          ZW_EULER_PYR: Y-axis (Pitch), Z-axis (Yaw), X-axis (Roll)  
          ZW_EULER_YRP: Z-axis (Yaw), X-axis (Roll), Y-axis (Pitch)  
          ZW_EULER_YPR: Z-axis (Yaw), Y-axis (Pitch), X-axis (Roll)

    @param [in] sequenceType rotation sequence type, see description
    @param [in] eulerData Euler angles and translate vector
    @param [out] resultMatrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
       ezwEulerAngleSequence sequenceType=...;
       szwEulerMatrix eulerData=...;
       ...
       szwMatrix resultMatrix{};
       ZwEulerAngleToMatrix(sequenceType,eulerData,&resultMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwEulerAngleToMatrix(ezwEulerAngleSequence sequenceType, szwEulerMatrix eulerData, szwMatrix *resultMatrix);

    /**
    @ingroup ZwMatrix

    Applies transformation matrix "inputMatrix" to "point".

    @param [out] inputMatrix transformation matrix
    @param [in,out] point point of operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix=...;
       ...
       szwPoint point{};
       ZwPointTransform(inputMatrix,&point);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwPointTransform(szwMatrix inputMatrix, szwPoint *point);

    /**
    @ingroup ZwMatrix

    Applies transformation matrix "inputMatrix" to "points".

    @param [in] inputMatrix transformation matrix
    @param [in] count number of points to transform 
    @param [in,out] points points of operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix=...;

       int count = ...;
       szwPoint point[] = { ... };
       ZwPointListTransform(inputMatrix,count,&point);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwPointListTransform(szwMatrix inputMatrix, int count, szwPoint *points);

    /**
    @ingroup ZwMatrix

    Calculates the determinant of the 2*2 matrix.

    @param [in] inputMatrix the matrix
    @param [out] matrixDeterminant determinant of the matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       double matrixDeterminant;
       // assume that there's a variable named inputMatrix(szwMatrix2)
       ZwMatrix2Determinant(inputMatrix, &matrixDeterminant);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix2Determinant(szwMatrix2 inputMatrix, double *matrixDeterminant);

    /**
    @ingroup ZwMatrix

    Calculates the determinant of the 3*3 matrix.

    @param [in] inputMatrix the matrix
    @param [out] matrixDeterminant determinant of the matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       double matrixDeterminant;
       // assume that there's a variable named inputMatrix(szwMatrix3)
       ZwMatrix3Determinant(inputMatrix, &matrixDeterminant);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix3Determinant(szwMatrix3 inputMatrix, double *matrixDeterminant);

    /**
    @ingroup ZwMatrix

    Gets the Transpose Matrix of a 2*2 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] transposeMat the transpose matrix of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwMatrix2 transposeMat;
       // assume that there's a variable named inputMatrix(szwMatrix2)
       ZwMatrix2Transpose(inputMatrix, &transposeMat);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix2Transpose(szwMatrix2 inputMatrix, szwMatrix2 *transposeMat);

    /**
    @ingroup ZwMatrix

    Gets the Transpose Matrix of a 3*3 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] transposeMat the transpose matrix of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwMatrix3 transposeMat;
       // assume that there's a variable named inputMatrix(szwMatrix3)
       ZwMatrix3Transpose(inputMatrix, &transposeMat);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix3Transpose(szwMatrix3 inputMatrix, szwMatrix3 *transposeMat);

    /**
    @ingroup ZwMatrix

    Gets the Transpose Matrix of a 4*4 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] transposeMat the transpose matrix of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwMatrix transposeMat = ...;
       ZwMatrixTranspose(inputMatrix, &transposeMat);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixTranspose(szwMatrix inputMatrix, szwMatrix *transposeMat);

    /**
    @ingroup ZwMatrix

    Gets the rotation matrix of a 4*4 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] rotationMat the rotation matrix of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       szwMatrix3 rotationMat{};
       szwMatrix inputMatrix = ...;
       ZwMatrixRotationGet(inputMatrix, &rotationMat);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixRotationGet(szwMatrix inputMatrix, szwMatrix3 *rotationMat);

    /**
    @ingroup ZwMatrix

    Gets the scale factor of a 4*4 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] scaleFactor the scale factor of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
        double scaleFactor = 0;
       // assume that there's a variable named inputMatrix(szwMatrix)
       ZwMatrixScaleGet(inputMatrix, &scaleFactor);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixScaleGet(szwMatrix inputMatrix, double *scaleFactor);

    /**
    @ingroup ZwMatrix

    Gets the translation vector of a 4*4 matrix.
    
    @param [in] inputMatrix the matrix
    @param [out] translationVector the translation vector of the inputMatrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
        szwVector translationVector{};
       // assume that there's a variable named inputMatrix(szwMatrix)
       ZwMatrixTranslationGet(inputMatrix, &translationVector);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixTranslationGet(szwMatrix inputMatrix, szwVector *translationVector);

    /**
    @ingroup ZwMatrix

    The three-dimensional matrix is converted to a four-dimensional matrix with scale 1
    and zero translation vector.

    @param [in] inputMatrix the 3*3 matrix
    @param [out] matrix4D the 4*4 matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
        szwMatrix matrix4D;
       // assume that there's a variable named inputMatrix(szwMatrix3)
       ZwMatrix3ToMatrix4(inputMatrix, &matrix4D);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrix3ToMatrix4(szwMatrix3 inputMatrix, szwMatrix *matrix4D);

    /**
    @ingroup ZwMatrix

    Sets the rotation matrix of a 4*4 matrix

    @param [in] rotationMat the rotation matrix matrix
    @param [out] setMatrix the 4*4 matrix after setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
       // assume that there's a variable named rotationMat(szwMatrix3) and a variable
       // named setMatrix(szwMatrix)
       ZwMatrixRotationSet(rotationMat, &setMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixRotationSet(szwMatrix3 rotationMat, szwMatrix *setMatrix);

    /**
    @ingroup ZwMatrix

    Sets the scale factor of a 4*4 matrix.

    @param [in] scaleFactor  the scale factor
    @param [in,out] setMatrix the 4*4 matrix after setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT

    @code
       // assume that there's a variable named scaleFactor(double) and a variable
       // named setMatrix(szwMatrix)
       ZwMatrixScaleSet(scaleFactor, &setMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixScaleSet(double scaleFactor, szwMatrix *setMatrix);

    /**
    @ingroup ZwMatrix

    Sets the translation vector of a 4*4 matrix.

    @param [in] translationVector  the translation vector
    @param [in,out] setMatrix the 4*4 matrix after setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT

    @code
       // assume that there's a variable named translationVector(szwVector) and a variable
       // named setMatrix(szwMatrix)
       ZwMatrixTranslationSet(translationVector, &setMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixTranslationSet(szwVector translationVector, szwMatrix *setMatrix);

    /**
    @ingroup ZwMatrix

    Normalized three direction vectors in the matrix.

    @param [in,out] setMatrix  input the 4*4 matrix and return it after normalization of direction vectors

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix setMatrix = ...;
       ZwMatrixNormalize(&setMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixNormalize(szwMatrix *setMatrix);

    /**
    @ingroup ZwMatrix

    Checks if the matrix is orthogonal.

    @param [in] matrix 4*4 matrix 
    @param [out] isOrthogonal 1 if input matrix is orthogonal, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwMatrixOrthogonalCheck(szwMatrix matrix, int *isOrthogonal);

    /**
    @ingroup ZwMatrix

    Gives a mirror plane S and a point on the mirror plane Q, this routine
    computes the matrix required to reflect points/vectors about this
    plane.  


    Let  
           S      = Mirror plane.  
           Q      = Point on mirror plane.  
           n      = unit normal to S.  
           M(n,Q) = Reflection matrix.  

       then,  

       M(n,Q) = | I-2(n XX n)  0 |(Transpose)  
                |  2(Q.n)n     1 |  

       where  
           I = Identity matrix.  
           u XX w = Tensor product of u(u1,u2,u3) and w(w1,w2,w3).  
                  = |v1w1 v1w2 v2w3|  
                    |v2w1 v2w2 v3w3|  
                    |v3w1 v3w2 v3w3|  

    @note
    If the input 'normalVector' is not an unit vector, this function will return ZW_API_INVALID_INPUT.

    @param [in] origin point on mirror plane
    @param [in] normalVector unit normal of the mirror plane
    @param [out] reflectionMatrix the reflection matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR

    @code
       szwMatrix reflectionMatrix;
       // assume that there's ,a variable named origin(szwPoint) and a variable named normalVector(szwVector)
       ZwMatrixReflectionMatrixCreate(origin, normalVector, &reflectionMatrix);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixReflectionMatrixCreate(szwPoint origin, szwVector normalVector, szwMatrix *reflectionMatrix);
    
    /**
    @ingroup ZwMatrix

    Checks whether the input 4x4 matrix is a full rank matrix.

    @param [in] inputMatrix the matrix
    @param [out] isFullRank 1 if input matrix is full rank, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT

    @code
       int isFullRank = -1;
       // assume that there's a variable named inputMatrix(szwMatrix)
       ZwMatrixFullRankCheck(inputMatrix, &matrixDeterminant);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwMatrixFullRankCheck(szwMatrix inputMatrix, int *isFullRank);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATRIX_H */
