/**
@file zwapi_ui_command.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command API
*/

#pragma once
#ifndef ZW_API_UI_COMMAND_H /* this ifndef surrounds entire header */
#define ZW_API_UI_COMMAND_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Command */
    //====================================================================================================================
    /**
    @ingroup ZwUiCommand

    Gets command text of the specified command.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [in] type text type, menu text or ribbon text
    @param [out] text command text
    @param [in] size the number of bytes of storage referenced by "text"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwUiCommandTextGet(const char *command, ezwCommandTextType type, char *text, int size);

    /**
    @ingroup ZwUiCommand

    Sets command text of the specified command.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [in] text command text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwUiCommandTextSet(const char *command, const char *text);

    /**
    @ingroup ZwUiCommand

    Gets icon name of the specified command.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [out] icon icon name
    @param [in] size the number of bytes of storage referenced by "icon"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwUiCommandIconGet(const char *command, char *icon, int size);

    /**
    @ingroup ZwUiCommand

    Sets icon of the specified command.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [in] icon icon name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwUiCommandIconSet(const char *command, const char *icon);

    /**
    @ingroup ZwUiCommand

    Gets enable or disable state of the specified command in the ribbon or menu.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [out] state command state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwUiCommandStateGet(const char *command, ezwCommandStateType *state);

    /**
    @ingroup ZwUiCommand

    Sets enable or disable state of the specified command in the ribbon or menu.
    Gets the command name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] command command name
    @param [in] state command state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwUiCommandStateSet(const char *command, ezwCommandStateType state);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_UI_COMMAND_H */
