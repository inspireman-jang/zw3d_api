/**
@file zwapi_table_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for table objects.
*/


#pragma once
#ifndef ZW_API_TABLE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_TABLE_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Table Data */
    //====================================================================================================================
    /**
    @brief table location origin
    @ingroup ZwTableData
    */
    typedef enum ezwTableOrigin
    {
        ZW_TABLE_ORIGIN_TOP_LEFT = 0,  /**<@brief  origin is located in the top-left of the table */
        ZW_TABLE_ORIGIN_TOP_CENTER,    /**<@brief  origin is located in the top-center of the table */
        ZW_TABLE_ORIGIN_TOP_RIGHT,     /**<@brief  origin is located in the top-right of the table */
        ZW_TABLE_ORIGIN_MID_LEFT,      /**<@brief  origin is located in the mid-left of the table */
        ZW_TABLE_ORIGIN_MID_CENTER,    /**<@brief  origin is located in the mid-center of the table */
        ZW_TABLE_ORIGIN_MID_RIGHT,     /**<@brief  origin is located in the mid-right of the table */
        ZW_TABLE_ORIGIN_BOTTOM_LEFT,   /**<@brief  origin is located in the bottom-left of the table */
        ZW_TABLE_ORIGIN_BOTTOM_CENTER, /**<@brief  origin is located in the bottom-center of the table */
        ZW_TABLE_ORIGIN_BOTTOM_RIGHT,  /**<@brief  origin is located in the bottom-right of the table */
    } ezwTableOrigin;

    /**
    @brief table insert data
    @ingroup ZwTableData
    */
    typedef struct szwTableInsertData
    {
        szwPoint insertPoint;  /**<@brief  insert point of the table */
        ezwTableOrigin origin; /**<@brief  the insert origin of the table */
        szwEntityHandle plane; /**<@brief  the alignment plane of 3D table (invalid handle to align the active view plane) */
        double rotateAngle;    /**<@brief  the rotation angle of 3D table */
        int attachToPoint;     /**<@brief  whether to attach to anchor point (1: on; 0: off) */
    } szwTableInsertData;

    /**
    @brief table cell data type
    @ingroup ZwTableData
    */
    typedef enum ezwTableCellDataType
    {
        ZW_TABLE_DATA_TYPE_NORMAL,  /**<@brief  normal data type */
        ZW_TABLE_DATA_TYPE_INT,     /**<@brief  integer data type */
        ZW_TABLE_DATA_TYPE_NUMBER,  /**<@brief  number data type */
        ZW_TABLE_DATA_TYPE_TEXT,    /**<@brief  text data type */
        ZW_TABLE_DATA_TYPE_PERCENT, /**<@brief  percent data type */
    } ezwTableCellDataType;

    /**
    @brief table text attribute data
    @ingroup ZwTableData
    */
    typedef struct szwTableTextAttribute
    {
        /* font */
        char font[37];            /**<@brief  text font name */
        char bigFont[37];         /**<@brief  text big font name */
        int bold;                 /**<@brief  bold text (1: bold; 0: normal) */
        int underLine;            /**<@brief  underline text (1: underline; 0: normal) */
        int overline;             /**<@brief  overline text (1: overline; 0: normal) */
        int strikethrough;        /**<@brief  strikethrough text (1: strikethrough; 0: normal) */
        ezwColor color;           /**<@brief  text color */
        ezwTextFontType fontType; /**<@brief  font type */

        /* alignments */
        ezwTextFitMethod fitMethod;             /**<@brief  fit method */
        ezwTextHorizontalAlign horizontalAlign; /**<@brief  text horizontal alignment */
        ezwTextVerticalAlign verticalAlign;     /**<@brief  text vertical alignment */

        /* number */
        ezwNumberPrecision precision; /**<@brief  number precision */
        ezwZeroSuppress zeroSuppress; /**<@brief  number zero suppression */

        /* text shape */
        float height;            /**<@brief  text height */
        float width;             /**<@brief  text width */
        float verticalSpacing;   /**<@brief  vertical spacing between text */
        float horizontalSpacing; /**<@brief  horizontal spacing between text */
        float slantAngle;        /**<@brief  slant angle of text */

        /* indentation */
        float firstLine; /**<@brief  first line indentation */
        float hanging;   /**<@brief  hanging indentation */
        float right;     /**<@brief  right indentation */
    } szwTableTextAttribute;

    /**
    @brief table cell attribute data
    @ingroup ZwTableData
    */
    typedef struct szwTableCellAttribute
    {
        double horizontalMargin;                  /**<@brief  horizontal margin */
        double verticalMargin;                    /**<@brief  vertical margin */
        ezwColor backgroundColor;                 /**<@brief  cell background color */
        szwLineDisplayAttribute borderDisplay[4]; /**<@brief  attribute list of the 4 border lines(order: top-bottom-left-right)
                                                  and the border line mode just support blank and normal */
    } szwTableCellAttribute;

    /**
    @brief table caption types
    @ingroup ZwTableData
    */
    typedef enum ezwTableCaption
    {
        ZW_TABLE_CAPTION_NONE = 0, /**<@brief  no caption is added */
        ZW_TABLE_CAPTION_ROW,      /**<@brief  caption column is added to the left of the table */
        ZW_TABLE_CAPTION_COLUMN,   /**<@brief  caption row is added to the top of the table */
        ZW_TABLE_CAPTION_BOTH,     /**<@brief  caption row and column are added */
    } ezwTableCaption;

    /**
    @brief table orientation
    @ingroup ZwTableData
    */
    typedef enum ezwTableOrient
    {
        ZW_TABLE_TOP_TO_BOTTOM = 0, /**<@brief  table orientation: form top to bottom */
        ZW_TABLE_BOTTOM_TO_TOP,     /**<@brief  table orientation: form bottom to top */
    } ezwTableOrient;

    /**
    @brief table line attribute update flag
    @ingroup ZwTableData
    */
    typedef enum ezwTableLineAttributeFlag
    {
        ZW_TABLE_BORDER_LINE_UPDATE     = 1, /**<@brief  update table border line attribute */
        ZW_TABLE_HORIZONTAL_LINE_UPDATE = 2, /**<@brief  update table horizontal line attribute */
        ZW_TABLE_VERTICAL_LINE_UPDATE   = 4, /**<@brief  update table vertical line attribute */
    } ezwTableLineAttributeFlag;

    /**
    @brief table attributes data
    @ingroup ZwTableData
    */
    typedef struct szwTableAttribute
    {
        double horizontalMargin; /**<@brief  the minimum horizontal spacing around each cell contents */
        double verticalMargin;   /**<@brief  the minimum vertical spacing above and below each cell contents */

        ezwTableCaption caption; /**<@brief  caption */
        ezwTableOrigin origin;   /**<@brief  the origin of the table */
        ezwTableOrient orient;   /**<@brief  the orientation of the table */

        int lineAttributeUpdateFlag;              /**<@brief  line attribute update flag, refers to ezwTableLineAttributeFlag  
                                                     set multiple attributes: ZW_TABLE_HORIZONTAL_LINE_UPDATE | ZW_TABLE_VERTICAL_LINE_UPDATE */
        szwLineAttribute borderLineAttribute;     /**<@brief  table border grid line attribute */
        szwLineAttribute horizontalLineAttribute; /**<@brief  table border horizontal line attribute */
        szwLineAttribute verticalLineAttribute;   /**<@brief  table border vertical line attribute */
    } szwTableAttribute;
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TABLE_DATA_H */
