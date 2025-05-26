/**
@file zwapi_ui_listwidget_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE MODULE FOR THE ZW3D Data Types and Structures of the List Widget 
*/

#pragma once
#ifndef ZWAPI_UI_LISTWIDGET_DATA_H
#define ZWAPI_UI_LISTWIDGET_DATA_H

#include "zwapi_util.h"

/**
@brief item information
@ingroup ZwUiListWidgetData
*/
typedef struct szwIconInformation
{
    int width;                       /**<@brief icon width*/
    int height;                      /**<@brief icon height*/
    szwColor *colorData;             /**<@brief icon RGB array(0~255)*/
    unsigned char *transparencyData; /**<@brief icon transparency array(0~255)*/
} szwIconInformation;

#endif
