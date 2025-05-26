/**
@file zwapi_memory.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Memory API
*/
/**
@defgroup zwapi_memory Memory
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Memory API
*/

#pragma once
#ifndef ZW_API_MEM_H /* this ifndef surrounds entire header */
#define ZW_API_MEM_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Memory  Allocate */
    //====================================================================================================================
    /**
    @ingroup zwapi_memory

    Allocates chunk of memory of requested size from system heap.  
    Returns void pointer to specified amount of memory.

    @param [in] NumBytes no. of bytes to allocate
    @param [out] MemPointer pointer to allocated memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxMemAlloc(int NumBytes, void **MemPointer);

    /**
    @ingroup zwapi_memory

    Resizes memory chunk that was allocated via VxMemAlloc().  
    If input pointer is NULL, allocates new memory.  
    Outputs pointer to resized memory.  
    If memory cannot not be resized, the input pointer is not modified.

    @param [in] NumBytes new memory size in bytes
    @param [out] MemPointer address of pointer to memory to be resized

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxMemResize(int NumBytes, void **MemPointer);

    //====================================================================================================================
    /** @name Memory Allocate */
    //====================================================================================================================
    /**
    @ingroup ZwMemory

    Allocates chunk of memory of requested size from system heap.
    Returns void pointer to specified amount of memory.

    @param [in] numBytes nunber of bytes to allocate
    @param [out] memoryPointer pointer to allocated memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwMemoryAlloc(int numBytes, void **memoryPointer);

    /**
    @ingroup ZwMemory

    Resizes memory chunk that was allocated via VxMemAlloc().
    If input pointer is NULL, allocates new memory.
    Outputs pointer to resized memory.
    If memory cannot not be resized, the input pointer is not modified.

    @param [in] numBytes new memory size in bytes
    @param [out] memoryPointer address of pointer to memory to be resized

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwMemoryResize(int numBytes, void **memoryPointer);

    //====================================================================================================================
    /** @name Memory  Zero */
    //====================================================================================================================
    /**
    @ingroup zwapi_memory

    Zero "NumBytes" of data beginning with "MemPointer".

    @param [in] MemPointer pointer to memory
    @param [in] NumBytes number of bytes to zero

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxMemZero(void *MemPointer, int NumBytes);

    //====================================================================================================================
    /** @name Memory Zero */
    //====================================================================================================================
    /**
    @ingroup ZwMemory

    Zero "numBytes" of data beginning with "memoryPointer".

    @param [in] numBytes number of bytes to zero
    @param [in] memoryPointer pointer to memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwMemoryZero(int numBytes, void *memoryPointer);

    //====================================================================================================================
    /** @name Memory  Free */
    //====================================================================================================================
    /**
    @ingroup zwapi_memory

    Frees memory at specified pointer.  
    Sets pointer to NULL if memory was freed successfully.  
    If the input pointer is already NULL, this function does nothing.

    @param [in] MemPointer address of pointer to be Free'd

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxMemFree(void **MemPointer);

    //====================================================================================================================
    /** @name Memory Free */
    //====================================================================================================================
    /**
    @ingroup ZwMemory

    Frees memory at specified pointer.
    Sets pointer to NULL if memory was freed successfully.
    If the input pointer is already NULL, this function does nothing.

    @param [in] memoryPointer address of pointer to be freed

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwMemoryFree(void **memoryPointer);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MEM_H */
