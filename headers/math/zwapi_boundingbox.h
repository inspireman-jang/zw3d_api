/**
@file zwapi_boundingbox.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Bounding Box Common API
*/

#pragma once
#ifndef ZW_API_BOUNDINGBOX_H /* this ifndef surrounds entire header */
#define ZW_API_BOUNDINGBOX_H

#include "zwapi_math_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @ingroup ZwBoundingBox

    Apply the specified transform to the specified bounding box.

    @note
    If the bounding box has not been modified since initialized, do nothing.

    @param [in] inputMatrix transformation matrix
    @param [in,out] boundingBox bounding box to transformation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MATRIX_NONORTHOGONAL

    @code
       szwMatrix inputMatrix=...;
       ...
       szwBoundingBox boundingBox{};
       ZwBoundingBoxTransform(inputMatrix,&boundingBox);
    @endcode
    */
    ZW_API_C ezwErrors ZwBoundingBoxTransform(szwMatrix inputMatrix, szwBoundingBox *boundingBox);

   /*
   *********************************************************************
   **  END HEADER FILE
   *********************************************************************
   */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_BOUNDINGBOX_H */
