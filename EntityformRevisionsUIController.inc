<?php

/**
 * @file EntityformRevisionsUIController
 */

/**
 * UI Controller extension
 */
class EntityformRevisionsUIController extends EntityformUIController {

  /**
   * Overrides hook_menu() defaults. Adds support for revisions
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $base = array(
      'file' => 'entityform_revisions.pages.inc',
      'file path' => drupal_get_path('module', 'entityform_revisions'),
    );

    // Loading and editing entityform revisions.
    $items['entityform/' . $wildcard . '/%'] = array(
      'page callback' => 'entityform_revision_form_wrapper',
      'page arguments' => array(1, 2),
      'access callback' => 'entityform_revisions_access',
      'access arguments' => array('edit', 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    ) + $base;

    $items['entityform/' . $wildcard . '/%/edit'] = array(
      'title' => 'Edit revision',
      'page callback' => 'entityform_revision_form_wrapper',
      'page arguments' => array(1, 2, 'edit'),
      'access callback' => 'entityform_access',
      'access arguments' => array('edit', 1),
      'weight' => 0,
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    ) + $base;

    $items['entityform/' . $wildcard . '/%/delete'] = array(
      'title' => 'Delete revision',
      'page callback' => 'entityform_revision_delete_form_wrapper',
      'page arguments' => array(1, 2),
      'access callback' => 'entityform_revisions_access',
      'access arguments' => array('delete', 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'weight' => 10,
    ) + $base;

    // Menu item for viewing entityforms revisions.
    $items['entityform/' . $wildcard . '/%'] = array(
      //'title' => 'Title',
      'title callback' => 'entityform_page_title',
      'title arguments' => array(1),
      'page callback' => 'entityform_revision_page_view',
      'page arguments' => array(1, 2),
      'access callback' => 'entityform_revisions_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    ) + $base;
    $items['entityform/' . $wildcard . '/%/view'] = array(
      'title' => 'View revision',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    );

    return $items;
  }
}