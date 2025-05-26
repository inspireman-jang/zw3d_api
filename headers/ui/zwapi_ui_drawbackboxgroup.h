/**
@file zwapi_ui_drawbackboxgroup.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Form API
*/

#pragma once
#ifndef ZW_API_DRAWBACKBOXGROUP_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWBACKBOXGROUP_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Form Set */
    //====================================================================================================================
    /**
    @ingroup ZwUiDrawbackBoxGroup

    Fold or expand box in drawback box group.

    @param [in] form form name
    @param [in] fieldIndex field id
    @param [in] boxIndex index of box in drawback box group, started from 1
    @param [in] fold 1 to fold drawback box group, 0 to expand it.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwUiDrawbackBoxGroupFold(const char *form, int fieldIndex, int boxIndex, int fold);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWBACKBOXGROUP_H */
