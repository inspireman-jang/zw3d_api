/**
@file zwapi_layer_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of Layer functions.
*/
/**
@defgroup zwapi_layer_data Layer Data
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of Layer functions.
*/

#pragma once
#ifndef ZW_API_LAYER_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_LAYER_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Layer Info Data */
    //====================================================================================================================
    /**
    @brief layer mask information
    @ingroup zwapi_layer_data
    */
    typedef enum evxInfoLayerFlag
    {
        VX_LAYER_INFOR_NAME      = 0x00000001,  /**<@brief  find layer name */
        VX_LAYER_INFOR_DESC      = 0x00000002,  /**<@brief  find layer description */
        VX_LAYER_INFOR_ID        = 0x00000004,  /**<@brief  find layer id */
        VX_LAYER_INFOR_VISIBLE   = 0x00000008,  /**<@brief  find layer visible */
        VX_LAYER_INFOR_FREEZE    = 0x000000010, /**<@brief  find layer freeze */
        VX_LAYER_INFOR_DISABLE   = 0x00000020,  /**<@brief  find layer disable */
        VX_LAYER_INFOR_COLOR     = 0x00000040,  /**<@brief  find layer color */
        VX_LAYER_INFOR_LINETYPE  = 0x00000080,  /**<@brief  find layer linetype */
        VX_LAYER_INFOR_LINEWIDTH = 0x0000100,   /**<@brief  find layer linewidth */
        VX_LAYER_INFOR_NUMOBJ    = 0x0000200,   /**<@brief  find layer numble object */
        VX_LAYER_INFOR_FLTR      = 0x0000400,   /**<@brief  find layer filter info */
        VX_LAYER_INFOR_ALL       = 0xFFFFFFFF,  /**<@brief  find layer all info */
    } evxInfoLayerFlag;

    /**
    @brief layer information
    @ingroup zwapi_layer_data
    */
    typedef struct svxLayerInfo
    {
        int mask;                 /**<@brief  obtain specified information from mask (evxInfoLayerFlag).
                               obtain sName and sDesc infos if mask = VX_LAYER_INFOR_NAME|VX_LAYER_INFOR_DESC */
        char sName[32];           /**<@brief  layer name */
        char sDesc[512];          /**<@brief  layer description */
        unsigned char uLayerId;   /**<@brief  layer id */
        unsigned char uVisible;   /**<@brief  layer visible */
        unsigned char uFrozen;    /**<@brief  layer freeze */
        unsigned char uDisable;   /**<@brief  layer disable */
        unsigned char uColor;     /**<@brief  layer color */
        unsigned char uLineType;  /**<@brief  layer linetype */
        unsigned char ulineWidth; /**<@brief  layer linewidth */
        char category[512];       /**<@brief  category, like this CURVES;SHEETS */
        int iNumObj;              /**<@brief  layer number object */
    } svxLayerInfo;

    //====================================================================================================================
    /** @name Layer Category Data */
    //====================================================================================================================
    /**
    @brief layer category type
    @ingroup ZwLayerData 
    */
    typedef enum ezwLayerCategoryType
    {
        ZW_CATEGORY_SPCIFIED_NAME = 0, /**<@brief  sets the state of the category with the specified name */
        ZW_CATEGORY_NO_CATEGORY,       /**<@brief  sets the state of layers for which no category is set */
    } ezwLayerCategoryType;

    //====================================================================================================================
    /** @name Layer Rule Data */
    //====================================================================================================================

    /**
    @brief attribute option of layer rule
    @ingroup ZwLayerData
    */
    typedef enum ezwLayerRuleAttributeOption
    {
        ZW_LAYER_RULE_ATTRIBUTE_NAME = 1, /**<@brief  name */
        ZW_LAYER_RULE_ATTRIBUTE_TYPE,     /**<@brief  type */
        ZW_LAYER_RULE_ATTRIBUTE_COLOR,    /**<@brief  color */
    } ezwLayerRuleAttributeOption;

    /**
    @brief operator type of layer rule
    @ingroup ZwLayerData
    */
    typedef enum ezwLayerRuleOperator
    {
        ZW_LAYER_RULE_OPERATOR_NONE, /**<@brief  none */
        ZW_LAYER_RULE_OPERATOR_AND,  /**<@brief  operator and */
        ZW_LAYER_RULE_OPERATOR_OR,   /**<@brief  operator or */
    } ezwLayerRuleOperator;

    /**
    @brief entity type of layer rule
    @ingroup ZwLayerData 
    */
    typedef enum ezwLayerRuleEntityType
    {
        /* Part/Assembly*/
        ZW_LAYER_RULE_SOLID = 1,    /**<@brief  solid */
        ZW_LAYER_RULE_SURFACE,      /**<@brief  surface */
        ZW_LAYER_RULE_CURVE,        /**<@brief  curve */
        ZW_LAYER_RULE_PARTING_LINE, /**<@brief  parting line */
        ZW_LAYER_RULE_SKETCH,       /**<@brief  sketch */
        ZW_LAYER_RULE_CURVE_LIST,   /**<@brief  curve list */
        ZW_LAYER_RULE_POINT,        /**<@brief  point */
        ZW_LAYER_RULE_DATUM_PLANE,  /**<@brief  datum plane */
        ZW_LAYER_RULE_DATUM_AXIS,   /**<@brief  datum axis */
        ZW_LAYER_RULE_DATUM_CSYS,   /**<@brief  datum CSYS */
        ZW_LAYER_RULE_BLOCK,        /**<@brief  block */
        ZW_LAYER_RULE_CONPOINT,     /**<@brief  conpoint */
        ZW_LAYER_RULE_TEXT,         /**<@brief  text */
        ZW_LAYER_RULE_PMI,          /**<@brief  PMI */
        ZW_LAYER_RULE_COMPONENT,    /**<@brief  component */
        /* Drawing */
        ZW_LAYER_RULE_VIEW,      /**<@brief  view of drawing */
        ZW_LAYER_RULE_TABLE,     /**<@brief  table of drawing */
        ZW_LAYER_RULE_DIMENSION, /**<@brief  dimention of drawing */
        ZW_LAYER_RULE_GEOMETRY,  /**<@brief  geometry of drawing */
        ZW_LAYER_RULE_2D_GROUP,  /**<@brief  2D group of drawing */
        ZW_LAYER_RULE_HATCH,     /**<@brief  hatch of drawing */
        ZW_LAYER_RULE_2D_SKETCH, /**<@brief  skecth of drawing */
        ZW_LAYER_RULE_2D_TEXT,   /**<@brief  text of drawing */
        ZW_LAYER_RULE_SYMBOL,    /**<@brief  symbol of drawing */
    } ezwLayerRuleEntityType;

    /**
    @brief layer rule data
    @ingroup ZwLayerData 
    */
    typedef struct szwLayerRuleData
    {
        ezwLayerRuleAttributeOption attributeOption; /**<@brief  attribute option */
        union
        {
            zwString256 entityName;            /**<@brief  entity name, it used when attributeOption is ZW_LAYER_RULE_ATTRIBUTE_NAME */
            ezwLayerRuleEntityType entityType; /**<@brief  entity type, it used when attributeOption is ZW_LAYER_RULE_ATTRIBUTE_TYPE */
            ezwColor entityColor;              /**<@brief  entity color, it used when attributeOption is ZW_LAYER_RULE_ATTRIBUTE_COLOR */
        } condition;
        ezwLayerRuleOperator ruleOperator; /**<@brief  operator that for the rules with same attribute option */
    } szwLayerRuleData;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !ZW_API_LAYER_DATA_H */
