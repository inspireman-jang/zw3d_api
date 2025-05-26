/**
@file zwapi_variable_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the variable
functions.
*/

#pragma once
#ifndef ZW_API_VARIABLE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_VARIABLE_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief variable types
    @ingroup ZwVariableData
    */
    typedef enum ezwVariableType
    {
        ZW_VARIABLE_NUMBER = 0, /**<@brief  number */
        ZW_VARIABLE_STRING = 1, /**<@brief  string */
        ZW_VARIABLE_POINT  = 2, /**<@brief  point */
        ZW_VARIABLE_VECTOR = 3  /**<@brief  vector */
    } ezwVariableType;

    /**
    @brief sub types of numeric variable
    @ingroup zwapi_variable_data
    */
    typedef enum ezwVariableNumberType
    {
        ZW_VARIABLE_CONSTANT    = 0, /**<@brief  constant number (without unit) */
        ZW_VARIABLE_DISTANCE    = 1, /**<@brief  distance */
        ZW_VARIABLE_ANGLE       = 2, /**<@brief  angle */
        ZW_VARIABLE_MASS        = 3, /**<@brief  mass */
        ZW_VARIABLE_DENSITY     = 4, /**<@brief  density */
        ZW_VARIABLE_AREA        = 5, /**<@brief  area */
        ZW_VARIABLE_VOLUME      = 6, /**<@brief  volume */
        ZW_VARIABLE_MASS_MOMENT = 7  /**<@brief  mass moment */
    } ezwVariableNumberType;

    /**
    @brief variable data
    @ingroup zwapi_variable_data
    */
    typedef struct szwVariableData
    {
        zwString32 name;      /**<@brief  variable name */
        ezwVariableType type; /**<@brief  variable type */

        union VariableValue
        {
            struct NumberValue
            {
                ezwVariableNumberType subType; /**<@brief  sub type of number variable */
                double number;                 /**<@brief  the value of number variable */
                char unitType;                 /**<@brief  unit type for value (ezwDistanceUnitType, ezwAngleUnitType...) */
            } numberValue;                     /**<@brief  number variable data*/
            zwString1024 stringValue;          /**<@brief  string variable data*/
            szwVector vectorValue;             /**<@brief  vector variable data*/
            struct PointValue
            {
                szwPoint point;  /**<@brief  the value of point variable */
                char unitType;   /**<@brief  unit type for value (ezwDistanceUnitType, ezwAngleUnitType...)*/
            } pointValue;        /**<@brief  point variable data*/
        } value;                 /**<@brief  variable value data for different type */
        zwString1024 expression; /**<@brief  optional expression (expression[0]=0 if undefined) */
        zwString512 description; /**<@brief  optional description (description[0]=0 if undefined) */
    } szwVariableData;

    //====================================================================================================================
    /** @name Standard Attribute Variable in Variable Browser */
    //====================================================================================================================
    /**
    @brief item of standard attribute variable in variable browser
    @ingroup zwapi_variable_data
    */
    typedef enum ezwVariableStandardAttributeItem
    {
        /*In drawing file, all items are supported 
          In part file, ZW_VARIABLE_PART_NAME~ZW_VARIABLE_PART_SHEET_METAL_WIDTH are supported.
          In sketch file, only ZW_VARIABLE_PROP_NAME ~ZW_VARIABLE_PROP_DESCRIPTION are supported.*/

        /*sheet attribute item.*/
        ZW_VARIABLE_SHEET_SCALE = 0,  /**<@brief  sheet scale */
        ZW_VARIABLE_SHEET_SEQUENCE,   /**<@brief  sheet sequence */
        ZW_VARIABLE_SHEET_AMOUNT,     /**<@brief  sheet amount */
        ZW_VARIABLE_SHEET_SIZE,       /**<@brief  sheet size */
        ZW_VARIABLE_SHEET_PROJECTION, /**<@brief  sheet projection */
        ZW_VARIABLE_SHEET_FILEPATH,   /**<@brief  sheet filepath */
        ZW_VARIABLE_SHEET_FILENAME,   /**<@brief  sheet file name */
        ZW_VARIABLE_SHEET_SHEETNAME,  /**<@brief  sheet sheet name */
        ZW_VARIABLE_SHEET_START_DATE, /**<@brief  sheet start date */
        ZW_VARIABLE_SHEET_END_DATE,   /**<@brief  sheet end date */
        ZW_VARIABLE_SHEET_TABLE_NAME, /**<@brief  sheet table name */

        /*part properties*/
        ZW_VARIABLE_PART_AREA,   /**<@brief  part area */
        ZW_VARIABLE_PART_VOLUME, /**<@brief  part volume */
        ZW_VARIABLE_PART_MASS,   /**<@brief  part mass property */
        ZW_VARAIBLE_PART_SIZE,   /**<@brief  part size property */
        ZW_VARIABLE_STOCK_SIZE,  /**<@brief  part stock size */
        ZW_VARIABLE_PART_LENGTH, /**<@brief  part length */
        ZW_VARIABLE_PART_WIDTH,  /**<@brief  part width */
        ZW_VARIABLE_PART_HEIGHT, /**<@brief  part height */
        ZW_VARIABLE_PART_CONFIG, /**<@brief  part config */

        ZW_VARIABLE_PART_NAME,        /**<@brief  part name */
        ZW_VARIABLE_PART_NUMBER,      /**<@brief  part number */
        ZW_VARIABLE_PART_CLASS,       /**<@brief  part class */
        ZW_VARIABLE_PART_DESIGNER,    /**<@brief  part designer */
        ZW_VARIABLE_PART_COST,        /**<@brief  part cost */
        ZW_VARIABLE_PART_SUPPLIER,    /**<@brief  part supplier */
        ZW_VARIABLE_PART_DESCRIPTION, /**<@brief  part description */
        ZW_VARIABLE_PART_KEYWORD,     /**<@brief  part keyword */

        ZW_VARIABLE_PART_MANAGER,               /**<@brief  part manager */
        ZW_VARIABLE_PART_MATERIAL,              /**<@brief  part material */
        ZW_VARIABLE_PART_START_DATE,            /**<@brief  part create time */
        ZW_VARIABLE_PART_END_DATE,              /**<@brief  part last modified time */
        ZW_VARIABLE_PART_DERIVED,               /**<@brief  part derived from */
        ZW_VARIABLE_PART_DENSITY,               /**<@brief  part density */
        ZW_VARIABLE_PART_FILEPATH,              /**<@brief  part file path */
        ZW_VARIABLE_PART_FILE_NAME,             /**<@brief  part file name */
        ZW_VARIABLE_PART_SHEET_CODE,            /**<@brief  part sheet code */
        ZW_VARIABLE_PART_SHEET_METAL_THICKNESS, /**<@brief  part sheet metal thickness */
        ZW_VARIABLE_PART_SHEET_METAL_K_FACTOR,  /**<@brief  part sheet metal k factor */
        ZW_VARIABLE_PART_SHEET_METAL_LENGTH,    /**<@brief  part sheet metal length of */
        ZW_VARIABLE_PART_SHEET_METAL_WIDTH,     /**<@brief  part sheet metal width of */

        /* Property attribute */
        ZW_VARIABLE_PROP_NAME,        /**<@brief  property name */
        ZW_VARIABLE_PROP_NUMBER,      /**<@brief  property number */
        ZW_VARIABLE_PROP_DESIGNER,    /**<@brief  property designer */
        ZW_VARIABLE_PROP_MANAGER,     /**<@brief  property manager */
        ZW_VARIABLE_PROP_SUPPLIER,    /**<@brief  property supplier */
        ZW_VARIABLE_PROP_KEYWORD,     /**<@brief  property keyword */
        ZW_VARIABLE_PROP_DESCRIPTION, /**<@brief  property description */
    } ezwVariableStandardAttributeItem;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VARIABLE_DATA_H */
