/**
@file zwapi_attribute_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Attribute Data Types and Structures 
for the attribute API function
*/

#pragma once
#ifndef ZW_API_ATTRIBUTE_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_ATTRIBUTE_DATA_H

#include "zwapi_util.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Date Attribute */
    //====================================================================================================================
    
    /**
    @brief sub-type of date attribute
    @ingroup zwapi_attribue_data
    */
    typedef enum ezwDateType
    {
        ZW_DATE_WITHTIME = 0, /**<@brief  date with time (H:mm:ss)*/
        ZW_DATE_DATEONLY = 1, /**<@brief  date without time */
    } ezwDateType;

    /**
    @brief display format of date attribute 
    @ingroup zwapi_attribute_data

    @note 
    When setting user attribute, "DATE ONLY" and "WITH TIME" share 0~7  
    to set the date format and 8~15 is invalid. While when setting the date  
    format of standard attribute, enumeration is not shared, 0~15 is valid
    */
    typedef enum ezwDateFormat
    {
        /*DATE ONLY*/
        ZW_DATE_FROMAT_SHORT = 0, /**<@brief  short date */
        ZW_DATE_FROMAT_LONG  = 1, /**<@brief  long date */
        ZW_DATE_FROMAT1      = 2, /**<@brief  yyyy/M/D */
        ZW_DATE_FROMAT2      = 3, /**<@brief  yyyy-M-D */
        ZW_DATE_FROMAT3      = 4, /**<@brief  yyyy.M.D */
        ZW_DATE_FROMAT4      = 5, /**<@brief  yy/M/D */
        ZW_DATE_FROMAT5      = 6, /**<@brief  yy-M-D */
        ZW_DATE_FROMAT6      = 7, /**<@brief  yy.M.D */

        /*WITH TIME*/
        ZW_DATE_WITH_TIME_FROMAT_SHORT = 8,  /**<@brief  short date with time */
        ZW_DATE_WITH_TIME_FROMAT_LONG  = 9,  /**<@brief  long date with time */
        ZW_DATE_WITH_TIME_FROMAT1      = 10, /**<@brief  yyyy/M/D H:mm:ss*/
        ZW_DATE_WITH_TIME_FROMAT2      = 11, /**<@brief  yyyy-M-D H:mm:ss*/
        ZW_DATE_WITH_TIME_FROMAT3      = 12, /**<@brief  yyyy.M.D H:mm:ss*/
        ZW_DATE_WITH_TIME_FROMAT4      = 13, /**<@brief  yy/M/D H:mm:ss*/
        ZW_DATE_WITH_TIME_FROMAT5      = 14, /**<@brief  yy-M-D H:mm:ss*/
        ZW_DATE_WITH_TIME_FROMAT6      = 15, /**<@brief  yy.M.D H:mm:ss*/
    } ezwDateFormat;

    //====================================================================================================================
    /** @name User Attribute Data*/
    //====================================================================================================================
    /**
    @brief value list in user attribute 
    @ingroup ZwAttributeData
    */
    typedef struct szwValueData
    {
        zwString1024 value;       /**<@brief  list item value */
        zwString1024 description; /**<@brief  list item description  */
    } szwValueData;

    /**
    @brief user attribute data
    @ingroup ZwAttributeData
    */
    typedef struct szwUserAttribute
    {
        zwString64 name;           /**<@brief  attribute label */
        ezwUserAttributeType type; /**<@brief  attribute type */
        union uzwsubAttribute
        {
            struct szwBool
            {
                int value; /**<@brief  value of the  bool attribute(1 : TRUE,0 : FALSE)*/
            } szwBool;
            struct szwInteger
            {
                zwString512 expression; /**<@brief  expression of integer attribute */
                int value;              /**<@brief  value of integer attribute */
            } szwInteger;
            struct szwNumber
            {
                ezwNumberType subType;  /**<@brief  sub type for number attribute */
                zwString512 expression; /**<@brief  expression of number attribute*/
                char unitType;          /**<@brief  unit for real subtype 
                                                       for length unit see ezwDistanceUnitType
                                                       for angle unit see ezwAngleUnitType
                                                       for mass unit see ezwMassUnitType
                                                       for mass-moment unit see ezwMassMomentUnitType
                                                       ......
                                                     */
                double value;           /**<@brief  real number value */
            } szwNumber;
            struct szwString
            {
                zwString512 expression; /**<@brief  attribute expression, used when "value" is empty,
                                        it can be a real string value or a string include expression. */
                zwString512 value;      /**<@brief  real string value, only used when the input is a real string,
                                        not include expression. */
            } szwString;
            struct szwDate
            {
                double expression;        /**<@brief  attribute expression of date attribute*/
                ezwDateType subType;      /**<@brief  sub type of date attribute */
                ezwDateFormat dateFormat; /**<@brief  date format of date attribute */
                zwString64 value;         /**<@brief  value of date attribute */
            } szwDate;
        } uzwsubAttribute;

        int listSize;             /**<@brief  size of the series value list, if > 0 check the list option, = 0 uncheck */
        szwValueData *valueList;  /**<@brief  value list of string attribute, used only when listSize > 0 and 
                                       type!=ZW_USER_ATTRIBUTE_BOOL and type!=ZW_USER_ATTRIBUTE_DATE*/
        int selectedOrder;        /**<@brief  the order of the selected value item in value list([0, listSize-1]), 
                                       it is useful only when listSize > 0 */
        zwString1024 description; /**<@brief  attribute description */
    } szwUserAttribute;

    //====================================================================================================================
    /** @name Standard attribute */
    //====================================================================================================================

    /**
    @brief items of standard attribute
    @ingroup ZwAttributeData
    */
    typedef enum ezwStandardAttributeItem
    {
        ZW_STANDARD_ATTRIBUTE_NAME = 1,    /**<@brief  name(part_name/sheet_filename/sheet_sheetname)*/
        ZW_STANDARD_ATTRIBUTE_NUMBER,      /**<@brief  number*/
        ZW_STANDARD_ATTRIBUTE_CLASS,       /**<@brief  part class (Part/Clamp/Stock/Table/Tool Holder/Attachment) */
        ZW_STANDARD_ATTRIBUTE_DESIGNER,    /**<@brief  designer */
        ZW_STANDARD_ATTRIBUTE_COST,        /**<@brief  cost */
        ZW_STANDARD_ATTRIBUTE_SUPPLIER,    /**<@brief  supplier */
        ZW_STANDARD_ATTRIBUTE_DESCRIPTION, /**<@brief  description */
        ZW_STANDARD_ATTRIBUTE_KEYWORD,     /**<@brief  keyword */
        ZW_STANDARD_ATTRIBUTE_MANAGER = 9, /**<@brief  manager */

        ZW_STANDARD_ATTRIBUTE_CREATE_TIME = 11, /**<@brief  create time */
        ZW_STANDARD_ATTRIBUTE_LAST_MODIFIED,    /**<@brief  last modified time */
        ZW_STANDARD_ATTRIBUTE_DERIVED,          /**<@brief  derived from */
        ZW_STANDARD_ATTRIBUTE_NO_SECTION,       /**<@brief  do not section */
        ZW_STANDARD_ATTRIBUTE_NO_HATCH,         /**<@brief  do not hatch */
        ZW_STANDARD_ATTRIBUTE_BOM,              /**<@brief  BOM(Normal Part/Indivisible Part/Do not list in BOM)*/
        ZW_STANDARD_ATTRIBUTE_NO_ROOT = 17,     /**<@brief  do not list in root manager */

        ZW_STANDARD_ATTRIBUTE_FILEPATH = 20, /**<@brief  file path */
        ZW_STANDARD_ATTRIBUTE_SHEETPATH,     /**<@brief  corresponded drawing sheet: FILE NAME,SHEET ROOT NAME */
        ZW_STANDARD_ATTRIBUTE_CAM_OBJECT,    /**<@brief  corresponded CAM object: FILE NAME,CAM ROOT NAME */
        ZW_STANDARD_ATTRIBUTE_SHEET_CODE,    /**<@brief  sheet code */
    } ezwStandardAttributeItem;

    /**
    @brief Locking state of attribute item
    @ingroup ZwAttributeData
    */
    typedef enum ezwAttributeItemLockStatus
    {
        ZW_ATTRIBUTE_ITEM_UNLOCKED = 0, /**<@brief  attribute item unlocked */
        ZW_ATTRIBUTE_ITEM_LOCKED,       /**<@brief  lock attribute item and value */
        ZW_ATTRIBUTE_ITEM_LIMITED,      /**<@brief  lock attribute item but not value */
    } ezwAttributeItemLockStatus;

    //====================================================================================================================
    /** @name Physical Attribute */
    //====================================================================================================================
    
    /**
    @brief physical source type
    @ingroup ZwAttributeData
    */
    typedef enum ezwPhysicalSourceType
    {
        ZW_PHYSICAL_ATTRIBUTE_SOURSE_ALL_CURRENT,       /**<@brief  All in current */
        ZW_PHYSICAL_ATTRIBUTE_SOURSE_ALL_ORIGIN,        /**<@brief  All from origin */
        ZW_PHYSICAL_ATTRIBUTE_SOURSE_ONLY_PART_CURRENT, /**<@brief  Only part in current */
        ZW_PHYSICAL_ATTRIBUTE_SOURSE_ONLY_PART_ORIGIN   /**<@brief  Only part in origin */
    } ezwPhysicalSourceType;

    /**
    @brief mass moment of inertia at centroid
    @ingroup ZwAttributeData
    */
    typedef struct szwMassCentroid
    {
        double lx;    /**<@brief  lxx */
        szwPoint2 ly; /**<@brief  lyx,lyy */
        szwPoint lz;  /**<@brief  lzx, lzy,lzz*/
    } szwMassCentroid;

    /**
    @brief physical attribute
    @ingroup ZwAttributeData
    */
    typedef struct szwPhysicalAttribute
    {
        ezwPhysicalSourceType source; /**<@brief  calculate source */
        zwString256 material;         /**<@brief  material name */
        double density;               /**<@brief  density, unit: kg/mm^3 */

        int userMass;     /**<@brief  flag if mass is user defined (if 0 no, else yes)*/
        int userArea;     /**<@brief  flag if area is user defined (if 0 no, else yes)*/
        int userVolume;   /**<@brief  flag if volume is user defined (if 0 no, else yes)*/
        int userSize;     /**<@brief  flag if size(length,width, height) is user defined (if 0 no, else yes)*/
        int userCentroid; /**<@brief  flag if centroid(x,y,z) is user defined (if 0 no, else yes)*/

        double mass;           /**<@brief  mass, unit: kg */
        double area;           /**<@brief  area, unit: mm^2 */
        double volume;         /**<@brief  volume, unit: mm^3 */
        szwPoint size;         /**<@brief  size(length,width, height), unit: mm */
        szwPoint centroid;     /**<@brief  centroid(x,y,z) */
        zwString256 stockSize; /**<@brief  stock size */

        /*the follows only can be get, can not be set */
        szwPoint principal;           /**<@brief  principal moments of inertia (I1, I2, I3)*/
        szwPoint radii;               /**<@brief  radii of principal axes (RG1, RG2, RG3)*/
        szwMassCentroid massCentroid; /**<@brief  mass moments of inertia at centroid */
        szwMassCentroid massOrigin;   /**<@brief  mass moments of inertia at origin */

        int decimal;      /**<@brief  decimal the accuracy of physical attributes (2~7)
                          2 : 0.00; 3 : 0.000,....7 : 0.0000000 */
        int updateOnSave; /**<@brief  flag if update Data On Save (if 0 no, else yes)*/
    } szwPhysicalAttribute;
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ATTRIBUTE_DATA_H */