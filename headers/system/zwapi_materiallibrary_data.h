/**
@file zwapi_materiallibrary_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
of Material Library.
*/

#pragma once
#ifndef ZW_API_MATERIAL_LIBRARY_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_MATERIAL_LIBRARY_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Material Library Data */
    //====================================================================================================================
    /**
    @brief material name group
    @ingroup ZwMaterialLibraryData
    */
    typedef struct szwMaterialNameGroup
    {
        zwString256 libraryName;  /**<@brief  material library name */
        zwString256 categoryName; /**<@brief  category name */
        zwString256 materialName; /**<@brief  material name */
    } szwMaterialNameGroup;

    /**
    @brief material property name group
    @ingroup ZwMaterialLibraryData
    */
    typedef struct szwMaterialPropertyNameGroup
    {
        zwString256 propertySetName; /**<@brief  property set name */
        zwString256 propertyName;    /**<@brief  property name */
    } szwMaterialPropertyNameGroup;

    /**
    @brief material general attribute
    @ingroup ZwMaterialLibraryData
    */
    typedef enum ezwMaterialProperty
    {
        ZW_MATERIAL_PROPERTY_DENSITY,                      /**<@brief  density */
        ZW_MATERIAL_PROPERTY_ELASTIC_MODULUS,              /**<@brief  elastic modulus */
        ZW_MATERIAL_PROPERTY_POISSON_RATIO,                /**<@brief  poisson's ratio */
        ZW_MATERIAL_PROPERTY_SHEAR_MODULUS,                /**<@brief  shear modulus */
        ZW_MATERIAL_PROPERTY_TENSILE_STRENGTH,             /**<@brief  tensile strength */
        ZW_MATERIAL_PROPERTY_COMPRESSIVE_STRENGTH,         /**<@brief  compressive strength */
        ZW_MATERIAL_PROPERTY_YIELD_STRENGTH,               /**<@brief  yield strength */
        ZW_MATERIAL_PROPERTY_THERMAL_EXPANSION_COEFFICIEN, /**<@brief  thermal expansion coefficien */
        ZW_MATERIAL_PROPERTY_THERMAL_CONDUCTICITY,         /**<@brief  thermal conducticity */
        ZW_MATERIAL_PROPERTY_SPECIFIC_HEAT_CAPACITY,       /**<@brief  specific heat capacity */
        ZW_MATERIAL_PROPERTY_K_FACTOR,                     /**<@brief  k-factor */
    } ezwMaterialProperty;

    /**
    @brief material general property data
    @ingroup ZwMaterialLibraryData
    */
    typedef struct szwMaterialGeneralProperty
    {
        ezwMaterialProperty property; /**<@brief  material general property */
        double value;                 /**<@brief  property value */
        zwString64 unit;              /**<@brief  property unit (the variable is ignored by the interface that sets the property) */
        zwString512 description;      /**<@brief  property description */
    } szwMaterialGeneralProperty;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATERIAL_LIBRARY_DATA_H */
