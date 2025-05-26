/**
@file zwapi_ui_listwidget.h
(C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D List Widget API
*/

/**
@defgroup zwapi_ui_listwidget List Widget
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D List Widget API
*/

#pragma once
#ifndef ZW_API_LIST_WIDGET_H /* this ifndef surrounds entire header */
#define ZW_API_LIST_WIDGET_H

#include "zwapi_ui_listwidget_data.h"
#include "zwapi_ui_data.h"
#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name List  Widget */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_listwidget

    Get callback parameters for the list widget when the callback function being invoked,  
    the interface should be used in the callback function.

    @note
    To use the function, you should add a property of type string-list with the property  
    name "eventsEnabled" and add the property value "dbl_clk" to the list widget control  
    in UI file.

    @param [in] form form name
    @param [in] idField field id
    @param [out] param param

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    ZW_API_C evxErrors cvxListCallbackParamGet(const char *form, int idField, svxListCallBackParam *param);

    /**
    @ingroup zwapi_ui_listwidget

    Set the tooltip for specified row item of listWdiget.

    @param [in] form form name
    @param [in] field field id
    @param [in] row item row
    @param [in] toolTip tooltip

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxListItemToolTipSet(const char *form, int field, int row, const char *toolTip);

    /**
    @ingroup zwapi_ui_listwidget

    Get the tooltip of specified row item for listWdiget.

    @param [in] form form name
    @param [in] field field id
    @param [in] row item row
    @param [out] toolTip tooltip
    @param [in] size max size of tooltip

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxListItemToolTipGet(const char *form, int field, int row, char *toolTip, int size);

    //====================================================================================================================
    /** @name List Widget */
    //====================================================================================================================
    /**
    @ingroup ZwUiListWidget
    
    Set a image for a listwidget item.
    
    @param [in] form form name
    @param [in] field field id
    @param [in] row item row
    @param [in] data image (Format_ARGB32)(transparency:0~255)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int width=...;
    int height=...;
    szwIconInformation info={0};
    szwColor colorList[width*height];//or memory alloc by new,but remember to delete
    unsigned char transparency[width*height];//or memory alloc by new,but remember to delete

    //colorList[y*width+x]save the color of(x,y)pixel
    //transparency[y*width+x]save the transparency of(x,y)pixel

    info.transparencyData=transparency;
    info.colorData=colorList;
    info.height=height;
    info.width=width;
    ...
    //fill the colorList and transparency
    ZwUiListWidgetIconSet(formName, fieldId, row, info);
    @endcode
    */
    ZW_API_C ezwErrors ZwUiListWidgetIconSet(const char *form, int field, int row, szwIconInformation data);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LIST_WIDGET_H */
