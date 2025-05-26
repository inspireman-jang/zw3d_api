/**
@file zwapi_template_command.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Template Command Container API
*/

#pragma once
#ifndef ZW_API_TEMPLATE_COMMAND_H
#define ZW_API_TEMPLATE_COMMAND_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Template Field Operate */
    //====================================================================================================================
    /**
    @ingroup ZwTemplateCommand 

    This function can be used to add the entity list to the specified field of the
    specified data container. And if this field is defined as a list in the command
    template, these new entities will be appended to those entities already associated
    with the field. However, if the field is not defined as a list, no matter how many
    entities are entered, all the previous will be replaced by the last one.

    @note
    The command data container could be created by cvxDataInit().

    @param [in] idData id of data container
    @param [in] idField id of data field
    @param [in] count number of entities in the entity list
    @param [in] entityList the entity list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_STRING
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_DATA_ERROR

    @code
        int* idEnts = nullptr;
        szwEntityHandle* entityList = nullptr;
        int Count = 0;
        // some code to get the entities
        ....
        ZwMemoryAlloc(Count * sizeof(szwEntityHandle), (void **)&entityList);
        ZwEntityIdTransfer(Count, idEnts, entityList);
        ....
        ZwCommandParameterEntityAdd(idData, 1, Count, entityList);
        ...
        (void)ZwEntityHandleListFree(Count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandParameterEntityAdd(int idData, int idField, int count, const szwEntityHandle *entityList);

    /**
    @ingroup ZwTemplateCommand 

    This function can be used to log the direction to the specified field of the
    specified data container.

    @note
    The command data container could be created by cvxDataInit().

    @param [in] idData id of data container
    @param [in] idField id of data field
    @param [in] direction direction data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwCommandParameterDirectionSet(int idData, int idField, szwDirection direction);
    //====================================================================================================================
    /** @name Template Command Properties */
    //====================================================================================================================

    /**
    @ingroup ZwTemplateCommand 

    Gets the string of the &quot;options&quot; of the specified field for the specified template.

    @param [in] templateName template name
    @param [in] idField index of field
    @param [in] nBytes bytes of option string
    @param [out] optionsData option string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwTemplateCommandOptionsGet(const char *templateName, int idField, int nBytes, char *optionsData);

    /**
    @ingroup ZwTemplateCommand 

    Sets the string of the &quot;options&quot; of the specified field for the specified template.

    @param [in] templateName template name
    @param [in] idField index of field
    @param [in] optionsData option string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwTemplateCommandOptionsSet(const char *templateName, int idField, const char *optionsData);

    /**
    @ingroup ZwTemplateCommand 

    Gets the list mode of the specified field for the specified template.  

    @note
    The list mode is only useful for the 'Entity' & 'EntityList' fields, even the other types can get or set this 
    property, but actually makes no sense.  

    @param [in] templateName template name
    @param [in] idField index of field
    @param [out] isList list mode value, 0-only accepts one input, 1-accepts more than one entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CMMD_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwTemplateCommandListModeGet(const char *templateName, int idField, int *isList);

    /**
    @ingroup ZwTemplateCommand 

    Sets the list mode of the specified field for the specified template.

    @note
    The list mode is only useful for the 'Entity' & 'EntityList' fields, even the other types can get or set this 
    property, but actually makes no sense.  

    @param [in] templateName template name
    @param [in] idField index of field
    @param [in] isList list mode value, 0-only accepts one input, 1-accepts more than one entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwTemplateCommandListModeSet(const char *templateName, int idField, int isList);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // !ZW_API_TEMPLATE_COMMAND_H
