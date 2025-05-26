/**
@file zwapi_ui_guiset.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D UI Setting API
*/
/**
@defgroup zwapi_ui_guiset Gui Set
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D UI Setting API
*/

#pragma once
#ifndef ZW_API_GUI_SET_H /* this ifndef surrounds entire header */
#define ZW_API_GUI_SET_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Role management */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_guiset

    Get the count of custom roles or called user roles
    The collection doesn't contain the ZW3D default roles like "Expert"

    @retval The count of custom roles in role manager.

    */
    ZW_API_C int cvxUiSettingsCount(void);

    /**
    @ingroup zwapi_ui_guiset

    Create a new ui custom role based on the create role text and copied role text

    @param [in] CreateRoleText the text of the new creating custom role
    @param [in] CopyRoleText   the text of the copied role

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsCreate(char *CreateRoleText, char *CopyRoleText);

    /**
    @ingroup zwapi_ui_guiset

    Rename the specified ui custom role from current text to the new

    @param [in] CurRoleText the text of the existed custom role to be renamed
    @param [in] NewRoleText the new text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsRename(char *CurRoleText, char *NewRoleText);

    /**
    @ingroup zwapi_ui_guiset

    Remove the specified ui custom role

    @param [in] RoleText the text of the custom role to be removed

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsRemove(char *RoleText);

    /**
    @ingroup zwapi_ui_guiset

    Import the file of custom role's profile

    @param [in] Path the zip file path of profile to be imported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxUiSettingsImport(char *Path);

    /**
    @ingroup zwapi_ui_guiset

    Export the profile of custom role located by input role text into one zip file

    @param [in] RoleText the text of custom role
    @param [in] Path     the zip file path of profile to be exported

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxUiSettingsExport(char *RoleText, char *Path);

    /**
    @ingroup zwapi_ui_guiset

    Check whether the custom roles defined in role manager contain the role
    of which the text equal with the input text

    @param [in] RoleText the text of custom role

    @retval custom role is existed
    -        ZW_API_NO_ERROR
    @retval custom role isn't existed
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsExists(char *RoleText);

    /**
    @ingroup zwapi_ui_guiset

    Apply the target custom role

    @param [in] RoleText the text of custom role

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsApply(char *RoleText);

    /**
    @ingroup zwapi_ui_guiset

    Use current role's profile data to reset the target custom role
    located by input role text

    @param [in] RoleText the text of custom role

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxUiSettingsReset(char *RoleText);

    /**
    @ingroup zwapi_ui_guiset

    Get the ui custom role text by the given index

    @param [in] i the index of the custom roles to be fetched
    @param [out] RoleText the text of the custom role to be fetched

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxUiSettingsFetch(int i, char *RoleText);


    //====================================================================================================================
    /** @name Cursor Management */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_guiset

    Changes the active mouse cursor to the specified type.  
    A call to this function should always be paired with  
    a subsequent callto cvxCursorRestore().
    @param [in] Type cursor type

    */
    ZW_API_C void cvxCursorSet(evxCursorType Type);

    /**
    @ingroup zwapi_ui_guiset

    Restores the cursor type that was active prior to the last
    call to cvxCursorSet.

    */
    ZW_API_C void cvxCursorRestore(void);

    /**
    @ingroup zwapi_ui_guiset

    Invoke GUI callback function to display percent progress  
    or to clear the progress meter if "iprogress < 0".  
    @param [in] iprogress percent progress (0-100)

    */
    ZW_API_C void cvxProgress(int iprogress);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_GUI_SET_H */
