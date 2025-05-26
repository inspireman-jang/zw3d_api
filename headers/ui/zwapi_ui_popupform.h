/**
@file zwapi_ui_popupform.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Popup Form API
*/
/**
@defgroup zwapi_ui_popupform Popup Form
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Popup Form API
*/

#pragma once
#ifndef ZW_API_POPUP_FORM_H /* this ifndef surrounds entire header */
#define ZW_API_POPUP_FORM_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Popup Form */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_popupform

    Show the specified popup menu.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] sName popup menu name

    @retval succeeds
    -       0 - success
    @retval fail
    -       1 - error
    -       2 - error and popupBar is not find.
    -       ZW_API_INVALIS_NAME
    */
    ZW_API_C int cvxPopupShow(const char *sName);

    /**
    @ingroup zwapi_ui_popupform

    Determine if the specified pop up menu exists.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name popup menu name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupDefine(const char *name);

    /**
    @ingroup zwapi_ui_popupform

    Update the specified pop up menu.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] Name menu name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupUpdate(const char *Name);

    /**
    @ingroup zwapi_ui_popupform

    Set the visible state for the specified pop up menu.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] sName popup menu name
    @param [in] visible visible or not

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupSetVisible(const char *sName, int visible);


    //====================================================================================================================
    /** @name Sub Menu */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_popupform

    Get count of menu actions.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] Name menu name
    @param [out] cnt count of actions

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPopupMenuCnt(const char *Name, int *cnt);

    /**
    @ingroup zwapi_ui_popupform

    Get count of sub-menu actions.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] Name menu name
    @param [in] Sub sub-menu name
    @param [out] cnt count of actions

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPopupSubMenuCnt(const char *Name, const char *Sub, int *cnt);

    /**
    @ingroup zwapi_ui_popupform

    Insert a item to specific sub-menu in menu.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).  
    If index = -1, it is inserted lase, otherwise it is inserted before index.

    @deprecated This API will not be updated anymore, please use ZwUiPopupSubMenuItemInsert()
    @see ZwUiPopupSubMenuItemInsert

    @param [in] Name menu name
    @param [in] Sub sub-menu name
    @param [in] index index in the sub-menu
    @param [in] ActName action name of item
    @param [in] Label label of item
    @param [in] Script action of the item
    @param [in] Icon icon of item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxPopupSubMenuItemInsert(const char *Name, const char *Sub, int index, const char *ActName, const char *Label, const char *Script, const char *Icon);

    /**
    @ingroup zwapi_ui_popupform

    Remove a item from specific sub-menu in menu.  
    The function of this interface is similar to cvxPopupSubMenuActionsRemove().  
    If index = -1, remove all.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] Name menu name
    @param [in] Sub sub-menu name
    @param [in] index index in the sub-menu

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxPopupSubMenuItemRemove(const char *Name, const char *Sub, int index);

    /**
    @ingroup zwapi_ui_popupform

    Remove action from specific sub-menu in menu.  
    If iLast = -1 and iFirst = 0, remove all.  
    If iLast = iFirst = -1, remove all.  
    The function of this interface is similar to cvxPopupSubMenuItemRemove().  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] Name menu name
    @param [in] Sub sub-menu name
    @param [in] iFirst index in the sub-menu
    @param [in] iLast index in the sub-menu

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupSubMenuActionsRemove(const char *Name, const char *Sub, int iFirst, int iLast);

    /**
    @ingroup zwapi_ui_popupform

    Insert a separator to specific sub-menu in menu.  
    This interface can only insert separator at the end of the sub-menu.  
    If there is no "action" after the separator, the separator is not displayed.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @deprecated This API will not be updated anymore, please use ZwUiPopupSubMenuItemInsert()
    @see ZwUiPopupSubMenuItemInsert

    @param [in] Name menu name
    @param [in] Sub sub-menu name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupSubMenuSeparatorInsert(const char *Name, const char *Sub);

    /**
    @ingroup zwapi_ui_popupform

    Set the visible state for the specified pop up sub-menu.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name popup menu name
    @param [in] sub popup sub-menu name
    @param [in] visible visible or not

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupSubMenuSetVisible(const char *name, const char *sub, int visible);


    //====================================================================================================================
    /** @name Popup Form  Item */
    //====================================================================================================================

    /**
    @ingroup zwapi_ui_popupform

    Check if special menu item is exist.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] action action name

    @retval succeeds
    -        1 - if exist
    -        0 - if not exist or function fails
    @retval warnings
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C int cvxPopupItemIsExist(const char *name, const char *action);

    /**
    @ingroup zwapi_ui_popupform

    Insert specified popup item.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).  
    If this menu is NULL, "index" = -1.  
    If this menu is not NULL, "index" >=0

    @deprecated This API will not be updated anymore, please use ZwUiPopupItemInsert()
    @see ZwUiPopupItemInsert

    @param [in] name menu name
    @param [in] index index in the menu
    @param [in] Label label name
    @param [in] Action action name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemInsert(const char *name, int index, const char *Label, const char *Action);


    /**
    @ingroup zwapi_ui_popupform

    Remove specified popup item.  
    If index = -1, remove all.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] index index in the menu

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemRemove(const char *name, int index);

    /**
    @ingroup zwapi_ui_popupform

    Get item action name by specified menu name and menu item.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] item menu item
    @param [out] Action action name
    @param [in] nByte max size of Action

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPopupItemActionGet(const char *name, int item, char *Action, int nByte);

    /**
    @ingroup zwapi_ui_popupform

    Set the action of menu specified item  
    This interface cannot change the action label.  
    The "index" can't be less than 0.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] index action index
    @param [in] Action action script

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxPopupItemSetAction(const char *name, int index, const char *Action);

    /**
    @ingroup zwapi_ui_popupform

    Get the menu item label name.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] item menu item
    @param [out] Label Label name
    @param [in] nByte max size of Label

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPopupItemLabelGet(const char *name, int item, char *Label, int nByte);

    /**
    @ingroup zwapi_ui_popupform

    Get the action's checked state.  
    Menu item must have the "GroupItem" attribute to call this interface.  
    Only one of the checked properties of all actions in a group can be true.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] group menu group
    @param [in] item menu item
    @param [out] Check checked state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxPopupItemCheckedGet(const char *name, int group, int item, int *Check);

    /**
    @ingroup zwapi_ui_popupform

    Get the action's visible state.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] item menu item
    @param [out] Visible visible state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemVisibleGet(const char *name, int item, int *Visible);

    /**
    @ingroup zwapi_ui_popupform

    Set the action visibility of quick bar, popup bar according to the specified  
    menu name and action name.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] action action name
    @param [in] visible action visibility

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemSetVisibleByAction(const char *name, const char *action, int visible);

    /**
    @ingroup zwapi_ui_popupform

    Set the action state of quick bar, popup bar according to the specified  
    menu name and action name.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] action action name
    @param [in] enabled action state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemSetEnabledByAction(const char *name, const char *action, int enabled);

    /**
    @ingroup zwapi_ui_popupform

    Set the action's checked state of quick bar, popup bar according to the specified  
    menu name and action name.  
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @param [in] name menu name
    @param [in] action action name
    @param [in] checked action's checked state

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C evxErrors cvxPopupItemSetCheckedByAction(const char *name, const char *action, int checked);

    //====================================================================================================================
    /** @name Popup Form Sub Menu */
    //====================================================================================================================
    /**
    @ingroup ZwUiPopupForm

    Insert the specified popup item into the sub-menu of popup menu.
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @note
    If 'label' and 'action' are not blank or null, it will insert the action.
    If 'label', 'action' and 'icon' are all blank or null, it will insert a menu separator.
    If one of 'label' and 'action' is blank or null and the other one is not, it will return ZW_API_GENERAL_ERROR.

    @param [in] menu menu name
    @param [in] submenu sub-menu name
    @param [in] index index in the sub-menu, -1 to append to the end of the popup sub-menu
    @param [in] label label name, nullptr to insert sub-menu separator
    @param [in] action action name, nullptr to ignore
    @param [in] icon icon name, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwUiPopupSubMenuItemInsert(const char *menu, const char *submenu, int index, const char *label, const char *action, const char *icon);

    //====================================================================================================================
    /** @name Popup Form Item */
    //====================================================================================================================
    /**
    @ingroup ZwUiPopupForm

    Insert the specified popup item into the popup menu.
    Get the popup menu name through using "$report" or viewing the configuration file(ZW3D/Settings/).

    @note
    If 'label' and 'action' are not blank or null, it will insert the action.
    If 'label', 'action' and 'icon' are all blank or null, it will insert a menu separator.
    If one of 'label' and 'action' is blank or null and the other one is not, it will return ZW_API_GENERAL_ERROR.

    @param [in] menu menu name
    @param [in] index index in the menu, -1 to append to the end of the popup menu
    @param [in] label label name, nullptr to insert menu separator
    @param [in] action action name, nullptr to ignore
    @param [in] icon icon name, nullptr to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwUiPopupItemInsert(const char *menu, int index, const char *label, const char *action, const char *icon);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_POPUP_FORM_H */
