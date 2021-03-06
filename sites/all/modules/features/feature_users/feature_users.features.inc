<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_users_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function feature_users_flag_default_flags() {
  $flags = array();
  // Exported flag: "Comment Abuse".
  $flags['abuse_comment'] = array(
    'content_type' => 'comment',
    'title' => 'Comment Abuse',
    'global' => '0',
    'types' => array(
      '0' => 'story',
      '1' => 'profile',
      '2' => 'item',
      '3' => 'idea',
      '4' => 'group',
      '5' => 'forum',
      '6' => 'blog',
      '7' => 'art',
    ),
    'flag_short' => 'Flag as offensive',
    'flag_long' => 'Flag this content as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Flag as non-offensive',
    'unflag_long' => 'Flag this content as non-offensive.',
    'unflag_message' => '',
    'unflag_denied_text' => 'Unflag are not allowed',
    'link_type' => 'flag_note_form',
    'roles' => array(
      'flag' => array(
        '0' => 2,
        '1' => 6,
      ),
      'unflag' => array(
        '0' => 6,
      ),
    ),
    'access_author' => 'comment_others',
    'show_on_comment' => 1,
    'flag_note_title' => 'Flag note',
    'flag_note_fieldset' => 'Flag note',
    'flag_note_label' => 'Flag note',
    'flag_note_help' => 'A descriptive reason.',
    'flag_note_history_disabled' => 1,
    'flag_note_delete_unflags' => 1,
    'flag_note_default_text' => '',
    'flag_note_maxlength' => '0',
    'flag_note_vocab' => '6',
    'flag_note_vocab_label' => 'Reason',
    'flag_note_vocab_help' => 'Please select a reason.',
    'flag_note_hide_text' => 0,
    'module' => 'feature_users',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "User Abuse".
  $flags['abuse_user'] = array(
    'content_type' => 'user',
    'title' => 'User Abuse',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Report User',
    'flag_long' => 'Report this user as offensive.',
    'flag_message' => '',
    'unflag_short' => 'Remove Report',
    'unflag_long' => 'Remove your report about this user.',
    'unflag_message' => '',
    'unflag_denied_text' => 'OpenID integration',
    'link_type' => 'flag_note_form',
    'roles' => array(
      'flag' => array(
        '0' => 2,
        '1' => 6,
      ),
      'unflag' => array(
        '0' => 6,
      ),
    ),
    'show_on_profile' => 1,
    'access_uid' => 'others',
    'flag_note_title' => 'Flag note',
    'flag_note_fieldset' => 'Flag note',
    'flag_note_label' => 'Flag note',
    'flag_note_help' => 'A descriptive reason.',
    'flag_note_history_disabled' => 1,
    'flag_note_delete_unflags' => 1,
    'flag_note_default_text' => '',
    'flag_note_maxlength' => '0',
    'flag_note_vocab' => '6',
    'flag_note_vocab_label' => 'Reason',
    'flag_note_vocab_help' => 'Please select a reason.',
    'flag_note_hide_text' => 0,
    'module' => 'feature_users',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Add to favourites".
  $flags['add_to_favourites'] = array(
    'content_type' => 'node',
    'title' => 'Add to favourites',
    'global' => '0',
    'types' => array(
      '0' => 'art',
      '1' => 'forum',
      '2' => 'item',
      '3' => 'profile',
    ),
    'flag_short' => 'Add to favourites',
    'flag_long' => '',
    'flag_message' => 'Added to favourites',
    'unflag_short' => 'Remove from favourites',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
      'unflag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'feature_users',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Bookmarks".
  $flags['bookmarks'] = array(
    'content_type' => 'node',
    'title' => 'Bookmarks',
    'global' => '0',
    'types' => array(
      '0' => 'forum',
      '1' => 'art',
    ),
    'flag_short' => 'Bookmark this',
    'flag_long' => 'Add this post to your bookmarks',
    'flag_message' => 'This post has been added to your bookmarks',
    'unflag_short' => 'Unbookmark this',
    'unflag_long' => 'Remove this post from your bookmarks',
    'unflag_message' => 'This post has been removed from your bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
      'unflag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'feature_users',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Friend".
  $flags['friend'] = array(
    'content_type' => 'user',
    'title' => 'Friend',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Add friend',
    'flag_long' => 'Add this user to your list of friends.',
    'flag_message' => '',
    'unflag_short' => 'Remove friend',
    'unflag_long' => 'Remove this user from your list of friends.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
      'unflag' => array(
        '0' => 2,
        '1' => 5,
        '2' => 7,
        '3' => 6,
        '4' => 15,
        '5' => 10,
        '6' => 14,
      ),
    ),
    'show_on_profile' => 0,
    'access_uid' => '',
    'flag_confirmation' => 'Are you sure you want to add [user] to your list of friends?',
    'unflag_confirmation' => 'Are you sure you want to remove [user] from your list of friends?',
    'module' => 'feature_users',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
    'status' => FALSE,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function feature_users_node_info() {
  $items = array(
    'education' => array(
      'name' => t('Education'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'group' => array(
      'name' => t('Group'),
      'module' => 'features',
      'description' => t('Create and manage new group. Each group can have subscribers, and maintains a group home page where subscribers communicate amongst themselves.
'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an "About us" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site\'s initial home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'profile' => array(
      'name' => t('Profile'),
      'module' => 'features',
      'description' => t('A user profile built as content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'simplenews' => array(
      'name' => t('Newsletter issue'),
      'module' => 'features',
      'description' => t('A newsletter issue to be sent to subscribed email addresses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'story' => array(
      'name' => t('Story'),
      'module' => 'features',
      'description' => t('A <em>story</em>, similar in form to a <em>page</em>, is ideal for creating and displaying content that informs or engages website visitors. Press releases, site announcements, and informal blog-like entries may all be created with a <em>story</em> entry. By default, a <em>story</em> entry is automatically featured on the site\'s initial home page, and provides the ability to post comments.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feature_users_views_api() {
  return array(
    'api' => '3.0',
  );
}
