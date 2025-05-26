/**
@file zwapi_3dbom_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the component
objects.
*/

#pragma once

#ifndef ZW_API_3DBOM_DATA_H
#define ZW_API_3DBOM_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief 3d BOM row data
    @ingroup Zw3DBOMData
    */
    typedef struct szw3DBomData
    {
        int rowCount;                  /**<@brief the total number of row in the table. */
        int columnCount;               /**<@brief the total number of column in the table. */
        zwString64 *attributeNameList; /**<@brief The name of the column attribute. */
        zwString256 **table;           /**<@brief table data. */
        zwString256 *totalList;        /**<@brief the total value of every column, if the column can not calculate, corresponding position will be filled with 0. */
    } szw3DBomData;

    /**
    @brief level display settings.
    @note In the part environment, 3D BOM supports only managing shape attributes.
    @ingroup Zw3DBOMData
    */
    typedef enum ezw3DBomLevelDispMode
    {
        ZW_3DBOM_TOP_LEVEL_ONLY = 1, /**<@brief Select this item to display only the top-level components. */
        ZW_3DBOM_PARTS_ONLY     = 2, /**<@brief Select this item to display only parts. */
        ZW_3DBOM_INDENTED       = 3, /**<@brief Select this item and indent it by assembly level. */
        ZW_3DBOM_SHAPE_ONLY     = 4, /**<@brief Select this item to display only the shapes. */
        ZW_3DBOM_ALLCOMPONENTS  = 5, /**<@brief Select this item to display all components that belong to the same level. */
    } ezw3DBomLevelDispMode;

    /**
    @brief 3D BOM display settings data
    @ingroup Zw3DBOMData
    */
    typedef struct szw3DBomSettingsData
    {
        ezw3DBomLevelDispMode mode; /**<@brief display mode */
        int countColumn;            /**<@brief number of columns display */
        struct szwBomColumn
        {
            zwString64 attributeName; /**<@brief The name of the column attribute that will be displayed in the 3d bom table. */
            zwString64 columnName;    /**<@brief user defined column name*/
            int isCheck;              /**<@brief 1 if set the specified property name to display, else 0 */
            int isTotal;              /**<@brief isTotal indicates whether to select to display totals(1 or 0).default:0.
                             Totals are usually displayed only if the content is numeric. */

        } *listColumnData;

    } szw3DBomSettingsData;

    /**
    @brief 3D BOM format settings data
    @ingroup Zw3DBOMData
    */
    typedef struct szw3DBomFormatData
    {
        int includeUnplacedComponents; /**<@brief whether to include unplaced component items (1-yes, 0-no), default: 0 */
        int includeShapeItems;         /**<@brief whether to include shape items (1-yes, 0-no), default: 0 */
        int displayAsOneItem;          /**<@brief whether to display configurations of the same part as one item (1-yes, 0-no), default: 0 */
        int showNotInBomItems;         /**<@brief whether to show "do not list in BOM" items (1-yes, 0-no), default: 0 */
        int includeVirtualComponents;  /**<@brief whether to include virtual component items (1-yes, 0-no), default: 1 */
    } szw3DBomFormatData;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_3DBOM_DATA_H*/
