/**
@file zwapi_pmi.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D PMI API  
*/

#pragma once
#ifndef zwapi_pmi_H /* this ifndef surrounds entire header */
#define zwapi_pmi_H

#include "zwapi_pmi_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name PMI Dimension Create */
    //====================================================================================================================
    /**
    @ingroup ZwPMIGeneral

    Creates a PMI label dimension in active part or assembly.  
    The leaderPoint.point will be projected into the reference entity, as long as leaderPoint.referenceEntityHandle is not NULL.

    @param [in] data data for creating PMI label dimension  
    @param [out] pmi PMI handle (input NULL to ignore)

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
    ZW_API_C ezwErrors ZwPMIDimensionLabelCreate(szwPMIDimensionLabel data, szwEntityHandle *pmi);

    /**
    @ingroup ZwPMIGeneral

    Creates a feature control symbol (FCS) in active part or assembly. 
    Function Guide: PMI -> Annotation -> Feature Control

    @note
    The caller is responsible to free the FCS by using ZwEntityHandleFree().

    @param [in] text the FCS text
    @param [in] leaderPoint the leader point, must be a point on the entity (input NULL to ignore)
    @param [in] location the location point
    @param [in] plane the placement plane of the FCS, must be a datum or planar face (input NULL to ignore)
    @param [out] FCS handle of the newly created FCS (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_STRING
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwPMIDimensionFeatureControlCreateByText(const char *text, szwPointOnEntity *leaderPoint, szwPointOnEntity location, szwEntityHandle *plane, szwEntityHandle *FCS);

    //====================================================================================================================
    /** @name PMI Text Create */
    //====================================================================================================================
    /**
    @ingroup ZwPMIText
    
    Creates a PMI balloon annotation in part.
    
    @note
    This function will create a feature.
    The caller is responsible to free the handle by using ZwEntityHandleFree().
    Function Guide: PMI -> Text -> Text Balloon
    
    @param [in] textPoint point coordinate of text placement point
    @param [in] text balloon string
    @param [in] imageFlag image flag: 1-image, 0-text
    @param [out] dimension handle of the dimension created (input NULL to ignore)
    
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
    
    @code
    szwPoint textPoint={...};
    char*text=...;
    int imageFlag=...;
    szwEntityHandle handle{};
    ZwFeatureTextBalloonCreate(textPoint,text,imageFlag,&handle);
    ...
    ZwEntityHandleFree(&handle);
    @endcode
    
    */
    ZW_API_C ezwErrors ZwFeatureTextBalloonCreate(szwPoint textPoint, const char *text, int imageFlag, szwEntityHandle *dimension);

    //====================================================================================================================
    /** @name PMI Discrete Data Query */
    //====================================================================================================================
    /**
    @ingroup ZwPMIDimension

    Gets discrete data of specified PMI dimension.

    @code
        szwEntityHandle entityHandles{};
        szwPMIDimensionDiscreteData data{};
        ZwPMIDimensionDiscreteDataGet(entityHandles, &data);
        ...
        ZwPMIDimensionDiscreteDataFree(&data);
    @endcode

    @note
    The calling procedure MUST deallocate the output list with ZwPMIDimensionDiscreteDataFree().

    @param [in] dimensionHandle handle of PMI dimension
    @param [out] data discrete data of PMI dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwPMIDimensionDiscreteDataGet(szwEntityHandle dimensionHandle, szwPMIDimensionDiscreteData *data);

    /**
    @ingroup ZwPMIDimension

    Frees the discrete data.

    @param [in] data discrete data of PMI dimension

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwPMIDimensionDiscreteDataFree(szwPMIDimensionDiscreteData *data);

    /**
    @ingroup ZwPMISymbol

    Gets discrete data of specified PMI symbol.

    @code
        szwEntityHandle entityHandles{};
        szwPMISymbolDiscreteData data{};
        ZwPMISymbolDiscreteDataGet(entityHandles, &data);
        ...
        ZwPMISymbolDiscreteDataFree(&data);
    @endcode

    @note The calling procedure MUST deallocate the output list with ZwPMISymbolDiscreteDataFree().

    @param [in] symbolHandle handle of PMI symbol
    @param [out] data discrete data of PMI symbol

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwPMISymbolDiscreteDataGet(szwEntityHandle symbolHandle, szwPMISymbolDiscreteData *data);

    /**
    @ingroup ZwPMISymbol

    Frees the discrete data.

    @param [in] data discrete data of symbol

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwPMISymbolDiscreteDataFree(szwPMISymbolDiscreteData *data);

    /**
    @ingroup ZwPMITable

    Gets discrete data of specified PMI table.

    @code
        szwEntityHandle entityHandles{};
        szwPMITableDiscreteData data{};
        ZwPMITableDiscreteDataGet(entityHandles, &data);
        ...
        ZwPMITableDiscreteDataFree(&data);
    @endcode

    @note
    The caller is responsible to free the data by using ZwPMITableDiscreteDataFree.  
    data->textData->numberText is the number of grids in the table.For example,
    for a 3*4 table,data->textData->textGroup->numberText is 12.  
    The grid of the table is numbered from left to right and from top to bottom.  
    data->textData->textList->textSegmentList[i] is the text information of i-th grid in th table.  
    data->textData->textList[i].numberText is the number of words in i-th grid,  
    it will be 0 if there are no words in this grid. And data.textData->textList[i].textSegmentList
    will be nullptr.  
    data->textData->textList[i].textSegmentList[j].textPointList is the coordinate
    point group of the j-th text segment in i-th grid.  
    data.textData->textList[i].textSegmentList[j].numberPoint is the number of points
    in above group.

    @param [in] tableHandle handle of PMI table
    @param [out] data discrete data of PMI table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwPMITableDiscreteDataGet(szwEntityHandle tableHandle, szwPMITableDiscreteData *data);
    
    /**
    @ingroup ZwPMITable

    Frees the table data.

    @param [in] data discrete data of table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwPMITableDiscreteDataFree(szwPMITableDiscreteData *data);

    //====================================================================================================================
    /** @name PMI Query */
    //====================================================================================================================
    /**
    @ingroup ZwPMIGeneral

    Gets matrix of alignment plane where the PMI is located.

    @param [in] pmiHandle handle of PMI
    @param [out] matrix matrix of alignment plane

    @code
        szwEntityHandle entityHandles{};
        szwMatrix mat{};
        ZwMatrixInit(&mat);
        ZwPMIAligmentPlaneGet(entityHandles, &mat);
    @endcode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPMIAligmentPlaneGet(szwEntityHandle pmiHandle, szwMatrix *matrix);

    /**
    @ingroup ZwPMIGeneral

    Get the views corresponding to PMI.

    This function allocates memory for the out via "viewHandleList". The calling procedure is responsible
    for deallocating the memory.

    @note
        A PMI can be attached to several views but that is not the default setting in ZW3D.
    If you want to attach a PMI to several views in ZW3D, you can switch to view manager, right-click
    'Views', and uncheck 'Only attach PMI in one view'. In this way, you can right-click the selected
    PMI and click 'attach' to choose which view to be attached.
        Please use 'ZwEntityHandleListFree' to free the memory.

    @param [in] handlePMI handle data of PMI
    @param [out] count the number of views
    @param [out] viewHandleList the handle data list of views

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR

    @code
        szwEntityHandle pHandlePMI{};
        ...
        int count = 0;
        szwEntityHandle *handleLists = nullptr;
        ...
        ZwPMIAttachedViewListGet(pHandlePMI, &count, &handleLists);
        ...
        ZwEntityHandleListFree(count, &handleLists);
    @endcode
    */
    ZW_API_C ezwErrors ZwPMIAttachedViewListGet(szwEntityHandle handlePMI, int *count, szwEntityHandle **viewHandleList);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* zwapi_pmi_H */
