/**
@file zwapi_pickset.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Pick set API
*/

#pragma once
#ifndef ZW_API_PICKSET_H /* this ifndef surrounds entire header */
#define ZW_API_PICKSE_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
 

    /**
    @ingroup ZwPickset

    Get information of the specified pick-set.

    @note
    The caller is responsible to free the entityList by using ZwEntityHandleListFree().

    @param [in] picksetHandle handle of the pick set
    @param [in] namelength the length of the pick set name
    @param [out] pickSetName name of the pick set
    @param [out] pickSetCount entity count of the pick set
    @param [out] entityList entity List of the pick set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_GENERAL_ERROR

    @code
       szwEntityHandle picksetHandle, *entityList = nullptr;
       zwString32 psName;
       int entityCount = 0;
       ...
       ZwPicksetInformationGet(picksetHandle, sizeof(psName), psName, &entityCount, &entityList);
       ...
       ZwEntityHandleFree(&picksetHandle);
       ZwEntityHandleListFree(entityCount, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwPicksetInformationGet(szwEntityHandle picksetHandle, int namelength, char *pickSetName, int *pickSetCount, szwEntityHandle **entityList);

    /**
    @ingroup ZwPickset

    Get the list of all pick set.

    @note
    The caller is responsible to free the picksetHandles by using ZwEntityHandleListFree().

    @param [out] pickSetCount count of pick sets
    @param [out] picksetHandles handles of pick sets

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       szwEntityHandle* entityHandles= nullptr;
       int psCount = 0;
       ZwPicksetListGet(&psCount, &entityHandles);
       ...
       ZwEntityHandleListFree(psCount, &entityHandles);
    @endcode
    */
    ZW_API_C ezwErrors ZwPicksetListGet(int *pickSetCount, szwEntityHandle **picksetHandles);

    /**
    @ingroup ZwPickset

    Delete the specified pick-set.

    @param [in] picksetHandle handle of the pick set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR

    @code
       szwEntityHandle picksetHandle;
       ...
       ZwPicksetDelete(picksetHandle);
       ZwEntityHandleFree(&picksetHandle);
    @endcode

    */
    ZW_API_C ezwErrors ZwPicksetDelete(szwEntityHandle picksetHandle);

    /**
    @ingroup ZwPickset

    Create a new pick set according to name and entityList.

    @note
    The caller is responsible to free the picksetHandle by using ZwEntityHandleListFree().  
    Duplicate entities exist in entity lists of pick set is not allowed, so any entity only appear once in the pick set.  
    When entityList has duplicate entities, the duplicate entities will be removed.

    @param [in] pickSetName name of the new pick set.If the picksetName is more than 31 bits,
                this function will truncate the content after 31 bits (the 32nd bit is the terminator).
                If picksetName is the same as any existing entity or pick set, the name of the new pick
                set will automatically numbered, such as "NewPick_1" "NewPick_2".
    @param [in] entityCount entity count of the new pick set
    @param [in] entityList entities of the new pick set
    @param [out] picksetHandle handle of the new pick set (can be NULL if no need)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       zwString32 picksetName;
       szwEntityHandle picksetHandle, *entityList = nullptr;
       int entityCount = 0;
       ...
       ZwPicksetCreate(picksetName, entityCount, entityList, &picksetHandle);
       ...
       ZwEntityHandleFree(&picksetHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwPicksetCreate(const zwString32 pickSetName, int entityCount, const szwEntityHandle *entityList, szwEntityHandle *picksetHandle);

    /**
    @ingroup ZwPickset

    Modify the pick set name. After modify the pick set name , users should call ZwCommandSend("~CdGuiUpdate")
    to refresh the pick set name.

    @param [in] pickSetName new name of the pick set.The picksetName can not be the same as
                any existing entity or pick set.The picksetName must less than 32 bits
    @param [in] picksetHandle handle of the pick set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwPicksetRename(const zwString32 pickSetName, szwEntityHandle picksetHandle);

    /**
    @ingroup ZwPickset

    Add entities to part pick set.Duplicate entities exist in entity lists of pick set is not allowed, 
    so any entity only appear once in the pick set.

    @param [in] picksetHandle handle of the pick set
    @param [in] entityCount the number of entities added to the pick set
    @param [in] entityList list of entities added to the pick set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       szwEntityHandle picksetHandle, *entityList = nullptr;
       int entityCount = 0;
       ... // some code to get the data of variables
       ZwPicksetEntityAdd(picksetHandle, entityCount, entityList);
       ...
       ZwEntityHandleFree(&picksetHandle);
       ZwEntityHandleListFree(entityCount, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwPicksetEntityAdd(szwEntityHandle picksetHandle, int entityCount, const szwEntityHandle *entityList);

    /**
    @ingroup ZwPickset

    Delete entities in part pick set. Deleting all entities in the pick set is not allowed.

    @note
    When any entity that exists in the entityList but not in pick set, this function will only delete
    the intersection of the entityList and pick set without error.


    @param [in] picksetHandle handle of the pick set
    @param [in] entityCount the number of entities deleted in the pick set
    @param [in] entityList entity lists of entities deleted in the pick set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       szwEntityHandle picksetHandle, *entityList = nullptr;
       int entityCount = 0;
       ... // some code to get the data of variables
       ZwPicksetEntityAdd(picksetHandle, entityCount, entityList);
       ...
       ZwEntityHandleFree(&picksetHandle);
       ZwEntityHandleListFree(entityCount, &entityList);
    @endcode

    */
    ZW_API_C ezwErrors ZwPicksetEntityDelete(szwEntityHandle picksetHandle, int entityCount, const szwEntityHandle *entityList);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PICKSE_H */
