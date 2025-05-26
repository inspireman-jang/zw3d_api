/**
@file zwapi_drawing_table_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for Drawing Table objects.
*/

#pragma once
#ifndef ZW_API_DRAWING_TABLE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_TABLE_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Table Data */
    //====================================================================================================================
    /**
    @brief drawing BOM level setting
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMLevelSetting
    {
        ZW_BOM_TOP_LEVEL_ONLY  = 0, /**<@brief  list parts and sub-assemblies, but not subassembly components */
        ZW_BOM_PARTS_ONLY      = 1, /**<@brief  list sub-assembly components, but not sub-assemblies */
        ZW_BOM_INDENTED        = 3, /**<@brief  list sub-assemblies and indents sub-assembly components below sub-assemblies */
        ZW_BOM_BY_BALLOON_ONLY = 4, /**<@brief  list only the parts and sub-assemblies marked by balloon */
    } ezwDrawingBOMLevelSetting;

    /**
    @brief drawing BOM sub-assembly components indent type
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMIndentedType
    {
        ZW_BOM_INDENTED_NO_NUMBERING,       /**<@brief  no numbering */
        ZW_BOM_INDENTED_DETAILED_NUMBERING, /**<@brief  detailed numbering */
        ZW_BOM_INDENTED_FLAT_NUMBERING,     /**<@brief  flat numbering */
    } ezwDrawingBOMIndentedType;

    /**
    @brief drawing BOM order type
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMOrderType
    {
        ZW_BOM_ORDER_BY_NAME              = 0, /**<@brief  sort the BOM based on the part name */
        ZW_BOM_REGENERATE_IDS_AFTER_SORT  = 1, /**<@brief  regenerate the BOM labels based on the sort order */
        ZW_BOM_ORDER_AS_ASSEMBLY          = 2, /**<@brief  sort the BOM based on the components insertion order */
        ZW_BOM_AUTO_UPDATE_IDS_AFTER_SORT = 4, /**<@brief  auto update IDs after sort */
    } ezwDrawingBOMOrderType;

    /**
    @brief drawing BOM attribute type
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMAttributeType
    {
        ZW_BOM_STANDARD_ATTRIBUTE, /**<@brief  standard attribute */
        ZW_BOM_PHYSICAL_ATTRIBUTE, /**<@brief  physical attribute */
        ZW_BOM_FILE_ATTRIBUTE,     /**<@brief  file information */
        ZW_BOM_ECAD_ATTRIBUTE,     /**<@brief  ECAD attribute */
        ZW_BOM_USER_ATTRIBUTE,     /**<@brief  user attribute */
    } ezwDrawingBOMAttributeType;

    /**
    @brief drawing BOM attribute ID
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMAttributeID
    {
        /* ezwDrawingBOMAttributeType::ZW_BOM_USER_ATTRIBUTE */
        ZW_BOM_ATTRIBUTE_USER = -1, /**<@brief  user attribute */

        /* ezwDrawingBOMAttributeType::ZW_BOM_STANDARD_ATTRIBUTE */
        ZW_BOM_ATTRIBUTE_ID = 0,       /**<@brief  id */
        ZW_BOM_ATTRIBUTE_NUMBER,       /**<@brief  number, merge support */
        ZW_BOM_ATTRIBUTE_CLASS,        /**<@brief  class, merge support */
        ZW_BOM_ATTRIBUTE_DESIGNER,     /**<@brief  designer, merge support */
        ZW_BOM_ATTRIBUTE_COST,         /**<@brief  cost, merge support */
        ZW_BOM_ATTRIBUTE_SUPPLIER,     /**<@brief  supplier, merge support */
        ZW_BOM_ATTRIBUTE_QUANTITY,     /**<@brief  quantity */
        ZW_BOM_ATTRIBUTE_MANAGER,      /**<@brief  manager, merge support */
        ZW_BOM_ATTRIBUTE_REMARKS,      /**<@brief  remarks */
        ZW_BOM_ATTRIBUTE_DESCRIPTION,  /**<@brief  description, merge support */
        ZW_BOM_ATTRIBUTE_KEYWORDS,     /**<@brief  keywords, merge support */
        ZW_BOM_ATTRIBUTE_DERIVED_FROM, /**<@brief  derived from, merge support */
        ZW_BOM_ATTRIBUTE_PART_CONFIG,  /**<@brief  part config */
        ZW_BOM_ATTRIBUTE_LEGEND,       /**<@brief  legend */
        ZW_BOM_ATTRIBUTE_VISIBLE,      /**<@brief  visible */
        ZW_BOM_ATTRIBUTE_SHEET_CODE,   /**<@brief  sheet code */

        /* ezwDrawingBOMAttributeType::ZW_BOM_PHYSICAL_ATTRIBUTE */
        ZW_BOM_ATTRIBUTE_MATERIAL = 101, /**<@brief  material */
        ZW_BOM_ATTRIBUTE_MASS,           /**<@brief  mass */
        ZW_BOM_ATTRIBUTE_VOLUME,         /**<@brief  volume */
        ZW_BOM_ATTRIBUTE_TOTAL_MASS,     /**<@brief  total mass */
        ZW_BOM_ATTRIBUTE_DENSITY,        /**<@brief  density */
        ZW_BOM_ATTRIBUTE_SIZE,           /**<@brief  size */
        ZW_BOM_ATTRIBUTE_LENGTH,         /**<@brief  length */
        ZW_BOM_ATTRIBUTE_WIDTH,          /**<@brief  width */
        ZW_BOM_ATTRIBUTE_HEIGHT,         /**<@brief  height */
        ZW_BOM_ATTRIBUTE_AREA,           /**<@brief  area */
        ZW_BOM_ATTRIBUTE_STOCKSIZE,      /**<@brief  stock size */

        /* ezwDrawingBOMAttributeType::ZW_BOM_FILE_ATTRIBUTE */
        ZW_BOM_ATTRIBUTE_NAME = 201,       /**<@brief  name */
        ZW_BOM_ATTRIBUTE_START_DATE,       /**<@brief  start date */
        ZW_BOM_ATTRIBUTE_END_DATE,         /**<@brief  end date */
        ZW_BOM_ATTRIBUTE_SOURCE_FILE_PATH, /**<@brief  source file path */
        ZW_BOM_ATTRIBUTE_NAME_TAG,         /**<@brief  name tag */

        /* ezwDrawingBOMAttributeType::ZW_BOM_ECAD_ATTRIBUTE */
        ZW_BOM_ATTRIBUTE_ECAD_REF_DES = 301, /**<@brief  ECAD RefDes */
        ZW_BOM_ATTRIBUTE_ECAD_BOARD_SIDE,    /**<@brief  ECAD board side */
    } ezwDrawingBOMAttributeID;

    /**
    @brief drawing BOM column attribute data
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingBOMAttribute
    {
        ezwDrawingBOMAttributeType attributeType; /**<@brief  attribute type */
        ezwDrawingBOMAttributeID attributeID;     /**<@brief  attribute ID */
        zwString64 attributeName;                 /**<@brief  attribute item name, used when attributeID = ZW_BOM_ATTRIBUTE_USER */
    } szwDrawingBOMAttribute;

    /**
    @brief drawing BOM filter operator
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingBOMFilterOperator
    {
        ZW_BOM_FILTER_OPERATOR_EQUAL,        /**<@brief  filter operator: = */
        ZW_BOM_FILTER_OPERATOR_NOT_EQUAL,    /**<@brief  filter operator: != */
        ZW_BOM_FILTER_OPERATOR_GREATER_THAN, /**<@brief  filter operator: > */
        ZW_BOM_FILTER_OPERATOR_LESS_THAN,    /**<@brief  filter operator: < */
    } ezwDrawingBOMFilterOperator;

    /**
    @brief drawing BOM filter item
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingBOMFilterItem
    {
        szwDrawingBOMAttribute attribute;           /**<@brief  attribute */
        ezwDrawingBOMFilterOperator filterOperator; /**<@brief  operator */
        zwString128 conditionValue;                 /**<@brief  condition value */
    } szwDrawingBOMFilterItem;

    /**
    @brief drawing BOM data
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingBOMData
    {
        szwEntityHandle viewHandle; /**<@brief  view handle to associate with the BOM */
        zwString32 BOMName;         /**<@brief  BOM name, input an empty string to use the default name */

        /* Level Setting */
        ezwDrawingBOMLevelSetting levelSetting; /**<@brief  level setting */
        ezwDrawingBOMIndentedType indentedType; /**<@brief  indented type of sub-assembly, used when levelSetting is ZW_BOM_INDENTED */
        int fromHierarchyDepth;                 /**<@brief  specify which assembly level should start to list BOM, starting at 1, 0 to traverse from the top level of assembly,  
                                                            used when levelSetting is ZW_BOM_PARTS_ONLY or ZW_BOM_INDENTED */
        int maxTraverseDepth;                   /**<@brief  specify which assembly level should read out up to, starting at 1, 0 to traverse to the maximum depth,  
                                                            used when levelSetting is ZW_BOM_PARTS_ONLY or ZW_BOM_INDENTED */

        /* Setting */
        int eachComponentAsOneItem;           /**<@brief  whether to display each component as one item (1: yes; 0: no) */
        int configurationOfSamePartAsOneItem; /**<@brief  whether to display configuration of the same part as one item (1: yes; 0: no) */
        int derivedPartsAsInstances;          /**<@brief  whether to derived parts as instances of source part (1: yes; 0: no) */
        int syncBOMWithPartAttribute;         /**<@brief  whether to sync BOM table with part attributes (1: yes; 0: no) */
        int keepMissingItem;                  /**<@brief  whether to keep missing item (1: yes; 0: no) */
        int strikethrough;                    /**<@brief  whether to strikethrough (1: yes; 0: no) */

        /* Item Numbers */
        int startingID;               /**<@brief  starting ID, staring at 1 */
        ezwDrawingBOMOrderType order; /**<@brief  BOM order type */

        /* Table Format */
        zwPath BOMTemplate; /**<@brief  the full path of BOM template file, input an empty string to ignore */
        int inherit3DBOM;   /**<@brief  whether to inherit 3D BOM (1: yes; 0: no) */

        int nColumns;                             /**<@brief  number of BOM columns */
        szwDrawingBOMAttribute *columnAttributes; /**<@brief  list of BOM columns attribute */
        szwDrawingBOMAttribute *sortAttribute;    /**<@brief  column attribute to sort BOM, NULL to use the first column attribute */
        int sortOrderMode;                        /**<@brief  sort BOM in either ascending (0) or descending (1) order */
        int sortWhenRegenerating;                 /**<@brief  whether to resort when regenerating (1: yes; 0: no) */
        szwDrawingBOMAttribute *mergeAttribute;   /**<@brief  column attribute to merge BOM, NULL to ignore, only some standard attribute support merging, for details, see the description of ezwDrawingBOMAttributeID */

        /* Filter */
        int nBOMFilterItems;                     /**<@brief  number of BOM filter items, 0 to ignore */
        szwDrawingBOMFilterItem *BOMFilterItems; /**<@brief  list of BOM filter items, NULL to ignore */

        int includeUnplacedComponent;          /**<@brief  whether to include unplaced component (1: yes; 0: no) */
        int showShape;                         /**<@brief  whether to show shape (1: yes; 0: no) */
        int nExcludeComponents;                /**<@brief  number of excluded components or shapes, 0 to ignore */
        szwEntityHandle *excludeComponentList; /**<@brief  list of excluded component or shape handles, NULL to ignore */
    } szwDrawingBOMData;

    //====================================================================================================================
    /** @name Annotation Table Data */
    //====================================================================================================================
    
    /**
    @brief table type (match with VeCdTableType)
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableType
    {
        ZW_TABLE_POINT     = 0, /**<@brief  by point */
        ZW_TABLE_DIMENSION = 1, /**<@brief  by dimension */
    } ezwDrawingTableType;

    /**
    @brief annotation table flag
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableAnnotationStartMethod
    {
        ZW_TABLE_SATRTBY_ID    = 0, /**<@brief  start id */
        ZW_TABLE_SATRTBY_LABEL = 1, /**<@brief  start label */
    } ezwDrawingTableAnnotationStartMethod;

    /**
    @brief annotation id set flag
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableAnnotationIdSet
    {
        ZW_TABLE_NONE           = 0, /**<@brief  neither regenerate nor not last max*/
        ZW_TABLE_REGENERATE_IDS = 1, /**<@brief  check the option "regenerate IDs after sort", and then "last max" can not be checked */
        ZW_TABLE_LAST_MAX       = 2, /**<@brief  check last max, only used when by dimensions and not regenerate*/
    } ezwDrawingTableAnnotationIdSet;

    /**
    @brief annotation table flag
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableAnnotationKeep
    {
        ZW_TABLE_NO_KEEP       = 0, /**<@brief  not keep the missing item or not show original indicator*/
        ZW_TABLE_KEEP_MISSING  = 1, /**<@brief  keep the missing item when by dimension, show original indicator when by point*/
        ZW_TABLE_STRIKETHROUGH = 2, /**<@brief  keep the missing item and strike-through, used only when by dimension*/
    } ezwDrawingTableAnnotationKeep;

    /**
    @brief label pattern type
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableLabelPatternType
    {
        ZW_LABEL_CONVEX_HULL = 0, /**<@brief  convex hull type*/
        ZW_LABEL_SQUIRE      = 1, /**<@brief  squire type*/
        ZW_LABEL_CIRCULAR    = 2, /**<@brief  circular type*/
    } ezwDrawingTableLabelPatternType;

    /**
    @brief label order
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableLabelOrder
    {
        ZW_LABEL_ANTI_CLOCKWISE = 0, /**<@brief  anti-clockwise*/
        ZW_LABEL_CLOCKWISE      = 1, /**<@brief  clockwise*/
        ZW_LABEL_LIST_ORDER     = 2, /**<@brief  list order*/
    } ezwDrawingTableLabelOrder;

    /**
    @brief label position
    @ingroup ZwDrawingTableData
    */
    typedef enum ezwDrawingTableLabelPosition
    {
        ZW_LABEL_AUTO    = 0, /**<@brief  auto*/
        ZW_LABEL_TOP     = 1, /**<@brief  top*/
        ZW_LABEL_LEFT    = 2, /**<@brief  left*/
        ZW_LABEL_RIGHT   = 3, /**<@brief  right*/
        ZW_LABEL_BOITTOM = 4, /**<@brief  bottom*/
    } ezwDrawingTableLabelPosition;

    /**
    @brief label of Table Format
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingTableLabel
    {
        int createLabel; /**<@brief  whether to create label (1(default): yes; 0: no) */

        //only when createLabel==1 the follows are needed
        int ballon;                              /**<@brief  ballon or note (1(default): ballon; 0: note) */
        int suppressLeader;                      /**<@brief  whether to suppress the leader (1(default): yes; 0: no) */
        ezwDrawingTableLabelOrder order;         /**<@brief  the order director, only used when by dimension */
        ezwDrawingTableLabelPosition position;   /**<@brief  label position when by dimensions, skip sides when by points */
        ezwDrawingTableLabelPatternType pattern; /**<@brief  pattern type, used when by point */
        int offset;                              /**<@brief  label offset, used when by points */

        int contents; /**<@brief  the order of the available as the contents in the list, choose from 0(default) to seletedCount-1 */
    } szwDrawingTableLabel;

    /**
    @brief Table Format 
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingTableFormat
    {
        /* column */
        int selectedCount;          /**<@brief  number of selected columns */
        zwString64 *selectedList;   /**<@brief  selected items name list */
        int sortBy;                 /**<@brief  the order of the item as the basic of classification in the list, from 1(default) to seletedCount */
        int sortOrderMode;          /**<@brief  sort table in either ascending (0) or descending (1) order */
        int sortWhenRegenerating;   /**<@brief  whether to resort when regenerating (1(default): yes; 0: no) */
        szwDrawingTableLabel label; /**<@brief  label */
    } szwDrawingTableFormat;
    
    /**
    @brief annotation table data
    @ingroup ZwDrawingTableData
    */
    typedef struct szwDrawingTableAnnotation
    {
        zwString32 name;             /**<@brief  annotation table name */
        ezwDrawingTableType type;    /**<@brief  annotation table type */
        int entityCount;             /**<@brief  number of points or dimension */
        szwEntityHandle *entityList; /**<@brief  entity handle list(dimension or point ) */
        szwPoint basePoint;          /**<@brief  base point, only used when type == ZW_TABLE_POINT*/
        /*item numbers*/
        ezwDrawingTableAnnotationStartMethod startBy; /**<@brief  start method */
        int startId;                                  /**<@brief  start id, from 1(default) to 100000000 */
        zwString16 startLabel;                        /**<@brief  start label, the default is "A" */
        ezwDrawingTableAnnotationIdSet idSet;         /**<@brief  flag of regenerate, when type == ZW_TABLE_DIMENSION the default is ZW_TABLE_LAST_MAX, otherwise, the default is ZW_TABLE_NONE */
        ezwDrawingTableAnnotationKeep keep;           /**<@brief  state of whether choose the keep the missing item or show original indicator and strike-through.
                                                          when type == ZW_TABLE_DIMENSION the default is ZW_TABLE_NO_KEEP, otherwise, the default is ZW_TABLE_KEEP_MISSING*/
        szwDrawingTableFormat tableFormat;            /**<@brief  table format*/
    } szwDrawingTableAnnotation;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_DRAWING_TABLE_DATA_H */
