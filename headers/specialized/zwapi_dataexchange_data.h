/**
@file zwapi_dataexchange_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
*/

#ifndef ZW_API_DATAEXCHANGE_DATA_H
#define ZW_API_DATAEXCHANGE_DATA_H

#include "zwapi_util.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @brief copy external part data
    @ingroup ZwDataExchangeData
    */
    typedef struct szwPartImportData
    {
        zwPath directory;  /**<@brief  pathname of directory that contains "file"
                 **  set "directory[0]=0" to search default pathnames
                 */
        zwPath file;       /**<@brief  name of ZW3D file that contains "part" */
        zwRootName part;   /**<@brief  name of part that to be copied*/
        szwMatrix frame;   /**<@brief  insertion frame for sub-part,the insert point
                 ** is the original point of frame
                 */
        int copyWireframe; /**<@brief  1 to copy wireframe, or 0 */
        int copyDimension; /**<@brief  1 to copy dimension, or 0 */
        int option;        /**<@brief  0 - sub-part with associative copy.
                             1 - sub-part with history.
                             2 - history copied into this part.
                             3 - associative copy in this part. */
    } szwPartImportData;

    /**
    @brief reference copy option
    @ingroup ZwDataExchangeData
    */
    typedef enum ezwReferenceCopyOption
    {
        ZW_STATIC_COPY                                        = 0, /**<@brief  static copy */
        ZW_ASSOCIATIVE_COPY                                   = 1, /**<@brief associative copy */
        ZW_TIME_STAMPED_ASSOCIATIVE_COPY                      = 2, /**<@brief time-stamped associative copy */
        ZW_TIME_STAMPED_ASSOCIATIVE_POSITION_INDEPENDENT_COPY = 3  /**<@brief for time-stamped associative copy - assembly position independent. */
    } ezwReferenceCopyOption;

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_DATAEXCHANGE_DATA_H */