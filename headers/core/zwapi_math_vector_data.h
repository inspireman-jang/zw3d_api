/**
@file zwapi_math_vector_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures
*/


#pragma once
#ifndef ZW_API_MATH_VECTOR_DATA_H
#define ZW_API_MATH_VECTOR_DATA_H
/*
@brief 4D vector
@ingroup zwapi_math_vector_data
*/
typedef struct szwVector4
{
    double x;
    double y;
    double z;
    double w; //weight
} szwVector4;

#endif ZW_API_MATH_VECTOR_DATA_H