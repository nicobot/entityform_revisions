<?php

/**
 * @file
 * Page callbacks for handling revisions
 */

/**
 * @param $entityform
 * @param $vid
 * @param string $view_mode
 *
 * @return mixed
 */
function entityform_revision_page_view($entityform, $vid, $view_mode = 'full') {

  $revision = entityform_get_revision($entityform, $vid);

  module_load_include('inc', 'entityform', 'entityform.admin');
  return entityform_page_view($revision, $view_mode);
}

/**
 * Form callback wrapper: create or edit a entityform.
 *
 * @param $entityform
 *   The entityform object being edited by this form.
 * @param $vid
 *   The revision being updated
 * @param $mode
 *     Current mode for this form
 *     Submit - user is submitting the form
 *     Edit - user with permission is editingform
 * @param $form_context
 *   How is form being used shown?
 *     'page' - on submit page
 *     'embedded' - called form EntityformTypeController->view()
 *     'preview' - Preview on Entityform type management
 *
 * @see entityform_edit_form()
 * @return array|mixed
 */
function entityform_revision_form_wrapper($entityform, $vid, $mode = 'submit', $form_context = 'page') {

  $revision = entityform_get_revision($entityform, $vid);

  module_load_include('inc', 'entityform', 'entityform.admin');
  return entityform_form_wrapper($revision, $mode, $form_context);
}

/**
 * @param $entityform \Entityform
 * @param $vid
 *
 * @return array|mixed
 */
function entityform_revision_delete_form_wrapper($entityform, $vid) {

  $revision = entityform_get_revision($entityform, $vid);

  module_load_include('inc', 'entityform', 'entityform.admin');
  return entityform_delete_form_wrapper($revision);
}
