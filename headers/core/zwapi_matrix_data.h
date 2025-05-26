/**
@file zwapi_matrix_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures
*/

#pragma once
#ifndef ZW_API_MATRIX_DATA_H
#define ZW_API_MATRIX_DATA_H

/**
@brief 3D transformation matrix or coordinate frame (local to world)  
please see ZwEntityTransformMatrixGet() to learn about the meaning of parameters.
@ingroup ZwMatrixData
*/
typedef struct szwMatrix
{
    char identity;

    double xx, yx, zx, xt;
    double xy, yy, zy, yt;
    double xz, yz, zz, zt;

    double ox, oy, oz, scale;
} szwMatrix;

/**
@brief 3*3 matrix for mathematical calculation
@ingroup ZwMatrixData
*/
typedef struct szwMatrix3
{
    double xx, yx, zx;
    double xy, yy, zy;
    double xz, yz, zz;
} szwMatrix3;

/**
@brief 2*2 matrix for mathematical calculation
@ingroup ZwMatrixData
*/
typedef struct szwMatrix2
{
    double xx, yx;
    double xy, yy;
} szwMatrix2;

#endif ZW_API_MATRIX_DATA_H