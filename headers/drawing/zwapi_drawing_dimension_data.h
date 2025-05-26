/**
@file zwapi_drawing_dimension_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the functions
for Drawing Dimension objects.
*/

#pragma once
#ifndef ZW_API_DRAWING_DIMENSION_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_DIMENSION_DATA_H

#include "zwapi_util.h"
#include "zwapi_dimension_data.h"
#include "zwapi_drawing_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension Data */
    //====================================================================================================================
    /**
    @brief the boundary type of plane and feature indicator 
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingBoundaryType
    {
        ZW_ORIENTATION_PLANE_FRAME,  /**<@brief  orientation plane frame */
        ZW_INTERSECTING_PLANE_FRAME, /**<@brief  intersecting plane frame */
        ZW_COMBINED_PLANE_FRAME,     /**<@brief  combined plane frame */
        ZW_DIRECTION_ELEMENT_FRAME,  /**<@brief  direction element frame */
    } ezwDrawingBoundaryType;

    /**
    @brief the feature symbol of plane and feature indicator 
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingFeatureSymbol
    {
        ZW_FEATURE_SYMBOL_PARALLELISM,      /**<@brief  parallelism */
        ZW_FEATURE_SYMBOL_PERPENDICULARITY, /**<@brief  perpendicularity */
        ZW_FEATURE_SYMBOL_ANGULARITY,       /**<@brief  angularity */
        ZW_FEATURE_SYMBOL_CIRCULAR_RUNOUT,  /**<@brief  circular run-out */
        ZW_FEATURE_SYMBOL_SYMMETRY,         /**<@brief  symmetry */
    } ezwDrawingFeatureSymbol;

    /**
    @brief plane and feature indicator data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingPlaneAndFeatureIndicator
    {
        ezwDrawingBoundaryType type;    /**<@brief  boundary type */
        ezwDrawingFeatureSymbol symbol; /**<@brief  feature symbol */
        zwString1024 datum;             /**<@brief  datum */
    } szwDrawingPlaneAndFeatureIndicator;

    /**
    @brief drawing feature control frame data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingFeatureControlFrame
    {
        ezwGeometricCharacteristic symbol;                            /**<@brief  geometric characteristic symbol */
        zwString1024 tolerance1;                                      /**<@brief  the first tolerance */
        zwString1024 tolerance2;                                      /**<@brief  the second tolerance */
        zwString1024 mainDatum;                                       /**<@brief  main datum */
        zwString1024 secondDatum;                                     /**<@brief  second datum */
        zwString1024 thirdDatum;                                      /**<@brief  third datum */
        szwDrawingPlaneAndFeatureIndicator *planeAndFeatureIndicator; /**<@brief  plane and feature */
    } szwDrawingFeatureControlFrame;

    /**
    @brief drawing feature control data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingFeatureControlData
    {
        int count;                             /**<@brief  number of feature control frames */
        szwDrawingFeatureControlFrame *frames; /**<@brief  list of feature control frame data */

        zwString1024 topAdjacentDimension;    /**<@brief  top adjacent dimension */
        zwString1024 leftAdjacentDimension;   /**<@brief  left adjacent dimension */
        zwString1024 rightAdjacentDimension;  /**<@brief  right adjacent dimension */
        zwString1024 bottomAdjacentDimension; /**<@brief  bottom adjacent dimension */
    } szwDrawingFeatureControlData;

    /**
    @brief drawing hole callout dimension shape type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingHoleCalloutType
    {
        ZW_HOLE_CALLOUT_SHAPE_RADIAL, /**<@brief  radial dimension type */
        ZW_HOLE_CALLOUT_SHAPE_LINEAR, /**<@brief  linear dimension type */
    } ezwDrawingHoleCalloutType;
    
    /**
    @brief drawing hole callout dimension hole data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingHoleCalloutHole
    {
        szwEntityHandle hole; /**<@brief  hole projection curve */
        szwPoint2 *textPoint; /**<@brief  dimension text placement point, input nullptr to automatically placed in the right upper point */
    } szwDrawingHoleCalloutHole;

    /**
    @brief drawing hole callout element
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingHoleCalloutElementMethod
    {
        ZW_SPECIFIED_CALLOUT_ELEMENTS,  /**<@brief  by callout elements */
        ZW_DEFAULT_CALLOUT_FORMAT_TEXT, /**<@brief  by callout format text: default */
        ZW_DEPTH_FROM_FEATURE,          /**<@brief  by callout format text: depth from feature */
    } ezwDrawingHoleCalloutElementMethod;

    /**
    @brief drawing hole callout dimension data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingHoleCalloutData
    {
        ezwDrawingHoleCalloutType type;   /**<@brief  hole callout shape type */
        szwEntityHandle viewHandle;       /**<@brief  view handle */
        int count;                        /**<@brief  number of holes */
        szwDrawingHoleCalloutHole *holes; /**<@brief  list of holes */
        int ignoreDuplicateHole;          /**<@brief  whether to ignore duplicate hole callout */

        ezwDrawingHoleCalloutElementMethod elementMethod; /**<@brief  hole callout elements configuration */
        unsigned int holeElements;                        /**<@brief  hole callout elements by ezwHoleCalloutElement combined, used when elementMethod is ZW_SPECIFIED_CALLOUT_ELEMENTS,
                                                                      default value: ZW_HOLE_ELEMENT_ALL,
                                                                      refer to the following method for multiple elements: ZW_HOLE_ELEMENT_QUALITY | ZW_HOLE_ELEMENT_DIAMETER */
    } szwDrawingHoleCalloutData;

    /**
    @brief dimension Line type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDimensionLineType
    {
        ZW_DIMENSION_LINE_HORIZONTAL = 1, /**<@brief  horizontal dimension */
        ZW_DIMENSION_LINE_VERTICAL   = 2, /**<@brief  vertical dimension */
        ZW_DIMENSION_LINE_ALIGNED    = 3, /**<@brief  aligned dimension */
        ZW_DIMENSION_LINE_ROTATION   = 4, /**<@brief  rotated dimension */
        ZW_DIMENSION_LINE_PROJECTION = 5, /**<@brief  projected dimension */
        ZW_DIMENSION_LINE_ORDINATE   = 6, /**<@brief  ordinate dimension, only used in ZwDrawingDimensionOrdinateCreate:
                                               create a Line ordinate horizontal dimension groups
                                               and the Line ordinate vertical dimension groups.*/
    } ezwDimensionLineType;

    /**
    @brief dimension line data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingDimensionLineData
    {
        ezwDimensionLineType type;    /**<@brief  type of dimension default value:horizontal method */
        szwPointOnEntity firstPoint;  /**<@brief  first point */
        szwPointOnEntity secondPoint; /**<@brief  second point, this param won't take effect in ZwDrawingDimensionOrdinateCreate */
        szwPointOnEntity textPoint;   /**<@brief  text point: to locate the dimension text */

        double angle;              /**<@brief  dimension angle.
                                      if type = ZW_DIMENSION_LINE_ROTATION, it is the angle between target line and vertical line,
                                      other type can be ignored */
        szwEntityHandle alignLine; /**<@brief  the line that dimension align on.
                                      if type = ZW_DIMENSION_LINE_PROJECTION, the point is on the project line, can regard as the entity of project line,
                                      other type can be ignored */
    } szwDrawingDimensionLineData;

    /**
    @brief drawing ordinate dimension data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingDimensionOrdinate
    {
        szwDrawingDimensionLineData referenceData; /**<@brief  Line constraint dimension, 6 type of line dimension */
        int numberEntity;                          /**<@brief  no. of entity in list */
        szwPointOnEntity *entityList;              /**<@brief  list of entity */
        int reverseAxis1;                          /**<@brief  reverse direction, change the direction of increment of number(to positive or negative) default value:0 */
        int reverseAxis2;                          /**<@brief  reverse direction, change the direction of increment of number(to positive or negative) default value:0
                                                      taking effect only when type is ZW_DIMENSION_LINE_ORDINATE */
        szwEntityHandle *shareOriginEntity;        /**<@brief  Share origin (Group dimension), NULL to ignore */
        szwPointOnEntity textPoint[2];             /**<@brief  Horizontal(textPoint[0]) and Vertical(textPoint[1]) text point,
                                                      taking effect only when refereceData.type is ZW_DIMENSION_LINE_ORDINATE,
                                                      and referenceData.textPoint will be ignored in this situation. */
    } szwDrawingDimensionOrdinate;
    
    /**
    @brief auto dimension include
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwAutoInclude
    {
        ZW_DIMENSION_AUTO_INCLUDE_INVALID            = 0x00000000, /**<@brief  all is not valid */
        ZW_DIMENSION_AUTO_INCLUDE_ARC                = 0x00000001, /**<@brief  Include arc */
        ZW_DIMENSION_AUTO_INCLUDE_CIRCLE             = 0x00000002, /**<@brief  Include circle */
        ZW_DIMENSION_AUTO_INCLUDE_HOLE               = 0x00000004, /**<@brief  Include hole */
        ZW_DIMENSION_AUTO_INCLUDE_LINE               = 0x00000008, /**<@brief  Include line */
        ZW_DIMENSION_AUTO_INCLUDE_HOLE_CALLOUT       = 0x00000010, /**<@brief  Include Hole callout  */
        ZW_DIMENSION_AUTO_INCLUDE_CYLIND_DIMENSIONS  = 0x00000020, /**<@brief  Include cylindrical dimensions */
        ZW_DIMENSION_AUTO_INCLUDE_MAXIMUM_DIMENSIONS = 0x00000040, /**<@brief  Include maximum dimensions */
        ZW_DIMENSION_AUTO_INCLUDE_VALID              = 0xFFFFFFFF  /**<@brief  all is valid */
    } ezwAutoInclude;

    /**
    @brief select geometry entity type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwAutoEntityType
    {
        ZW_DIMENSION_AUTO_ENTITY_ALL = 0,    /**<@brief  entity type is all */
        ZW_DIMENSION_AUTO_ENTITY_ARC_CIRCLE, /**<@brief  entity type is all arc/circle */
        ZW_DIMENSION_AUTO_ENTITY_PICKED      /**<@brief  entity type is picked by user */
    } ezwAutoEntityType;

    /**
    @brief auto dimension type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwAutoDimensionType
    {
        ZW_DIMENSION_AUTO_BASELINE         = 0, /**<@brief  baseline */
        ZW_DIMENSION_AUTO_CONTINUOUS       = 1, /**<@brief  continuous */
        ZW_DIMENSION_AUTO_ORDINATE         = 2, /**<@brief  ordinate dimension */
        ZW_DIMENSION_AUTO_LABEL_COORDINATE = 3, /**<@brief  label ordinate dimension */
    } ezwAutoDimensionType;

    /**
    @brief dimension position/placement
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwAutoPlacement
    {
        ZW_DIMENSION_VIEW_ABOVE_LEFT  = 0, /**<@brief  left or above of view */
        ZW_DIMENSION_VIEW_BELOW_RIGHT = 1, /**<@brief  right or below of view */
        ZW_DIMENSION_VIEW_BOTH        = 2, /**<@brief  both of view */
    } ezwAutoPlacement;

    /**
    @brief dimension position
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwAutoSet
    {
        int enable;                      /**<@brief  szwAutoSet enabled or not */
        ezwAutoDimensionType type;       /**<@brief  select auto dimension type */
        szwPointOnEntity referencePoint; /**<@brief  reference point, used when enable is 1*/
        ezwAutoPlacement viewType;       /**<@brief  dimensions position / placement, default value:ZW_DIMENSION_VIEW_BELOW_RIGHT*/
        int asGroup;                     /**<@brief  1:auto dimensions are as group dimension* 0:not, default value:1*/
    } szwAutoSet;

    /**
    @brief auto dimension data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwAutoDimensionData
    {
        ezwAutoEntityType entityType;   /**<@brief  select entity type, default value:ZW_DIMENSION_AUTO_ENTITY_ALL*/
        int entityCount;                /**<@brief  entities count.
                                          if type = ZW_DIMENSION_AUTO_ENTITY_PICKED, number of entities need to be created dimension,
                                          other type can be 0 */
        szwEntityHandle *entityList;    /**<@brief  entity handle list.
                                          if type = ZW_DIMENSION_AUTO_ENTITY_PICKED, list handles of entities need to be created dimension,
                                          other type can be null */
        unsigned int includeAuto;       /**<@brief see ezwAutoInclude, whether to include arc, circle, hole, line, R/hole callout, cylindrical
                                          dimensions and maximum dimensions(0 = no, 1 = yes) */
        int checkOrigin;                /**<@brief  origin check flag, default value:1*/
        szwPointOnEntity pointOrigin;   /**<@brief  origin reference point, member critPnt should be entity critical point */
        szwAutoSet horizontalDimension; /**<@brief  horizontal dimensions position/placement */
        szwAutoSet verticalDimension;   /**<@brief  vertical dimensions position/placement */
    } szwAutoDimensionData;
	
    /**
    @brief Center Line type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwCenterLineType
    {
        ZW_CENTERLINE_BASE_ON_CURVE     = 1, /**<@brief  draw by two lines(Based to curve) */
        ZW_CENTERLINE_BASE_ON_PICKPOINT = 2, /**<@brief  draw by two points(Based on pick point) */
    } ezwCenterLineType;

    /**
    @brief Center Mark type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwCenterMarkType
    {
        ZW_CENTER_MARK_EXTENSION_NONE     = 1, /**<@brief  no extension line */
        ZW_CENTER_MARK_EXTENSION_LONGDASH = 2, /**<@brief  long dash extension line */
        ZW_CENTER_MARK_EXTENSION_DASH     = 3, /**<@brief  short dash extension line */
    } ezwCenterMarkType;

    /**
    @brief Center Mark Settings
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwCenterDimensionAttribute
    {
        ezwCenterMarkType centerMarkType;    /**<@brief center mark type, default : ZW_CENTER_MARK_EXTENSION_LONGDASH. Only used in ZwDrawingDimensionCenterMarkCreate().  */
        int isUseIndividuallyExtension;      /**<@brief use individually extension, default : 1*/
        int isCenterMarkScalesWithViewScale; /**<@brief use individually extension, default : 1. Only used in ZwDrawingDimensionCenterMarkCreate(). */
        double dash;                         /**<@brief  center line/mark size (short dash), default value:4.254534*/
        double overRun;                      /**<@brief  extension lines overrun, default value:3.06324*/
        double gap;                          /**<@brief  extension lines break length (gap), default value:1.5*/
        ezwColor color;                      /**<@brief  line color, default: ZW_COLOR_DARK_BLUE */

        ezwLineWidth lineWidth; /**<@brief  line width, default: ZW_WIDTH_018 */
        double scaleFactor;     /**<@brief  overall scale factor, default value:1*/


    } szwCenterDimensionAttribute;

    /**
    @brief Center Line
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingCenterLine
    {
        ezwCenterLineType dimensionType;              /**<@brief  dimension type */
        szwPointOnEntity startPoint;                  /**<@brief  start point.
                                     if dimensionType = ZW_CENTERLINE_BASE_ON_CURVE, the start point is regarded as the entity line of the point,
                                     if dimensionType = ZW_CENTERLINE_BASE_ON_PICKPOINT, it is the start point of centerline */
        szwPointOnEntity endPoint;                    /**<@brief  end point.
                                     if type = ZW_CENTERLINE_BASE_ON_CURVE, the end point is regarded as the entity line of the point,
                                     if type = ZW_CENTERLINE_BASE_ON_PICKPOINT, it is the end point of centerline */
        szwCenterDimensionAttribute *centerDimension; /**<@brief  option parameter: center dimension attribute.( NULL to use default value ) */
    } szwDrawingCenterLine;

    /**
    @brief Line Dimension text type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwLineDimensionTextType
    {
        ZW_LINE_DIMENSION_TEXT_TYPE_VALUE     = 1, /**<@brief  value */
        ZW_LINE_DIMENSION_TEXT_TYPE_USER_TEXT = 2, /**<@brief user text  */

    } ezwLineDimensionTextType;

    /**
    @brief Line Dimension text placement
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwLineDimensionTextPlacement
    {
        ZW_LINE_DIMENSION_TEXT_AUTOMATIC_PLACEMENT = 1, /**<@brief  automatic placement */
        ZW_LINE_DIMENSION_TEXT_MANUAL_PLACEMENT    = 2, /**<@brief manual placement  */
    } ezwLineDimensionTextPlacement;

    /**
    @brief text of line dimension
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLineDimensionText
    {
        ezwLineDimensionTextType textType;       /**<@brief  text type, default: ZW_LINE_DIMENSION_TEXT_TYPE_VALUE */
        ezwLineDimensionTextPlacement placement; /**<@brief  placement, default: ZW_LINE_DIMENSION_TEXT_AUTOMATIC_PLACEMENT */
        int isNearPlacement;                     /**<@brief  whether to near the placement , default: 1. only used in ZwDrawingDimensionOrdinateCreate() */
        char *userText;                          /**<@brief  user text. only used when textType ==  ZW_LINE_DIMENSION_TEXT_TYPE_USER_TEXT */
    } szwDrawingLineDimensionText;


    /**
    @brief Linear
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLineDimension
    {
        ezwDimensionLineType type;    /**<@brief  type of dimension default value:horizontal method*/
        szwPointOnEntity firstPoint;  /**<@brief  first point */
        szwPointOnEntity secondPoint; /**<@brief  second point */
        szwPointOnEntity textPoint;   /**<@brief  text point: to locate the dimension text */

        double angle;         /**<@brief  dimension angle.
                                   if type = ZW_DIMENSION_LINE_PROJECTED, it is the angle between target line and vertical line */
        szwEntityHandle line; /**<@brief  line. if type = ZW_DIMENSION_LINE_PROJECTED, the point is on the project line, can regard as the entity of project line,
                                   other type can be null */
    } szwDrawingLineDimension;

    /**
    @brief Baseline, Continuous
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLineGroupDimension
    {
        szwDrawingLineDimension linearDimension; /**<@brief  Linear constraint dimension */
        int countPoint;                          /**<@brief  count of Points data items */
        szwPointOnEntity *pointList;             /**<@brief  list of "countPoint"  Points */
        int isDimensionAsGroup;                  /**<@brief whether the dimension is as group, default to be 0. */
        szwDrawingLineDimensionText text;        /**<@brief text*/
    } szwDrawingLineGroupDimension;

    /**
    @brief Center Mark type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwCenterDimensionType
    {
        ZW_DIMENSION_CENTER_MARK = 1,    /**<@brief  Center Mark: create a center mark at an arc or circle. */
        ZW_DIMENSION_CENTER_MARK_CIRCLE, /**<@brief  Center Mark Circle: place a centerline through a circular pattern such as bolt holes. */
        ZW_DIMENSION_CENTER_LINE         /**<@brief  Center Line: create a centerline mark between lines, arcs or circle. */
    } ezwCenterDimensionType;

    /**
    @brief Slot Center Mark type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwSlotCenterMarkType
    {
        ZW_SLOT_CENTERS = 1, /**<@brief  Slot centers */
        ZW_SLOT_ENDS    = 2, /**<@brief  Slot centers */
    } ezwSlotCenterMarkType;

    /**
    @brief Center Mark
    @ingroup zwapi_drawing_dimension_data
    */
    typedef struct szwDrawingCenterMark
    {
        int countArc;                                 /**<@brief  count of arc */
        szwEntityHandle *arcList;                     /**<@brief  arc handle data list */
        char isRotatePoint;                           /**<@brief  whether to rotate the center line/mark toward a selected point.(0: no, 1: yes) */
        szwPoint2 rotatePoint;                        /**<@brief  rotation point */
        int isCreateLinesForCenterMarks;              /**<@brief  whether to create lines for center marks.(0: no, 1: yes)  */
        ezwSlotCenterMarkType slotType;               /**<@brief  Slot center mark type, valid when entity is a hole, default value:ZW_SLOT_CENTERS */
        szwCenterDimensionAttribute *centerDimension; /**<@brief  option param: center dimension attribute.(NULL: use default value) */
    } szwDrawingCenterMark;

    /**
    @brief Label
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDimensionLabel
    {
        int localPointCount;              /**<@brief  localPointList list count */
        szwPointOnEntity *localPointList; /**<@brief  localPointList info: specify the location of the arrow*/
        char *text;                       /**<@brief  text content to be shown */
        int leadPointCount;               /**<@brief  leadPnts list count */
        szwPointOnEntity *leadPointList;  /**<@brief  leadPointList info: locate where additional leader arrow will point*/
    } szwDimensionLabel;

    /**
    @brief Drawing Text Sub Condition
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingTextSubCondition
    {
        /* ezwDrawingTextCondition::ZW_DRAWING_CONDITION_STANDARD */
        ZW_DRAWING_SUB_CONDITION_ID          = 0,  /**<@brief  id */
        ZW_DRAWING_SUB_CONDITION_DERIVEDFROM = 1,  /**<@brief  derived from, merge support */
        ZW_DRAWING_SUB_CONDITION_NUMBER      = 2,  /**<@brief  number, merge support */
        ZW_DRAWING_SUB_CONDITION_DESIGNER    = 3,  /**<@brief  designer, merge support */
        ZW_DRAWING_SUB_CONDITION_MANAGER     = 4,  /**<@brief  manager, merge support */
        ZW_DRAWING_SUB_CONDITION_REMARKS     = 5,  /**<@brief  remarks */
        ZW_DRAWING_SUB_CONDITION_SUPPLIER    = 6,  /**<@brief  supplier, merge support */
        ZW_DRAWING_SUB_CONDITION_COST        = 7,  /**<@brief  cost, merge support */
        ZW_DRAWING_SUB_CONDITION_CLASS       = 8,  /**<@brief  class, merge support */
        ZW_DRAWING_SUB_CONDITION_KEYWORDS    = 9,  /**<@brief  keywords, merge support */
        ZW_DRAWING_SUB_CONDITION_DESCRIPTION = 10, /**<@brief  description, merge support */
        ZW_DRAWING_SUB_CONDITION_QUANTITY    = 11, /**<@brief  quantity */
        ZW_DRAWING_SUB_CONDITION_VISIBLE     = 12, /**<@brief  visible */

        /* ezwDrawingTextCondition::ZW_DRAWING_CONDITION_PHYSICAL */
        ZW_DRAWING_SUB_CONDITION_DENSITY   = 0, /**<@brief  density */
        ZW_DRAWING_SUB_CONDITION_MASS      = 1, /**<@brief  mass */
        ZW_DRAWING_SUB_CONDITION_AREA      = 2, /**<@brief  area */
        ZW_DRAWING_SUB_CONDITION_VOLUME    = 3, /**<@brief  volume */
        ZW_DRAWING_SUB_CONDITION_LENGTH    = 4, /**<@brief  length */
        ZW_DRAWING_SUB_CONDITION_WIDTH     = 5, /**<@brief  width */
        ZW_DRAWING_SUB_CONDITION_HEIGHT    = 6, /**<@brief  height */
        ZW_DRAWING_SUB_CONDITION_STOCKSIZE = 7, /**<@brief  stock size */
        ZW_DRAWING_SUB_CONDITION_SIZE      = 8, /**<@brief  size */
        ZW_DRAWING_SUB_CONDITION_MATERIAL  = 9, /**<@brief  material */

        /* ezwDrawingTextCondition::ZW_DRAWING_CONDITION_FILE */
        ZW_DRAWING_SUB_CONDITION_NAME      = 0, /**<@brief  legend */
        ZW_DRAWING_SUB_CONDITION_FILEPATH  = 1, /**<@brief  source file path */
        ZW_DRAWING_SUB_CONDITION_STARTDATE = 2, /**<@brief  start date */
        ZW_DRAWING_SUB_CONDITION_ENDDATE   = 3, /**<@brief  end date */

        /* ezwDrawingTextCondition::ZW_DRAWING_CONDITION_ECAD */
        ZW_DRAWING_SUB_CONDITION_ECAD_REFER_DES  = 0, /**<@brief  ECAD_RefDes */
        ZW_DRAWING_SUB_CONDITION_ECAD_BOARD_SIDE = 1, /**<@brief  ECAD board side */

        /* ezwDrawingTextCondition::ZW_DRAWING_CONDITION_USER and ZW_DRAWING_CONDITION_USER_TEXT::VX_DWG_CON_USER_TEXT */
        ZW_DRAWING_SUB_CONDITION_NULL = -1,
    } ezwDrawingBalloonTextSubCondition;

    /**
    @brief Drawing Text Condition
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingTextCondition
    {
        ZW_DRAWING_CONDITION_STANDARD  = 0, /**<@brief  standard attribute */
        ZW_DRAWING_CONDITION_PHYSICAL  = 1, /**<@brief  physical attribute */
        ZW_DRAWING_CONDITION_FILE      = 2, /**<@brief  file information */
        ZW_DRAWING_CONDITION_ECAD      = 3, /**<@brief  Ecad attribute */
        ZW_DRAWING_CONDITION_USER      = 4, /**<@brief  user attribute */
        ZW_DRAWING_CONDITION_USER_TEXT = 5, /**<@brief  custom text */
    } ezwDrawingBalloonTextCondition;

    /**
    @brief Type of instances in auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingAutoBalloonInstanceType
    {
        ZW_AUTO_BALLOON_IGNORE_MULTIPLE_INSTANCES = 0, /**<@brief  ignore multiple instances */
        ZW_AUTO_BALLOON_MULTI_LEADER_INSTANCE     = 1, /**<@brief  multi-leader for multiple instances */
        ZW_AUTO_BALLOON_EACH_INSTANCE             = 2  /**<@brief  one for each instances */
    } ezwDrawingAutoBalloonInstanceType;

    /**
    @brief Pattern type of auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingAutoBalloonPatternType
    {
        ZW_AUTO_BALLOON_PATTERN_CONVEX_HULL = 1, /**<@brief  convex hull around the layout view */
        ZW_AUTO_BALLOON_PATTERN_SQUARE      = 2, /**<@brief  square around the layout view */
        ZW_AUTO_BALLOON_PATTERN_CIRCULAR    = 3  /**<@brief  circular around the layout view */
    } ezwDrawingAutoBalloonPatternType;

    /**
    @brief Leader attachment of auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingAutoBalloonLeaderAttachment
    {
        ZW_AUTO_BALLOON_LEADER_ATTACH_EDGES = 1, /**<@brief  attach to edges */
        ZW_AUTO_BALLOON_LEADER_ATTACH_FACES = 2  /**<@brief  attach to face */
    } ezwDrawingAutoBalloonLeaderAttachment;

    /**
    @brief Skip sides of auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingAtBalloonSkipSide
    {
        ZW_AUTO_BALLOON_SKIP_SIDE_NONE   = 0, /**<@brief  skip none */
        ZW_AUTO_BALLOON_SKIP_SIDE_LEFT   = 1, /**<@brief  skip left */
        ZW_AUTO_BALLOON_SKIP_SIDE_TOP    = 2, /**<@brief  skip top */
        ZW_AUTO_BALLOON_SKIP_SIDE_RIGHT  = 4, /**<@brief  skip right */
        ZW_AUTO_BALLOON_SKIP_SIDE_BOTTOM = 8  /**<@brief  skip bottom */
    } ezwDrawingAtBalloonSkipSide;

    /**
    @brief Arrangement of auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingAutoBalloonArrangement
    {
        ZW_AUTO_BALLOON_ARRANGE_NEAREST           = 1, /**<@brief  simply located nearest to the component being labeled */
        ZW_AUTO_BALLOON_ARRANGE_CLOCKWISE         = 2, /**<@brief  arranged in clockwise order */
        ZW_AUTO_BALLOON_ARRANGE_CLOCKWISE_COUNTER = 3  /**<@brief  arranged in counter - clockwise order */
    } ezwDrawingAutoBalloonArrangement;

    /**
    @brief Information of creating auto balloon
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingAutoBalloonData
    {
        int viewCount;                           /**<@brief  count of view */
        szwEntityHandle *viewList;               /**<@brief  list of view */
        szwEntityHandle *relatedBom;             /**<@brief  relatedBom. NULL to use default: Assembly struct. Only used in when viewCount == 1. */
        ezwDrawingTextCondition condition;       /**<@brief  Text condition, default value:ZW_DRAWING_CONDITION_STANDARD */
        ezwDrawingTextSubCondition subCondition; /**<@brief  Text sub condition, default value:ZW_DRAWING_SUB_CONDITION_ID */
        zwString256 text;                        /**<@brief  text string, 
                                                taking effect only when condition = ZW_DRAWING_CONDITION_USER_TEXT or subCondition = ZW_DRAWING_SUB_CONDITION_ID */

        ezwDrawingAutoBalloonInstanceType instanceType;         /**<@brief  instances type
                                        (note: ZW_AUTO_BALLOON_IGNORE_MULTIPLE_INSTANCES as default) */
        ezwDrawingAutoBalloonPatternType patternType;           /**<@brief  pattern type
                                        (note: ZW_AUTO_BALLOON_PATTERN_CONVEX_HULL as default)*/
        ezwDrawingAutoBalloonLeaderAttachment leaderAttachment; /**<@brief  leader attachment
                                        (note: ZW_AUTO_BALLOON_LEADER_ATTACH_EDGES as default) */
        int isAutoOffset;                                       /**<@brief  auto offset, default: 1.( no: 0, yes: 1) */
        zwUInt32 offSet;                                        /**<@brief  specify the offset */
        ezwDrawingAtBalloonSkipSide skipSides;                  /**<@brief  prevent placing balloon labels along one side of the view.
                                        Be unusable when ptnType is ZW_AUTO_BALLOON_PATTERN_CIRCULAR
                                        (note: ZW_AUTO_BALLOON_SKIP_SIDE_NONE as default). */
        ezwDrawingAutoBalloonArrangement arrangement;           /**<@brief  how the balloon labels will be arranged around the layout view. Used when have bom in sheeting,
                                        but must be initialized any time.
                                        (note: ZW_AUTO_BALLOON_ARRANGE_NEAREST as default) */
        int isKeepItem;                                         /**<@brief  flag of keeping item (0 no, else yes), Used when arrangement is not ZW_ATBLLNARR_NEAREST.
                                        (note: 0 as default) */
        szwEntityHandle *itemHandle;                            /**<@brief  handle data of the kept curve,used when isKeepItem is not 0. Null to ignore*/
        int isOnlyForComponentsInBOM;                           /**<@brief  Whether the excluded components from BOM should be labeled. Used when have bom in sheeting.
                                        (0 no, else yes. Note: 1 as default) */
        int isOnlyForItemsWithoutBalloon;                       /**<@brief  Whether label the components which are not labeled in any other views to eliminate duplicate balloons. Used when isOnlyForComponentsInBOM is not 0.
                                        (0 no, else yes. Note: 0 as default) */
        int isAddMagneticLine;                                  /**<@brief  Whether to add magnetic line. Used when patternType == ZW_AUTO_BALLOON_PATTERN_SQUARE.
                                        (0 no, else yes. Note: 0 as default) */
    } szwDrawingAutoBalloonData;
    
     /**
    @brief type of drawing geometry critical point
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingDimensionPointType
    {
        ZW_DRAWING_DIMENSION_FREE_POINT,         /**<@brief  the free point on curve */
        ZW_DRAWING_DIMENSION_START_POINT,        /**<@brief  start point of curve */
        ZW_DRAWING_DIMENSION_END_POINT,          /**<@brief  end point of curve */
        ZW_DRAWING_DIMENSION_MIDDLE_POINT,       /**<@brief  middle point, entity must be line or arc */
        ZW_DRAWING_DIMENSION_ARC_CENTER,         /**<@brief  center of arc, entity must be an arc or circle */
        ZW_DRAWING_DIMENSION_ARC_PROXIMAL_POINT, /**<@brief  the minimum distance point or proximal tangent point of arc, entity must be an arc or circle */
        ZW_DRAWING_DIMENSION_ARC_DISTAL_POINT,   /**<@brief  the maximum distance point or distal tangent point of arc, entity must be an arc or circle */
        ZW_DRAWING_DIMENSION_SPLINE_POINT,       /**<@brief  the defining point of spline, entity must be a spline */
    } ezwDrawingDimensionPointType;

    /**
    @brief data of drawing dimension point
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingDimensionPoint
    {
        szwEntityHandle entityHandle;           /**<@brief  entity handle to dimension*/
        ezwDrawingDimensionPointType pointType; /**<@brief  type of dimension point */
        int definingPoint;                      /**<@brief  the index number of the defining point of the spline (starting from 0), if pointType = ZW_SKETCH_DIMENSION_SPLINE_POINT */
        szwPoint2 freePoint;                    /**<@brief  the free point coordinate, if pointType = ZW_SKETCH_DIMENSION_FREE_POINT */
    } szwDrawingDimensionPoint;


    /**
    @brief type of linear chamfer dimension in sheeting
    @ingroup ZwDrawingDimensionData
     */
    typedef enum ezwDrawingLinearChamferDimensionType
    {
        ZW_LEADER_CHAMFER_DIMENSION = 1,            /**<@brief  leader linear chamfer dimension */
        ZW_ALIGNED_CHAMFER_DIMENSION,               /**<@brief  aligned linear chamfer dimension */
        ZW_HORIZONTAL_OR_VERTICAL_CHAMFER_DIMENSION /**<@brief  horizontal/vertical linear chamfer dimension */
    } zwDrawingLinearChamferDimensionType;

    /**
    @brief text style of leader linear chamfer dimension in sheeting
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDrawingLinearChamferDimensionTextType
    {
        ZW_TEXT_NORMAL_CHAMFER_DIMENSION = 0,      /**<@brief  normal */
        ZW_TEXT_PERPENDICULAR_CHAMFER_DIMENSION,   /**<@brief  always perpendicular */
        ZW_TEXT_ALONG_MODEL_LINE_CHAMFER_DIMENSION /**<@brief  along the model line */
    } ezwDrawingLinearChamferDimensionTextType;

    /**
    @brief the info of the linear chamfer dimension
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLinearChamferDimensionData
    {
        szwPointOnEntity lineData;                                  /**<@brief  handle and point data of line (the referenceEntityHandle of "lineData" must be valid).
                                                                    if type =ZW_LEADER_CHAMFER_DIMENSION, the arrow is point at lineData on the chamfer entity,
                                                                    other type the lineData represent the specified chamfer*/
        szwPointOnEntity adjacentLineData;                          /**<@brief  handle and point data of adjacent line */
        ezwDrawingLinearChamferDimensionType dimensionType;         /**<@brief  type of line linear chamfer dimension */
        ezwDrawingLinearChamferDimensionTextType dimensionTextType; /**<@brief  type of Text, only required when "dimensionType" is ZW_LEADER_CHAMFER_DIMENSION */
        szwPointOnEntity textPoint;                                 /**<@brief  point coordinate of text placement point. */
        szwPointOnEntity horizontalTextPoint;                       /**<@brief  point coordinate of horizontal text placement point,
                                                                    only required when "dimensionType" is ZW_HORIZONTAL_OR_VERTICAL_CHAMFER_DIMENSION */
        szwPointOnEntity verticalTextPoint;                         /**<@brief  point coordinate of vertical text placement point,
                                                                    only required when "dimensionType" is ZW_HORIZONTAL_OR_VERTICAL_CHAMFER_DIMENSION */
    } szwDrawingLinearChamferDimensionData;

    /**
    @brief dimension Line type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDimensionLinearType
    {
        ZW_DIMENSION_LINEAR_HORIZONTAL = 1, /**<@brief  horizontal dimension */
        ZW_DIMENSION_LINEAR_VERTICAL   = 2, /**<@brief  vertical dimension */
        ZW_DIMENSION_LINEAR_ALIGNED    = 3, /**<@brief  aligned dimension */
        ZW_DIMENSION_LINEAR_ROTATE     = 4, /**<@brief  rotated dimension */
        ZW_DIMENSION_LINEAR_PROJECTED  = 5, /**<@brief  projected dimension */
        ZW_DIMENSION_LINEAR_ORDINATE   = 6, /**<@brief  ordinate dimension, only used when creating ordinate dimension: 
                                            create a linear ordinate horizontal dimension groups and the linear ordinate
                                            vertical dimension groups.*/
    } ezwDimensionLinearType;

    /**
    @brief linear dimension
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLinearDimension
    {
        ezwDimensionLinearType type;  /**<@brief  type of dimension default value:horizontal method*/
        szwPointOnEntity firstPoint;  /**<@brief  first point */
        szwPointOnEntity secondPoint; /**<@brief  second point */
        szwPointOnEntity textPoint;   /**<@brief  text point: to locate the dimension text */
        double angle;                 /**<@brief  dimension angle.
                                           If type = ZW_DIMENSION_LINE_ROTATE, it is the angle between target line and vertical line,
                                           other type can be 0 */
        szwEntityHandle projectLine;  /**<@brief  the point on the project line.
                                           If type = ZW_DIMENSION_LINE_PROJECTED, the point is on the project line, can regard as the entity of project line,
                                           other type can be 0 */
    } szwDrawingLinearDimension;

    /**
    @brief dimension offset type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwDimensionLinearOffsetType
    {
        ZW_DIMENSION_OFFSET_LINE_TO_LINE  = 1, /**<@brief  line to line (Offset Method) */
        ZW_DIMENSION_OFFSET_POINT_TO_LINE = 2, /**<@brief  point to line (Projected Distance Method) */
    } ezwDimensionLinearOffsetType;

    /**
    @brief linear offset dimension data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingLinearOffsetDimension
    {
        ezwDimensionLinearOffsetType type;    /**<@brief  type of dimension default value:ZW_DIMENSION_OFFSET_LINE_TO_LINE*/
        szwDrawingDimensionPoint firstPoint;  /**<@brief  ZW_DIMENSION_OFFSET_LINE_TO_LINE: first line ; ZW_DIMENSION_OFFSET_POINT_TO_LINE : first line*/
        szwDrawingDimensionPoint secondPoint; /**<@brief  ZW_DIMENSION_OFFSET_LINE_TO_LINE: second line; ZW_DIMENSION_OFFSET_POINT_TO_LINE : point*/
        szwPointOnEntity textPoint;           /**<@brief  text point: select a point to locate the dimension text */
    } szwDrawingLinearOffsetDimension;

    /**
    @brief angular dimension type
    @ingroup ZwDrawingDimensionData
    */
    typedef enum ezwAngleDimensionType
    {
        ZW_DIMENSION_ANGLE_TWOCURVES  = 1, /**<@brief  2 curves angular dimension*/
        ZW_DIMENSION_ANGLE_HORIZONTAL = 2, /**<@brief  horizontal angular dimension */
        ZW_DIMENSION_ANGLE_VERTICAL   = 3, /**<@brief  vertical angular dimension */
        ZW_DIMENSION_ANGLE_THREEPOINT = 4, /**<@brief  3 point angular dimension*/
        ZW_DIMENSION_ANGLE_ARC        = 5, /**<@brief  arc angular dimension*/
    } ezwAngleDimensionType;

    /**
    @brief Angular dimension data
    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingAngularDimensionData
    {
        ezwAngleDimensionType type; /**<@brief  Angular or diametric type */

        szwPointOnEntity curve1; /**<@brief get one entity and point coordinate.
                                  if type = ZW_DIMENSION_ANGLE_TWOCURVES, the angle is between 1st curve and 2nd curve.
                                  if type = ZW_DIMENSION_ANGLE_HORIZONTAL, the angle is between 1st curve and horizontal line.
                                  if type = ZW_DIMENSION_ANGLE_VERTICAL, the angle is between 1st curve and vertical line.
                                  other type can ignore */
        szwPointOnEntity curve2; /**<@brief  get one entity and point coordinate.
                                   if type = ZW_DIMENSION_ANGLE_TWOCURVES, the angle is between 1st curve and 2nd curve.
                                   other can ignore */

        szwPointOnEntity basePoint;     /**<@brief  base point.
                                   if type = ZW_DIMENSION_ANGLE_THREEPOINT, basePoint is angle's vertex.
                                   other type can ignore. */
        szwPointOnEntity startPoint;    /**<@brief  start point.
                                   if type = ZW_DIMENSION_ANGLE_THREEPOINT, the angle is between two line, 1st line through.
                                   startPoint and basePoint.
                                   other type can ignore. */
        szwPointOnEntity endPoint;      /**<@brief  end point.
                                   if type = ZW_DIMENSION_ANGLE_THREEPOINT, the angle is between two line, 2nd line through.
                                   basePoint and endPoint.
                                   other type can ignore */
        szwPointOnEntity arcPoint;      /**<@brief  arc point on arc.
                                   if type = ZW_DIMENSION_ANGLE_ARC , the angle is arc's angle.
                                   other type can ignore */
        szwPointOnEntity quadrantPoint; /**<@brief  quadrant point.
                                   if type != ZW_DIMENSION_ANGLE_ARC, the point is position of text of angle.*/
        szwPointOnEntity textPoint;     /**<@brief  text point.
                                   if type = ZW_DIMENSION_ANGLE_ARC, the point is position of text of angle.
                                   other type can ignore */
    } szwDrawingAngularDimensionData;
    
    /**
    @brief balloon display type in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef enum ezwDrawingBalloonType
    {
        ZW_DRAWING_DIMENSION_BALLOON_NONE                = 0, /**<@brief  none*/
        ZW_DRAWING_DIMENSION_BALLOON_CIRCULAR            = 1, /**<@brief  circular */
        ZW_DRAWING_DIMENSION_BALLOON_TRIANGLE            = 2, /**<@brief  triangle */
        ZW_DRAWING_DIMENSION_BALLOON_SQUARE              = 3, /**<@brief  square */
        ZW_DRAWING_DIMENSION_BALLOON_HEXAGON             = 4, /**<@brief  hexagon */
        ZW_DRAWING_DIMENSION_BALLOON_CIRCULAR_SPLIT_LINE = 5, /**<@brief  circular split line */
        ZW_DRAWING_DIMENSION_BALLOON_UNDERLINE           = 6, /**<@brief  underline */
    } ezwDrawingBalloonType;

    /**
    @brief balloon dimension in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef struct szwDrawingBalloonDimension
    {
        ezwDrawingBalloonType balloonType; /**<@brief  balloon type */
        szwEntityHandle relatedBom;        /**<@brief  relatedBom, handle of the related bom */

        ezwDrawingTextType textType;       /**<@brief  text type, default value:ZW_DRAWING_DIMENSION_TEXT_STANDARD */
        ezwDrawingTextSubType textSubType; /**<@brief  text sub type, default value:ZW_DRAWING_DIMENSION_TEXT_ID */
        zwString1024 text;                 /**<@brief  text string, taking effect only when textType = ZW_DRAWING_DIMENSION_TEXT_USER_TEXT or textSubType = ZW_DRAWING_DIMENSION_TEXT_ID */

        /*only if balloonType = ZW_DRAWING_DIMENSION_BALLOON_CIRCULAR_SPLIT_LINE lower text need to be set*/
        ezwDrawingTextType lowerTextType;       /**<@brief  lower text type, default value:ZW_DRAWING_DIMENSION_TEXT_STANDARD */
        ezwDrawingTextSubType lowertextSubType; /**<@brief  lower text sub type, default value:ZW_DRAWING_DIMENSION_TEXT_ID */
        zwString1024 lowerText;                 /**<@brief  lower text string, taking effect only when lowerTextType = ZW_DRAWING_DIMENSION_TEXT_USER_TEXT or textSubType = ZW_DRAWING_DIMENSION_TEXT_ID */

        int countLocation;           /**<@brief  number of location points */
        szwPointOnEntity *locations; /**<@brief  list of location points */
        int countLeader;             /**<@brief  number of lead points */
        szwPointOnEntity *leaders;   /**<@brief  list of lead points */
    } szwDrawingBalloonDimension;

    /**
    @brief label coordinate dimension type in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef enum ezwDrawingLabelCoordinateType
    {
        ZW_DRAWING_DIMENSION_AUTO_TEXT = 1, /**<@brief  Auto text placement */
        ZW_DRAWING_DIMENSION_PICK_TEXT = 2, /**<@brief  Pick text placement */
    } ezwDrawingLabelCoordinateType;

    /**
    @brief label coordinate dimension in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef struct szwDrawingLabelCoordinateDimension
    {
        ezwDrawingLabelCoordinateType type; /**<@brief  label coordinate type */
        szwPointOnEntity origin;            /**<@brief  origin point of label coordinate dimension*/

        int countPoint;              /**<@brief  number of the point need the coordinates */
        szwPointOnEntity *points;    /**<@brief  point to the coordinate point of dimension(length of list must equal to countPoint)*/
        szwPointOnEntity *textPoint; /**<@brief  list of text points. the length of list must equal to countPoint when it is customization, 
                                         when data.type == ZW_DRAWING_DIMENSION_AUTO_TEXT and data.textPoint is NULL, the default text points are used */
        zwString1024 text;           /**<@brief  text(empty to be formatted as <C_X>,<C_Y>,<C_Z>, you can also custom text) */
    } szwDrawingLabelCoordinateDimension;

    /**
    @brief datum feature type in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef enum ezwDrawingDatumFeatureType
    {
        ZW_DRAWING_DIMENSION_DATUM_FEATUE_NORMAL = 1, /**<@brief  normal datum feature dimension */
        ZW_DRAWING_DIMENSION_DATUM_FEATUE_ANSI   = 2, /**<@brief  based on ANSI(per 1982) */
    } ezwDrawingDatumFeatureType;

    /**
    @brief label feature type in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef enum ezwDrawingDatumLabelType
    {
        ZW_DRAWING_DIMENSION_DATUM_LABEL_USER_TEXT    = 1, /**<@brief  user text */
        ZW_DRAWING_DIMENSION_DATUM_LABEL_FROM_FEATURE = 2, /**<@brief  from feature */
    } ezwDrawingDatumLabelType;

    /**
    @brief datum feature dimension in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef struct szwDrawingDatumFeatureDimension
    {
        ezwDrawingDatumFeatureType datumType; /**<@brief  datum feature type, default:ZW_DRAWING_DIMENSION_DATUM_FEATUE_NORMAL) */
        ezwDrawingDatumLabelType labelType;   /**<@brief  label type, only used when datumType = ZW_DRAWING_DIMENSION_DATUM_FEATUE_NORMAL,
                                                  default:ZW_DRAWING_DIMENSION_DATUM_LABEL_USER_TEXT */
        zwString1024 labelText;               /**<@brief  datum label text , not used when labelType = ZW_DRAWING_DIMENSION_DATUM_LABEL_FROM_FEATURE*/
        szwPointOnEntity entity;              /**<@brief  entity or a point on entity
                                                 if type = ZW_DRAWING_DIMENSION_DATUM_FEATUE_NORMAL, entity is the textPoint's projection on the entity
                                                 if type = ZW_DRAWING_DIMENSION_DATUM_FEATUE_ANSI, entity is a point on entity. */
        szwPointOnEntity textPoint;           /**<@brief  point coordinate of text placement point.
                                                 if type = ZW_DRAWING_DIMENSION_DATUM_FEATUE_NORMAL, textPoint can be given arbitrarily.
                                                 if type = ZW_DRAWING_DIMENSION_DATUM_FEATUE_ANSI, textPoint is on the parallel or vertical line through leadPoint */
    } szwDrawingDatumFeatureDimension;

    /**
    @brief dimension line type in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef enum ezwDrawingDimensionLineType
    {
        ZW_DRAWING_DIMENSION_LINE_HORIZONTAL = 1, /**<@brief  horizontal dimension */
        ZW_DRAWING_DIMENSION_LINE_VERTICAL   = 2, /**<@brief  vertical dimension */
        ZW_DRAWING_DIMENSION_LINE_ALIGNED    = 3, /**<@brief  aligned dimension */
        ZW_DRAWING_DIMENSION_LINE_ROTATED    = 4, /**<@brief  rotated dimension */
        ZW_DRAWING_DIMENSION_LINE_PROJECTED  = 5, /**<@brief  projected dimension */
        ZW_DRAWING_DIMENSION_LINE_LORIDINATE = 6, /**<@brief  ordinate dimension, only used in ZwDrawingDimensionOrdinateCreate():
                                 create a linear ordinate horizontal dimension groups
                                 and the linear ordinate vertical dimension groups.*/
    } ezwDrawingDimensionLineType;

    /**
    @brief baseline dimension in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef struct szwDrawingBaseLineDimension
    {
        ezwDrawingDimensionLineType type; /**<@brief  type of dimension default value:ZW_DRAWING_DIMENSION_LINE_HORIZONTAL*/
        szwPointOnEntity firstPoint;      /**<@brief  first point */
        szwPointOnEntity secondPoint;     /**<@brief  second point */
        szwPointOnEntity textPoint;       /**<@brief  text point: to locate the dimension text */

        double angle;         /**<@brief  the angle between target line and vertical line, 
                                          only be used when type = ZW_DRAWING_DIMENSION_LINE_ROTATED */
        szwEntityHandle line; /**<@brief  the line to project dimension, 
                                          only be used when type = ZW_DRAWING_DIMENSION_LINE_PROJECTED */

        int countPoint;              /**<@brief  number of points*/
        szwPointOnEntity *pointList; /**<@brief  list of points*/
        int dimensionAsGroup;        /**<@brief  flag to determine whether dimensions are as group dimension.(if 0 no, else yes)*/
    } szwDrawingBaseLineDimension;

    /**
    @brief center mark circle dimension data in drawing
    @ingroup ZwDrawingDimensionCreateData
    */
    typedef struct szwCenterMarkCircleDimension
    {
        int countPoint;                /**<@brief  the number of points */
        szwPointOnEntity *pointList;   /**<@brief  point list for center marks(the length of list must equal to countPoint) */
        int useCenter;                 /**<@brief  flag to use "circleCenter" (0 as default)*/
        szwPointOnEntity circleCenter; /**<@brief  arc center or circle center(only when useCenter = 1, the value is valid) */
    } szwCenterMarkCircleDimension;

    /**
    @brief position points of a dimension text

    @verbatim
    For a horizontal dimension, the position points are as below:
      topLeft            topRight
        -----------------------
        |                     |
        -----------------------
      bottomLeft         bottomRight

    If the dimension slopes, the position points still keep as the horizontal one:
      topRight     bottomRight
              ----
              |  |
              |  |
              |  |
              ----
      topLeft      bottomLeft

    @endverbatim

    @ingroup ZwDrawingDimensionData
    */
    typedef struct szwDrawingDimensionTextPositionPoints
    {
        szwPoint2 bottomLeft;  /**<@brief  point at bottom-left */
        szwPoint2 bottomRight; /**<@brief  point at bottom-right */
        szwPoint2 topRight;    /**<@brief  point at top-right */
        szwPoint2 topLeft;     /**<@brief  point at top-left */
    } szwDrawingDimensionTextPositionPoints;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_DRAWING_DIMENSION_DATA_H */
