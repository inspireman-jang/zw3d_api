/**
@file zwapi_sketch_wireframe_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Sketch Wireframe
*/

#pragma once
#ifndef ZW_API_SKETCH_WIREFRAME_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_SKETCH_WIREFRAME_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sketch Wireframe Data */
    //====================================================================================================================
    /**
    @brief  sketch arc create data Three Points
    @ingroup ZwSketchData
    */
    typedef struct szwSketchArcCreateByThreePoints
    {
        szwPoint2 start;   /**<@brief  1st point  */
        szwPoint2 end;     /**<@brief  2st point */
        szwPoint2 through; /**<@brief  through point */
        int isG2Arc;       /**<@brief   whether to use G2(curvature continuous) arc
                                     0 - default to use G2 arc
                                     1 - not use G2 arc */
    } szwSketchArcCreateByThreePoints;

    /**
    @brief  sketch circle create data By Radius or Diameter
    @ingroup ZwSketchData
    */
    typedef struct szwSketchCircleCreateByRadius
    {
        szwPoint2 center; /**<@brief  center point  */
        double radius;    /**<@brief  radius  */
    } szwSketchCircleCreateByRadius;

    /**
    @brief ready text fit method
    @ingroup ZwSketchData
    */
    typedef enum ezwReadyTextFitMethod
    {
        ZW_READY_TEXT_FIT_METHOD_NONE,           /**<@brief none */
        ZW_READY_TEXT_FIT_METHOD_WORD_WRAP,      /**<@brief word wrap */
        ZW_READY_TEXT_FIT_METHOD_AUTO_SIZE_TEXT, /**<@brief auto size text */
        ZW_READY_TEXT_FIT_METHOD_AUTO_FIT,       /**<@brief auto fit */
    } ezwReadyTextFitMethod;

    /**
    @brief text vertical alignment
    @ingroup ZwBasicData
    */
    typedef enum ezwReadyTextVerticalAlign
    {
        ZW_READY_TEXT_ALIGNMENT_CAP = 2, /**<@brief  cap alignment */
        ZW_READY_TEXT_ALIGNMENT_HALF,    /**<@brief  half alignment */
        ZW_READY_TEXT_ALIGNMENT_BASE,    /**<@brief  base alignment */
    } ezwReadyTextVerticalAlign;

    /**
    @brief The text alignment of sketch ready text
    @ingroup ZwSketchData
    */
    typedef struct szwSketchReadyTextAlignment
    {
        ezwReadyTextFitMethod fitMethod;    /**<@brief  fit method*/
        ezwTextHorizontalAlign horizontal;  /**<@brief  horizontal */
        ezwReadyTextVerticalAlign vertical; /**<@brief  vertical */
    } szwSketchReadyTextAlignment;

    /**
    @brief The settings of on curve text data of sketch ready text
    @ingroup ZwSketchData
    */
    typedef struct szwSketchOnCurveTextSettings
    {
        szwEntityHandle curveHandle; /**<@brief  curve handle data */
        int horizontalFlip;          /**<@brief  Horizontal Flip */
        int mirror;                  /**<@brief  Mirror */
        int reverseCurve;            /**<@brief  Reverse curve */
        int placeTextAtOrigin;       /**<@brief  Place text at origin */
        int reduceTextData;          /**<@brief  Reduce text data */
        int keepTextShape;           /**<@brief  Keep text shape */
    } szwSketchOnCurveTextSettings;

    /**
    @brief The settings of box text data of sketch ready text
    @ingroup ZwSketchData
    */
    typedef struct szwSketchBoxTextSettings
    {
        double widthSetting;  /**<@brief  Setting Width */
        double heightSetting; /**<@brief  Setting Height */
        int horizontalFlip;   /**<@brief  Horizontal Flip */
        int mirror;           /**<@brief  Mirror */
    } szwSketchBoxTextSettings;

    /**
    @brief data of ready sketch text
    @ingroup ZwSketchData
    */
    typedef struct szwReadyText
    {
        ezwReadyTextMethods methods; /**<@brief  ready text methods */

        szwPoint origin;     /**<@brief  text position */
        szwPoint alignPoint; /**<@brief  align Point, only used when methods is ZW_BOX */
        char *textString;    /**<@brief  text string */

        szwReadyTextFont font;                  /**<@brief  the front settings of Sketch ready text */
        szwSketchTextForm text;                 /**<@brief  the text form setting of sketch ready text */
        szwSketchReadyTextAlignment alignments; /**<@brief  the text alignment of sketch ready text */

        union uzwSketchReadyTextSettings /**<@brief union of sketch text data */
        {
            szwSketchOnCurveTextSettings onCurveSettings; /**<@brief  the settings of on curve text data of sketch ready text */
            szwSketchBoxTextSettings boxSettings;         /**<@brief  the settings of box text data of sketch ready text */
        } settings;
    } szwReadyText;

    /**
    @brief data to create ready text
    @ingroup ZwSketchData
    */
    typedef struct szwReadyTextCreate
    {
        ezwReadyTextMethods methods; /**<@brief  ready text methods */

        szwPointOnEntity origin;     /**<@brief  text position */
        szwPointOnEntity alignPoint; /**<@brief  Align Point, only when methods == ZW_BOX */
        char *textString;            /**<@brief  text string */

        szwReadyTextFont font;                  /**<@brief  the front settings of Sketch ready text */
        szwSketchTextForm text;                 /**<@brief  the text form setting of sketch ready text */
        szwSketchReadyTextAlignment alignments; /**<@brief  the text alignment of sketch ready text */

        union uzwSketchReadyTextSettings /**<@brief union of sketch text data */
        {
            szwSketchOnCurveTextSettings onCurveSettings; /**<@brief  the settings of on curve text data of sketch ready text */
            szwSketchBoxTextSettings boxSettings;         /**<@brief  the settings of box text data of sketch ready text */
        } settings;
    } szwReadyTextCreate;


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SKETCH_WIREFRAME_DATA_H */
