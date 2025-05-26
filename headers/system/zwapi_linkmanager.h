/**
@file zwapi_linkmanager.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Link Manager API
*/

#pragma once
#ifndef ZW_API_LINKMANAGER_H /* this ifndef surrounds entire header */
#define ZW_API_LINKMANAGER_H

#include "zwapi_linkmanager_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Link Manager */
    //====================================================================================================================
    /**
    @ingroup ZwLinkManager

    Get link file list of active file.

    @note
    Zw3d object and external file only have file name.
    The calling procedure is responsible to free data (ZwMemoryFree((void**)&data);).

    @param [in] type output data type
    @param [out] count the number of embedded file data in list
    @param [out] data embedded file data list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
        //Assume that you want to get link file in a component which belongs to an assemble.
        szwEntityHandle targetFileHandle{};
        ... // some code to get targetFileHandle.
        szwEntityHandle currentFileHandle{};
        //Switch to target file where link information that you want to get
        ZwEntityActivate(targetFileHandle, 1, &currentFileHandle);

        szwPartLinkManagerFileData* data = NULL;
        int count = 0;
        ezwLinkManagerFileType type = ZW_LINK_MANAGER_ALL;
        ZwLinkManagerFileListGet(type, &count, &data);
        ...
        //Remember to switch back to original file.
        ZwEntityActivate(currentFileHandle, 1, NULL);

        ZwEntityHandleFree(&currentFileHandle);
        ZwEntityHandleFree(&targetFileHandle);
        ZwMemoryFree((void**)&data);
    @endcode
    */
    ZW_API_C ezwErrors ZwLinkManagerFileListGet(ezwLinkManagerFileType type, int *count, szwPartLinkManagerFileData **data);

    /**
    @ingroup ZwLinkManager

    Open/Close auto regen function in link manager in active file.

    @param [in] status 1 to open auto regen, 0 to disable auto regen

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       //Assume that you want to set auto regen flag in a component which belongs to an assemble.
       szwEntityHandle targetFileHandle{};
       ... // some code to get targetFileHandle.
       szwEntityHandle currentFileHandle{};
       //Switch to target file where link information that you want to get
       ZwEntityActivate(targetFileHandle, 1, &currentFileHandle);

       ZwLinkManagerAutoRegenSet(1);
       ...
       //Remember to switch back to original file.
       ZwEntityActivate(currentFileHandle, 1, NULL);

       ZwEntityHandleFree(&currentFileHandle);
       ZwEntityHandleFree(&targetFileHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwLinkManagerAutoRegenSet(int status);

    /**
    @ingroup ZwLinkManager

    Get open/close auto regen flag in link manager in active file.

    @param [out] status 1 to open auto regen, 0 to disable auto regen

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       //Assume that you want to get auto regen flag in a component which belongs to an assemble.
       szwEntityHandle targetFileHandle{};
       ... // some code to get targetFileHandle.
       szwEntityHandle currentFileHandle{};
       //Switch to target file where link information that you want to get
       ZwEntityActivate(targetFileHandle, 1, &currentFileHandle);

       int status = 0;
       ZwLinkManagerAutoRegenGet(&status);
       ...
       //Remember to switch back to original file.
       ZwEntityActivate(currentFileHandle, 1, NULL);

       ZwEntityHandleFree(&currentFileHandle);
       ZwEntityHandleFree(&targetFileHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwLinkManagerAutoRegenGet(int *status);

    /**
    @ingroup ZwLinkManager

    Get link information in link manager in active file.

    @note
    The calling procedure is responsible to free informationList (ZwMemoryFree((void**)&informationList);).

    @param [out] count number of link information in list
    @param [out] informationList link information list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_GENERAL_ERROR

    @code
       //Assume that you want to get link information in a component which belongs to an assemble.
       szwEntityHandle targetFileHandle{};
       ... // some code to get targetFileHandle.
       szwEntityHandle currentFileHandle{};
       //Switch to target file where link information that you want to get
       ZwEntityActivate(targetFileHandle, 1, &currentFileHandle);
       int cnt = 0;
       szwPartLinkManagerInformation *infoList = NULL;
       ZwLinkManagerInformationGet(&cnt, &infoList);
       ...
       //Remember to switch back to original file.
       ZwEntityActivate(currentFileHandle, 1, NULL);
       ZwEntityHandleFree(&currentFileHandle);
       ZwEntityHandleFree(&targetFileHandle);
       ZwMemoryFree((void**)&infoList);
    @endcode
    */
    ZW_API_C ezwErrors ZwLinkManagerInformationGet(int *count, szwPartLinkManagerInformation **informationList);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LINKMANAGER_H */
