/**
@file zwapi_attribute.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Attribute API
*/

#pragma once
#ifndef ZW_API_ATTRIBUTE_H /* this ifndef surrounds entire header */
#define ZW_API_ATTRIBUTE_H

#include "zwapi_attribute_data.h"
#include "zwapi_face.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Physical Attribute */
    //====================================================================================================================

    /**
    @ingroup ZwPhysicalAttribute

    Outputs the physical attribute in the activated file.  
    Function Guide: Attributes -> Properties -> Physical

    @note
    If the data has not been calculated or user-defined,  
    this function will init it to 0.0 and return it. If the data has been user-defined,  
    this function returns the user-defined data.
    
    @param [out] attribute physical attribute of of activated file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwPhysicalAttributeGet(szwPhysicalAttribute *attribute);

    /**
    @ingroup ZwPhysicalAttribute

    Sets physical attribute item data(with user defined) in the activated file.  
    Function Guide: Attributes -> Properties -> Physical

    @note
    Mass, area, volume, size, centroid can set by users if its user flag is 1,  
    source type, material, decimal, update-on-save, stock size can always be set  
    by users, others can not.  
    If the user-define flag is 1, set it, otherwise, keep the previous data.

    @param [in] attribute physical attribute of the activated file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwPhysicalAttributeSet(szwPhysicalAttribute attribute);

    /**
    @ingroup ZwPhysicalAttribute

    This function is used to calculate physical attribute, which is the same as that of the  
    calculator on the platform interface, of the activated file. Note that it will directly  
    use these user defined data , if there is, instead of calculated data.  
    Function Guide: Attributes -> Properties -> Physical

    @note  
    If you need to output these physical attribute data please use ZwPhysicalAttributeGet()

    @see ZwPhysicalAttributeGet and ZwPhysicalAttributeSet

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwPhysicalAttributeCalculate();

    //====================================================================================================================
    /** @name Standard Attribute */
    //====================================================================================================================

    /**
    @ingroup ZwStandardAttribute

    Outputs the contents of the specified item in the standard attribute of the current activated file.  
    The attributeItem includes standard attribute items of ezwStandardAttributeItem  
    Function Guide: Attributes -> Properties -> Standard

    @param [in] attributeItem the specified item in the standard attributes
    @param [in] size length of bytes need to get from the specified contents
    @param [out] attribute the contents of the specified item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwStandardAttributeGet(ezwStandardAttributeItem attributeItem, int size, char *attribute);

    /**
    @ingroup ZwStandardAttribute

    Sets the contents to the specified item in the standard attribute of the current activated file.
    But this function is not suitable for setting the date display format. For date format setting, 
    please use ZwStandardAttributeDateSet().
    Function Guide: Attributes -> Properties -> Standard

    @note
    The attributeItem includes standard attribute items of ezwStandardAttributeItem 
    (ZW_STANDARD_ATTRIBUTE_NAME ~ ZW_STANDARD_ATTRIBUTE_SHEET_CODE). But except following items that 
    cannot be set by users :
        ZW_STANDARD_ATTRIBUTE_NAME ZW_STANDARD_ATTRIBUTE_CREATE_TIME 
        ZW_STANDARD_ATTRIBUTE_LAST_MODIFIED 

    @see ZwStandardAttributeGet and ZwStandardAttributeDateSet.
    
    @param [in] attributeItem the specified item in the standard attributes 
    @param [in] attribute the content to set in the specified item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwStandardAttributeSet(ezwStandardAttributeItem attributeItem, const char *attribute);

    /**
    @ingroup ZwStandardAttribute

    Sets the date display format to the date items  
    (include ZW_STANDARD_ATTRIBUTE_CREATE_TIME and ZW_STANDARD_ATTRIBUTE_LAST_MODIFIED)
    in the standard attribute of the current activated file.  
    Function Guide: Attributes -> Properties -> Standard -> Date

    @param [in] dateFormat the date display format to be set to date items

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwStandardAttributeDateSet(ezwDateFormat dateFormat);

    //====================================================================================================================
    /** @name User Attribute */
    //====================================================================================================================
    
    /**
    @ingroup ZwUserAttribute

    Import the user attribute data from the specified file 'filePath'.  
    The 'filePath' must be a valid excel file path that ends with 'xlsx', 'xls' or 'csv'.  
    Function Guide: Attributes -> Properties -> User 

    @see ZwUserAttributeExport

    @param [in] filePath path of excel file to import

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwUserAttributeImport(const char *filePath);

    /**
    @ingroup ZwUserAttribute

    Export the user attribute data to the specified file 'filePath'.  
    The 'filePath' must be a valid excel file path that ends with 'xlsx', 'xls' or 'csv'.  
    Function Guide: Attributes -> Properties -> User 

    @param [in] filePath path of excel file to export
    @see ZwUserAttributeImport

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwUserAttributeExport(const char *filePath);

    /**
    @ingroup ZwUserAttribute

    Outputs the specified user attributes data if attributeName is not NULL,  
    else get all, in the activated file.  
    Function Guide: Attributes -> Properties -> User 

    @note
    The caller is responsible to free the output data by using ZwUserAttributeDataFree().

    @see ZwUserAttributeDataFree and ZwUserAttributeSet and ZwUserAttributeDelete

    @param [in] attributeName name of the user attribute, if NULL get all attribute
    @param [out] count number of user attributes
    @param [out] attributeList list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwUserAttributeGet(const zwString64 attributeName, int *count, szwUserAttribute **attributeList);

    /**
    @ingroup ZwUserAttribute

    Sets user attribute data of the specified component. And a new user attribute  
    will be inserted if the user attribute for the specified attribute does not exist.  
    Function Guide: Attributes -> Properties -> User 

    @note
    If you want set value of "non-constant real number" type, please refer to the following enum to set "attribute->unit":  
    attribute->type = ZW_NUMBER_LENGTH, attribute->unit = ezwDistanceUnitType;  
    attribute->type = ZW_NUMBER_ANGLE, attribute->unit = ezwAngleUnitType;  
    attribute->type = ZW_NUMBER_MASS, attribute->unit = ezwMassUnitType;  
    attribute->type = ZW_NUMBER_DENSITY, attribute->unit = ezwDensityUnitType;  
    attribute->type = ZW_NUMBER_AREA, attribute->unit = ezwAreaUnitType;  
    attribute->type = ZW_NUMBER_VOLUME, attribute->unit = ezwVolumeUnitType;  
    attribute->type = ZW_NUMBER_MASS_MOMENT, attribute->unit = ezwMassMomentUnitType;  
    attribute->type = ZW_NUMBER_PRESSURE, attribute->unit = ezwPressureUnitType;  
    attribute->type = ZW_NUMBER_TEMPERATURE, attribute->unit = ezwTemperatureUnitType;  
    attribute->type = ZW_NUMBER_MASS_PER_LENGTH, attribute->unit = ezwMassPerLengthUnitType;  

    @see ZwUserAttributeGet and ZwUserAttributeDelete

    @param [in] count number of user attributes to be set
    @param [in] attributeList list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwUserAttributeSet(int count, const szwUserAttribute *attributeList);

    /**
    @ingroup ZwUserAttribute

    Delete the user attributes list in  the activated file.  
    If count < 1 or nameList is null, delete all user attributes in the activated file.  
    Function Guide: Attributes -> Properties -> User 

    @see ZwUserAttributeGet and ZwUserAttributeSet

    @param [in] strictFlag the strictness of delete (if 0:even if one of the input name is wrong,  
                it will not affect others to be deleted, else, others cannot be deleted )
    @param [in] count number of user attributes to be deleted (<1 to delete all user attributes) 
    @param [in] nameList names list of user attributes to be deleted

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwUserAttributeDelete(int strictFlag, int count, const zwString64 *nameList);

    /**
    @ingroup ZwUserAttribute

    Sets the locking state of the specified user attribute item in activated file.  
    When lockStatus = ZW_ATTRIBUTE_ITEM_UNLOCKED, attribute item will be unlocked, that is, it can be edit.  
    When lockStatus = ZW_ATTRIBUTE_ITEM_LOCKED, attribute item will be all locked, that is, the item and its value can not be edit.  
    When lockStatus = ZW_ATTRIBUTE_ITEM_LIMITED, attribute item will be limited, that is, the item will be locked but value is unlocked.  
    Function Guide: Attributes -> Properties -> User 

    @param [in] attributeName name of the specified user attribute
    @param [in] lockStatus locking state of the specified user attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwUserAttributeLockSet(const zwString64 attributeName, ezwAttributeItemLockStatus lockStatus);

    //====================================================================================================================
    /** @name Component User Attribute */
    //====================================================================================================================
    
    /**
    @ingroup ZwUserAttribute

    Outputs the specified user attributes data if attributeName is not NULL, else get all,  
    in the activated component.
    Function Guide: Component(right click) -> Attributes -> User Attribute

    @note
    The caller is responsible to free the output data by using ZwUserAttributeDataFree().

    @see ZwUserAttributeDataFree and ZwComponentUserAttributeSet and ZwComponentUserAttributeDelete

    @param [in] component the component handle
    @param [in] attributeName name of the user attribute, if NULL get all attribute
    @param [out] count the whole number of user attributes in the specified component.
    @param [out] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwComponentUserAttributeGet(szwEntityHandle component, const zwString64 attributeName, int *count, szwUserAttribute **attributeList);

    /**
    @ingroup ZwUserAttribute

    Sets user attribute data of the specified component in the current active file.  
    A new user attribute is inserted if the user attribute for the specified label  
    does not exist.  
    Function Guide: Component(right click) -> Attributes -> User Attribute

    @note
    If you want set value of "non-constant real number" type, please refer to the following enum to set "attribute->unit":  
    attribute->type = ZW_NUMBER_LENGTH, attribute->unit = ezwDistanceUnitType;  
    attribute->type = ZW_NUMBER_ANGLE, attribute->unit = ezwAngleUnitType;  
    attribute->type = ZW_NUMBER_MASS, attribute->unit = ezwMassUnitType;  
    attribute->type = ZW_NUMBER_DENSITY, attribute->unit = ezwDensityUnitType;  
    attribute->type = ZW_NUMBER_AREA, attribute->unit = ezwAreaUnitType;  
    attribute->type = ZW_NUMBER_VOLUME, attribute->unit = ezwVolumeUnitType;  
    attribute->type = ZW_NUMBER_MASS_MOMENT, attribute->unit = ezwMassMomentUnitType;  
    attribute->type = ZW_NUMBER_PRESSURE, attribute->unit = ezwPressureUnitType;  
    attribute->type = ZW_NUMBER_TEMPERATURE, attribute->unit = ezwTemperatureUnitType;  
    attribute->type = ZW_NUMBER_MASS_PER_LENGTH, attribute->unit = ezwMassPerLengthUnitType;  

    @see ZwComponentUserAttributeGet and ZwComponentUserAttributeDelete

    @param [in] component the component handle
    @param [in] count number of user attributes to be set
    @param [in] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR

    @code
       szwEntityHandle entityHandle;
      //code to get component handle
       szwUserAttribute attributes[3] = {};

       strcpy_s(attributes[0].name, sizeof(attributes[0].name), "DATE");
       attributes[0].type = ZW_USER_ATTRIBUTE_DATE;
       attributes[0].uzwsubAttribute.szwDateAttribute.sub_type = ZW_DATE_WITHTIME;
       attributes[0].uzwsubAttribute.szwDateAttribute.dateFormat = ZW_DATE_FROMAT2;
       attributes[0].uzwsubAttribute.szwDateAttribute.expression = 1693849287;

       //suppose that there is an expression named "aaa" in active part.
       strcpy_s(attributes[1].name, sizeof(attributes[1].name), "str1");
       attributes[1].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[1].uzwsubAttribute.szwStringAttribute.value, sizeof(zwString512), "[$aaa]"); 

       strcpy_s(attributes[2].name, sizeof(attributes[2].name), "str2");
       attributes[2].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[2].uzwsubAttribute.szwStringAttribute.expression, sizeof(zwString512), "aaa");

       ZwComponentUserAttributeSet(entityHandle, 3, attributes);
    @endcode  
    */
    ZW_API_C ezwErrors ZwComponentUserAttributeSet(szwEntityHandle component, int count, const szwUserAttribute *attributeList);

    /**
    @ingroup ZwUserAttribute

    Delete user attribute of the specified component in the current active part.  
    This function does not delete any attributes if the specified name is an empty string or the attribute  
    specified name is not found. And all user attribute will be deleted if count < 1 or namelist is empty.  
    Function Guide: Component(right click) -> Attributes -> User Attribute

    @see ZwComponentUserAttributeGet and ZwComponentUserAttributeSet

    @param [in] component the component handle
    @param [in] strictFlag the strictness of delete (if 0:even if one of the input name is wrong,  
            it will not affect others to be deleted, else, others cannot be deleted )
    @param [in] count number of user attributes to be deleted (<1 to delete all user attributes)
    @param [in] nameList list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_INVALID_STRING
    */
    ZW_API_C ezwErrors ZwComponentUserAttributeDelete(szwEntityHandle component, int strictFlag, int count, const zwString64 *nameList);

    //====================================================================================================================
    /** @name Entity User Attribute */
    //====================================================================================================================
    
    /**
    @ingroup ZwUserAttribute

    Outputs the specified user attributes data if attributeName is not NULL, else get all,  
    of the specified entity in the active file.  
    Function Guide: Specified Entity(right click) -> Attributes -> User Attribute

    @note
    The caller is responsible to free the output data by using ZwUserAttributeDataFree().

    @see ZwUserAttributeDataFree, ZwEntityUserAttributeSet and ZwEntityUserAttributeDelete

    @param [in] entityHandle the entity(ONLY SHELL, FACE and EDGE) handle
    @param [in] attributeName name of the user attribute, if NULL get all attribute
    @param [out] count the whole number of user attributes in the specified component.
    @param [out] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEntityUserAttributeGet(szwEntityHandle entityHandle, const zwString64 attributeName, int *count, szwUserAttribute **attributeList);

    /**
    @ingroup ZwUserAttribute

    Sets the user attribute for the specified entity(ONLY SHAPE, FACE and EDGE) in the current active part.  
    A new user attribute is inserted if the user attribute for the specified label does not exist.  
    Function Guide: Specified Entity(right click) -> Attributes -> User Attribute

    @note
    If you want set value of "non-constant real number" type, please refer to the following enum to set "attribute->unit":  
    attribute->type = ZW_NUMBER_LENGTH, attribute->unit = ezwDistanceUnitType;  
    attribute->type = ZW_NUMBER_ANGLE, attribute->unit = ezwAngleUnitType;  
    attribute->type = ZW_NUMBER_MASS, attribute->unit = ezwMassUnitType;  
    attribute->type = ZW_NUMBER_DENSITY, attribute->unit = ezwDensityUnitType;  
    attribute->type = ZW_NUMBER_AREA, attribute->unit = ezwAreaUnitType;  
    attribute->type = ZW_NUMBER_VOLUME, attribute->unit = ezwVolumeUnitType;  
    attribute->type = ZW_NUMBER_MASS_MOMENT, attribute->unit = ezwMassMomentUnitType;  
    attribute->type = ZW_NUMBER_PRESSURE, attribute->unit = ezwPressureUnitType;  
    attribute->type = ZW_NUMBER_TEMPERATURE, attribute->unit = ezwTemperatureUnitType;  
    attribute->type = ZW_NUMBER_MASS_PER_LENGTH, attribute->unit = ezwMassPerLengthUnitType;  

    @see ZwEntityUserAttributeGet and ZwEntityUserAttributeDelete

    @param [in] entityHandle the entity(ONLY SHELL, FACE and EDGE) handle
    @param [in] count number of user attributes to be set
    @param [in] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
       szwEntityHandle entityHandle;
       //code to get entity handle
       szwUserAttribute attributes[3] = {};

       strcpy_s(attributes[0].name, sizeof(attributes[0].name), "DATE");
       attributes[0].type = ZW_USER_ATTRIBUTE_DATE;
       attributes[0].uzwsubAttribute.szwDateAttribute.sub_type = ZW_DATE_WITHTIME;
       attributes[0].uzwsubAttribute.szwDateAttribute.dateFormat = ZW_DATE_FROMAT2;
       attributes[0].uzwsubAttribute.szwDateAttribute.expression = 1693849287;

       //suppose that there is an expression named "aaa" in active part.
       strcpy_s(attributes[1].name, sizeof(attributes[1].name), "str1");
       attributes[1].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[1].uzwsubAttribute.szwStringAttribute.value, sizeof(zwString512), "[$aaa]"); 

       strcpy_s(attributes[2].name, sizeof(attributes[2].name), "str2");
       attributes[2].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[2].uzwsubAttribute.szwStringAttribute.expression, sizeof(zwString512), "aaa");

       ZwEntityUserAttributeSet(entityHandle, 3, attributes);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityUserAttributeSet(szwEntityHandle entityHandle, int count, const szwUserAttribute *attributeList);

    /**
    @ingroup ZwUserAttribute
     
    Delete user attribute of the specified entity(ONLY SHELL, FACE and EDGE) in the current active part.  
    This function does not delete any attributes if the specified name is an empty string or the attribute  
    specified name is not found. And all user attribute will be deleted if count < 1 or namelist is empty.  
    Function Guide: Specified Entity(right click) -> Attributes -> User Attribute

    @see ZwEntityUserAttributeGet and ZwEntityUserAttributeSet

    @param [in] entityHandle the entity(ONLY SHELL, FACE and EDGE) handle
    @param [in] strictFlag the strictness of delete (if 0:even if one of the input name is wrong,  
                it will not affect others to be deleted, else, others cannot be deleted )
    @param [in] count number of user attributes to be deleted (<1 to delete all user attributes)
    @param [in] nameList list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_STRING
    -        ZW_API_OBJ_DATA_SET_ERROR  
    */
    ZW_API_C ezwErrors ZwEntityUserAttributeDelete(szwEntityHandle entityHandle, int strictFlag, int count, const zwString64 *nameList);

    //====================================================================================================================
    /** @name History User Attribute */
    //====================================================================================================================
    
    /**
    @ingroup ZwUserAttribute

    Outputs the specified user attributes data if attributeName is not NULL, else get all,  
    of the specified feature or sketch in the activated part.  
    Function Guide: History Entity(right click) -> Attributes -> User Attribute

    @note
    The caller is responsible to free the output data by using ZwUserAttributeDataFree()

    @see ZwUserAttributeDataFree, ZwHistoryUserAttributeSet and ZwHistoryUserAttributeDelete

    @param [in] historyHandle the history(just support feature and sketch) handle  
    @param [in] attributeName name of the user attribute, if NULL get all attribute  
    @param [out] count the whole number of user attributes in the specified component.  
    @param [out] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwHistoryUserAttributeGet(szwEntityHandle historyHandle, const zwString64 attributeName, int *count, szwUserAttribute **attributeList);

    /**
    @ingroup ZwUserAttribute

    Sets the user attribute for the specified history(feature or sketch) in the activated part.  
    A new user attribute is inserted if the user attribute for the specified name does not exist.  
    Function Guide: History Entity(right click) -> Attributes -> User Attribute

    @note
    If you want set value of "non-constant real number" type, please refer to the following enum to set "attribute->unit":  
    attribute->type = ZW_NUMBER_LENGTH, attribute->unit = ezwDistanceUnitType;  
    attribute->type = ZW_NUMBER_ANGLE, attribute->unit = ezwAngleUnitType;  
    attribute->type = ZW_NUMBER_MASS, attribute->unit = ezwMassUnitType;  
    attribute->type = ZW_NUMBER_DENSITY, attribute->unit = ezwDensityUnitType;  
    attribute->type = ZW_NUMBER_AREA, attribute->unit = ezwAreaUnitType;  
    attribute->type = ZW_NUMBER_VOLUME, attribute->unit = ezwVolumeUnitType;  
    attribute->type = ZW_NUMBER_MASS_MOMENT, attribute->unit = ezwMassMomentUnitType;  
    attribute->type = ZW_NUMBER_PRESSURE, attribute->unit = ezwPressureUnitType;  
    attribute->type = ZW_NUMBER_TEMPERATURE, attribute->unit = ezwTemperatureUnitType;  
    attribute->type = ZW_NUMBER_MASS_PER_LENGTH, attribute->unit = ezwMassPerLengthUnitType;  

    @see ZwHistoryUserAttributeGet, ZwHistoryUserAttributeDelete and ZwUserAttributeDataFree

    @param [in] historyHandle the history(just support feature and sketch) handle
    @param [in] count number of user attributes to be set
    @param [in] attributeList data list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
       szwEntityHandle entityHandle;
       //code to get feature or sketch handle
       szwUserAttribute attributes[3] = {};

       strcpy_s(attributes[0].name, sizeof(attributes[0].name), "DATE");
       attributes[0].type = ZW_USER_ATTRIBUTE_DATE;
       attributes[0].uzwsubAttribute.szwDateAttribute.sub_type = ZW_DATE_WITHTIME;
       attributes[0].uzwsubAttribute.szwDateAttribute.dateFormat = ZW_DATE_FROMAT2;
       attributes[0].uzwsubAttribute.szwDateAttribute.expression = 1693849287;

       //suppose that there is an expression named "aaa" in active part.
       strcpy_s(attributes[1].name, sizeof(attributes[1].name), "str1");
       attributes[1].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[1].uzwsubAttribute.szwStringAttribute.value, sizeof(zwString512), "[$aaa]"); 

       strcpy_s(attributes[2].name, sizeof(attributes[2].name), "str2");
       attributes[2].type = ZW_USER_ATTRIBUTE_STRING;
       strcpy_s(attributes[2].uzwsubAttribute.szwStringAttribute.expression, sizeof(zwString512), "aaa");

       ZwHistoryUserAttributeSet(entityHandle, 3, attributes);
    @endcode
    */
    ZW_API_C ezwErrors ZwHistoryUserAttributeSet(szwEntityHandle historyHandle, int count, const szwUserAttribute *attributeList);

    /**
    @ingroup ZwUserAttribute

    Delete user attribute of the specified history (feature or sketch) in the activated part  
    when the specified attribute name is not empty and can be found in attribute list.  
    And all user attribute will be deleted if count < 1 or namelist is empty.  
    Function Guide: History Entity(right click) -> Attributes -> User Attribute

    @see ZwHistoryUserAttributeGet and ZwHistoryUserAttributeSet

    @param [in] historyHandle the history(just support feature and sketch) handle
    @param [in] strictFlag the strictness of delete (if 0:even if one of the input name is wrong,  
                it will not affect others to be deleted, else, others cannot be deleted )
    @param [in] count number of user attributes to be deleted (<1 to delete all user attributes)
    @param [in] nameList list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_STRING
    */
    ZW_API_C ezwErrors ZwHistoryUserAttributeDelete(szwEntityHandle historyHandle, int strictFlag, int count, const zwString64 *nameList);

    /**
    @ingroup ZwUserAttribute

    Free the memory inside each user attribute and the user attributeList itself.
    Function Guide: Attributes -> Properties -> User 

    @param [in] userCount user attribute number
    @param [in] attributeList user attribute list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwUserAttributeDataFree(int userCount, szwUserAttribute **attributeList);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !ZW_API_ATTRIBUTE_H */