/**
@file zwapi_ui_ribbon.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Ribbon API
*/
/**
@defgroup zwapi_ui_ribbon Ribbon
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Ribbon API
*/

#pragma once
#ifndef ZW_API_RIBBON_H /* this ifndef surrounds entire header */
#define ZW_API_RIBBON_H

#include "zwapi_dll_define.h"
#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Ribbon */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_ribbon

    Enable or disable the ribbon.

    @param [in] enable 1: enable the ribbon. 0: disable the ribbon

    @warning
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxRibbonSetStatus(int enable);

    /**
    @ingroup zwapi_ui_ribbon

    Set the append string to display after the title area of the base GUI window.  
    pStr is NULL or a blank string to clear the append title string.  
    @param [in] pStr Set/clear the string to display after the window title

    */
    ZW_API_C void cvxSetTitleAppend(const char *pStr);

    //====================================================================================================================
    /** @name Ribbon Visible*/
    //====================================================================================================================

    /**
    @ingroup ZwUiRibbon

    Sets the specified ribbon page visible or not.

    @note
    You can find ribbon page name in zcui files in "Settings" folder.  
    ribbonPageName is the same with the QObject name of the ribbon page.  
    ZW_API_INVALID_INPUT will be output if the ribbonPageName does not exist in current environment.  

    @param [in] ribbonPageName the ribbon page name.
    @param [in] visibility 1 to set the ribbon page visible, else 0. 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwUiRibbonPageVisibleSet(const char *ribbonPageName, int visibility);

    /**
    @ingroup ZwUiRibbon

    Checks the specified ribbon page visible or not.
    
    @note
    You can find ribbon page name in zcui files in "Settings" folder.  
    ribbonPageName is the same with the QObject name of the ribbon page.  
    ZW_API_INVALID_INPUT will be output if the ribbonPageName does not exist in current environment.  

    @param [in] ribbonPageName the ribbon page name.
    @param [out] visibility 1 if the ribbon page is visible, else 0. 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwUiRibbonPageVisibleGet(const char *ribbonPageName, int *visibility);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_RIBBON_H */
