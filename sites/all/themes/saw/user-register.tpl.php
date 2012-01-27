<?php

	define ('ROLE_ARTSTUDENT',		17);
	define ('ROLE_STUDENT',				16);
	define ('ROLE_ARTCOLLECTOR',	7);

	$roles = array (
		7		=> $form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTCOLLECTOR],
		16	=> $form ['autoassignrole_user'] ['user_roles'] [ROLE_STUDENT],
		17	=> $form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTSTUDENT]
	);

	unset ($form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTCOLLECTOR]);
	unset ($form ['autoassignrole_user'] ['user_roles'] [ROLE_STUDENT]);
	unset ($form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTSTUDENT]);
	
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTSTUDENT]		= $roles [ROLE_ARTSTUDENT];
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_STUDENT]				= $roles [ROLE_STUDENT];
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTCOLLECTOR]	= $roles [ROLE_ARTCOLLECTOR];
	
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTSTUDENT]		['#description']	= t('Select <b>Art Student</b> if you are currently registered at a college or university. (please note you require an email address e.g. Name.Surname@Education.ac.uk)');
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_STUDENT]				['#description']	= t('Select <b>Student</b> if you are a student but don’t have a college or university email account.');
	$form ['autoassignrole_user'] ['user_roles'] [ROLE_ARTCOLLECTOR]	['#description']	= t('Select <b>Art Collector</b> if you wish to purchase artworks and join our community.');
	
	print drupal_render ($form ['group_basic']);
	
	//print_r ($form ['autoassignrole_user']);
	//exit;
	
	$form ['autoassignrole_user'] ['#description'] = t('<a href="/page/account-types">See the benefits for each type of account</a>') . '.';
	
	$list = array (
		'group_basic',
		'user_registration_help',
		'autoassignrole_user',
		'account',
		'legal',
		'submit'
	);
		
	
	foreach ($list as $name)
	{
		$item = $form [$name];
		
		unset ($form [$name]);
		
		$form [$name] = $item;
	}

	print drupal_render ($form)	;

?>