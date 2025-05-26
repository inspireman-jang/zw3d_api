/**
@file zwapi_ui_filedialog.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D UI FILE DIALOG API
*/

#pragma once
#ifndef ZW_API_FILEDIALOG_H /* this ifndef surrounds entire header */
#define ZW_API_FILEDIALOG_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name File dialog attribute */
    //====================================================================================================================

    /**
    @ingroup ZwUiFileDialog

    Hide the file dialog currently shown on ZW3D. User can click "Open" or "Save as" to popup file dialog in ZW3D.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwUiFileDialogHide();

    /**
    @ingroup ZwUiFileDialog

    Show the file dialog hiden by ZwUiFileDialogHide.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwUiFileDialogUnHide();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FILEDIALOG_H */
