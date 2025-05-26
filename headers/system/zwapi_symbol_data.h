/**
@file zwapi_symbol_data.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the symbol
*/

#pragma once

#ifndef ZW_API_SYMBOL_DATA_H
#define ZW_API_SYMBOL_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Symbol Data*/
    //====================================================================================================================

    /**
    @brief type of other side weld symbol
    @ingroup ZwSymbolData
    */
    typedef enum ezwOtherSideWeldSymbolType
    {
        ZW_SYMBOL_OTHER_NULL = 1,                        /**<@brief  no symbol*/
        ZW_SYMBOL_OTHER_SQUARE_BUTT,                     /**<@brief  square butt*/
        ZW_SYMBOL_OTHER_V_BUTT,                          /**<@brief  V butt*/
        ZW_SYMBOL_OTHER_BEVEL_BUTT,                      /**<@brief  bevel butt*/
        ZW_SYMBOL_OTHER_U_BUTT,                          /**<@brief  U butt*/
        ZW_SYMBOL_OTHER_J_BUTT,                          /**<@brief  J butt*/
        ZW_SYMBOL_OTHER_FLARE_V,                         /**<@brief  flare V*/
        ZW_SYMBOL_OTHER_FLARE_BEVEL,                     /**<@brief  flare bevel*/
        ZW_SYMBOL_OTHER_INCLINED_JOINT,                  /**<@brief  inclined joint*/
        ZW_SYMBOL_OTHER_FILLET,                          /**<@brief  fillet*/
        ZW_SYMBOL_OTHER_PLUG_SLOT,                       /**<@brief  plug slot*/
        ZW_SYMBOL_OTHER_SPOT,                            /**<@brief  spot*/
        ZW_SYMBOL_OTHER_SPOT_CENTERED,                   /**<@brief  spot centered*/
        ZW_SYMBOL_OTHER_SEAM,                            /**<@brief  seam*/
        ZW_SYMBOL_OTHER_SEAM_CENTERED,                   /**<@brief  seam centered*/
        ZW_SYMBOL_OTHER_BACKING_RUN,                     /**<@brief  backing run*/
        ZW_SYMBOL_OTHER_BUTT_WELD_WITH_RAISED_EDGES,     /**<@brief  butt weld with raised edges*/
        ZW_SYMBOL_OTHER_SINGLE_FLANGE,                   /**<@brief  single flange*/
        ZW_SYMBOL_OTHER_MELT_THROUGH,                    /**<@brief  melt through*/
        ZW_SYMBOL_OTHER_CONSUMABLE_INSERT,               /**<@brief  consumable insert*/
        ZW_SYMBOL_OTHER_DOUBLE_V_GROOVE_SPACER,          /**<@brief  double V groove spacer*/
        ZW_SYMBOL_OTHER_DOUBLE_BEVEL_GROOVE_SPACER,      /**<@brief  double bevel groove spacer*/
        ZW_SYMBOL_OTHER_DOUBLE_U_GROOVE_SPACER,          /**<@brief  double U groove spacer*/
        ZW_SYMBOL_OTHER_DOUBLE_J_GROOVE_SPACER,          /**<@brief  double J groove spacer*/
        ZW_SYMBOL_OTHER_SURFACING,                       /**<@brief  surfacing*/
        ZW_SYMBOL_OTHER_V_BUTT_WITH_BROAD_ROOT_FACE,     /**<@brief  V butt with broad root face*/
        ZW_SYMBOL_OTHER_BEVEL_BUTT_WITH_BROAD_ROOT_FACE, /**<@brief  Bevel butt with broad root face*/
        ZW_SYMBOL_OTHER_STEEP_FLANKED_V_BUTT,            /**<@brief  steep flanked V butt*/
        ZW_SYMBOL_OTHER_STEEP_FLANKED_BEVEL_BUTT,        /**<@brief  steep flanked bevel butt*/
        ZW_SYMBOL_OTHER_EDGE,                            /**<@brief  edge*/
        ZW_SYMBOL_OTHER_SURFACE_JPOINT,                  /**<@brief  surface jpoint*/
        ZW_SYMBOL_OTHER_FOLD_JPOINT,                     /**<@brief  fold jpoint*/
        ZW_SYMBOL_OTHER_BACKING_PLATE,                   /**<@brief  backing plate*/
        ZW_SYMBOL_OTHER_EDGE_2,                          /**<@brief  edge 2*/
        ZW_SYMBOL_OTHER_SPOT_JIS,                        /**<@brief  spot(JIS)*/
        ZW_SYMBOL_OTHER_SEAM_JIS,                        /**<@brief  SEAM(JIS)*/
        ZW_SYMBOL_OTHER_CUT_WELD_ENFORCEMENT,            /**<@brief  cut weld enforcement*/
        ZW_SYMBOL_OTHER_SMOOTH_TRANSITION_TO_BASE_METAL, /**<@brief  smooth transition to base metal*/
        ZW_SYMBOL_OTHER_SPOT_OR_PROJECTION_WELD,         /**<@brief  spot or projection weld*/
        ZW_SYMBOL_OTHER_ZIGZAG_WELD,                     /**<@brief  zigzag weld*/
        ZW_SYMBOL_OTHER_OPEN_WELD_CONTOUR                /**<@brief  open weld contour*/
    } ezwOtherSideWeldSymbolType;

    /**
    @brief type of arrow side weld symbol
    @ingroup ZwSymbolData
    */
    typedef enum ezwArrowSideWeldSymbolType
    {
        ZW_SYMBOL_ARROW_NULL = 1,                        /**<@brief  no symbol*/
        ZW_SYMBOL_ARROW_SQUARE_BUTT,                     /**<@brief  square butt*/
        ZW_SYMBOL_ARROW_V_BUTT,                          /**<@brief  V butt*/
        ZW_SYMBOL_ARROW_BEVEL_BUTT,                      /**<@brief  bevel butt*/
        ZW_SYMBOL_ARROW_U_BUTT,                          /**<@brief  U butt*/
        ZW_SYMBOL_ARROW_J_BUTT,                          /**<@brief  J butt*/
        ZW_SYMBOL_ARROW_FLARE_V,                         /**<@brief  flare V*/
        ZW_SYMBOL_ARROW_FLARE_BEVEL,                     /**<@brief  flare bevel*/
        ZW_SYMBOL_ARROW_INCLINED_JOINT,                  /**<@brief  inclined joint*/
        ZW_SYMBOL_ARROW_FILLET,                          /**<@brief  fillet*/
        ZW_SYMBOL_ARROW_PLUG_SLOT,                       /**<@brief  plug slot*/
        ZW_SYMBOL_ARROW_SPOT,                            /**<@brief  spot*/
        ZW_SYMBOL_ARROW_SPOT_CENTERED,                   /**<@brief  spot centered*/
        ZW_SYMBOL_ARROW_SEAM,                            /**<@brief  seam*/
        ZW_SYMBOL_ARROW_SEAM_CENTERED,                   /**<@brief  seam centered*/
        ZW_SYMBOL_ARROW_BACKING_RUN,                     /**<@brief  backing run*/
        ZW_SYMBOL_ARROW_BUTT_WELD_WITH_RAISED_EDGES,     /**<@brief  butt weld with raised edges*/
        ZW_SYMBOL_ARROW_SINGLE_FLANGE,                   /**<@brief  single flange*/
        ZW_SYMBOL_ARROW_MELT_THROUGH,                    /**<@brief  melt through*/
        ZW_SYMBOL_ARROW_CONSUMABLE_INSERT,               /**<@brief  consumable insert*/
        ZW_SYMBOL_ARROW_DOUBLE_V_GROOVE_SPACER,          /**<@brief  double V groove spacer*/
        ZW_SYMBOL_ARROW_DOUBLE_BEVEL_GROOVE_SPACER,      /**<@brief  double bevel groove spacer*/
        ZW_SYMBOL_ARROW_DOUBLE_U_GROOVE_SPACER,          /**<@brief  double U groove spacer*/
        ZW_SYMBOL_ARROW_DOUBLE_J_GROOVE_SPACER,          /**<@brief  double J groove spacer*/
        ZW_SYMBOL_ARROW_STUD,                            /**<@brief  stud*/
        ZW_SYMBOL_ARROW_SURFACING,                       /**<@brief  surfacing*/
        ZW_SYMBOL_ARROW_V_BUTT_WITH_BROAD_ROOT_FACE,     /**<@brief  V butt with broad root face*/
        ZW_SYMBOL_ARROW_BEVEL_BUTT_WITH_BROAD_ROOT_FACE, /**<@brief  Bevel butt with broad root face*/
        ZW_SYMBOL_ARROW_STEEP_FLANKED_V_BUTT,            /**<@brief  steep flanked V butt*/
        ZW_SYMBOL_ARROW_STEEP_FLANKED_BEVEL_BUTT,        /**<@brief  steep flanked bevel butt*/
        ZW_SYMBOL_ARROW_EDGE,                            /**<@brief  edge*/
        ZW_SYMBOL_ARROW_SURFACE_JPOINT,                  /**<@brief  surface jpoint*/
        ZW_SYMBOL_ARROW_FOLD_JPOINT,                     /**<@brief  fold jpoint*/
        ZW_SYMBOL_ARROW_BACKING_PLATE,                   /**<@brief  backing plate*/
        ZW_SYMBOL_ARROW_EDGE_2,                          /**<@brief  edge 2*/
        ZW_SYMBOL_ARROW_CUT_WELD_ENFORCEMENT,            /**<@brief  cut weld enforcement*/
        ZW_SYMBOL_ARROW_SMOOTH_TRANSITION_TO_BASE_METAL, /**<@brief  smooth transition to base metal*/
        ZW_SYMBOL_ARROW_SPOT_OR_PROJECTION_WELD,         /**<@brief  spot or projection weld*/
        ZW_SYMBOL_ARROW_ZIGZAG_WELD,                     /**<@brief  zigzag weld*/
        ZW_SYMBOL_ARROW_OPEN_WELD_CONTOUR                /**<@brief  open weld contour*/
    } ezwArrowSideWeldSymbolType;

    /**
    @brief finish symbol of weld symbol
    @ingroup ZwSymbolData
    */
    typedef enum ezwWeldFinishSymbol
    {
        ZW_WELD_FINISH_NONE = 1,    /**<@brief  none */
        ZW_WELD_FINISH_CHIPPING,    /**<@brief  chipping */
        ZW_WELD_FINISH_GRINDING,    /**<@brief  grinding */
        ZW_WELD_FINISH_HAMMERING,   /**<@brief  hammering */
        ZW_WELD_FINISH_MACHINING,   /**<@brief  machining */
        ZW_WELD_FINISH_ROLLING,     /**<@brief  rolling */
        ZW_WELD_FINISH_UNSPECIFIED, /**<@brief  unspecified */
    } ezwWeldFinishSymbol;

    /**
    @brief contour symbol of weld symbol
    @ingroup ZwSymbolData
    */
    typedef enum ezwWeldContourSymbol
    {
        ZW_WELD_COUNTOUR_NONE = 1,        /**<@brief  none */
        ZW_WELD_COUNTOUR_FLAT,            /**<@brief  flat */
        ZW_WELD_COUNTOUR_CONVEX,          /**<@brief  convex */
        ZW_WELD_COUNTOUR_CONCAVE,         /**<@brief  concave */
        ZW_WELD_COUNTOUR_BLEND_TOES,      /**<@brief  blended toes */
        ZW_WELD_COUNTOUR_STRIP_PERMANENT, /**<@brief  backing strip permanent */
        ZW_WELD_COUNTOUR_STRIP_REMOVABLE, /**<@brief  backing strip removable */
    } ezwWeldContourSymbol;

    /**
    @brief weld data settings
    @ingroup ZwSymbolData
    */
    typedef struct szwSymbolWeldSetting
    {
        ezwWeldFinishSymbol finishSymbolUp;        /**<@brief  finish symbol (other side) */
        ezwWeldContourSymbol contourSymbolUp;      /**<@brief  contour symbol (other side) */
        int flipText;                              /**<@brief  flip flag(0:not flip,1:flip)  */
        char upperText[33];                        /**<@brief  upper text */
        char underText[33];                        /**<@brief  under text */
        int lineFlag;                              /**<@brief  line flag 0:plain, 1:below, 2:above */
        int stagger;                               /**<@brief  stagger (0: suppress; 1: enable) */
        int fillet2Up;                             /**<@brief  2nd fillet (other side) (0: suppress; 1: enable) */
        ezwOtherSideWeldSymbolType weldSymbolUp;   /**<@brief  weld symbol (other side) */
        int fieldFlag;                             /**<@brief  field flag (0: suppress; 1: enable) */
        int aroundCircle;                          /**<@brief  all round circle (0 ~ 2) */
        int tail;                                  /**<@brief  tail (0 ~ 2) */
        ezwArrowSideWeldSymbolType weldSymbolDown; /**<@brief  weld symbol (arrow side) */
        int fillet2Down;                           /**<@brief  2nd fillet (arrow side) (0: suppress; 1: enable) */
        ezwWeldContourSymbol contourSymbolDown;    /**<@brief  contour symbol (arrow side) */
        ezwWeldFinishSymbol finishSymbolDown;      /**<@brief  finish symbol (arrow side) */
        int inWeldTable;                           /**<@brief  include in weld table flag*/
        char grooveAngleUp[33];                    /**<@brief  groove angle (arrow side) */
        char fillet2SizeUp[33];                    /**<@brief  2nd fillet size (other side) */
        char fillet2LengthUp[33];                  /**<@brief  2nd fillet length (other side) */
        char depthPreparationUp[33];               /**<@brief  depth of preparation, size or strength,
                                                effective throat, or groove weld size, you can use "[VxWD]p" to add triangle symbol in this field */
        char weldLengthPitchUp[33];                /**<@brief  length and pitch of weld */
        char tailReference[65];                    /**<@brief  tail reference */
        char depthPreprationDown[33];              /**<@brief  depth of preparation, size or strength,
                                                effective throat, or groove weld size, you can use "[VxWD]p" to add triangle symbol in this field*/
        char weldLengthPitchDown[33];              /**<@brief  length and pitch of weld */
        char fillet2SizeDown[33];                  /**<@brief  2nd fillet size (arrow side) */
        char fillet2LengthDown[33];                /**<@brief  2nd fillet length (arrow side) */
        char weldRoot[33];                         /**<@brief  root opening/depth of filling/number of weld */
        char grooveAngleDown[33];                  /**<@brief  groove angle (other side) */
        char weldOtherRoot[33];                    /**<@brief  root opening/depth of filling/number of weld (other side) */
        double gapSpacing;                         /**<@brief  ratio for symbol gap */
    } szwSymbolWeldSetting;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_SYMBOL_DATA_H*/