/**
@file zwapi_history_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of History.
*/

#pragma once
#ifndef ZW_API_HISTORY_DATA_H
#define ZW_API_HISTORY_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name History Data */
    //====================================================================================================================
    /**
    @brief The type of delete the specified operations from the history of the active part
    @ingroup ZwHistoryData
    */
    typedef enum ezwHistoryDeleteType
    {
        ZW_PROMPT_TO_USER              = 0, /**<@brief  prompt to the user    */
        ZW_DELETE_ASSOCIATED_OPERATION = 1, /**<@brief  auto delete associated history operations   */
        ZW_SUPPRESS_FAILED_FEATURE     = 2, /**<@brief  auto suppress failed feature */
    } ezwHistoryDeleteType;

    /**
    @brief The type of get the specified operations from the history of the active part
    @ingroup ZwHistoryData
    */
    typedef enum ezwHistoryOperationGetType
    {
        ZW_OPERATION_PLAYED     = 0, /**<@brief  get history operations that have been played      */
        ZW_OPERATION_NOT_PLAYED = 1, /**<@brief  get history operations that have not been played     */
        ZW_OPERATION_ALL        = 2, /**<@brief  get played and unplayed history operations */
    } ezwHistoryOperationGetType;

    /**
    @brief suppress status of entity on history tree
    @ingroup ZwHistoryData
    */
    typedef enum ezwSuppressStatus
    {
        ZW_SUPPRESS_STATUS_UNSUPPRESSED           = 0, /**<@brief  unsuppressed */
        ZW_SUPPRESS_STATUS_MANUAL_SUPPRESSED      = 1, /**<@brief  manually suppressed */
        ZW_SUPPRESS_STATUS_AUTO_SUPPRESSED        = 2, /**<@brief  automatically suppressed due to the failure of regen */
        ZW_SUPPRESS_STATUS_CONDITIONAL_SUPPRESS   = 3, /**<@brief  conditional suppress */
        ZW_SUPPRESS_STATUS_CAN_SUPPRESS           = 3, /**<@brief  this element has been deprecated */
        ZW_SUPPRESS_STATUS_CONDITIONAL_UNSUPPRESS = 4, /**<@brief  conditional unsuppress */
    } ezwSuppressStatus;

    /*
    @brief History operation to copy or cut
    @ingroup ZwHistoryData
    */
    typedef enum ezwHistoryClipOption
    {
        ZW_HISTORY_CLIP_COPY = 0, /* <@brief  copy the entities */
        ZW_HISTORY_CLIP_CUT  = 1, /* <@brief  cut the entities */
    } ezwHistoryClipOption;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // !ZW_API_HISTORY_DATA_H
