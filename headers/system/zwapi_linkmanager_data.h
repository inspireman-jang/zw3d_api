/**
@file zwapi_linkmanager.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D link Manager Data
*/

#pragma once
#ifndef ZW_API_LINKMANAGER_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_LINKMANAGER_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

     /**
    @brief link manager file data
    @ingroup ZwLinkManagerData
    */
    typedef struct szwPartLinkManagerFileData
    {
        zwPath fileName; /**<@brief  file name */
        zwPath fullPath; /**<@brief  file path */
    } szwPartLinkManagerFileData;

    /**
    @brief link manager file data type
    @ingroup ZwLinkManagerData
    */
    typedef enum ezwLinkManagerFileType
    {
        ZW_LINK_MANAGER_ALL = 0,     /**<@brief get all type */
        ZW_LINK_MANAGER_ZW3D_OBJECT, /**<@brief get ZW3D object links */
        ZW_LINK_MANAGER_EXTERNAL,    /**<@brief get external file links */
        ZW_LINK_MANAGER_EMBEDDED     /**<@brief get embedded files */
    } ezwLinkManagerFileType;

    /**
    @brief link mode in link manager
    @ingroup ZwLinkManagerData
    */
    typedef enum ezwLinkMode
    {
        ZW_LINK_MANAGER_DRIVE = 0, /**<@brief drive */
        ZW_LINK_MANAGER_DRIVEN,    /**<@brief driven */
    } ezwLinkMode;

    /**
    @brief link status in link manager
    @ingroup ZwLinkManagerData
    */
    typedef enum ezwLinkRelationStatus
    {
        ZW_LINK_MANAGER_UPTODATE = 0, /**<@brief uptodate */
        ZW_LINK_MANAGER_OUTDATE,      /**<@brief outdate */
        ZW_LINK_MANAGER_MISSING,      /**<@brief missing */
        ZW_LINK_MANAGER_UNKNOWN       /**<@brief unknown */
    } ezwLinkRelationStatus;

    /**
    @brief link type in link manager
    @ingroup ZwLinkManagerData
    */
    typedef enum ezwLinkRelationType
    {
        ZW_LINK_MANAGER_UNKNOWNN = 0,     /**<@brief  unknown type */
        ZW_LINK_MANAGER_PART,             /**<@brief  part type */
        ZW_LINK_MANAGER_GEOMETRY,         /**<@brief  geometry type */
        ZW_LINK_MANAGER_GEOM_IMPORT,      /**<@brief  geom inport type */
        ZW_LINK_MANAGER_EXPRESSION,       /**<@brief  expression type */
        ZW_LINK_MANAGER_ASSEMBLE_FEATURE, /**<@brief  assemble feature type */
        ZW_LINK_MANAGER_HISTORY_FEATURE,  /**<@brief  history feature type */
        ZW_LINK_MANAGER_COMPONENT,        /**<@brief  component type */
        ZW_LINK_MANAGER_ALIGN,            /**<@brief  align object type */
        ZW_LINK_MANAGER_PROFILE,          /**<@brief  profile type */
        ZW_LINK_MANAGER_2DBLOCK,          /**<@brief  2d block type */
    } ezwLinkRelationType;

    /**
    @brief link manager information data
    @ingroup ZwLinkManagerData
    */
    typedef struct szwPartLinkManagerInformation
    {
        zwString256 linkObject;       /**<@brief  link object */
        ezwLinkMode mode;             /**<@brief  link mode */
        zwString256 associatedObject; /**<@brief  associated object */
        zwString256 linkFilePath;     /**<@brief  link file path */
        zwString256 associatedFile;   /**<@brief  associated file */
        ezwLinkRelationStatus status; /**<@brief  link relation status */
        ezwLinkRelationType type;     /**<@brief  link relation type */
        zwString256 contextAssembly;  /**<@brief  context assembly */
    } szwPartLinkManagerInformation;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LINKMANAGER_DATA_H */
