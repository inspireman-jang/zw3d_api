/**
@file zwapi_materiallibrary.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Material Library API
*/

#pragma once
#ifndef ZW_API_MATERIAL_LIBRARY_H /* this ifndef surrounds entire header */
#define ZW_API_MATERIAL_LIBRARY_H

#include "zwapi_materiallibrary_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Material Library */
    //====================================================================================================================
    /**
    @ingroup ZwMaterialLibrary

    Creates a new material library with the specified name.

    @param [in] libraryName material library name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_NAME_ALREADY_IN_USE
    */
    ZW_API_C ezwErrors ZwMaterialLibraryCustomCreate(const char *libraryName);

    /**
    @ingroup ZwMaterialLibrary

    Deletes the material library with the specified name. The function will only delete unused materials from the material library.
    Materials in use will not be deleted.

    @param [in] libraryName material library name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialLibraryCustomDelete(const char *libraryName);

    /**
    @ingroup ZwMaterialLibrary

    Gets a list of all the material library names.

    @note
    The caller is responsible to free the libraryList by using ZwMemoryFree().

    @param [out] count the number of material libraries
    @param [out] libraryList list of material library names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwMaterialLibraryListGet(int *count, zwString512 **libraryList);

    //====================================================================================================================
    /** @name Material Category */
    //====================================================================================================================
    /**
    @ingroup ZwMaterialLibrary

    Creates a new material category to the specified material library. If the specified material library does not exist,
    a material library with the specified name will be created.

    @param [in] libraryName material library name
    @param [in] categoryName material category name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_NAME_ALREADY_IN_USE
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialLibraryCategoryCreate(const char *libraryName, const char *categoryName);

    /**
    @ingroup ZwMaterialLibrary

    Deletes the material category with the specified name. The function will only delete unused materials from the material category.
    Materials in use will not be deleted.

    @param [in] libraryName material library name
    @param [in] categoryName material category name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialLibraryCategoryDelete(const char *libraryName, const char *categoryName);

    /**
    @ingroup ZwMaterialLibrary

    Gets a list of the names of all categories in the specified material library.

    @note
    The caller is responsible to free the categoryList by using ZwMemoryFree().

    @param [in] libraryName material library name
    @param [out] count the number of material categories
    @param [out] categoryList list of material category names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwMaterialLibraryCategoryListGet(const char *libraryName, int *count, zwString512 **categoryList);

    //====================================================================================================================
    /** @name Material */
    //====================================================================================================================
    /**
    @ingroup ZwMaterialLibrary

    Creates a new material to the specified material library and category. If the specified material library or category does not exist,
    a material library or category with the specified name will be created.

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [in] density density value of the material
    @param [in] densityUnit unit applied to the input density value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_NAME_ALREADY_IN_USE
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialLibraryMaterialCreate(szwMaterialNameGroup materialNameGroup, double density, ezwDensityUnitType densityUnit);

    /**
    @ingroup ZwMaterialLibrary

    Deletes the material with the specified name. the material will not be deleted if it is in use.

    @param [in] materialNameGroup material name group, include material library name, category name and material name 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialLibraryMaterialDelete(szwMaterialNameGroup materialNameGroup);

    /**
    @ingroup ZwMaterialLibrary

    Gets a list of the names of all materials in the specified material category.

    @note
    The caller is responsible to free the materialList by using ZwMemoryFree().

    @param [in] libraryName material library name
    @param [in] categoryName material category name
    @param [out] count the number of materials
    @param [out] materialList list of material names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwMaterialLibraryMaterialListGet(const char *libraryName, const char *categoryName, int *count, zwString512 **materialList);

    //====================================================================================================================
    /** @name Material Property */
    //====================================================================================================================
    /**
    @ingroup ZwMaterialLibrary

    Sets the specified general property of the material. The property will be added if the material does not contain it. 

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [in] property the general attribute of the material
    @param [in] value property value
    @param [in] unitSystem unit system applied to the input property value, please refer to the description of ezwUnitSystem for the specific units of each unit system
    @param [in] description property description (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialGeneralPropertySet(szwMaterialNameGroup materialNameGroup, ezwMaterialProperty property, double value, ezwUnitSystem unitSystem, const char *description);

    /**
    @ingroup ZwMaterialLibrary

    Gets the specified general property of the material.

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [in] property the general attribute of the material
    @param [out] value property value (input NULL to ignore)
    @param [out] unit property unit (input NULL to ignore)
    @param [in] bytes the number of bytes of memory for the variable description
    @param [out] description property description (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwMaterialGeneralPropertyGet(szwMaterialNameGroup materialNameGroup, ezwMaterialProperty property, double *value, zwString64 unit, int bytes, char *description);

    /**
    @ingroup ZwMaterialLibrary

    Sets the specified general properties of the material. Properties not included in the material will be added.

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [in] unitSystem unit system applied to the input property value, please refer to the description of ezwUnitSystem for the specific units of each unit system
    @param [in] count the number of properties
    @param [in] properties list of properties

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialGeneralPropertyListSet(szwMaterialNameGroup materialNameGroup, ezwUnitSystem unitSystem, int count, const szwMaterialGeneralProperty *properties);

    /**
    @ingroup ZwMaterialLibrary

    Gets a list of general properties that the material contains.

    @note
    The caller is responsible to free the libraryList by using ZwMemoryFree().

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [out] count the number of properties
    @param [out] properties list of properties

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMaterialGeneralPropertyListGet(szwMaterialNameGroup materialNameGroup, int *count, szwMaterialGeneralProperty **properties);

    /**
    @ingroup ZwMaterialLibrary

    Deletes the specified general properties of the material.

    @param [in] materialNameGroup material name group, include material library name, category name and material name 
    @param [in] count the number of the general attributes to delete
    @param [in] properties list of the general attributes to delete

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_UNSUPPORTED_OBJ
    */
    ZW_API_C ezwErrors ZwMaterialGeneralPropertyDelete(szwMaterialNameGroup materialNameGroup, int count, const ezwMaterialProperty *properties);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATERIAL_LIBRARY_H */
