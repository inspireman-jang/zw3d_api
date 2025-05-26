/**
@file zwapi_history.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HISTORY FILE FOR THE ZW3D History API
*/

#pragma once
#ifndef ZW_API_HISTORY_H /* this ifndef surrounds entire header */
#define ZW_API_HISTROY_H

#include "zwapi_history_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name History Operate */
    //====================================================================================================================
    /**
    @ingroup ZwHistory

    Deletes the specified operations from the history of the active part.

    @param [in] count number of history operations to delete
    @param [in] operations list of history operation handles
    @param [in] operationsType operationsType = ZW_PROMPT_TO_USER : prompt to the user   
                               operationsType = ZW_DELETE_ASSOCIATED_OPERATION : auto delete associated history operations   
                               operationsType = ZW_SUPPRESS_FAILED_FEATURE : auto suppress failed feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwHistoryOperationDelete(int count, szwEntityHandle *operations, ezwHistoryDeleteType operationsType);

    /**
    @ingroup ZwHistory

    Gets a list of history operations in the active part as specified by the
    input "option".

    @note
    The caller is responsible to free the histList by using ZwEntityHandleListFree().

    @param [in] option option = ZW_OPERATION_PLAYED : get history operations that have been played  
                       option = ZW_OPERATION_NOT_PLAYED : get history operations that have not been played  
                       option = ZW_OPERATION_ALL : get played and unplayed history operations
    @param [out] countHistory number of history operations
    @param [out] histList list of history operations

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
    ZW_API_C ezwErrors ZwHistoryListGet(ezwHistoryOperationGetType option, int *countHistory, szwEntityHandle **histList);

    /**
    @ingroup ZwHistory

    Cuts or copies the specified entities of the active part
    to the clipboard, replacing operations previously stored on the clipboard.
    It also works for component objects.

    @param [in] clipOption ZW_HISTORY_CLIP_CUT to cut; ZW_HISTORY_CLIP_COPY to copy
    @param [in] count number of history operations or components to cut or copy
    @param [in] entityList list of history operations or components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwHistoryClip(ezwHistoryClipOption clipOption, int count, const szwEntityHandle *entityList);

    /**
    @ingroup ZwHistory

    Paste operations currently on the clipboard into the history of the active part.
    It also works to paste component objects.
    If the 'targetEntity' is not NULL, it will paste the objects under the specified entity.
    What 'targetEntity' means?
    For example, if you have a file named A with the history objects a1, a2 and a3, and another
    file named B with the history objects b1 and b2, now we can clip the objects a2 and a3 by
    'ZwHistoryClip' and paste them between b1 and b2 by 'ZwHistoryPaste' with set the 'targetEntity'
    to b1. And we can get the history objects of B as b1, a2, a3 and b2.

    @param [in] targetEntity the target entity that pastes the objects under it, NULL to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwHistoryPaste(const szwEntityHandle *targetEntity);

    //====================================================================================================================
    /** @name History Query */
    //====================================================================================================================
    /**
    @ingroup ZwHistory

    Outputs the suppress status of a entity which can be suppressed on history tree(including feature, CSYS...).

    @param [in] entityHandle entity handle
    @param [out] status entity suppress status

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwHistoryEntitySuppressStatusGet(szwEntityHandle entityHandle, ezwSuppressStatus *status);

    /**
    @ingroup ZwHistory

    Outputs the name of the command template that defines the input parameters of the specified history entity.

    @param [in] entityHandle entity handle
    @param [in] nbytes size of "templateName"
    @param [out] templateName command template name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwHistoryEntityTemplateNameGet(szwEntityHandle entityHandle, int nbytes, char *templateName);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_HISTORY_H */