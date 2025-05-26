/**
@file zwapi_file_path.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Path API
*/
/**
@defgroup zwapi_file_path Path Operation
@ingroup FileModel
@brief
@details THE MODULE FOR THE ZW3D Path API
*/

#pragma once
#ifndef ZW_API_PATH_H /* this ifndef surrounds entire header */
#define ZW_API_PATH_H

#include "zwapi_file_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Path Add */
    //====================================================================================================================
    /**
    @ingroup zwapi_file_path

    Adds the specified file directory to the list of search paths.   
    These paths are used to find files specified by name only.  
    The search path added by this interface is used to search resource files

    Only when the file path is found through the interface cvxPathFindByFileName(),  
    the file will be searched from these search directories.

    Use interface cvxPathCheck to judge whether the input path is correct.

    @deprecated This function will not be updated any more, please use ZwResourcePathAdd() 
    @see ZwResourcePathAdd  

    @see cvxPathSet() can be used to search drawing files(.Z3,.Z3PRT,.Z3DRW...).

    @param [in] SearchDirectory directory pathname

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxPathAdd(const vxLongPath SearchDirectory);

    /**
    @ingroup zwapi_file_path

    Adds the specified file directory to the begin of list of search paths.
    These paths are used to find files specified by name only.
    The search path added by this interface is used to search resource files

    Only when the file path is found through the interface cvxPathFindByFileName(),
    the file will be searched from these search directories.

    Use interface cvxPathCheck to judge whether the input path is correct.

    @see cvxPathSet() can be used to search drawing files(.Z3,.Z3PRT,.Z3DRW...).

    @param [in] SearchDirectory directory pathname

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxPathSearchBeginAdd(const vxLongPath SearchDirectory);

    /**
    @ingroup zwapi_file_path

    Logs the specified sub-folder of the "apilibs" directory that
    contains the specified DLL (LibName) to the list of ZW3D search
    paths.  
    It is assumed that the sub-folder name or path is defined
    relative to the "apilibs" directory.

    If "SubFolder" is input as NULL, the path to "apilibs" is added
    to the ZW3D search paths.  
    "SubFolder" should not begin with a path delimiter.

    @param [in] LibName library name (without .dll extension)
    @param [in] SubFolder sub-folder name or path  (NULL if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPathAddApiPath(vxName LibName, char *SubFolder);

    /**
    @ingroup zwapi_file_path

    Combines the input directory name (Path) and file name (Name).
    Outputs the result via "Path".

    @see cvxPathCheck() can check whether the path is correct.

    @param [in,out] Path directory where file is located output directory/file path
    @param [in] File filename

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - pathname is too long
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxPathCompose(vxPath Path, const char *File);

    /**
    @ingroup zwapi_file_path

    Combines the input directory name (Path) and file name (Name).
    Outputs the result via "Path".

    @see cvxPathCheck() can check whether the path is correct.

    @param [in,out] Path directory where file is located output directory/file path
    @param [in] sizePath Maximum memory space for "Path".
    @param [in] Name filename

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        
    */
    ZW_API_C evxErrors cvxPathComposeByLongPath(char *Path, int sizePath, const char *Name);

    /**
    @ingroup zwapi_file_path

    @verbatim
    1. Check the input path to see if it is properly formatted for the target OS.
       Forward or backward slashes are replaced with the appropriate path delimiter for the operating system.
       D:/aa/bb <==> D:\aa\bb

    2. If the file name containing the path is passed in, the file path is output.
       D:\aa\bb\cc.Z3PRT  ==> D:\aa\bb

    3. Occurrences of ~ expand to the current user's home directory path, and
    occurrences of ~user expand to the current user's profile directory path.
       ~user\aa  ==>  %USERPROFILE%\aa
       ~\aa  ==>  %HOME%\aa
       $path\bb  ==> (the directory represented by the system environment variable "path")\bb  <==> %path%\bb

    4. The directory is verified to exist and to be accessible. If srcPath specifies the path to a file,
    the file is also required to exist and to be accessible.

    A desPath that is too long (longer than "sizedes") is truncated.

    It is assumed that the input "desPath" is no longer than 512 bytes.

    @endverbatim

    @param [in] srcPath path to a file or directory
    @param [out] desPath directory part of srcPath
    @param [in] sizedes max size of desPath

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPathCheck(const vxLongPath srcPath, char *desPath, int sizedes);

    //====================================================================================================================
    /** @name Path Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_file_path

    Add specified path to directory search conducted by DmPathFind
    and resave search paths.

    This interface corresponds to the file->search paths... function of
    the platform.

    @deprecated This function will not be updated any more, please use ZwSearchPathAdd()
    @see ZwSearchPathAdd

    @note
    When option(Vx.AutoRecordPaths=1) is checked, the interface can add a
    search path.  
    Otherwise, the function of the interface is the same as that of the
    interface cvxPathSearchFirst().  
    Use interface cvxPathCheck to judge whether the input path is correct.

    @code
    cvxConfigGetYesNo("Vx.AutoRecordPaths",&YesNo);
    cvxConfigSetYesNo("Vx.AutoRecordPaths",YesNo);
    @endcode

    @param [in] path pathname

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxPathSet(const vxLongPath path);

    /**
    @ingroup zwapi_file_path

    Causes ZW3D to search the input directory before searching the
    directories listed in "vxpaths".

    @see
    cvxPathSet: The search path of the format file supported by ZW3D.  
    cvxPathAdd: Add search paths for some resource files. Customers are not recommended to use this interface.  
    cvxPathSearchFirst: Set the search path temporarily. The path set through this interface
    is easy to be overwritten.Therefore, the path set by this interface is recommended to be 
    used only once.

    @param [in] Directory directory pathname

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C void cvxPathSearchFirst(const vxLongPath Directory);

    //====================================================================================================================
    /** @name Path Delete */
    //====================================================================================================================
    /**
    @ingroup zwapi_file_path

    Deletes the specified path from the current list of search paths.
    No error is logged if the path doesn't exist.

    @deprecated This function will not be updated any more, please use ZwSearchPathDelete() ZwResourcePathDelete() 
    @see ZwSearchPathDelete ZwResourcePathDelete

    @param [in] Path file search pathname

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C void cvxPathDel(const vxLongPath Path);

    /**
    @ingroup zwapi_file_path

    Deletes all paths from the current list of search paths.

    @deprecated This function will not be supported any more, please use cvxPathDel()
    @see cvxPathDel

    */
    ZW_API_C void cvxPathDelAll(void);

    /**
    @ingroup zwapi_file_path

    If "Path" does not end with the path delimiter, appends the delimiter.  
    It is assumed that the memory referenced by "Path" is sufficient to
    accommodate addition of another character.

    @param [in,out] Path file pathname

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C void cvxPathDelim(vxPath Path);

    /**
    @ingroup zwapi_file_path

    If "Path" does not end with the path delimiter, appends the delimiter.
    It is assumed that the memory referenced by "Path" is sufficient to
    accommodate addition of another character.

    @param [in,out] Path file pathname
    @param [in] sizePath Maximum memory space for "Path".

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C void cvxPathDelimByLongPath(char *Path, int sizePath);


    //====================================================================================================================
    /** @name Path  Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_file_path

    Gets the path of the "apilibs" directory that contains the
    specified API library.  
    It is assumed the library resides
    in a sub-directory named "apilibs" either in the runtime
    user directory or in the ZW3D installation directory.  
    The local "apilibs" is checked first, then the "apilibs" in
    the installation directory.

    @param [in] LibName library name (without .dll extension)
    @param [out] LibDirectory path of directory that contains the library

    @retval return
    -        1 - if the library is found
    -        0 - if not found or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C int cvxPathApiLib(vxName LibName, vxPath LibDirectory);
    /**
    @ingroup zwapi_file_path

    Gets the path of the "apilibs" directory that contains the
    specified API library.  It is assumed the library resides
    in a sub-directory named "apilibs" either in the runtime
    user directory or in the ZW3D installation directory.  The
    local "apilibs" is checked first, then the "apilibs" in
    the installation directory.

    A LibDirectory that is too long (longer than "sizeLib") is truncated.

    It is assumed that the input "LibDirectory" is no longer than 512 bytes.

    @param [in] LibName library name (without .dll extension)
    @param [out] LibDirectory path of directory that contains the library
    @param [in] sizeLib max size of LibDirectory

    @retval return
    -        1 - if the library is found
    -        0 - if not found or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C int cvxPathApiLibByLongPath(const vxName LibName, char *LibDirectory, int sizeLib);

    /**
    @ingroup zwapi_file_path

    Extracts the directory portion of the specified physical path.  
    If there is no directory specified, outputs "./".

    @param [in] FullPath full path/file name
    @param [out] Directory directory portion of "FullPath"

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathDir(vxPath FullPath, vxPath Directory);

    /**
    @ingroup zwapi_file_path

    Extracts the directory portion of the specified physical path.
    If there is no directory specified, outputs "./".

    @param [in] FullPath full path/file name
    @param [out] Directory directory portion of "FullPath"
    @param [in] sizeDir max size of Directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathDirByLongPath(const vxLongPath FullPath, char *Directory, int sizeDir);

    /**
    @ingroup zwapi_file_path

    Extracts the filename portion of the specified physical path.  
    The filename may include an extension, if there is one.

    Outputs FileName[0]=0 if a filename could not be extracted or
    if its length exceeds the size of a "vxPath" string.

    Use cvxPathFile2() to extract a file name that may be longer
    than "vxName".

    @param [in] FullPath full path/file name
    @param [out] FileName filename portion of "FullPath"

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathFile(vxPath FullPath, vxPath FileName);

    /**
    @ingroup zwapi_file_path

    Extracts the filename portion of the specified physical path.  
    The filename may include an extension, if there is one.

    Outputs FileName[0]=0 if a filename could not be extracted

    A FileName that is too long (longer than "sizeFile") is truncated.

    It is assumed that the input "FileName" is no longer than 512 bytes.

    @param [in] fullPath full path/file name
    @param [out] fileName filename portion of "FullPath"
    @param [in] sizeFile max size of filename

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathFileByLongPath(const vxLongPath fullPath, char *fileName, int sizeFile);

    /**
    @ingroup zwapi_file_path

    Extracts the filename portion of the specified physical path.  
    The filename may include an extension, if there is one.

    Outputs FileName[0]=0 if a filename could not be extracted or
    if its length (including the null-terminator) exceeds the size
    of "MaxNameLen".

    It is assumed "FileName" references at least "MaxNameLen" bytes
    of memory.

    @param [in] FullPath full path/file name
    @param [in] MaxNameLen maximum name length in bytes (including null-terminator)
    @param [out] FileName filename portion of "FullPath"

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathFile2(char *FullPath, int MaxNameLen, char *FileName);

    /**
    @ingroup zwapi_file_path

    Given a filename without any directory path (FileName), this
    function searches default paths for the file and outputs a
    complete pathname to the file.

    @note
    When the ZW3D filename exceeds 32bytes,using this function causes
    ZW3D crashed.  
    Therefore,this function will be deprecated in the future and is not
    recommended for use by customers.  
    User can replace this function with the cvxPathFindByFileName().

    @param [in] FileName file name
    @param [out] FullPath full path to the specified file

    @retval return
    -        1 - if the file is found
    -        0 - if not found or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C int cvxPathFind(const vxName FileName, vxPath FullPath);

    /**
    @ingroup zwapi_file_path

    Given a filename without any directory path (FileName), this
    function searches default paths for the file and outputs a
    complete pathname to the file.

    @note
    When the ZW3D filename exceeds 32bytes,using this function causes
    ZW3D crashed.  
    Therefore,this function will be deprecated in the future and is not
    recommended for use by customers.  
    User can replace this function with the cvxPathFindByFileName().

    @param [in] FileName file name
    @param [out] FullPath full path to the specified file
    @param [in] sizeFull the size of FullPath

    @retval return
    -        1 - if the file is found
    -        0 - if not found or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C int cvxPathFindByLongPath(const vxName FileName, char *FullPath, int sizeFull);

    /**
    @ingroup zwapi_file_path

    Given a filename without any directory path (FileName), this
    function searches default paths for the file and outputs a
    complete pathname to the file.

    @deprecated This function will not be updated any more, please use ZwPathFindByFileName()
    @see ZwPathFindByFileName

    @param [in] fileName file name
    @param [out] fullPath full path to the specified file
    @param [in] sizeFullPath max size of fullPath

    @retval return
    -       2 if the file is found and saved;
    -       1 if the file is found but never saved;
    -       0 if not found;
    @retval fail
    -       ZW_API_INVALID_NAME
    -       ZW_API_INVALID_OUTPUT
    -       ZW_API_OUT_OF_RANGE
    */
    ZW_API_C int cvxPathFindByFileName(const char *fileName, char *fullPath, int sizeFullPath);

    /**
    @ingroup zwapi_file_path

    Outputs the path of the ZW3D installation directory.

    @param [out] InstallDirectory installation directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathInstall(vxPath InstallDirectory);

    /**
    @ingroup zwapi_file_path

    Outputs the path of the ZW3D installation directory.

    A InstallDirectory that is too long (longer than "sizeIns") is truncated.

    It is assumed that the input "InstallDirectory" is no longer than 512 bytes.

    @param [out] InstallDirectory installation directory
    @param [int] sizeIns max size of InstallDirectory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxPathInstallByLongPath(char *InstallDirectory, int sizeIns);

    /**
    @ingroup zwapi_file_path

    Outputs the path of the ZW3D "temp" directory for the active session.

    @param [out] Directory ZW3D temp directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxPathTemp(vxPath Directory);

    /**
    @ingroup zwapi_file_path

    Outputs the path of the ZW3D "temp" directory for the active session.

    A Directory that is too long (longer than "sizeDir") is truncated.

    It is assumed that the input "Directory" is no longer than 512 bytes.

    @param [out] Directory ZW3D temp directory
    @param [in] sizeDir max size of Directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxPathTempByLongPath(char *Directory, int sizeDir);

    /**
    @ingroup zwapi_file_path

    Get user folder path of ZW3D.

    @param [out] Directory user path

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxPathUserFolder(vxPath Directory);

    /**
    @ingroup zwapi_file_path

    Get user folder path of ZW3D.

    A Directory that is too long (longer than "sizeDir") is truncated.

    It is assumed that the input "Directory" is no longer than 512 bytes.

    @param [out] Directory user path
    @param [in] sizeDir max size of Directory

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxPathUserFolderByLongPath(char *Directory, int sizeDir);

    /**
    @ingroup zwapi_file_path

    Check whether current environment is debug/release based on the name of folder where zw3d.exe resides in.

    @param [in] FolderName name of folder where zw3d.exe resides in

    @retval return
    -        1 - if the folder name contains Debug/Debugx64/Release/Releasex64,
    -        0 - otherwise .
    @warning
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C int cvxPathIsDebug(const char *FolderName);


    //====================================================================================================================
    /** @name Path State Get/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_file_path

    Set the flag to control the file search path.

    @param [in] Value 1-search file in search paths(including their sub-folders), 0-not to search in search paths

    */
    ZW_API_C void cvxPathSearchSet(int Value);

    /**
    @ingroup zwapi_file_path

    Get the flag that control the file search path.

    @retval return
    -        1 - search file in search paths(including their sub-folders)
    -        0 - not to search in search paths

    */
    ZW_API_C int cvxPathSearchGet();

    /**
    @ingroup zwapi_file_path

    Set the VgCheckActivePathOnly.

    */
    ZW_API_C void cvxPathCheckActiveOnlySet(int Value);

    /**
    @ingroup zwapi_file_path

    Get the VgCheckActivePathOnly.

    */
    ZW_API_C int cvxPathCheckActiveOnlyGet();

    /**
    @ingroup zwapi_file_path

    Check if the length of file name is over ranging.

    @param [in] file_name name to check

    @retval succeeds
    -        ZW_API_NO_ERROR - name is ok
    @retval fails
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_NAME_LEN_OVER_RANGE
    */
    ZW_API_C evxErrors cvxFileNameLenIsOverrange(const char *file_name);

    /**
    @ingroup zwapi_file_path

    Check if the length of file path is over ranging.

    @param [in] file_path path to check

    @retval succeeds
    -        ZW_API_NO_ERROR - path is ok
    @retval fails
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_PATH_LEN_OVER_RANGE
    */
    ZW_API_C evxErrors cvxFilePathLenIsOverrange(const char *file_path);

    //====================================================================================================================
    /** @name Path Query */
    //====================================================================================================================
    /**
    @ingroup ZwFilePath

    Check the input path to see if it is properly formatted for the target OS.
    Forward or backward slashes are replaced with the appropriate path delimiter for the operating system.
        D:/aa/bb <==> D:\aa\bb
    Besides, this function will get the real path for the sourcePath, that means it will remove the path mark
    like '..' or '.' and translate to the absolute path.

    @param [in] sourcePath path to a file or directory
    @param [in] nBytes max size of path
    @param [out] path correct path of sourcePath

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwPathSeparatorCheck(const char *sourcePath, int nBytes, char *path);

    /**
    @ingroup ZwFilePath
    
    Given a filename without any directory path (fileName),
    this function searches the default path for the file and outputs a complete path name to the file.
    
    @param [in] fileName file name
    @param [in] sizeFullPath max size of fullPath
    @param [out] fullPath full path to the specified file
    @param [out] result search result(NULL to ignore)
    
    @retval succeeds
    -       ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_INVALID_NAME
    -       ZW_API_INVALID_OUTPUT
    -       ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwPathFindByFileName(const char *fileName, int sizeFullPath, char *fullPath, ezwPathSearchResult *result);

    //====================================================================================================================
    /** @name Path Operate */
    //====================================================================================================================

    /**
    @ingroup ZwSearchPath
    
    Adds specified path to search paths.  
    This function is used to set search path for Z3/Z3XXX files.  
    You can open file just using file name after adding path with this function.  

    @note
    It's recommended to use ZwResourcePathAdd() if you want to add path to search resource file.  
    If auto record option(Configuration -> Files -> File search -> Open search path -> Auto Record) is checked, search 
    folders option(Configuration -> Files ->File search -> Search folders ) will be checked automatically  
    

    @see ZwSearchPathDelete ZwSearchPathListGet
    
    @param [in] path file search path name
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwSearchPathAdd(const zwString512 path);

    /**
    @ingroup ZwSearchPath
    
    Deletes the specified path from the current list of search paths.  

    @see ZwSearchPathAdd ZwSearchPathListGet
    
    @param [in] path file search path name
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C ezwErrors ZwSearchPathDelete(const zwString512 path);

    /**
    @ingroup ZwSearchPath
    
    Gets all search paths.
    
    @note
    The calling procedure MUST deallocate the pathList with ZwMemoryFree().
    
    @see ZwSearchPathDelete ZwSearchPathAdd 
    
    @param [out] count path list count
    @param [out] pathList path list
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwSearchPathListGet(int *count, zwString512 **pathList);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PATH_H */
