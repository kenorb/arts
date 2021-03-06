<?php
// $Id: page.tpl.php,v 1.25.2.2 2009/04/30 00:13:31 goba Exp $
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <meta http-equiv="Content-Style-Type" content="text/css" />
  <?php print $head ?>
  <title><?php print $head_title ?></title>
  <?php print $styles ?>
  <?php print $scripts ?>
  <script>
  </script>
</head>

<body>
<?php print $closure ?>
<div id="page">

  <div class="wrapper">
  
    <div class="hide"><a href="#content" title="<?php print t('Skip navigation') ?>." accesskey="2"><?php print t('Skip navigation') ?></a>.</div>
    
      <div id="banner">
        <table id="primary-menu" summary="Navigation elements." border="0" cellpadding="0" cellspacing="0" width="100%">
          <tr>
            <td id="home" rowspan="2" width="22%" onclick="window.location.href = '/';"></td>
            <td class="primary-links" valign="middle">
              <?php print theme('links', $primary_links, array('class' => 'links', 'id' => 'navlist')) ?>
            </td>
            <td td class="login-box" valign="middle" >
          	  <?php if (!$logged_in): ?>
								<p>
                	<a class="active" href="/user/register"><img src="/sites/all/themes/saw/kreska.png" alt=""> Sign up </a>
                	<a class="active" href="/user"><img src="/sites/all/themes/saw/klodka.png" alt=""> Sign in </a>  </p>
								</p>
                <?php else: ?>
                	<table class="profile-menu-container" cellspacing="0" cellpadding="0">
										<tr class="top">
											<td class="username">
												<a href="/users/<?php echo $user -> name; ?>">
													<span class="role"><?php echo ucwords (end ($user -> roles)); ?></span> - <span class="name"><?php echo $user -> name; ?></span>
												</a>
											</td>
											<td class="dropdown-icon">
												<div class="dropdown-icon"></div>
											</td>
											
											<td class="logout">
												<a href="/logout">Log out</a>
											</td>
										</tr>
										<tr class="bottom">
											<td colspan="3" class="items">
												<?php
												
													$menu = module_invoke('menu', 'block', 'view', 'menu-profilemenu');
													
													saw_users_alter_profilemenu ($menu ['content']);
													
													echo str_replace ('>-<', '><div class="separator"></div><', $menu ['content']); ?>
													
											</td>
										</tr>
									</table>
										
									</div>
                <?php endif; ?>
            </td>
          </tr>
          <tr>
            <td class="secondary-links" width="50%" valign="middle">
							<?php if ($logged_in): ?>
								<?php if (!$logged_in) $secondary_links ['menu-9668'] = array ('attributes' => array ('title' => ''), 'href' => 'user/register', 'title' => 'Sell My Art'); krsort ($secondary_links); ?>
								<?php print theme('links', $secondary_links, array('class' => 'links', 'id' => 'subnavlist')) ?>
							<?php endif; ?>
            </td>
          </tr>
        </table>
      </div>
      
      <div id="toolbar-area" <?php if (!$logged_in): ?>class="unlogged"<?php endif; ?>>
        <table id="toolbar" cellspacing="0" cellpadding="0">
          <tr>
            <td id="breadcrumb-container">
              <?php print $breadcrumb ?>
            </td>
						<td>
							<?php if (!$logged_in): ?>
								<div class="secondary-links unlogged-links">
									<?php if (!$logged_in) $secondary_links ['menu-9668'] = array ('attributes' => array ('title' => ''), 'href' => 'user/register', 'title' => 'Sell My Art'); krsort ($secondary_links); ?>
									<?php print theme('links', $secondary_links, array('class' => 'links', 'id' => 'subnavlist')) ?>
								</div>
							<?php endif; ?>
						</td>
						<td class="search-box" valign="middle" width="20%">
							<form action="/search" method="get">
								<div id="search" class="container-inline">
									<div class="search-box"></div>
								</div>
							</form>
						</td>
          </tr>
        </table>
       </div>
      
      <table id="content" border="0" cellpadding="15" cellspacing="0" width="100%">
        <tr>
          <?php if ($left != ""): ?>
          <td id="sidebar-left">
            <?php print $left ?>
          </td>
          <?php endif; ?>
      
          <td valign="top">
            <div id="main">
              <?php if ($title != ""): ?>
      
                <h1 class="title"><?php print $title ?></h1>
      
                <?php if ($tabs != ""): ?>
                  <div class="tabs"><?php print $tabs ?></div>
                <?php endif; ?>
      
              <?php endif; ?>
      
              <?php if ($show_messages && $messages != ""): ?>
                <?php print $messages ?>
              <?php endif; ?>
      
              <?php if ($help != ""): ?>
                  <div id="help"><?php print $help ?></div>
              <?php endif; ?>
      
            <!-- start main content -->
            <?php print $content; ?>
            <?php print $feed_icons; ?>
            <!-- end main content -->
      
							<div class="clear-block"></div>
            </div><!-- main -->
          </td>
          <?php if ($right != ""): ?>
          <td id="sidebar-right">
            <?php print $right ?>
          </td>
          <?php endif; ?>
        </tr>
      </table>
      
      <div class="push"></div>
      
  </div>
  
  <div id="footer">
    <div id="footer_container">
      <table id="footer-menu-list">
        <tr>
          <td id="copyright">
            <span class="text"><?php echo "Copyright &copy; 2008-2011 Student Art World";?></span>
          </td>
        </tr>
        <tr>
          <td id="footer_menu">  
            <?php print $footer1; ?>
          </td>
        </tr>
      </table>
    </div>
  </div>
</div>
</body>
</html>
