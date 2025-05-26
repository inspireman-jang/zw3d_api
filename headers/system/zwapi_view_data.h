/**
@file zwapi_view_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures of View
*/

#pragma once
#ifndef ZW_API_VIEW_DATA_H
#define ZW_API_VIEW_DATA_H

#include "zwapi_util.h"

/**
@brief  align plane option of section with envelope, slice and 3 planes
@ingroup ZwViewData
*/
typedef enum ezwSectionViewOptionPlane
{
    ZW_SECTION_VIEW_TOP_PLANE    = 0, /**<@brief  activate to top plane */
    ZW_SECTION_VIEW_BACK_PLANE   = 1, /**<@brief  activate to back plane */
    ZW_SECTION_VIEW_RIGHT_PLANE  = 2, /**<@brief  activate to right plane */
    ZW_SECTION_VIEW_BOTTOM_PLANE = 3, /**<@brief  activate to bottom plane */
    ZW_SECTION_VIEW_FRONT_PLANE  = 4, /**<@brief  activate to front plane */
    ZW_SECTION_VIEW_LEFT_PLANE   = 5, /**<@brief  activate to left plane */
} ezwSectionViewOptionPlane;

/**
@brief  mode of section view
@ingroup ZwViewData
*/
typedef enum ezwSectionViewMode
{
    ZW_SECTION_VIEW_SECTION_AT_PLANE      = 0, /**<@brief  section at plane */
    ZW_SECTION_VIEW_SECTION_WITH_ENVELOPE = 1, /**<@brief  section with envelope */
    ZW_SECTION_VIEW_SECTION_WITH_SLICE    = 2, /**<@brief  section with slice */
    ZW_SECTION_VIEW_SECTION_WITH_PROFILE  = 3, /**<@brief  section with profile */
    ZW_SECTION_VIEW_SECTION_WITH_3_PLANES = 4, /**<@brief  section with 3 planes */
} ezwSectionViewMode;

/**
@brief align plane turn on/off in section view
@ingroup ZwViewData
*/
typedef enum ezwSectionViewAlignPlaneIsOn

{
    ZW_SECTION_VIEW_SECTION_ALIGN_PLANE_OFF = 0, /**<@brief  align plane off */
    ZW_SECTION_VIEW_SECTION_ALIGN_PLANE_ON  = 1, /**<@brief  align plane on */
} ezwSectionViewAlignPlaneIsOn;

/**
@brief  status of section view on/off
@ingroup ZwViewData
*/
typedef enum ezwSectionViewIsOn
{
    ZW_SECTION_VIEW_OFF = 0, /**<@brief  section is off */
    ZW_SECTION_VIEW_ON  = 1, /**<@brief  section is on */
} ezwSectionViewIsOn;

/**
@brief  the component of the section view is Included/excluded
@ingroup ZwViewData
*/
typedef enum ezwSectionViewComponentIsIncluded
{
    ZW_SECTION_VIEW_COMPONENT_EXCLUDED = 0, /**<@brief  the component is excluded */
    ZW_SECTION_VIEW_COMPONENT_INCLUDED = 1  /**<@brief  the component is included */
} ezwSectionViewComponentIsIncluded;

/**
/**
@brief  parameter of section view  with 3 planes mode
@ingroup ZwViewData
*/
typedef struct szwSectionWith3PlanesParameter
{
    ezwSectionViewAlignPlaneIsOn alignPlane1IsTurnOn; /**<@brief flag of align plane 1 is turn on of section with 3 planes */
    ezwSectionViewAlignPlaneIsOn alignPlane2IsTurnOn; /**<@brief flag of align plane 2 is turn on of section with 3 planes */
    ezwSectionViewAlignPlaneIsOn alignPlane3IsTurnOn; /**<@brief flag of align plane 3 is turn on of section with 3 planes */
    szwEntityHandle alignPlane1;                      /**<@brief handle of align plane 1 of section with 3 planes */
    szwEntityHandle alignPlane2;                      /**<@brief handle of align plane 2 of section with 3 planes */
    szwEntityHandle alignPlane3;                      /**<@brief handle of align plane 3 of section with 3 planes */
    double alignPlane1Offset;                         /**<@brief offset of align plane 1 of section with 3 planes */
    double alignPlane2Offset;                         /**<@brief offset of align plane 2 of section with 3 planes */
    double alignPlane3Offset;                         /**<@brief offset of align plane 3 of section with 3 planes */
} szwSectionWith3PlanesParameter;


/**
@brief  parameter of section plane attribute of the section view
@ingroup ZwViewData
*/
typedef struct szwSectionPlaneParameter
{
    szwEntityHandle profile;                             /**<@brief sketch handle of section with profile  */
    double startS;                                       /**<@brief start S of section with profile  */
    double endE;                                         /**<@brief end E of section with profile  */
    szwEntityHandle alignPlane;                          /**<@brief align plane handle of section with envelope, slice and 3 planes */
    ezwSectionViewOptionPlane optionPlane;               /**<@brief align plane option of section with envelope, slice and 3 planes */
    szwSectionWith3PlanesParameter threePlanesParameter; /**<@brief parameter of section with 3 planes mode */
} szwSectionPlaneParameter;

/**
@brief  parameter of section plane placement of the section view
@ingroup ZwViewData
*/
typedef struct szwSectionPlanePlacement
{
    double top;       /**<@brief top face offset of section with envelope */
    double front;     /**<@brief front face offset of section with envelope */
    double right;     /**<@brief right face offset of section with envelope */
    double left;      /**<@brief left face offset of section with envelope */
    double back;      /**<@brief back face offset of section with envelope */
    double bottom;    /**<@brief bottom face offset of section with envelope */
    double offset;    /**<@brief plane offset of section at plane and section with slice */
    double thickness; /**<@brief thickness of two faces of section with slice */
} szwSectionPlanePlacement;


/**
@brief attribute of section view
@ingroup  ZwViewData
*/
typedef struct szwSectionViewParameter
{
    ezwSectionViewMode sectionViewMode;      /**<@brief mode of section view */
    szwSectionPlaneParameter planeParameter; /**<@brief plane parameter of section view */
    szwSectionPlanePlacement planePlacement; /**<@brief plane placement of section view */
} szwSectionViewParameter;

 /**
  @brief interference option
  @ingroup ZwViewData
  */
typedef enum ezwSectionInterferenceOption
{
    ZW_SECTION_HIDE_INTERFERENCE    = 0, /**<@brief  Hide interference */
    ZW_SECTION_DISPLAY_INTERFERENCE = 1  /**<@brief  Display interference */
} ezwSectionInterferenceOption;

/**
 @brief hatch open option
 @ingroup ZwViewData
 */
typedef enum ezwSectionHatchOpenOption
{
    ZW_SECTION_HIDE_HATCH    = 0, /**<@brief  Hide hatch for non-closed shapes */
    ZW_SECTION_DISPLAY_HATCH = 1  /**<@brief  Display hatch for non-closed shapes */
} ezwSectionHatchOpenOption;

/**
 @brief move handle only option
 @ingroup ZwViewData
 */
typedef enum ezwSectionMoveOption
{
    ZW_SECTION_NOT_MOVE_ONLY = 0, /**<@brief  Not move handle only */
    ZW_SECTION_MOVE_ONLY     = 1  /**<@brief  Move handle only */
} ezwSectionMoveOption;

/**
 @brief show shape option
 @ingroup ZwViewData
 */
typedef enum ezwSectionShape
{
    ZW_SECTION_HIDE_SHAPE = 0, /**<@brief  Invisible Section Shape */
    ZW_SECTION_SHOW_SHAPE = 1  /**<@brief  show Section Shape */
} ezwSectionShape;

/**
 @brief choose hatch type
 @ingroup ZwViewData
 */
typedef enum ezwSectionHatchType
{
    ZW_SECTION_PART_COLOR    = 0, /**<@brief  Part color*/
    ZW_SECTION_SPECIFY_COLOR = 1  /**<@brief  specify color*/
} ezwSectionHatchType;

/**
 @brief choose hatch style
 @ingroup ZwViewData
 */
typedef enum ezwSectionHatchStyle
{
    ZW_SECTION_NO_CAP_OVERLAY = 0, /**<@brief  no cap overlay*/
    ZW_SECTION_GRID_OVERLAY   = 1, /**<@brief  grid overlay*/
    ZW_SECTION_HATCH_OVERLAY  = 2  /**<@brief  hatch overlay*/
} ezwSectionHatchStyle;

/**
 @brief section plane option
 @ingroup ZwViewData
 */
typedef enum ezwSectionPlaneOption
{
    ZW_SECTION_HIDE_PLANE    = 0, /**<@brief hide plane*/
    ZW_SECTION_DISPLAY_PLANE = 1  /**<@brief display plane*/
} ezwSectionPlaneOption;

/**
 @brief show handle option
 @ingroup ZwViewData
 */
typedef enum ezwSectionHandleOption
{
    ZW_SECTION_HIDE_HANDLE = 0, /**<@brief hide handle*/
    ZW_SECTION_SHOW_HANDLE = 1  /**<@brief show handle*/
} ezwSectionHandleOption;

/**
 @brief section slice option
 @ingroup ZwViewData
 */
typedef enum ezwSectionSliceOption
{
    ZW_SECTION_NOT_SLICE_ONLY = 0, /**<@brief not only show section slice*/
    ZW_SECTION_SLICE_ONLY     = 1  /**<@brief show section slice only*/
} ezwSectionSliceOption;

/**
 @brief section display frame option
 @ingroup ZwViewData
 */
typedef enum ezwSectionFrameOption
{
    ZW_SECTION_NO_CLIP_FRAME = 0, /**<@brief do not clip wireframe*/
    ZW_SECTION_CLIP_FRAME    = 1  /**<@brief clip wireframe*/
} ezwSectionFrameOption;

/**
 @brief section display curve attributes
 @ingroup ZwViewData
 */
typedef enum ezwSectionCurveOption
{
    ZW_SECTION_HIDE_CURVE    = 0, /**<@brief hide curves*/
    ZW_SECTION_DISPLAY_CURVE = 1  /**<@brief display curves*/
} ezwSectionCurveOption;

/**
 @brief section view global display attributes
 @ingroup ZwViewData
 */
typedef struct szwControlGlobalAttributes
{
    ezwSectionInterferenceOption displayInterference; /**<@brief choose if display interference*/
    ezwSectionHatchOpenOption displayNonclose;        /**<@brief choose if display hatch for non-closed shapes*/
    ezwSectionMoveOption moveHandleOnly;              /**<@brief choose if Move handle only*/
} szwControlGlobalAttributes;

/**
 @brief section view local display attributes
 @ingroup ZwViewData
 */
typedef struct szwControlLocalAttributes
{
    ezwSectionShape sectionShape;         /**<@brief choose if show Section Shape*/
    szwColor interference;                /**<@brief choose interference color*/
    ezwSectionHatchType hatchType;        /**<@brief choose hatch type*/
    szwColor hatchColor;                  /**<@brief choose hatch color*/
    ezwSectionHatchStyle hatchStyle;      /**<@brief choose hatch style*/
    double spacing;                       /**<@brief set spacing value*/
    double opaque;                        /**<@brief set opaque value*/
    ezwSectionPlaneOption displayPlane;   /**<@brief choose if display plane*/
    ezwSectionHandleOption displayHandle; /**<@brief choose if display handle */
    ezwSectionSliceOption displaySlice;   /**<@brief choose if display slice*/
    ezwSectionFrameOption displayFrame;   /**<@brief choose if clip frame*/
} szwControlLocalAttributes;

/**
 @brief section view curve attributes
 @ingroup ZwViewData
 */
typedef struct szwCurveAttributes
{
    ezwSectionCurveOption displayCurve; /**<@brief choose if display curve*/
    szwColor curveColor;                /**<@brief choose curve color*/
    ezwLineWidth curveWidth;            /**<@brief choose curve width*/
} szwCurveAttributes;

#endif ZW_API_VIEW_DATA_H
