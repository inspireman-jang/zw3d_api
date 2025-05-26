/**
@file zwapi_pmi_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for PMI objects, including dimension, symbol and table.
*/
/**
@defgroup zwapi_pmi_data PMI Data
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the functions
for PMI objects, including dimension, symbol and table.
*/

#pragma once
#ifndef zwapi_pmi_data_H /* this ifndef surrounds entire header */
#define zwapi_pmi_data_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name PMI  Symbol data */
    //====================================================================================================================
    /**
    @brief symbol object type
    @ingroup zwapi_pmi_data
    */
    typedef enum evxSymbolType
    {
        VX_SYM_ALL       = -1, /**<@brief  any symbol */
        VX_SYM_USER      = 0,  /**<@brief  user defined symbol */
        VX_SYM_SURF      = 1,  /**<@brief  surface finish */
        VX_SYM_WELD      = 2,  /**<@brief  weld */
        VX_SYM_IMAGE     = 3,  /**<@brief  image */
        VX_SYM_ORIGIN    = 4,  /**<@brief  origin symbol */
        VX_SYM_BEAD      = 5,  /**<@brief  caterpillar */
        VX_SYM_ENDTRT    = 6,  /**<@brief  end treatment */
        VX_SYM_OPEN_LINK = 7,  /**<@brief  OLE object */
        VX_SYM_HOLE_MARK = 8,  /**<@brief  hole mark */
    } evxSymbolType;

    //====================================================================================================================
    /** @name PMI Symbol data */
    //====================================================================================================================
    /**
    @brief symbol object type
    @ingroup ZwPMIData
    */
    typedef enum ezwSymbolType
    {
        ZW_SYMBOL_ALL          = -1, /**<@brief  any symbol */
        ZW_SYMBOL_USER         = 0,  /**<@brief  user defined symbol */
        ZW_SYMBOL_SURFACE      = 1,  /**<@brief  surface finish */
        ZW_SYMBOL_WELD         = 2,  /**<@brief  weld */
        ZW_SYMBOL_IMAGE        = 3,  /**<@brief  image */
        ZW_SYMBOL_ORIGIN       = 4,  /**<@brief  origin symbol */
        ZW_SYMBOL_CATERPILLAR  = 5,  /**<@brief  caterpillar */
        ZW_SYMBOL_ENDTREATMENT = 6,  /**<@brief  end treatment */
        ZW_SYMBOL_OPEN_LINK    = 7,  /**<@brief  OLE object */
        ZW_SYMBOL_HOLE_MARK    = 8,  /**<@brief  hole mark */
    } ezwSymbolType;

    /**
    @brief symbol element type
    @ingroup ZwPMIData
    */
    typedef enum ezwSymbolEntityType
    {
        ZW_SYMBOL_ENTITY_POINT = 1,  /**<@brief  point */
        ZW_SYMBOL_ENTITY_LINE,       /**<@brief  line */
        ZW_SYMBOL_ENTITY_ARC,        /**<@brief  arc */
        ZW_SYMBOL_ENTITY_POLY,       /**<@brief  poly line */
        ZW_SYMBOL_ENTITY_TEXT,       /**<@brief  text */
        ZW_SYMBOL_ENTITY_TERMINATER, /**<@brief  terminator arrow */
        ZW_SYMBOL_ENTITY_DASH,       /**<@brief  dash */
    } ezwSymbolEntityType;

    //====================================================================================================================
    /** @name PMI discrete Data */
    //====================================================================================================================
    /**
    @brief discrete data of line in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMILineDiscreteData
    {
        szwPoint startPoint; /**<@brief  start point */
        szwPoint endPoint;   /**<@brief  end point */
    } szwPMILineDiscreteData;

    /**
    @brief discrete data of polyline in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMIPolylineDiscreteData
    {
        int numberPoint;     /**<@brief  number of point in list */
        szwPoint *pointList; /**<@brief  pointer to the list of points */
    } szwPMIPolylineDiscreteData, szwPMIArcDiscreteData, szwPMICircleDiscreteData;

    /**
    @brief discrete data of terminator point in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMITerminatorData
    {
        szwPoint terminatorPoints[3]; /**<@brief  list of terminator point */
    } szwPMITerminatorData;

    /**
    @brief discrete data of center mark in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMICenterMarkData
    {
        szwPMILineDiscreteData line; /**<@brief  center mark line */
    } szwPMICenterMarkData;

    /**
    @brief discrete data of text segments point in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMITextSegmentPointDiscreteData
    {
        int numberPoint;         /**<@brief  number of text segment point in list */
        szwPoint *textPointList; /**<@brief  text segment point list */
    } szwPMITextSegmentPointDiscreteData;

    /**
    @brief discrete data of text segments in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMITextSegmentDiscreteData
    {
        int numberSegment;                                   /**<@brief  number of text segment in list */
        szwPMITextSegmentPointDiscreteData *textSegmentList; /**<@brief  text segment list */
    } szwPMITextSegmentDiscreteData;

    /**
    @brief discrete data of text in PMI
    @ingroup ZwPMIData
    */
    typedef struct szwPMITextDiscreteData
    {
        int numberText;                          /**<@brief  number of text in list */
        szwPMITextSegmentDiscreteData *textList; /**<@brief  text list */
    } szwPMITextDiscreteData;

    /**
    @brief discrete data of PMI dimension
    @ingroup ZwPMIData
    */
    typedef struct szwPMIDimensionDiscreteData
    {
        int numberLine;                           /**<@brief  number of line in list */
        szwPMILineDiscreteData *lineList;         /**<@brief  line list */
        int numberPolyLine;                       /**<@brief  number of polyline in list */
        szwPMIPolylineDiscreteData *polylineList; /**<@brief  polyline list */
        int numberCircle;                         /**<@brief  number of circle in list */
        szwPMICircleDiscreteData *circleList;     /**<@brief  circle list */
        int numberArc;                            /**<@brief  number of arc in list */
        szwPMIArcDiscreteData *arcList;           /**<@brief  arc list */
        int numberText;                           /**<@brief  number of text in list */
        szwPMITextDiscreteData *textGroup;        /**<@brief  text group */
        int numberTerminator;                     /**<@brief  number of terminator point in list */
        szwPMITerminatorData *terminatorList;     /**<@brief  terminator point list */
        int numberCenterMark;                     /**<@brief  number of center mark line in list */
        szwPMICenterMarkData *centerMarkList;     /**<@brief  center mark */
    } szwPMIDimensionDiscreteData;

    /**
    @brief discrete data of PMI symbol entity
    @ingroup ZwPMIData
    */
    typedef struct szwPMISymbolEntityDiscreteData
    {
        ezwSymbolEntityType type; /**<@brief  type of symbol entity(ezwSymbolEntityType) */
        union
        {
            szwPoint point;                      /**<@brief  point data */
            szwPMILineDiscreteData line;         /**<@brief  line data */
            szwPMIArcDiscreteData arc;           /**<@brief  arc data */
            szwPMIPolylineDiscreteData polyLine; /**<@brief  poly line */
            szwPMITerminatorData terminator;     /**<@brief  terminator arrow */
            szwPMITextSegmentDiscreteData text;  /**<@brief  text */
        } entity;
    } szwPMISymbolEntityDiscreteData;

    /**
    @brief discrete data of PMI symbol
    @ingroup ZwPMIData
    */
    typedef struct szwPMISymbolDiscreteData
    {
        evxSymbolType typeSymbol;                 /**<@brief  type of symbol(evxSymbolType) */
        int count;                                /**<@brief  number of data in list */
        szwPMISymbolEntityDiscreteData *dataList; /**<@brief  symbol data list */
    } szwPMISymbolDiscreteData;


    /**
    @brief discrete data of PMI table
    @ingroup ZwPMIData
    */
    typedef struct szwPMITableDiscreteData
    {
        int numberLine;                   /**<@brief  number of line in list */
        szwPMILineDiscreteData *lineList; /**<@brief  line list */
        szwPMITextDiscreteData *textData; /**<@brief  data of table text */
    } szwPMITableDiscreteData;

    /**
    @brief data of PMI label dimension
    @ingroup ZwPMIData
    */
    typedef struct szwPMIDimensionLabel
    {
        szwPointOnEntity leaderPoint; /**<@brief  leader point */
        szwPointOnEntity textPoint;   /**<@brief  the point to locate the dimension text. */
        char *text;                   /**<@brief  label text */
        szwEntityHandle plane;        /**<@brief  a plane (datum or planar face) to associate with the annotation text and/or dimensions. (use default view plane when innerData is NULL)  
                                          Annotation dimensions will be placed on a plane that passes through the defining points or lines and that is parallel to this plane. */
    } szwPMIDimensionLabel;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_PMI_DATA_H */
