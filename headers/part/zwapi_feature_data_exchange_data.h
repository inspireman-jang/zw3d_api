/**
@file zwapi_feature_data_exchange_data.h
@copyright (C) Copyright 2024, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Data Exchange Feature.
*/

#pragma once
#ifndef ZW_API_FEATURE_DATA_EXCHANGE_DATA_H
#define ZW_API_FEATURE_DATA_EXCHANGE_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Import Data */
    //====================================================================================================================

    /**
    @brief types of the command 'External Geom Copy' 
    @ingroup ZwFeatureDataExchange
    */
    typedef enum ezwExternalGeometryCopyType
    {
        ZW_GEOMETRY_COPY_FROM_EXTERNAL_FILE, /**<@brief  from external file */
        ZW_GEOMETRY_COPY_FROM_LOCAL,         /**<@brief  from local component */
    } ezwExternalGeometryCopyType;

    /**
    @brief option of the data 'Associative copy' of the command 'External Geom Copy' 
    @ingroup ZwFeatureDataExchange
    */
    typedef enum ezwAssociativeCopyType
    {
        ZW_ASSOCIATIVE_COPY_NONE = 0,      /**<@brief  disable the option 'Associative copy' */
        ZW_ASSOCIATIVE_COPY_AUTO_UPDATE,   /**<@brief  auto update  */
        ZW_ASSOCIATIVE_COPY_MANUAL_UPDATE, /**<@brief  manual update */
    } ezwAssociativeCopyType;

    /**
    @brief option of the data 'Placement' of the command 'External Geom Copy' 
    @ingroup ZwFeatureDataExchange
    */
    typedef enum ezwExternalGeometryPlacementType
    {
        ZW_PLACEMENT_DEFAULT_DATUM,  /**<@brief  use default datum */
        ZW_PLACEMENT_SELECTED_DATUM, /**<@brief  use selected datum, it requires the data provides a valid external datum */
    } ezwExternalGeometryPlacementType;

    /**
    @brief option of the data 'Type' of the command 'External Geom Copy' to pick entities
    @ingroup ZwFeatureDataExchange
    */
    typedef enum ezwExternalGeometryEntityType
    {
        ZW_GEOMETRY_COPY_PICKED_ENTITIES, /**<@brief  pick entities */
        ZW_GEOMETRY_COPY_COPY_ALL,        /**<@brief  copy all valid from picked file, it means 'Entire component' when the type is ZW_GEOMETRY_COPY_FROM_LOCAL */
        ZW_GEOMETRY_COPY_PUBLISH_SET,     /**<@brief  publish set */
    } ezwExternalGeometryEntityType;

    /**
    @brief external file data of the command 'External Geom Copy'
    @ingroup ZwFeatureDataExchange
    */
    typedef struct szwExternalGeometryExternalData
    {
        zwString512 fileName;                           /**<@brief  external file name */
        zwString256 rootName;                           /**<@brief  root name of external file name, it's required when the 'fileName' is not a single-root file */
        ezwExternalGeometryPlacementType placementType; /**<@brief  placement type for external entities */
        ezwExternalGeometryEntityType entityType;       /**<@brief  type of external entities */
        szwEntityHandle externalDatum;                  /**<@brief  external datum of the external file, it's required when placementType = ZW_PLACEMENT_SELECTED_DATUM */
        szwEntityHandle targetDatum;                    /**<@brief  local datum of current file, use default datum if the innerData is empty or invalid, it's required when placementType = ZW_PLACEMENT_SELECTED_DATUM */
        int entityCount;                                /**<@brief  number of the entities to copy, it will be ignored when entityType = ZW_GEOMETRY_COPY_COPY_ALL */
        szwEntityHandle *entityList;                    /**<@brief  entities to copy, it will be ignored when entityType = ZW_GEOMETRY_COPY_COPY_ALL */

    } szwExternalGeometryExternalData;

    /**
    @brief local data of the command 'External Geom Copy'
    @ingroup ZwFeatureDataExchange
    */
    typedef struct szwExternalGeometryLocalData
    {
        ezwExternalGeometryEntityType entityType; /**<@brief  type of component entities */
        int entityCount;                          /**<@brief  number of the entities to copy */
        szwEntityHandle *entityList;              /**<@brief  entities to copy */
    } szwExternalGeometryLocalData;

    /**
    @brief data of the command 'External Geom Copy'
    @ingroup ZwFeatureDataExchange
    */
    typedef struct szwExternalGeometryCopyData
    {
        /* Required */
        ezwExternalGeometryCopyType copyType; /**<@brief  type to copy the geometry data */

        union uzwCopyData
        {
            szwExternalGeometryExternalData externalData; /**<@brief  data of external file */
            szwExternalGeometryLocalData localData;       /**<@brief  data of local components */
        } copyData;                                       /**<@brief  data to copy the geometries */

        /* Association Settings */
        ezwAssociativeCopyType associativeCopyType; /**<@brief  whether to create reference geometry associates with the referenced external geometry. 
                                                                The reference geometry re-evaluates each time when referenced geometry is regenerated.
                                                                If use ZW_ASSOCIATIVE_COPY_NONE, this option create reference geometry that is a one-time static copy of the selected geometry.
                                                                default : ZW_ASSOCIATIVE_COPY_AUTO_UPDATE */
        int isRecordState;                          /**<@brief  whether to record the state of the history of the part from which the reference geometry is extracted(1-yes, 0-no, default:0) */
        int isPositionIndependent;                  /**<@brief  1 - the position of the reference geometry is the same as the referenced assembly
                                                                0 - the position of the reference geometry is the same as the original part associated with the referenced assembly
                                                                default : 0
                                                                it will be used when copyType = ZW_GEOMETRY_COPY_FROM_LOCAL */
    } szwExternalGeometryCopyData;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // !ZW_API_FEATURE_DATA_EXCHANGE_DATA_H